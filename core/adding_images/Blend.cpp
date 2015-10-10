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
    const int expectedNumArgs = 4;
    if (argc != expectedNumArgs) {
        const string cmdName = "Blend";
        const string argsDesc = " <Image1_Path> <Image2_Path> <Alpha>";
        std::cout << "Usage: " << cmdName << argsDesc << endl;
        return -1;
    }
    const string src1Filename = argv[1];
    using cv::Mat;
    using cv::imread;
    const Mat src1 = imread(src1Filename);
    const string src2Filename = argv[2];
    const Mat src2 = imread(src2Filename);
    if (!src1.data || !src2.data) {
        const string err = "No image data";
        std::cerr << err << endl;
        return -1;
    }
    const double alpha = atof(argv[3]);
    const double beta = 1.0 - alpha;
    const double gamma = 0.0;
    Mat dst;
    cv::addWeighted(src1, alpha, src2, beta, gamma, dst);
    const string dstFilename = "blended.png";
    cv::imwrite(dstFilename, dst);
    return 0;
}
