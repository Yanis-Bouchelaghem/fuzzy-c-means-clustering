#include <opencv2/opencv.hpp>
#include "GrayscaleImageWithClusters.h"
#include "CMeansClustering.h"
int main()
{
    // Load the image in grayscale (black and white)
    GrayscaleImageWithClusters image("milky-way-nvg.jpg", 2);
    image.DisplayClusters();
    CMeansClustering clustering(image);
    
    return 0;
}