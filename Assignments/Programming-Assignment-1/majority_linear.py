#!/usr/bin/env python3

"""
Filename: majority_linear.py

Author: Devere Anthony Weaver

Assignment: Programming Assignment 1, Problem 4

Purpose: This program is an implementation of the Majority Element algorithm
using the linear implementation and also illustrates the runtime in seconds.

"""

def Open(filename):
    """
    Open(filename) - opens and parses the given filename containing integer
    values into a single integer array for further processing.

    Input:
         1. filename - the name of the desired file to open as a string value

     Return:
         1.  nums - an integer array with the values from filename
    """
    nums = []
    with open(filename) as f:
        for line in f.readlines():
            line = line.split()
            for i in range(len(line)):
                nums.append(int(line[i]))
        return nums


def FrequencyCount(list, key):
    """
    FrequencyCount(list, key) - iterates over a collection to
    search for instances of key in the collection.

    Input:
        1. list - the collection containing the integer values to be searched
        2. key - item to be counted in a given list

    Return:
        1. count - the number of occurences of key in list
    """
    count = 0
    for i in range(len(list)):
        if list[i] == key:
            count = count + 1
    return count


def MajorityElementLinear(list):
    """
    MajorityElementLinear(list) - linear time implementation of majority
    element algorithm; it determins the most occuring element and checks if it is
    the majority element.

    Input:
      1. list - a list of values to be searched

    Output: N/A
    """
    frequencies = {}
    unique = []

    # iterate over list to get unique elements
    for i in list:
        if i not in unique:
            unique.append(i)

    # use unique elements as dictionary keys
    for i in unique:
        frequencies[i] = FrequencyCount(list, i)

    # figure out how to return the max value of this dictionary
    most_occurring = max(zip(frequencies.values(), frequencies.keys()))[1]
    print(f"Most occurring element: {most_occurring}")

    # check if it is a majority element in the given list
    if frequencies[most_occurring] > (len(list) / 2):
        print(f"{most_occurring} is the majority element.")
    else:
        print("There is no majority element.")


def main():
    """
    Main driver
    """
    import time

    majex1 = Open("Majex1.txt")
    majex2 = Open("Majex2.txt")
    majex3 = Open("Majex3.txt")
    majex4 = Open("Majex4.txt")

    print("Filename: Majex1.txt")
    start = time.time()
    MajorityElementLinear(majex1)
    runtime = time.time() - start
    print(f"Runtime: {runtime:.4f} seconds")

    print("\nFilename: Majex2.txt")
    start = time.time()
    MajorityElementLinear(majex2)
    runtime = time.time() - start
    print(f"Runtime: {runtime:.4f} seconds")

    print("\nFilename: Majex3.txt")
    start = time.time()
    MajorityElementLinear(majex3)
    runtime = time.time() - start
    print(f"Runtime: {runtime:.4f} seconds")

    print("\nFilename: Majex4.txt")
    start = time.time()
    MajorityElementLinear(majex4)
    runtime = time.time() - start
    print(f"Runtime: {runtime:.4f} seconds")


main()
