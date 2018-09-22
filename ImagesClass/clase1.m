% Leer una imagen

im = imread('profundidad.jpg');
figure(1)
imshow(im);
title('Imagen original')
[r,c,ch] = size(im);

L = max(max(max(im)));

imNeg = L - im;

%imnor= im/L;
figure(2)

imshow(imNeg);
title('Imagen negativa')

%% Gamma Correction
clear all;
close all;

im = imread('profundidad.jpg');
figure(1)
imshow(im);
title('Imagen original')
[r,c,ch] = size(im);

imAj2 = imadjust(im, [],[], 0.2);
imAj4 = imadjust(im, [],[], 0.4);
figure(2)
imshow(imAj2);
title('Imagen gamma correction 0,2')

figure(3)
imshow(imAj4);
title('Imagen gamma correction 0,4')

%% histograma de una imagen

clear all;
close all;

im = imread('profundidad.jpg');
figure(1)
imshow(im);
title('Imagen original')
[r,c,ch] = size(im);

h_im = imhist(im);
figure(2)
imhist(im);

h_ime = histeq(im);

figure(3)
imshow(h_ime);

figure(4)
imhist(h_ime);

%imAj4 = imadjust(im, [],[], 0.4);

%figure(3)
%imhist(imAj4);