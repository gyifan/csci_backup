x = hw6prob2a(100000);
u = compress(x);
v = usquant(u, N);
y = decompress(v);
MSE = mean(power((x-y),2));
