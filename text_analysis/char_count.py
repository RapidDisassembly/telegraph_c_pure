#This one-off script counts the number of latin letters, spaces, and arabic digits in the enwik9 file, then prints the probability of each to output.
#I manually copied this output to the "summary_enwik9" file, because it was easier than looking up how to write to a file

file = open("enwik9")
one_per_cent = 10000000

characters = [chr(l) for l in range(97,123)] + [' '] + [str(i) for i in range(10)]
occurences = [0 for c in characters]

i = 0
for line in file:
    for c in line:
        i += 1
        if c in characters:
            occurences[characters.index(c)] += 1
        if i%one_per_cent == 0:
            print("{}% complete".format(i//one_per_cent))

probabilities = [o/sum(occurences) for o in (occurences)]

for i in range(len(characters)):
    print("'{}',{}".format(characters[i],probabilities[i]))
