//
//  main.cpp
//  test
//
//  Created by 徐亦燊 on 2020/2/28.
//  Copyright © 2020 徐亦燊. All rights reserved.
//


#include <opencv2/opencv.hpp>
#include <opencv2/imgproc/imgproc.hpp>
using namespace cv;
using namespace std;


int main( )
{
   
    Mat srcMat = imread("/Users/xuyishen/Desktop/sa jiganyouhaximeiyouga/2020.4.10/3/1.png");
    Mat dstMat;
    Canny(srcMat, dstMat, 50, 200, 3);
    vector<Vec4i> lines;
    HoughLinesP(dstMat, lines, 1, CV_PI/180, 30, 30, 10 );
    for (size_t i = 0; i < lines.size(); i++ )
    {
        Point pt1,pt2;
        pt1.x = lines[i][0];
        pt1.y = lines[i][1];
        pt2.x = lines[i][2];
        pt2.y = lines[i][3];
        line( srcMat, pt1, pt2, Scalar(0,0,255), 1, LINE_AA);

    }
    imshow("src", srcMat);
    waitKey(0);
    return 0;
}


