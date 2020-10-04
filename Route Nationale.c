#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct
{
    char Nom[30];
    int Distance;
    char VilleD[50];
    char VilleF[50];
}RouteN;

int Menu()
{
    int choix;
    do
    {
        printf("------------------Gestion des routes nationales------------------\nTapez le numero de l'operation a realiser :\n1 ------ Ajouter une nouvelle route\n2 ------ Afficher les routes\n3 ------ Chercher une route\n4 ------ Supprimer une route\n5 ------ Sauvegarder dans un fichier\n6 ------ Quiter\n");
        printf("-----------------------------------------------------------------\n");
        fflush(stdin);scanf("%d",&choix);
    } while (!(choix >=1 && choix <=6));
    return choix;
}

void Ajouter(RouteN N[], int Nbr)
{
    fflush(stdin);printf("Tapez nom : ");gets(&N[Nbr].Nom);
    fflush(stdin);printf("Tapez distance : ");scanf("%d",&N[Nbr].Distance);
    fflush(stdin);printf("Tapez Ville de depart : "),gets(&N[Nbr].VilleD);
    fflush(stdin);printf("Tapez ville de fin : ");gets(&N[Nbr].VilleF);
}

void Afficher(RouteN N[], int Nbr)
{
    int i;
    for(i=0;i<=Nbr-1;i++)
    {
        printf("---------Ville %d---------\n",i+1);
        printf("Nom : %s\nDistance : %d\nVille de depart : %s\nVille de fin : %s\n",N[i].Nom,N[i].Distance,N[i].VilleD,N[i].VilleF);
    }
    printf("--------------------------\n");
}

void Chercher(RouteN N[], int Nbr)
{
    int i; char Nom[30];
    printf("Tapez nom pour rechercher : ");fflush(stdin);gets(&Nom);
    for ( i = 0; i < Nbr; i++)
    {
        if (strcmp(N[i].Nom,Nom)==0)
        {
            printf("Nom : %s\nDistance : %d\nVille de depart : %s\nVille de fin : %s\n",N[i].Nom,N[i].Distance,N[i].VilleD,N[i].VilleF);
            return;
        }
    }
    printf("la route n'existe pas!\n");
}

void Supprimer(RouteN N[], int* Nbr)
{
    int i,j,r=0; char Nom[30];
    printf("Tapez nom pour rechercher : ");fflush(stdin);gets(&Nom);
    for (i=0,j=0;i<*Nbr;i++,j++)
    {
        if(strcmp(N[i].Nom,Nom)==0)
        {
            j++;r=1;
        }
        strcpy(N[i].Nom,N[j].Nom);
        N[i].Distance=N[i].Distance;
        strcpy(N[i].VilleD,N[j].VilleD);
        strcpy(N[i].VilleF,N[j].VilleF);
    }
    switch (r)
    {
    case 0:
        printf("La route n'existe pas!\n");
        break;
    
    default:
        printf("La route a ete supprimer avec success!\n");*Nbr=*Nbr-1;
        break;
    }
}

void Sauvegarder(RouteN N[], int Nbr)
{
    int i;
    FILE* fichier = fopen("RouteNationale.txt","w");
    for ( i = 0; i < Nbr; i++)
    {
        fprintf(fichier,"%s | %d | %s | %s\n",N[i].Nom,N[i].Distance,N[i].VilleD,N[i].VilleF);
    }
    fclose(fichier);
    printf("Les donnee a ete sauvegarder avec success!\n");
}

int main()
{
    int Nbr=0;
    RouteN* R;
    R = malloc(100*sizeof(RouteN));
    M: switch (Menu())
    {
    case 1:
        Ajouter(R,Nbr);Nbr++;goto M;break;
    case 2:
        Afficher(R,Nbr);goto M;break;
    case 3:
        Chercher(R,Nbr);goto M;break;
    case 4:
        Supprimer(R,&Nbr);goto M;break;
    case 5:
        Sauvegarder(R,Nbr);goto M;break;
    default:
        printf("Merci pour votre temps.\n");return;
        break;
    }
    system("Pause");
    free(R);
}