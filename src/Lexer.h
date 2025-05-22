#ifndef LEXER_H_
#define LEXER_H_

#include <string>
#include <vector>

namespace svs
{

struct FilePosition
{
    unsigned int line;
    unsigned int col;

    const std::string to_string() const;
};

enum LexicalTokenType
{
    WhiteSpace,
    Comment,
};

class LexicalToken
{
protected:
    LexicalToken(
        const LexicalTokenType& __type,
        const FilePosition& __file_position,
        const std::string& __raw_token);

public:
    const LexicalTokenType& type() const;

    const FilePosition& file_position() const;

    const std::string& raw_token() const;

    const virtual std::string to_string() const = 0;

    virtual ~LexicalToken() = default;

private:
    LexicalTokenType _type;
    FilePosition _file_position;
    std::string _raw_token;
};

class WhiteSpaceLexicalToken : public LexicalToken
{
public:
    WhiteSpaceLexicalToken(
        const FilePosition& __file_position,
        const std::string& __raw_token);

    const std::string to_string() const override;
};

enum CommentLexicalTokenType
{
    OneLine,
    Block,
};

class CommentLexicalToken : public LexicalToken
{
public:
    CommentLexicalToken(
        const FilePosition& __file_position,
        const std::string& __raw_token,
        const CommentLexicalTokenType& __comment_type);

    const CommentLexicalTokenType& comment_type();

    const std::string to_string() const override;

private:
    CommentLexicalTokenType _comment_type;
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
