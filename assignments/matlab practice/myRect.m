
function rt=myRect(t,A,a,b)

ta=t-a;
u1=myUnitStep(ta);

tb=t-b;
u2=myUnitStep(tb);

rt=A*(u1-u2);
return;
