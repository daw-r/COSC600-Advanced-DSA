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

majorityElement([5,4,5,2,5,2,5,5])