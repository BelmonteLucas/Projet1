#include <iostream>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <ctime>
#include <bitset>

using namespace cv;
using namespace std;

int main()
{
	Mat img = imread("minion.jpg");

	const unsigned char character2[26] = { 0x41,0x42,0x43,0x44,0x45,0x46,0x47,0x48,0x49,0x4A,0x4B,0x4C,0x4D,0x4E,0x4F,0x50,0x51,0x52,0x53,0x54,0x55,0x56,0x57,0x58,0x59,0x5A };


	int i, j;
	for (j = 10; j < img.cols; j = j + 10)
	{
		const unsigned char m = character2[j - 10];
		bitset<8> binaryValue2(m);


		for (i = 10; i < img.rows; i = i + 10)
		{

			Vec3b & Color = img.at<Vec3b>(i, j);


			if (binaryValue2[(i / 10) - 1] == 1)
			{
				Color[0] = 255;
				Color[1] = 255;
				Color[2] = 255;
			}

			else
			{
				Vec3b& Color = img.at<Vec3b>(i, j);
				Color[0] = 0 + (rand() % 125);
				Color[1] = 0 + (rand() % 136);
				Color[2] = 0 + (rand() % 147);
			}
		}
	}

	imshow("image", img);
	waitKey(0);
	imwrite("IMAGE", img);
	waitKey(0);
}

