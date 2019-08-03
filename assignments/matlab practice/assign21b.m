x1 = [3 1 4 16 2];
h = [2 -1 -4 1 -3];
M1 = length(x1);
N = length(h);
L1 = M1 + N - 1;
xe1 = zeros(1,L);
he1 = zeros(1,L);
xe1(1:M1) = x1;
he1(1:N) = h;
for n = 1:L1
    y1(n) = 0;
    for k=1:n
        y1(n) = y1(n) + xe1(k)*he1(n-k+1);
    end
end
x2 = [3 -1 3 -1];
M2 = length(x2);
L2 = M2 + N - 1;
xe2 = zeros(L2);
he2 = zeros(L2);
xe2(1:M2) = x2;
he2(1:N) = h;
for n = 1:L2
    y2(n) = 0;
    for k = 1:n
        y2(n) = y2(n) + xe2(n)*he2(n-k+1);
    end
end
y = y1 + [y2,0];
stem(y);
y