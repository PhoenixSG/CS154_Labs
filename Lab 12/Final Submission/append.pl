revlist([], L, L).
revlist([H|T], A, X) :- revlist(T,[H|A], X).


appendlist([], L, L).
appendlist([H|T], A, X) :- appendlist(T,[H|A], X).
