def word_counter_normal(f):
	occurence = {};
	for x in f:
		for i in x.split():
			if i in occurence:
				occurence[i] += 1
			else:
				occurence[i] = 1

	for x in occurence:
		print(str(occurence[x])+" "+x)

import sys
f = open(sys.argv[1])
word_counter_normal(f)