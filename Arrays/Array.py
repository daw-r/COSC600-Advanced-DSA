#!/usr/bin/env python3

"""
Illustration of a better Array class using Python lists.

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
        self.__nItems = 0    # keep track of Array size

    def __len__(self):
        """
        __len__ - special function that returns the length of 
        whatever is passed into it, for this implementation it 
        will return the value of nItems 
        """
        return self.__nItems
    
    def get(self, n):
        """
        get(self,n) - return the value at index n with bounds checking

        Input: 
            1. n - the index value 
        Return:
            1. The value at index n
        """
        if (0 <= n) and (n < self.__nItems):
            return self.__a[n]
        
    def set(self, n, value):
        """
        set(self, n, value) - sets the value at index n to the new value
        with bounds checking

        Input:
            1. n - the index to mutate
            2. value - the new value at index n
        Return: N/A
        """
        if (n <= 0) and (n < self.__nItems):
            self.__a[n] = value

    def insert(self, item):
        """

        insert() - inserts an item at the end of the array and 
        increments the array size
        Input:
            1. tem - an object to be placed into the array
        Return: N/A
        """
        self.__a[self.__nItems] = item    
        self.__nItems += 1
    
    def find(self, item):
        """
        find(self, item) - finds the index of the desired item

        Input:
            1. item - the intem to be searched for
        Return:
            1. the index of item OR -1 if the item isn't found
        """
        for i in range(self.__nItems):
            if self.__a[i] == item:
                return i
        return -1

    def search(self, item):
        """ 
        search(self, item) - searches the array for an item and returns it by 
        first searching for the item's index, and then using that return value 
        to find the item in the array 

        1. 
        """
        return self.get(self.find(item))
    
    def delete(self, item):
        """
        delete(self, item) - searches for item in the array and removes it

        Input:
            1. item - the object to be removed from the array
        Return:
            1. True if the object exsits or False if it doesn't exist

        Note: Does this create a hole in the array using this implementation?
        """
        for i in range(self.__nItems):
            if self.__a[i] == item:   # if found
                self.__nItems -= 1    # decrement array size 
                for k in range(i, self.__nItems):  # shift remaining values left
                    self.__a[k] = self.__a[k+1]
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
        for i in range(self.__nItems):
            function(self.__a[i])

    