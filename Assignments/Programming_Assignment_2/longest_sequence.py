#!/usr/bin/env python3
import random

# TODO: add code to generate a randomized matrix

# input matrix
matrix = [[97, 47, 56, 36], [35, 57, 41, 13], [89, 36, 98, 75], [25, 45, 26, 17]]

# print input matrix for user
print("Input matrix: ")
for i in range(4):
    for j in range(4):
        print(f"{matrix[i][j]} ", end="")
    print()

# compute longest increasing sequence
size = len(matrix)  # num elements in matrix
longest_sequence = []  # store the longest sequence in a Python list
stack = []  # utilize Python list as a stack datastructure instead of
# implementing an entire stack ADT

# iterate over matrix and create unique sequences with each
# element in the matrix
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
            for dx, dy in directions:  # change direction and go to element
                new_x, new_y = x + dx, y + dy

                # enforce matrix bounds
                if 0 <= new_x < size and 0 <= new_y < size:
                    new_number = matrix[new_x][new_y]

                    if (
                        new_number > last_number
                        and (new_number, (new_x, new_y)) not in sequence
                    ):
                        new_sequence = sequence + [(new_number, (new_x, new_y))]
                        stack.append(new_sequence)

print(longest_sequence)
