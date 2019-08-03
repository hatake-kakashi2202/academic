clc
clear
close all
%%
t=-12:0.01:12;
y=zeros(size(t));
for x=-10:1:10
    y=y+fun(t+x*3);
end
subplot(211);
plot(t,fun(t));
xlabel('x(t)');
axis([-6,8,-1,1]);
subplot(212);
plot(t,y);
xlabel('y(t) with period 3');
axis([-8,8,-1,1]);

function x=fun(t)
x=zeros(size(t));
x(t>-1&t<0)=exp(2*t(t>-1&t<0));
x(t>0&t<1)=exp(-2*t(t>0&t<1));
return;
end