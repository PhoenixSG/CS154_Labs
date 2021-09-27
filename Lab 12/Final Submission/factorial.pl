factorial(0, 1).
factorial(X, Y) :- factorial(A, B), X is A+1, Y is B*X, X>0.