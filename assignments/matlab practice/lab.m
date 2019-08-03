clc
clear
close all
%%
A=1;
wo=pi;
To=2*pi/wo;
phi=pi/3;
Fs=1000;    %no.of samples
tvec=0:1/Fs:To;
xt=A*cos(wo*tvec+phi);
kvec=-10:10;
for kx=1:length(kvec)
    k=kvec(kx);
    basis=exp(-1i*k*wo*tvec);
    avec(kx)=1/To*trapz(tvec,xt.*basis);
end

stem(kvec,avec)