x=linspace(-1.5,1.5,300);
y=usquant(x,N);
plot(x,y);
axis([-1.5 1.5 -1 1]);
xlabel('x');
ylabel('y');
title('uniform scalar quantization');
grid on;