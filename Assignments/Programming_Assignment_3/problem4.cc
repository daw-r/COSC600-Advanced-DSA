/* Filename: problem4.cc
 *
 * Author: Devere Anthony Weaver
 *
 * Assignment: Programming Assignment 3
 * Problem: Problem 4
 *
 * Description: This program implements a radix sort algorithm to sort a vector
 * of 5,000 randomly generated integers.
 */
#include <iostream>
#include <string>
#include <vector>
#include <random>

template <typename T>
void print_array(T arr[], int n)
{
   std::cout << "(";
   for (int i{}; i < n; i++)
      std::cout << arr[i] << ", ";
}

template <typename T>
void print_array_last(T arr[], int n)
{
   for (int i = 0; i < n; i++)
   {
      if (i == n - 1)
         std::cout << arr[4900 + i] << ")\n";
      else
         std::cout << arr[4900 + i] << ", ";
   }
}

std::vector<int> generate_random(int low, int high, int n)
{
   /* generate n random numbers in the interval [low, high] */
   std::random_device rd;
   std::mt19937 gen(rd());
   std::uniform_int_distribution<> distr(low, high);
   std::vector<int> v{};
   for (int i = 0; i < n; i++)
      v.push_back(distr(gen));
   return v;
}

int get_length(int x)
{
   if (x == 0)
      return 1;

   int digits = 0;
   while (x != 0)
   {
      digits++;
      x /= 10;
   }
   return digits;
}

int max_length(int *list, int list_size)
{
   /* get max length of arrays */
   int max = 0;
   for (int i = 0; i < list_size; i++)
   {
      int digits = get_length(list[i]);
      if (digits > max)
      {
         max = digits;
      }
   }
   return max;
}

void radix_sort(int *list, int list_size)
{
   /* implementation of a radix sort algorithm */
   std::vector<std::vector<int> *> buckets;
   for (int i = 0; i < 10; i++)
   {
      std::vector<int> *bucket = new std::vector<int>();
      buckets.push_back(bucket);
   }

   int back = 0;

   int max = max_length(list, list_size);

   int pow = 1;
   for (int i = 0; i < max; i++)
   {
      for (int j = 0; j < list_size; j++)
      {
         int n = list[j];
         int bucket_index = (abs(n) / pow) % 10;
         buckets[bucket_index]->push_back(n);
      }
      back = 0;

      for (int i = 0; i < 10; i++)
      {
         std::vector<int> &bucket = *buckets[i];
         for (int j = 0; j < bucket.size(); j++)
         {
            list[back] = bucket[j];
            back++;
         }
         bucket.clear();
      }

      pow *= 10;
   }

   std::vector<int> sorted;
   for (int i = 0; i < list_size; i++)
   {
      int num = list[i];
      sorted.push_back(num);
   }

   back = 0;
   for (int i = 0; i < sorted.size(); i++)
   {
      list[back] = sorted[i];
      back++;
   }

   for (int i = 0; i < 10; i++)
   {
      delete buckets[i];
   }
}

int main()
{
   int size = 5000;
   std::random_device rd;
   std::mt19937 gen(rd());
   std::uniform_int_distribution<> distr(0, 50000);
   int a[size];
   for (int i{}; i < size; i++)
      a[i] = distr(gen);
   std::cout << "Input (first 100...last 100): ";
   print_array(a, 100);
   std::cout << " . . . . . . ";
   print_array_last(a, 100);
   std::cout << '\n';

   auto start = std::chrono::high_resolution_clock::now();
   radix_sort(a, size);
   auto end = std::chrono::high_resolution_clock::now();
   auto duration = std::chrono::duration_cast<std::chrono::nanoseconds>(end - start);

   std::cout << "Output (first 100...last 100): ";
   print_array(a, 100);
   std::cout << " . . . . . . ";
   print_array_last(a, 100);
   std::cout << '\n';
   std::cout << "\nExecution time: " << duration.count() << " nanoseconds.\n";
}