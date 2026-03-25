//#include "mainwindow.h"
#include <iostream>
#include "cipherModule.h"
#include <string>
#include <QApplication>
#include "initialwindow.h"
//#include <windows.h>
#include <locale.h>

using namespace std;

   int main(int argc, char *argv[])
   {
       setlocale(LC_ALL, ".UTF8");
      QApplication a(argc, argv);
       cipherModule* module = new cipherModule();
      initialWindow w(module);

      w.show();
      return a.exec();
   }


