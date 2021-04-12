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
    int k = 0;
    while (arr[len - 1] > value) {
        len--;
    }
    for (len; len > 0; len--) {
        int R = len - 1;
        int L = 0;
        while (L < R) {
            midl = (R - L) / 2 + L;
            int Q = 0;
            int Z = midl;
            if (arr[midl] == (value - arr[len - 1])) {
                while (arr[midl - 1] == (value - arr[len - 1])) {
                    Q++;
                    midl--;
                }
                midl += Q;
                while (arr[midl] == (value - arr[len - 1])) {
                    midl++;
                    Q++;
                }
            }
            if (Q > 0) {
                k += Q;
                midl = Z;
                break;
            }
            if (arr[midl] > (value - arr[len - 1])) {
                R = midl;
            } else {
                L = midl + 1;
            }
        }
    }
    if (k > 0) {
        return k;
    }
    else {
        return 0;
    }
}
