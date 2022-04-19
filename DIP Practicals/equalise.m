clc
clear all

% read input iname usin imread() function
inImg = imread('sample\e12.tif');

% histogram equlization function
outImg = histeq(inImg);

%Display input image, its histogram, equalize histogram and output image
subplot(2,2,1);imshow(inImg);title('Input Image')
subplot(2,2,2);imhist(inImg );title('Input Image Histogram')
subplot(2,2,3);imshow(outImg );title('Histogram Equalizes Image')
subplot(2,2,4);imhist(outImg );title('Equalized Histogram')