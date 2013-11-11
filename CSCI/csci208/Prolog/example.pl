edge(a,b).
edge(a,e).
edge(b,d).
edge(b,c).
edge(c,a).
edge(e,b).

path2(Node1, Node2) :-
	edge(Node1, SomeNode),
	edge(SomeNode, Node2).

fib(0,1).
fib(1,1).

fib(N,F) :- 
	N > 1, 
	N1 is N - 1, 
	fib(N1, F1), 
	N2 is N-2, 
	fib(N2,F2), 
	F is F1 + F2.
