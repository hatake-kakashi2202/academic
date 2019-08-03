clc
clear
close all
%%
tvec = -1:0.01:1;
w = -100:100;
for i = 1:length(w)
xfwd(i) = trapz(tvec,xin(tvec).*exp(-1i*w(i)*tvec));
end
for i = 1:length(tvec)
xrev(i) = (1/(2*pi))*trapz(w,exp(1i*w*tvec(i)).*xfwd);
end
theor = 2*1i*cos(w)./(w) ...
    - 6*1i*sin(w)./(w).^2  ...
    -12*1i*cos(w)./(w).^3 ...
    +12*1i*sin(w)./(w).^4;
theor((size(w)+1)/2) = 0;
figure(1)
subplot(2,1,1)
hold on
stem(w,real(theor),'+');
stem(w,real(xfwd),'o');
xlabel('real fourier transform (+ Theoritical values)');
subplot(2,1,2)
hold on
stem(w,imag(xfwd),'o');
stem(w,imag(theor),'+');
xlabel('imaginary fourier transform (+ Theoritical values)')
figure(2)
plot(tvec,xrev);
xlabel('Reconstructed');
figure(3)
plot(tvec,xin(tvec));
xlabel('original');
function x = xin(t)
x = t.^3;
end

