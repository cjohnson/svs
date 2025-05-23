#include <sstream>

#include "FilePosition.h"

const std::string svs::FilePosition::to_string() const
{
    std::stringstream ss;
    ss << "FilePosition{ ";
    ss << "Line=" << line << " ";
    ss << "Col=" << col << " ";
    ss << "}";

    return ss.str();
}
