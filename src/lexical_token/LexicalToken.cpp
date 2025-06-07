#include "LexicalToken.h"

svs::LexicalToken::LexicalToken(
    const svs::LexicalToken::Type& __type,
    const svs::FilePosition& __file_position)
    : _type(__type),
      _file_position(__file_position)
{}

const svs::LexicalToken::Type& svs::LexicalToken::type() const
{
    return _type;
}

const svs::FilePosition& svs::LexicalToken::file_position() const
{
    return _file_position;
}
