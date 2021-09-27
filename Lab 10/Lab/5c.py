import sys

def length(l):
	if l == []:
		return 0
	else:
		return (1 + length(l[1:]))

def b_sort(a):
	if a == []:
		return []
	else:
		for x in range(0, length(a) - 1, 1):
			if(a[x] > a[x+1]):
				temp = a[x]
				a[x] = a[x+1]
				a[x+1] = temp 
		max = a[length(a)-1]
		a = b_sort(a[:-1])
		a.append(max)

		return a


def word_sorted_cntr(f, name):
	Dict = {};
	for x in f:
		y = x.split()
		for i in y:
			if i in Dict:
				Dict[i] += 1
			else:
				Dict[i] = 1

	count_list = []
	for x in Dict:
		count_list.append(str(Dict[x])+ " " + x)

	z = b_sort(count_list)

	g = open(name, 'w')

	for x in z:
		g.write(str(x) + '\n')



f = open(sys.argv[1])

word_sorted_cntr(f, "words_sorted"); 