#include <iostream>
#include <time.h>
using namespace std;

int binarySearch(int *arr, int s, int e, int find) {
  int mid;

  while (s <= e) {
    mid = (s + e) / 2;
    if (arr[mid] == find)
      return mid;
    else if (arr[mid] < find)
      s = mid + 1;
    else
      e = mid - 1;
  }

  return -1;
}

int main() {
  int data[10] = {10, 11, 12, 13, 14, 15, 16, 17, 18, 19};
  int findKey;

  cout << "Input Number(10 ~ 19): ";
  cin >> findKey;

  clock_t t = clock();
  int answer = binarySearch(data, 0, 9, findKey);
  cout << findKey << " is on index [" << answer << "]" << endl;
  cout << "elapsed time: " << (clock() - t) / 1000. << endl;
}
