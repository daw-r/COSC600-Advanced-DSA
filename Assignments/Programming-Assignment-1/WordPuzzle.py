#!/usr/bin/env python3

"""
TODO: Fill in docstring here
"""

import copy

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
    with open(filename) as f:
        for line in f.readlines():
            if line.strip():
                add = []
                line = line[:-1]  # drop newline
                for i in range(len(line)):
                    add.append(line[i])
            grid.append(add)
    return grid


def main():
    rows = 7
    cols = 7

    # set up the word puzzle board
    grid = Parse("textpuzzle.txt")
    print("The Word Puzzle Board:")
    for line in grid:
        print(f"{line}")

    # create an empty board with same dimensions as grid
    output_grid = copy.deepcopy(grid)
    for i in range(len(output_grid)):
        for j in range(len(output_grid)):
            output_grid[i][j] = "-"
    print("\n\nThe Output Board")
    for line in output_grid:
        print(f"{line}")
    print("\n\n")


    # create a list of words to look for in the puzzle
    # words = []
    # with open("words.txt") as f:
    #     for line in f.readlines():
    #         words.append(line.strip())
    # print(f"\nList of words to search for:\n{words}")

    word = "cave"
    #for word in words:
    # Find locations of first letter
    found_row = 0
    found_col = 0
    start_coordinates_list = []
    found = [] 
    # CheckRight(grid, word)
    # CheckLeft(grid, word)
    # CheckDown(grid, word)
    # CheckUp(grid, word)
    print(f"Right Up Diagonal:", end=""); RightUpDiag(grid, word)
    print(f"Left Up Diagonal:", end=""); LeftUpDiag(grid, word)
    print(f"Right Down Diagonal:", end=""); RightDownDiag(grid, word)
    print(f"Left Down Diagonal:", end=""); LeftDownDiag(grid, word)


def CheckRight(grid, word):
    found = []
    for i in range(len(grid)):    # iterate over rows
        for j in range(len(grid)):    # iterate over columns
            if grid[i][j] == word[0]:    # check first letter
                found_row = i
                found_col = j
                found_word = ""
                test_word = ""
                # check right
                if (j + len(word) >= len(grid)):  # don't go outside of board to right
                    found.append("")
                else:
                    for h in range(len(word)):    # iterate over grid to 
                        test_word = test_word + (grid[i][j+h])   # build strings
                    found.append(test_word)
    print(found)
    print(word in found)

def CheckLeft(grid, word):
    found = []
    for i in range(len(grid)):    # iterate over rows
        for j in range(len(grid)):    # iterate over columns
            if grid[i][j] == word[0]:    # check first letter
                found_row = i
                found_col = j
                found_word = ""
                test_word = ""
                # check right
                if j <= 0 or j - len(word) <= 0:     # don't go outside of board to left
                    found.append("")
                else:
                    for h in range(len(word)):    # iterate over grid to 
                        test_word = test_word + (grid[i][j-h])   # build strings
                    found.append(test_word)
    print(found)
    print(word in found)

def CheckDown(grid, word):
    found = []
    for i in range(len(grid)):    # iterate over rows
        for j in range(len(grid)):    # iterate over columns
            if grid[i][j] == word[0]:    # check first letter
                found_row = i
                found_col = j
                found_word = ""
                test_word = ""
                # check down
                if i + len(word) >=  len(grid): 
                    found.append("")
                else:
                    for h in range(len(word)):    # iterate over grid to 
                        test_word = test_word + (grid[i+h][j])   # build strings
                    found.append(test_word)
    print(found)
    print(word in found)

def CheckUp(grid, word):
    found = []
    for i in range(len(grid)):    # iterate over rows
        for j in range(len(grid)):    # iterate over columns
            if grid[i][j] == word[0]:    # check first letter
                found_row = i
                found_col = j
                found_word = ""
                test_word = ""
                # check down
                if i <= 0 or i - len(word) <= 0: 
                    found.append("")
                else:
                    for h in range(len(word)):    # iterate over grid to 
                        test_word = test_word + (grid[i-h][j])   # build strings
                    found.append(test_word)
    print(found)
    print(word in found)

def RightUpDiag(grid, word):
    found = []
    for i in range(len(grid)):    # iterate over rows
        for j in range(len(grid)):    # iterate over columns
            if grid[i][j] == word[0]:    # check first letter
                found_row = i
                found_col = j
                found_word = ""
                test_word = ""
                # check right
                if (j + len(word) >= len(grid)) or (i - len(word) <= 0):  # don't go outside of board to right
                    found.append("")
                else:
                    for h in range(len(word)):    # iterate over grid to 
                        test_word = test_word + (grid[i-h][j+h])   # build strings
                    found.append(test_word)
    print(found)
    print(word in found)

def LeftUpDiag(grid, word):
    found = []
    for i in range(len(grid)):    # iterate over rows
        for j in range(len(grid)):    # iterate over columns
            if grid[i][j] == word[0]:    # check first letter
                found_row = i
                found_col = j
                found_word = ""
                test_word = ""
                # check right
                if (i - len(word) <= 0 ) or (j - len(word) <= 0): 
                    found.append("") 
                else:
                    for h in range(len(word)):    # iterate over grid to 
                        test_word = test_word + (grid[i-h][j-h])   # build strings
                    found.append(test_word)
    print(found)
    print(word in found)

def RightDownDiag(grid, word):
    found = []
    for i in range(len(grid)):    # iterate over rows
        for j in range(len(grid)):    # iterate over columns
            if grid[i][j] == word[0]:    # check first letter
                found_row = i
                found_col = j
                found_word = ""
                test_word = ""
                # check right
                if (j + len(word) >= len(grid)) or (i + len(word) >= len(grid)):  # don't go outside of board to right
                    found.append("")
                else:
                    for h in range(len(word)):    # iterate over grid to 
                        test_word = test_word + (grid[i+h][j+h])   # build strings
                    found.append(test_word)
    print(found)
    print(word in found)

def LeftDownDiag(grid, word):
    found = []
    for i in range(len(grid)):    # iterate over rows
        for j in range(len(grid)):    # iterate over columns
            if grid[i][j] == word[0]:    # check first letter
                found_row = i
                found_col = j
                found_word = ""
                test_word = ""
                # check right
                if (j - len(word) >= len(grid)) or (i + len(word) >= len(grid)):  # don't go outside of board to right
                    found.append("")
                else:
                    for h in range(len(word)):    # iterate over grid to 
                        test_word = test_word + (grid[i+h][j-h])   # build strings
                    found.append(test_word)
    print(found)
    print(word in found)

main()
