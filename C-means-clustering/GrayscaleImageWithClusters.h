#pragma once
#include <string>
#include <opencv2/opencv.hpp>

class GrayscaleImageWithClusters
{
public:
	GrayscaleImageWithClusters(const std::string& image_path, int clusterCount);
	int GetPixelCount() const;
	void DisplayClusters() const;
	int GetClusterCount() const;
	float GetMembershipAt(int pixelIndex, int clusterIndex) const;
	uchar GetPixelAt(int pixelIndex) const;
	void SetMembershipAt(int pixelindex, int clusterIndex, float value);

private:
	void InitializeMembershipMatrix();
private:
	cv::Mat image;
	std::vector<std::vector<float>> membershipMatrix; // The membership matrix U.
	const int clusterCount;
};