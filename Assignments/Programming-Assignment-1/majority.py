#!/usr/bin/env python3
"""
Filename: majority.py

Author: Devere Anthony Weaver 

Assignment: Programming Assignment 1, Problem 4

Purpose: This program is an implementation of the Majority Element algorithm
using the recursive implementation and also illustrates the runtime in seconds.

"""

def FrequencyCount(list, left, right, key):
    """
    FrequencyCount(list, left, right, key) - iterates over a collection to
    search for instances of key in the collection. 

    Input:
        1. list - the collection containing the integer values to be searched
        2. left - the left bound of the list (changes with recursive calls)
        3. right - the right bound of the list (changes with recursive calls) 
    
    Return:
        1. count - the number of occurences of key in list
    """
    count = 0
    for i in range(left, right + 1):
        if list[i] == key:
            count = count + 1
    return count

def MajorityElement(list, left, right):
    """
    MajorityElement(list, left, right) - implementation of a recursive algorithm
    to compute the majority element of a given list (or other collection) of
    integers. 

    Input: 
        1. list - the collection containing the integer values to be searched
        2. left - the left bound of the list (changes with recursive calls)
        3. right - the right bound of the list (changes with recursive calls)

    Return:
        1. leftMajority / rightMajority - the majority element in list
        
        or

        2. (-1) - if there is no majority element in the list
    """
    if left == right:    # Base Case: single element array
        return list[left]

    # DIVIDE
    mid = left + (right - left) // 2 
    leftMajority = MajorityElement(list, left, mid)
    rightMajority = MajorityElement(list, mid + 1, right)

    # CONQUER
    if leftMajority == rightMajority:
        return leftMajority

    leftCount = FrequencyCount(list, left, right, leftMajority)
    rightCount = FrequencyCount(list, left, right, rightMajority)

    # COMBINE
    if leftCount > (right - left + 1) // 2:
        return leftMajority
    elif rightCount > (right - left + 1) // 2:
        return rightMajority
    else:
        return -1  # No majority element in this subarray

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

def main():
    """
    Main driver of program
    """

    # Open and parse all 4 Majex files in sequence and store values in a 
    # Python list
    majex1 = Open("Majex1.txt")
    majex2 = Open("Majex2.txt")
    majex3 = Open("Majex3.txt")
    majex4 = Open("Majex4.txt")

    # Majex 1
    print("Filename: Majex1.txt")
    print(f"Number of elements in list: {len(majex1)}")
    majority = MajorityElement(majex1, 0, len(majex1) - 1)
    if majority == -1:
        print("There is no majority element.")
    else:
        print(f"Majority element: {majority}.")

    # Majex 2
    print("\n\nFilename: Majex2.txt")
    print(f"Number of elements in list: {len(majex2)}")
    majority = MajorityElement(majex2, 0, len(majex2) - 1)
    if majority == -1:
        print("There is no majority element.")
    else:
        print(f"Majority element: {majority}.")

    # Majex 3
    print("\n\nFilename: Majex3.txt")
    print(f"Number of elements in list: {len(majex3)}")
    majority = MajorityElement(majex3, 0, len(majex3) - 1)
    if majority == -1:
        print("There is no majority element.")
    else:
        print(f"Majority element: {majority}.")

    # Majex 4 
    print("\n\nFilename: Majex4.txt")
    print(f"Number of elements in list: {len(majex4)}")
    majority = MajorityElement(majex4, 0, len(majex4) - 1)
    if majority == -1:
        print("There is no majority element.")
    else:
        print(f"Majority element: {majority}.")

# invoke main driver
main()