#ifndef CIPHERMODULE_H
#define CIPHERMODULE_H
#include <string>

using namespace std;

class cipherModule{

private:

    //metodos que ayudaran a las demas cosas
    bool validacionTexto(const string mensaje);
    int  obtenerIndiceLetra(const string abc, const char letra);
    string convertirABinario(string &mensaje);


public:
    cipherModule();
    string cifradoCesar(const string mensaje, int saltos);
   // string cifradoXOR(const string mensaje);
    string cifradoVigenere(const string mensaje);
    string convertirXOR(const string &msgBinario, const string &key);

    int countGroups(const string &msgBinario);

    string generarKeyBinario(const string &msgBinario);

    string convertirABinario(const string &mensaje);
};


#endif // CIPHERMODULE_H
