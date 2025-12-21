#include <opencv2/opencv.hpp>
#include<opencv2/imgproc.hpp>

int main()
{
    cv::Mat img{cv::imread("/home/muhammad/Downloads/unnamed.jpg",cv::IMREAD_GRAYSCALE)},dst;
    cv::applyColorMap(img,dst,cv::COLORMAP_BONE);
    cv::imshow("test",dst);
    cv::waitKey(0);
    cv::destroyAllWindows();

    return 0;
}