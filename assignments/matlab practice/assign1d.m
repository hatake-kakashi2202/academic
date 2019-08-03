clc
clear
close all
%%
n=-2:0.001:6;
subplot(511);
stem(n,fun(n+1),'filled');
xlabel('x(n+1)');
subplot(512);
stem(n,fun(n-2),'filled');
xlabel('x(n-2)');
subplot(513);
stem(n,fun(3-n),'filled');
xlabel('x(3-n)');
subplot(514);
stem(n,fun(3-2*n),'filled');
xlabel('x(3-2*n)');
subplot(515);
stem(n,fun(4*n-5),'filled');
xlabel('x(4*n-5)');

function x=fun(n)
x=zeros(size(n));
x(n==0)=-1;
x(n==1)=-2;
x(n==2)=-3;
x(n==3)=4;
x(n==4)=-2;
end
