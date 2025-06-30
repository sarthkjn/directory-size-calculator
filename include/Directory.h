#pragma once

#include <string>
#include <vector>
#include <map>
#include <memory>
#include "File.h"

class Directory {
private:
    std::string name;
    Directory* parent;
    std::vector<File> files;
    std::map<std::string, std::unique_ptr<Directory>> subdirectories;

public:
    Directory(const std::string& name, Directory* parent = nullptr);

    const std::string& getName() const;
    Directory* getParent() const;

    void addFile(const File& file);
    void addSubdirectory(const std::string& dirname);
    Directory* getSubdirectory(const std::string& dirname);

    void listContents() const;
    int calculateSize() const;
};
