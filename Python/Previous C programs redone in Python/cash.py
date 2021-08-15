from cs50 import get_float
change = 0
# ask for change amount, if less than zero, kick back question
while (change <= 0):
    change = get_float("Change:")
# convert to cents
cents = change * 100
# cycle through coin types, adding to to the coin counter, with every iteration
coin_counter = 0
while cents > 0:
    if cents >= 25:
        cents -= 25
        coin_counter += 1
    elif cents >= 10:
        cents -= 10
        coin_counter += 1
    elif cents >= 5:
        cents -= 5
        coin_counter += 1
    elif cents >= 1:
        cents -= 1
        coin_counter += 1
        
print(f"{coin_counter}")