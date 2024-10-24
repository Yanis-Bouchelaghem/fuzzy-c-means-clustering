#include "CMeansClustering.h"
#include <iostream>

CMeansClustering::CMeansClustering(GrayscaleImageWithClusters& image)
	:
	image(image),
	clusterCenters(image.GetClusterCount(), 0.f)
{
}

void CMeansClustering::UpdateClusterCenters(float m)
{
	for (int clusterIndex = 0; clusterIndex < image.GetClusterCount(); ++clusterIndex)
	{
		float numerator = 0.0f;
		float denominator = 0.0f;
		for (int pixelIndex = 0; pixelIndex < image.GetPixelCount(); ++pixelIndex)
		{
			float u_ij_m = pow(image.GetMembershipAt(pixelIndex,clusterIndex),m);
			numerator += u_ij_m * image.GetPixelAt(pixelIndex);
			denominator += u_ij_m;
		}
		clusterCenters[clusterIndex] = numerator / denominator;
	}
}

void CMeansClustering::UpdateMembershipMatrix(float m)
{
	for (int pixelindex = 0; pixelindex < image.GetPixelCount(); ++pixelindex)
	{
		for (int clusterIndex = 0; clusterIndex < image.GetClusterCount(); ++clusterIndex)
		{
			float sum = 0.f;
			for (int secondClusterIndex = 0; secondClusterIndex < image.GetClusterCount(); ++secondClusterIndex)
			{
				double ratio = abs(image.GetPixelAt(pixelindex) - clusterCenters[clusterIndex]) / abs(image.GetPixelAt(pixelindex) - clusterCenters[secondClusterIndex]);
				sum += pow(ratio, 2.f / (m - 1.f));
			}
			float newU_ij = 1.f / sum;
			image.SetMembershipAt(pixelindex, clusterIndex, newU_ij);
		}
	}
}

void CMeansClustering::RunClustering(int iterationCount, int m)
{
	for (int iteration = 0; iteration < iterationCount; ++iteration)
	{
		std::cout << "Running iteration " << iteration << "...\n";
		UpdateClusterCenters(m);
		UpdateMembershipMatrix(m);

	}
}


