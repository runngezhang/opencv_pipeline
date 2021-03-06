#pragma once

#include "exceptions.h"
#include <functional>

namespace opencv_pipeline {

typedef
enum { noverify=false, verify=true }
verify_result;

struct waitkey
{
    explicit waitkey(int delay = 0) : delay_(delay)
    {
    }

    cv::Mat const &operator()(cv::Mat const &src) const
    {
        cvWaitKey(delay_);
        return src;
    }

  private:
    int const delay_;
};

// image loading
cv::Mat load(char const * const pathname);
cv::Mat load(std::string const &pathname);

// save an image
std::function<cv::Mat (cv::Mat const &)>
save(char const * const pathname);

// detect keypoint features
std::function<cv::Mat (cv::Mat const &)>
detect(std::string const &detector, std::vector<cv::KeyPoint> &keypoints);

// detect region features
std::function<cv::Mat (cv::Mat const &)>
detect(std::string const &detector, std::vector<std::vector<cv::Point>> &regions);

// extract region features
std::function<cv::Mat (cv::Mat const &)>
extract(char const * const detector, std::vector<cv::KeyPoint> &keypoints);

// image manipulation
cv::Mat gray(cv::Mat const &image);         // single channel grey-scale image
cv::Mat gray_bgr(cv::Mat const &image);     // 3-channel grey-scale image
cv::Mat mirror(cv::Mat const &image);

}   // namespace opencv_pipeline

#include "detail.h"
#include "opencv_pipeline_impl.inl"
#include "detail.inl"
