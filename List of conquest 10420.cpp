#include <iostream>
#include <sstream>
#include <algorithm>
using namespace std;

struct listaPaises{
    string pais;
    int numeroMujeres;
};

bool compare(listaPaises lhs, listaPaises rhs){
    return lhs.pais < rhs.pais;
}


int main(){
    struct listaPaises lista[2000]{
    };
    int contadorNumeroPaises=0;
    
    int numeroEntradas;
    cin >> numeroEntradas;
    
    for (int i = 0;i<numeroEntradas+1;i++){
        
        //Obtengo nombre y pais
        string entrada;
        string pais;
        string nombre;
        
        getline(cin,entrada);
        istringstream iss(entrada);
        
        iss >> pais;
        
        //Verifica si el país esta en la lista
        bool repetido = false;
        for (int i = 0;i<contadorNumeroPaises;i++){
            if (pais == lista[i].pais){
                lista[i].numeroMujeres++;
                repetido = true;
            }
        }
        if (repetido == false){
            lista[contadorNumeroPaises].pais = pais;
            lista[contadorNumeroPaises].numeroMujeres++;
            contadorNumeroPaises++;
        }
    }
    
    sort(lista, lista+contadorNumeroPaises, compare);
    
    for (int i=1;i<contadorNumeroPaises;i++){
        cout << lista[i].pais << " " << lista[i].numeroMujeres << endl;
    }
    
    return 0;
}