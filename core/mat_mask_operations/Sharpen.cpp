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
    const string srcFilename = argv[1];
    const Mat src = cv::imread(srcFilename);
    if (!src.data) {
        const string err = "No image data";
        std::cerr << err << std::endl;
        return -1;
    }
    const Mat kernel = (cv::Mat_<char>(3, 3) <<
             0, -1,  0,
            -1,  5, -1,
             0, -1,  0);
    Mat dst;
    cv::filter2D(src, dst, src.depth(), kernel);
    const string dstFilename = "sharpened.jpg";
    cv::imwrite(dstFilename, dst);
    return 0;
}
