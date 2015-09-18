// Copyright 2015 Matt Heard
// http://mattheard.net
// matt@mattheard.net
// @mattheard

#include <opencv2/opencv.hpp>
#include <iostream>
#include <string>

using cv::Mat;

int main(int argc, char **argv) {
    using std::string;
    const int expectedNumArgs = 2;
    if (argc != expectedNumArgs) {
        const string cmdName = "Sharpen";
        const string argsDesc = " <Image_Path>";
        std::cout << "Usage: " << cmdName << argsDesc << std::endl;
        return -1;
    }
    const string inputFilename = argv[1];
    const Mat srcImg = cv::imread(inputFilename);
    if (!srcImg.data) {
        const string err = "No image data";
        std::cerr << err << std::endl;
        return -1;
    }
    return 0;
}
