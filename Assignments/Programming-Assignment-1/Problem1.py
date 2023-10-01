#!/usr/bin/env python3

"""
Name: Devere Anthony Weaver

Assignment: Programming Assignment 1
Problem: Problem 1 - Guessing Game

Description: TODO
"""
import random


def BinarySearch(array, key):
    """

    Implementation of the binary search algorithm. The function
    takes an array-like structure and searches for the given key. This
    implementation of binary search returns the index of the search key,
    the value of the key once found, and the total number of guess until
    the key was found.

    Input:
      1. array - an array values to be searched
      2. key - the particular value to be searched for in array

    Return:
      1. packed tuple containing:
        * the key's index if found or -1 if the key is not found
        * value - the value of the key itself
        * the number of iterations (guesses) until the key was found

    """
    low = 1
    high = len(array) - 1
    num_guesses = 0

    while low <= high:
        num_guesses += 1
        middle = (low + high) // 2
        if array[middle] < key:  # shift left
            print(f"The number is higher than {middle}.")
            low = middle + 1
        elif array[middle] > key:  # shift right
            print(f"The number is lower than {middle}.")
            high = middle - 1
        elif array[middle] == key:
            print(f"\nThe number is found. It is {middle + 1}")
            print(f"The total number of guesses is: {num_guesses}.")
            return middle, middle + 1, num_guesses

    return -1


def main():
    arr = range(1, 1000001)
    guess = []

    # execute the "game" 100 times and store the number of guesses
    for i in range(1, 101):
        r = random.randint(1, 1000000)
        print(f"Guess {i}")
        index, value, num_guesses = BinarySearch(arr, r)  # index, value go unused
        guess.append(num_guesses)
        print()

    # verify the number of guesses and compute average number over 100 iterations
    print(f"\nNumber of guesses: {len(guess)}")
    print(f"Average number of guesses: {sum(guess) / len(guess)}")


main()  # invoke program
