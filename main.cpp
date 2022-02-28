#include <iostream>
#include <stdio.h>
#include <string>
#include <sstream>
#include <algorithm>
#include <cmath>

using namespace std;
using std::stoi;
using std::to_string;
using std::cout;
using std::endl;
using std::sort;
using std::pow;


int* Triplets3(int resultado3[]){
    int a[]= {67,67,12};
    int b[]= {29,15,10};
    int x = (a[0]-b[0])/abs(a[0]-b[0]);//3 operación aritmetica
    int y = (a[1]-b[1])/abs(a[1]-b[1]);
    int z = (a[2]-b[2])/abs(a[2]-b[2]);

    if (x == -1){resultado3[0] += 0;//6 comparaciones y
        resultado3[1] += 1;//6 sumas
        }else{resultado3[0] += 1;
        resultado3[1] += 0;
        }
    if(y == -1){resultado3[0] += 0;
       resultado3[1] += 1;
       }else{resultado3[0] += 1;
        resultado3[1] += 0;
        }
    if(z == -1){resultado3[0] += 0;
       resultado3[1] += 1;
       }else{resultado3[0] += 1;
        resultado3[1] += 0;
        }
    return resultado3;
}
//-----------------------------------------------------------
int* Triplets2(int resultado2[]){
    int a[]= {1,1,1};
    int b[]= {0,1,2};
    //--6 comparaciones y 6 sumas
    resultado2[0]= a[0]>b[0]?1:0 + a[1]>b[1]?1:0 + a[2]>b[2]?1:0;
    resultado2[1]= a[0]<b[0]?1:0 + a[1]<b[1]?1:0 + a[2]<b[2]?1:0;
    return resultado2;
}
//-----------------------------------------------------------
int* Triplets(int resultado[]){
    int a[] = {0,1,3};
    int b[] = {0,1,2};

    for (int i = 0; i < 3; i++){//itera 3 veces

        if (a[i] > b[i]){//4 comparaciones del for y 6 internas
            resultado[0]++;//7 veces el ++
        }
        if (b[i] > a[i]){
            resultado[1]++;
        }
    }
    return resultado;
}
//-----------------------------------------------------------
string TimeConversion(string time){
    int horas = stoi(time.substr(0,2));
    int timeValues[3];
    timeValues[0]= horas;

    if(time[8]== 'A'){//6 comparaciones y 5 asignaciones
        if(timeValues[0] == 12){
            timeValues[0] = 0;
        }else if(timeValues[0] != 12){
            timeValues[0] -=12;
        }
    }
    if(time[8]== 'P'){
      if(timeValues[0] < 12){
        timeValues[0] +=12;
      }
    }
    string result ="";
    if(timeValues[0] <10){
            result+="0";
    }
    string resultado = to_string(timeValues[0]);
    result += resultado + time.substr(2,6);
    return result;
}
//-----------------------------------------------------------
string TimeConversion2(string time2){
    int horas = stoi(time2.substr(0,2));
    int timeValues[3];
    timeValues[0]= horas;
    if(time2[8]== 'A'){//4 comparaciones y 3 asignaciones
        timeValues[0]+=(timeValues[0] == 12)?timeValues[0] = 0:timeValues[0] -=12;
    }
    if(timeValues[0] < 12){
        timeValues[0] +=12;
      }
    string result ="";
    if(timeValues[0] <10){
            result+="0";
    }
    string resultado = to_string(timeValues[0]);
    result += resultado + time2.substr(2,6);
    return result;
}
//-----------------------------------------------------------
int SubarrayDivision(int segmento[],int n , int dianacimento, int mes){
        int total=0;
    int suma=0;
    int i=0;
    while(i < n){//n comparaciones
            for(int j=i;j<mes+i;j++){//J iteraciones
                suma+= segmento[j];//J asignaciones
            }
            suma=(suma==dianacimento)?total++:suma =0;//N comparaciones
        i++;//N ++
        }
    return total;
}
//-----------------------------------------------------------

int SubarrayDivision2(int segmento[],int n , int dianacimento, int mes){
    int total=0;
    int suma=0;
    int i=0;
    while(i < n){//n comparaciones
            int j=0;
            while(j<mes+i){//j comparaciones
                suma+= segmento[j];//J asignaciones
                j++;//j ++
            }
            suma=(suma==dianacimento)?total++:suma =0;//N comparaciones
        i++;//N ++
        }
    return total;
}

