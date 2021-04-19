// Copyright 2021 NNTU-CS

int countPairs1(int *arr, int len, int value) {
int i;
int j;
int counter1 = 0;
int r1 = len - 1;
for(i = 0; i < r1; i++) {
for(j = i + 1; j < r1 + 1; j++) {
if((arr[i] + arr[j]) == value) {
counter1++;
}
}
}
if(counter1 >= 0) {
return counter1;
} else {
return 0;
}
}

int countPairs2(int *arr, int len, int value) {
int r2 = len - 1;
int l2 = 0;
int counter2 = 0;
while(arr[r2] > value) {
r2--;
}
while(l2 <= r2) {
if (((arr[r2] + arr[l2]) == value) && (l2 < r2)) {
counter2++;
l2++;
} else if (((arr[r2] + arr[l2]) < value) && (l2 < r2)) {
l2++;
} else {
r2--;
l2 = 0;
}
}
if(counter2 >= 0) {
return counter2;
} else {
return 0;
}
}

int countPairs3(int *arr, int len, int value) {
int counter3 = 0;
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
counter3++;
i--;
}
i = index + 1;
while((i < len) && (len > index) && (arr[i] == valuer)) {
counter3++;
i++;
}
ii++;
}
return counter3;
}
