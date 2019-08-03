function x=cx(n)
x=zeros(size(n));
x(n==0)= 1;
x(n==1)= 2;
x(n==2)= -3;
x(n==3)=8;
x(n==4) =-9;
return;