t=-2:0.01:2
f=1.
x1=cos(4*pi*f*t)+cos(8*pi*f*t)% Even terms
x2=cos(2*pi*f*t)+cos(6*pi*f*t)% Odd terms
x3= cos(4*pi*f*t)% second harmonic
x4=cos(4*pi*f*t)+cos(5*pi*f*t) %Even odd terms
x5=cos(4*pi*f*t)+cos(2*pi*f*t)%Even  odd terms
 subplot(5,1,1), plot(t,x1)
 grid
   legend('A')
        subplot(5,1,2), plot(t,x2)
        grid
        legend('B')
         subplot(5,1,3),  plot(t,x3)
         grid
           legend('C')
          subplot(5,1,4),  plot(t,x4)
            legend('D')
          grid
           subplot(5,1,5),  plot(t,x5)
           grid
             legend('E')
           