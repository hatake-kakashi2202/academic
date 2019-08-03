
%%
function h=H(n)
h=zeros(size(n));
h(n==0)=3;
h(n==1)=2;
h(n==2)=1;
h(n==3)=2;
h(n==4)=3;
return
end