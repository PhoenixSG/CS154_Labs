'''
Author- Shashwat Garg, 200050130.
May 31, 2021
CS154 Lab 11, Recursion

Ackermann Function

2) count total no. of calls made to ackerman
'''

count=0

def stepcount():
    global count
    count+=1

def displaycount():
    global count
    print("Number of calls made for this output- "+ str(count))
    count=0 # resetting the count variable

def ack (m,n): 
    #print("call made")
    stepcount()
    if m==0:
        return n+1
    elif n==0:
        return ack(m-1,1)
    else:
        return ack(m-1,ack(m,n-1))


# Here you can input your own values to get whichver ackerman function you want to calculate

m = int(input("Enter your value of m: "))
n = int(input("Enter your value of n: "))


print("\nValue of Ackermann("+str(m)+","+str(n)+") is "+ str(ack(m,n)))
displaycount()

# We cannot calculate ackermann of numbers with m>3 using plain recursion, lets try memoization in the next step
