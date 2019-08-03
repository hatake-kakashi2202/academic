clear;
clc;
tvec = -1:0.01:1;
w = -100:100;
for i = 1:length(w)
xfwd(i) = trapz(tvec,xin(tvec).*exp(-1i*w(i)*tvec));
end
for i = 1:length(tvec)
xrev(i) = (1/(2*pi))*trapz(w,exp(1i*w*tvec(i)).*xfwd);
end
theor = sin(w)./w-cos(w)./w.^2+1./w.^2;
theor((size(w)+1)/2) = 1.5; %%since as k = 0 theor0 = infinite
figure(1)
subplot(2,1,1)
hold on
stem(w,real(theor),'+');
stem(w,real(xfwd),'o');
xlabel('real fourier transform + -Theoritical values,o -in code values')
subplot(2,1,2)
hold on
stem(w,imag(xfwd),'o');
stem(w,imag(theor),'+');
xlabel('imaginary fourier transform + -Theoritical values,o -in code values')
figure(2)
plot(tvec,xrev);
xlabel('Reconstructed');
figure(3)
plot(tvec,xin(tvec));
xlabel('original');
function x = xin(t)
x = zeros(size(t));
x(t<1 & t> -1)= 1-abs(t(t<1 & t> -1))/2;
end