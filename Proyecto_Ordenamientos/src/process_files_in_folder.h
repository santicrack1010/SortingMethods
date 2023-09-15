#ifndef __PROCESSFILESINFOLDER_H__
#define __PROCESSFILESINFOLDER_H__

#include <algorithm>
#include <filesystem>
#include <fstream>
#include <iostream>
#include <numeric>
#include <random>
#include <string>
#include <vector>

#include "check_files.h"

using namespace std;
namespace fs = filesystem;

void bubbleSort(vector<int>& arr) {
  int n = arr.size();
  for (int i = 0; i < (n - 1); i++) {
    for (int j = 0; j < n - i - 1; j++) {
      if (arr[j] > arr[j + 1]) {
        swap(arr[j], arr[j + 1]);
      }
    }
  }
}

void selectSort(vector<int>& arr) {
  int n = arr.size();
  for (int i = 0; i < n - 1; i++) {
    int minIndex = i;
    for (int j = i + 1; j < n; j++) {
      if (arr[j] < arr[minIndex]) {
        minIndex = j;
      }
    }
    if (minIndex != i) {
      swap(arr[i], arr[minIndex]);
    }
  }
}

void insertSort(vector<int>& arr) {
  int n = arr.size();
  for (int i = 1; i < n; i++) {
    int key = arr[i];
    int j = i - 1;
    while (j >= 0 && arr[j] > key) {
      arr[j + 1] = arr[j];
      j--;
    }
    arr[j + 1] = key;
  }
}

void shellSort(vector<int>& arr) {
  int n = arr.size();
  for (int gap = n / 2; gap > 0; gap /= 2) {
    for (int i = gap; i < n; i++) {
      int temp = arr[i];
      int j;
      for (j = i; j >= gap && arr[j - gap] > temp; j -= gap) {
        arr[j] = arr[j - gap];
      }
      arr[j] = temp;
    }
  }
}

int partition(vector<int>& arr, int low, int high) {
  int pivot = arr[high];
  int i = low - 1;
  for (int j = low; j < high; j++) {
    if (arr[j] < pivot) {
      i++;
      swap(arr[i], arr[j]);
    }
  }
  swap(arr[i + 1], arr[high]);
  return i + 1;
}

void quickSort(vector<int>& arr, int low, int high) {
  if (low < high) {
    int pi = partition(arr, low, high);
    quickSort(arr, low, pi - 1);
    quickSort(arr, pi + 1, high);
  }
}

void applySortingMethod(vector<int>& arr, const string& sortingMethod) {
  if (sortingMethod == "bubble") {
    bubbleSort(arr);
  }
  if (sortingMethod == "select") {
    selectSort(arr);
  }
  if (sortingMethod == "insert") {
    insertSort(arr);
  }
  if (sortingMethod == "shell") {
    shellSort(arr);
  }
  if (sortingMethod == "quicksort") {
    int low = 0;
    int high = arr.size() - 1;
    quickSort(arr, low, high);
  }
}

void processFilesInFolder(const string& folderPath,
                          const string& sortingMethod) {
  for (const auto& subfolder : filesystem::directory_iterator(folderPath)) {
    if (subfolder.is_directory()) {
      for (const auto& entry : filesystem::directory_iterator(subfolder)) {
        if (entry.is_regular_file()) {
          if (entry.path().extension() == ".txt") {
            string filePath = entry.path().string();
            ifstream file(filePath);
            vector<int> data;

            int value;
            while (file >> value) {
              data.push_back(value);
            }

            // Medir el tiempo antes de aplicar el método de ordenamiento
            auto start_time = chrono::high_resolution_clock::now();

            applySortingMethod(data, sortingMethod);

            // Medir el tiempo después de aplicar el método de ordenamiento
            auto end_time = chrono::high_resolution_clock::now();
            auto duration =
                chrono::duration_cast<chrono::seconds>(end_time - start_time);

            // Sobrescribir el archivo original con los datos ordenados
            ofstream outFile(filePath);
            for (const int& val : data) {
              outFile << val << " ";
            }

            // Mostrar un mensaje indicando que el archivo ha sido ordenado y
            // modificado
            cout << "===============";
            cout << "\nArchivo " << entry.path().filename()
                 << " ordenado y modificado.";
            cout << " Tiempo de ordenamiento: " << duration.count()
                 << " segundos." << endl;
          }
        }
      }
    }
  }
}

#endif  // __PROCESSFILESINFOLDER_H__