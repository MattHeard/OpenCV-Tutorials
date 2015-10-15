// Copyright 2015 Matt Heard
// http://mattheard.net
// matt@mattheard.net
// @mattheard

#include <opencv2/opencv.hpp>
#include <iostream>
#include <string>

void drawAtom() {
    const int width = 400;
    cv::Mat atomImg = cv::Mat::zeros(width, width, CV_8UC3);
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
