clc
clear all
close all
warning off;
x=imread('e9.tif');
h=zeros(1,256);
[r c]=size(x);
n = 0 : 255;  
for i=1:r
    for j=1:c
        h(x(i,j)+1)=h(x(i,j)+1)+1;
    end
stem(n, h);
drawnow limitrate;
end
figure;
histogram(x);