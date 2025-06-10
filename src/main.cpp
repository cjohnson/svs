#include <iostream>
#include <fstream>
#include <sstream>

int main(int argc, char **argv)
{
    if (argc < 2)
    {
        std::cerr << "Usage: svsc <filename>\n";
        return 1;
    }
    std::string file_name{argv[1]};

    std::ifstream file_stream{file_name};
    std::stringstream file_string_stream;
    file_string_stream << file_stream.rdbuf();
    std::string file_buffer{file_string_stream.str()};

    return 0;
}
