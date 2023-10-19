#include <iostream>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <ctime>
#include <bitset>
#define taille 7

using namespace cv;
using namespace std;


int main()
{
	int i, j;
	

	Mat img = imread("minion.jpg");


	for (j = 0; j < img.cols; j++)
	{
		for (i = 0; i < img.rows; i++)
		{
			Vec3b & unPixel = img.at<Vec3b>(i, j);
			if (unPixel[0] == 255 && unPixel[1] == 255 && unPixel[2] == 255)
			{
				unPixel[0] =230;
				unPixel[1] =230;
				unPixel[2] =230;
			}
		}
	}
	
	for (j = 0; j < img.cols; j++)
	{
		for (i = 0; i < img.rows; i++)
		{
			int r = (rand() % 20);
			Vec3b & unPixel = img.at<Vec3b>(i, j);
			if (r==2)
			{
				unPixel[0] = 0 + (rand() % 254);
				unPixel[1] = 0 + (rand() % 253);
				unPixel[2] = 0 + (rand() % 252);
			}

		}
	}
	
	unsigned char caractere[taille]= { 0x42,0x6F,0x6E,0x6A,0x6F,0x75,0x72 };


	for (j = 10; j <= taille*10; j = j + 10)
	{
		unsigned char octet = caractere[j / 10 - 1];
		bitset<8> binaryValue2(octet);

		for (i = 10; i <= 80; i = i + 10)
		{
				if ((octet & 0x01) == 1)
				{
					Vec3b & unPixel = img.at<Vec3b>(i, j);

					unPixel[0] = 255;
					unPixel[1] = 255;
					unPixel[2] = 255;
				}

				octet = octet >> 1;
			
		}
	}


	/*decoder le code image*/

	string code;
	char octet;
	for (j = 10; j < img.cols; j = j + 10)
	{
		char octet = 0;
		for (i = 80; i >= 10; i = i - 10)
		{
			Vec3b& unPixel = img.at<Vec3b>(i, j);

			if (unPixel[0] == 255 && unPixel[1] == 255 && unPixel[2] == 255)
			{
				octet = octet + pow(2, i / 10 - 1);
			}

		}

		code.push_back(octet);
	}

	code.push_back('\0');

	cout << code << endl;

	imwrite("IMAGE.png", img);
	imshow("image", img);
	waitKey(0);
}

