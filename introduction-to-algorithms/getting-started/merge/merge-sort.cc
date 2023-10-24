/* merge-sort.cc - implemented example of using the merge sort algorithm on 
a fixed-size integer array; can and should be generic to be useful for other 
data types; however, this is just illustrative and for educational purposes
only */
#include <iostream>
#include <cmath>
#include <catch2/catch_test_macros.hpp>

void merge(int arr[], int p, int q, int r)
{
    /* merge() - merge given subarrays into a single ordered array */

    // compute lengths of subarrays
    int nleft = q - p + 1;
    int nright = r - q;

    // split array and copy into new subarrays
    int left[nleft];
    int right[nright];

    for (int i{}; i < nleft; ++i)    // left subarray
        left[i] = arr[p + i];

    for (int j{}; j < nright; ++j)  // right subarray
        right[j] = arr[q + j + 1];
    
    // create indicies for smallest remaining elments in left and right
    // k is the index for the sorted output array
    int i{}, j{}, k{p};

    // element-wise comparision of elements in left and right, copy the smallest
    // value of each into the sorted output array until either one is exhausted
    while (i < nleft && j < nright) {
        if (left[i] <= right[j]) {
            arr[k] = left[i];
            i++;
        } else {
            arr[k] = right[j];
            j++;
        }
        k++;
    }

    // once either is exhausted, then add the elements of remaining array to the 
    // final sorted output array
    while (i < nleft) {
        arr[k] = left[i];
        i++;
        k++;
    }
    while (j < nright) {
        arr[k] = right[j];
        j++;
        k++;
    }
}

void merge_sort(int arr[], int p, int r)
{
    /* merge_sort() - performs merge-sort algorithm to give a sorted array */
    if (p >= r) return;    // zero or one element array is already sorted
    int q = floor((p+r)/2);  // compute midpoint

    // recursively call merge-sort on subarrays to sort them until base-case
    merge_sort(arr, p, q);
    merge_sort(arr, q+1, r);
    merge(arr, p, q, r);    // bring them all together
}

void print_array(int arr[], int n)
{
    std::cout << "[ ";
    for (int i{}; i < n; i++)
        std::cout << arr[i] << ' ';
    std::cout << "]\n";
}


TEST_CASE("Sorted Array") {
    std::cout << "TEST_CASE(Sorted Array)\n";
    int arr[] = {8, 1, 5, 13, 7, 2, 9, 7};
    int sorted[] = {1, 2, 5, 7, 7, 8, 9, 13};
    std::cout << "Input: "; print_array(arr, 8);
    merge_sort(arr, 0, 7);
    std::cout << "Output: "; print_array(arr, 8);
    int flag = 1; // TRUE
    for (int i{}; i < 8; i++) {
        if (arr[i] != sorted[i])
            flag = 0;    // FALSE
    }
    REQUIRE(flag == 1);
}

TEST_CASE("Problem 2.3-1") {
    std::cout << "\n\nTEST_CASE(Problem 2.3-1)\n";
    int arr[] = {3, 41, 52, 26, 38, 57, 9, 49};
    int sorted[] = {3, 9, 26, 38, 41, 49, 52, 57};
    std::cout << "Input: "; print_array(arr, 8);
    merge_sort(arr, 0, 7);
    std::cout << "Output: "; print_array(arr, 8);
    int flag = 1; // TRUE
    for (int i{}; i < 8; i++) {
        if (arr[i] != sorted[i])
            flag = 0;    // FALSE
    }
    REQUIRE(flag == 1);

}