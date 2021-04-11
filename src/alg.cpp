// Copyright 2021 NNTU-CS

int countPairs1(int* arr, int len, int value) {
    int pairs = 0;
    for (int i = 0; i < len; i++) {
            for (int j = i + 1; j < len-1-i; j++) {
                if (arr[i] + arr[j] == value) {
                    pairs++;
            }
        }
    }
    return pairs;
}

int countPairs2(int* arr, int len, int value) {
    int pairs = 0;
        for (int i = 0; i < len; i++) {
                for (int j=len-1; j < len; j--) {
                        if (arr[i]+arr[j] == value)
                                pairs++;
                }
        }
        return pairs;
}

int countPairs3(int *arr, int len, int value) {
        int pairs = 0;
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
                  pairs++;
        }
        break;
      } else if (arr[middle] > (value - arr[i])) {
        right = middle;
      } else {
        left = middle+1;
      }
    }
  }
    return pairs;
}
