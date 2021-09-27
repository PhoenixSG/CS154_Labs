def word_counter(f, name):
	Dict = {};
	for x in f:
		y = x.split()
		for i in y:
			if i in Dict:
				Dict[i] += 1
			else:
				Dict[i] = 1

	g = open(name, 'w')

	for x in Dict:
		g.write(x + ',' + str(Dict[x]) + '\n')


import sys

f = open(sys.argv[1])
word_counter(f, "words.csv"); 