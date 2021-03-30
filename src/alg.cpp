// Copyright 2021 NNTU-CS

int countPairs1(int *arr, int len, int value) {
    int count = 0;
    for (int i = 0; i < len - 1; ++i) {
        for (int j = i + 1; j < len; ++j) {
            if (arr[i] + arr[j] == value) count++;
        }
    }
    return count;
}

int countPairs2(int *arr, int len, int value) {
    int count = 0, right = len;
    for (int i = len - 1; i > 0; --i)
        if (arr[i] <= value) {
            right = i;
            break;
        }

    for (int i = right; i > 0; --i)
        for (int j = 0; j < i; ++j)
            if (arr[i] + arr[j] == 50) count++;

    return count;
}

int countPairs3(int *arr, int len, int value) {
    int count = 0, right = 0;
    for (int i = len - 1; i > 0; --i)
        if (arr[i] <= value) {
            right = i;
            break;
        }
    for (int i = right; i > 0; --i) {
        // binary search
        int val = value - arr[i];
        int low = 0, high = i - 1, left = -1;
        right = -1;
        int resLeft = -1, resRight = -1;
        while (low <= high) {
            left = (low + high) / 2;

            if (arr[left] == val && (left == 0 || arr[left - 1] != val)) {
                resLeft = left;
                break;
            } else if (val <= arr[left]) {
                high = left - 1;
            } else {
                low = left + 1;
            }
        }

        low = 0, high = i - 1;

        while (low <= high) {
            right = (low + high) / 2;

            if ((arr[right] == val && (right == 0 || arr[right + 1] != val)) ||
                (arr[right] == val && right == high)) {
                resRight = right;
                break;
            } else if (val < arr[right]) {
                high = right - 1;
            } else {
                low = right + 1;
            }
        }
        if (resLeft == -1 || resRight == -1) {
            count += 0;
        } else if (resLeft == resRight) {
            count++;
        } else {
            count += (resRight - resLeft + 1);
        }
    }
    return count;
}
