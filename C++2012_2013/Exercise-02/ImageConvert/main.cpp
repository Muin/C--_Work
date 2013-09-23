/*      Exercise-02, Number-01
       IMAGE PROCESSING MODULE
        ISLAM,MOHAMMAD MUINUL
      MATRICULATION NO:-2581908
INFORMATION AND AUTOMATION ENGINEERING
        UNIVERSITY OF BREMEN
        CREATED: 27.11.2012

            PROPOSED TASK
Create a module for image processing functions. Within this module implement four functions that are
able to invert a passed bmp image file (use the file http://www2.iat.uni-bremen.de/~friend2/fruit.
bmp to test your module). The four functions differ only in the way, the image is passed to them. Use
the following different ways of passing the image:

     Pass the image as std::vector<char> to the function, invert it and return it back to the main.
     Pass the image as reference of std::vector<char> to the function and invert it.
     Pass the image as pointer to std::vector<char> to the function and invert it.
     Pass the image as character array to the function and invert it.

Implement a main application that is capable of handling command line arguments in the form,
    int main ( int argc , char ** argv )
        {
            // ...
        }

so that one can call your application like:

    ImageConvert InputImage . bmp ResultImage .bmp USE_POINTER

The first argument is the source image file, the second is the target image file and the third is used to
specify which function from the module hast to be used to process the image.

To invert the image you have to calculate for each value of the image data the new value in the following
form:

    resultValue = 255 - sourceValue

Within your main application do some time measurement to get the duration of the converting process.
For this purpose you can use:

    # include <time .h>
    double dStart = clock ();
    // Image processing ...
    double dDuration = clock () - dStart ;
    std :: cout << dDuration / CLOCKS_PER_SEC << " sec ." << std :: endl ;

Test your program and compare the time consumption for the different functions from your module.
Notes:

     A BMP image consists of a 54 bytes long header followed by the image data.
     Calculate the new values only for the image data and not for the header.
        Otherwise the image is not readable any more.
     Read the input image file in binary mode! E.g.:
        ifstream inputFile("InFile.bmp", ios::in | ios::binary);
     Write the output image file in binary mode! E.g.:
        ofstream outputFile("OutFile.bmp", ios::out | ios::binary);
*/




//@@@@@@@@@@ Please also read the COMMENT at the end of the program @@@@@@@@@@@

#include <iostream>
#include <fstream>
#include <time.h>
#include <string>
#include <vector>


using namespace std;


void Load_image( char* argv, vector<char> &vMemblock );
void write_image( char* argv , vector<char> vMemblock );

vector<char> invert_image_vector_method ( vector<char> vMemblock );
void invert_image_vector_pointer_method ( vector<char> *vMemblock );
void invert_image_vector_reference_method ( vector<char> &vMemblock );

int read_image_array_method ( char* argv , char*& memblock );
void invert_image_array_method ( char* vMemblock , int &size );
void write_image_array_method ( char* argv , char* memblock , int &size );




int main ( int argc , char** argv )
    {

        if ( argc < 4 )
            {
                cerr << "\nUsage: " << *argv << "  [InputImage.bmp]  [ResultImage.bmp]  <Method Name>" << endl;
                cout <<"\n\t Notes:\n\n\t [InputImage.bmp]  = fruit.bmp\n\t [ResultImage.bmp] = Give a output name";
                cout <<"\n\t <Method Name>     = 1.UseVector 2.UseReference 3.UsePointer 4.UseArray\n\n";
                return 1;
            }

        vector <char> vMemblock;
        char* aMemblock = NULL;

        Load_image ( argv[1] , vMemblock );
        read_image_array_method ( argv [1] , aMemblock);

        int size = read_image_array_method ( argv [1] , aMemblock);

        double dStart = clock ();

        string myStr = argv[3];

        if ( myStr == "UseVector")
            {
                vMemblock = invert_image_vector_method ( vMemblock );
                double dDuration = clock () - dStart ;
                cout<<"\nConversion time: "<< dDuration / CLOCKS_PER_SEC << " sec.\n";
                write_image ( argv[2] , vMemblock );
            }

        else if ( myStr == "UseArray")
            {
                if(aMemblock!=NULL)
                invert_image_array_method ( aMemblock , size );
                double dDuration = clock () - dStart ;
                cout <<"\nConversion time: "<< dDuration / CLOCKS_PER_SEC << " sec.\n";
                write_image_array_method ( argv[2] , aMemblock , size );
            }

        else if ( myStr == "UsePointer")
            {
                invert_image_vector_pointer_method ( &vMemblock );
                double dDuration = clock () - dStart ;
                cout<<"\nConversion time: "<< dDuration / CLOCKS_PER_SEC << " sec.\n";
                write_image ( argv[2], vMemblock );
            }

        else if ( myStr == "UseReference")
            {
                invert_image_vector_reference_method( vMemblock );
                double dDuration = clock () - dStart ;
                cout<<"\nConversion time: "<< dDuration / CLOCKS_PER_SEC << " sec.\n";
                write_image ( argv[2], vMemblock );
            }


        cout <<"\nConversion successful. Check The Destination Folder.....\n\n";

        return 0;

    }




