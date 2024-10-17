#include <opencv2/opencv.hpp>
#include "GrayscaleImageWithClusters.h"
#include "CMeansClustering.h"
int main()
{
    // Load the image in grayscale (black and white)
    GrayscaleImageWithClusters image("milky-way-nvg.jpg", 2);
    CMeansClustering clustering(image, 2);
    
    return 0;
}