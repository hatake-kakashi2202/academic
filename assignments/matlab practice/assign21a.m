x1 = [3 1 4 16 2];
x2 = [3 -1 3 -1];
h = [2 -1 -4 1 -3];
x = x1 + [x2,0];
M = length(x);
N = length(h);
L = M + N - 1;
xc = zeros(1,L);
hc = zeros(1,L);
xc(1:M) = x;
hc(1:N) = h;
for n = 1:L
    y1(n) = 0;
    for k = 1:n
        y1(n) = y1(n) + xc(k)*hc(n-k+1);
    end
end
l=0:1:4;
%subplot(311);
%stem(y1);
%ylabel('y1(n)');
subplot(311);
stem(l,x1);
m=0:1:3;
ylabel('x1(n)');
subplot(312);
stem(m,x2);
ylabel('x2(n)');
subplot(313);
stem(l,h);
ylabel('h(n)');
y1