clear all;

% Problem 1
%==========================================================================
w = [-5:0.001:5];

Fa = exp(-j*w*0.5).*sinc(w*pi()/2);

figure (1)
plot (w, Fa)
title('F(jw) vs. w')
xlabel ('w')
ylabel ('F(jw)')
grid on

Fb = 2*exp(-j*w).*sinc(w*pi());

figure (2)
plot (w, Fb)
title('F1(jw) vs. w')
xlabel ('w')
ylabel ('F1(jw)')
grid on

Fc = exp(-j*w*1.5).*sinc(w*pi()/2);

figure (3)
plot (w, Fc)
title('F2(jw) vs. w')
xlabel ('w')
ylabel ('F2(jw)')
grid on

% Problem 3
%==========================================================================

t = [0:0.01:6];
n = 1;
a = 1/2;
b = 1/2;

% Plot x(t) vs. t
xt = cos(n*pi()*t/2) + sin(n*pi()*t/2);

figure (4)
subplot(2,1,1)

plot (t, xt)
title('x(t) vs. t while n = 1')
xlabel ('t')
ylabel ('x(t) = cos(n*pi*t/2) + sin(n*pi*t/2)')
grid on

% Plot y(t) vs. t
yt = xt + a*b*xt;

subplot(2,1,2)
plot (t, yt)
title('y(t) vs. t while a = 1/2, b = 1/2')
xlabel ('t')
ylabel ('y(t) = x(t) + a*b*x(t)')
grid on

% Problem 4
%==========================================================================

t = [-1:0.01:2];

% Plot x(t) vs. t
xt = t.*(heaviside(t)-heaviside(t-1));

figure (5)
subplot(3,1,1)

plot (t, xt)
axis([-1,2,-0.5,1.5])
title('x(t) vs. t')
xlabel ('t')
ylabel ('x(t) = t(u(t)-u(t-1))')
grid on

% Plot h(t) vs. t
ht = heaviside(t)-heaviside(t-1);

subplot(3,1,2)

plot (t, ht)
axis([-1,2,-0.5,1.5])
title('h(t) vs. t')
xlabel ('t')
ylabel ('h(t) = t(u(t)-u(t-1))')
grid on

% Plot y(t) vs. t 
ht = heaviside(t-1)-heaviside(t-2);
yt = convn(xt,ht,'same');

subplot(3,1,3)
plot (t, yt)
axis([-1,2,-0.5,4])
title('y(t) vs. t')
xlabel ('t')
ylabel ('y(t) = x(t)*y(t) ERROR')
grid on

% Problem 5
%==========================================================================
t = [-0.5:0.01:4];

% Plot x(t)
xt = (5*sin(10*t)).*heaviside(t);

figure (6)
subplot(2,1,1)

plot (t, xt)
title('x(t) vs. t')
xlabel ('t')
ylabel ('x(t) = (5*sin(10*t))u(t)')
grid on

% Plot y(t)
yt = (-2.5*(cos(10*t)-sin(10*t))+2.5*exp(-10*t)).*heaviside(t);

subplot(2,1,2)
plot (t, yt)
axis([-0.5,4,-5,5])
title('y(t) vs. t')
xlabel ('t')
ylabel ('y(t) = (-2.5*(cos(10*t)-sin(10*t))+2.5*exp(-10*t))u(t)')
grid on

% FFT of h(t)
Fs = 30;
T = 1/Fs;
L = 1000;
t = (0:L-1)*T;
ht = 1/sqrt(2)*cos(10*t-pi()/4).*heaviside(t);

NFFT = 2^nextpow2(L);
H = fft(ht,NFFT)/L;
f = Fs/2*linspace(0,1,NFFT/2+1);

figure (7)
plot(f*(2*pi()), 2*abs(H(1:NFFT/2+1)))
title('FFT of h(t)')
xlabel('w(rad/s)')
ylabel('|H(f)|')

% FFT of x(t)
xt = (5*sin(10*t)).*heaviside(t);
X = fft(xt, NFFT)/L;

figure (8)
plot(f, 2*abs(X(1:NFFT/2+1)))
title('FFT of x(t)')
xlabel('Frequency (Hz)')
ylabel('|X(f)|')

% Z-transform of h(t)
syms n;
h = 1/sqrt(2)*cos(10*n-pi()/4).*heaviside(n);
ztrans(h)

% Plot |H(exp(jwT)| vs. w.
w = [0:0.01:13];
h = exp(-j*w*pi()/4)/sqrt(2)*pi().*[dirac(w-10)+dirac(w+10)];

figure (9)
plot(w, abs(h))
title('|H(exp(-j*w*pi/4))| vs. w ERROR')
xlabel('w (rad/s)')
ylabel('|H(exp(-j*w*pi/4))|')

% Problem 6
%==========================================================================

% Plot v(t) vs t
T = 1/4000;
t = [0:0.00001:0.001];
vt = 4/pi()*sin(2*pi()*t/T) + 2/pi()*sin(4*pi()*t/T);

figure (10)
subplot(2,1,1)
plot(t, vt)
title('v(t) vs. t')
xlabel('t(s^(-1))')
ylabel('v(t)')

% Plot y(t) vs t
yt =1/sqrt(16*pi()^2+1)*sin(2*pi()*t/T-atan(4*pi()))+1/sqrt(144*pi()^2+1)*sin(4*pi()*t/T-atan(12*pi()));

subplot(2,1,2)
plot(t, yt)
title('y(t) vs. t')
xlabel('t(s^(-1))')
ylabel('y(t)')