//-----------------------------------------------------------
void minion_game(string cadena){
    int ganador[2] = {0,0};
    string vocales = "AEIOU";
    for(int i=0;i<cadena.size();i++){// i iteraciones
        int n =0;
            ganador[0]+=(cadena[i]== vocales[n])?cadena.size()-i:0;//i comparaciones e i sumas
            ganador[1]+=(cadena[i]!= vocales[n])?cadena.size()-i:0;
           n++;
    }
    if(ganador[0] == ganador[1]){//2 comparaciones por n iteraciones
        cout<<"draw"<<endl;
    }else if (ganador[0] > ganador[1]){
        cout<<"KEVIN "<< ganador[0]<<endl;
    }else{
        cout<<"STUART "<< ganador[1]<<endl;
    }
}

//-----------------------------------------------------------
int pairs(int n, int k,int arr[]){
    sort(arr, arr + n);
    int total =0;
    int contador = 0;
    for(int i=0;i<n;i++){//n iteraciones
        for(int j=i;j<n;j++){//j=i iteraciones
                contador =arr[j]-arr[i];// N asignaciones
            if(contador == k){// N comparaciones
                total++;//N ++
            }
        }
    }
    return total;
}

int main(){
    int resultado[] = {0,0};
    int resultado2[] = {0,0};
    int resultado3[] = {0,0};

    int* a = Triplets(resultado);
    int* b = Triplets2(resultado2);
    int* c = Triplets3(resultado3);

    cout << "Prueba Compare the Triplets" << endl;
    cout << a[0] <<","<< a[1]<< endl;
    cout << "Prueba 2 Compare the Triplets" << endl;
    cout << b[0] <<","<< b[1]<< endl;
    cout << "Prueba 3 Compare the Triplets" << endl;
    cout << c[0] <<","<< c[1]<< endl;
    cout<<"-----------------------------------------------------------"<<endl;
//-----------------------------------------------------------
    cout << "Prueba Time conversion" << endl;
    string time ="21:25:00PM";
    string d = TimeConversion(time);
    cout <<d<<endl;

    cout << "Prueba Time conversion" << endl;
    string time2 ="21:25:00PM";
    string e = TimeConversion(time2);
    cout <<e<<endl;

    cout << "Prueba 2 Time conversion" << endl;
    string time3 ="14:37:00AM";
    string f = TimeConversion(time3);
    cout <<f<<endl;

    cout << "Prueba 2 Time conversion" << endl;
    string time4 ="14:37:00AM";
    string g = TimeConversion(time4);
    cout <<g<<endl;
    cout<<"-----------------------------------------------------------"<<endl;

//-----------------------------------------------------------
cout << "Prueba Subarray Division" << endl;
    int n=5;
    int segmento[]={1,2,1,3,2};
    int dianacimento = 3 ;
    int mes = 2;
    int h= SubarrayDivision(segmento,n,dianacimento,mes);
    cout <<h<<endl;

    cout << "Prueba Subarray Division" << endl;
    int n2 = 5;
    int segmento2[]={1,2,1,3,2};
    int dianacimento2 = 3;
    int mes2 = 2;
    int l = SubarrayDivision(segmento2,n2,dianacimento2,mes2);
    cout <<l<<endl;

    cout << "Prueba2 Subarray Division" << endl;
    int n6 = 1;
    int segmento6[]={4};
    int dianacimento6 = 4 ;
    int mes6 = 1;
    int m = SubarrayDivision2(segmento6,n6,dianacimento6,mes6);
    cout <<m<<endl;

    cout << "Prueba2 Subarray Division" << endl;
    int n7 = 1;
    int segmento7[]={4};
    int dianacimento7 = 4 ;
    int mes7 = 1;
    int o = SubarrayDivision2(segmento7,n7,dianacimento7,mes7);
    cout <<o<<endl;
    cout<<"-----------------------------------------------------------"<<endl;

//-----------------------------------------------------------

    cout << "Prueba The Minion Game" << endl;
    string cadena ="BANANA";
    minion_game(cadena);

    cout << "Prueba2 The Minion Game" << endl;
    string cadena2 ="ANA";
    minion_game(cadena2);
    cout<<"-----------------------------------------------------------"<<endl;

//-----------------------------------------------------------
    cout << "Prueba Pairs" << endl;
    int n3=4;
    int k =1;
    int arr[]={19,20,32,31};
    int p =pairs(n3,k,arr);
    cout<<p<<endl;

    cout << "Prueba Pairs" << endl;
    int n4=4;
    int k1 =1;
    int arr2[]={19,20,32,31};
    int q =pairs(n4,k1,arr2);
    cout<<q<<endl;

    cout << "Prueba2 Pairs" << endl;
    int n9=4;
    int k2 =1;
    int arr3[]={1,2,3,4};
    int r =pairs(n9,k2,arr3);
    cout<<r<<endl;

    cout << "Prueba2 Pairs" << endl;
    int n0=4;
    int k3 =1;
    int arr4[]={1,2,3,4};
    int s =pairs(n0,k3,arr4);
    cout<<s<<endl;
return 0;
}
