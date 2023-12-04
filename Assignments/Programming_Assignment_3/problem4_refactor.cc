#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>

template <typename T>
void print_vector(std::vector<T> &vec)
{
    std::cout << "(";
    for (int i{}; i < vec.size(); i++)
    {
        if (i == vec.size())
            std::cout << vec[i] << ")\n";
        else 
            std::cout << vec[i] << ", ";
    }
}

int get_length(int value) {
   if (value == 0) 
      return 1;
      
   int digits = 0;
   while (value != 0) {
      digits++;
      value /= 10;
   }
   return digits;
}


template<typename T>
void radix_sort(std::vector<T>) 
{
    // vector of vectors 
   std::vector<std::vector<int>> buckets;

   for (int i = 0; i < 10; i++) 
   {
      std::vector<int> bucket = new std::vector<int>();
      buckets.push_back(bucket);
   }
      
   int copyBackIndex = 0;
      
   // Find the max length, in number of digits
   int maxDigits = max_length(numbers, numbersSize);
      
   int pow10 = 1;
   for (int digitIndex = 0; digitIndex < maxDigits; digitIndex++) {
      // Put numbers into buckets
      for (int i = 0; i < numbersSize; i++) {
         int num = numbers[i];
         int bucketIndex = (abs(num) / pow10) % 10;
         buckets[bucketIndex]->push_back(num);
      }
         
      // Copy buckets back into numbers array
      copyBackIndex = 0;
      for (int i = 0; i < 10; i++) {
         std::vector<int>& bucket = *buckets[i];
         for (int j = 0; j < bucket.size(); j++) {
            numbers[copyBackIndex] = bucket[j];
            copyBackIndex++;
         }
         bucket.clear();
      }
      
      pow10 *= 10;
   }
      
   std::vector<int> negatives;
   std::vector<int> nonNegatives;
   for (int i = 0; i < numbersSize; i++) {
      int num = numbers[i];
      if (num < 0) {
         negatives.push_back(num);
      }
      else {
         nonNegatives.push_back(num);
      }
   }
      
   // Copy sorted content to array - negatives in reverse, then non-negatives
   copyBackIndex = 0;
   for (int i = negatives.size() - 1; i >= 0; i--) {
      numbers[copyBackIndex] = negatives[i];
      copyBackIndex++;
   }
   for (int i = 0; i < nonNegatives.size(); i++) {
      numbers[copyBackIndex] = nonNegatives[i];
      copyBackIndex++;
   }
   
   // Free each dynamically allocated bucket
   for (int i = 0; i < 10; i++) {
      delete buckets[i];
   }
}















