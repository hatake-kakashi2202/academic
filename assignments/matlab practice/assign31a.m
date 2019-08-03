clear;
clc;
close all
%%
global W0 tval T0;
T0 = 3;
W0 = 2*pi/T0;
tval = -10:0.01:10;
k = -100:100;
c = f_coeff(abs(k(1)));
N=floor(abs(tval(1))/T0);
x = zeros(size(tval));
for i = -N:N
    x = x + xin(tval+i*T0);
end 
theor = 1/T0*((2*sin(k*W0)./(k*W0))-(4*sin(k*W0)./(k.^3*W0.^3))+(4*cos(k*W0)./(k.^2*W0.^2)));
theor((size(k)+1)/2)=2/9;
figure(1)
subplot(2,1,1)
stem(k,imag(c));
xlabel('Imaginary part for fourier coefficients');
subplot(2,1,2)
hold on
stem(k,theor,'+')
stem(k,real(c),'o');
xlabel('Real part for fourier coefficients  (+ for theoritical)');
for i=1:(length(k)-1)/2
    conver(i) = (1/T0)*trapz(tval,(x-re_con(i)).^2);
end
figure(2)
subplot(2,1,1)
plot(tval,re_con(abs(k(1))),'b');
xlabel('reconstructed function');
subplot(2,1,2)
plot(tval,x,'r');
xlabel('original function');
figure(3)
stem(1:(length(k)-1)/2,conver);
xlabel('value');
ylabel('converergence values');
function x = xin(t)
x = zeros(size(t));
x(t>-1 & t<1) = t(t>-1 & t<1).^2;
end
function x1 = re_con(m)
global W0 tval;
temp = f_coeff(m);
x1 = zeros(size(tval));
k = -m:m;
for i=1:2*m+1
    x1 = x1+exp(1i*W0.*k(i)*tval)*temp(i);
end
end
function coeff = f_coeff(k)
global W0 tval T0;
k1 = -k:k;
coeff = zeros(size(k1));
for i = 1:length(k1)
    basis = exp(-1i*W0.*k1(i)*tval);
    coeff(i) = (1/T0)*trapz(tval,xin(tval).*basis);
end
end