
function un=myUnitStep(n)
un=zeros(size(n));
un(n>=0)=1;
return;
end
