#include <opencv2/opencv.hpp>
#include <opencv2/imgproc.hpp>
int main()
{
    cv::Mat img=cv::imread("/home/muhammad/Downloads/unnamed.jpg",cv::IMREAD_GRAYSCALE);
    cv::Mat dst(cv::Size(img.rows,img.cols),img.type());
    double threshold_value=135,max_val=100;
    cv::threshold(img,dst,threshold_value,max_val,cv::THRESH_BINARY);
    cv::imshow("input",img);
    cv::imshow("output",dst);
    cv::waitKey(0);
    cv::destroyAllWindows();

    return 0;
}