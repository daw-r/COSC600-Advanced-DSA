#!/usr/bin/env python3

"""
TODO: Fill in docstring here
"""

from typing import List


def Parse(filename):
    """
    Parse(filename) - parses a given 2D-array character file as input and places
    it into 2D Python list.

    Input: 
        1. filename - name of the given file to parse
    
    Return:
        1. grid - a 2D array containing the characters in filename
    """
    grid = []
    rows = 0
    cols = 0
    with open("puzzleinput.txt") as f:
        for line in f.readlines():
            line = line.strip()   # drop whitespace 
            line = line[:-1]    # drop newline
            for i in range(len(line)):
                grid.append(line[i])
    return grid


def main():
    grid = Parse("puzzleinput.txt")
    
    # check grid was read correctly
    for i in range(len(grid)):
        print(f"Index {i}: {grid[i]}")

main()