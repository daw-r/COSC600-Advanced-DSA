#!/usr/bin/env python3
import numpy as np

nums = []
with open("Majex1.txt") as f:
    for line in f.readlines():
        line = line.split()
        for i in range(len(line)):
            nums.append(int(line[i]))

print(f"Number of elements in list: {len(nums)}")
nums = np.array(nums)
unique, counts = np.unique(nums, return_counts =True)
print(np.asarray((unique, counts)).T)

nums = []
with open("Majex2.txt") as f:
    for line in f.readlines():
        line = line.split()
        for i in range(len(line)):
            nums.append(int(line[i]))

print(f"\nNumber of elements in list: {len(nums)}")
nums = np.array(nums)
unique, counts = np.unique(nums, return_counts =True)
print(np.asarray((unique, counts)).T)


nums = []
with open("Majex3.txt") as f:
    for line in f.readlines():
        line = line.split()
        for i in range(len(line)):
            nums.append(int(line[i]))

print(f"\nNumber of elements in list: {len(nums)}")
nums = np.array(nums)
unique, counts = np.unique(nums, return_counts =True)
print(np.asarray((unique, counts)).T)

nums = []
with open("Majex4.txt") as f:
    for line in f.readlines():
        line = line.split()
        for i in range(len(line)):
            nums.append(int(line[i]))

print(f"\nNumber of elements in list: {len(nums)}")
nums = np.array(nums)
unique, counts = np.unique(nums, return_counts =True)
print(np.asarray((unique, counts)).T)