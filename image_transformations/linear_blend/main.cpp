#include <bits/stdc++.h>
#include <opencv2/opencv.hpp>
#include<opencv2/imgproc.hpp>
int main() {
    cv::Mat im1{cv::imread("/home/muhammad/Downloads/unnamed.jpg")};
    cv::cvtColor(im1,im1,cv::COLOR_BGR2RGB);

    cv::Mat im2{cv::imread("/home/muhammad/Downloads/32721009.jpeg")};
    cv::resize(im1,im1,im2.size());
    cv::cvtColor(im2,im2,cv::COLOR_BGR2RGB);
    cv::Mat w1{cv::Mat::ones(im1.size(),CV_32FC1)};
    cv::Mat w2{cv::Mat::ones(im2.size(),CV_32FC1)};
    cv::Mat dst;
    cv::blendLinear(im1,im2,w1,w2,dst);
    cv::cvtColor(dst,dst,cv::COLOR_BGR2RGB);
    cv::imshow("test",dst);
    cv::waitKey(0);
    cv::destroyAllWindows();

    return 0;
}
