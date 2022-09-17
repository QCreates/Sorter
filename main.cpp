// Merge sort in C++

#include <bits/stdc++.h>
#include <vector>
#include <iostream>
using namespace std;

/*// Merge two subarrays L and M into arr
void merge(string arr[], int p, int q, int r) {

  // Create L ← A[p..q] and M ← A[q+1..r]
  int n1 = q - p + 1;
  int n2 = r - q;

  string L[n1], M[n2];

   for (int i = 0; i < n1; i++)
      L.at(i) = arr.at(p + i);
      for (int j = 0; j < n2; j++)
      M.at(j) = arr.at(q + 1 + j);
  
  // Maintain current index of sub-arrays and main array
  int i, j, k;
  i = 0;
  j = 0;
  k = p;

  // Until we reach either end of either L or M, pick larger among
  // elements L and M and place them in the correct position at A[p..r]
  while (i < n1 && j < n2) {
    if (L[i] <= M[j]) {
      arr[k] = L[i];
      i++;
    } else {
      arr[k] = M[j];
      j++;
    }
    cout << arr[k];

    k++;
  }

  // When we run out of elements in either L or M,
  // pick up the remaining elements and put in A[p..r]
  while (i < n1) {
    arr[k] = L[i];
    i++;
    k++;
  }

  while (j < n2) {
    arr[k] = M[j];
    j++;
    k++;
  }
}

// Divide the array into two subarrays, sort them and merge them
void mergeSort(string arr[], int l, int r) {
  if (l < r) {
    // m is the point where the array is divided into two subarrays
    int m = l + (r - l) / 2;

    mergeSort(arr, l, m);
    mergeSort(arr, m + 1, r);

    // Merge the sorted subarrays
    merge(arr, l, m, r);
  }
  
}


// Driver program
  int main() {
  int arr[] = {6, 5, 12, 10, 9, 1};
  int size = sizeof(arr) / sizeof(arr[0]);

  mergeSort(arr, 0, size - 1);

  cout << "Sorted array: \n";
  return 0;
  }
int main(){

  string words[] = {"zbea's", "ccc'c", "CCc", "dw", "a", "ccc"};
  
  int arr[] = {1, 5, 3, 2, 4, 6, 0};

    std::string line;
      while (std::getline(std::cin, line)) {
      words.push_back(line);
      }

  for (int i = 0; i < 6; i++){
    cout << words[i] + " :: unsorted" << endl;
  }
  
  mergeSort(words, 0, 5);

  for (int i = 0; i < 6; i++){
    cout << words[i] + "  :: sorted" << endl;
  }
  return 0;
  }*/


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
