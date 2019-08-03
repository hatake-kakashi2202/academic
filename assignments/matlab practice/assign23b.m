
x = [1 2 -3 8 -9];
h = [3 2 1 2 3];
hf = fliplr(h);
xf = fliplr(x);
nk = -3:5;
M1 = length(x);
M2 = length(xf);
N1 = length(h);
N2 = length(hf);
L1 = M1 + N2 - 1;
L2 = M2 + N1 - 1;
xc1 = zeros(1,L1);
hc1 = zeros(1,L1);
xc1(1:M1) = x;
hc1(1:N2) = hf;
for n = 1:L1
	y1(n) = 0;
	for k = 1:n
		y1(n) = y1(n) + xc1(k)*hc1(n-k+1);
	end
end
xc2 = zeros(1,L2);
hc2 = zeros(1,L2);
xc2(1:M2) = xf;
hc2(1:N1) = h;
for n = 1:L2
	y2(n) = 0;
	for k = 1:n
		y2(n) = y2(n) + xc2(k)*hc2(n-k+1);
	end
end
subplot(211)
stem(nk,y1);
xlabel('n');
ylabel('y1[n]')
subplot(212)
stem(nk,y2);
xlabel('n');
ylabel('y2[n]')
y1
y2