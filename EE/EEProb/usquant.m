function y = usquant(x, N)
    xgt1 = x >= 1;
    xltn1 = x <= -1;
    n1x1 = -1<x & x<1;
   
    y(xltn1) = -1 + 1/N;
    y(xgt1) = 1 - 1/N;
    n(n1x1) = h(x(n1x1), N);
    r(n1x1) = round(n(n1x1));
    y(n1x1) = h_inv(r(n1x1), N);
end

