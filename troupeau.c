#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "troupeau.h"
#include <gtk/gtk.h>

enum
{
	IDENTIFIANT,
	TYPE,
	DATE,
	SEXE,
	POIDS,
	COLUMNS
	
};

//ajouter un troupeau
void ajouter_troupeau(Troupeau t)
{

FILE *f;
f=fopen("troupeaux.txt","a+");
if (f!=NULL)
{
fprintf(f,"%s %s %s %s %s \n",t.IDtroupeau, t.Typetroupeau, t.Datetroupeau, t.Sexetroupeau, t.Poidstroupeau);
fclose(f);
}
}
//afficher les troupeaux
void afficher_troupeau(GtkWidget *liste)
{

	GtkCellRenderer *renderer; //afficher la cellule(cellule contient un texte, image, case a cocher
	GtkTreeViewColumn *column; //visualisation des colonnes
	GtkTreeIter iter; //c'est l'ensemble des elements de notre treeview
	GtkListStore *store;// créartion du modèle de type liste
	char id[20];
	char type[20];
	char date[20];
	char sexe[20];
	char poids[20];
	
	store=NULL;

FILE *f;

store=gtk_tree_view_get_model(liste);

if (store==NULL)
{
renderer=gtk_cell_renderer_text_new();
column=gtk_tree_view_column_new_with_attributes("IDtroupeau",renderer,"text",IDENTIFIANT,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);
renderer=gtk_cell_renderer_text_new();
column=gtk_tree_view_column_new_with_attributes("Typetroupeau",renderer,"text",TYPE,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);
renderer=gtk_cell_renderer_text_new();
column=gtk_tree_view_column_new_with_attributes("Datetroupeau",renderer,"text",DATE,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);
renderer=gtk_cell_renderer_text_new();
column=gtk_tree_view_column_new_with_attributes("Sexetroupeau",renderer,"text",SEXE,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);
renderer=gtk_cell_renderer_text_new();
column=gtk_tree_view_column_new_with_attributes("Poidstroupeau",renderer,"text",POIDS,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);
store=gtk_list_store_new(COLUMNS, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING);}

f=fopen("troupeaux.txt","r");
if (f==NULL)
{	
	return;
}
else {
f=fopen("troupeaux.txt","a+");
while(fscanf(f,"%s %s %s %s %s \n",id,type,date,sexe,poids)!=EOF)
{
gtk_list_store_append(store,&iter);
gtk_list_store_set(store,&iter,IDENTIFIANT,id,TYPE,type,DATE,date,SEXE,sexe,POIDS,poids,-1);
}
fclose(f);
gtk_tree_view_set_model(GTK_TREE_VIEW(liste), GTK_TREE_MODEL(store));
g_object_unref (store);
}
}
//supprimer un troupeau
void supprimer_troupeau(Troupeau t)
{
	char id[20];
	char type[20];
	char date[20];
	char sexe[20];
	char poids[20];


FILE *f,*g;
f=fopen("troupeaux.txt","r");
g=fopen("troupeaux2.txt","w");
if(f==NULL || g==NULL)
{
	return;
}
else{
while(fscanf(f,"%s %s %s %s %s \n",id,type,date,sexe,poids)!=EOF)
{
if (strcmp(t.IDtroupeau,id)!=0||strcmp(t.Typetroupeau,type)!=0||strcmp(t.Datetroupeau,date)!=0||strcmp(t.Sexetroupeau,sexe)!=0||strcmp(t.Poidstroupeau,poids)!=0)
fprintf(g,"%s %s %s %s %s ",id,type,date,sexe,poids);
}
fclose(f);
fclose(g);
remove("troupeaux.txt");
rename("troupeaux2.txt","troupeaux.txt");
}
}


//Chercher un troupeau
int Chercher_troupeau (char Id[])

{
int trouvetroupeau=-1;
FILE *f=NULL;

	char chid[20];
	char chtype[20];
	char chdate[20];
	char chsexe[20];
	char chpoids[20];



f=fopen("troupeaux.txt","r");
if(f!=NULL)
{
while(fscanf(f,"%s %s %s %s %s \n",chid,chtype,chdate,chsexe,chpoids)!=EOF)
{
if (strcmp(chid,Id)==0)
{
trouvetroupeau=1;
//printf("%s %s %s %s %s",chid,chtype,chdate,chsexe,chpoids);
}
}
fclose(f);
}
return (trouvetroupeau);
}



//supprimer un troupeau
void Supprimer_troupeau(char Id[])
{
	char chid[20];
	char chtype[20];
	char chdate[20];
	char chsexe[20];
	char chpoids[20];
FILE *f=NULL;
FILE *p=NULL;

f=fopen("troupeaux.txt","r");
p=fopen("temp.txt","a+");
if(f!=NULL)
{
while(fscanf(f,"%s %s %s %s %s \n",chid,chtype,chdate,chsexe,chpoids)!=EOF)
{
if (strcmp(chid,Id)!=0) 
fprintf(p,"%s %s %s %s %s \n",chid,chtype,chdate,chsexe,chpoids);

}
fclose(f);
fclose(p);
}
remove("troupeaux.txt");
rename("temp.txt","troupeaux.txt");
}
//Modifer un troupeau

void modifier_troupeau(char Id[])
{
	char chid[20];
	char chtype[20];
	char chdate[20];
	char chsexe[20];
	char chpoids[20];
FILE *f=NULL;
FILE *p=NULL;

f=fopen("troupeaux.txt","r");
p=fopen("temp.txt","w");
if(f!=NULL)
{
while(fscanf(f,"%s %s %s %s %s \n",chtype,chdate,chsexe,chpoids,chid)!=EOF)
{
if (strcmp(chid,Id)==0)
{ 
printf("Nouveau Type: ");
scanf("%s",chtype);
printf("Nouveau Date: ");
scanf("%s",chdate);
printf("Nouveau Sexe: ");
scanf("%s",chsexe);
printf("Nouveau Poids: ");
scanf("%s",chpoids);
printf("Nouveau ID: ");
scanf("%s",chid);
fprintf(p,"%s %s %s %s %s \n",chtype,chdate,chsexe,chpoids,chid);
}
else
fprintf(p,"%s %s %s %s %s \n",chtype,chdate,chsexe,chpoids,chid);
}
fclose(f);
fclose(p);
}
remove("troupeaux.txt");
rename("temp.txt","troupeaux.txt");

}

