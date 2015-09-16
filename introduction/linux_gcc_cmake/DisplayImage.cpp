// Copyright 2015 Matt Heard
// http://mattheard.net
// matt@mattheard.net
// @mattheard

#include <iostream>
#include <string>

int main(int argc, char **argv) {
    const int expectedNumArgs = 2;
    if (argc != expectedNumArgs) {
        using std::string;
        const string cmdName = "DisplayImage";
        const string argsDesc = " <Image_Path>";
        std::cout << "Usage: " << cmdName << argsDesc << std::endl;
        return -1;
    }
    return 0;
}
