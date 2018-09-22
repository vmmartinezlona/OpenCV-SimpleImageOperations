% ________________________________________________ Read the images

 img_  = imread('./Images/original_color_rm.png');
 img1_ = imread('./Images/color1.jpg');
 img2_ = imread('./Images/color2.jpg');
 img3_ = imread('./Images/color3.jpg');
 img4_ = imread('./Images/color4.jpg');
 img5_ = imread('./Images/color5.jpg');
 img6_ = imread('./Images/color6.jpg');

% ___________________________ Convert to gray scale

 img  = rgb2gray(img_);
 img1 = rgb2gray(img1_);
 img2 = rgb2gray(img2_);
 img3 = rgb2gray(img3_);
 img4 = rgb2gray(img4_);
 img5 = rgb2gray(img5_);
 img6 = rgb2gray(img6_);

% ________________________________________________ 1. Filtrado espacial

% ___________________________ Mode Filter

% ___________________________ Median Filter

%_img1Median = medfilt2(img1, [3 3]); 
%_img2Median = medfilt2(img2, [9 9]);

% ___________________________ Maximum Filter

%_img1Maximum = imdilate(img1,strel('square', 3));

% ___________________________ Minimum Filter

% ___________________________ Average Filter

%_AverageFImg1 = fspecial('average', [3, 3]);
%_img1Average = imfilter(img1, AverageFImg1);

% ___________________________ Gauss Filter
% 5, 6, 9, 21 salieron iguak
%_GaussFImg1 = fspecial('gaussian', [5, 5]);
%_img1Gauss = imfilter(img1, GaussFImg1);

% ___________________________ Median Square Error

[m n] = size(img1);
numElements = m * n;
% _____ Median Filter
%__MSEImg1Median = sum(sum((img - img1Median).^2))/numElements
%_MSEImg2Median = (sum(sum((img - img2Median).^2)))/numElements

% _____ Maximum Filter
%_MSEImg1Maximum = sum(sum((img - img1Maximum).^2))/numElements
% _____ Average Filter
%_MSEImg1Average = sum(sum((img - img1Average).^2))/numElements
% _____ Gauss Filter
%_MSEImg1Gauss = (sum(sum((img - img1Gauss).^2)))/numElements

% ___________________________ Show the results
% _____ img1
%imshow(img1_)
%figure, imshow(img1)
%figure, imshow(img1Median)
%figure, imshow(img1Maximum)
%figure, imshow(img1Average)
%figure, imshow(img1Gauss)


