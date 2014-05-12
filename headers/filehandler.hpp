#ifndef FILEHANDLER_HPP
#define FILEHANDLER_HPP

#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <ostream>

#include "log.hpp"
#include "defs.hpp"
#include "file.hpp"

namespace mugg {
    class Filehandler {
        private:
            std::ifstream in_stream;
            std::ofstream out_stream;
        public:
            std::string ReadTextFromFilepath(std::string filepath);
            std::vector<char> ReadDataFromFilepath(std::string filepath);
            void WriteDataToFilepath(std::string filepath, std::vector<char> data);
            void AppendDataToFilepath(std::string filepath, std::vector<char> data);
            void AppendStringToFilepath(std::string filepath, std::string what);

            File GetFileFromPath(std::string filepath);
            void WriteFileToPath(mugg::File file, std::string filepath);
    };
}

#endif
