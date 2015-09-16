// Copyright 2015 Matt Heard
// http://mattheard.net
// matt@mattheard.net
// @mattheard

#include <opencv2/opencv.hpp>
#include <iostream>
#include <string>

using cv::Mat;

// TODO(mattheard): Implement me
Mat convertToGrey(const Mat &src) {
    return Mat();
}

int main(int argc, char **argv) {
    using std::string;
    const int expectedNumArgs = 2;
    if (argc != expectedNumArgs) {
        const string cmdName = "ConvertToGrey";
        const string argsDesc = " <Image_Path>";
        std::cout << "Usage: " << cmdName << argsDesc << std::endl;
        return -1;
    }
    const string filename = argv[1];
    const Mat srcImg = cv::imread(filename);
    if (!srcImg.data) {
        const string err = "No image data";
        std::cerr << err << std::cout;
        return -1;
    }
    const Mat greyImg = convertToGrey(srcImg);
    return 0;
}
