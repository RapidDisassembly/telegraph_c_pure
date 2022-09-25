#This one off script takes the summary_enwik9 file and approximates how often a morse telegraph signal will be on or off.

from collections import Counter

morse_file_name = 'morse'
summary_file_name = 'summary_enwik9'

#
def morse_to_bin(input_str):
    output_str = ""
    if input_str == '/': #space between words is four more than the space between characters
        return "0000"
    for c in input_str:
        if c == '.':
            r = "10"
        if c == '-':
            r = "1110"
        output_str += r
    output_str += "00" #space between characters is two more than the space between two parts of the same character
    return output_str

#get the morse code for each character
morse_dict = {}
with open(morse_file_name) as morse_file:
    for line in morse_file:
        a,b = line.split(',')
        morse_dict[a] = b.replace('\n','')

#get the probability of each character
proba_dict = {}
with open(summary_file_name) as proba_file:
    for line in proba_file:
        a,b = line.split(',')
        proba_dict[a] = float(b.replace('\n',''))

#find the telegraph signal for each character
bin_dict = {}
for key in morse_dict:
    bin_dict[key] = morse_to_bin(morse_dict[key])

#find the proportions of off-time/on-time for the telegraph signal of each character
fraction_dict = {}
for key in bin_dict:
    co = Counter(bin_dict[key])
    count_0 = co['0']/len(bin_dict[key])
    count_1 = co['1']/len(bin_dict[key])
    fraction_dict[key] = (count_0,count_1)

#sum over the telegraph signals for all characters, weighted by character probability
p_0 = 0; p_1 = 0
for key in fraction_dict:
    p_0 += proba_dict[key]*fraction_dict[key][0]
    p_1 += proba_dict[key]*fraction_dict[key][1]

print("probability of 0 is: {}".format(p_0/(p_0 + p_1)))
print("probability of 1 is: {}".format(p_1/(p_0 + p_1)))
#find that it's about 60% off, 40% on
