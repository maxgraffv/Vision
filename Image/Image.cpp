#include "Image.h"
#include <cstdlib>
#include <cstdio>
#include <algorithm>


Image::Image(int width, int height, const char* path) : Matrix( width,height )
{
    this->buffer().clear();
    this->buffer() = std::vector<float>(width*height*3, 0.f); // Image needs 3 times more data for RGB

    load(path);
}

Image::~Image()
{

}

int Image::load(const char* path)
{
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

    std::vector<uint8_t> temp(file_size);

    size_t read_size = fread(temp.data(), 1, file_size, file);
    fclose(file);

    std::transform(temp.begin(), temp.end(), this->buffer().begin(), [](uint8_t b) {
        return static_cast<double>(b);
    });

    if (read_size != file_size) 
    {
        perror("Error reading file\n"); 
        fclose(file);
        return 1;
    }

    return 0;
}

Pixel Image::getPixel(int i)
{
    // std::cout << "Wanted pixel i= " << i << std::endl;
    Pixel ret;

    if(i > ((this->getWidth() * this->getHeight())-1))
    {
        i = 0;
    }
    if(i < 0)
        i = 0;

    int ind = i * 3;
    double r = this->buffer()[ind];
    double g = this->buffer()[ind+1];
    double b = this->buffer()[ind+2];

    ret = Pixel(r,g,b);

    return ret;
}


Pixel Image::getPixel(int x, int y)
{
    // std::cout << "pixel X: " << x << "\t Y: " << y << std::endl;
    
    int i = (y * this->getWidth()) + x;

    return getPixel(i);
}


void Image::applyKernel(Matrix<float>& kernel)
{
    int kWidth = kernel.getWidth();
    int kHeight = kernel.getHeight();
    int kCenterX = kWidth / 2;
    int kCenterY = kHeight / 2;


    std::vector<float> newImgVec;

    for (int y = 0; y < this->getHeight(); ++y) {
        for (int x = 0; x < this->getWidth(); ++x) {
            Pixel pix = {0, 0, 0};
            for (int ky = 0; ky < kHeight; ++ky) {
                for (int kx = 0; kx < kWidth; ++kx) {
                    int ix = x + kx - kCenterX;
                    int iy = y + ky - kCenterY;
                    
                    // std::cout << "Ops GO" << std::endl;
                    double ker = kernel.buffer()[ky*kernel.getWidth() + kx];
                    // std::cout << "Ker OK" << std::endl;
                    Pixel temp = this->getPixel(ix, iy);
                    // std::cout << "Pix OK" << std::endl;
                    pix += temp * ker;
                    // std::cout << "Ops STOP" << std::endl;

                }
            }
            newImgVec.push_back(pix.red());
            newImgVec.push_back(pix.green());
            newImgVec.push_back(pix.blue());
        }
    }

    this->buffer() = newImgVec;
}