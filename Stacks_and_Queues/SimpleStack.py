#!/usr/bin/env python3

"""
Implementation of a basic stack data structure usingn a Python list
"""


class Stack(object):
    def __init__(self, max):
        self.__stackList = [None] * max  # list implementation
        self.__top = -1  # point to top most item in stack

    def push(self, item):  
        """
        Insert a new item onto the stack, client should use IsFull() 
        before calling push()
        """
        self.__top += 1  # increment stack pointer
        self.__stackList[self.__top] = item  # place new item on top of stack

    def pop(self):  
        """
        Remove top item from off the stack, client should use IsEmpty()
        before calling pop()
        """
        top = self.__stackList[self.__top]  # set top to last item via index
        self.__stackList[self.__top] == None  # remove item reference
        self.__top -= 1  # decrement stack pointer
        return top  # return the removed item

    def peek(self):
        """
        Return top item from stack, don't pop
        """
        if not self.isEmpty():  # empty stack causes errors
            return self.__stackList[self.__top]

    def isEmpty(self):
        """
        Check if stack is empty
        """
        return self.__top < 0

    def isFull(self):
        """
        Check if stack is full
        """
        return self.__top >= len(self.__stackList) - 1

    def __len__(self):
        """
        Return total number of objects on the stack
        """
        return self.__top + 1  # number of indexes plus 1

    def __str__(self):
        """
        Convert the stack into a formatted string
        """
        ans = "["
        for i in range(self.__top + 1):  # iterate over all items in stack
            if len(ans) > 1:  # add remaing itmes to string
                ans += ", "
            ans += str(self.__stackList[i])  # add first item to string
        ans += "]"
        return ans
