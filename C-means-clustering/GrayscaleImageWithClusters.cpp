#include "GrayscaleImageWithClusters.h"
#include "opencv2/opencv.hpp"
#include <stdexcept>

GrayscaleImageWithClusters::GrayscaleImageWithClusters(const std::string& image_path)
{
	//Load the image
	image = cv::imread(image_path, cv::IMREAD_GRAYSCALE);
	if (image.empty())
	{
		throw std::runtime_error("Failed loading image.");
	}
}

int GrayscaleImageWithClusters::getImagePixelCount() const
{
	return image.total();
}
