from cs50 import get_int
# asks for a height and keeps asking if it isnt between 1 and 8
height = 0
while (height <= 0 or height > 8):
    height = get_int("Height:")
    
# outlines range
# prints spaces on row 1, then blocks
# repeats until hits the height number
for i in range(1, height + 1):
    print(" " * (height - i), end="")
    print("#" * (i))