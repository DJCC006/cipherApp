//#include "mainwindow.h"
#include <iostream>
#include "cipherModule.h"
#include <string>
#include <QApplication>
#include "initialwindow.h"

using namespace std;

   int main(int argc, char *argv[])
   {
      QApplication a(argc, argv);
      initialWindow w;

      w.show();
      return a.exec();
   }


