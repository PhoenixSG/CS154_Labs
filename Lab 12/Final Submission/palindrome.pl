revlist([], L, L).
revlist([H|T], A, X) :- revlist(T,[H|A], X).
palindrome(A) :- revlist(A,[],A).