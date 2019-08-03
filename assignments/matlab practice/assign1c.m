clc 
clear
close all
%%
t=-5:0.01:10;
subplot(411);
plot(t,fun(t-2),'b');
xlabel('x(t-2)');
subplot(412);
plot(t,fun(t+3),'r');
xlabel('x(t+3)');
subplot(413);
plot(t,fun(3*t-4),'b');
xlabel('x(3*t-4)');
subplot(414);
plot(t,fun(1-3*t),'r');
xlabel('x(1-3*t)');

function x=fun(t)
x = zeros(size(t));
x(t<0) = 0;
x(t>=0 & t<1)=2*t(t>=0 & t<1);
x(t>=1 & t<3)=3-t(t>=1 & t<3);
x(t>=3 & t<5)=-3+t(t>=3 & t<5);
x(t>=5 & t<7)=2;
x(t>=7)=0;
return;
end