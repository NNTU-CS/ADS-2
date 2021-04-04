// Copyright 2021 NNTU-CS
int countPairs1(int* arr, int len, int value) {
  int count = 0;
  for (int i = 0; i < len - 1; i++)  {
    for (int j = i; j <(len - 1)-i; j++) {
      if (arr[i] + arr[j + 1] == value)
        count++;
    }
  }
  if (count)
    return count;
  else
    return 0;
}

int countPairs2(int* arr, int len, int value) {
  int count = 0;
  for (int i = len - 1; i > 0; i--) {
    if (arr[len - 1] <= value) {
      for (int j = i; j > 0; j--)
        if (arr[i] + arr[j - 1] == value)
          count++;
    } else {
      len--;
    }
  }
  if (count)
    return count;
  else
    return 0;
}

int countPairs3(int* arr, int len, int value) {
  int count = 0;
  for (int i = 0; i < len - 1; i++) {
    int rt = len;
    if (arr[i] < value) {
      int lt = i;
      while (lt < rt - 1) {
        int mid = (lt + rt) / 2;
        if (arr[i] + arr[mid] == value) {
          count++;
          int j = mid + 1;
          while (arr[i] + arr[j] == value && j < rt) {
            count++;
            j++;
          }
          j = mid - 1;
          while (arr[i] + arr[j] == value && j > lt) {
            count++;
            j--;
          }
          break;
        }
        if (arr[i] + arr[mid] > value)
          rt = mid;
        else
          lt = mid;
      }
    } else {
      rt--;
    }
  }
  if (count)
    return count;
  else
    return 0;
}
