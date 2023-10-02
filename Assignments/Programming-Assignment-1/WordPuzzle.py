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
    # set up the word puzzle board
    #grid = Parse("textpuzzle.txt")
    grid = Parse("puzzleinput.txt")
    print("The Word Puzzle Board:")
    for line in grid:
        print(f"{line}")

    # create an empty board with same dimensions as grid
    output_grid = copy.deepcopy(grid)
    print(output_grid)
    for i in range(len(output_grid)):
        for j in range(len(output_grid)):
            output_grid[i][j] = "-"
    print("\n\nThe Output Board")
    for line in output_grid:
        print(f"{line}")
    print("\n\n")


    # create a list of words to look for in the puzzle
    words = []
    with open("wordlist.txt") as f:
        for line in f.readlines():
            words.append(line.strip())
    print(f"\nList of words to search for:\n{words}")

    for word in words:
        word = word.upper()
        print(f"\n\nSEARCH TERM: {word}")
        if (
            CheckRight(grid, word) or CheckLeft(grid, word) or 
            CheckDown(grid, word) or CheckUp(grid, word) or 
            RightUpDiag(grid, word) or LeftUpDiag(grid, word) or
            RightDownDiag(grid, word) or LeftDownDiag(grid,word)
            ):
            print(f"{word} was found.")
        else:
            print(f"{word} not found.")
# end main()


def CheckRight(grid, word):
    found = []
    for i in range(len(grid)):    # iterate over rows
        for j in range(len(grid)):    # iterate over columns
            if grid[i][j] == word[0]:    # check first letter
                test_word = ""
                if (j < 0) or (j + len(word) - 1 >= len(grid)):  # don't go outside of board to right
                    found.append("")
                else:
                    for h in range(len(word)):    # iterate over grid to 
                        test_word = test_word + (grid[i][j+h])   # build strings
                    found.append(test_word)
    #print(found)
    #print(word in found)
    if (word in found):
        return True
    else:
        return False 

def CheckLeft(grid, word):
    found = []
    for i in range(len(grid)):    # iterate over rows
        for j in range(len(grid)):    # iterate over columns
            if grid[i][j] == word[0]:    # check first letter
                test_word = ""
                if j < 0 or j - len(word) + 1 < 0:     # don't go outside of board to left
                    found.append("")
                else:
                    for h in range(len(word)):    # iterate over grid to 
                        test_word = test_word + (grid[i][j-h])   # build strings
                found.append(test_word)
    # print(found)
    # print(word in found)
    if (word in found):
        return True
    else:
        return False 

def CheckDown(grid, word):
    found = []
    for i in range(len(grid)):    # iterate over rows
        for j in range(len(grid)):    # iterate over columns
            if grid[i][j] == word[0]:    # check first letter
                test_word = ""
                if i + len(word) - 1 >=  len(grid): 
                    found.append("")
                else:
                    for h in range(len(word)):    # iterate over grid to 
                        test_word = test_word + (grid[i+h][j])   # build strings
                    found.append(test_word)
    # print(found)
    # print(word in found)
    if (word in found):
        return True
    else:
        return False 

def CheckUp(grid, word):
    found = []
    for i in range(len(grid)):    # iterate over rows
        for j in range(len(grid)):    # iterate over columns
            if grid[i][j] == word[0]:    # check first letter
                test_word = ""
                if i < 0 or i - len(word) + 1 < 0: 
                    found.append("")
                else:
                    for h in range(len(word)):    # iterate over grid to 
                        test_word = test_word + (grid[i-h][j])   # build strings
                    found.append(test_word)
    # print(found)
    # print(word in found)
    if (word in found):
        return True
    else:
        return False 

def RightUpDiag(grid, word):
    found = []
    for i in range(len(grid)):    # iterate over rows
        for j in range(len(grid)):    # iterate over columns
            if grid[i][j] == word[0]:    # check first letter
                test_word = ""
                if (j + len(word) >= len(grid)) or (i - len(word) + 1 < 0):  # don't go outside of board to right
                    found.append("")
                else:
                    for h in range(len(word)):    # iterate over grid to 
                        test_word = test_word + (grid[i-h][j+h])   # build strings
                    found.append(test_word)
    # print(found)
    # print(word in found)
    if (word in found):
        return True
    else:
        return False 

def LeftUpDiag(grid, word):
    found = []
    for i in range(len(grid)):    # iterate over rows
        for j in range(len(grid)):    # iterate over columns
            if grid[i][j] == word[0]:    # check first letter
                test_word = ""
                if (i - len(word) <= 0 ) or (j - len(word) <= 0): 
                    found.append("") 
                else:
                    for h in range(len(word)):    # iterate over grid to 
                        test_word = test_word + (grid[i-h][j-h])   # build strings
                    found.append(test_word)
    # print(found)
    # print(word in found)
    if (word in found):
        return True
    else:
        return False 


def RightDownDiag(grid, word):
    found = []
    for i in range(len(grid)):    # iterate over rows
        for j in range(len(grid)):    # iterate over columns
            if grid[i][j] == word[0]:    # check first letter
                test_word = ""
                if (j + len(word) -1  >= len(grid)) or (i + len(word) - 1 >= len(grid)):  # don't go outside of board to right
                    found.append("")
                else:
                    for h in range(len(word)):    # iterate over grid to 
                        test_word = test_word + (grid[i+h][j+h])   # build strings
                    found.append(test_word)
    # print(found)
    # print(word in found)
    if (word in found):
        return True
    else:
        return False 


def LeftDownDiag(grid, word):
    found = []
    for i in range(len(grid)):    # iterate over rows
        for j in range(len(grid)):    # iterate over columns
            if grid[i][j] == word[0]:    # check first letter
                test_word = ""
                if (j - len(word) >= len(grid)) or (i + len(word) >= len(grid)):  # don't go outside of board to right
                    found.append("")
                else:
                    for h in range(len(word)):    # iterate over grid to 
                        test_word = test_word + (grid[i+h][j-h])   # build strings
                    found.append(test_word)
     # print(found)
    # print(word in found)
    if (word in found):
        return True
    else:
        return False 

main()