'''
Author- Shashwat Garg, 200050130.
May 31, 2021
CS154 Lab 11, Recursion

Ackermann Function

5) Implement the table lookup technique in 4 above
for a recursive fibonacci implementation, and see
if it improves the computer's ability to compute
in some sense.  

'''

count = {};
values = {} 

# Uses a dictionary to keep track of the various fibonacci functions.
# Keeps track using dictionary with indices as n

def stepcount(n): 
    global count
    if n in count:
        count[n] += 1
    else:
        count[n] = 1

def displaycount():
    global count
    global values
    sum = 0
    for i in count:
        print("Number of calls made for Fibonacci("+ str(i) +") is: "+ str(count[i]))
        sum+=count[i]
    print("\nTotal number of calls "+ str(sum))
    count={} # resetting the count variable
    values={}

def fibonaccinormal (n): 
    stepcount(n)

    if n==1 or n==2:
        return 1
    else:
        return fibonaccinormal(n-1) + fibonaccinormal(n-2)


def fibonaccimemoized (n): 
    global values
    stepcount(n)

    if n in values:
        #print(i)
        return values[n]

    if n==1 or n==2:
        values[n]=1
    else:
        values[n-1]= fibonaccimemoized(n-1)
        values[n-2]= fibonaccimemoized(n-2)
        values[n] = values[n-1]+values[n-2]

    return values[n]


# Here you can input your own values to get whichver fibonacci function you want to calculate

n = int(input("Enter your value of n: "))


#print("\nValue of Fibonaccinormal("+str(n)+") is "+ str(fibonaccinormal(n))+"\n\n")
#displaycount()
#print("--------now we get to the memoized part-----------")


print("\nValue of Fibonaccimemoized("+str(n)+") is "+ str(fibonaccimemoized(n))+"\n\n")
displaycount()

# There is a ton of improvement. The total number of calls has reduced greatly.
# As an example, for n=34, for normal recursion, we have 11405773 calls. Now it is just 65.

#Memoization is a very useful technique
# You can even try un-commenting out the normal fibonacci part, to get idea of time difference
