#include <bits/stdc++.h>
#include<opencv2/opencv.hpp>
int main()
{
    auto img{cv::imread("/home/muhammad/Downloads/unnamed.jpg",cv::IMREAD_GRAYSCALE)};
    cv::Mat bin_img;
    cv::Mat mask{cv::Mat::zeros(img.size(),CV_8UC3)};
    std::vector<std::vector<cv::Point>> contours;
    std::vector<cv::Vec4i> hierarchy;
    cv::threshold(img,bin_img,100,255,cv::THRESH_BINARY);
    cv::findContours(bin_img,contours,hierarchy,cv::RETR_TREE,cv::CHAIN_APPROX_SIMPLE);
    cv::drawContours(mask,contours,-1,cv::Scalar(0,255,255),1);
    for (auto i=0;i<contours.size();++i)
    {
        cv::putText(mask,std::to_string(i),contours[i][0],1,1,cv::Scalar(0,255,255),1);
    }
    std::cout<<hierarchy.size()<<std::endl;
    for (const auto &cont:hierarchy)
    {
        std::cout<<cont<<std::endl;
    }


    return 0;
}