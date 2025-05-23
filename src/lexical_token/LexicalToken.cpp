#include "LexicalToken.h"

svs::LexicalToken::LexicalToken(
    const svs::LexicalToken::Type& __type,
    const svs::FilePosition& __file_position,
    const std::string& __raw_token)
    : _type(__type),
      _file_position(__file_position),
      _raw_token(__raw_token)
{}

const bool svs::LexicalToken::is_ignored() const
{
    switch (_type) {
    case WhiteSpace:
    case Comment:
        return true;
    default:
        return false;
    }
}

const svs::LexicalToken::Type& svs::LexicalToken::type() const
{
    return _type;
}

const svs::FilePosition& svs::LexicalToken::file_position() const
{
    return _file_position;
}

const std::string& svs::LexicalToken::raw_token() const
{
    return _raw_token;
}
