substring([], _).

substring([H|A], [H|B]) :- substring(A, B).

substring([H|A], [C|B]) :- substring([H|A], B), H=\=C.