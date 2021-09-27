countelem([],X,0).
countelem([X|L],X,A):- countelem(L,X,B), A is B+1.
countelem([Xnew|L],X,Z):- countelem(L,X,Z) , X=\=Xnew.