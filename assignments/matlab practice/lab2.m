clc
clear
close all
%%
t=-25:0.01:25;
ut=myUnitStep(t);
t1=t-3;

ut1=myUnitStep(t1);

subplot(211);
plot(t,ut);
subplot(221);
plot(t,ut1);