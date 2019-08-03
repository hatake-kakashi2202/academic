x = [1 2 -3 8 -9];
h = [3 2 1 2 3];
h_n = fliplr(h);
x_n = fliplr(x);
n = -3:5;
y = conv(x,h_n);
y1 = conv(x_n,h);
y
y1

