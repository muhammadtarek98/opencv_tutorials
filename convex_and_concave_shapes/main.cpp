#include <bits/stdc++.h>
#include <opencv2/opencv.hpp>
int main()
{
    auto img{cv::imread("")};
    cv::Mat out{cv::Mat::zeros(img.size(),CV_8UC1)};
    std::vector<std::vector<cv::Point>>cont;
    std::vector<cv::Vec4i>hier;
    cv::threshold(img,img,100,255,cv::THRESH_BINARY);
    cv::findContours(img,cont,hier,cv::RETR_EXTERNAL,cv::CHAIN_APPROX_SIMPLE);
    std::vector<cv::Point2f>center(cont.size());
    std::vector<float>radii(cont.size());
    std::vector<bool> convexities(cont.size());
    for (int i=0;i<cont.size();i++)
    {
        cv::minEnclosingCircle(cont[i],center[i],radii[i]);
        auto convexity=cv::isContourConvex(cont[i]);
        convexities.push_back(convexity);
    }

    return 0;
}