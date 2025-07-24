#include <bits/stdc++.h>
#include <opencv2/opencv.hpp>
int main()
{
    cv::Mat src=cv::imread("/home/muhammad/Downloads/unnamed.jpg");
    cv::Mat dst=cv::Mat::zeros(src.size(),src.type());
    int max_radius=50,flag=cv::INTER_LINEAR;
    cv::Point2f center(src.cols/2,src.rows/2);
    cv::warpPolar(src,dst,src.size(),center,max_radius,flag+cv::WARP_INVERSE_MAP);
    cv::imshow("dst",dst);
    cv::waitKey(0);
    cv::destroyAllWindows();
    return 0;
}