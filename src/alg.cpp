// Copyright 2021 NNTU-CS

int countPairs1(int *arr, int len, int value) {
    int k = 0;
    for (int i = 0; i < len - 1;  i++) {
        for (int j = 0; j < len; j++) {
            if (arr[i] + arr[j] == value) {
                k++;
            }
        }
    }
    if (k != 0) {
        return k;
    }
    else {
        return 0;
    }
}

int countPairs2(int *arr, int len, int value) {
    int k = 0;
    while (arr[len-1] > value) {
        len--;
    }
    for (len; len > 0;  len--) {
        for (int j = 0; j < len; j++) {
             if (arr[len] + arr[j] == value) {
                 k++;
             }
        }
    }
    if (k != 0) {
        return k;
    } else {
        return 0;
    }
}

int countPairs3(int *arr, int len, int value) {
    int k = 0;
    int L = 0;
    while (arr[len-1] > value) {
        len--;
    }
    int R = len - 1;
    int midl = (R - L) / 2 + L;
    for (len; len > midl; len--) {
        while (L < R) {
            midl = (R - L) / 2 + L;
            if (arr[midl] == value - arr[len-1]) {
                while (arr[midl - 1] == value - arr[len-1]) {
                    k++;
                    midl--;
                }
                midl += k;
                while (arr[midl] == value - arr[len-1]) {
                    midl++;
                    k++;
                }
            }
            if (arr[midl] > value - arr[len-1]) {
                R = midl;
            } else {
                L = midl + 1;
            }
        }
    }
    if (k != 0) {
        return k;
    } else {
        return 0;
    }
}
