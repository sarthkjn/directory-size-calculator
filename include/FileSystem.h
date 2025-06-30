#pragma once
#include "Directory.h"

class FileSystem {
private:
    Directory* root;
    Directory* current;

public:
    FileSystem();

    void seedSampleData();            // Create sample structure
    void listDirectory() const;       // ls
    void changeDirectory(const std::string& dirname); // cd
    void printCurrentPath() const;
    void showSize() const;            // size
    Directory* getRoot() const;
    Directory* getCurrent() const;

};
