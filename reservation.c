#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"reservation.h"
#include <gtk/gtk.h>
/*
int tableau_Reservation_client(ReservationClient tab[])
{
int n=0;
FILE* f=fopen("clientsreserve.txt","r");
if (f!=NULL)
{
while(fscanf(f,"%s %s %s %s %d %d %d"),tab[n].IDclient,tab[n].Nomclient,tab[n].Prenomclient,tab[n].Numeroclient,tab[n].dt_resr.Jour,tab[n].dt_resr.Mois,tab[n].dt_resr.Annee!=EOF)
{n++;}
fclose(f);
}
return n;
}

verifier_reservation(ReservationClient cr)
{}
*/

int tableau_client_disponible(char rs[20][10])
{
FILE* f=fopen("clientsreserve.txt","r");
FILE* g=fopen("clients.txt","r");

int nc=0;
char nom[20],prenom[20],email[20];
char id[20], numero[20];
int jour,mois,annee,heure;
char id1[20];
if(f!=NULL)
{
while (fscanf(f,"%d %d %d %s %d ",&jour,&mois,&annee,id1,&heure)!=EOF)
{
while (fscanf(g,"%s %s %s %s %s ",nom,prenom,email,id,numero)!=EOF)
{
if (strcmp(id,id1)!=0)
{
//strcat(id,nom);
//strcat(id,prenom);
strcpy(rs[nc],id);
nc++;
}

}
}
}
fclose(f);
fclose(g);
return nc;
}




void reservation_client (ReservationClient rc)
{
FILE* f=fopen("clientsreserve.txt","a");
if(f!=NULL)
{fprintf(f,"%d %d %d %s %d \n",rc.dt_resr.jour,rc.dt_resr.mois,rc.dt_resr.annee,rc.IDclient,rc.hr_resr);
fclose(f);
}
}
