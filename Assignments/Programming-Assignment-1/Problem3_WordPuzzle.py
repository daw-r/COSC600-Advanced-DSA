#!/usr/bin/env python3

"""
Filename: Problem3_Solution.py

Author: Devere Anthony Weaver

Assignment: Programming Assignment 1
Problem: Problem 3 - Word Puzzle Problem

Description: This program is a solution to the word puzzle problem. The program 
takes as input a file containing a 2D matrix of letters representing a 
crossword puzzle board and another file containing a 1D array of words to 
be searched for. 

The output is the 2D coordinate pair of the start and end of the first 
instance of each word in the list (had difficulty creating output of
a 2D array with only the word locations filled in).
"""

#import copy

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
    """
    Main driver of program
    """
    # set up the word puzzle board
    grid = Parse("puzzleinput.txt")

    # rows, cols = (7, 7)
    # arr = [['-']*cols]*rows
    # for line in arr:
    #     print(line)

    # create a list of words to look for in the puzzle based on the 
    # gives words file from the assignment
    words = []
    with open("wordlist.txt") as f:
    #with open("words.txt") as f:
        for line in f.readlines():
            words.append(line.strip())

    print(f"\nList of words to search for:\n{words}")

    print("\n\n\nNOTE: ALL INDEXING IS ZERO-BASED FOR THE FOLLOWING RESULTS.")

    # iterate over words list to find location of first intances of the words
    for word in words:
        word = word.upper()
        print(f"\n\nSEARCH TERM: {word}")
        if (Right(grid, word) or Left(grid, word) or 
            Down(grid, word) or Up(grid, word) or 
            RightUpDiag(grid, word) or LeftUpDiag(grid, word) or
            RightDownDiag(grid, word) or LeftDownDiag(grid,word)
            ):
                pass
        else:
            print(f"{word} not found.")
# end main()


def Right(grid, word):
    """
    Right(grid, word) - takes a word puzzle grid and searches for the give word
    in the direction to the right of the start of the searched word

    Input:
        1. grid - a 2D matrix containing words representing a word puzzle 
        2. word - the word to be searched for
    
    Output:
        1. True if word is found in the right direction 

        or

        2. False if word is not found in the right direction
    """
    found = []

    # find word
    for i in range(len(grid)):    # iterate over rows
        for j in range(len(grid)):    # iterate over columns
            if grid[i][j] == word[0]:    # check first letter
                test_word = ""
                found_row = i
                found_col = j
                if (j < 0) or (j + len(word) - 1 >= len(grid)):  # don't go outside of board to right
                    found.append("")
                else:
                    for h in range(len(word)):    # iterate over grid to 
                        test_word = test_word + (grid[i][j+h])   # build strings
                        if test_word == word:    # we've found the word
                            print(f"The first instance of the word '{word}'",end="")
                            print(f" was found starting at ({i},{j})", end="")
                            print(f" and \ngoing right ending at ({i},{j+h})")
                            return True
                    #found.append(test_word)

def Left(grid, word):
    """
    Left(grid, word) - takes a word puzzle grid and searches for the give word
    in the direction to the left of the start of the searched word

    Input:
        1. grid - a 2D matrix containing words representing a word puzzle 
        2. word - the word to be searched for
    
    Output:
        1. True if word is found in the left direction 

        or

        2. False if word is not found in the left direction
    """
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
                        if test_word == word:
                            print(f"The first instance of the word '{word}'",end="")
                            print(f" was found starting at ({i},{j})", end="")
                            print(f" and \ngoing left ending at ({i},{j-h})")
                            return True
    #             found.append(test_word)

def Down(grid, word):
    """
    Down(grid, word) - takes a word puzzle grid and searches for the give word
    in the direction below the start of the searched word

    Input:
        1. grid - a 2D matrix containing words representing a word puzzle 
        2. word - the word to be searched for
    
    Output:
        1. True if word is found in the down direction 

        or

        2. False if word is not found in the down direction
    """
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
                        if test_word == word:
                            print(f"The first instance of the word '{word}'",end="")
                            print(f" was found starting at ({i},{j})", end="")
                            print(f" and \ngoing down ending at ({i+h},{j})")
                            return True
    #                 found.append(test_word)

