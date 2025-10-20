#ifndef SVS_COMPILER_SV2017_SCANNER_H_
#define SVS_COMPILER_SV2017_SCANNER_H_

#include <cstdio>
#include <string>

#include "scanner_impl.h"
#include "parser_impl.h"

namespace svs::sv2017 {

//
// Scanner for SystemVerilog 2017.
// Produces a token stream from standard input.
//
class scanner {
public:
    //
    // Attempts to read the next token into the provided token reference.
    // If EOF is read, token is YYEOF.
    //
    scanner& operator>>(yytokentype& token);

    //
    // Returns true if the scanner has not yet read input EOF.
    //
    operator bool() const;

private:
    //
    // The last token read.
    //
    yytokentype last;
};

//
// File scanner for SystemVerilog 2017.
// Produces a token stream from the provided file.
//
class file_scanner : public scanner {
public:
    //
    // Constructor for the file scanner.
    //
    file_scanner(const std::string& file_path);

    //
    // Destructor for the file scanner.
    //
    ~file_scanner();

private:
    //
    // The C file handle
    //
    FILE *file_handle;
};

//
// String scanner for SystemVerilog 2017.
// Produces a token stream from the provided string.
//
class string_scanner : public scanner {
public:
    //
    // Constructor for the string scanner.
    //
    string_scanner(const std::string& string);

    //
    // Destructor for the string scanner.
    //
    ~string_scanner();

private:
    //
    // The buffer state; handle to the scratchpad copy of the provided string input.
    //
    YY_BUFFER_STATE buffer_state;
};

}

#endif // SVS_COMPILER_SV2017_SCANNER_H_

