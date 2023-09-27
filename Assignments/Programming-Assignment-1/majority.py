#!/usr/bin/env python3

def countFrequency(X, l, r, value):
    count = 0
    for i in range(l, r + 1):
        if X[i] == value:
            count = count + 1
    return count

def findMajorityElement(X, l, r):
    if l == r:
        return X[l]

    mid = l + (r - l) // 2
    leftMajority = findMajorityElement(X, l, mid)
    rightMajority = findMajorityElement(X, mid + 1, r)

    if leftMajority == rightMajority:
        return leftMajority

    leftCount = countFrequency(X, l, r, leftMajority)
    rightCount = countFrequency(X, l, r, rightMajority)

    if leftCount > (r - l + 1) // 2:
        return leftMajority
    elif rightCount > (r - l + 1) // 2:
        return rightMajority
    else:
        return -1  # No majority element in this subarray

def majorityElement(X):
    n = len(X)
    return findMajorityElement(X, 0, n - 1)

def Open(filename):
   nums = []
   with open(filename) as f:
    for line in f.readlines():
        line = line.split()
        for i in range(len(line)):
            nums.append(int(line[i])) 
    return nums


majex1 = Open("Majex1.txt")
majex2 = Open("Majex2.txt")
majex3 = Open("Majex3.txt")
majex4 = Open("Majex4.txt")

# Majex 1
print("Filename: Majex1.txt")
print(f"Number of elements in list: {len(majex1)}")
majority = majorityElement(majex1)
if majority == -1:
    print("There is no majority element.")
else:
    print(f"Majority element: {majority}.")

# Majex 2
print("\n\nFilename: Majex2.txt")
print(f"Number of elements in list: {len(majex2)}")
majority = majorityElement(majex2)
if majority == -1:
    print("There is no majority element.")
else:
    print(f"Majority element: {majority}.")

# Majex 3
print("\n\nFilename: Majex3.txt")
print(f"Number of elements in list: {len(majex3)}")
majority = majorityElement(majex3)
if majority == -1:
    print("There is no majority element.")
else:
    print(f"Majority element: {majority}.")

# Majex 4 
print("\n\nFilename: Majex4.txt")
print(f"Number of elements in list: {len(majex4)}")
majority = majorityElement(majex4)
if majority == -1:
    print("There is no majority element.")
else:
    print(f"Majority element: {majority}.")
