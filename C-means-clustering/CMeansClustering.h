#pragma once
#include <vector>
#include "GrayscaleImageWithClusters.h"

class CMeansClustering
{
public:
	CMeansClustering(GrayscaleImageWithClusters& image);


private:
	GrayscaleImageWithClusters& image;
};