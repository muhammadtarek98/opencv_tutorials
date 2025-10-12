#include <bits/stdc++.h>
#include <opencv2/imgproc.hpp>
int main() {
    cv::Mat img=cv::Mat::zeros(cv::Size(3,3),CV_32F);
    img.at<uchar>(cv::Point(0,0))=125;
    img.at<uchar>(cv::Point(0,1))=5;
    img.at<uchar>(cv::Point(0,2))=1;

    img.at<uchar>(cv::Point(1,0))=88;
    img.at<uchar>(cv::Point(1,1))=55;
    img.at<uchar>(cv::Point(1,2))=166;

    img.at<uchar>(cv::Point(2,0))=128;
    img.at<uchar>(cv::Point(2,1))=123;
    img.at<uchar>(cv::Point(2,2))=121;

    cv::Mat dst,dst1;
    cv::integral(img,dst,CV_32F);
    cv::integral(img,dst,dst1,CV_32F,CV_32F);
    std::cout<<img<<std::endl;
    std::cout<<dst<<std::endl;
    std::cout<<dst1<<std::endl;
    return 0;
}
