#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>
#include<math.h>
typedef struct 
{
  char ville[20];int nbh;
}city;
void lecture(city P[],int n)
{
  int i;
  for ( i = 0; i < n; i++)
  {
    printf("Donnez nom de ville: ");fflush(stdin);gets(P[i].ville);
    printf("Donnez nombre d'habitants: ");scanf("%d",&P[i].nbh);
  }
  
}
void affiche(city P[],int n)
{
  int i;
  for ( i = 0; i < n; i++)
  {
    printf("---------ville %d---------\n",i+1);
    printf("Ville: %s\n",P[i].ville);
    printf("Nombre d'habitants: %d\n",P[i].nbh);
  }
  printf("-----------------------------\n");
}
void orderAlpha(city P[],int n)
{
  char tab[20];int i,j,C;
  for ( i = 0; i < n; i++)
  {
    for ( j = 0; j < n; j++)
    {
      if (strcmp(P[i].ville,P[j].ville)<0)
      {
        strcpy(tab,P[i].ville);C=P[i].nbh;
        strcpy(P[i].ville,P[j].ville);P[i].nbh=P[j].nbh;
        strcpy(P[j].ville,tab);P[j].nbh=C;
      }
      ;
    }
  }
  for ( i = 0; i < n; i++)
  {
    printf("---------ville %d---------\n",i+1);
    printf("Ville: %s\n",P[i].ville);
    printf("Nombre d'habitants: %d\n",P[i].nbh);
  }
  
  printf("-----------------------------\n");
}
void orderNum(city P[],int n)
{
  int i,j,C;char tab[20];
  for ( i = 0; i < n; i++)
  {
    for ( j = 0; j < n; j++)
    {
      if (P[i].nbh<P[j].nbh)
      {
        strcpy(tab,P[i].ville);C=P[i].nbh;
        strcpy(P[i].ville,P[j].ville);P[i].nbh=P[j].nbh;
        strcpy(P[j].ville,tab);P[j].nbh=C;
      }
    }
  }
  for ( i = 0; i < n; i++)
  {
    printf("---------ville %d---------\n",i+1);
    printf("Ville: %s\n",P[i].ville);
    printf("Nombre d'habitants: %d\n",P[i].nbh);
  }
}
int main()
{
  city E[5];
  lecture(E,3);affiche(E,3);orderAlpha(E,3);orderNum(E,3);
}
