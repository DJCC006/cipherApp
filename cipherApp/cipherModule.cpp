#include "cipherModule.h"

#include <algorithm>//utilizada para any_of
#include <cctype> //usada para is_digit...funcion propia de libreria cctype
#include <limits>
#include <iostream> //por si acaso,,,verificar bien esto

#include <cctype>
#include <limits>
#include <cstdlib>


//libreria para facilitar la conversion de texto a binario
#include<bitset>








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


string cipherModule::cifradoCesar(const string &mensaje, int saltos){
    string newMessage="";
    string abc="abcdefghijklmnñopqrstuvwxyz";

    char letra;
    for(int i=0; i<mensaje.length(); i++){
        letra = mensaje[i];

        letra= tolower(letra);
        cout<<letra<<endl;

        if(letra==' '){
            newMessage+=' ';
        }else{
            int indxletra = obtenerIndiceLetra(abc, letra);

            cout<<"Indice de letra: "<<indxletra<<endl;
            int newIndex = indxletra+saltos;


            if(newIndex>27){
                int dif= newIndex-26;
                char newLetra = abc[dif-2];
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
        char letraMsg = msgBinario[i];
        char letraKey = key[i];

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

    spaces--;

    int groups =spaces+1;
    cout<<"ESPACIOS: "<<spaces<<endl;
    cout<<"GRUPOS: "<<groups<<endl;

    return groups;
}


string cipherModule::generarKeyBinario(const string &msgBinario){
    int max=1;
    int min=0;

    int totalGroups = countGroups(msgBinario);
    int actualGroups =0;
    string keyBinaria="";

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
    string binaryMessage="";
    for(char c: mensaje){
        bitset<8> binary(c);

        string pedazo="";

        pedazo+=binary.to_string();

        binaryMessage= binaryMessage + pedazo +" ";
    }

    return binaryMessage;

}



char cipherModule::getRandomChar(){
    string abc= "abcdefghijklmnñopqrstuvwxyz";
    int max=26;
    int min=0;

    int selector = (rand()%(max-min+1))+min;
    char randChar = abc[selector];

    return randChar;
}




string cipherModule::genKeyVigerne(string const &mensaje){
    string keyVigerne="";

    for(int i=0; i<mensaje.length(); i++){
        char check=mensaje[i];
        if(check==' '){
            keyVigerne+=' ';
        }else{
            char randChar = getRandomChar();
            keyVigerne+=randChar;

        }
    }

    return keyVigerne;
}



string cipherModule::convertirVigerne(string const &mensaje){
    //generacion de key
    string mensajeCifrado ="";
    string abc= "abcdefghijklmnñopqrstuvwxyz";
    string keyVigerne = genKeyVigerne(mensaje);


    cout<<"Key para mensaje ingresado: \n";
    cout<<keyVigerne<<endl;

    for(int i=0; i<mensaje.length(); i++){
        char charOriginal = mensaje[i];
        if(charOriginal==' '){
            mensajeCifrado+=' ';
        }else{
            int indxCharOriginal = obtenerIndiceLetra(abc, charOriginal);

            char charKey = keyVigerne[i];
            int indxCharKey = obtenerIndiceLetra(abc, charKey);

            cout<<"Indice char original: "<<indxCharOriginal<<endl;
            cout<<"Indice char Key: "<<indxCharKey<<endl;


            int newIndx = indxCharOriginal+indxCharKey;
            cout<<"Nuevo indice cifrado: "<<newIndx<<endl;

            if(newIndx>27){
                int indxAcortado = newIndx-27;
                char charCifrado = abc[indxAcortado];
                cout<<"Indice acortado: "<<indxAcortado<<endl;
                mensajeCifrado+=charCifrado;
            }else{
                char charCifrado = abc[newIndx];
                mensajeCifrado+=charCifrado;
            }
        }
    }

    cout<<"Mensaje cifrado en Vigerne: \n";
    cout<<mensajeCifrado<<endl;


    return mensajeCifrado;
}


string cipherModule::descifrarCesar(const string &mensajeEncriptado, int saltos){

    string newMessage="";
    string abc="abcdefghijklmnñopqrstuvwxyz";

    int indexChar=0;
    char letra;
    //recorremos el abecedario
    for(int i=0; i<mensajeEncriptado.length(); i++){
        //extraigo letra
        letra = mensajeEncriptado[i];

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
            int newIndex = indxletra-saltos;

            //verificamos si el salot cae deebajo del 0
            if(newIndex<0){
                //Al caer de cero, volvemos al tope,
                int dif= newIndex+26;

                //restamos uno para concordar con el indice
                char newLetra = abc[dif]; //restamos dos por aparente bug de salto      -2
                newMessage+=newLetra;
            }else{
                char newLetra = abc[newIndex];
                newMessage = newMessage + newLetra;
            }
        }

    }

    return newMessage;

}



string cipherModule::desencriptarXOR(string const &key, string const &msgEncriptado){
    //metodo que hara la comparacion XOR como tal para devolver el binario del original
    string mensajeOriginal="";
    string binarioOriginal = originalBinario(key, msgEncriptado);

    for(int i=0; i+8 <= binarioOriginal.length();i+=8){
        string bit = binarioOriginal.substr(i,8);

        //transformamos a bit de nuevo para poderlo usar
        bitset<8> bits(bit);

        //casteo a caracter
        char letra = static_cast<char>(bits.to_ulong());

        //unimos a la cadena mayor
        mensajeOriginal+=letra;
    }

    return mensajeOriginal;

}

string cipherModule::desencriptarVigerne(string const &key, string const &msgEncriptado){
    string originalmsg="";
    string abc = "abcdefghijklmnñopqrstuvwxyz";
    int length = msgEncriptado.length();
    for(int i=0; i<length; i++){
        //obtenemos letra
        char letraMSG = msgEncriptado[i];
        char letraKEY = key[i];

        if(letraMSG==' ' && letraKEY==' '){
            originalmsg+=" ";
        }else{
            //verificamos indices
            int indxActual = obtenerIndiceLetra(abc, letraMSG);
            int indxKey = obtenerIndiceLetra(abc, letraKEY);

            //obtneemos el indice original
            int indxOriginal = indxActual-indxKey;


            //verificacion de no pasarnos
            if(indxOriginal <0){
                int indxAjustado= indxOriginal+27;
                char charOriginal = abc[indxAjustado];
                originalmsg+=charOriginal;
            }else{
                char charOriginal = abc[indxOriginal];
                originalmsg+=charOriginal;
            }
        }
    }

    return originalmsg;

}


string cipherModule::originalBinario(string const &key, string const &msgEncriptado){
    string originalBinary="";
    int length = msgEncriptado.length();

    //controladores de indices
    int keyControlador=0;//avanzamos por seguridad
    int msgControlador=0;


    while(msgControlador<length){

        //saltar espacios en mensaje original
        if(msgEncriptado[msgControlador]==' '){
            msgControlador++;
            continue;
        }


        //saltar espacios en key
        if(keyControlador< key.length() && key[keyControlador]==' '){
            keyControlador++;
            continue;
        }

        if(keyControlador< key.length()){
            if(msgEncriptado[msgControlador]== key[keyControlador]){
                originalBinary+="0";
            }else{
                originalBinary+="1";
            }
            keyControlador++;
        }

        msgControlador++;


    }

    return originalBinary;
}
