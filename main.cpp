/*
 * PRACTICA EXAMEN 3 EMMANUEL NARANJO
 */
#include <iostream>
#include <list>
#include <forward_list>
#include <array>
#include <vector>
#include <string>
#include <math.h>
using namespace std;

//Global
const int tam=5;
//Estructuras
struct Semiprimo{
    int encontrado;
    int primo1;
    int primo2;
};
//Definicion de funciones
//1
int extraer_num(int num, int inicio, int fin){
    string cadena, resultado;
    cadena=to_string(num);
    for(int i=inicio-1;i<fin;i++){
        resultado+=cadena[i];
    }
    int extraido=stoi(resultado, nullptr,10);
    return extraido;
}
int base10_a_otras_bases(int numero, int inicial, int final, int base){
    int extraido=extraer_num(numero,inicial,final);
    int resultado=0;
    int aux=0;
    while(extraido!=0){
        resultado+=(extraido%base)*pow(10,aux);
        aux++;
        extraido/=base;
    }
    return resultado;
}
//3
forward_list<float> extraer_numeros(string frase){
    forward_list<float> listNum,Imprimir;
    string resultado;
    int i=0;
    while(i<frase.size()){
        if (isdigit(frase[i])!=0){
            resultado+=frase[i];}

        if(frase[i]=='.' &&isdigit(frase[i-1])!=0 &&isdigit(frase[i+1])!=0){
            resultado+=frase[i];}
        if(resultado != ""){
            if((isdigit(frase[i-1])!=0 && isalpha(frase[i])!=0)){
                float num=stof(resultado, nullptr);
                    listNum.push_front(num);
                resultado="";
            }
            if(frase[i]==' '){
                float num=stof(resultado, nullptr);
                listNum.push_front(num);
                resultado="";}
        }
        i++;
    }
    float num=stof(resultado, nullptr);
    listNum.push_front(num);
    for(auto elemento:listNum){Imprimir.push_front(elemento);}
    return Imprimir;
}
void extraer_numeros_imprimir(forward_list<float>listaNum){
    cout<<"Numeros encontrados: "<<endl;
    for(auto elemento:listaNum){
        cout<<elemento<<"  ";
    }
}
//4
int factorial(int num){
    int factorial=1;
    int i=1;
    while (i<=num){
        factorial*=i;
        i++;
    }
    return factorial;
}
vector<vector<int>> triangulo_de_pascal(int cantidad){
    vector<int>nivel;
    vector<vector<int>> trianguloPascal;
    int numero;
    int n=1;
    while(n<=cantidad){
        int k=1;
        while (k<=n) {
            numero = factorial(n - 1) / (factorial(k - 1) * factorial(((n - 1) - (k - 1))));
            nivel.push_back(numero);
            k++;
        }
        trianguloPascal.push_back(nivel);
        nivel.clear();
        n++;
    }
    return trianguloPascal;
}
void triangulo_de_pascal_imprimir(vector<vector<int>> trianguloPascal){
    int i=0;
    for(auto elemento:trianguloPascal){
        int j=0;
        while(j<trianguloPascal[i].size()){
            cout<<trianguloPascal[i][j]<<"  ";
            j++;
        }
        i++;
        cout<<endl;
    }

}
//5
vector<int> factores_primos(int num) {
    vector<int>primos={};
    int i = 2;
    do {
        while(num%i==0){
                primos.push_back(i);
                num/=i;
        }
        i++;
    }while(num>1);
    return primos;
}
list<Semiprimo> semiprimos(int inicio, int fin){
    list<Semiprimo>semiprimos;
    Semiprimo aux{};
    for(int i=inicio;i<=fin;i++){
        vector<int>x={};
        x=factores_primos(i);
        if(x.size()==2){
            aux.encontrado=i;
            aux.primo1=x[0];
            aux.primo2=x[1];
            semiprimos.push_back(aux);
        }
    }
    return semiprimos;
}
void imprimir_semiprimos(list<Semiprimo>semiprimos){
    cout<<"{ ";
    for (auto elemento : semiprimos){
        cout<<elemento.encontrado<<","<<elemento.primo1<<","<<elemento.primo2<<"  ";
    }
    cout<<"}";
}
//6
vector<int> extrae_diagonal(array<array<int,tam>,tam> matriz, int nxn, int diagonal){
    vector<int>diagVector;
    if (diagonal>=0){
        int x=0, j=diagonal;
        while(x<tam && j<tam){
            diagVector.push_back(matriz[x][j]);
            x++;j++;
        }
    }
    else if (diagonal<0){
        int x=0,j=-(diagonal);
        while (j<tam){
            diagVector.push_back(matriz[j][x]);
            x++;j++;
        }
    }
    return diagVector;
}
void imprimir_diagonal(vector<int>diagonal){
    int i=0;
    cout<<"{ ";
    while(i<diagonal.size()){
        cout<<diagonal[i]<<"  ";
        i++;
    }
    cout<<"}";
}
//7
list<int> convertir_a_lista(int numero){
    list<int>lista;
    while(numero!=0){
        lista.push_front(numero%10);
        numero=numero/10;
    }
    return lista;
}
void imprimir_lista(list<int> lista){
    for (auto elemento : lista){
        cout<<elemento<<"  ";
    }
    cout<<endl;
}
void  sumar_numeros_largos(int num1,int num2){
    list<int>suma;
    int aux=0,sum;
    auto lista1=convertir_a_lista(num1), lista2=convertir_a_lista(num2);
    auto it2=lista2.rbegin(), it1=lista1.rbegin();
    if(lista2.size()>lista1.size()){
        while(it1!=lista1.rend()){
            sum=*it1+*it2+aux;
            if(sum<=9){
                aux=0;
            }
            else if(sum>9){
                aux=sum/10;
                sum=sum%10;
            }
            suma.push_front(sum);
            it2++;it1++;
        }
        while(it2!=lista2.rend()){
            sum=*it2+aux;
            if(sum<=9){
                aux=0;
            }
            else if(sum>9){
                aux=sum/10;
                sum=sum%10;
            }
            suma.push_front(sum);
            it2++;
        }
        if(lista1.size()>lista2.size()) {
            while (it2 != lista2.rend()) {
                sum = *it2 + *it1 + aux;
                if (sum <= 9) {
                    aux = 0;
                } else if (sum > 9) {
                    aux = sum / 10;
                    sum = sum % 10;
                }
                suma.push_front(sum);
                it2++;
                it1++;
            }
            while (it1 != lista1.rend()) {
                sum = *it1 + aux;
                if (sum <= 9) {
                    aux = 0;
                } else if (sum > 9) {
                    aux = sum / 10;
                    sum = sum % 10;
                }
                suma.push_front(sum);
                it1++;
            }
        }
    }
    cout<<"Lista del numero 1: ";imprimir_lista(lista1);
    cout<<"\nLista del numero 2: ";imprimir_lista(lista2);
    cout<<"\nLista resultante: ";imprimir_lista(suma);
}

