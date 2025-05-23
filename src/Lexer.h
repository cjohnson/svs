#ifndef LEXER_H_
#define LEXER_H_

#include <string>
#include <vector>

#include "lexical_token/LexicalToken.h"

#include "FilePosition.h"

namespace svs
{

class WhiteSpaceLexicalToken : public LexicalToken
{
public:
    WhiteSpaceLexicalToken(
        const FilePosition& __file_position,
        const std::string& __raw_token);

    const std::string to_string() const override;
};

class CommentLexicalToken : public LexicalToken
{
public:
    enum Type
    {
        OneLine,
        Block,
    };

    CommentLexicalToken(
        const FilePosition& __file_position,
        const std::string& __raw_token,
        const Type& __comment_type);

    const Type& comment_type();

    const std::string to_string() const override;

private:
    Type _comment_type;
};

class AssignmentOperatorLexicalToken : public LexicalToken
{
public:
    enum Type
    {
        Simple,
        PlusEquals,
        MinusEquals,
        TimesEquals,
        DivideEquals,
        ModuloEquals,
        BitwiseAndEquals,
        BitwiseOrEquals,
        BitwiseExclusiveOrEquals,
        LogicalLeftShiftEquals,
        LogicalRightShiftEquals,
        ArithmeticLeftShiftEquals,
        ArithmeticRightShiftEquals,
    };

    AssignmentOperatorLexicalToken(
        const FilePosition& __file_position,
        const std::string& __raw_token,
        const Type& __assignment_operator_type);

    const std::string to_string() const override;

private:
    Type _assignment_operator_type;
};

class Lexer
{
public:
    bool lex_file(
        const std::string& file_contents,
        std::vector<LexicalToken *>& tokens);
};

}

#endif // LEXER_H_