def Up(grid, word):
    """
    Up(grid, word) - takes a word puzzle grid and searches for the give word
    in the direction above the start of the searched word

    Input:
        1. grid - a 2D matrix containing words representing a word puzzle 
        2. word - the word to be searched for
    
    Output:
        1. True if word is found in the up direction 

        or

        2. False if word is not found in the up direction
    """
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
                        if test_word == word:
                            print(f"The first instance of the word '{word}'",end="")
                            print(f" was found starting at ({i},{j})", end="")
                            print(f" and \ngoing up ending at ({i-h},{j})")
                            return True
    #                 found.append(test_word)

def RightUpDiag(grid, word):
    """
    RightUpDiag(grid, word) - takes a word puzzle grid and searches for the give word
    in the direction diagonally to the upper right of the start of the searched word

    Input:
        1. grid - a 2D matrix containing words representing a word puzzle 
        2. word - the word to be searched for
    
    Output:
        1. True if word is found in the upper right diagonal direction 

        or

        2. False if word is not found in the upper right diagonal direction
    """
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
                        if test_word == word:
                            print(f"The first instance of the word '{word}'",end="")
                            print(f" was found starting at ({i},{j})", end="")
                            print(f" and \ngoing up diagonally to the right",end="")
                            print(f" ending at ({i-h},{j+h})")
                            return True
    #                 found.append(test_word)

def LeftUpDiag(grid, word):
    """
    LeftUpDiag(grid, word) - takes a word puzzle grid and searches for the give word
    in the direction diagonally to the upper left of the start of the searched word

    Input:
        1. grid - a 2D matrix containing words representing a word puzzle 
        2. word - the word to be searched for
    
    Output:
        1. True if word is found in the upper left diagonal direction 

        or

        2. False if word is not found in the upper left diagonal direction
    """
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
                        if test_word == word:
                            print(f"The first instance of the word '{word}'",end="")
                            print(f" was found starting at ({i},{j})", end="")
                            print(f" and \ngoing up diagonally to the left",end="")
                            print(f" ending at ({i-h},{j-h})")
                            return True
    #                    found.append(test_word)

def RightDownDiag(grid, word):
    """
    RightDownDiag(grid, word) - takes a word puzzle grid and searches for the give word
    in the direction diagonally to the lower right of the start of the searched word

    Input:
        1. grid - a 2D matrix containing words representing a word puzzle 
        2. word - the word to be searched for
    
    Output:
        1. True if word is found in the lower right diagonal direction 

        or

        2. False if word is not found in the lower right diagonal direction
    """
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
                        if test_word == word:
                            print(f"The first instance of the word '{word}'",end="")
                            print(f" was found starting at ({i},{j})", end="")
                            print(f" and \ngoing down diagonally to the right",end="")
                            print(f" ending at ({i+h},{j+h})")
                            return True
    #                 found.append(test_word)


def LeftDownDiag(grid, word):
    """
    LeftDownDiag(grid, word) - takes a word puzzle grid and searches for the give word
    in the direction diagonally to the upper right of the start of the searched word

    Input:
        1. grid - a 2D matrix containing words representing a word puzzle 
        2. word - the word to be searched for
    
    Output:
        1. True if word is found in the lower left diagonal direction 

        or

        2. False if word is not found in the lower left diagonal direction
    """
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
                        if test_word == word:
                            print(f"The first instance of the word '{word}'", end="")
                            print(f" was found starting at ({i},{j})", end="")
                            print(f" and \ngoing down diagonally to the left",end="")
                            print(f" ending at ({i + len(word) - 1},{j - len(word) + 1})")
                            return True
    #                    found.append(test_word)

main()    # invoke program