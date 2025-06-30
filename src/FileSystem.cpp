#include "../include/FileSystem.h"
#include <iostream>

FileSystem::FileSystem() {
    root = new Directory("root");
    current = root;
    seedSampleData();
}

void FileSystem::seedSampleData() {
    // Add files to root
    root->addFile(File("file1.txt", 100));
    root->addFile(File("file2.log", 200));

    // Add docs/
    root->addSubdirectory("docs");
    Directory* docs = root->getSubdirectory("docs");
    docs->addFile(File("doc1.pdf", 500));
    docs->addFile(File("doc2.pdf", 300));

    // Add images/ with raw/
    root->addSubdirectory("images");
    Directory* images = root->getSubdirectory("images");
    images->addFile(File("img1.png", 1500));

    images->addSubdirectory("raw");
    Directory* raw = images->getSubdirectory("raw");
    raw->addFile(File("raw1.cr2", 2500));
}

void FileSystem::listDirectory() const {
    current->listContents();
}

void FileSystem::changeDirectory(const std::string& dirname) {
    if (dirname == "..") {
        if (current->getParent() != nullptr) {
            current = current->getParent();
        } else {
            std::cout << "Already at root directory.\n";
        }
    } else {
        Directory* subdir = current->getSubdirectory(dirname);
        if (subdir != nullptr) {
            current = subdir;
        } else {
            std::cout << "No such directory: " << dirname << "\n";
        }
    }
}

void FileSystem::showSize() const {
    std::cout << "Total size: " << current->calculateSize() << " bytes\n";
}

void FileSystem::printCurrentPath() const {
    std::cout << current->getName() << " > ";
}

Directory* FileSystem::getRoot() const {
    return root;
}

Directory* FileSystem::getCurrent() const {
    return current;
}

