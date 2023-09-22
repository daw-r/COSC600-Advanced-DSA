#!/usr/bin/env python3

import random

def BinarySearch(array, key):
  """Implementation of the binary search algorithm. The function
  takes an array-like structure and searches for the given key. This
  implementation of binary search returns the index of the search key,
  the value of the key once found, and the total number of guess until
  the key was found."""
  low = 1
  high = len(array) - 1
  num_guesses = 0

  while(low <= high):
    num_guesses += 1
    middle = (low + high) // 2
    if (array[middle] < key):    # shift left
      print(f"The number is higher than {middle}.")
      low = middle + 1
    elif (array[middle] > key):    # shift right
      print(f"The number is lower than {middle}.")
      high = middle - 1
    elif (array[middle] == key):
      print(f"\nThe number is found. It is {middle + 1}")
      print(f"The total number of guesses is: {num_guesses}.")
      return middle, middle+1, num_guesses

  return -1


# use this random number as the key and have the search the range (1,100000)?
arr = range(1,1000001)
guess = []

# execute the "game" 100 times and store the number of guesses 
for i in range(1,101):
  r = random.randint(1,1000000)
  print(f"Guess {i}")
  index, value, num_guesses = BinarySearch(arr, r)
  guess.append(num_guesses)
  print()

# verify the number of guesses and compute average number over 100 iterations
print(f"\nNumber of guesses: {len(guess)}")
print(f"Average number of guesses: {sum(guess) / len(guess)}")