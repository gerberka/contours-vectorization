//
// Created by Dariya Petrova on 11.05.2020.
//

#pragma once

#include <opencv2/core.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/highgui.hpp>

using namespace cv;
using namespace std;

int getContourArea(vector<Point> contour);
bool isClosedContour(vector<Point> contour);
vector<Point> doubleContourToSingle(vector<Point> contour);
bool canBeDescribedByRectOld(vector<Point> contour, int maxDiff);
bool canBeDescribedByRect(vector<Point> contour);
vector<Point> processingMinAreaRect(vector<Point> contour);
vector<Point> deleteRepeatedNeighborPoints(vector<Point> points);
