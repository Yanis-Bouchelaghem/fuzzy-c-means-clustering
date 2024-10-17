#pragma once
#include <vector>
#include "GrayscaleImageWithClusters.h"

class CMeansClustering
{
public:
	CMeansClustering(GrayscaleImageWithClusters& image, int classCount);
private:
	void InitializeMembershipMatrix();
private:
	std::vector<std::vector<float>> membershipMatrix; // The membership matrix U.
	const int classCount;
	GrayscaleImageWithClusters& image;
};