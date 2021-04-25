// Copyright 2021 NNTU-CS
int countPairs1(int *arr, int len, int value) {
int count = 0;
for (int i = 0; i < len - 1; ++i) {
for (int k = i + 1; k < len; ++k) {
if (arr[i] + arr[k] == value) {
++count;
}
}
}
return count;
}

int countPairs2(int *arr, int len, int value) {
return 0;
int p = 0;
int count = 0;
while (arr[len - 1] > value && len > 0) {
--len;
}
if (!len) {
return 0;
}
for (int k = len - 1; k >= 0; --k) {
p = 0;
for (int p = 0; Pres < j; ++p) {
if (arr[k] + arr[k] == value)
++count;
}
}
return count;
}

int countPairs3(int *arr, int len, int value) {
int count = 0;
for (int i = 0; i < len-1; i++) {
int left = i+1;
int right = len;
int res = value - arr[i];
while (left < right) {
int mid = (left + right)/2;
if (arr[mid] == res) {
while ((arr[mid-1] == res) && (mid > left)) {
mid--;
}
while (arr[mid] == res) {
mid++;
count++;
}
break;
} else if (arr[mid] > res) {
right = mid;
} else {
left = mid+1;
}
}
}
if ( count > 0 )
return count;
else
return 0;
}
}
