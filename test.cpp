#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include <iostream>
#include <stdio.h>

using namespace cv;
using namespace std;
int high , low ;
Mat src, dst;

void inRangeDemo( int, void* ) // fonction "Call Back"
{
    inRange(src,low,high,dst);  // Seuillage Hat
    imshow( "Image", dst );     // Affichage
}

int main (int argc, char *argv[])
{
	VideoCapture cap(0) ;
	if (!cap.isOpened())
	{
		cerr << "Erreur ouverture flux video" << "\n" ;
		return -1 ;
	}
	namedWindow("Image", CV_WINDOW_AUTOSIZE) ;
	cap.set(CAP_PROP_FRAME_WIDTH, 320) ;
	cap.set(CAP_PROP_FRAME_HEIGHT, 240);
	
	while(1)
	{
		cap >> src ;
		imshow("Image", src);
		createTrackbar( "LOW","Image", &low, 255, inRangeDemo );
		createTrackbar( "HIGH","Image", &high,255, inRangeDemo );
		inRangeDemo( 0, 0 ) ;
		if (waitKey(1) >= 0 ) break ;
	}
	return 0;
}
		
