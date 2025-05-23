#include <sstream>
#include <vector>

#include "AssignmentOperatorLexicalToken.h"

struct AssignmentOperatorTypeTableRow
{
    std::string syntax;
    svs::AssignmentOperatorLexicalToken::Type type;
    std::string help_text;
};

static const std::vector<AssignmentOperatorTypeTableRow> assignment_operator_type_table
{
    { "=", svs::AssignmentOperatorLexicalToken::Simple, "Simple"  },
    { "+=", svs::AssignmentOperatorLexicalToken::PlusEquals, "PlusEquals"  },
    { "-=", svs::AssignmentOperatorLexicalToken::MinusEquals, "MinusEquals"  },
    { "*=", svs::AssignmentOperatorLexicalToken::TimesEquals, "TimesEquals"  },
    { "/=", svs::AssignmentOperatorLexicalToken::DivideEquals, "DivideEquals"  },
    { "%=", svs::AssignmentOperatorLexicalToken::ModuloEquals, "ModuloEquals"  },
    { "&=", svs::AssignmentOperatorLexicalToken::BitwiseAndEquals, "BitwiseAndEquals"  },
    { "|=", svs::AssignmentOperatorLexicalToken::BitwiseOrEquals, "BitwiseOrEquals"  },
    { "^=", svs::AssignmentOperatorLexicalToken::BitwiseExclusiveOrEquals, "BitwiseExclusiveOrEquals"  },
    { "<<=", svs::AssignmentOperatorLexicalToken::LogicalLeftShiftEquals, "LogicalLeftShiftEquals"  },
    { ">>=", svs::AssignmentOperatorLexicalToken::LogicalRightShiftEquals, "LogicalRightShiftEquals"  },
    { "<<<=", svs::AssignmentOperatorLexicalToken::ArithmeticLeftShiftEquals, "ArithmeticLeftShiftEquals"  },
    { ">>>=", svs::AssignmentOperatorLexicalToken::ArithmeticRightShiftEquals, "ArithmeticRightShiftEquals"  },
};

svs::AssignmentOperatorLexicalToken::AssignmentOperatorLexicalToken(
    const svs::FilePosition& __file_position,
    const std::string& __raw_token)
    : svs::LexicalToken(
        svs::LexicalToken::Type::AssignmentOperator,
        __file_position,
        __raw_token)
{
    for (const AssignmentOperatorTypeTableRow& row : assignment_operator_type_table) {
        if (row.syntax == __raw_token)
        {
            _assignment_operator_type = row.type;
        }
    }
}

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

const std::regex svs::AssignmentOperatorLexicalToken::regex
    = std::regex("(=)|(\\+=)|(-=)|(\\*=)|(/=)|(%=)|(&=)|(\\|=)|(\\^=)|(<<=)|(>>=)|(<<<=)|(>>>=)");

