female(zouLiying).
female(liHuiying).
female(wangQing).
female(geJianhua).
female(huJiayi).
female(wangYuanyuan).
male(geXingbao).
male(wangXinglong).
male(geYifan).
male(geZhixi).
male(geZhidong).
male(huangMinyuan).
male(geZihan).
male(geJianyong).
parent(zouLiying, geZhixi).
parent(zouLiying, geZhidong).
parent(geXingbao, geZhixi).
parent(geXingbao, geZhidong).
parent(liHuiying, wangQing).
parent(liHuiying, wangYuanyuan).
parent(wangXinglong, wangQing).
parent(wangXinglong, wangYuanyuan).
parent(geZhixi, geYifan).
parent(wangQing, geYifan).
parent(geZhidong, geJianyong).
parent(geZhidong, geJianhua).
parent(geJianhua, huangMinyuan).
parent(geJianyong, geZihan).
parent(wangYuanyuan, huJiayi).

father(Father, Child) :-
	male(Father),
	parent(Father, Child).

mother(Mother, Child) :-
	female(Mother),
	parent(Mother, Child).

son(Son,Parent) :-
	male(Son),
	parent(Parent, Son).

daughter(Daughter, Parent) :-
	female(Daughter),
	parent(Parent, Daughter).

grandparent(GrandParent, GrandChild) :-
	parent(GrandParent, SomeOne),
	parent(SomeOne, GrandChild).

sibling(Person1, Person2) :-
	Person1 \= Person2,
	parent(SomeOne, Person1),
	parent(SomeOne, Person2).

aunt(Aunt, Person) :-
	female(Aunt),
	sibling(Aunt, SomeOne),
	parent(SomeOne, Person).

uncle(Uncle, Person) :-
	male(Uncle),
	sibling(Uncle, SomeOne),
	parent(SomeOne, Person).

cousin(Person1, Person2) :-
	parent(SomeOne1, Person1),
	parent(SomeOne2, Person2),
	sibling(SomeOne1,SomeOne2).

ancestor(Ancestor, Person) :-
	parent(Ancestor, Person).
ancestor(Ancestor, Person) :-
	parent(Ancestor, SomeOne),
	parent(SomeOne, Person).	
