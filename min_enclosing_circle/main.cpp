#include <bits/stdc++.h>
#include <opencv2/opencv.hpp>
int main()
{
    auto img{cv::imread("")};
    cv::Mat out=cv::Mat::zeros(img.size(),CV_8UC1);
    std::vector<std::vector<cv::Point>> cont;
    std::vector<cv::Vec4i>hier;
    cv::threshold(img,img,100,255,cv::THRESH_BINARY);
    cv::findContours(img,cont,hier,cv::RETR_EXTERNAL,cv::CHAIN_APPROX_SIMPLE);
    std::vector<cv::Point2f> centers(cont.size());
    std::vector<float> radii(cont.size());
    for (int i=0;i<cont.size();i++)
     {
         cv::minEnclosingCircle(cont[i],centers[i],radii[i]);
         cv::circle(out,centers[i],static_cast<int>(radii[i]),cv::Scalar(255,255,0),5);
    }
    return 0;
}