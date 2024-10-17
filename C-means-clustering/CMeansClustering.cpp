#include "CMeansClustering.h"
#include <random>

CMeansClustering::CMeansClustering(GrayscaleImageWithClusters& image, int classCount)
	:
	membershipMatrix(image.getImagePixelCount(), std::vector<float>(classCount, 0.0)),
	classCount(classCount),
	image(image)
{
	InitializeMembershipMatrix();
	
}

void CMeansClustering::InitializeMembershipMatrix()
{
	//Initialize the membership matrix with random numbers
	std::random_device rd;
	std::mt19937 rng(rd());
	std::uniform_real_distribution<float> distribution(0, 1.0);

	for (int pixel = 0; pixel < image.getImagePixelCount(); ++pixel)
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
