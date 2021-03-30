// Copyright 2021 NNTU-CS

int cbinsearch(int* arr, int size, int value, unsigned int i) {
    int count = 0, min = i, max = size - 1, mid = i;
    while (min <= max) {
        mid = (min + max) / 2;
        if (arr[mid] == value && mid != i) {
            count++;
            break;
        }
        value < arr[mid] ? max = mid - 1 : min = mid + 1;
    }
    int l = 1;
    bool bo1 = true, bo2 = true;
    if (count) {
        while (bo1 || bo2) {
            if (mid + l < size) {
                arr[mid + l] == value ? count++ : bo1 = false;
            }
            if (mid - l >= 0) {
                arr[mid - l] == value ? count++ : bo2 = false;
            }
            if (mid + l >= size && mid - l < 0) break;
            l++;
        }
    }
    return count;
}

int mod(int i) {
    if (i > 0) {
        return i;
    } else {
        return -i;
    }
}

int countPairs1(int* arr, int len, int value) {
    unsigned int count = 0;
    for (int i = 0; i < len - 1; i++) {
        for (int j = i + 1; j < len; j++) {
            if (arr[i] + arr[j] == value && i != j) {
                count++;
            }
        }
    }
    return count;
}

int countPairs2(int* arr, int len, int value) {
    unsigned int count = 0, i = 0, left = 0, right = len - 1;
    while (left < right) {
        i = 1;
        while (true) {
            if (arr[right] > value || arr[left] + arr[right] > value) {
                right--;
            } else {
                break;
            }
        }
        while (left + i <= right) {
            if (arr[left] + arr[left + i] == value) count++;
            i++;
        }
        left++;
    }
    return count;
}
int countPairs3(int* arr, int len, int value) {
    unsigned int count = 0;
    for (int i = 0; i < len; i++) {
        count += cbinsearch(arr, len, mod(value - arr[i]), i);
    }
    return count;
}
