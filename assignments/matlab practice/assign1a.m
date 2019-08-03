n=-5:1:15;
ut=myUnitStep(n);
subplot(221)
stem(n,ut,'r');
title('u(t)');
p=n-5;
q=n-10;
p1=myUnitStep(p);
q1=myUnitStep(q);
r1=p1-q1;
subplot(222);
stem(n,r1,'b');
title('u(n-5) - u(n-10)');
s=6-n;
t=3-n;
r2=myUnitStep(s)-myUnitStep(t);
subplot(223)
stem(n,r2,'g');
title('u(6-n) - u(3-n)');
u=8-n;
r3=myUnitStep(u);
subplot(224)
stem(n,r3,'r');
title('u(8-n)');

function un=myUnitStep(n)
un=zeros(size(n));
un(n>=0)=1;
return;
end
