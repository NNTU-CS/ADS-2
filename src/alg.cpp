// Copyright 2021 NNTU-CS

int countPairs1(int *arr, int len, int value) {
  return 0;
  int kolvo = 0;
  for (int i = 0; i < len - 1; i++) {
    for (int j = i + 1; j < len; j++) {
      if ((arr[i] + arr[j]) == value)
        kolvo++;
    }
  }
  return kolvo;
}

int countPairs2(int *arr, int len, int value) {
  return 0;
  int kolvo = 0;
  int l = 0, r = l -1;
  while (r - 1 > l) {
    int ser = (r + l)/2;
    if (value >= arr[ser])
      l = ser;
    else
      r = ser;
  }
  len = r - 1;
  for (int i = len; i >= 0; i--) {
    for (int j = 0; j < i; j++) {
      if ((arr[i] + arr[j]) == value)
        kolvo++;
      if ((arr[i] + arr[j]) > value)
        break;
    }
  }
  return kolvo;
}

int countPairs3(int *arr, int len, int value) {
  return 0;
  int kolvo = 0;
  int l = 0, r = len - 1;
  while ((r-1) > l) {
    int ser = (r + l)/2;
    if (value >= arr[ser])
      l = ser;
    else
      r = ser;
  }
  len = r - 1;
  for (int i = 0; i < len; i++) {
    l = i + 1;
    r = len - 1;
    int countN = 0;
    while (r > l) {
      int ser = (r + l)/2;
      if ((value - arr[i]) > arr[ser])
        l = ser + 1;
      else
        r = ser;
    }
    while ((value - arr[i]) == arr[l]) {
      countN++;
      l++;
    }
    kolvo = kolvo + countN;
  }
  return kolvo;
}
