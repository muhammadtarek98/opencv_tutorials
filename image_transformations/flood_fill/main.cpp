#include <bits/stdc++.h>
#include <opencv2/opencv.hpp>
#include <opencv2/imgproc.hpp>
int main()
{
    cv::Mat img{cv::imread("/home/muhammad/Downloads/unnamed.jpg")};
    cv::cvtColor(img,img,cv::COLOR_BGR2GRAY);
    cv::namedWindow("test2");
    cv::namedWindow("test");
    cv::Mat dst=img.clone(),mask;
    cv::Point p(10,10);
    cv::Scalar val(100),up(200),lower(50);
    cv::Rect r;
    cv::floodFill(dst,p,val);
    cv::imshow("test2",dst);
    cv::floodFill(dst,mask,p,val,&r,lower,up,cv::FLOODFILL_FIXED_RANGE);
    cv::imshow("test",dst);
    cv::waitKey(0);
    cv::destroyAllWindows();
    return 0;
}