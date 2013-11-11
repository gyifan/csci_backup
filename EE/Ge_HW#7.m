%defines j
j = sqrt(-1);
%defines values for C, L, and Rl
C = 800*10^(-12);
L = 0.4*10^(-6);
Rl = 50;
%Greates matrix to store values of f, R, X at different frequency.
f = 1:101;
R = 1:101;
X = 1:101;

%Use for loop store values of f, R, X at diferent frequency.
for i = 1:100;
    %defines frequency
    f(i+1) = i*10^6;
    %defines angular frequency
    w = 2*pi*f(i+1);
    %finds values for impedence of Z,C,and R at this frequency
    Zc = -j/(w*C);
    Zl = j*w*L;
    Zr = Rl;
    %finds the whole equavalent impedence
    Zeq = Zc+1/(1/Zr+1/Zl);
    %gets the resistance from Zeq
    R(i+1) = real(Zeq);
    %gets the reactance from Zeq
    X(i+1) = imag(Zeq);
end

%This is the first point of the plot. Since the frequency is zero, we have
%negatively infinite reactance and 0 resistance. 
f(1) = 0;
R(1) = 0;
X(1) = -Inf;

%plot the graph
plot(f,R,f,X,'--')    
grid on
title ('plot for Reactances and resistances at different frequency')
xlabel('Frequency (Hz)')
ylabel('Reactance or Resistance (Ohms)')
legend('Resistance','Reactance')
