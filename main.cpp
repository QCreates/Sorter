// Merge sort in C++

#include <bits/stdc++.h>
#include <vector>
#include <iostream>
using namespace std;

// Function to compare 2 words
bool isAlphabeticallySmaller(string str1, string str2)
{
  transform(str1.begin(), str1.end(), str1.begin(), ::toupper);
  transform(str2.begin(), str2.end(), str2.begin(), ::toupper);

  if (str1 < str2) {
    return true;
  }
  return false;
}

void selectionSort(vector<string>& arr)
{
  int n = arr.size();

  // One by one move boundary of
  // unsorted subarray
  for (int i = 0; i < n - 1; i++) {

    // Find the minimum element
    // in unsorted array
    int min_idx = i;
    for (int j = i + 1; j < n; j++)
      if (isAlphabeticallySmaller(arr[j], arr[min_idx]))
	min_idx = j;

    // Swap the found minimum
    // element with the first element
    string temp = arr[min_idx];
    arr[min_idx] = arr[i];
    arr[i] = temp;
  }
}

//  std::cout << words << std::endl;

int main(){

  vector<string> words;

  std::string line;
  while (std::getline(std::cin, line)) {
    words.push_back(line);
  }

  selectionSort(words);
  for (int i = 0; i < words.size(); i++){
    std::cout << words[i] << endl;
  }
}
