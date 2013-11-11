split(R, [[], R]).
split([X|R], [[X|R1], R2]) :- split(R, [R1,R2]).

parts([], [[]]).
parts([X],[[X]]).
parts([X|R], [[X|Y] | S]) :- length(R,N), N >= 1, parts(R, [Y|S]).
parts([X|R], [[X] | [Y|S]]) :- length(R,N), N >= 1, parts(R,[Y|S]).

match(eps, []).
match(symb(A), [A]).
match(union(R1,R2), W) :- match(R1, W).
match(union(R1,R2), W) :- match(R2, W).
match(conc(R1,R2), W) :- 
	split(W,[L1,L2]),
	match(R1, L1),
	match(R2, L2).
match(star(R1), []).
match(star(R1), W) :- match(R1, W).
match(star(R1), W) :- 
	parts(W, [X,Y]),
	match(R1, X),
	match(star(R1), Y).

/*
Test1:
?- match(star(conc(star(symb(a)),star(symb(b)))), [b,b,a,a,b,b,a]).
true.

Test2:
?- match(star(conc(symb(a),conc(star(symb(b)),symb(c)))), [a,c,a,b,b,c,a,b,c,c]).
false.

*/


