clc
clear
close all

%%
%width of the pulse T
T=2;
%height of the pulse
A=1;
%no.of pulses
N=10;
%time support
t=-5:0.001:30;
ws=zeros(size(t));
for i=1:N
    ai=(i-1)*T;
    bi=i*T;
    if rem(i,2)==0
        Ai=-1;
        ai=(i-1)*T-0.8;
    else
        Ai=1;
        bi=i*T-0.8;
    end
    
    rti=myRect(t,Ai,ai,bi);
    ws=ws+rti;
end
plot(t,ws,'LineWidth',2);
xlabel('time');
ylabel('amplitude');
