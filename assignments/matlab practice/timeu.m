clc 
clear
close all

%%
delt=0.001;
N=10;
t=-N:delt:N;
ut=zeros(size(t));
ut(t>=0)=1;
plot(t,ut);
xlabel('time(t)');
ylabel('u(t)');