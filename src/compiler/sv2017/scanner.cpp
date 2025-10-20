#include <sstream>
#include <stdexcept>

#include "scanner.h"

extern int yylex(void);

using namespace svs::sv2017;

scanner& scanner::operator>>(yytokentype& token) {
    last = token = (yytokentype)yylex();
    return *this;
}

scanner::operator bool() const {
    return last != YYEOF;
}

file_scanner::file_scanner(const std::string& file_path) {
    file_handle = yyin = fopen(file_path.c_str(), "r");
    if (!file_handle) {
        std::stringstream ss;
        ss << "Failed to open file: ";
        ss << file_path;
        throw std::runtime_error(ss.str());
    }
}

file_scanner::~file_scanner() {
    fclose(file_handle);
}

string_scanner::string_scanner(const std::string& string) {
    buffer_state = yy_scan_string(string.c_str());
}

string_scanner::~string_scanner() {
    yy_delete_buffer(buffer_state);
}
