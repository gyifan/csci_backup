edge(a,b).
edge(a,f).
edge(b,c).
edge(c,d).
edge(c,e).
edge(e,d).
edge(f,c).
edge(f,e).
edge(f,g).
edge(g,c).

path2(Node1,Node2) :-
	edge(Node1,SomeNode),
	edge(SomeNode,Node2).

path3(Node1,Node2) :-
	path2(Node1,SomeNode),
	edge(SomeNode,Node2).

path3(Node1,Node2) :-
	edge(Node1,SomeNode1),
	edge(SomeNode1,SomeNode2),
	edge(SomeNode2,Node2).

path(Node1,Node2) :-
	Node1 == Node2.
path(Node1,Node2) :-
	edge(Node1,Node2).
path(Node1,Node2) :-
	edge(Node1,SomeNode),
	path(SomeNode, Node2).

chain(X,Y,[X,Y]) :- edge(X,Y).
chain(X,Y,[X|Z]) :- edge(X,I),path(I,Y),chain(I,Y,Z).
