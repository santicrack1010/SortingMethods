#ifndef __CHECK_FILES_H__
#define __CHECK_FILES_H__

#include <algorithm>
#include <filesystem>
#include <fstream>
#include <iostream>
#include <numeric>
#include <random>
#include <string>
#include <vector>

#include "create_files.h"

using namespace std;
namespace fs = filesystem;

string folders[] = {"select", "bubble", "quicksort", "shell", "insert"};
string subfolders[] = {"tamanio_5",    "tamanio_10",    "tamanio_100",
                       "tamanio_1000", "tamanio_10000", "tamanio_100000"};

void check_Files() {
  cout << "Verificando existencia de archivos...";
  if (filesystem::exists("output/Metodos_Ordenamientos")) {
    cout << "\nArchivos encontrados ;)" << endl;
    system("PAUSE");
  } else {
    cout << "\nArchivos no encontrados. Creando archivos...";
    for (const auto &folder : folders) {
      for (const auto &subfolder : subfolders) {
        string dir = "output/Metodos_Ordenamientos/" + folder + "/" + subfolder;
        create_directory(dir);

        int size = stoi(subfolder.substr(8));
        vector<int> array(size);

        random_device rd;
        mt19937 g(rd());
        uniform_int_distribution<int> distribution(1, 100000);

        for (int &value : array) {
          value = static_cast<int>(distribution(g));
        }

        sort(array.begin(), array.end());
        create_file(dir + "/ordenado.txt", array);

        sort(array.rbegin(), array.rend());
        create_file(dir + "/inversamente_ordenado.txt", array);

        for (int i = 0; i < 10; ++i) {
          shuffle(array.begin(), array.end(), g);
          create_file(dir + "/aleatorio_" + to_string(i) + ".txt", array);
        }
      }
    }
    cout << "\nArchivos creados, pudes continuar ;)" << endl;
    system("PAUSE");
  }
}

#endif  // __CHECK_FILES_H__