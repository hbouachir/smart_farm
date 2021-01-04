#include<gtk/gtk.h>



typedef struct troupeau{
char IDtroupeau[20];
char Typetroupeau[20];
char Datetroupeau[20];
char Sexetroupeau[20];
char Poidstroupeau[20];
}Troupeau;



int Chercher_troupeau (char Id[]);
void Supprimer_troupeau(char Id[]);
void Modifier_troupeau(char Id[]);
void afficher_troupeau(GtkWidget *liste);
void ajouter_troupeau(Troupeau t);
void modifier_troupeau(char Id[]);

void Ajouter_troupeau (Troupeau *T);
void supprimer_troupeau(Troupeau t);
void afficher_troupeau();

