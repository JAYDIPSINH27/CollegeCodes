close all;
clear;
clc;
 
% read the input image as input image
inImage = imread('rose_copy.jpg');
 
% get the shape of the image
[row,col] = size(inImage);
outImage = zeros(row,col);
 
n = 6; % the number of bits for the grayscale. Say I want it from 8-bit to 6-bit in this case
 
for y = 1:1:row
    for x = 1:1:col
        pixel = uint8(inImage(y,x));
        
        mask = uint8(256 - power(2,(8 - n)));
        
        pixel2 = uint8(bitand(pixel,mask));
        
        fin = bitsra(pixel2,8 - n);
        
        outImage(y,x) = uint8(fin);
    end
end
 
 
outImage = uint8(outImage);
imwrite(outImage,'Grayscale.jpg','jpg');