clc
clear
close all
%%
A=1;
a=3;
b=5;

t1=t-a;
ut1=myUnitStep(t1);

t2=t-a;
ut2=myUnitStep(t2);

rt=ut1-ut2;

plot(rt,t,'b');
xlib([-10,10]);
ylim([0,1.2]);