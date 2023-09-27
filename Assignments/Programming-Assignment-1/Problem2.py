#!/usr/bin/env python3
"""
Name: Devere Anthony Weaver

Assignment: Programming Assignment 1
Problem: Problem 2 - Recursive Binary Algorithm

Description: Problem2.py illustrates a function decimalToBinary() that taks as
input a positive decimal number and prints out the decimal representation of the
number to standard output. 

E.g. If input is 57 then 111001 would be output to stdout.

"""

def decimalToBinary(dec):
  """
  Returns value of given decimal argument to its binary equivalent via a
  recursive algorithm call.

  Arguments:
    1. dec - decimal number to be converted to a binary number

  Return: N/A
  """
  if ((dec / 2) == 0):
    pass
  elif ((dec % 2) == 0):    # even
    dec = dec // 2
    decimalToBinary(dec)
    print("0", end="")
  elif((dec % 2) != 0):   # odd:
    dec = dec // 2
    decimalToBinary(dec)
    print("1", end="")

def main():
  """
  Main driver
  """
  number = int(input("Enter a positive decimal number: "))
  print(f"The binary number is: ", end="")
  decimalToBinary(number)
  print()

main()    # invoke program