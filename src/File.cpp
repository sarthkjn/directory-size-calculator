#include "File.h"
using namespace std;

File::File(const string& name, int size) : name(name), size(size) {}

string File::getName() const {
    return name;
}

int File::getSize() const {
    return size;
}
