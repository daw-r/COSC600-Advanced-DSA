#!/usr/bin/env python3


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

main()