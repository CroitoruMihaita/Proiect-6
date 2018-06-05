/**
* @file functii.c
* @brief Aceasta fila contine functiile folosite in program.
* @author Croitoru Mihaita Cosmin
*/

#include "header.h"
#include<stdlib.h>


int n;
int calea_finala[100];
char MatriceAdiacenta[100][100];
int numarator;
int fp;
int b[100];

/**
* Afiseaza circuitul sau calea euleriana.
* @author Croitoru Mihaita Cosmin
* @date 4/06/2018
*/
void afisare(){
     int iterator_1;
     for(iterator_1 = 0; iterator_1 < fp; iterator_1++){
       printf("%d->",calea_finala[iterator_1]);
     }
}
/**
* Este folosita pentru a obtine gradul nodului.
* @author Croitoru Mihaita Cosmin
* @date 4/06/2018
*/
int grad(int nod){
    int iterator_2, grad_1 = 0;
    int pozitie = Index(nod);
    for(iterator_2 = 0; iterator_2 < n ; iterator_2++){
      if(MatriceAdiacenta[pozitie][iterator_2] == 'd'){
        grad_1++;
      }
    }
    return grad_1;
}

/**
* Este folosita pentru a atribui radacina graﬁcului.
* @author Croitoru Mihaita Cosmin
* @date 4/06/2018
*/
int radacina(){
     int iterator_1, current = 1;
     ///Se presupune că rădăcina este 1
     for(iterator_1 = 0; iterator_1 < n; iterator_1++){
        if(grad(b[iterator_1]) %2 != 0){
           numarator++;
           ///Păstrați nodul care are un grad impar in variabila current
           current = iterator_1;
        }
     }

     ///Dacă "numărator" nu este exact 2, atunci calea / circuitul euler nu este posibil, deci returneaza 0.
     if(numarator != 0 && numarator != 2){
        return 0;
     }
     ///dacă exact 2 noduri au un grad impar, se va returna unul din acele noduri ca rădăcină, altfel se va returna 1 ca radacina.
     else return b[current];
}

/**
* Folosita pentru a obtine indicele curent al nodului in matricea b [] a nodului.
* @author Croitoru Mihaita Cosmin
* @date 4/06/2018
*/
int Index(int nod){
    int iterator_3 = 0;
    while(nod != b[iterator_3]){
        iterator_3++;
    }
    return iterator_3;
}

/**
* Returneaza 0 daca numarul ”d” este egal cu 2 in matrice si indica faptul ca nu exista alte muchii pe care sa le vizitai in acest graf.
* @author Croitoru Mihaita Cosmin
* @date 4/06/2018
*/
int ultimul_nod(int nod){
    int iterator_1 = 0;
    int suma_gradelor = 0;
    for(iterator_1 = 0; iterator_1 < n; iterator_1++){
     suma_gradelor = suma_gradelor + grad(b[iterator_1]);
    }
    if(suma_gradelor == 2)
      return 1;
    else
      return 0;
}

/**
* Nodul urmator.
* @author Croitoru Mihaita Cosmin
* @date 4/06/2018
*/
int nodul_urmator(int nod){
    int iterator_1 = 0;
    int pozitie = Index(nod);

    for(iterator_1 = 0; iterator_1 < n; iterator_1++){
      if(MatriceAdiacenta[pozitie][iterator_1] == 'd'){
        if(!are_o_muchie(b[iterator_1])){
          return b[iterator_1];
        }
        else{
            if(ultimul_nod(b[iterator_1]))
            return b[iterator_1];
        }
      }
    }
    return -1;
}

/**
* Daca gradul de varf este egal cu 1 inseamna ca varful are o muchie.
* @author Croitoru Mihaita Cosmin
* @date 4/06/2018
*/
int are_o_muchie(int nod){
    if(grad(nod)==1)
      return 1;
    else
      return 0;
}

/**
* Daca nu exista ”d”ˆin matrice inseamna ca am vizitat toate varfurile si muchiile.
* @author Croitoru Mihaita Cosmin
* @date 4/06/2018
*/
int Complet(){
    int iterator_1 = 0;
    for(iterator_1 = 0; iterator_1 < n; iterator_1++){
        if(grad(b[iterator_1])>0)
             return 0;
    }
    return 1;
}
/**
* Stergerea muchiilor.
* @author Croitoru Mihaita Cosmin
* @date 4/06/2018
*/
void stergere_muchie(radacina1,eNod){
     int pozitia_1 = 0,pozitia_2 = 0;
     pozitia_1=Index(radacina1);
     pozitia_2=Index(eNod);
     MatriceAdiacenta[pozitia_1][pozitia_2] = 'n';
     MatriceAdiacenta[pozitia_2][pozitia_1] = 'n';
}

/**
* Este folosita pentru a gasi circuitul / calea Euler ¸si a-l depozita in matricea ﬁnalPath [].
* @author Croitoru Mihaita Cosmin
* @date 4/06/2018
*/
void Euler(int radacina1){
     int eNod;
     while(!Complet()){
        eNod=nodul_urmator(radacina1);
        ///adauga nodul urmator
        calea_finala[fp++]=eNod;
        ///adauga nodul in calea euleriana
        stergere_muchie(radacina1,eNod);
        ///sterge muchia
        radacina1=eNod;
        ///schimba radacina
     }
}

/**
* Stocheaza nodrueile in b
* @author Croitoru Mihaita Cosmin
* @date 4/06/2018
*/
void afisare_2(){
     int iterator_1;
      for( iterator_1 = 0; iterator_1 < n; iterator_1++){
        printf("%d ",b[iterator_1]);
        ///stocheaza nodrueile in b
    }
}
