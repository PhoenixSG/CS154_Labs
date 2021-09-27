'''
Author- Shashwat Garg, 200050130.
May 31, 2021
CS154 Lab 11, Recursion

Ackermann Function

3) count total no. of calls for each recursive 
instance of ackerman (k1,k2) where k1 and k2 are specific
combinations
'''

count = {};


# Uses a dictionary to keep track of the various ackermann functions.
# Keeps track using dictionary with indices as strings of the form m,n

def stepcount(m,n): 
    global count
    i=str(m)+","+ str(n)
    if i in count:
        count[i] += 1
    else:
        count[i] = 1

def displaycount():
    global count
    sum = 0
    for i in count:
        print("Number of calls made for Ackermann("+ i +") is: "+ str(count[i]))
        sum+=count[i]
    print("\n\nTotal number of calls "+ str(sum))
    count={} # resetting the count variable

def ack (m,n): 
    #print("call made")
    stepcount(m,n)
    if m==0:
        return n+1
    elif n==0:
        return ack(m-1,1)
    else:
        return ack(m-1,ack(m,n-1))


# Here you can input your own values to get whichver ackerman function you want to calculate

m = int(input("Enter your value of m: "))
n = int(input("Enter your value of n: "))


print("\nValue of Ackermann("+str(m)+","+str(n)+") is "+ str(ack(m,n))+"\n\n")
displaycount()
print("\nAgain, Final Value of Ackermann("+str(m)+","+str(n)+") is "+ str(ack(m,n)))

# We still cannot calculate ackermann of numbers with m>3 using plain recursion.
# Here, we are just storing the number of calls, not the value of each call.
# Lets do that in the next step to avoid the familiar error of--> RecursionError: maximum recursion depth exceeded while getting the str of an object
