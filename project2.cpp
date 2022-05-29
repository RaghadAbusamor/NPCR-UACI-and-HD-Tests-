#include<iostream>
#include <string>
#include <fstream>
using namespace std;

//function to encrypt by Cesare cipher
int encrypt(int num, int k)
{
   int cipher;
   cipher=num+k;
      if(cipher>255)
         cipher-=255;
      else
                ;
    return cipher;
}


int main()
{

cout<<"---------------WELCOME TO  PLAINTEXT SENSITIVITY ATTAK--------------------"<<endl;
cout<<"------------------Done By:RAGHAD ABU SAMMOUR 217099-----------------------"<<endl<<endl;
//declerad two 4*4 Matrices
    int plain_image[4][4];
    int cipher_image[4][4];
    int k;
//read the plainText from file
    ifstream f("file.txt");
    if(f.is_open())
    {
        for(int row=0; row<4; row++){
          for(int column=0; column<4; column++)
        f>> plain_image[row][column];
       }

    }


//print the plain on the screen
    cout<<endl<<"--plain_image--"<<endl;

     for(int row = 0; row < 4; row++){
        for(int column = 0; column < 4; column++){
            cout <<plain_image[row][column] << " ";
        }
        cout << endl;
    }
//encrypt the 4 by 4 bytes matrix using Cesare cipher to have the 4 by 4 bytes of the cipher image
    cout<<endl<<"Enter key to encrypt by Cesare cipher : ";
    cin>>k;
    for(int row = 0; row < 4; row++){
        for(int column = 0; column < 4; column++){
           cipher_image[row][column]=encrypt(plain_image[row][column],k);
        }
        cout << endl;
    }
//print the cipher on the screen
  cout<<"--cipher_image--"<<endl;
    for(int row = 0; row < 4; row++){
        for(int column = 0; column < 4; column++){
            cout <<cipher_image[row][column] << " ";
        }
        cout <<endl;
    }
////////////////////////////////////////////////////////////////////////
//NPCR
float D=0,sum=0,sub=0,H=255,SUM=0;
int L=4*4;
for(int row=0;row<4;row++){
    for(int column=0;column<4;column++)
    {
      if ((plain_image[row][column]) - (cipher_image[row][column])!=0)
          D=D+1;
      else
          ;

    }

}
float NPCR=D/L*100;
cout<<endl<<"NPCR = "<<NPCR<<"%";
///////////////////////////////////////////////////////////////////////
//UACI
for(int row=0;row<4;row++){
    for(int column=0;column<4;column++)
    {
      if ((plain_image[row][column]) - (cipher_image[row][column])>0)
          sum=sum+((plain_image[row][column]) - (cipher_image[row][column]))/H;
      else
          sum=sum+(((plain_image[row][column]) - (cipher_image[row][column]))*-1)/H;
    }
}
float UACI=sum/L*100;
cout<<endl<<"UACI = "<<UACI<<"%";
/////////////////////////////////////////////////////////////////////////
//HD
for(int row=0;row<4;row++){
    for(int column=0;column<4;column++)
    {
       SUM=SUM+((plain_image[row][column]) ^ (cipher_image[row][column]));

    }
}

float HD=SUM/L*100;
cout<<endl<<"HD = "<<HD<<"%"<<endl;
    return 0;
}
