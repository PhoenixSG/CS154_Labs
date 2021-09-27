def word_counter_better(f):
	occurence = {};
	for x in f:
		#print(x)
		y = re.split(',|.| |_|-|!|\n', x)
		#print(y)
		for i in y:
			if i in occurence:
				occurence[i] += 1
			else:
				occurence[i] = 1

	for x in occurence:
		print(x + ' ' + str(occurence[x]))

def word_counter_normal(f):
	occurence = {};
	for x in f:
		for i in x.split():
			if i in occurence:
				occurence[i] += 1
			else:
				occurence[i] = 1

	for x in occurence:
		print(x + ' ' + str(occurence[x]))


import sys
import re

f = open(sys.argv[1])
#word_count_failed(f)
#word_counter_normal(f)
word_counter_better(f)

