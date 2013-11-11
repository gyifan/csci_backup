t=-2:.005:2;
x1=cos(2*pi*t)
x2=sin(2*pi*t)
x3=square(t)

plot(t,x1,'*')
xlabel('t')
grid
figure(2) 
plot(t,x2,'*')
xlabel('t')
grid
figure(3)
plot(t,x3,'*')
xlabel('t')
grid
figure(4)

plot(t,(x1>=0).* x1,'*')
xlabel('t')
grid


