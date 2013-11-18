import cv, cv2
import numpy as np

cv2.namedWindow("bgr")
#cv2.namedWindow("red")
#cv2.namedWindow("grn")
#cv2.namedWindow("blu")

cv2.namedWindow("hsv")
cv2.namedWindow("hue")
#cv2.namedWindow("sat")
#cv2.namedWindow("val")

vc = cv2.VideoCapture(1)

if vc.isOpened(): # try to get the first frame
	avail, frame = vc.read()
else:
	avail = False

while avail:
	avail, BGR = vc.read()
	HSV = cv2.cvtColor(BGR, cv.CV_BGR2HSV)

	blu,grn,red = cv2.split(BGR)
	hue,sat,val = cv2.split(HSV)

	thres = cv2.inRange(HSV, (7, 160, 200), (25, 255, 255))

	blur = cv2.GaussianBlur(thres, (9,9), 2, 2)
	edges = thres - cv2.erode(thres, None)

	circles = cv2.HoughCircles(blur, cv2.cv.CV_HOUGH_GRADIENT, 2, 120, np.array([]), 80, 40, 0, 100)

	if circles is not None:
		for c in circles[0]:
			cv2.circle(BGR, (c[0],c[1]), 1,    (0,0,255), 2)
			cv2.circle(BGR, (c[0],c[1]), c[2], (0,255,0), 2)

	cv2.imshow("bgr", BGR)
	#cv2.imshow("red", orange[1])
	#cv2.imshow("grn", grn)
	#cv2.imshow("blu", blu)

	cv2.imshow("hsv", blur)
	cv2.imshow("hue", thres)
	#cv2.imshow("sat", sat)
	#cv2.imshow("val", val)

	key = cv2.waitKey(20)
	if key == 27: # exit on ESC
		break
