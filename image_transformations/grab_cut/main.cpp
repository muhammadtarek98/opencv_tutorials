#include<bits/stdc++.h>
#include <opencv2/opencv.hpp>
#include <opencv2/imgproc.hpp>
int main()
{
    cv::Mat img{cv::imread("/home/muhammad/Downloads/unnamed.jpg")},mask,bg,fg;
    int iter=1;
    auto mode=cv::GC_INIT_WITH_RECT;
    cv::cvtColor(img,img,cv::COLOR_BGR2RGB);
    auto res{img.clone()};
    cv::Rect r=cv::selectROI(img);
    cv::grabCut(img,mask,r,bg,fg,iter,mode);
    for (int i=0;i<img.cols;++i)
    {
        for (int j=0;j<img.rows;++j)
        {
            if (mask.at<u_char>(cv::Point(i,j))==0)
            {
                res.at<cv::Vec2b>(cv::Point(i,j))[0]=0;
                res.at<cv::Vec2b>(cv::Point(i,j))[1]=0;
                res.at<cv::Vec2b>(cv::Point(i,j))[2]=0;
            }
            else if (mask.at<u_char>(cv::Point(i,j))==1)
            {
                res.at<cv::Vec2b>(cv::Point(i,j))[0]=255;
                res.at<cv::Vec2b>(cv::Point(i,j))[1]=0;
                res.at<cv::Vec2b>(cv::Point(i,j))[2]=0;
            }
            else if (mask.at<u_char>(cv::Point(i,j))==2)
            {
                res.at<cv::Vec2b>(cv::Point(i,j))[0]=255;
                res.at<cv::Vec2b>(cv::Point(i,j))[1]=255;
                res.at<cv::Vec2b>(cv::Point(i,j))[2]=0;
            }
        }
    }
    cv::imshow("input",img);
    cv::imshow("background",bg);
    cv::imshow("foreground",fg);
    cv::waitKey(0);
    cv::destroyAllWindows();

    return 0;
}