#include <opencv2/opencv.hpp>
#include "GrayscaleImageWithClusters.h"
#include "CMeansClustering.h"
int main()
{
    // Load the image in grayscale (black and white)
    GrayscaleImageWithClusters image("milky-way-nvg.jpg", 2);
    image.DisplayClusters();
    CMeansClustering clustering(image);
    clustering.RunClustering(20, 2);
    image.DisplayClusters();
    
    return 0;
}