'''
Author- Shashwat Garg, 200050130.
May 31, 2021
CS154 Lab 11, Recursion

Ackermann Function

4) Try to reduce these calls by saving the results once
computed in a table, and instead of making a call,
return the result from the table.
Now print the no. of calls and no. of table lookups.

'''

count = {};
values = {} 

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
    print("\nTotal number of calls "+ str(sum))
    count={} # resetting the count variable



def ack (m,n): 
    global values
    stepcount(m,n)

    i=str(m)+","+ str(n)
    if i in values:
        #print(i)
        return values[i]


    if m==0:
        values[i]=n+1
    elif n==0:
        values[i]= ack(m-1,1)
    else:
        values[i]= ack(m-1,ack(m,n-1))

    return values[i]


# Ackermann function has been changed, now whichever values needs to be calculated, first gets assigned to values dictionary and then gets returned.
# Also, the program checks for value already being present. This prevents over, repeated calculation.






# Here you can input your own values to get whichver ackerman function you want to calculate
m = int(input("Enter your value of m: "))
n = int(input("Enter your value of n: "))


print("\nValue of Ackermann("+str(m)+","+str(n)+") is "+ str(ack(m,n))+"\n\n")
displaycount()
print("\nAgain, Final Value of Ackermann("+str(m)+","+str(n)+") is "+ str(ack(m,n)))

# This is much better. The total number of calls has reduced greatly.
# As an example, Earlier, we had 2432 calls for ack(3,3). Now it is just 186.

# There is improvement for m=3, We can now calculate ack(3,7) and ack(3,8), which werent possible earlier, due to recursion depth overflow
# Similarly, the argument range for n for m=2 is increased

# This is a good improvement, but still we still cannot calculate ackermann of numbers with m>3 using plain recursion.
# This is probably because ackermann function for m=4 brings in such a large such a large 


