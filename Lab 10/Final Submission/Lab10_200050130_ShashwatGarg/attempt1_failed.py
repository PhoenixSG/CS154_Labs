def word_count_failed(f):
	occurence_count = {};
	for i in f:
		if i in occurence_count:
				occurence_count[i] += 1
		else:
				occurence_count[i] = 1

	for x in occurence_count:
		print(str(occurence_count[x])+" "+x)


import sys

f = open(sys.argv[1])
word_count_failed(f)