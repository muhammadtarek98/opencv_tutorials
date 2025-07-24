#include <bits/stdc++.h>
#include <opencv2/opencv.hpp>
#include<opencv2/imgproc.hpp>
int main()
{
    cv::Mat img1=cv::imread("/home/muhammad/Downloads/32721009.jpeg");
    cv::Mat img2;
    double angle=50,scale=2.0;
    cv::Point2f rotation_point(200,100);
    cv::Size sz(400,400);
    cv::Mat Rotation_mat=cv::getRotationMatrix2D(rotation_point,angle,scale);
    cv::warpAffine(img1,img2,Rotation_mat,sz);
    cv::imshow("image 1",img1);cv::imshow("rotated image",img2);
    cv::waitKey(0);cv::destroyAllWindows();


    return 0;
}