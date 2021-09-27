def perm(l):
    if len(l) == 0:
        return []

    if len(l) == 1:
        return [l]

    ans=[]

    for i in range(len(l)):
        l2= l.copy()
        m = l2.pop(i)

        for j in perm(l2):
            ans.append([m]+ j)
    return ans



l=[1,2,3,4]

print(perm(l))