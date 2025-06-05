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
    { "=", "=", svs::OperatorLexicalToken::Type::SimpleAssignment, "SimpleAssignment" },
    { "+=", "\\+=", svs::OperatorLexicalToken::Type::AdditionAssignment, "AdditionAssignment" },
    { "-=", "-=", svs::OperatorLexicalToken::Type::SubtractionAssignment, "SubtractionAssignment" },
    { "*=", "\\*=", svs::OperatorLexicalToken::Type::MultiplicationAssignment, "MultiplicationAssignment" },
    { "/=", "/=", svs::OperatorLexicalToken::Type::DivisionAssignment, "DivisionAssignment" },
    { "%=", "%=", svs::OperatorLexicalToken::Type::ModuloAssignment, "ModuloAssignment" },
    { "&=", "&=", svs::OperatorLexicalToken::Type::BitwiseAndAssignment, "BitwiseAndAssignment" },
    { "|=", "\\|=", svs::OperatorLexicalToken::Type::BitwiseOrAssignment, "BitwiseOrAssignment" },
    { "^=", "\\^=", svs::OperatorLexicalToken::Type::BitwiseExclusiveOrAssignment, "BitwiseExclusiveOrAssignment" },
    { "<<=", "<<=", svs::OperatorLexicalToken::Type::LogicalLeftShiftAssignment, "LogicalLeftShiftAssignment" },
    { ">>=", ">>=", svs::OperatorLexicalToken::Type::LogicalRightShiftAssignment, "LogicalRightShiftAssignment" },
    { "<<<=", "<<<=", svs::OperatorLexicalToken::Type::ArithmeticLeftShiftAssignment, "ArithmeticLeftShiftAssignment" },
    { ">>>=", ">>>=", svs::OperatorLexicalToken::Type::ArithmeticRightShiftAssignment, "ArithmeticRightShiftAssignment" },

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
