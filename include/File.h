#pragma once
#include <string>

class File {
private:
    std::string name;
    int size;

public:
    File(const std::string& name, int size);
    std::string getName() const;
    int getSize() const;
};
