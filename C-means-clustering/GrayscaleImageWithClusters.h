#pragma once
#include <string>
#include <opencv2/opencv.hpp>

class GrayscaleImageWithClusters
{
public:
	GrayscaleImageWithClusters(const std::string& image_path, int classCount);
	int GetImagePixelCount() const;
	void DisplayClusters() const;
private:
	void InitializeMembershipMatrix();
private:
	cv::Mat image;
	std::vector<std::vector<float>> membershipMatrix; // The membership matrix U.
	const int clusterCount;
};