// Copyright 2021 NNTU-CS

int countPairs1(int *arr, int len, int value) {
  int counter = 0;
  for (int i = 0; i < len - 1; i++) {
    for (int j = i + 1; j < len; j++) {
      if (arr[i] + arr[j] == value) {
        counter++;
      }
    }
  }
  return counter;
}

int countPairs2(int *arr, int len, int value) {
  int counter = 0;
  int left = 0;
  int right = len - 1;
  while (left < right - 1) {
    int mid = (left + right) / 2;
    if (arr[mid] > value) {
      right = mid;
    } else {
      left = mid + 1;
    }
  }
  len = right;
  for (int i = 0; i < len; i++) {
    for (int j = len; j > i; j--) {
      if (arr[i] + arr[j] == value) {
        counter++;
      }
      if (arr[i] + arr[j] < value) {
        break;
      }
      if (arr[i] + arr[j] > value) {
        continue;
      }
    }
  }
  return counter;
}

int countPairs3(int *arr, int len, int value) {
  int counter = 0;
  for (int i = 0; i < len - 1; i++) {
    int left = i + 1;
    int right = len - 1;
    int second = value - arr[i];
    while (left < right) {
      int mid = (left + right) / 2;
      if (arr[mid] < second) {
        left = mid + 1;
      } else {
        right = mid;
      }
    }
    if (arr[left] == second) {
      while (arr[left] == second) {
        counter++;
        left++;
      }
    }
  }
  return counter;
}
