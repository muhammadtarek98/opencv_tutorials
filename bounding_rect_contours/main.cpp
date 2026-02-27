#include <bits/stdc++.h>
#include <opencv2/opencv.hpp>
#include <opencv2/imgproc.hpp>
int main()
{
    auto img{cv::imread("")};
    std::vector<std::vector<cv::Point>> contours;
    std::vector<cv::Vec2i> hierarchy;
    cv::threshold(img,img,100,255,cv::THRESH_BINARY);
    cv::findContours(img,contours,hierarchy,cv::RETR_EXTERNAL,cv::CHAIN_APPROX_SIMPLE);
    cv::Mat out{cv::Mat::zeros(img.size(),CV_8UC3)};
    auto color{cv::Scalar(255,0,0)};
    int rect_thickness{5};

    for (auto i=0;i<contours.size();++i)
    {
        auto rect=cv::boundingRect(contours[i]);

        cv::rectangle(out, rect, (color), rect_thickness);
    }

    return 0;
}