// Copyright 2021 NNTU-CS

int countPairs1(int *arr, int len, int value) {
  int count = 0;
    for (int i = 0; i < (len - 1); i++) {
        for (int j = i + 1; j < len; j++) {
            if ((arr[i] + arr[j]) == value) {
                count++;
            }
        }
    }
    return count;
}

int countPairs2(int *arr, int len, int value) {
 int count = 0;
  int l = 0, r = len - 1;
  while (l < r - 1) {
    int m = (r + l) / 2;
    if (arr[m] <= value)
      l = m + 1;
    else
    r = m;
  }
  len = r;
  for (int i = 0; i < len; i++) {
    for (int j = len; j > i; j--) {
      if (arr[i] + arr[j] > value) continue;
      if (arr[i] + arr[j] < value) break;
      if (arr[i] + arr[j] == value) {
        count++;
      }
    }
  }
  return count;
}

int countPairs3(int *arr, int len, int value) {
  int а = 0, lb = 0, rb = len;
    int k = (lb + rb) / 2, l = k, r = k;
    for (int i = 0; i < len; i++) {
        while (rb >= lb) {
            k = (lb + rb) / 2;
            l = k - 1;
            r = k + 1;
            if (arr[i] + arr[k] == value) {
                if (i != k) {
                    count++;
                }
                while (((arr[i] + arr[l]) == value) && (i != l)) {
                    count++;
                    l--;
                }
                while (((arr[i] + arr[r]) == value) && (i != r)) {
                    count++;
                    r++;
                }
                rb = lb - 1;
                } else if ((arr[i] + arr[k]) < value) {
                        lb = k + 1;
                    } else if ((arr[i] + arr[k]) > value) {
                                rb = k - 1;
                            }
        }
        arr[i] = value + 1;
        rb = len;
        lb = i + 1;
    }
    return count;
}
