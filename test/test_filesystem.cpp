#include <iostream>
#include "FileSystem.h"
using std::cout;


void testRootSize() {
    FileSystem fs;
    int expected = 100 + 200 + 500 + 300 + 1500 + 2500;
    int actual = fs.getRoot()->calculateSize();  // You may need to make `root` public or friend
    if (actual == expected) {
        cout << "[PASS] Root directory size\n";
    } else {
        cout << "[FAIL] Root size: expected " << expected << ", got " << actual << "\n";
    }
}

void testDocsSize() {
    FileSystem fs;
    Directory* docs = fs.getRoot()->getSubdirectory("docs");
    if (docs && docs->calculateSize() == 800) {
        cout << "[PASS] docs/ directory size\n";
    } else {
        cout << "[FAIL] docs/ directory size\n";
    }
}

void testChangeDirectory() {
    FileSystem fs;
    fs.changeDirectory("docs");
    if (fs.getCurrent()->getName() == "docs") {
        cout << "[PASS] cd docs\n";
    } else {
        cout << "[FAIL] cd docs failed\n";
    }

    fs.changeDirectory("..");
    if (fs.getCurrent()->getName() == "root") {
        cout << "[PASS] cd .. back to root\n";
    } else {
        cout << "[FAIL] cd .. failed\n";
    }
}

int main() {
    cout << "Running unit tests...\n\n";
    testRootSize();
    testDocsSize();
    testChangeDirectory();
    return 0;
}
