// Copyright 2021 NNTU-CS

int countPairs1(int *arr, int len, int value) {
  int count = 0;
    for (int i = 0; i < len; i++)
        for (int j = i + 1; j < len; j++)
            if (arr[i] + arr[j] == value)
                count++;
  if (count > 0) {
    return count;
  } else {
  return 0;
  }
}

int countPairs2(int *arr, int len, int value) {
  int count = 0, rb = len-1;
    while (arr[0] + arr[rb] > value)
        rb--;
    for (int i = 0; i <= rb; i++)
        for (int j = i + 1; j <= rb; j++)
        if (arr[i] + arr[j] == value)
            count++;
  if (count > 0) {
    return count;
  } else {
  return 0;
  }
}

int countPairs3(int *arr, int len, int value) {
  int count = 0, left, right, mid;
    for (int i = 0; i < len - 1; i++) {
        left = i+1;
        right = len - 1;
        mid = (left + right) / 2;
        while (right != left) {
            if (arr[i] + arr[mid] > value) {
                right = mid;
                mid = (left + right) / 2;
            } else if (arr[i] + arr[mid] < value) {
                left = mid + 1;
                mid = (left + right) / 2;
            } else
                break;
        }
        if (arr[i] + arr[mid] == value) {
            count++;
            int k = mid-1;
            while ((k > i) && (arr[k] + arr[i] == value)) {
                count++;
                k--;
            }
            k = mid + 1;
            while ((k < len) && (arr[k] + arr[i] == value)) {
                count++;
                k++;
            }
        }
    }
  if (count > 0) {
    return count;
  } else {
  return 0;
  }
}
