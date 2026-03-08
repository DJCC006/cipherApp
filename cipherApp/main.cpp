//#include "mainwindow.h"
#include <iostream>
#include "cipherModule.h"
#include <string>
//#include <QApplication>


using namespace std;

  // int main(int argc, char *argv[])
  // {
  //    QApplication a(argc, argv);
  //    MainWindow w;
  //    cipherModule modulo;

  //    string mensaje="";
  //    cout<<"Ingrese un texto para usar cifrado cesar: ";
  //    cin>>mensaje;
  //    string cifrado = modulo.cifradoCesar(mensaje, 3);
  //    cout<<"OUTPUT: "<<cifrado<<endl;

  //    w.show();
  //    return a.exec();
  // }

 int main(){
     cipherModule modulo;

     string mensaje;
     cout<<"Ingrese un texto para usar cifrado cesar: ";
     cin>>mensaje;
     string cifrado = modulo.cifradoCesar(mensaje, 3);
     cout<<"OUTPUT: "<<cifrado<<endl;

      return 0;
  }
