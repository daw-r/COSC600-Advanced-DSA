#!/usr/bin/env python3

"""
Illustration of a poor Array class using Python lists.

The most common operations for arrays include:
    - insert
    - search
    - delete
    - traverse
"""

class Array(object):
    """
    Array class is an implementation of a poorly thought out array.
    """

    def __init__(self, initialSize):
        """
        Array constructor with two memembers
        """
        self.__a = [None] * initialSize   # allocate empty array
        self.nItems = 0    # keep track of Array size

    def insert(self, item):
        """

        insert() - inserts an item at the end of the array and 
        increments the array size
        Input:
            1. tem - an object to be placed into the array
        Return: N/A
        """
        self.__a[self.nItems] = item    
        self.nItems += 1
    
    def search(self, item):
        """
        search(self, item) - searches the Array instance for item a

        Input: 
            1. item - object to be searched for in the array 
        Return:
            1. the object if found OR None if the object is not found
        """
        for i in range(self.nItems):
            if self.__a[i] == item:
                return self.__a[i]
    
    def delete(self, item):
        """
        delete(self, item) - searches for item in the array and removes it

        Input:
            1. item - the object to be removed from the array
        Return:
            1. True if the object exsits or False if it doesn't exist

        Note: Does this create a hole in the array using this implementation?
        """
        for i in range(self.nItems):

            if self.__a[i] == item:
                for k in range(i, self.nItems): 
                    # shift all objects from index onward to the right
                    self.__a[k] = self.__a[k+1]
                self.nItems -= 1 
                return True
        return False

    def traverse(self, function=print):
        """
        traverse(self, function) - traverses the entire array and invokes a
        given function object on each element in the array
        
        Input: 
            1. function - some function object to invoke on the element of 
            the array, print() is the default 
        Return: N/A
        """
        for i in range(self.nItems):
            function(self.__a[i])

    