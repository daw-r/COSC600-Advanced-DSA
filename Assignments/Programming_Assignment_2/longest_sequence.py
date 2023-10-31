#!/usr/bin/env python3

"""
Filename: longest_sequence.py

Author: Devere Anthony Weaver 

Assignment: Programming Assignment 2
Problem: Problem 3 - Longest Increasing Sequence Problem

Description: This program generates a random NxN integer matrix 
and attempts to find the longest increasing sequence in the matrix. 
It does so by iterating over the matrix elements, traversing multiple
directions and comparing their length the current longest increasing 
sequence. A stack data structure is used to store the state of the 
sequences. 

"""
import random
import time

# use list comprehension to build a randomized integer matrix
print("Build an NxN matrix:")
n = int(input("Enter a value for N: "))
matrix = [[random.randint(0, 1000) for _ in range(n)] for _ in range(n)]

# print input matrix for user
print("\nInput matrix: ")
for i in range(n):
    for j in range(n):
        print(f"{matrix[i][j]:=5} ", end="")
    print()

# variable needed to compute longest sequence
size = len(matrix)  # num elements in matrix
longest_sequence = []  # store the longest sequence in a Python list
stack = []  # utilize Python list as a stack datastructure instead of
            # implementing an entire stack ADT

# iterate over matrix and create unique sequences with each
# element in the matrix
start = time.time()   # keep track of execution time in seconds
for i in range(size):
    for j in range(size):
        # get current value and position, then add to stack
        current_sequence = [(matrix[i][j], (i, j))]
        stack.append(current_sequence)  # equivalent to push operation

        # iterate over the stack to build and compare sequences
        while stack:  # while stack not empty
            sequence = stack.pop()  # remove top element
            last_number, (x, y) = sequence[-1]  # add to next in sequence
            if len(sequence) > len(longest_sequence):
                longest_sequence = sequence

            # compare last value in sequence to all previous sequence
            # members to test if the sequence is increasing and if the
            # value isn't already in the sequence
            directions = [
                (0, 1),
                (1, 0),
                (0, -1),
                (-1, 0),
                (1, 1),
                (-1, -1),
                (1, -1),
                (-1, 1),
            ]
            for move_x, move_y in directions:  # change direction and go to element
                new_x, new_y = x + move_x, y + move_y

                # enforce matrix bounds
                if 0 <= new_x < size and 0 <= new_y < size:
                    new_number = matrix[new_x][new_y]

                    if (
                        new_number > last_number
                        and (new_number, (new_x, new_y)) not in sequence
                    ):
                        new_sequence = sequence + [(new_number, (new_x, new_y))]
                        stack.append(new_sequence)
runtime = time.time() - start
print(f"\nThe longest sequence contains: {len(longest_sequence)} elements.")
print("Longest sequence order (value, ordinates):")
for element in longest_sequence:
    print(element)
print(f"\nAlgorithm runtime (in seconds): {runtime:.4f}s")
