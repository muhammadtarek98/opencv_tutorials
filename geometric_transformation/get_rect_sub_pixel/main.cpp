#include <iostream>
#include <opencv2/opencv.hpp>
int main()
{
    cv::Mat src=cv::imread("/home/muhammad/Downloads/unnamed.jpg");
    cv::Mat dst;

    cv::Size sz(100,100);
    cv::Point2f center(10,10);
    cv::Rect rect(sz,center);
    cv::getRectSubPix(src,sz,center,dst);
    cv::Mat dst2=src(rect);
    cv::imshow("dest 1",dst);
    cv::imshow("dest 2",dst2);
    cv::waitKey(0);
    cv::destroyAllWindows();



    return 0;
}