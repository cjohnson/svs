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

class LexicalToken
{
public:
    enum Type
    {
        WhiteSpace,
        Comment,
    };

protected:
    LexicalToken(
        const Type& __type,
        const FilePosition& __file_position,
        const std::string& __raw_token);

public:
    virtual ~LexicalToken() = default;

    const bool is_ignored() const;

    const Type& type() const;

    const FilePosition& file_position() const;

    const std::string& raw_token() const;

    const virtual std::string to_string() const = 0;

private:
    Type _type;
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

class Lexer
{
public:
    bool lex_file(
        const std::string& file_contents,
        std::vector<LexicalToken *>& tokens);
};

}

#endif // LEXER_H_
