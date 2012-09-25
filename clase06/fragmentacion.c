// #include <iostream>
#include <stdlib.h>
// #include <vector>
#include <stdio.h>
#include <string.h>

// using namespace std;
# define MAX_STRING_LEN 265

int main()
{
    int nroCasos ;
    char linea[MAX_STRING_LEN];
 
    getline(cin,linea);
    nroCasos = atoi(linea.data());
    getline(cin,linea);
    // while(nroCasos--)
    // {
    //     int totalLetras = 0 ;
    //     vector<string> datos;
    //     while(getline(cin,linea) && !linea.empty())
    //     {
    //         totalLetras += linea.size();
    //         datos.push_back(linea);
    //     }
    //     int tamdatos = datos.size();
 
    //     int longitudSol = totalLetras/(tamdatos/2);
 
    //     //fout << "POSIBLES SOLUCIONES"<<endl;
    //     vector<string> solucion;
    //     for(int i = 0; i<tamdatos; i++)
    //         for(int j = i+1; j < tamdatos; j++)
    //             if(datos[i].size()+datos[j].size() == longitudSol)
    //                 solucion.push_back(datos[i]+datos[j]),solucion.push_back(datos[j]+datos[i]);
 
    //     tamdatos = solucion.size();
    //     int marcas[tamdatos];
    //     for(int i = 0; i<tamdatos; i++)
    //         marcas[i] = 0;
    //     string sol ;
    //     int may = -1 ;
    //     for(int i = 0; i<tamdatos; i++)
    //         if(marcas[i]==0)
    //         {
    //             for(int j = i; j < tamdatos; j++)
    //                 if(solucion[i].compare(solucion[j])==0)
    //                     marcas[j]=1, marcas[i]++;
 
    //             if(marcas[i]>may)
    //                 may = marcas[i],sol =  solucion[i];
    //         }
    //     cout<<sol<<endl;
    //     if(nroCasos!=0)
    //         cout<<endl;
    // }
    return 0;
}