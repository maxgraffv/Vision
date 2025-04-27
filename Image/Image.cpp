#include "Image.h"

#include <opencv2/opencv.hpp>

Image::Image(const char* path) : Matrix( 0,0 )
{

    setWidth(300);
    setHeight(168);
    load(path);


}


int Image::load(const char* path)
{
    buffer = (uint8_t*)malloc(sizeof(int) * this->getWidth() * this->getHeight() * 3);
    FILE* file = fopen(path, "rb");
    if(file == NULL)
    {
        perror("Error opening a file\n");
        return 1;
    }

    // Move the file pointer to the end to determine the file size
    fseek(file, 0, SEEK_END);
    long file_size = ftell(file);
    rewind(file); // Reset the file pointer to the beginning

    size_t read_size = fread(buffer, 1, file_size, file);
    fclose(file);

    if (read_size != file_size) 
    {
        perror("Error reading file");
        free(buffer);
        fclose(file);
        return 1;
    }

    return 0;
}


int Image::show()
{
    cv::Mat image(getHeight(), getWidth(), CV_8UC3, cv::Scalar(0, 0, 0)); // Black canvas

    int row = 0;
    int col = 0;
    int pixel = 0;

    while( row < getHeight() )
    {
        while( col < getWidth() )
        {
            image.at<cv::Vec3b>(row, col) = cv::Vec3b( buffer[pixel+2] , buffer[pixel+1], buffer[pixel]); // BGR
            col++;
            pixel += 3;
        }
        row++;
        col = 0;
    }


    cv::imshow("My Window", image);
    cv::waitKey(0); // Wait for key press

    return 0;
}