int main() {
    cout<<"--- PRACTICA EXAMEN 3 ---"<<endl;
    cout<<"Convetir numero a otras bases"<<endl;
    cout<<"Resultado de la conversion: "<<base10_a_otras_bases(61309 ,2,4,8);
    cout<<"\nExtraer numeros"<<endl;
    string strEj3="xy 225pa.b3.1415g89iou1000 ab78.9  25";
    forward_list<float>Ej3=extraer_numeros(strEj3);
    extraer_numeros_imprimir(Ej3);
    cout<<"\nTriangulo de Pascal"<<endl;
    vector<vector<int>>Ej4=triangulo_de_pascal(5);
    triangulo_de_pascal_imprimir(Ej4);
    cout<<"\nSemiprimos"<<endl;
    list<Semiprimo>Ej5=semiprimos(14,24);
    imprimir_semiprimos(Ej5);
    cout<<"\nDiagonal de Matriz"<<endl;
    array<array<int,tam>,tam> matriz={20,50,60,70,80,15,20,16,40,50,30,56,60,25,30,41,85,90,64,70,68,43,12,24,16};
    vector<int>Ej6=extrae_diagonal(matriz,tam,0);
    imprimir_diagonal(Ej6);
    cout<<"\nNumeros Largos"<<endl;
    sumar_numeros_largos(875,12348);
    return 0;
}