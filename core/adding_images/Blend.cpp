// Copyright 2015 Matt Heard
// http://mattheard.net
// matt@mattheard.net
// @mattheard

#include <opencv2/opencv.hpp>
#include <iostream>
#include <string>

int main(int argc, char **argv) {
    using std::string;
    const int expectedNumArgs = 4;
    if (argc != expectedNumArgs) {
        const string cmdName = "Blend";
        const string argsDesc = " <Image1_Path> <Image2_Path> <Alpha>";
        std::cout << "Usage: " << cmdName << argsDesc << std::endl;
        return -1;
    }
    return 0;
}
