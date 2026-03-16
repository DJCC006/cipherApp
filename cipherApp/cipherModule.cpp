#include "cipherModule.h"

#include <algorithm>//utilizada para any_of
#include <cctype> //usada para is_digit...funcion propia de libreria cctype
#include <limits>
#include <iostream> //por si acaso,,,verificar bien esto

//libreria para facilitar la conversion de texto a binario
#include<bitset>



#include <cctype>
#include <limits>
#include <ctime>
#include <cstdlib>




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


cipherModule::cipherModule(){}


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
     * -verificar que no contenga numeros (creo que eso se hace afuera)...X
     * -verificar el uso de espacios...x
     * -ignorar el hecho si es mayuscula o minuscula para evaluacion...x
     * */

    string newMessage="";
    string abc="abcdefghijklmnñopqrstuvwxyz";


    int indexChar=0;
    char letra;
    //recorremos el abecedario
    for(int i=0; i<mensaje.length(); i++){
        //extraigo letra
        letra = mensaje[i];

        //manejo de letra
        letra= tolower(letra);
        cout<<letra<<endl;

        if(letra==' '){
            //considerando caso de espacios
            newMessage+=' ';
        }else{

            //veo su posicion dentro del alfabeto
            int indxletra = obtenerIndiceLetra(abc, letra);

            cout<<"Indice de letra: "<<indxletra<<endl;
            //calculo la posicion de la nueva letra
            int newIndex = indxletra+saltos;

            //si el nuevo indice es mayor a 26, representando el tamaño del abc en español, iniciando a contar en 0, se vuelve al comiezno
            if(newIndex>27){
                //obtenemos la diferencia al volver al comienzo, calculando la distancia faltante
                int dif= newIndex-26;

                //restamos uno para concordar con el indice
                char newLetra = abc[dif-2]; //restamos dos por aparente bug de salto
                newMessage+=newLetra;
            }else{
                char newLetra = abc[newIndex];
                newMessage = newMessage + newLetra;
            }
        }
    }

    return newMessage;
}



string cipherModule::convertirXOR(const string &msgBinario, const string &key){
    string msgXOR="";

    for(int i=0; i<msgBinario.length(); i++){

        //se extrae el mismo indice de antes
        char letraMsg = msgBinario[i];

        char letraKey = key[i];

        //como en teoria son de la misma longitud, no habria conflicto
        //CONVERSION EN BASE A SEMEJANZA -TIPO XOR
        if(letraMsg==' '){
            msgXOR+=" ";
        }else if(letraMsg==letraKey){
            msgXOR+="0";
        }else if(letraMsg!= letraKey){
            msgXOR+="1";
        }

    }


    return msgXOR;

}


//esta funcion interna nos dara una idea de cuantos grupos binarios hay
int cipherModule::countGroups(const string &msgBinario){

    int spaces=0;
    for(char c: msgBinario){
        if(c==' '){
            spaces++;
        }
    }

    spaces--;//restamos uno para control

    int groups =spaces+1;
    //la idea es que siempre abra un total de conjuntos numericos igual al total de espacios +1
    cout<<"ESPACIOS: "<<spaces<<endl;
    cout<<"GRUPOS: "<<groups<<endl;


    //FIX LA FORMA EN COMO SE GENERAN LOS GRUPOS,,,,,SE GENERA UNO DE MAS

    return groups;
}


string cipherModule::generarKeyBinario(const string &msgBinario){
    int max=1;
    int min=0;


    //se tiene que repetir hasta que se tenga el mismo size que el original
    //se tiene que considerar el espacio de 8

    int totalGroups = countGroups(msgBinario);
    int actualGroups =0;
    string keyBinaria="";
    //esto cada vez que se repita ira generando bloques de 8 numeros en binario, a manera de generar
    //una key de la misma longitud del mensaje normal


    while(actualGroups<totalGroups){
        string miniGroup="";
        for(int i=0; i<8; i++){
            int eleccion_rand= (rand()%(max-min+1))+min;
            miniGroup+= to_string(eleccion_rand);
        }

        miniGroup+=" ";
        keyBinaria+=miniGroup;
        actualGroups++;

    }

    return keyBinaria;
}

string cipherModule::convertirABinario(const string &mensaje){


    //uso de un for - each para recorrer todo el mensaje
    string binaryMessage="";
    for(char c: mensaje){

        //inicializacion previa
        bitset<8> binary(c);

        string pedazo="";

        //un objeto de binary set ya trae su propio metodo de to string
        pedazo+=binary.to_string();

        binaryMessage= binaryMessage + pedazo +" ";

        /*
         * VER SI NO HAY PROBLEMAS POR NO EVALUAR LOS ESPACIOS
         *DE HECHO ES MEJOR ASI, YA QUE HASTA EL ESPACIO ES CONVERTIRDO A BINARIO
         *
         * */

    }

    return binaryMessage;

}






