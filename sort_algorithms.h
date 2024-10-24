//Aluna:Mylena dos Reis Sobral 202211140016
//Aluno:Carlos Eduardo Maues Mendes 202211140013
#ifndef SORT_ALGORITHMS_H
#define SORT_ALGORITHMS_H

#include <vector>
#include <iostream>

class SortAlgorithms {
public:
    int comparisons;
    int swaps;

    SortAlgorithms();

    void bubbleSort(std::vector<int>& arr);
    void mergeSort(std::vector<int>& arr);
    void bucketSort(std::vector<int>& arr);

private:
    void merge(std::vector<int>& arr, std::vector<int>& left, std::vector<int>& right);
};

#endif
