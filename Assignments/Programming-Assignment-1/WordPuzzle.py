#!/usr/bin/env python3

"""
TODO: Fill in docstring here
"""

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
            if line.strip():
                line = line[:-1]   # get rid of newline
                grid.append(line)
                cols += len(line)
                rows += 1
        cols = int(cols / rows)
    return grid, rows, cols

    return grid

def main():
    grid, rows, cols = Parse("puzzleinput.txt")
    
    # check grid was read correctly
    for line in grid:
        print(f"{line}")
    print(f"Number of rows: {rows}")
    print(f"Number of columns: {cols}")

            

main()