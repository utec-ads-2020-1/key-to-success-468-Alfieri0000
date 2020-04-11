#include <iostream>
#include <string>
#include <sstream>
#include <algorithm>
using namespace std;


struct asociacion{
  char caracter =32;
  int numRepeticiones =0;
};


bool compare(asociacion lhs, asociacion rhs){
    return lhs.numRepeticiones > rhs.numRepeticiones;
}


string decodificador(string text,string codedText){
    string resultado;
    
    struct asociacion normalText[text.length()];
    struct asociacion encodedText[codedText.length()];
    
    
    //Ordena y coloca, el numero de veces que se repite cada caracter en un struct (texto normal)
    //NOTA: Intente colocar esto como función, tuve problemas accediendo a un dato especifico de un struct.
    for(int i=0;i<text.length();i++) {
        bool repetido = false;
        for (int j=0;j<text.length();j++){
            if (text[i] == normalText[j].caracter){
                normalText[j].numRepeticiones++;
                repetido = true;
            }
        }
        if (repetido == false){
            normalText[i].caracter = text[i];
            normalText[i].numRepeticiones++;
        }
    }
    sort(normalText, normalText+text.length(), compare);
    
    //Ordena y coloca, el numero de veces que se repite cada caracter en un struct (texto codificado)
    for(int i=0;i<codedText.length();i++) {
        bool repetido = false;
        for (int j=0;j<codedText.length();j++){
            if (codedText[i] == encodedText[j].caracter){
                encodedText[j].numRepeticiones++;
                repetido = true;
            }
        }
        if (repetido == false){
            encodedText[i].caracter = codedText[i];
            encodedText[i].numRepeticiones++;
        }
    }
    sort(encodedText, encodedText+codedText.length(), compare);
    
    int indicador=0;
    for(int i=0;i<codedText.length();i++){
        if (encodedText[i].numRepeticiones > 0){
            indicador++;
        }
    }
    
    //Generar el resultado y agregarlo
    for(int i = 0;i<codedText.length();i++){
        for (int j=0;j<indicador;j++){
            if (codedText[i] == encodedText[j].caracter){
                resultado = resultado + normalText[j].caracter;
            }
        }
    }
    
    return resultado;
}



int main(){
    string S_numeroCasos;
    int numeroCasos;

    getline(cin,S_numeroCasos);
    stringstream geek(S_numeroCasos);
    geek >> numeroCasos;
    
    string resultados[numeroCasos];
    int cont_resultados;
    
    for (int i = 0;i<numeroCasos;i++){
        string trash;
        string text;
        string encodedText;
        
        getline(cin,trash);
        getline(cin,text);
        getline(cin,encodedText);
        
        resultados[cont_resultados] = decodificador(text,encodedText);
        cont_resultados++;
    }
    
    for (int i = 0;i<cont_resultados;i++){
        cout << resultados[i] << endl << endl;
    }
    
    return 0;
}