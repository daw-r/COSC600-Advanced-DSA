/*
 Quicksort.h - contains templated implementations of the quicksort algorithm
 as well as the partition algorithm upon which quicksort relies on.
 */

#ifndef QUICKSORT_H
#define QUICKSORT_H
#include <iostream>
#include <cmath>

namespace Quicksort
{

    template <typename T>
    bool compare(T &list, int p, int r)
    {
        auto x = list[p];
        for (size_t i = p; i < r; i++)
        {
            if (list[i] != x)
                return false; // i.e. they're different
        }
        return true; // they're equal
    }

    template <typename T>
    int partition(T &list, int p, int r, bool desc = false)
    {
        /*

         partition() - computes the pivot index needed for the quicksort algorithm

         INPUT:
         ------
         - list = a generic C++ STL container or C-style array
         - p = integer representing starting index of the list or sublist
         - r = integer representing the last index of the list or sublist

         NOTE: list is simply a synonym for any container here

         RETURN:
         -------
         - an integer value representing the index of the pivot element in the list

         */
        auto x = list[r]; // pivot
        int i = p - 1;    // highest index

        if (desc)
        {
            for (int j = p; j <= (r - 1); ++j)
            {
                if (list[j] >= x)
                {
                    i++;
                    auto temp = list[i];
                    list[i] = list[j];
                    list[j] = temp;
                }
            }
            auto temp = list[i + 1];
            list[i + 1] = list[r];
            list[r] = temp;
            i++;
            return i;
        }

        for (int j = p; j <= (r - 1); ++j)
        {
            if (list[j] <= x)
            {
                i++;
                auto temp = list[i];
                list[i] = list[j];
                list[j] = temp;
            }
        }
        auto temp = list[i + 1];
        list[i + 1] = list[r];
        list[r] = temp;
        i++;
        return i;
    }

    template <typename T>
    void quicksort(T &list, int p, int r, bool desc = false)
    {
        /*

         quicksort() - executes standard quicksort algorithm on a given list of
                       some type

         INPUT:
         ------
         - list = a generic C++ STL container or C-style array
         - p = integer representing starting index of the list or sublist
         - r = integer representing the last index of the list or sublist

         NOTE: list is simply a synonym for any container here

         RETURN:
         -------
         - void - function sorts list in place and returns nothing

         */

        if (p < r)
        {
            int q = Quicksort::partition(list, p, r, desc);
            Quicksort::quicksort(list, p, q - 1, desc);
            Quicksort::quicksort(list, q + 1, r, desc);
        }
    }
} // end namespace Quicksort
#endif
