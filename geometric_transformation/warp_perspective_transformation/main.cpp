#include <bits/stdc++.h>
#include <opencv2/opencv.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/core.hpp>
int main()
{
    cv::Mat img1=cv::imread("/home/muhammad/Downloads/32721009.jpeg");
    cv::Mat img2;
    cv::Size dstsize(300,300);
    std::vector<cv::Point2f> src_points{
        cv::Point(100,100),
        cv::Point(150,150),
        cv::Point(200,200),
        cv::Point(250,250)
    };
    std::vector<cv::Point2f> dst_points{
        cv::Point(100,100),
               cv::Point(150,150),
               cv::Point(200,200),
               cv::Point(250,250)
    };
    cv::Mat trans_mat=cv::getPerspectiveTransform(src_points,dst_points);
    cv::warpPerspective(img1,img2,trans_mat,dstsize);
    cv::imshow("image 1",img1);
    cv::imshow("image 2",img2);
    cv::waitKey(0);
    cv::destroyAllWindows();



    return 0;
}