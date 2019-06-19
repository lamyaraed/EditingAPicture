// Program: demo2.cpp
// Purpose: Demonstrate use of bmplip for handling
//          bmp colored and grayscale images
//          Program load a gray image and store in another file
// Author:  Mohammad El-Ramly
// Date:    30 March 2018
// Version: 1.0

#include <iostream>
#include <fstream>
#include <cstring>
#include <cmath>
#include "bmplib.cpp"

using namespace std;
unsigned char image[SIZE][SIZE];
unsigned char image2[SIZE][SIZE];
unsigned char image3[SIZE][SIZE];

void menu();//DONE

void loadImage (); //DONE

void loadImage2 (); //MSH MOHEMA BS DONE

void black_and_white(); //DONE

void flipimage(); //DONE

void merge_images(); //DONE

void Invert_Filter();//DONE

void dark_light(); //DONE

void rotate_image();

void edges();//DONE

void enlarge(); //DONE

void shrink();

void saveImage (); //DONE

int main()
{
  while(1)
  {
      int choice;

      menu();

      cin>>choice;




      if (choice == 1)
      {


          black_and_white();
      }
      else if (choice==2)
      {
          Invert_Filter();
      }

      else if (choice==3)
      {
          merge_images();
      }
      else if (choice==4)
      {

          flipimage();
      }
      else if (choice==5)
      {
          dark_light();
      }
      else if (choice==6)
      {
          rotate_image();
      }
      else if (choice==7)
      {
          edges();
      }
      else if (choice==8)
      {
          enlarge();
      }
      else if (choice==9)
      {
           shrink();
      }

      else if (choice==0)
      {
          break;
      }

      saveImage();


  }
  return 0;
}


void loadImage () {
   char imageFileName[100];

   // Get gray scale image file name
   cout << "Enter the source image file name: ";
   cin >> imageFileName;

   // Add to it .bmp extension and load image
   strcat (imageFileName, ".bmp");
   readGSBMP(imageFileName, image);
}


void loadImage2 () {
   char imageFileName[100];

   // Get gray scale image file name
   cout << "Enter the source image file name: ";
   cin >> imageFileName;

   // Add to it .bmp extension and load image
   strcat (imageFileName, ".bmp");
   readGSBMP(imageFileName, image2);
}


void black_and_white()
{
     cout<<"lol\n";
     loadImage();

  for (int i = 0; i <256; i++) {
    for (int j = 0; j< 256; j++) {
          if (image[i][j]<127){image[i][j]=0;}
          else
            image[i][j]=255;


    }
  }
}


void saveImage () {
   char imageFileName[100];

   // Get gray scale image target file name
   cout << "Enter the target image file name: ";
   cin >> imageFileName;

   // Add to it .bmp extension and load image
   strcat (imageFileName, ".bmp");
   writeGSBMP(imageFileName, image);
}



void flipimage() {
    loadImage();

  for (int i = 0; i < 128; i++) {
    for (int j = 0; j< 256; j++) {
            swap(image [i][j], image[256-i][256-j]);

    }
  }
}



void merge_images()
{
    loadImage();
    loadImage2();


    for (int i = 0; i < 255; i++) {
    for (int j = 0; j< 255; j++) {
            image3[i][j]=(image2[i][j]+image[i][j])/2;
    }
  }

    for (int i = 0; i < 255; i++) {
    for (int j = 0; j< 255; j++) {
            image[i][j]=image3[i][j];
    }
    }
}

void Invert_Filter()
{
    loadImage();
  for (int i = 0; i <255; i++) {
    for (int j = 0; j< 256; j++) {
          image[i][j]=256-image[i][j];
}
  }
}
void dark_light()
{
    int x;
    loadImage();

  cout<<"do you want to make the photo: \n"<<"1-lighter\n"<<"2-darker\n";
  cin>>x;

  if (x==1){
  for (int i = 0; i <255; i++) {
    for (int j = 0; j< 256; j++) {

          image[i][j]+=(256-image[i][j])/2;


  }
  }}
  else if (x==2){

    for (int i = 0; i <255; i++) {
    for (int j = 0; j< 256; j++) {
       image[i][j]-=image[i][j]/2;

  }


}}
}

void rotate_image()
{
    loadImage();
    int temp[256][256];
    for (int i = 0; i <255; i++) {
    for (int j = 0; j <256; j++)
        {
            temp[i][j]=image [255-j][i];

        }


    for (int i = 0; i <255; i++) {
    for (int j = 0; j <256; j++)
        {
            image[i][j]=temp[i][j];

        }
}
}
}

void edges()
{
    loadImage();
     for (int i = 0; i <255; i++) {
    for (int j = 0; j< 256; j++) {
          if (abs(image[i][j]-image[i][j+1]>25)){image[i][j]=0;}
          else
            image[i][j]=255;
    }
  }
}

void enlarge()
{
    loadImage();
    for (int i = 0; i <128; i++) {
    int a=i , b ;
    for (int j = 0; j<128; j++) {
    b=j*2;
           for (int k=a ; k<i+2;k++){
            for (int m=b ; m<b+4;m++){
            image2[k][m]=image[i][j];
            }
           }
    }
    }
for(int i = 0 ; i < 256 ; i++)
{
    for(int j=0 ; j < 256 ; j++)
    {
        image[i][j] = image2[i][j];
    }
}

}

void shrink()
{
    int x;
    loadImage();

    cout<<"do u want to shrink the image to: \n";
    cout<<"1-(1/2) \n"<<"2-(1/3) \n"<<"3-(1/4) \n";
    cin>>x;

    if(x==1)
    {
        for (int i = 0; i < 255; i+=2) {
    for (int j = 0; j< 255; j+=2) {

        image3[(i-1)/2][(j-1)/2]=(image[i][j]+image[i][j+1]+image[i+1][j]+image[i+1][j+1])/4;
    }
    }

    for (int i = 0; i < 255; i++) {
    for (int j = 0; j< 255; j++) {

        image[i][j]=image3[i][j];
    }
    }

    }

    else if (x==2)
    {


    for (int i = 0; i < 255; i+=2) {
    for (int j = 0; j< 255; j+=2) {

        image3[(i-1)/3][(j-1)/3]=(image[i][j]+image[i][j+1]+image[i+1][j]+image[i+1][j+1])/4;
    }
    }

    for (int i = 0; i < 255; i++) {
    for (int j = 0; j< 255; j++) {

        image[i][j]=image3[i][j];
    }
    }
    }

    else if(x==3)
    {
        for (int i = 0; i < 255; i+=2) {
    for (int j = 0; j< 255; j+=2) {

        image3[(i-1)/4][(j-1)/4]=(image[i][j]+image[i][j+1]+image[i+1][j]+image[i+1][j+1])/4;
    }
    }

    for (int i = 0; i < 255; i++) {
    for (int j = 0; j< 255; j++) {

        image[i][j]=image3[i][j];
    }
    }

    }
}


void menu() {

  cout<<"Enter your choice:";
  cout<<endl<<endl;
  cout<<"1- Black & White Filter \n";
  cout<<"2- Invert Filter\n";
  cout<<"3- Merge Filter\n";
  cout<<"4- Flip Image\n";
  cout<<"5- Darken and Lighten Image\n";
  cout<<"6- Rotate Image\n";
  cout<<"7- Detect Image Edges\n";
  cout<<"8- Enlarge Image\n";
  cout<<"9- Shrink Image\n";
  //cout<<"s- Save the image to a file;
  cout<<"0- Exit\n";
}


