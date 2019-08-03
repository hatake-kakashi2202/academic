clc
clear
close all
%%
wo=2*pi/3;
A=5;
To=2*pi/wo;
Fs=1000;

tvec=-To/2:1/Fs:To/2;
xt=zeros(size(tvec));
xt(abs(tvec)<1)=1-(tvec(abs(tvec)<1)/3);
t=-10:10;
kvec=-10:10;
for kx=1:length(kvec)
    k=kvec(kx);
    basis=exp(-1i*k*wo*tvec);
    avec(kx)=(1/To)*trapz(tvec,xt.*basis);
end
subplot(4,1,1);
stem(kvec,real(avec)),title('real')
subplot(4,1,2);
stem(kvec,imag(avec)),title('imaginary')


%Reconstruction
sq_recon=zeros(size(tvec));
for kx= 1:length(kvec)
    k=kvec(kx);
    basis=exp(1i*k*wo*tvec);
    sq_recon=sq_recon+avec(kx)*basis;
end
subplot(4,1,3);
stem(tvec,sq_recon);
xlim([-1 1]);