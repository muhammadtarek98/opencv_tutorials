#include <bits/stdc++.h>
#include <opencv2/opencv.hpp>
#include <opencv2/imgproc.hpp>
void get_histogram(cv::Mat &img,cv::Mat &hist)
{
    float range[]{0,256};
    const int hist_sz{256};
    const int channel_num{0};
    const float *hist_range{range};
    cv::Mat mask;
    cv::calcHist(&img,1,&channel_num,mask,hist,1,&hist_sz,&hist_range);}
int main()
{
    cv::Mat img1{cv::imread("/home/muhammad/Downloads/unnamed.jpg",cv::IMREAD_GRAYSCALE)};
    cv::Mat img2{cv::imread("/home/muhammad/Downloads/32721009.jpeg",cv::IMREAD_GRAYSCALE)};
    cv::Mat hist1,hist2;
    get_histogram(img1,hist1);
    get_histogram(img2,hist2);
    auto res=    cv::compareHist(hist1,hist2,cv::HISTCMP_CORREL);
    std::cout<<res;
    return 0;
}