clc
clear all
close all
%%
x = [1 2 -3 8 -9];
h = [3 2 1 2 3];
subplot(311);
stem(x);
ylabel('x(n)');
subplot(312);
stem(h);
ylabel('h(n)');