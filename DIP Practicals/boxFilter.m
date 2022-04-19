x=imread('sample/e14.tif');

%%gray1=rgb2gray(x);
[r,c]=size(x);
B=zeros(r,c);

for i=2:r-1
    for j=2:c-1
        sum=0;
        for k=i-1:i+1  %3*3 averaging filter
            for m=j-1:j+1
               
                sum=sum+x(k,m);
            end
        end %3*3 averaging filter ended
        temp=sum*(1/9);
        B(i,j)=temp;
    end
end
figure
imshow(x);
figure
imshow(uint4(B));