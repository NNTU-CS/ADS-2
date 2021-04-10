// Copyright 2021 NNTU-CS

int countPairs1(int *arr, int len, int value) {
        int k = 0;
                for (int i = 0; i < len-1; i++) {
                for (int j = i + 1; j < len; j++) {
        if (arr[i] + arr[j] == value)
                k++;
        }
        }
        if ( k > 0 )
                return k;
        else
                return 0;
        }

int countPairs2(int *arr, int len, int value) {
        int k = 0;
        int j = len - 1;
                while (arr[j] > value) {
        j--;
        }
                for (j; j > 0; j--) {
                for (int i = 0; i < j; i++) {
                if ((arr[i] + arr[j]) == value)
                k++;
        }
        }
        if ( k > 0 )
                return k;
        else
                return 0;
        }


int countPairs3(int *arr, int len, int value) {
        int k = 0;
                for (int i = 0; i < len-1; i++) {
        int left = i+1;
        int right = len;
        int result = value - arr[i];
                while (left < right) {
        int center = (left + right)/2;
                if (arr[center] == result) {
                while ((arr[center-1] == result) && (center > left)) {
        center--;
        }
                while (arr[center] == result) {
        center++;
        k++;
        }
        break;
        } else if (arr[center] > result) {
        right = center;
        } else {
        left = center+1;
        }
        }
        }
        if ( k > 0 )
                return k;
        else
                return 0;
        }
