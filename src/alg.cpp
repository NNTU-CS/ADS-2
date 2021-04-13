// Copyright 2021 NNTU-CS

int countPairs1(int *arr, int len, int value) {
        int count = 0;
                for (int i = 0; i < len-1; i++) {
                for (int j = i + 1; j < len; j++) {
        if (arr[i] + arr[j] == value)
                count++;
        }
        }
        if ( count > 0 )
                return count;
        else
                return 0;
        }

int countPairs2(int *arr, int len, int value) {
        int count = 0;
        int j = len - 1;
                while (arr[j] > value) {
        j--;
        }
                for (j; j > 0; j--) {
                for (int i = 0; i < j; i++) {
                if ((arr[i] + arr[j]) == value)
                count++;
        }
        }
        if ( count > 0 )
                return count;
        else
                return 0;
        }


int countPairs3(int *arr, int len, int value) {
        int count = 0;
                for (int i = 0; i < len-1; i++) {
        int left = i+1;
        int right = len;
        int res = value - arr[i];
                while (left < right) {
        int center = (left + right)/2;
                if (arr[center] == res) {
                while ((arr[center-1] == res) && (center > left)) {
        center--;
        }
                while (arr[center] == res) {
        center++;
        count++;
        }
        break;
        } else if (arr[center] > res) {
        right = center;
        } else {
        left = center+1;
        }
        }
        }
        if ( count > 0 )
                return count;
        else
                return 0;
        }
