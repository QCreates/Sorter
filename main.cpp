// Merge sort in C++

#include <bits/stdc++.h>
#include <vector>
#include <iostream>
using namespace std;


// Function to compare 2 words
bool isAlphabeticallySmaller(string str1, string str2)
{
  transform(str1.begin(), str1.end(), str1.begin(),
	    ::toupper);
  transform(str2.begin(), str2.end(), str2.begin(),
	    ::toupper);
  if (str1 < str2) {
    return true;
  }
  return false;
}

vector<string> merge(vector<string> Arr1,
		     vector<string> Arr2)
{
  int m = Arr1.size();
  int n = Arr2.size();
  vector<string> Arr3;

  int idx = 0;

  int i = 0;
  int j = 0;
  while (i < m && j < n) {
    if (isAlphabeticallySmaller(Arr1[i], Arr2[j])) {
      Arr3.push_back(Arr1[i]);
      i++;
      idx++;
    }
    else {
      Arr3.push_back(Arr2[j]);
      j++;
      idx++;
    }
  }
  while (i < m) {
    Arr3.push_back(Arr1[i]);
    i++;
    idx++;
  }
  while (j < n) {
    Arr3.push_back(Arr2[j]);
    j++;
    idx++;
  }
  return Arr3;
}

// Function to mergeSort 2 arrays
vector<string> mergeSort(vector<string> Arr, int lo, int hi)
{
  if (lo == hi) {
    vector<string> A = { Arr[lo] };
    return A;
  }
  int mid = lo + (hi - lo) / 2;
  vector<string> arr1 = mergeSort(Arr, lo, mid);
  vector<string> arr2 = mergeSort(Arr, mid + 1, hi);

  vector<string> arr3 = merge(arr1, arr2);
  return arr3;
}

// Driver code
int main(){
  vector<string> words;

  std::string line;
  while (std::getline(std::cin, line)) {
    words.push_back(line);
  }

  int N = words.size();
  vector<string> a = mergeSort(words, 0, N - 1);
  for (int i = 0; i < N; i++) {
    cout << a[i] << "\n";
  }
  return 0;
}




/*

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
*/
