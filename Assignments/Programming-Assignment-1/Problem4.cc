#include <iostream>
#include <cmath>
#include <vector>

int countFrequency(int X[], int l, int r, int value)
{
    int count = 0;
    for (int i = l; i <= r; i = i + 1)
    {
        if (X[i] == value)
            count = count + 1;
    }
    return count;
}

int findMajorityElement(int X[], int l, int r)
{
    if (l == r)
        return X[l];

    /* DIVIDE */
    int mid = l + (r - l) / 2;
    int leftMajority = findMajorityElement(X, l, mid);
    int rightMajority = findMajorityElement(X, mid + 1, r);

    /* CONQUER */
    if (leftMajority == rightMajority)
        return leftMajority;

    int leftCount = countFrequency(X, l, r, leftMajority);
    int rightCount = countFrequency(X, l, r, rightMajority);

    /* COMBINE */
    if (leftCount > (r - l + 1) / 2)
        return leftMajority;
    else if (rightCount > (r - l + 1) / 2)
        return rightMajority;
    else
        return -1; // No majority element in this subarray
}

int majorityElement(int X[], int n)
{
    return findMajorityElement(X, 0, n - 1);
}

int main()
{
    int arr[]{5,5,5,2};
    int majority = majorityElement(arr, 4);
    std::cout << "Result: " << majority << "\n";
}