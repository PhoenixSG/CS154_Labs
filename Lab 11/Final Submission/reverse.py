def reverse(l):
    if len(l)==0:
        return []
    
    a=[l.pop()]
    return a+ reverse(l)


l=[1,2,3,4,5,6,435,764,25,8965]

print(reverse(l))