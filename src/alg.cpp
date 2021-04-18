// Copyright 2021 NNTU-CS

int countPairs1(int *arr, int len, int value) {
 int count = 0;
 for (int i = 0; i < len - 1; i++) {
  for (int j = i + 1; j < len; j++) {
     if (arr[i] + arr[j] == value && arr[i] >= 0 && arr[j] >= 0) {
       count++;
     }
   }
 }
 return count;
}

int countPairs2(int *arr, int len, int value) {
 int count = 0;
 int l = 0;
 int r = len - 1;
 while (arr[r] > value) {
   r--;
 }
 while (l < r) {
   if (arr[l] + arr[r] == value && arr[l] >= 0 && arr[r] >= 0) {
     count++;
     l++;
   }
   else if (arr[l] + arr[r] < value && arr[l] >= 0 && arr[r] >= 0) {
     l++;
   }
   else {
     r--;
     l = 0;
   }
 }
 return count;
}

int countPairs3(int *arr, int len, int value) {
 int count = 0;
 int r = len - 1;
 int l = 0;
 while(arr[r] > value) {
   len--;
 }
 int ii = 0;
 int med, index, valuer, l, r;
 while(ii < len - 1) {
   valuer = value - arr[ii];
   l = ii + 1;
   r = len - 1;
   while (l <= r) {
     med = l + (r - l) / 2;
     if (arr[med] > valuer) {
        r = med - 1;
     } 
     else if (arr[med] < valuer) {
       l = med + 1;
     } 
     else {
       index = med;
       break;
   }
 }
 int i = index;
 while ((i > ii) && (index >= 0) && (arr[i] == valuer)) {
   c3++;
   i--;
 }
 i = index + 1;
 while((i < len) && (len > index) && (arr[i] == valuer)) {
   c3++;
   i++;
 }
   ii++;
 }
 return c3;  
}
