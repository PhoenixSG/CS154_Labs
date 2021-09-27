connected(delhi, mumbai).
connected(mumbai, bangalore).
connected(bangalore, chennai).
connected(chennai, kolkata).
connected(kolkata, patna).
connected(patna, jaipur).
connected(jaipur, goa).
connected(goa, agra).

connected(A, B) :- connected(A, C), connected(C, B).
