x = [-3 -2 0 1 2 3];
h = [3 1 1 3 1 1];
M = length(x);
N = length(h);
L = M + N - 1;
xe = zeros(1,L);
he = zeros(1,L);
xe(1:M) = x;
he(1:N) = h;
for n=1:L
    y(n) = 0;
    for k = 1:n
        y(n) = y(n) + xe(k)*he(n - k + 1);
    end
end
l=0:1:10;
m=-3:1:2;
n=0:1:5;
subplot(311);
stem(m,x);
ylabel('x(n)');
subplot(312);
stem(n,h);
ylabel('h(n)');
subplot(313);
stem(l,y);
ylabel('y(n)');
y