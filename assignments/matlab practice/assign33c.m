Fs=30;
Ts=1/Fs;
t=-2*pi:Ts:2*pi-Ts;
y=sinc(pi*t);
figure(1);
plot(t,y,'linewidth',1.5); grid on;
xlim([-2 2]);

N=600;
fy=(fft(y,N));
figure(2);
fr=(0:N-1)*Fs/N;
plot(fr,fftshift(abs(fy)),'linewidth',1.5);