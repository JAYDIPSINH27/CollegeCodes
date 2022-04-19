clc;
clear all;
close all;

b=imread('jpsinh.jpg');
[m,n,colormap]=size(b);

%For RGB Input
if colormap==3
    x=b(:,:,1);
    y=b(:,:,2);
    z=b(:,:,3);
end

k=1; %Counter for Row and
l=1; %Column replication
f=input('Enter the Factor: ');

for i=1:m %Loop for reading row and 
    for t=1:f %Row replication
        for j=1:n %Loop for reading column and
            for t=1:f %Column Replication
                if colormap==3 %For RGB image
                    c1(k,l)=x(i,j);
                    c2(k,l)=y(i,j);
                    c3(k,l)=z(i,j);
                else %For Grayscale image
                    c(k,l)=b(i,j);
                end
                l=l+1;
            end
        end
        l=1;
        k=k+1;
    end
end

if colormap==3
    c(:,:,1)=c1;
    c(:,:,2)=c2;
    c(:,:,3)=c3;
end

figure
imshow(b),title('Original')
figure, imshow(c) , title('Zoomed')