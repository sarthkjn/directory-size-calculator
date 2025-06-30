#include "Directory.h"
#include <iostream>

Directory::Directory(const std::string& name, Directory* parent)
    : name(name), parent(parent) {}

const std::string& Directory::getName() const {
    return name;
}

Directory* Directory::getParent() const {
    return parent;
}

void Directory::addFile(const File& file) {
    files.push_back(file);
}

void Directory::addSubdirectory(const std::string& dirname) {
    if (subdirectories.find(dirname) == subdirectories.end()) {
        subdirectories[dirname] = std::make_unique<Directory>(dirname, this);
    }
}

Directory* Directory::getSubdirectory(const std::string& dirname) {
    if (subdirectories.find(dirname) != subdirectories.end()) {
        return subdirectories[dirname].get();
    }
    return nullptr;
}

void Directory::listContents() const {
    for (const auto& file : files) {
        std::cout << "FILE: " << file.getName() << " (" << file.getSize() << " bytes)\n";
    }
    for (const auto& pair : subdirectories) {
        std::cout << "DIR: " << pair.first << "\n";
    }
}

int Directory::calculateSize() const {
    int totalSize = 0;

    for (const auto& file : files) {
        totalSize += file.getSize();
    }

    for (const auto& pair : subdirectories) {
        totalSize += pair.second->calculateSize();  // recursive call
    }

    return totalSize;
}
