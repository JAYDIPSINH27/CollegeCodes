close all;
clear;
clc;

x=imread('e18.tif');
% x=rgb2gray(x);
x=im2double(x);

[m,n]=size(x);

gamma=2;
c=1;

for i=1:m
    for j=1:n
        ex(i,j)=c*(x(i,j)^gamma);
    end
end

subplot(1,2,1)
imshow(x);
title('Original Image');

subplot(1,2,2)
imshow(ex);
title('Power Low Image')