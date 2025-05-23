#include <sstream>

#include "OperatorLexicalToken.h"

struct OperatorLookupTableRow
{
    std::string syntax;
    std::string regex_part;
    svs::OperatorLexicalToken::Type type;
    std::string help_text;
};

static const std::vector<OperatorLookupTableRow> operator_lookup_table
{
    // Assignment Operators
    { "=", "=", svs::OperatorLexicalToken::Type::EqualsAssignment, "EqualsAssignment" },
    { "+=", "\\+=", svs::OperatorLexicalToken::Type::PlusEqualsAssignment, "PlusEqualsAssignment" },
    { "-=", "-=", svs::OperatorLexicalToken::Type::MinusEqualsAssignment, "MinusEqualsAssignment" },
    { "*=", "\\*=", svs::OperatorLexicalToken::Type::TimesEqualsAssignment, "TimesEqualsAssignment" },
    { "/=", "/=", svs::OperatorLexicalToken::Type::DivideEqualsAssignment, "DivideEqualsAssignment" },
    { "%=", "%=", svs::OperatorLexicalToken::Type::ModuloEqualsAssignment, "ModuloEqualsAssignment" },
    { "&=", "&=", svs::OperatorLexicalToken::Type::BitwiseAndEqualsAssignment, "BitwiseAndEqualsAssignment" },
    { "|=", "\\|=", svs::OperatorLexicalToken::Type::BitwiseOrEqualsAssignment, "BitwiseOrEqualsAssignment" },
    { "^=", "\\^=", svs::OperatorLexicalToken::Type::BitwiseExclusiveOrEqualsAssignment, "BitwiseExclusiveOrEqualsAssignment" },
    { "<<=", "<<=", svs::OperatorLexicalToken::Type::LogicalLeftShiftEqualsAssignment, "LogicalLeftShiftEqualsAssignment" },
    { ">>=", ">>=", svs::OperatorLexicalToken::Type::LogicalRightShiftEqualsAssignment, "LogicalRightShiftEqualsAssignment" },
    { "<<<=", "<<<=", svs::OperatorLexicalToken::Type::ArithmeticLeftShiftEqualsAssignment, "ArithmeticLeftShiftEqualsAssignment" },
    { ">>>=", ">>>=", svs::OperatorLexicalToken::Type::ArithmeticRightShiftEqualsAssignment, "ArithmeticRightShiftEqualsAssignment" },

    // Increment and Decrement Operators
    { "++", "\\+\\+", svs::OperatorLexicalToken::Type::Increment, "Increment" },
    { "--", "--", svs::OperatorLexicalToken::Type::Decrement, "Decrement" },
};

svs::OperatorLexicalToken::OperatorLexicalToken(
    const svs::FilePosition& __file_position,
    const std::string& __raw_token)
    : svs::LexicalToken(
        svs::LexicalToken::Type::Operator,
        __file_position,
        __raw_token)
{
    for (const OperatorLookupTableRow& row : operator_lookup_table)
    {
        if (row.syntax == __raw_token)
        {
            _operator_type = row.type;
        }
    }
}

const std::string svs::OperatorLexicalToken::to_string() const
{
    std::stringstream ss;
    ss << "OperatorLexicalToken{\n";
    ss << "  FilePosition=" << file_position().to_string() << ",\n";
    ss << "  Syntax=\"" << raw_token() << "\",\n";

    ss << "  Type=\"";
    for (const OperatorLookupTableRow& row : operator_lookup_table)
    {
        if (row.type == _operator_type)
        {
            ss << row.help_text << "\"";
            break;
        }
    }

    ss << "}";

    return ss.str();
}

const std::regex svs::OperatorLexicalToken::regex()
{
    std::string regex_definition;
    for (const auto& row : operator_lookup_table)
    {
        if (!regex_definition.empty())
        {
            regex_definition += "|";
        }
        regex_definition += row.regex_part;
    }

    return std::regex(regex_definition);
}
