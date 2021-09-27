revlist([], L, L).
revlist([H|T], A, X) :- revlist(T,[H|A], X).
revlist([H|T], X):- revlist([H|T], [], X).