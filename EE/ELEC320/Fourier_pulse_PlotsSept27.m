% Plotting diagram for Fourier: Pulse train
% using Matlab sinc function
% note that it is in the form of sin (pi*z)/pi*z

% an=(2*a/T)sinc(n*pi*a/T)/(n*pi*a/T)
clear all
n=[0:1:60]
a=1;
T=10;
an=(2*a/T)*sinc(n*a/T)
stem(n,an)
xlabel('n')
ylabel('an')
legend('T=10, a=1')
figure(2)
stem(n,abs(an))
xlabel('n')
ylabel('abs(an), Magniude')
legend('T=10, a=1')
figure(3)
anangle=(180/pi)*angle(an)
stem(n,anangle)
xlabel('n')
ylabel('angle(an), Phase, degrees')
legend('T=10, a=1')
figure(4)
subplot(3,1,1),stem(n,an)
xlabel('n')
ylabel('an')
legend('T=10, a=1')
%%%% Change T=20
T=20;
an1=(2*a/T)*sinc(n*a/T)
subplot(3,1,2),stem(n,an1)
xlabel('n')
ylabel('an')
legend('T=20, a=1')
% Repeat with a=0.5
a=0.5;
an1=(2*a/T)*sinc(n*a/T)
subplot(3,1,3),stem(n,an1)
xlabel('n')
ylabel('an')
legend('T=20, a=0.5')