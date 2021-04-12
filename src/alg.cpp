// Copyright 2021 NNTU-CS
int countPairs1(int* arr, int len, int value) {
    int k = 0;
    for (int i = 0; i < len - 1; i++) {
        for (int j = i + 1; j < len; j++) {
            if ((arr[i] + arr[j]) == value) {
                k++;
            }
        }
    }
    if (k > 0) {
        return k;
    } else {
        return 0;
    }
}
int countPairs2(int* arr, int len, int value) {
    int k = 0;
    while (arr[len - 1] > value) {
        len--;
    }
    for (len; len > 0; len--) {
        for (int j = 0; j < len; j++) {
            if ((arr[len] + arr[j]) == value) {
                k++;
            }
        }
    }
    if (k > 0) {
        return k;
    } else {
        return 0;
    }
}
int countPairs3(int* arr, int len, int value) {
    int k = 0, L, R;
        for (int i = 0; i < len-1; i++) {
            L = i + 1;
            R = len;
            while (L < R) {
                int mid = L + (R - L) / 2;
                if (arr[mid] < (value - arr[i]))
                    L = mid + 1;
                else
                    R = mid;
                if (arr[L] == (value - arr[i])) {
                    while (arr[L] == (value - arr[i])) {
                        L++;
                        k++;
                    }
                }
            }
        }
        if (k != 0) {
            return k;
        } else {
            return 0;
        }
}
