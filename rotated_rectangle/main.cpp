#include <opencv2/opencv.hpp>
#include <bits/stdc++.h>
int main()
{
    auto img{cv::imread("")};
    std::vector<std::vector<cv::Point>> cont;
    std::vector<cv::Vec4i>hier;
    cv::threshold(img,img,100,255,cv::THRESH_BINARY);
    cv::findContours(img,cont,hier,cv::RETR_EXTERNAL,cv::CHAIN_APPROX_SIMPLE);
    std::vector<cv::RotatedRect> oriented_rect;
    std::vector<cv::Mat> rects_points;
    std::vector<cv::Point>centers;
    cv::Scalar color(255,255,0);
    for (int i=0;i<cont.size();i++)
    {
        oriented_rect.push_back(cv::minAreaRect(cont[i]));
    }
    for (int i=0;i<oriented_rect.size();i++)
    {
        auto curr_rect=oriented_rect[i];
        cv::Mat curr_point;
        cv::boxPoints(curr_rect,curr_point);
        rects_points.push_back(curr_point);
        centers.push_back(curr_rect.center);
    }
    for(int i =0;i<rects_points.size();i++)
    {
        auto points=rects_points[i];
        cv::Point2f p1(points.at<float>(cv::Point(0,0)),points.at<float>(cv::Point(1,0)));
        cv::Point p2(points.at<float>(cv::Point(0,1)),points.at<float>(cv::Point(1,1)));
        cv::Point p3(points.at<float>(cv::Point(0,2)),points.at<float>(cv::Point(1,2)));
        cv::Point p4(points.at<float>(cv::Point(0,3)),points.at<float>(cv::Point(1,3)));
        cv::line(img,p1,p2,color,5);
        cv::line(img,p3,p4,color,5);
        cv::line(img,p1,p3,color,5);
        cv::line(img,p2,p4,color,5);
    }


    return 0;
}