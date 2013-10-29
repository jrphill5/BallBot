import cv, cv2
import numpy as np

cv2.namedWindow("video")
cv2.namedWindow("edges")
cv2.namedWindow("blura")
#cv2.namedWindow("blurb")
vc = cv2.VideoCapture(1)

if vc.isOpened(): # try to get the first frame
	rval, frame = vc.read()
else:
	rval = False

while rval:
	rval, frame = vc.read()
	gray = cv2.cvtColor(frame, cv.CV_RGB2GRAY)
	#ret,thres = cv2.threshold(gray,127,255,0)
	blura = cv2.GaussianBlur(gray, (5,5), 3, 3)
        #blurb = cv2.GaussianBlur(gray, (9,9), 2, 2)
	edges = gray - cv2.erode(gray, None)
	#edges = cv2.Canny( blura, 40, 80 )

	circles = cv2.HoughCircles(blura, cv2.cv.CV_HOUGH_GRADIENT, 1, 300, np.array([]), 100, 30, 10, 50)
	if circles is not None:
		for c in circles[0]:
			cv2.circle(frame, (c[0],c[1]), c[2], (0,255,0),2)
	cv2.imshow("video", frame)
	cv2.imshow("edges", edges)
	cv2.imshow("blura", blura)
        #cv2.imshow("blurb", blurb)
	key = cv2.waitKey(20)
	if key == 27: # exit on ESC
		break
