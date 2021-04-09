// Copyright 2021 NNTU-CS
int countPairs1(int* arr, int len, int value) {
    int chet = 0;
    for (int i = 0; i < len - 1; i++) {
        for (int j = i + 1; j < len; j++) {
            if ((arr[i] + arr[j]) == value)
                chet++;
        }
    }
    return chet;
}

int countPairs2(int* arr, int len, int value) {
    int chet = 0;
    for (int i = len - 1; i > 0; i--) {
        if (arr[i] <= value) {
            for (int j = 0; j < i; j++) {
                if ((arr[i] + arr[j]) == value)
                    chet++;
            }
        }
    }
    return chet;
}

int countPairs3(int* arr, int len, int value) {
    int chet = 0;
    for (int i = 0; i < len - 1; i++) {
        int left = i + 1, right = len, twoElement = value - arr[i];
        while (left < right) {
            int middle = (left + right) / 2;
            if (arr[middle] == twoElement) {
                while ((arr[middle - 1] == twoElement) && (middle > left)) {
                    middle--;
                }
                while (arr[middle] == twoElement) {
                    middle++;
                    chet++;
                }
                break;
            } else if (arr[middle] > twoElement) {
                right = middle;
            } else {
                left = middle + 1;
            }
        }
    }
    return chet;
}
