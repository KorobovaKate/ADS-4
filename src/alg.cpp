// Copyright 2021 NNTU-CS
// cppcheck-suppress constParameterPointer
int countPairs1(int *arr, int len, int value) {
  int kol = 0;
  for (int i = 0; i < len; i++) {
    if (i > 0 && arr[i] == arr[i - 1]) {
      continue;
    }
    for (int j = i + 1; j < len; j++) {
      if (j > i + 1 && arr[j] == arr[j - 1]) {
        continue;
      }
      if (arr[i] + arr[j] == value) {
        kol++;
      }
    }
  }
  return kol;
}

// cppcheck-suppress constParameterPointer
int countPairs2(int *arr, int len, int value) {
  int kol = 0;
  int left = 0;
  int right = len - 1;
  while (left < right) {
    int sum = arr[left] + arr[right];
    if (sum == value) {
      kol++;
      left++;
      right--;
    } else if (sum < value) {
      left++;
    } else {
      right--;
    }
  }
  return kol;
}

// cppcheck-suppress constParameterPointer
int countPairs3(int *arr, int len, int value) {
  int kol = 0;
  for (int i = 0; i < len; i++) {
    int vtor = value - arr[i];
    int left = i + 1;
    int right = len - 1;
    while (left <= right) {
      int middle = left + (right - left) / 2;
      if (arr[middle] == vtor) {
        kol++;
        int povt = middle - 1;
        while (povt >= left && arr[povt] == vtor) {
          kol++;
          povt--;
        }
        povt = middle + 1;
        while (povt <= right && arr[povt] == vtor) {
          kol++;
          povt++;
        }
        break;
      } else if (arr[middle] < vtor) {
        left = middle + 1;
      } else {
        right = middle - 1;
      }
    }
  }
  return kol;
}
