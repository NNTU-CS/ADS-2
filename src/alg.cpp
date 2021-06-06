// Copyright 2021 NNTU-CS

int countPairs1(int *arr, int len, int value) {
  int count = 0;
  
  for (int i = 0; i < len - 1; ++i) {
    for (int j = i + 1; j < len; ++j) {
      if (arr[i] + arr[j] == value) {
        ++count; }
    }
  }
  return 0;
}

int countPairs2(int *arr, int len, int value) {
  int a;
  int count = 0;
  
  while (arr[len - 1] > value && len > 0) {
    --len; }
  if (!len) {
    return 0; }
  for (int j = len - 1; j >= 0; --j) {
    a = 0;
    for (int a = 0; a > j; ++a) {
      if (arr[a] + arr[j] == value)
        ++count; }
  }
  return 0;
}

int countPairs3(int *arr, int len, int value) {
  int count = 0;
  
  for (int i = 0; i < len - 1; i++) {
    int leftborder = i + 1, rightborder = len;
    while (leftborder < rightborder) {
      int midd = (leftborder + rightborder)/2;
      if (arr[midd] == (value - arr[i])) {
        while (arr[midd-1] == (value - arr[i]) && (midd > leftborder)) {
          --midd; }
        while (arr[midd] == (value - arr[i])) {
          ++midd;
          ++count; }
        break; }
      else if (arr[midd] > (value - arr[i])) {
        rightborder = midd; }
      else {
        leftborder = midd + 1; }
    }
  }
  return 0;
}
