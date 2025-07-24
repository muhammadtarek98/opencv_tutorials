#include <iostream>
#include<opencv2/imgcodecs.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/highgui.hpp>
int main()
{
    cv::Mat src=cv::imread("/home/muhammad/Downloads/32721009.jpeg");
    cv::Mat dst=cv::Mat::zeros(src.size(),src.type());
    cv::Mat map_x=cv::Mat::zeros(src.size(),CV_32FC1);
    cv::Mat map_y=cv::Mat::zeros(src.size(),CV_32FC1);
    //flip the input image
    auto rows=src.rows;auto cols=src.cols;
    for (int i=0;i<cols;++i)
    {
        for (int j=0;j<rows;++j)
        {
            map_x.at<float>(cv::Point(i,j))=cols-i;
            map_y.at<float>(cv::Point(i,j))=rows-j;
        }
    }
    cv::remap(src,dst,map_x,map_y,cv::INTER_LINEAR);
    cv::imshow("org",src);
    cv::imshow("remaped",dst);
    cv::waitKey(0);
    cv::destroyAllWindows();

    return 0;
}