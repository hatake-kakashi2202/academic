
%%
function y=convol(x,h)
a=length(x);
b=length(h);
len=a+b-1;
x(a+1:len)=0;
h(b+1:len)=0;
y(1:len)=0;
for i=1:len
    u=fliplr(x(1:i));
    op=h(1:i).*u;
    y(i)=sum(op);
end
return
end