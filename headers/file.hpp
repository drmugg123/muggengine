#ifndef FILE_HPP
#define FILE_HPP

#include <vector>
#include <string>

namespace mugg {
    class File {
        private:
            std::string filepath, data;
        public:
            void SetFilepath(std::string filepath);
            std::string GetFilepath();

            std::size_t GetSize();

            void SetData(std::string data);
            std::string GetData();
    };
}

#endif
