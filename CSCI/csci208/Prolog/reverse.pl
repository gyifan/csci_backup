append([],L,L).
append([H|T],X,[H|N]) :- append(T,X,N).

reverse([],[]).
reverse([H|T],R) :-
	reverse(T,TR),
	append(TR,[H],R).
