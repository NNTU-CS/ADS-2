// Copyright 2021 NNTU-CS

int countPairs1(int *arr, int len, int value) {
  int count = 0;
    for (int i = 0; i < len-1; i++) {
        for (int j = i+1; j < len; j++) {
            if (arr[i] + arr[j] == value)
                count++;
        }
    }
    if (count)
      return count;
    else
      return 0;
}

int countPairs2(int *arr, int len, int value) {
  int count = 0;
  for (int i = len-1; i > 0; i--) {
    if (arr[len-1] <= value) {
    for (int j = i; j > 0; j--)
      if (arr[i] + arr[j-1] == value)
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

int countPairs3(int *arr, int len, int value) {
  int n = 0;
  for (int i = 0; i < len - 1; i++) {
  int right = len;
    if (arr[i] < value) {
      int left = i;
    while (left < right-1) {
      int midd = (left + right) / 2;
      if (arr[i] + arr[midd] == value) {
        n++;
        int j = midd+1;
        while (arr[i] + arr[j] == value && j < right) {
          n++;
          j++;
        }
        j = midd - 1;
        while (arr[i] + arr[j] == value && j > left) {
          n++;
          j--;
          }
        break;
      }
      if (arr[i] + arr[midd] > value)
        right = midd;
      else
        left = midd;
      }
    } else {
      right--;
      }
  }
  if (n)
    return n;
  else
    return 0;
}
