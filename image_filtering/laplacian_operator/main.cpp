#include <bits/stdc++.h>
#include <opencv2/opencv.hpp>
#include <opencv2/imgproc.hpp>
int main()
{
    cv::Mat img{cv::imread("/home/muhammad/Downloads/32721009.jpeg")};
    cv::Mat out;
    cv::cvtColor(img,img,cv::COLOR_BGR2RGB);
    int k_size=3,factor=1,delta=1;
    cv::Laplacian(img,out,-1,k_size,factor,delta);
    cv::imshow("test",out);
    cv::waitKey(0);
    cv::destroyAllWindows();
    return 0;
}