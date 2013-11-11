mem(K, [K|R]).
mem(K, [H|R]) :- mem(K, R).
