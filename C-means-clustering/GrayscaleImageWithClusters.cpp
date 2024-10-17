#include "GrayscaleImageWithClusters.h"
#include "opencv2/opencv.hpp"
#include <stdexcept>
#include <random>

GrayscaleImageWithClusters::GrayscaleImageWithClusters(const std::string& image_path, int classCount)
	:
	image(cv::imread(image_path, cv::IMREAD_GRAYSCALE)),
	membershipMatrix(getImagePixelCount(), std::vector<float>(classCount, 0.0)),
	classCount(classCount)
{
	if (image.empty()) throw std::runtime_error("Failed loading image.");
	InitializeMembershipMatrix();
}

int GrayscaleImageWithClusters::getImagePixelCount() const
{
	return image.total();
}

void GrayscaleImageWithClusters::InitializeMembershipMatrix()
{
	//Initialize the membership matrix with random numbers
	std::random_device rd;
	std::mt19937 rng(rd());
	std::uniform_real_distribution<float> distribution(0, 1.0);

	for (int pixel = 0; pixel < getImagePixelCount(); ++pixel)
	{
		float membershipValuesSum = 0.f;
		for (int classIndex = 0; classIndex < classCount; ++classIndex)
		{
			float membershipValue = rng();
			membershipMatrix[pixel][classIndex] = membershipValue;
			membershipValuesSum += membershipValue;
		}
		//Normalize the membership values so that they sum to 1 for every pixel
		for (int classIndex = 0; classIndex < classCount; ++classIndex)
		{
			membershipMatrix[pixel][classIndex] /= membershipValuesSum;
		}
	}
}