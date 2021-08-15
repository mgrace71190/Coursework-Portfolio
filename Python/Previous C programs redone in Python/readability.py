from cs50 import get_string
# prompts the user for a test paragraph
text = get_string("Text: ")

letter_counter = 0
rand_counter = 0
word_counter = 1
sentence_counter = 0
for i in text:
    rand_counter += 1

    # print(rand_counter)
# letter counter here
for i in range(rand_counter):
    if text[i] >= "A" and text[i] <= "z":
        letter_counter += 1
        # print(letter_counter)
# word counter here
    elif text[i] == " ":
        word_counter += 1
        # print(word_counter)
# sentence counter here
    elif text[i] == "." or text[i] == "?" or text[i] == "!":
        sentence_counter += 1
        # print(sentence_counter)

# put all together to use the formula
# 0.0588 * L - 0.296 * S - 15.8

L = letter_counter * 100 / word_counter
S = sentence_counter * 100 / word_counter

index = round(0.0588 * L - 0.296 * S - 15.8)

if index < 1:
    print("Before Grade 1")
    
elif index >= 16:
    print("Grade 16+")
    
else:
    print(f"Grade {index}")
