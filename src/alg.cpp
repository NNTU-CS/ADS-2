// Copyright 2021 NNTU-CS
int countPairs1(int *arr, int len, int value) {
  int k = 0;
  for (int i = 0; i < len; ++i) {
    for (int j = i + 1; j < len; ++j) {
      if (arr[i] + arr[j] == value)
        k = k + 1;
    }
  }
  return k;
}
int countPairs2(int *arr, int len, int value) {
  int k = 0;
  for (int right = len - 1; right > 0; --right) {
    if (arr[right] <= value) {
      for (int j = 0; j < right; ++j) {
        if ((arr[right] + arr[j]) == value)
          ++k;
      }
    }
  }
  return k;
}
int countPairs3(int *arr, int len, int value) {
  int k = 0, j, middle, left, right, value2;
  for (int i = 0; i < len - 1; ++i) {
    if (arr[i] >= 0) {
      j = 0;
      left = i + 1;
      right = len;
      value2 = value-arr[i];
      while (left < right) {
        middle = left + (right - left) / 2;
        if (arr[middle] == value2) {
          while ((arr[middle-1] == value2)
                 && (middle > i+1)) --middle;
          while (arr[middle] == value2) ++middle, ++j;
          break;
        } else if (arr[middle] > value2) {
          right = middle;
        } else { left = middle + 1;
               }
      }
      k += j;
    }
  }
  return k;
}
