min([X],X).
min([A,B|C],X) :- A=<B, min([A|C],X).
min([A,B|C],X) :- A>B, min([B|C],X).