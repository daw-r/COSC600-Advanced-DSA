#!/usr/bin/env python3 

"""
Heap.py - definition for the core Heap ADT
"""

def identity(x):
    """
    Function which defines the function to extract the 
    key used in ordering records or other structures
    ...not entirely sure I see the usefulness of this guy yet
    """
    return x    

class Heap(object):
    def __init__(self, key=identity, size=2):
        self._array = [None] * size
        self._numItems = 0
        self._key = key

    def isEmpty(self): return self._numItems == 0

    def isFull(self): return self._numItems == len(self._array)

    def __len__(self): return self._numItems

    def peek(self):
        return None if self.isEmpty() else self._arr[0]