//############# LOAD IMAGE for vector/reference/pointer method #####################

void Load_image ( char* argv , vector<char>& vMemblock )
    {

        fstream myfile;
        fstream::pos_type size;
        myfile.open( argv , ios::in | ios::binary | ios::ate );
            if ( myfile.is_open() )
                {
                    size = myfile.tellg();
                    vMemblock.resize(size);
                    myfile.seekg ( 0 , ios::beg );
                    myfile.read (&vMemblock[0] , size );
                    myfile.close();
                }

            else cout << "Unable to open file";

     }




//%%%%%%%%%%% VECTOR METHOD %%%%%%%%%%%%%

vector<char> invert_image_vector_method ( vector<char> vMemblock )
    {

        for ( unsigned int a = 55 ; a <= vMemblock.size(); a++ )
            {
                vMemblock[a] = 255 - vMemblock[a] ;
            }

        return vMemblock;
    }




//%%%%%%%%%%%% REFERENCE METHOD %%%%%%%%%%%

void invert_image_vector_reference_method ( vector<char> &vMemblock )
    {

        for ( unsigned int a = 55 ; a <= vMemblock.size(); a++ )
            {
                vMemblock[a] = 255 - vMemblock[a] ;
            }

    }





//%%%%%%%%%%%%% POINTER METHOD %%%%%%%%%%%%%%

void invert_image_vector_pointer_method ( vector<char> *vMemblock1 )
    {

        for ( unsigned int a = 55 ; a <= vMemblock1->size() ; a++ )
            {
                (*vMemblock1)[a] = 255 - (*vMemblock1)[a] ;

            }

    }




//############# WRITE IMAGE for vector/reference/pointer method #####################

void write_image ( char* argv , vector<char> vMemblock )
    {

        fstream myfile1;
        myfile1.open( argv , ios::binary | ios::ate | ios::out );
        if ( myfile1.is_open() )
            {
                myfile1.write ( &vMemblock[0] , vMemblock.size() );
                vMemblock.clear();
                myfile1.close();
            }
        else cout << "Unable to open file";

    }




//############# LOAD IMAGE for array method #####################

int read_image_array_method ( char* argv , char*& memblock )
    {
        fstream myfile;
        fstream::pos_type size;
        myfile.open( argv , ios::in | ios::binary | ios::ate );
        if ( myfile.is_open() )
            {
                size = myfile.tellg();
                memblock=new char [size];
                myfile.seekg ( 0 , ios::beg );
                myfile.read ( memblock , size );
                myfile.close();
            }
        else cout << "Unable to open file";
        return size;
    }




//############# ARRAY METHOD #####################

void  invert_image_array_method ( char* vMemblock , int &size )
    {

        for (int a = 55 ; a <= size; a++ )
            {
                vMemblock[a] = 255 - vMemblock[a] ;
            }

    }




//############# WRITE IMAGE for array method #####################

void write_image_array_method ( char* argv , char* memblock , int &size)
    {

        fstream myfile1;
        myfile1.open( argv , ios::binary | ios::ate | ios::out );
        if ( myfile1.is_open() )
            {
                myfile1.write ( memblock , size );
                myfile1.close();
                delete[] memblock;
            }
        else cout << "Unable to open file";

    }




//@@@@@@@@@@ COMMENT @@@@@@@@@@@@@

/*

  1. Command: ImageConvert fruit.bmp fruit1.bmp UseVector
             Conversion time: 0.2 sec.

  2. Command: ImageConvert fruit.bmp fruit1.bmp UseReference
             Conversion time: 0.14 sec.

  3. Command: ImageConvert fruit.bmp fruit1.bmp UsePointer
             Conversion time: 0.15 sec.

  4. Command: ImageConvert fruit.bmp fruit1.bmp UseArray
             Conversion time: 0.05 sec.

  So, It is better to Use Dynamic Array
  as it is showing it took only 0.05 sec to make the conversion

*/

































