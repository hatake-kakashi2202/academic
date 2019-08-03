clc
clear
close all
%%
To=3;
wo=2*pi/To;
Fs=1000;    %no.of samples
tvec=-To/2:1/Fs:To/2;
xt=zeros(size(tvec));
xt(abs(tvec)<=1)=exp((tvec(abs(tvec)<=1).^3));
%xt(abs(tvec)<=1)=exp(-2*abs(tvec(abs(tvec)<=1)));
kvec=-10:10;
for kx=1:length(kvec)
    k=kvec(kx);
    basis=exp(-1i*k*wo*tvec);
    avec(kx)=1/To*trapz(tvec,xt.*basis);
end
subplot(211)
stem(kvec,avec)
z=imag(avec);
subplot(212)
stem(kvec,z)