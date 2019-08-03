clc
clear
close all
%%
t1=0;
t2=3*pi;
T=pi/2;
n=(t2-t1)/T;
y=1:1:n;
for i=1:n
    l=t1+(i-1)*T:pi/100:t1+i*T;
    xt=sin(l);
    yt(i)=(1/T)*trapz(l,xt);
end
plot(y,yt,'.');