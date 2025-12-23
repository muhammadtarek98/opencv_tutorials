#include <opencv2/imgproc.hpp>
#include <opencv2/opencv.hpp>
#include <bits/stdc++.h>
int main()
{
    cv::Mat src{cv::imread("/home/muhammad/Downloads/unnamed.jpg",cv::IMREAD_GRAYSCALE)};
    cv::Mat out,graph,mask;
    float ranges[]{0,256};
    const float *hist_range{ranges};
    const int sz{256},channelnum{0};
    cv::calcHist(&src,1,&channelnum,mask,out,1,&sz,&hist_range);
    int sum=0;
    for (int i=0;i<sz;++i)
    {
        sum+=(int)out.at<float>(cv::Point(i,0));
    }
    double mx;
    int ref;
    cv::minMaxLoc(out, nullptr, &mx);
    double ratio=mx/src.rows;
    graph=cv::Mat::zeros(src.cols,src.rows,src.type());
    for (int i=0;i<sz;++i)
    {
        if (i!=0)
        {
            cv::Point p1{(i-1)*2,int(src.rows-ref/ratio)};
            cv::Point p2{i*2,int(src.rows-int(out.at<float>(cv::Point(i,0))/ratio))};

            cv::line(graph,p1,p2,cv::Scalar(255),1);
        }
        ref=double(out.at<float>(cv::Point(i,0)));
    }
    cv::imshow("graph",graph);
    cv::waitKey(0);cv::destroyAllWindows();
    return 0;
}