function AverageFilter(image)

I = imread(image);
% I=rgb2gray(InImage);
[x,y] = size(I);

for i = 2:x-1
    for j = 2:y-1
        sum = 0;
        for ii = i-1:i+1  
            for jj = j-1:j+1
                sum = sum + I(ii,jj);
            end
        end
        I2(i,j) = ceil(sum/9);
    end
end


imshow(I2);