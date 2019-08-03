clc
close all
clear all
%%
t=2:0.01:8;
tau=2:0.01:8;
y=zeros(length(t));
x=myUnitStep(tau-3)-myUnitStep(tau-5);
for i=1:length(y)
  h=exp(-3*(t(i)-tau)).*myUnitStep(t(i)-tau);
  y(i)=trapz(tau,x.*h);
end
plot(t,y),grid;