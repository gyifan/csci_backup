hanoi(1,L,C,R,[[L,R]]).
hanoi(A,L,C,R,M) :- 
	A > 1, 
	B is A-1,
	hanoi(B,L,R,C,N), 
	hanoi(B,C,L,R,O),
	append(N,[[L,R]],List),
	append(List,O,M).
