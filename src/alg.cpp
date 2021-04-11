// Copyright 2021 NNTU-CS

int countPairs1(int *arr, int len, int value) {
  int count = 0;
  for (int i = 0; i < len - 1; i++)
  {
    (int j = i + 1; j < len ; j++)
    {
      if (arr[i] + arr[j] == value)
        count++;
    }
  }  
  return count;
}

int countPairs2(int *arr, int len, int value) {
  int count = 0;
  int i = len - 1;
  while (arr[i] > value) {
    i--;
  }
  for (i; i > 0; i--) {
    for (int j = 0; j < i; j++) {
      if ((arr[i] + arr[j]) == value)
        count ++;
    }
  }
  return count;
}

int countPairs3(int *arr, int len, int value) {
  int count = 0;
  for (int i = 0; i < len - 1; i++) {
    int left = i + 1;
    int right = len;
    int diff = value - arr[i];
    while (left < right) {
      int mid = (left + right) / 2;
      if (arr[mid] == diff) {
        while ((arr[mid - 1] == diff) && (mid > left)) {
          mid--;
        }
        while (arr[mid] == diff) {
          mid++;
          count++;
        }
        break;
      }
      else if (arr[mid] > diff) {
        right = mid;
      }
      else {
        left = mid + 1;
      }
    }
  }
  return count;
}
