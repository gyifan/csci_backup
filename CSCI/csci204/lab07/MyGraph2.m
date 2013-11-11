close all
load outru
x = outru(:,1);
y = outru(:,2);
load outsu
a = outsu(:,1);
b = outsu(:,2);
load outsm
c = outsm(:,1);
d = outsm(:,2);
load outrm
e = outrm(:,1);
f = outrm(:,2);
n = linspace(8, 16384, 200);
nlogn = n.*(log(n)/log(2));
nxn = n.*n;
plot(x, y, 'o:', a, b, '*:', c, d, 'x:', e, f, '+:', n, nlogn, '-', ...
     n, nxn, '-');
legend('Random data, unmodified quicksort', ...
       'Sorted data, unmodified quicksort', ...
       'Sorted data, modified quicksort', ...
       'Random data, modified quicksort', ...
       'n log n', 'n^2', ...
       'Location', 'SouthEast');
grid
xlabel 'n'
ylabel 'Key Comparisons'
title 'Yifan Ge - CSCI 204 Quicksort lab'
orient landscape
myAxis = axis;
myAxis(4) = 270000;
axis(myAxis)
