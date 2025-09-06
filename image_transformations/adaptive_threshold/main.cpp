#include <opencv2/opencv.hpp>
#include <opencv2/imgproc.hpp>
int main()
{
    cv::Mat img=cv::imread("/home/muhammad/Downloads/unnamed.jpg",cv::IMREAD_GRAYSCALE);
    cv::Mat dst(cv::Size(img.rows,img.cols),img.type());
    double max_val=113;
    int block_size=3;
    cv::adaptiveThreshold(img,dst,max_val,cv::ADAPTIVE_THRESH_MEAN_C,cv::THRESH_BINARY,block_size,-5);
    cv::imshow("input",img);
    cv::imshow("output",dst);
    cv::waitKey(0);
    cv::destroyAllWindows();

    return 0;
}