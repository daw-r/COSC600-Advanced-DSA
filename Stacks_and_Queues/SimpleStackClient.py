#!/usr/bin/env python3

from SimpleStack import *

# create a Stack with a maximum capacity of 10 
stack = Stack(10)

# push a list of words onto the stack
for word in [ 'May', 'the', 'force', 'be', 'with', 'you']:
    stack.push(word)

print(f"After pushing {len(stack)} words on the stack, it contains: {stack}")

print(f"Is the stack full? {stack.isFull()}")

# demonstrate order in which items are popped from the stack
print("Popping items off the stack:")
while not stack.isEmpty():
    print(stack.pop(), end = ' ')
print()