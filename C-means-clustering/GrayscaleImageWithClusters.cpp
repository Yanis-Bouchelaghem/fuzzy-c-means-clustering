#include "GrayscaleImageWithClusters.h"
#include "opencv2/opencv.hpp"
#include <stdexcept>
#include <random>
#include <vector>

GrayscaleImageWithClusters::GrayscaleImageWithClusters(const std::string& image_path, int clusterCount)
	:
	image(cv::imread(image_path, cv::IMREAD_GRAYSCALE)),
	membershipMatrix(GetImagePixelCount(), std::vector<float>(clusterCount, 0.0)),
	clusterCount(clusterCount)
{
	if (image.empty()) throw std::runtime_error("Failed loading image.");
	InitializeMembershipMatrix();
}

int GrayscaleImageWithClusters::GetImagePixelCount() const
{
	return image.total();
}

void GrayscaleImageWithClusters::DisplayClusters() const
{
	//Create a cv::mat for each cluster with the right size
	std::vector<cv::Mat> clusterMaps;
	for (int i = 0; i < clusterCount; ++i)
	{
		clusterMaps.push_back(cv::Mat::zeros(image.size(), image.type()));
	}
	//Iterate over each pixel and assign the cluster color 
	for (int pixelIndex = 0; pixelIndex < GetImagePixelCount(); ++pixelIndex)
	{
		//Determine the x and y position of the clusterMap corresponding to the current pixel
		const int y = pixelIndex % image.size().width;
		const int x = pixelIndex / image.size().height;
		for (int clusterIndex = 0; clusterIndex < clusterCount; ++clusterIndex)
		{
			clusterMaps[clusterIndex].at<uchar>(y, x) = 255 * membershipMatrix[pixelIndex][clusterIndex];
		}
	}
	//display the result and wait for input.
	for (int cluster = 0; cluster < clusterCount; ++cluster)
	{
		cv::imshow("Cluster " + std::to_string(cluster), clusterMaps[cluster]);
	}
	cv::waitKey(0);
	cv::destroyAllWindows();
}

void GrayscaleImageWithClusters::InitializeMembershipMatrix()
{
	//Initialize the membership matrix with random numbers
	std::random_device rd;
	std::mt19937 rng(rd());
	std::uniform_real_distribution<float> distribution(0, 1.0);

	for (int pixelIndex = 0; pixelIndex < GetImagePixelCount(); ++pixelIndex)
	{
		float membershipValuesSum = 0.f;
		for (int clusterIndex = 0; clusterIndex < clusterCount; ++clusterIndex)
		{
			float membershipValue = rng();
			membershipMatrix[pixelIndex][clusterIndex] = membershipValue;
			membershipValuesSum += membershipValue;
		}
		//Normalize the membership values so that they sum to 1 for every pixel
		for (int classIndex = 0; classIndex < clusterCount; ++classIndex)
		{
			membershipMatrix[pixelIndex][classIndex] /= membershipValuesSum;
		}
	}
}