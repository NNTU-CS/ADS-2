//Copyright 2021 NNTU-CS

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
    int count = 0, r = len - 1;
    while ((arr[0] + arr[r]) > value) {
        r--;
    }
    for (int i = 0; i < (r); i++) {
        for (int j = i + 1; j < (r + 1); j++) {
            if ((arr[i] + arr[j]) == value) {
                count++;
            }
        }
    }
    return count;
}

int countPairs3(int *arr, int len, int value) {
    int count = 0, l = 0, r = len;
    int med = (l + r) / 2, left = med, right = med;
    for (int i = 0; i < len; i++) {
        while (r >= l) {
            med = (l + r) / 2;
            left = med - 1;
            right = med + 1;
            if (arr[i] + arr[med] == value) {
                if (i != med) {
                    count++;
                }
                while (((arr[i] + arr[left]) == value) && (i != left)) {
                    count++;
                    left--;
                }
                while (((arr[i] + arr[right]) == value) && (i != right)) {
                    count++;
                    right++;
                }
                r = l - 1;
                } else if ((arr[i] + arr[med]) < value) {
                        l = med + 1;
                    } else if ((arr[i] + arr[med]) > value) {
                                r = med - 1;
                            }
        }
        arr[i] = value + 1;
        r = len;
        l = i + 1;
    }
    return count;
}
