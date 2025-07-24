#include <bits/stdc++.h>
#include <opencv2/opencv.hpp>
#include <opencv2/imgproc.hpp>
int main()
{
    cv::Mat img1=cv::imread("/home/muhammad/Downloads/32721009.jpeg");
    cv::Mat img2;
    std::vector<cv::Point2f>src_points{cv::Point2f(0.0,0.0),cv::Point2f(static_cast<float>(img1.cols),0),cv::Point2f(0,
        static_cast<float>(img1.rows))};
    std::vector<cv::Point2f>dst_points{cv::Point2f(0,500),cv::Point2f(500,100),cv::Point2f(180,500)};
    cv::Mat trans_mat=cv::getAffineTransform(src_points,dst_points);
    cv::warpAffine(img1,img2,trans_mat,cv::Size(500,500));
    cv::imshow("image 1",img1);cv::imshow("image 2",img2);
    cv::waitKey(0);cv::destroyAllWindows();

    return 0;
}