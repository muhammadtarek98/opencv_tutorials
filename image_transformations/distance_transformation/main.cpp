#include <bits/stdc++.h>
#include <opencv2/imgproc.hpp>
#include <opencv2/opencv.hpp>

int main() {
    cv::Mat in{cv::Mat::ones(cv::Size(128,128),CV_8UC1)};
    in.at<u_char>(cv::Point(2,2))=0;
    cv::Mat dst;
    int mask_size=5;
    cv::distanceTransform(in,dst,cv::DIST_L2,mask_size,CV_8U);
    std::cout<<dst;


    return 0;
}
