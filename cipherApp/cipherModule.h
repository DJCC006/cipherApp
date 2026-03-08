#ifndef CIPHERMODULE_H
#define CIPHERMODULE_H
#include <string>

using namespace std;

class cipherModule{

private:

    //metodos que ayudaran a las demas cosas
    bool validacionTexto(const string mensaje);
    int  obtenerIndiceLetra(const string abc, const char letra);
    string genASCIIKey(const string mensaje);


public:
    string cifradoCesar(const string mensaje, int saltos);
    string cifradoXOR(const string mensaje);
    string cifradoVigenere(const string mensaje);

};


#endif // CIPHERMODULE_H
