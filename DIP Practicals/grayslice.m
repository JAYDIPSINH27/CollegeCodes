a=imread('jpsinh.jpg');
a=rgb2gray(a);
subplot(2,2,1);
imshow(a);
[M,N]=size(a);
title 'Original Image';
r1=input('enter value r1: ');
r2=input('enter value r2: ');
   for i=1:1:M
        for j=1:1:N
            if a(i,j)>=r1 && a(i,j)<=r2
                b(i,j)=255;
               d(i,j)=255;
            else
                b(i,j)=a(i,j);
               d(i,j)=0;
            end
        end
   end    


% s1=uint8(s);
subplot(2,2,3);
imshow(d);
title 'Output 1';
subplot(2,2,2);
imshow(b);
title 'Output 2';


 