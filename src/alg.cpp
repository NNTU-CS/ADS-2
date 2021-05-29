// Copyright 2021 NNTU-CS

int countPairs1(int *arr, int len, int value) {
  int count = 0;
  for (int i=0; i < len-1; i++) {
    for (int j=i+1; j < len; j++) {
     if (arr[i]+arr[j] == value) {
       count++; }
    }
  }
  return count;
}

int countPairs2(int *arr, int len, int value) {
int count = 0, left = 0, right = len, middle;
while (left < right - 1) {
middle = (left + right) / 2;
if (arr[middle] <= value)
left = middle;
else
right = middle;
}
len = right;
  for (int i = 0; i < len-1; i++) {
for (int j = len; j > i; j--) {
if (arr[i] + arr[j] == value)
count++;
}
}
  return count;
}

int countPairs3(int *arr, int len, int value) {
  int mid, right, left, dif,m=0, count=0;
  for (int i=0; i < len; i++) {
    left= i+1;
    right= len;
    dif= value - arr[i];
    while (left < right) {
      mid = left + (right - left)/2;
      if (arr[mid]==dif) {
        while (arr[mid-1] == dif && mid >= i+1) {
          mid--; }
        while (arr[mid] == dif && mid<len) {
          mid++;
          count++; }
        break;
      }
      if (arr[mid]> dif) {
        right = mid;
      } else {
        left = mid+1; }
    }
  }
          
  return count;
}

