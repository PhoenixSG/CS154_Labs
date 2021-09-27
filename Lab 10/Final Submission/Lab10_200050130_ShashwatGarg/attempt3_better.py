def word_counter_better(f):
	occurence = {};
	for x in f:
		y = re.split(',| |\.|"|\'|\(|\)|_|-|!|\n', x)
		for i in y:
			if i in occurence:
				occurence[i] += 1
			else:
				occurence[i] = 1

	for x in occurence:
		print(str(occurence[x])+" "+x)

import sys
import re
f = open(sys.argv[1])
word_counter_better(f)