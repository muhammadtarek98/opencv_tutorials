#include <iostream>
#include <opencv2/imgproc.hpp>
int main()
{
    cv::Mat input1=cv::Mat::zeros(cv::Size(5,5),CV_32FC1);
    cv::Mat input2=cv::Mat::zeros(cv::Size(5,5),CV_32FC1);
    cv::Mat output1=cv::Mat::zeros(cv::Size(5,5),CV_16SC2);
    cv::Mat output2=cv::Mat::zeros(cv::Size(5,5),CV_16UC1);
    input1.at<float>(cv::Point(0,4))=8.1;
    input2.at<float>(cv::Point(1,3))=3.4;

    cv::convertMaps(input1,input2,output1,output2,CV_16SC2);
    std::cout<<input1<<std::endl;
    std::cout<<input2<<std::endl;
    std::cout<<output1<<std::endl;
    std::cout<<output2<<std::endl;
    return 0;
}