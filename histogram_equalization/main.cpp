#include <opencv2/opencv.hpp>
#include <opencv2/imgproc.hpp>
int main()
{
    cv::Mat src{cv::imread("/home/muhammad/Downloads/unnamed.jpg")};
    cv::cvtColor(src,src,cv::COLOR_BGR2RGB);
    auto src_gray{src.clone()};
    cv::cvtColor(src_gray,src_gray,cv::COLOR_RGB2GRAY);
    cv::Mat dst,dst_gray;
    cv::equalizeHist(src_gray,dst_gray);
    cv::namedWindow("gray",0);
    cv::namedWindow("color",0);
    std::vector<cv::Mat>channels;
    cv::split(src,channels);
    for (auto &i:channels)
        cv::equalizeHist(i,i);
    cv::merge(channels,dst);
    cv::imshow("color",dst);
    cv::imshow("gray",dst_gray);
    cv::waitKey(0);
    cv::destroyAllWindows();


    return 0;
}