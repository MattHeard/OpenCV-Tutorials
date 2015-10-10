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
        const string cmdName = "ContrastAndBrighten";
        const string argsDesc = " <Image_Path> <Contrast [1.0-3.0]> "
                " <Brightness [0-100]>";
        std::cout << "Usage: " << cmdName << argsDesc << endl;
        return -1;
    }
    const string srcFilename = argv[1];
    using cv::Mat;
    const Mat src = cv::imread(srcFilename);
    if (!src.data) {
        const string err = "No image data";
        std::cerr << err << endl;
        return -1;
    }
    Mat dst;
    const int rtype = -1;
    double alpha = atof(argv[2]);
    if (alpha < 1.0 || alpha > 3.0) {
        std::cerr << "Invalid contrast, using '1.0'" << endl;
        alpha = 1.0;
    }
    double beta = atof(argv[3]);
    if (beta < 0 || beta > 100) {
        std::cerr << "Invalid brightness, using '0'" << endl;
        beta = 0.0;
    }
    src.convertTo(dst, rtype, alpha, beta);
    const string dstFilename = "output.png";
    cv::imwrite(dstFilename, dst);
    return 0;
}
