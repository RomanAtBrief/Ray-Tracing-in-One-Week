/*
 * File: main.cpp
 * ---------------------
 * Description
 */

/* Preprocessor statement always satrts with # */
#include <iostream>

/* Main program */
int main()
{
    /* Image Size */
    int imageWidth = 256;
    int imageHeight = 256;

    /* Render */
    std::cout << "P3\n"
              << imageWidth << " " << imageHeight << "\n255\n";

    for (int j = 0; j < imageHeight; j++)
    {
        std::clog << "\rScanlines remaining: " << (imageHeight - j) << " " << std::flush;
        for (int i = 0; i < imageWidth; i++)
        {
            /*
             * By convention, each of the red/green/blue components are represented internally
             * by real-valued variables that range from 0.0 to 1.0.
             * For example when i = 1 r = 0.0666.
             */
            double r = double(i) / (imageWidth - 1);
            double g = double(j) / (imageHeight - 1);
            double b = 0.0;

            /* At this satge we must scale to intgeres values between 0 and 255 for .ppm to work */
            int ir = int(255.99 * r);
            int ig = int(255.99 * g);
            int ib = int(255.99 * b);

            /* Writing scaled values to console */
            std::cout << ir << " " << ig << " " << ib << "\n";
        }
    }

    std::clog << "\rDone.\n";
    return 0;
}