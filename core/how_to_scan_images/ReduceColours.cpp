// Copyright 2015 Matt Heard
// http://mattheard.net
// matt@mattheard.net
// @mattheard

#include <opencv2/opencv.hpp>
#include <iostream>
#include <string>

using cv::Mat;

Mat buildLookUpTable(const int divideWith) {
    const int rows = 1;
    const int cols = 256;
    const int type = CV_8U;
    const Mat table(rows, cols, type);
    for (int i = 0; i < 256; ++i) {
        const int reduced = divideWith * (i / divideWith);
        table.data[i] = (uchar) reduced;
    }
    return table;
}

int main(int argc, char **argv) {
    using std::string;
    const int expectedNumArgs = 3;
    if (argc != expectedNumArgs) {
        const string cmdName = "ConvertToGrey";
        const string argsDesc = " <Image_Path> <Reduce_By>";
        std::cout << "Usage: " << cmdName << argsDesc << std::endl;
        return -1;
    }
    const string inputFilename = argv[1];
    const Mat srcImg = cv::imread(inputFilename);
    if (!srcImg.data) {
        const string err = "No image data";
        std::cerr << err << std::cout;
        return -1;
    }
    const int divideWith = atoi(argv[2]);
    if (divideWith < 1) {
        std::cout << "Invalid number entered for dividing." << std::endl;
        return -1;
    }
    const Mat lookUpTable = buildLookUpTable(divideWith);
    Mat dstImg;
    LUT(srcImg, lookUpTable, dstImg);
    const string outputFilename = "reduced.jpg";
    imwrite(outputFilename, dstImg);
    return 0;
}
