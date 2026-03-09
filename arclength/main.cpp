#include <bits/stdc++.h>
#include <opencv2/opencv.hpp>
int main()
{
    auto img{cv::imread("")};
    std::vector<std::vector<cv::Point>> contours;
    std::vector<cv::Vec4i>hier;
    cv::threshold(img,img,100,255,cv::THRESH_BINARY);
    cv::findContours(img,contours,cv::RETR_EXTERNAL,cv::CHAIN_APPROX_SIMPLE);
for (int i=0;i<contours.size();i++)
{
    cv::Point2f center;
    cv::Point start=contours[i][0],end=contours[i][contours[i].size()-1];
    float radius;
    cv::minEnclosingCircle(contours[i],center,radius);
    auto perimeter=cv::arcLength(contours[i],start==end?true:false);
}


    return 0;
}