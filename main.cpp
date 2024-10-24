//Aluna:Mylena dos Reis Sobral 202211140016
//Aluno:Carlos Eduardo Maues Mendes 202211140013
#include "sort_algorithms.h"
#include <cstdlib>
#include <ctime>
#include <chrono>

using namespace std;
using namespace std::chrono;

int main() {
    SortAlgorithms algo;
    int n;
    string order, sort_choice;

    cout << "Escolha a quantidade de elementos (10, 100, 1000, 10000): ";
    cin >> n;

    cout << "Escolha a disposição dos valores (aleatorio/decrescente): ";
    cin >> order;

    vector<int> arr(n);
    if (order == "decrescente") {
        for (int i = 0; i < n; ++i) {
            arr[i] = n - i;
        }
    } else {
        srand(time(0));
        for (int i = 0; i < n; ++i) {
            arr[i] = rand() % 101;
        }
    }

    cout << "Vetor antes da ordenação: ";
    for (int num : arr) {
        cout << num << " ";
    }
    cout << endl;

    cout << "Escolha o algoritmo de ordenação (bubblesort/mergesort/bucketsort): ";
    cin >> sort_choice;

    auto start = high_resolution_clock::now();
    if (sort_choice == "bubblesort") {
        algo.bubbleSort(arr);
    } else if (sort_choice == "mergesort") {
        algo.mergeSort(arr);
    } else if (sort_choice == "bucketsort") {
        algo.bucketSort(arr);
    } else {
        cout << "Escolha inválida." << endl;
        return 1;
    }
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);

    cout << "Vetor ordenado: ";
    for (int num : arr) {
        cout << num << " ";
    }
    cout << endl;

    cout << "Tempo de execução: " << duration.count() << " microssegundos" << endl;
    cout << "Número de comparações: " << algo.comparisons << endl;
    cout << "Número de trocas: " << algo.swaps << endl;

    return 0;
}
