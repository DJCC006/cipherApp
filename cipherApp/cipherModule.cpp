#include "cipherModule.h"

#include <algorithm>//utilizada para any_of
#include <cctype> //usada para is_digit...funcion propia de libreria cctype
using namespace std;

/*
 * IDEA DE DESARROLLO
 *
 * FUNCIONES AUXILIARES SE REALIZAN CON FUNCIONES MAS OPTIMIZABLES
 * FUNCIONES PRINCIPALES A PURA ARTILLERIA
 *
 *
 *
 * */



bool cipherModule::validacionTexto(const string mensaje){

    //funcion lamda revisa si el caracter es en efecto un caracter
    auto is_digit = [](unsigned char c){
        return std::isdigit(c);
    };

    //any_of revisara si cualquier elemento del rango dado cumple con la condicion de is-digit
    bool tieneNum = std::any_of(mensaje.begin(), mensaje.end(), is_digit);


    if(tieneNum){
        return true;
    }

    return false;
}


int cipherModule::obtenerIndiceLetra(const string abc, const char letra){
    for(int i=0; i<abc.length(); i++){
        char check = abc[i];
        if(letra==check){
            return i;
        }
    }

    return -1;
}


string cipherModule::cifradoCesar(const string mensaje, int saltos){
    /*
     * Cosas a revisar
     * -verificar que no contenga numeros (creo que eso se hace afuera)
     * -verificar el uso de espacios
     * -ignorar el hecho si es mayuscula o minuscula para evaluacion
     * */

    string newMessage="";
    string abc="abcdefghijklmnñopqrstuvwxyz";
    int indexChar=0;
    char letra;
    //recorremos el abecedario
    for(int i=0; i<mensaje.length(); i++){
        //extraigo letra
        letra = mensaje[i];

        //veo su posicion dentro del alfabeto
        int indxletra = obtenerIndiceLetra(abc, letra);

        //calculo la posicion de la nueva letra
        int newIndex = indxletra+saltos;

        //si el nuevo indice es mayor a 26, representando el tamaño del abc en español, iniciando a contar en 0, se vuelve al comiezno
        if(newIndex>26){
            //obtenemos la diferencia al volver al comienzo, calculando la distancia faltante
            int dif= newIndex-26;

            //restamos uno para concordar con el indice
            char newLetra = abc[dif-1];
            newMessage+=newLetra;
        }else{
            char newLetra = abc[newIndex];
            newMessage +=newLetra;
        }

    }

    return newMessage;
}

