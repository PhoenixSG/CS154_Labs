'''
Author- Shashwat Garg, 200050130.
May 31, 2021
CS154 Lab 11, Recursion

Ackermann Function

1) Write the function in python and check your output

'''

def ack (m,n): 
    #print("call made")
    if m==0:
        return n+1
    elif n==0:
        return ack(m-1,1)
    else:
        return ack(m-1,ack(m,n-1))


#Initial values are pretty small but recursion is very powerful in m.
# The increase in m greatly increases the depth of recursion 
# increasing n also increases the value

# Also, I read about this on the internet, about how Ackerman is not primitively recursive.
# This means that it cannot be described iteratively. It is pure recursion.
# I also read that, due to its definition in terms of very deep recursion, we can use it as a test of a compiler's ability to recurse.

print(ack(0,0))
print(ack(1,0))
print(ack(0,1))
print(ack(1,1))
print(ack(1,2))
print(ack(2,1))
print(ack(0,2))
print(ack(2,0))
print(ack(2,2))
print("------------------")
print(ack(3,3))
print(ack(3,4))
print(ack(3,5))
print(ack(3,6))
#print(ack(4,1))
#print(ack(4,2))
#Bottom 2 gave error- RecursionError: maximum recursion depth exceeded in comparison
#Grows so rapidly, the last answer is supposed to be 19,729 digits long. Huge!
