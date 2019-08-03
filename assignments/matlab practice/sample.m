w=pi/2;

n=-9:0.1:9;

%sin function

subplot(311);

stem(n,sin(w*n));

xlim([-10,10]);

ylim([-1,1]);

title('sin(wn)');

%cos function

k=2;

n1=n-k;

n2=n+k;

subplot(312);

stem(n,cos(w*n1),'b');

title('cos(w(n-k))');

subplot(313);

stem(n,cos(w*n2),'r');

title('cos(w(n+k)');