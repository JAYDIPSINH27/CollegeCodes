clc
clear all

% read input iname usin imread() function
inImg = imread('e13.tif');
grayImage=inImg;
% grayImage = rgb2gray(inImg); %For Color Image(Passport image)
[rows, columns, numberOfColorChannels] = size(grayImage);
counts = zeros(1, 256);
for col = 1 : columns
	for row = 1 : rows
		% Get the gray level.
		grayLevel = grayImage(row, col);
		% Add 1 because graylevel zero goes into index 1 and so on.
		counts(grayLevel+ 1) = counts(grayLevel+1) + 1;
	end
end

subplot(1,2,1)
imshow(inImg)
% Plot the histogram.\
subplot(1,2,2)
grayLevels = 0 : 255;
bar(grayLevels, counts, 'BarWidth', 1, 'FaceColor', 'b');
xlabel('Gray Level', 'FontSize', 20);
ylabel('Pixel Count', 'FontSize', 20);
title('Histogram', 'FontSize', 20);
grid on;

