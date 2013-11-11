t = (0:1:180)
y = zeros(1,180)
for n = 0:180
    if n<=90
        y(n+1)=abs((cos((t(n+1))/180*pi())^4))
    else
        y(n+1)=0
    end
end

plot(t,y)
title('Normalized Power Pattern')
xlabel('Theta in degrees')
ylabel('F(Theta)')
grid on