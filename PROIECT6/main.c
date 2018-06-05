/**
* @file main.c
* @brief Aceasta fila contine programul principal.
* @author Croitoru Mihaita Cosmin
*/

#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include"header.h"

int n;
int calea_finala[100];
char MatriceAdiacenta[100][100];
int numarator;
int fp;
int b[100];
/**
* Functia main.
* @author Croitoru Mihaita Cosmin
* @date 4/06/2018
*/
int main(){
    char v;
    int iterator_1, iterator_2, l;
    printf("Introduceti numarul de noduri din graf: \n");
    scanf("%d",&n);
    printf("Introduceti valorile nodului\n");
    for( iterator_1 = 0; iterator_1 < n; iterator_1++){
     scanf("%d",&b[iterator_1]);
     ///stocheaza nodurile in in b[]
    }



    printf("\nDaca exista muchie intre doua noduri introduceti d, altfel introduceti n !\n");
    for( iterator_1 = 0; iterator_1 < n; iterator_1++){
            printf(" %d ",b[iterator_1]);
        }
    for( iterator_1 = 0; iterator_1 < n; iterator_1++){
         printf("\n%d ",b[iterator_1]);
         for( iterator_2 = 0; iterator_2 < n; iterator_2++){
             printf("%c ",v=getch());
             MatriceAdiacenta[iterator_1][iterator_2] = v;
         }
         printf("\n\n");
    }

    ///caleafinala[] va returna 0 daca calea/circcuitul euler nu este posibil
    ///otherwise it will return array index of any node as root
    int radacina1;
    if(radacina1=radacina()){
      if(numarator){
        printf("Available Euler Path is\n");
      }
      else printf("Ciclul eulerian valabil este:\n");
      calea_finala[fp++] = radacina1;
      Euler(radacina1);
      afisare();
    }
    else printf("Ciclul sau calea euleriana nu este valabil!\n");
    getch();
    return 0;
}
