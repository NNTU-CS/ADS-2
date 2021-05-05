// Copyright 2021 NNTU-CS

int countPairs1(int* arr, int len, int value) {
    int count = 0;
    for (int i = 0; i < len - 1; i++) {
        for (int j = i + 1; j < len; j++) {
            if ((arr[i] + arr[j]) == value) count += 1;
        }
    }
    return count;
}
int countPairs2(int* arr, int len, int value) {
    int count = 0, l = 0, r = len, m;
    while (l < r - 1) {
        m = (l + r) / 2;
        if (arr[m] <= value)
            l = m;
        else
            r = m;
    }
    len = r;
    for (int i = 0; i < len - 1; i++) {
        for (int j = len; j > i; j--) {
            if (arr[i] + arr[j] == value)
                count++;
        }
    }
    return count;
}
int countPairs3(int* arr, int len, int value) {
    int l = 0;
    int r = len;
    int m;
    while (l < r - 1) {
        m = (l + r) / 2;
        if (arr[m] <= value)
            l = m + 1;
        else
            r = m;
    }
    len = r;
    int count = 0;
    for (int i = 0; i < len - 1; i++) {
        int l = i;
        int r = len;
        while (l < r - 1) {
            int m = (l + r) / 2;
            if (arr[i] + arr[m] == value) {
                count++;
                int j = m + 1;
                while (arr[i] + arr[j] == value && j < r) {
                    count++;
                    j++;
                }
                j = m - 1;
                while (arr[i] + arr[j] == value && j > l) {
                    count++;
                    j--;
                }
                break;
            }
            if (arr[i] + arr[m] > value)
                r = m;
            else
                l = m;
        }
    }
    return count;
}
