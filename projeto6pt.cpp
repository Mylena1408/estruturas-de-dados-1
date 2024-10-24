//Aluna:Mylena dos Reis Sobral 202211140016
//Aluno:Carlos Eduardo Maues Mendes 202211140013
#include "sort_algorithms.h"
#include <algorithm>

SortAlgorithms::SortAlgorithms() : comparisons(0), swaps(0) {}

void SortAlgorithms::bubbleSort(std::vector<int>& arr) {
    int n = arr.size();
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            comparisons++;
            if (arr[j] > arr[j + 1]) {
                std::swap(arr[j], arr[j + 1]);
                swaps++;
            }
        }
    }
}

void SortAlgorithms::mergeSort(std::vector<int>& arr) {
    if (arr.size() > 1) {
        int mid = arr.size() / 2;
        std::vector<int> left(arr.begin(), arr.begin() + mid);
        std::vector<int> right(arr.begin() + mid, arr.end());

        mergeSort(left);
        mergeSort(right);

        merge(arr, left, right);
    }
}

void SortAlgorithms::bucketSort(std::vector<int>& arr) {
    if (arr.empty()) return;

    int max_value = *std::max_element(arr.begin(), arr.end());
    std::vector<std::vector<int>> buckets(max_value + 1);

    for (int num : arr) {
        buckets[num].push_back(num);
    }

    arr.clear();
    for (auto& bucket : buckets) {
        for (int num : bucket) {
            arr.push_back(num);
        }
    }
}

void SortAlgorithms::merge(std::vector<int>& arr, std::vector<int>& left, std::vector<int>& right) {
    int i = 0, j = 0, k = 0;
    while (i < left.size() && j < right.size()) {
        comparisons++;
        if (left[i] <= right[j]) {
            arr[k++] = left[i++];
        } else {
            arr[k++] = right[j++];
        }
    }

    while (i < left.size()) {
        arr[k++] = left[i++];
    }

    while (j < right.size()) {
        arr[k++] = right[j++];
    }
}
