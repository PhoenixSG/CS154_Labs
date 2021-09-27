def sub(l1,l2):
    if len(l1)>len(l2):
        return []
    if len(l1)==len(l2):
        if(l1==l2):
            return l1 
        else:
            return []

    return sub(l1,l2[1:]) or sub(l1,l2[:-1])

testl1=[3,4,5,6]
testl2=[764,25]
testl3=[1,5,6]
testl4=[46635,5742]
l2=[1,2,3,4,5,6,435,764,25,8965]

print(sub(testl1,l2))
print(sub(testl2,l2))
print(sub(testl3,l2))
print(sub(testl4,l2))

#empty list indicates not a substring, the false case