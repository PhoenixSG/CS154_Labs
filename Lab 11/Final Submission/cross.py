def cross(l1,l2):

    if(len(l1)==0):
        return []

    x=l1.pop()
    a=[(x,y) for y in l2]

    return a+cross(l1,l2)



l1=[0,1,2,3]
l2=[4,5,6,7]
#a=[(x,y) for x in l1 for y in l2]
a=cross(l1,l2)
print(a)
