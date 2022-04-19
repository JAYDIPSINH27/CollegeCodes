clc;
clear;

% Initializing result table
res = zeros(40,4);

% Processing Grape Images
for a = 1:20
   
    path = strcat('images/grapes',string(a),'.jpg');
    img = imread(path);
    [m,n,k] = size(img);
    
    % Calculating Average of pixel value for each plane
    for i = 1:k
        sum = 0;
        for j = 1:m
            for k = 1:n
                sum = sum + double(img(j,k,i));
            end
        end
        sum = sum/(n*m);
        res(a,i) = sum;
    end

    % Classifying Grapes as 0
    res(a,4) = 0;

end

% Processing Apple Images
for a = 21:40

    path = strcat('images/apples',string(a-20),'.jpg');
    img = imread(path);
    [m,n,k] = size(img);
    
    % Calculating Average of pixel value for each plane
    for i = 1:k
        sum = 0;
        for j = 1:m
            for k = 1:n
                sum = sum + double(img(j,k,i));
            end
        end
        sum = sum/(n*m);
        res(a,i) = sum;
    end
    
    % Classifying Apples as 1
    res(a,4) = 1;

end

% Writing table to worksheet
writematrix(res,"data.xlsx");
