#ifndef __MENU_H__
#define __MENU_H__

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
#include "method_menus.h"
#include "process_files_in_folder.h"

using namespace std;

void method_menu() {
  int method_opc;
  do {
    system("CLS");
    cout << "\t---Menu de seleccion de metodos---";
    cout << "\n\t[1] Bubble sort"
         << "\n\t[2] Select sort"
         << "\n\t[3] Insert sort"
         << "\n\t[4] Shell sort"
         << "\n\t[5] Qick sort"
         << "\n\t[6] Salir" << endl;
    cout << "\nIngrese la opcion deseada: ";
    cin >> method_opc;

    switch (method_opc) {
      case 1:
        bubble_menu();
        break;
      case 2:
        select_menu();
        break;
      case 3:
        insert_menu();
        break;
      case 4:
        shell_menu();
        break;
      case 5:
        quick_menu();
        break;

      default:
        break;
    }
  } while (method_opc != 6);
}

void menu() {
  int opc;
  do {
    system("CLS");
    cout << "\t---Menu de medicion de metodos de ordenamiento---" << endl;
    cout << "\n\t[1] Verificar o crear archivos necesarios"
         << "\n\t[2] Entrar al menu de metodos de ordenamiento"
         << "\n\t[3] Salir" << endl;
    cout << "\nIngrese la opcion deseada: ";
    cin >> opc;
    switch (opc) {
      case 1:
        check_Files();
        break;

      case 2:
        method_menu();
        break;

      default:
        break;
    }

  } while (opc != 3);
}
#endif  // __MENU_H__