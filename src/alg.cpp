// Copyright 2021 NNTU-CS

int countPairs1(int* arr, int len, int value) {
    int pair_sum = 0;
    for (int i = 0; i < len; i++) {
            for (int j = i + 1; j < len-1-i; j++) {
                if ((arr[i] + arr[j]) == value) {
                    pair_sum++;
            }
        }
    }
    return pair_sum;
}

int countPairs2(int* arr, int len, int value) {
    int pair_sum = 0;
        for (int i = 0; i < len; i++) {
                for (int j=len-1; j < len; j--) {
                        if (arr[i]+arr[j] == value)
                                pair_sum++;
                }
        }
        return pair_sum;
}

int countPairs3(int *arr, int len, int value) {
        int pair_sum = 0;
        for (int i = 0; i < len-1; i++) {
                int left = i+1, right = len;
                while (left < right) {
      int middle = (left + right) / 2;
      if (arr[middle] == (value - arr[i])) {
        while (arr[middle-1] == (value - arr[i])) {
          middle--;
        }
          while (arr[middle] == (value - arr[i])) {
                  middle++;
                  pair_sum++;
        }
        break;
      } else if (arr[middle] > (value - arr[i])) {
        right = middle;
      } else {
        left = middle+1;
      }
    }
  }
    return pair_sum;
}
