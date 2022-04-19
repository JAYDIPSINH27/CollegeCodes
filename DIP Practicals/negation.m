%clc
%clear all
% reading the image file.
skI = imread("e7.tif");   
subplot(1, 2, 1), 
% displaying the image
imshow(skI);
title("Original image");
  
% levels of the 8-bit image
L = 2 ^ 8;    
  
% finding the negative                   
neg = (L - 1) - skI;
subplot(1, 2, 2),
  
% displaying the negative image
imshow(neg);
title("Negative Image")