// Copyright 2015 Matt Heard
// http://mattheard.net
// matt@mattheard.net
// @mattheard

#include <opencv2/opencv.hpp>
#include <iostream>
#include <string>

using cv::Mat;

Mat drawBlankCanvas() {
    const int rows = 400;
    const int cols = 400;
    const int type = CV_8UC3;
    return Mat::zeros(rows, cols, type);
}

void drawAtom() {
    Mat atomImg = drawBlankCanvas();
    cv::imwrite("atom.jpg", atomImg);
}

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
    drawAtom();
    return 0;
}
