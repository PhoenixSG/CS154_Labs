mother(ron, tracy).
mother(tracy, nancy).
grandmother(X, Y) :- mother(X, Z), mother(Z, Y).
