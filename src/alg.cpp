// Copyright 2021 NNTU-CS
int countPairs1(int *arr, int len, int value) {
        int count = 0;
        for (int i = 0; i < len; i++) {
                for (int j = i + 1; j < len - 1 - i; j++) {
                        if ((arr[i] + arr[j]) == value)
                                count++;
                }
        }
        return count;
}
int countPairs2(int *arr, int len, int value) {
        int count = 0;
        for (int i = 0; i < len; i++) {
                for (int j = len - 1; j < len - 1 - i; j--) {
                        if ((arr[i] + arr[j]) == value)
                                count++;
                }
        }
        return count;
}
int countPairs3(int *arr, int len, int value) {
        int count = 0;
        for (int i = 0; i < len - 1; i++) {
                int l = i + 1, r = len;
                while (l < r) {
                        int midd = (l + r) / 2;
                        if (arr[midd] == (value - arr[i])) {
                                while (arr[midd - 1] == (value - arr[i])) {
                                        midd--;
                                }
                                while (arr[midd] == (value - arr[i])) {
                                        midd++;
                                        count++;
                                }
                                break;
                        } else if (arr[midd] > (value - arr[i])) {
                                r = midd;
                        } else {
                                l = midd + 1;
                        }
                }
        }
  return count;
}
