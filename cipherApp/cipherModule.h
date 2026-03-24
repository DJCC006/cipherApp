#ifndef CIPHERMODULE_H
#define CIPHERMODULE_H
#include <string>
#include <windows.h>
#include <cctype>
#include <limits>
#include <ctime>
#include <cstdlib>

//cosas para XOR
#include<bitset>



using namespace std;

class cipherModule{

private:

    //metodos que ayudaran a las demas cosas
    bool validacionTexto(const string mensaje);
    int  obtenerIndiceLetra(const string abc, const char letra);
    string convertirABinario(string &mensaje);


public:
    //constructor
    cipherModule();

    //Cosas de cifrado Cesar
    string cifradoCesar(const string &mensaje, int saltos);
    int countGroups(const string &msgBinario);

    //Cosas de XOR
    string convertirXOR(const string &msgBinario, const string &key);
    string generarKeyBinario(const string &msgBinario);


    //----CONTENIDO NUEVO A NIVEL LOGICO-----

    //COSAS DE VIGERNE
    string genKeyVigerne(string const &mensaje);
    char getRandomChar();
    string convertirVigerne(string const &mensaje);
    string convertirABinario(const string &mensaje);

    //Metodos de descifrar
    string descifrarCesar(const string &mensajeEncriptado, int saltos);
    string desencriptarXOR(string const &key, string const &msgEncriptado);
    string desencriptarVigerne(string const &key, string const &msgEncriptado);
    string originalBinario(string const &key, string const &msgEncriptado);


};

#endif // CIPHERMODULE_H
