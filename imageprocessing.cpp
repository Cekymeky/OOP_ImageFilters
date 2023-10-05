#include <bits/stdc++.h>
#include "Bitmaplib/bmplib.cpp"
#include <unistd.h>

using namespace std;
typedef unsigned char (*ImagePtr)[SIZE];

class Image_Processing
{
    private:
    //Converting the string image file name to a const char
    char * ConvertStringToCharArr (string str) {
        //making the new array of chars to hold the string
        char * arrChar = new char[str.size() + 1];
        
        //copying all the string
        copy(str.begin(), str.end(), arrChar);
        
        //adding null
        arrChar[str.size()] = '\0';
        
        return arrChar;
    }

    public:

    char* imagesPath;
    char* savedImagesPath;

    //_____________________________________
    Image_Processing(string& ImagesPath, string& SavedImagesPath){
        imagesPath =  ConvertStringToCharArr(ImagesPath);
        savedImagesPath = ConvertStringToCharArr(SavedImagesPath);
    }

    //____________________________________
    ImagePtr LoadImage(string ImageName) {
        char* imagePath = ConvertStringToCharArr(imagesPath + ImageName + ".bmp");
        ImagePtr image = (ImagePtr)malloc(SIZE * SIZE * sizeof(unsigned char));

        readGSBMP(imagePath, image);

        return image;
    }

    //____________________________________
    void SaveImage (string SaveImageFileName, ImagePtr image) {
        writeGSBMP(ConvertStringToCharArr(savedImagesPath + SaveImageFileName + ".bmp"), image);
        free(image);
    }

    //____________________________________
    void BlackWhiteFilter (ImagePtr image) { //1
        for (int i = 0; i < SIZE ; i++){
            for (int j = 0; j < SIZE ; j++){
                
                auto& pixel = image[i][j];
                
                if ( pixel > SIZE / 2 ) {
                    pixel = 255;
                }
                else if (pixel < SIZE / 2 ){
                    pixel = 0;
                }

            }
        }
    }

    void InvertImageFilter (ImagePtr& image) { //2
        for (int i = 0; i < SIZE; i++) {
            for (int j = 0; j < SIZE; j++) {
                auto& pixel = image[i][j];
                pixel = 255 - pixel;
            }
        }
    }

    void MergeImageFilter (ImagePtr& image1, ImagePtr& image2) { //3
        for (int i = 0; i < SIZE; i++) {
            for (int j = 0; j < SIZE; j++) {
                auto& pixel1 = image1[i][j];
                auto& pixel2 = image2[i][j];

                pixel1 = (pixel1 + pixel2) / 2;
            }
        }
        free(image2);
    }

    void FlipImageFilter (ImagePtr& image) {//4
        
    }

    void DarkenLightenImageFilter (ImagePtr& image) {//5

    }

    void RotateImageFilter (ImagePtr& image) {//6

    }

    void DetectEdgesImageFilter (ImagePtr& image) {//7

    }

    void EnlargeImageFilter (ImagePtr& image) {//8

    }

    void ShrinkImageFilter (ImagePtr& image) {//9

    }


    void BlurImageFilter (ImagePtr& image) {//c
        for (int i = 1; i < SIZE - 1; i++) {
            for (int j = 1; j < SIZE - 1; j++) {
                image[i][j] = (image[i - 1][j - 1] + image[i - 1][j] +
                                        image[i - 1][j + 1] + image[i][j - 1] +
                                        image[i][j] + image[i][j + 1] + image[i + 1][j - 1] +
                                        image[i + 1][j] + image[i + 1][j + 1]) / 9;
            }
        }
    }
    

    
};