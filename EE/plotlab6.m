j=sqrt(-1);
%f=100;
C1=47*10^(-12);
C2=150*10^(-12);
C3=47*10^(-12);
L1=300*10^(-9);
L2=300*10^(-9);
Rg=50;
Vg=1;
f=1:21;
ratio=1:21;

f(1)=0;
ratio(1)=0.5;

for i=1:20;
    f(i+1)=5*10^6*i;
    w=2*pi*f(i+1);
    Zc1=-j/(w*C1);
    Zc2=-j/(w*C2);
    Zc3=-j/(w*C3);
    Zl1=j*w*L1;
    Zl2=j*w*L2;
    A=[-Rg*Zc1 (Rg*Zc1+Rg*Zl1+Zl1*Zc1) 0; (Zl2*Zl1+Zl1*Zc2+Zl2*Zc2) -Zl2*Zc2 -Zl1*Zc2; -Zc3*Rg 0 (Zl2*Zc3+Rg*Zc3+Rg*Zl2)];
    b=[Zl1*Zc1*Vg; 0; 0];
    V=A\b;
    Vo=V(3);
    ratio(i+1)=abs(Vo/Vg);
end

plot(f,ratio)
