// Copyright 2015 Matt Heard
// http://mattheard.net
// matt@mattheard.net
// @mattheard

#include <opencv2/opencv.hpp>
#include <iostream>
#include <string>

int main(int argc, char **argv) {
    using std::string;
    using std::endl;
    const int expectedNumArgs = 1;
    if (argc != expectedNumArgs) {
        const string cmdName = "Draw";
        const string argsDesc = "";
        std::cout << "Usage: " << cmdName << argsDesc << endl;
        return -1;
    }
    return 0;
}
