#include <stdio.h>
#include <stdlib.h>
#include<string.h>
typedef struct {
	char nomEleve[30];
	int ageEleve;
	float mynEleve;
	char classeEleve[20];
	float moduleEleve[7];
	float moduleeEleve;
}eleve;

void Saisie (eleve E[],int Nbr)
{
	int module=0;
	int i,j;
	for (i=0;i<Nbr;i++)
	{
		printf ("Donnez le nom d'eleve: ");fflush(stdin);gets(E[i].nomEleve);
		printf ("Donnez l'age d'eleve: ");fflush(stdin);scanf("%i",&E[i].ageEleve);
		printf ("Donnez la classe d'eleve: ");fflush(stdin);gets(E[i].classeEleve);
		printf ("----Entrez les Notes des Modules:----\n");
		E[i].moduleeEleve=0; //Intialiser o mati9ch fi la ram
		for (j=0;j<7;j++)
		{
			printf ("Entrez la note du Module: %i\n",j+1);
			scanf("%f",&E[i].moduleEleve[j]);
			E[i].moduleeEleve+=E[i].moduleEleve[j];
		}
	}
}



void Affichage (eleve E[],int Nbr)
{
	
	int i;
	for (i=0;i<Nbr;i++)
	{
		printf ("Affichage des Informations de %i Eleve\n",i+1);
		printf ("Le nom d'eleve est: %s | son Age est: %i | son Classe est: %s | sa Moyenne est: %.1f\n",E[i].nomEleve,E[i].ageEleve,E[i].classeEleve,E[i].moduleeEleve/7);
		if (E[i].moduleeEleve/7<10)
		{
			printf ("Non-Admis\n");
		}
		else
		{
			printf ("Admis\n");
		}
	}
}

char SearchClass(eleve E[],int Nbr,char classe[20])
{
	int i,R=0;
	for(i=0;i<Nbr;i++)
	{
		if(strcmp(E[i].classeEleve,classe)==0)
		{
			R=1;
			goto B;
		}
	}
B:	return R;
}

void ClasseSearch(eleve E[],int Nbr)
{
	int i; char C[20];
	printf("Donnez la classe a chercher : ");fflush(stdin);gets(C);
	if(SearchClass(E,Nbr,C)==1)
	{
		for(i=0;i<Nbr;i++)
		{
			if(strcmp(E[i].classeEleve,C)==0)
			{
				printf("Eleve %d\n",i+1);
				printf ("Le nom d'eleve est: %s | son Age est: %i | son Classe est: %s | sa Moyenne est: %.1f\n",E[i].nomEleve,E[i].ageEleve,E[i].classeEleve,E[i].moduleeEleve/7);
			}
		}
	}
	else
	{
		printf("Classe Introuvable\n");
	}
}

void SaveFile(eleve E[],int Nbr)
{
	int i;
	FILE* fichier=fopen("Eleve.txt","a");
	for ( i = 0; i < Nbr; i++)
	{
		fprintf(fichier,"%s %d %s %.1f\n",E[i].nomEleve,E[i].ageEleve,E[i].classeEleve,E[i].moduleeEleve/7);
	}
	fclose(fichier);
}

void LoadFile()
{
	int A; char N[30],C[20]; float M;
	FILE* fichier=fopen("Eleve.txt","r");
			/*
				while (feof(fichier)==0)
				{
				fscanf(fichier,"%s %d %s %f",N,&A,&C,&M);
				printf("%s %d %s %.1f\n",N,A,C,M);
			} */
	while(1)
    {
        fscanf(fichier,"%s %d %s %f",N,&A,&C,&M);
        if ( feof(fichier) )
            break; // exit from while
        printf("%s %d %s %.1f\n",N,A,C,M);
}
	fclose(fichier);
}

int main ()
{
	int Nbr,R;
	printf ("You want add informations or Read informations 1/2 ?\n");
	scanf ("%i",&R);
	if (R==1)
	{
	printf ("Donnez combien d'eleve:");
	scanf ("%i",&Nbr);
		eleve* E;
	E=malloc(sizeof(eleve)*Nbr);
	Saisie(E,Nbr);
	Affichage(E,Nbr);
	ClasseSearch(E,Nbr);
	SaveFile(E,Nbr);
	LoadFile();
	}
	else {
		LoadFile();
	}
	return 0;
}


