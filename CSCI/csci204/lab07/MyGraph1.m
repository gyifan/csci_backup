close all
load outru
x = outru(:,1);
y = outru(:,2);
load outsu
a = outsu(:,1);
b = outsu(:,2);
n = linspace(8, 16384, 200);
nlogn = n.*(log(n)/log(2));
nxn = n.*n;
plot(x, y, 'o:', a, b, '*:', n, nlogn, '-', ...
     n, nxn, '-');
legend('Random data, unmodified quicksort', ...
       'Sorted data, unmodified quicksort', ...
       'n log n', 'n^2', ...
       'Location', 'SouthEast');
grid
xlabel 'n'
ylabel 'Key Comparisons'
title 'First part only - This is not the lab answer'
orient landscape
myAxis = axis;
myAxis(4) = 270000;
axis(myAxis)
