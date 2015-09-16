// Copyright 2015 Matt Heard
// http://mattheard.net
// matt@mattheard.net
// @mattheard

#include <opencv2/opencv.hpp>
#include <iostream>
#include <string>

int main(int argc, char **argv) {
    using std::string;
    const int expectedNumArgs = 2;
    if (argc != expectedNumArgs) {
        const string cmdName = "DisplayImage";
        const string argsDesc = " <Image_Path>";
        std::cout << "Usage: " << cmdName << argsDesc << std::endl;
        return -1;
    }
    const string filename = argv[1];
    const cv::Mat img = cv::imread(filename);
    if (!img.data) {
        const string err = "No image data";
        std::cerr << err << std::cout;
        return -1;
    }

    // The tutorial calls `namedWindow` and `imshow` to display the input image
    // in a GUI window, but as I'm currently running these tutorials on a
    // headless Raspberry Pi, I will not do that. Where future tutorials show
    // modified images, I will write them to files instead with `imwrite`, and
    // view them on a browser across my local network.

    return 0;
}
