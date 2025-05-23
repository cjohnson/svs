#ifndef SVS_FILE_POSITION_H_
#define SVS_FILE_POSITION_H_

#include <string>

namespace svs {

///
/// A position in a source document. Contains the line and column,
/// rather than just the amount of characters since the beginning
/// of the file.
///
struct FilePosition
{
    ///
    /// The line in the file. Zero-indexed - the first line in a file is 0.
    ///
    unsigned int line;

    ///
    /// The column in the line. Zero-indexed - the first character after the newline
    /// is 0.
    ///
    unsigned int col;

    ///
    /// Convert the file position information to a string.
    ///
    const std::string to_string() const;
};

}

#endif // SVS_FILE_POSITION_H_
