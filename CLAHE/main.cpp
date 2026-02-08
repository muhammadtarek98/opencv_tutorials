#include <bits/stdc++.h>
#include <opencv2/opencv.hpp>
int main()
{
    auto image{cv::imread("/home/muhammad/Downloads/32721009.jpeg")};
    cv::cvtColor(image,image,cv::COLOR_BGR2RGB);
    std::vector<cv::Mat> channels;
    cv::Mat clahe_res;
    cv::split(image,channels);
    double clip_limit{100};
    cv::Size size(8,8);
    auto clahe=cv::createCLAHE(clip_limit,size);
    clahe->apply(channels[0],channels[0]);
    clahe->apply(channels[1],channels[1]);
    clahe->apply(channels[2],channels[2]);
    cv::merge(channels,clahe_res);
    cv::imshow("",clahe_res);
    cv::waitKey(0);
    cv::destroyAllWindows();

    return 0;
}