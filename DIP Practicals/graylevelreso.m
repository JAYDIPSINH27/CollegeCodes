clc
clear all

% read input iname usin imread() function
% inImg = imread('Images\Jaydip.jpg');
inImg = imread('jpsinh.jpg');

%convert image int to gray scale
grayImg = rgb2gray(inImg);

%Get row,col and plane number
[row,col,plane] = size(grayImg);

max = 0;
bit = [ 1 2 3 4 ];       %Divide 8 bit image by different levels 

% traverse loop to get maximum pixel intensity of image
for x=1:row
    for y=1:col
        if inImg(x,y) > max
            max = inImg(x,y);
        end
    end
end


figure
for i = 1:length(bit)
    d = 2^i;                        %Total number of bits equal to 2^i
    outImg = round(grayImg/d);     %Divide each pixel by 2^i;
    subplot(2,2,i);
    title(['Gray Level ',num2str(256/(2^(i-1)))]);
    hold on
    imshow(outImg * d);
end