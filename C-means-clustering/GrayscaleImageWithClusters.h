#pragma once
#include <string>
#include <opencv2/opencv.hpp>

class GrayscaleImageWithClusters
{
public:
	GrayscaleImageWithClusters(const std::string& image_path);
	int getImagePixelCount() const;
private:
	cv::Mat image;
};