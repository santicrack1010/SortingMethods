#ifndef __METHOD_MENUS_H__
#define __METHOD_MENUS_H__

#include <algorithm>
#include <chrono>
#include <filesystem>
#include <fstream>
#include <iostream>
#include <numeric>
#include <random>
#include <string>
#include <vector>

#include "check_files.h"
#include "process_files_in_folder.h"

void bubble_menu() {
  cout << "\t---Metodo seleccionado: Bubble Sort---";
  cout << "\n\tLeyendo carpeta de buble sort..." << endl;

  string methodFolderPath = "output/Metodos_Ordenamientos/bubble";
  ///////////////
  for (const auto& subfolder :
       filesystem::directory_iterator(methodFolderPath)) {
    if (subfolder.is_directory()) {
      cout << "Subcarpeta encontrada: " << subfolder.path() << endl;
    }
  }
  //////////////
  system("PAUSE");

  processFilesInFolder(methodFolderPath, "bubble");
  system("PAUSE");
}

void select_menu() {
  cout << "\t---Metodo seleccionado: Select Sort---";
  cout << "\n\tLeyendo carpeta de select sort..." << endl;

  string methodFolderPath = "output/Metodos_Ordenamientos/select";
  ///////////////
  for (const auto& subfolder :
       filesystem::directory_iterator(methodFolderPath)) {
    if (subfolder.is_directory()) {
      cout << "Subcarpeta encontrada: " << subfolder.path() << endl;
    }
  }
  //////////////
  system("PAUSE");

  processFilesInFolder(methodFolderPath, "select");
  system("PAUSE");
}

void insert_menu() {
  cout << "\t---Metodo seleccionado: Insert Sort---";
  cout << "\n\tLeyendo carpeta de insert sort..." << endl;

  string methodFolderPath = "output/Metodos_Ordenamientos/insert";
  ///////////////
  for (const auto& subfolder :
       filesystem::directory_iterator(methodFolderPath)) {
    if (subfolder.is_directory()) {
      cout << "Subcarpeta encontrada: " << subfolder.path() << endl;
    }
  }
  //////////////
  system("PAUSE");

  processFilesInFolder(methodFolderPath, "insert");
  system("PAUSE");
}

void shell_menu() {
  cout << "\t---Metodo seleccionado: Shell Sort---";
  cout << "\n\tLeyendo carpeta de shell sort..." << endl;

  string methodFolderPath = "output/Metodos_Ordenamientos/shell";
  ///////////////
  for (const auto& subfolder :
       filesystem::directory_iterator(methodFolderPath)) {
    if (subfolder.is_directory()) {
      cout << "Subcarpeta encontrada: " << subfolder.path() << endl;
    }
  }
  //////////////
  system("PAUSE");

  processFilesInFolder(methodFolderPath, "shell");
  system("PAUSE");
}

void quick_menu() {
  cout << "\t---Metodo seleccionado: Quick Sort---";
  cout << "\n\tLeyendo carpeta de quick sort..." << endl;

  string methodFolderPath = "output/Metodos_Ordenamientos/quicksort";
  ///////////////
  for (const auto& subfolder :
       filesystem::directory_iterator(methodFolderPath)) {
    if (subfolder.is_directory()) {
      cout << "Subcarpeta encontrada: " << subfolder.path() << endl;
    }
  }
  //////////////
  system("PAUSE");

  processFilesInFolder(methodFolderPath, "quicksort");
  system("PAUSE");
}
#endif  // __METHOD_MENUS_H__