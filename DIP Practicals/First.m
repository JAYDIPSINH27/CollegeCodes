%clc
%clear all
P = imread('jpsinh.jpg');
I=rgb2gray(P);
figure
imshow(I)
[nr,nc]=size(I);
k=1;
l=1;
f=input('Enter the factor:')

for i = 1:nr
    for t=1:f
        for j=1:nc
            for t=1:f
                d(k,l)=I(i,j);
                l=l+1;
            end
        end
        l=1;
        k=k+1;
    end
end
    
figure(2)
% imshow(uint8(d))
imshow(d)

