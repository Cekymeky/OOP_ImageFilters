#include "imageprocessing.cpp"


using namespace std;


class BlackBox {
    private :
    string ImagesPath;
    string SavedImagesPath;

    string GetCurrentDir () {
        char currentDir[MAX_PATH];
        if (getcwd(currentDir, sizeof(currentDir)) != NULL) {
            string currentDirStr = currentDir;
            return currentDirStr + "\\";
        } 
        else {
            perror("getcwd() error");
        }
    }

    public : 
    void SetImagesPath (string FolderName) {
        this -> ImagesPath = GetCurrentDir () + FolderName ;
    }

    string GetImagesPath () {
        return this -> ImagesPath + "\\";
    }

    void SetSavedImagesPath (string FolderName) {
        this -> SavedImagesPath = GetCurrentDir () + FolderName ;
    }
    
    string GetSavedImagesPath () {
        return this -> SavedImagesPath + "\\";
    }
    
    void menu(){
        cout<< "Please select a filter to apply or 0 to exit\n" ;

        cout<< "1- Black & white Filter" << endl
            << "2- Inver Filter"<< endl
            << "3- Merge Filter" << endl 
            << "4- Flip image"<< endl 
            << "5- Darken and Lighten image" << endl
            << "6- Rotate image" << endl
            << "7- Detect image Edges"<< endl 
            << "8- Enlarge image"<< endl
            << "9- Shrink image"<< endl 
            << "a- Mirror 1/2 image" << endl 
            << "b- Shuffle image"<< endl 
            << "c- blur image" << endl 
            << "d- Crop image" << endl 
            << "e- Skew image Right" << endl 
            << "f- Skew image Up" << endl
            << "s- Save the image to a file" << endl 
            << "0- Exit" ;

        // Filter Selection
        char filter ;
        cin>>filter; 

        // Filter Functions
        char choice ;

        switch (filter) 
        {
            case '0' : //exit
                return ;


            case '1' : //Black & white Filter

                break;
        

            case '2' : //Invert Filter

                break ;
            

            case '3' : //Merge Filter

                break ;

            case '4' : // Flip image

                break ;

            case '5' : //Darken and Lighten image

                break;

            case '6' : //Rotate image

                break;

            case '7' : //Detect image Edges

                break ;

            case '8' : //Enlarge Image

                break ;

            case '9' : //Shrink image

                break ;

            case 'a' : //Mirror 1/2 image

                break ;

            case 'b' : //Shuffle image

                break ;

            case 'c' : //Blur image

                break ;

            case 'd' : //Crop image
           
                break ;

            case 'e' : //Skew image right

                break ;

            case 'f' : //Skew image up

                break ;

            case 's' : //Save the image to a file
                
                break ;

        }
    }

};
