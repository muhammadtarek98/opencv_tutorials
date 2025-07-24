#include <iostream>
#include <opencv2/opencv.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
int main()
{
    cv::Mat img=cv::imread("/home/muhammad/Downloads/32721009.jpeg");
    cv::Mat img_resized;
    cv::resize(img,img_resized,cv::Size(1920,1080));
    cv::imshow("image",img_resized);
    cv::waitKey(0);
    cv::destroyAllWindows();

    return 0;
}