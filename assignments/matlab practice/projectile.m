clc
clear
close all
%%
%input variables
g=9.81;
vo=input('what is the initial speed');
tho = input('What is the launch angle in degrees?');
tho = pi*tho/180;

%time of flight and range
txmax = (2*vo/g) * sin(tho);
xmax = txmax * vo * cos(tho);
print(txmax)
print(xmax)

%sequence of steps for trajectory computation
dt = txmax/100;
t = 0:dt:txmax;