// Copyright 2015 Matt Heard
// http://mattheard.net
// matt@mattheard.net
// @mattheard

#include <opencv2/opencv.hpp>
#include <iostream>
#include <string>

using cv::Mat;

const int width = 400;

Mat drawBlankCanvas() {
    const int rows = width;
    const int cols = width;
    const int type = CV_8UC3;
    return Mat::zeros(rows, cols, type);
}

using cv::Point;
using cv::Scalar;

void drawEllipse(Mat img, const double angle) {
    const Point center(width / 2, width / 2);
    const cv::Size axes(width / 4, width / 16);
    const double startAngle = 0;
    const double endAngle = 360;
    const Scalar BLUE(255, 0, 0);
    const Scalar color = BLUE;
    const int thickness = 2;
    cv::ellipse(img, center, axes, angle, startAngle, endAngle, color,
            thickness);
}

void drawAtomEllipses(Mat img) {
    const double angles[] = { -45.0, 0.0, 45.0, 90.0 };
    const size_t numAngles = sizeof(angles) / sizeof(angles[0]);
    for (size_t i = 0; i < numAngles; ++i) {
        const double angle = angles[i];
        drawEllipse(img, angle);
    }
}

void drawAtomDot(Mat img) {
    const Point center(width / 2, width / 2);
    const int radius = width / 32;
    const Scalar RED(0, 0, 255);
    const Scalar color = RED;
    const int FILL = -1;
    const int thickness = FILL;
    cv::circle(img, center, radius, color, thickness);
}

void drawAtom() {
    Mat img = drawBlankCanvas();
    drawAtomEllipses(img);
    drawAtomDot(img);
    cv::imwrite("atom.jpg", img);
}

void drawRook() {
    Mat img = drawBlankCanvas();
    cv::imwrite("rook.jpg", img);
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
    drawRook();
    return 0;
}
