#include <iostream>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <ctime>
#include <chrono>
#include <sstream>
using namespace cv;
using namespace std;
using chrono::system_clock;
using namespace chrono;

int main()
{
	Mat image;
	namedWindow("Video");
	VideoCapture video(0);

	high_resolution_clock::time_point start = high_resolution_clock::now();

	if (!video.isOpened())
	{
		cout << "Erreur du fichier ou de la video!" << endl;
		return -1;
	}

	time_t now = time(NULL);
	tm now_tm;
	char str[26];
	localtime_s(&now_tm, &now);
	asctime_s(str, 26, &now_tm);
	str[strlen(str) - 1] = ' ';


	Point text_position1(200, 30);
	Point text_position2(200, 60);

	int font_size = 1;
	Scalar font_Color(0, 0, 255);
	Scalar font_Color2(255, 255, 255);

	int font_weight = 1;


	while (true)
	{
		ostringstream toto;

		auto now = high_resolution_clock::now();
		auto elapsed = duration_cast<seconds>(now - start).count();
		toto << "Chrono : " << elapsed << "s";
		string timeString = toto.str();

		video.read(image);

		int i, j;
		
		for (j = 0; j < image.cols; j++)
		{
			for (i = 0; i < image.rows; i++)
			{
				Vec3b unPixel = image.at<Vec3b>(i, j);

			}
		}
		putText(image, timeString, text_position2, FONT_HERSHEY_DUPLEX, font_size, font_Color, font_weight);
		putText(image, str, text_position1, FONT_HERSHEY_DUPLEX, font_size, font_Color, font_weight);
		imshow("Video", image);
		waitKey(33);
	}
	video.release();
	return 0;

}
