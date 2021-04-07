// Copyright 2021 NNTU-CS

int countPairs1(int *arr, int len, int value) {
int res = 0;
for (int i = 0; i < len - 1; i++) {
for (int j = i + 1; j < len; j++) {
if ((arr[i] + arr[j]) == value) res++;
}
}
  return res;
}

int countPairs2(int *arr, int len, int value) {
int res = 0;
int l = 0;
int r = len - 1;
while ((r - 1) > l) {
int mid = (r + l) / 2;
if (value >= arr[mid]) l = mid;
else
r = mid;
}
len = r - 1;
for (int i = len; i >= 0; i--) {
for (int j = 0; j < i; j++) {
if ((arr[i] + arr[j]) == value) res++;
if ((arr[i] + arr[j]) > value) break;
}
}
  return res;
}

int countPairs3(int *arr, int len, int value) {
int res = 0;
int l = 0;
int r = len - 1;
while ((r - 1) > l) {
int mid = (r + l) / 2;
if (value >= arr[mid]) l = mid;
else
r = mid;
}
len = r - 1;
for (int i = 0; i < len; i++) {
l = i + 1;
r = len - 1;
int res2 = 0;
while (r > l) {
int mid = (r + l) / 2;
if ((value - arr[i]) > arr[mid]) l = mid + 1;
else
r = mid;
}
while ((value - arr[i]) == arr[l]) {
res2++;
l++;
}
res = res + res2;
}
  return res;
}
