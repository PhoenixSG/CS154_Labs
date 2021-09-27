connected(delhi, mumbai).
connected(mumbai, bangalore).
connected(bangalore, chennai).
connected(chennai, kolkata).
connected(kolkata, patna).
connected(patna, jaipur).
connected(jaipur, goa).
connected(goa, agra).

path(A, B) :- connected(A, B).
path(A, B) :- connected(A, C), path(C, B).
