#include <regex>

#include "Lexer.h"

svs::WhiteSpaceLexicalToken::WhiteSpaceLexicalToken(
    const svs::FilePosition& __file_position,
    const std::string& __raw_token)
    : svs::LexicalToken(
        svs::LexicalToken::Type::WhiteSpace,
        __file_position,
        __raw_token)
{}

svs::CommentLexicalToken::CommentLexicalToken(
    const svs::FilePosition& __file_position,
    const std::string& __raw_token,
    const svs::CommentLexicalToken::Type& __comment_type)
    : svs::LexicalToken(
        svs::LexicalToken::Type::Comment,
        __file_position,
        __raw_token),
      _comment_type(__comment_type)
{}

svs::AssignmentOperatorLexicalToken::AssignmentOperatorLexicalToken(
    const svs::FilePosition& __file_position,
    const std::string& __raw_token,
    const svs::AssignmentOperatorLexicalToken::Type& __assignment_operator_type)
    : svs::LexicalToken(
        svs::LexicalToken::Type::AssignmentOperator,
        __file_position,
        __raw_token),
      _assignment_operator_type(__assignment_operator_type)
{}

const std::string svs::WhiteSpaceLexicalToken::to_string() const
{
    std::stringstream ss;
    ss << "WhiteSpaceLexicalToken{\n";
    ss << "  FilePosition=" << file_position().to_string() << ",\n";
    ss << "  Syntax=\"" << raw_token() << "\"\n";
    ss << "}";

    return ss.str();
}

const std::string svs::CommentLexicalToken::to_string() const
{
    std::stringstream ss;
    ss << "CommentLexicalToken{\n";
    ss << "  FilePosition=" << file_position().to_string() << ",\n";
    ss << "  Syntax=\"" << raw_token() << "\",\n";

    switch (_comment_type)
    {
    case OneLine:
        ss << "  CommentType=OneLine\n";
        break;
    case Block:
        ss << "  CommentType=Block\n";
        break;
    }

    ss << "}";

    return ss.str();
}

struct AssignmentOperatorTypeTableRow
{
    std::string syntax;
    svs::AssignmentOperatorLexicalToken::Type type;
    std::string help_text;
};

static const std::vector<AssignmentOperatorTypeTableRow> assignment_operator_type_table
{
    { "=",    svs::AssignmentOperatorLexicalToken::Simple,                     "Simple"  },
    { "+=",   svs::AssignmentOperatorLexicalToken::PlusEquals,                 "PlusEquals"  },
    { "-=",   svs::AssignmentOperatorLexicalToken::MinusEquals,                "MinusEquals"  },
    { "*=",   svs::AssignmentOperatorLexicalToken::TimesEquals,                "TimesEquals"  },
    { "/=",   svs::AssignmentOperatorLexicalToken::DivideEquals,               "DivideEquals"  },
    { "%=",   svs::AssignmentOperatorLexicalToken::ModuloEquals,               "ModuloEquals"  },
    { "&=",   svs::AssignmentOperatorLexicalToken::BitwiseAndEquals,           "BitwiseAndEquals"  },
    { "|=",   svs::AssignmentOperatorLexicalToken::BitwiseOrEquals,            "BitwiseOrEquals"  },
    { "^=",   svs::AssignmentOperatorLexicalToken::BitwiseExclusiveOrEquals,   "BitwiseExclusiveOrEquals"  },
    { "<<=",  svs::AssignmentOperatorLexicalToken::LogicalLeftShiftEquals,     "LogicalLeftShiftEquals"  },
    { ">>=",  svs::AssignmentOperatorLexicalToken::LogicalRightShiftEquals,    "LogicalRightShiftEquals"  },
    { "<<<=", svs::AssignmentOperatorLexicalToken::ArithmeticLeftShiftEquals,  "ArithmeticLeftShiftEquals"  },
    { ">>>=", svs::AssignmentOperatorLexicalToken::ArithmeticRightShiftEquals, "ArithmeticRightShiftEquals"  },
};

const std::string svs::AssignmentOperatorLexicalToken::to_string() const
{
    std::stringstream ss;
    ss << "AssignmentOperatorLexicalToken{\n";
    ss << "  FilePosition=" << file_position().to_string() << ",\n";
    ss << "  Syntax=\"" << raw_token() << "\"\n";

    ss << "  Type=\"";
    for (const AssignmentOperatorTypeTableRow& row : assignment_operator_type_table) {
        if (row.type == _assignment_operator_type) {
            ss << row.help_text << "\"";
            break;
        }
    }

    ss << "}";

    return ss.str();
}

bool svs::Lexer::lex_file(
    const std::string& file_contents,
    std::vector<svs::LexicalToken *>& tokens)
{
    std::regex whitespace_regex("\\s+");
    std::regex one_line_comment_regex("\\/\\/.*$", std::regex_constants::multiline);
    std::regex block_comment_regex("\\/\\*(.|\n)*\\*\\/");
    std::regex assignment_operator_regex("(=)|(\\+=)|(-=)|(\\*=)|(/=)|(%=)|(&=)|(\\|=)|(\\^=)|(<<=)|(>>=)|(<<<=)|(>>>=)");

    std::string::const_iterator search_start(file_contents.begin());
    std::string::const_iterator search_end(file_contents.end());

    std::string::const_iterator file_position_iterator(file_contents.begin());
    FilePosition file_position{ .line=0, .col=0 };

    while (search_start != search_end)
    {
        std::smatch match;

        if (std::regex_search(
                search_start,
                search_end,
                match,
                whitespace_regex,
                std::regex_constants::match_continuous))
        {
            auto token = new svs::WhiteSpaceLexicalToken(
                file_position,
                match.str());
            tokens.push_back(token);

            search_start = match.suffix().first;

            goto update_file_position;
        }

        if (std::regex_search(
                search_start,
                search_end,
                match,
                one_line_comment_regex,
                std::regex_constants::match_continuous))
        {
            auto token = new svs::CommentLexicalToken(
                file_position,
                match.str(),
                svs::CommentLexicalToken::Type::OneLine);
            tokens.push_back(token);

            search_start = match.suffix().first;

            goto update_file_position;
        }

        if (std::regex_search(
                search_start,
                search_end,
                match,
                block_comment_regex,
                std::regex_constants::match_continuous))
        {
            auto token = new svs::CommentLexicalToken(
                file_position,
                match.str(),
                svs::CommentLexicalToken::Type::Block);
            tokens.push_back(token);

            search_start = match.suffix().first;

            goto update_file_position;
        }

        if (std::regex_search(
                search_start,
                search_end,
                match,
                assignment_operator_regex,
                std::regex_constants::match_continuous))
        {
            svs::AssignmentOperatorLexicalToken::Type type;
            for (const AssignmentOperatorTypeTableRow& row : assignment_operator_type_table) {
                if (row.syntax == match.str())
                {
                    type = row.type;
                }
            }

            auto token = new svs::AssignmentOperatorLexicalToken(
                file_position,
                match.str(),
                type);
            tokens.push_back(token);

            search_start = match.suffix().first;

            goto update_file_position;
        }

        ++search_start;

update_file_position:
        while (file_position_iterator < search_start)
        {
            if (*file_position_iterator == '\n')
            {
                ++file_position.line;
                file_position.col = 0;
            }
            else
            {
                ++file_position.col;
            }

            ++file_position_iterator;
        }
    }

    return true;
}

