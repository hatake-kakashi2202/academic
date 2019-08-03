clc 
clear
close all

%%
delt=0.001;
Fs=1/delt;
Fv=-3/2*Fs:delt:3/2*Fs;
fv = zeros(size(Fv));
fv(Fv>=-3/2*Fs & Fv<-1/2*Fs) = 1+ 1/Fs*Fv(Fv>=-3/2*Fs & Fv<-1/2*Fs);
fv(Fv>=-1/2*Fs & Fv<1/2*Fs)=1/Fs*Fv(Fv>=-1/2*Fs & Fv<1/2*Fs);
fv(Fv>=1/2*Fs & Fv<3/2*Fs)=-1+1/Fs*Fv(Fv>=1/2*Fs & Fv<3/2*Fs);

plot(Fv,fv,'o');
xlabel('Analog Frequency(F xFs)');
ylabel('Discrete Frequency(f)');