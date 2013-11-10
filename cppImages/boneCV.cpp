/* boneCV.cpp
 *
 * Copyright Derek Molloy, School of Electronic Engineering, Dublin City University
 * www.derekmolloy.ie
 *
 * Redistribution and use in source and binary forms, with or without modification, are permitted
 * provided that source code redistributions retain this notice.
 *
 * This software is provided AS IS and it comes with no warranties of any type. 
 */

#include<iostream>
#include<opencv2/opencv.hpp>
#include <cv.h>
#include <highgui.h>
#include <math.h>
using namespace std;
using namespace cv;

int main()
{
    
    VideoCapture capture(0);
    capture.set(CV_CAP_PROP_FRAME_WIDTH,1280);
    capture.set(CV_CAP_PROP_FRAME_HEIGHT,720);
    if(!capture.isOpened()){
	    cout << "Failed to connect to the camera." << endl;
    }
    Mat frame, hsv, hsverode, circlesOut;
    capture >> frame;
    if(frame.empty()){
		cout << "Failed to capture an image" << endl;
		return -1;
    }
    circlesOut = frame;
    cvtColor(frame, hsv, CV_BGR2HSV);
    
    inRange(hsv, Scalar(7,150,180), Scalar(30,255,255), hsv);
    blur(hsv,hsv,Size(5,5));
    erode(hsv, hsverode, Mat());
    subtract(hsv, hsverode, hsv);

    vector<Vec3f> circles;

    //HoughCircles(src, outarray,#method,dp??,minDist,param1,param2,minRadius,maxRadius)
    HoughCircles(hsv, circles, CV_HOUGH_GRADIENT, 2, 100, 18, 80, 10, 200);

    for(size_t i = 0; i < circles.size(); i++){
	    Point center(cvRound(circles[i][0]), cvRound(circles[i][1]));
	    int radius = cvRound(circles[i][2]);

	    circle(circlesOut, center, 3, Scalar(0,255,0), -1, 8, 0);
	    circle(circlesOut, center, radius, Scalar(0,255,0), 3, 8, 0);

	    cout << "i found a circle" << endl;
    }

    /* previous code to test for lines
     * *************************
    //inRange(src,lower bound,upper bound,dst)
    inRange(edges, 25, 160, hsv);
    //blur(src, output, kernel)
    blur(edges,edges,Size(5,5));
    //Canny(src, output, thresh1, thresh2, 3?????)
    Canny(edges, edges, 5, 70, 3);
    ***************************
    */
    imwrite("capture.png", frame);
    imwrite("hsv.png", hsv);
    imwrite("circlesOut.png", circlesOut);
    return 0;
}
