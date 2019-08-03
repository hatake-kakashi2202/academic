clc
clear
close all
%%
%T=3
%w0=2*pi*T;
%del=0.001;
%t=0:del:T;
%xt=sin(w0*t);
%fs=1/del;
%ws=2*pi*fs;
%f0<fs/2;
%xt=sin

N=50;
M=900;
T=1/M;
n=(0:N-1);
tvec=3*T*(0:M-1);
theta=pi/3;
xt=sin(2*pi*tvec+theta);
figure;
%%
plot(tvec,xt,'LineWidth',2);
set(gca,'Box','on',...,
        'FontSize',12,...,
        'LineWidth',1.5,...,
        'FontName','Helvetica',...,
        'Color',[0.95,0.95,0.95],...,
        'XGrid','off',...,
        'YGrid','off');
    xlabel('time x pi');
    ylabel('sine');
legend('Analog:Non zero phase');
Ns=60;
Nt=length(tvec);
sam_inx=1:Ns:Nt;
x=zeros(size(xt));
x(sam_inx)=xt(sam_inx);
x(x==0)=NaN;

hold on
stem(tvec,x,'r','LineWidthl',2);

set(gca,'Box','on',...,
        'FontSize',12,...,
        'LineWidth',1.5,...,
        'FontName','Helvetica',...,
        'Color',[0.95,0.95,0.95],...,
        'XGrid','off',...,
        'YGrid','off');
    
%%
