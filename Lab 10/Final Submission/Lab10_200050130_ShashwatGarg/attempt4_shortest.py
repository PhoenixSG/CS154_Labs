import sys
occurence = {};
for x in open(sys.argv[1]):
    for i in x.split():
        if i in occurence:
            occurence[i] += 1
        else:
            occurence[i] = 1
for x in occurence:
    print(str(occurence[x])+" "+x)