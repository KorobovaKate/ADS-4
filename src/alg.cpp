// Copyright 2021 NNTU-CS
#include <iostream>
#include <algorithm>
// cppcheck-suppress constParameterPointer
int countPairs1(int *arr, int len, int value) {
    int count = 0;
    for (int i = 0; i < len; i++) {
        for (int j = i + 1; j < len; j++) {
            if (arr[i] + arr[j] == value) {
                count++;
            }
        }
    }
    return count;
}

// cppcheck-suppress constParameterPointer
int countPairs2(int *arr, int len, int value) {
    int count = 0;
    int left = 0;
    int right = len - 1;

    while (left < right) {
        int sum = arr[left] + arr[right];
        if (sum == value) {
            count++;
            left++;
            right--;
            while (left < right && arr[left] == arr[left - 1]) left++;
            while (left < right && arr[right] == arr[right + 1]) right--;
        } else if (sum < value) {
            left++;
        } else {
            right--;
        }
    }
    return count;
}

// cppcheck-suppress constParameterPointer
int countPairs3(int *arr, int len, int value) {
    int count = 0;
    for (int i = 0; i < len; i++) {
        int middle = value - arr[i];
        int left = i + 1, right = len - 1;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (arr[mid] == middle) {
                count++;
                break;
            } else if (arr[mid] < middle) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        while (i + 1 < len && arr[i] == arr[i + 1]) i++;
    }
    return count;
}
