// Copyright 2021 NNTU-CS

int countPairs1(int *arr, int len, int value) {
  int count1 = 0;
  for (int i = 0; i < len - 1; i++) {
    for (int j = i + 1; j < len; j++) {
      if ((arr[i] + arr[j]) == value) {
        count1++;
      }
    }
  }
  if (count1 > 0) {
    return count1;
  } else {
  return 0;
  }
}

int countPairs2(int *arr, int len, int value) {
  int count2 = 0;
  int rb = len - 1;
  int lb = 0;
  while (arr[rb] > value) {
    rb--;
  }
  while (lb <= rb) {
    if (((arr[lb] + arr[rb]) == value) && (lb < rb)) {
      lb++;
    } else {
      rb--;
      lb = 0;
    }
  }
  if (count2 > 0) {
    return count2;
  } else {
  return 0;
  }
}

int countPairs3(int *arr, int len, int value) {
  int count3 = 0;
  int ind = 0;
  int mid, index, val, lt, rt;
  while(ind < len - 1) {
  val = value - arr[ind];
  lt = ind + 1;
  rt = len - 1;
  while (lt <= rt) {
  mid = lt + (rt - lt) / 2;
  if (arr[mid] > val) {
  rt = mid - 1;
  } else if (arr[mid] < val) {
  lt = mid + 1;
  } else {
  index = mid;
  break;
  }
  }
  int i = index;
  while ((i > ind) && (index >= 0) && (arr[i] == val)) {
  count3++;
  i--;
  }
  i = index + 1;
  while((i < len) && (len > index) && (arr[i] == val)) {
  count3++;
  i++;
  }
  ind++;
  }
  if (count 3 > 0) {
  return count3;
  } else {
  return 0;
  }
}
