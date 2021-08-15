from csv import reader
from csv import DictReader
from sys import argv

###########################################

# need 3 arguments so the filename, csv file and txt file
if len(argv) != 3:
    print("Usage: python dna.py database.csv sequence.txt")
    exit(1)

    #sequence = []
#filename = sys.argv[1]
# read the csv file
with open(argv[1]) as person_list:
    people = reader(person_list)
    # cycle through row values
    for row in people:
        # identify the letters(basepairs)
        amino_acids = row
        # makes it easier if i get rid of first value
        amino_acids.pop(0)
        break

# read txt file
with open(argv[2]) as file:
    file_reader = reader(file)
    # cycle through row values
    for row in file_reader:
        # identify dna
        dna = row

# store the string, followed by make a blank dict
sequence = dna[0]
sequences = dict()

# put this list into a dict (from line 22)
for i in amino_acids:
    sequences[i] = 1

# cycle through the amino acids and if theres a
# match with the sequence, add 1 to the counter
# sc means short chain
for STR in sequences:
    # the short chain in equal to the STR length
    sc = len(STR)
    counter = 0
    long_counter = 0
    # if it counts a sc, this is to stop counting more than once
    for letters in range(len(sequence)):
        while counter >= 1:
            counter -= 1
            continue

        # if that amino acid segment matchs the str, thats where oyu add 1
        if sequence[letters: letters + sc] == STR:
            while sequence[letters - sc: letters] == sequence[letters: letters + sc]:
                counter += 1
                letters += sc
            # takes the previous longest consecutive chain length and replaces with the new longest
            if counter >= long_counter:
                long_counter = counter

    sequences[STR] += long_counter

# FINALLY....compute the matchs (if there is one)
with open(argv[1]) as person_list:

    people = DictReader(person_list)

    for member in people:
        matchs = 0

        for sequence in sequences:
            if sequences[sequence] == int(member[sequence]):
                matchs += 1

        if matchs == len(sequences):
            print(member['name'])
            exit()

    print("No match")
