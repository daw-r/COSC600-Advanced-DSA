#!/usr/bin/env python3

# Method 1: O(N log N)
def GetMajorityElement(arr):
    """
    TODO: Fill in docstring
    """
    if (len(arr) == 1):
        return arr[0];    # possible issues
    k = int(len(arr)/ 2) 
    left_element= GetMajorityElement(arr[:k])
    right_element = GetMajorityElement(arr[k:])
    if left_element == right_element:
        return left_element
    # These need to search the entirety of the array
    left_count = GetFrequency(arr, left_element)
    right_count = GetFrequency(arr, right_element)
    if left_count > (k + 1):
        return left_element
    elif right_count > (k + 1):
        return right_element
    else:
        return -1    # come up with better return than this

def GetFrequency(arr, key):
    """
    TODO: Fill in docstring
    """
    count = 0
    for i in range(len(arr)):
        if arr[i] == key:
            count += 1
    return count

def main():
    arr = [5,5,5,2,5,2,5,5]
    majority = GetMajorityElement(arr)
    print(f"{majority}")
    #  if (majority == None):
    #      print("No majority element")
    #  else:
    #      print(f"Majority element: {majority}")
    
main()