#include "Image.h"
#include <cstdlib>
#include <cstdio>


Image::Image(int width, int height, const char* path) : Matrix( width,height )
{

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