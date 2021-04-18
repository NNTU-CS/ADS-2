// Copyright 2021 NNTU-CS
int countPairs1(int *arr, int len, int value) {
int count = 0;
int i;
int j;
int r = len - 1;	
int r = len - 1;
for(i = 0; i < r; i++) {
for(j = i + 1; j < r + 1; j++) {
if((arr[i] + arr[j]) == value) {
count++;
}
}
}
return count;
}

int countPairs2(int *arr, int len, int value) {
int rg = len - 1;
int lg = 0;
int count = 0;
while(arr[rg] > value) {
rg--;
}
while(lg <= rg) {
if (((arr[rg] + arr[lg]) == value) && (lg < rg)) {
count++;
lg++;
} else if (((arr[rg] + arr[lg]) < value) && (lg < rg)) {
lg++;
} else {
rg--;
lg = 0;
}
}
return count;
}

int countPairs3(int *arr, int len, int value) {
int count = 0;
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
} else if (arr[med] < valuer) {
l = med + 1;
} else {
index = med;
break;
}
}
int i = index;
while ((i > ii) && (index >= 0) && (arr[i] == valuer)) {
count++;
i--;
}
i = index + 1;
while((i < len) && (len > index) && (arr[i] == valuer)) {
count++;
i++;
}
ii++;
}
return count;
}
