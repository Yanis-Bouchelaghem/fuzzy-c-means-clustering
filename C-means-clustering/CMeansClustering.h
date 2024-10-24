#pragma once
#include <vector>
#include "GrayscaleImageWithClusters.h"

class CMeansClustering
{
public:
	CMeansClustering(GrayscaleImageWithClusters& image);
	void UpdateClusterCenters(float m);
	void UpdateMembershipMatrix(float m);
	void RunClustering(int iterationCount, int m);

private:
	GrayscaleImageWithClusters& image;
	std::vector<float> clusterCenters;
};