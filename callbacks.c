#ifdef HAVE_CONFIG_H
#  include <config.h>
#endif

#include <gtk/gtk.h>
#include "capteur.h"
#include "client.h"
#include "ouvrier.h"
#include "troupeau.h"
#include "seche.h"
#include "reservation.h"
#include "callbacks.h"
#include "interface.h"
#include "support.h"

int x;
int y;
int z,w;
char h[300]="";



/////////////////////HAMZA///////////////////////////////////////////////////////
void
on_retour_vers_menu_capteur_clicked            (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *menu_capteurs, *fenetre_ajouter_capteur;
fenetre_ajouter_capteur=lookup_widget(objet,"fenetre_ajouter_capteur");
gtk_widget_destroy(fenetre_ajouter_capteur);
menu_capteurs=create_menu_capteurs();
gtk_widget_show(menu_capteurs);
}


void
on_ajouter_capteur_clicked                     (GtkWidget       *objet,
                                        gpointer         user_data)
{
capteur c;
  GtkWidget *input1;
  GtkWidget *input2;
  GtkWidget *input3;
  GtkWidget *input4;
GtkWidget *output;

    

  GtkWidget *combobox1;
char text1[20];
char r1[20];
char r2[20];
char r3[20];
  int jj,mm,aa;
 

 
  GtkWidget *fenetre_ajouter_capteur;


fenetre_ajouter_capteur=lookup_widget(objet,"fenetre_ajouter_capteur");
 
	 
 input1 = lookup_widget(objet, "id");
 input2= lookup_widget(objet,"jour");
input3=lookup_widget(objet,"mois");
input4=lookup_widget(objet,"annee");
 combobox1 = lookup_widget(objet, "combobox1");

 

output=lookup_widget(objet,"label42");

 strcpy(c.id, gtk_entry_get_text(GTK_ENTRY(input1)));
if (x==1) strcpy(c.type, "temperature");
if (x==2) strcpy(c.type, "humidité");
 


 strcpy(c.marque, gtk_combo_box_get_active_text(GTK_COMBO_BOX(combobox1)));

jj= gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(input2));
mm= gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(input3));
aa= gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(input4));

sprintf(r1,"%d",jj);
strcat(r1,"/");

sprintf(r2,"%d",mm);
strcat(r1,r2);
strcat(r1,"/");

sprintf(r3,"%d",aa);
strcat(r1,r3);
/*strcat(c.d_ajout,r1);
strcat(c.d_ajout,"/");

sprintf(r2,"%d",mm);
strcat(c.d_ajout,r2);
strcat(c.d_ajout,"/");

sprintf(r3,"%d",aa);
strcat(c.d_ajout,r3);
*/

strcpy(c.d_ajout,r1);
if (Chercher_capteur(c.id)==1) strcpy(text1,"id déja utilisé");
else strcpy(text1,"capteur ajouté");
 if (Chercher_capteur(c.id)==1) gtk_label_set_text(GTK_LABEL(output),text1);
else{
 ajouter_capteur(c);
 gtk_label_set_text(GTK_LABEL(output),text1);}
}


void
on_afficher_capteur_clicked                    (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *fenetre_ajouter_capteur;
GtkWidget *fenetre_afficher_capteur;
GtkWidget *treeview1;

fenetre_ajouter_capteur=lookup_widget(objet,"fenetre_ajouter_capteur");

gtk_widget_destroy(fenetre_ajouter_capteur);
fenetre_afficher_capteur=lookup_widget(objet,"fenetre_afficher_capteur");
fenetre_afficher_capteur=create_fenetre_afficher_capteur();

gtk_widget_show(fenetre_afficher_capteur);

treeview1=lookup_widget(fenetre_afficher_capteur,"treeview1_capteur");

afficher_capteur(treeview1);
}


void
on_treeview1_capteur_row_activated             (GtkTreeView     *treeview1,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data)
{
GtkTreeIter iter;
	gchar* id;
	gchar* type;
	gchar* marque;
	gchar* d_ajout;
	
	
	capteur c;

	GtkTreeModel *model = gtk_tree_view_get_model(treeview1);

	if(gtk_tree_model_get_iter(model, &iter, path))
	{
		//obtention des valeurs de la ligne selectionnée
		gtk_tree_model_get (GTK_LIST_STORE(model),&iter, 0, &id, 1, &type, 2, &marque, 3, &d_ajout,-1);

		strcpy(c.id,id);
		strcpy(c.type,type);
		strcpy(c.marque,marque);
		strcpy(c.d_ajout,d_ajout);

		
		//appel de la fonction de suppression
		supprimer_capteur(c);
		//mise a jour de l'affichage de la treeview

		
		afficher_capteur(treeview1);



}
}


void
on_retour2_vers_menu_capteur_clicked                      (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *menu_capteurs, *fenetre_afficher_capteur;
fenetre_afficher_capteur=lookup_widget(objet,"fenetre_afficher_capteur");
gtk_widget_destroy(fenetre_afficher_capteur);
menu_capteurs=create_menu_capteurs();
gtk_widget_show(menu_capteurs);
}


void
on_afficher_capteurs_clicked            (GtkWidget       *objet,
                                        gpointer         user_data)
{

GtkWidget *menu_capteurs;
GtkWidget *fenetre_afficher_capteur;
GtkWidget *treeview1;

menu_capteurs=lookup_widget(objet,"menu_capteurs");

gtk_widget_destroy(menu_capteurs);
fenetre_afficher_capteur=lookup_widget(objet,"fenetre_afficher_capteur");
fenetre_afficher_capteur=create_fenetre_afficher_capteur();

gtk_widget_show(fenetre_afficher_capteur);

treeview1=lookup_widget(fenetre_afficher_capteur,"treeview1_capteur");

afficher_capteur(treeview1);

}


void
on_ajouter_capteurs_clicked             (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *menu_capteurs, *fenetre_ajouter_capteur;
menu_capteurs=lookup_widget(objet,"menu_capteurs");
gtk_widget_destroy(menu_capteurs);
fenetre_ajouter_capteur=create_fenetre_ajouter_capteur();
gtk_widget_show(fenetre_ajouter_capteur);
}


void
on_chercher_capteurs_clicked            (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *menu_capteurs, *fenetre_rechercher_capteur;
menu_capteurs=lookup_widget(objet,"menu_capteurs");
gtk_widget_destroy(menu_capteurs);
fenetre_rechercher_capteur=create_fenetre_rechercher_capteur();
gtk_widget_show(fenetre_rechercher_capteur);
}


void
on_supprimer_capteurs_clicked           (GtkWidget       *objet,
                                        gpointer         user_data)
{

GtkWidget *menu_capteurs, *fenetre_supprimer_capteur;
GtkWidget *combo;
	FILE *f;
	char id[30];
menu_capteurs=lookup_widget(objet,"menu_capteurs");
gtk_widget_destroy(menu_capteurs);
fenetre_supprimer_capteur=create_fenetre_supprimer_capteur();
combo=lookup_widget(fenetre_supprimer_capteur,"combobox2_capteur");
	f=fopen("capteurs.txt","r");
	while(fscanf(f,"%s %*s %*s %*s  \n",id)!=EOF)
	{
		gtk_combo_box_append_text(GTK_COMBO_BOX(combo),id);
	}
	fclose(f);
gtk_widget_show(fenetre_supprimer_capteur);
}
/*
GtkWidget *menu_capteurs, *fenetre_supprimer_capteur;
menu_capteurs=lookup_widget(objet,"menu_capteurs");
gtk_widget_destroy(menu_capteurs);
fenetre_supprimer_capteur=create_fenetre_supprimer_capteur();
gtk_widget_show(fenetre_supprimer_capteur);*/



void
on_modifier_capteurs_clicked            (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *menu_capteurs, *fenetre_modifier_capteur;
GtkWidget *combo;
	FILE *f;
	char id[30];
menu_capteurs=lookup_widget(objet,"menu_capteurs");
gtk_widget_destroy(menu_capteurs);
fenetre_modifier_capteur=create_fenetre_modifier_capteur();
combo=lookup_widget(fenetre_modifier_capteur,"combobox2_modifier");
	f=fopen("capteurs.txt","r");
	while(fscanf(f,"%s %*s %*s %*s  \n",id)!=EOF)
	{
		gtk_combo_box_append_text(GTK_COMBO_BOX(combo),id);
	}
	fclose(f);
gtk_widget_show(fenetre_modifier_capteur);
}


void
on_Capteurs_defectueux_clicked         (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *output;
defectueux("temperature.txt",h);
output=lookup_widget(objet,"label38");
gtk_label_set_text(GTK_LABEL(output),h);
strcpy(h,"");
}


void
on_rechercher_capteur_clicked                  (GtkWidget       *objet,
                                        gpointer         user_data)
{

 GtkWidget *input1,*output;
FILE *f=NULL;
 char id[20],text1[20];
input1=lookup_widget(objet,"rech_id");

output=lookup_widget(objet,"label19");

 strcpy(id, gtk_entry_get_text(GTK_ENTRY(input1)));
 if (Chercher_capteur(id)==-1){
strcpy(text1,"id introuvable");
gtk_label_set_text(GTK_LABEL(output),text1);}
else {
strcpy(text1,"id existant");
gtk_label_set_text(GTK_LABEL(output),text1);}

}


void
on_retour_menu1_capteur_clicked                (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *menu_capteurs, *fenetre_rechercher_capteur;
fenetre_rechercher_capteur=lookup_widget(objet,"fenetre_rechercher_capteur");
gtk_widget_destroy(fenetre_rechercher_capteur);
menu_capteurs=create_menu_capteurs();
gtk_widget_show(menu_capteurs);
}


void
on_supprimer_capteur_clicked                   (GtkWidget       *objet,
                                        gpointer         user_data)
{
 capteur c;
char text3[100]="";
GtkWidget *combobox1;
GtkWidget *output;

    combobox1 = lookup_widget(objet, "combobox2_capteur");
strcpy(c.id, gtk_combo_box_get_active_text(GTK_COMBO_BOX(combobox1)));

 Supprimer_capteur(c.id);
sprintf(text3,"le capteur %s est supprimé",c.id);
output=lookup_widget(objet,"label23");
gtk_label_set_text(GTK_LABEL(output),text3);
}


void
on_retour_menu2_capteur_clicked                (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *menu_capteurs, *fenetre_supprimer_capteur;
fenetre_supprimer_capteur=lookup_widget(objet,"fenetre_supprimer_capteur");
gtk_widget_destroy(fenetre_supprimer_capteur);
menu_capteurs=create_menu_capteurs();
gtk_widget_show(menu_capteurs);
}


void
on_retour_menu3_capteur_clicked                (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *menu_capteurs, *fenetre_modifier_capteur;
fenetre_modifier_capteur=lookup_widget(objet,"fenetre_modifier_capteur");
gtk_widget_destroy(fenetre_modifier_capteur);
menu_capteurs=create_menu_capteurs();
gtk_widget_show(menu_capteurs);
}


void
on_modifier_capteur_clicked                    (GtkWidget       *objet,
                                        gpointer         user_data)
{
capteur c;
  GtkWidget *input1;
  GtkWidget *input2;
  GtkWidget *input3;
  GtkWidget *input4;
  GtkWidget *output;
  GtkWidget *combobox1,*combobox2;
char text3[50];
char r1[20];
char r2[20];
char r3[20];
  int jj1,mm1,aa1;
 

 
  GtkWidget *fenetre_modifier_capteur;


fenetre_modifier_capteur=lookup_widget(objet,"fenetre_modifier_capteur");
 output=lookup_widget(objet,"label208");
	 
 combobox2 = lookup_widget(objet, "combobox2_modifier");
 input2= lookup_widget(objet,"jj");
input3=lookup_widget(objet,"mm");
input4=lookup_widget(objet,"aa");
 combobox1 = lookup_widget(objet, "combobox3");

 




if (y==1) strcpy(c.type, "temperature");
if (y==2) strcpy(c.type, "humidité");
 


 strcpy(c.marque, gtk_combo_box_get_active_text(GTK_COMBO_BOX(combobox1)));
 strcpy(c.id, gtk_combo_box_get_active_text(GTK_COMBO_BOX(combobox2)));
jj1= gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(input2));
mm1= gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(input3));
aa1= gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(input4));

sprintf(r1,"%d",jj1);
strcat(r1,"/");

sprintf(r2,"%d",mm1);
strcat(r1,r2);
strcat(r1,"/");

sprintf(r3,"%d",aa1);
strcat(r1,r3);

strcpy(c.d_ajout,r1);

 
 Modifier_capteur(c);
sprintf(text3,"le capteur %s est modifié",c.id);

gtk_label_set_text(GTK_LABEL(output),text3);

}


void
on_radiobutton1_toggled                (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if (gtk_toggle_button_get_active(GTK_RADIO_BUTTON(togglebutton)))
x=1;
}


void
on_radiobutton2_toggled                (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if (gtk_toggle_button_get_active(GTK_RADIO_BUTTON(togglebutton)))
x=2;
}


void
on_radiobutton4_toggled                (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if (gtk_toggle_button_get_active(GTK_RADIO_BUTTON(togglebutton)))
y=1;
}


void
on_radiobutton3_toggled                (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if (gtk_toggle_button_get_active(GTK_RADIO_BUTTON(togglebutton)))
y=2;
}


void
on_radiobutton5_toggled                (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if (gtk_toggle_button_get_active(GTK_RADIO_BUTTON(togglebutton)))
w=1;
}


void
on_radiobutton6_toggled                (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if (gtk_toggle_button_get_active(GTK_RADIO_BUTTON(togglebutton)))
w=2;
}



void
on_retour_menu_valeur_clicked          (GtkWidget      *objet,
                                        gpointer         user_data)
{
GtkWidget *menu_capteurs, *fenetre_afficher_valeur;
fenetre_afficher_valeur=lookup_widget(objet,"fenetre_afficher_valeur");
gtk_widget_destroy(fenetre_afficher_valeur);
menu_capteurs=create_menu_capteurs();
gtk_widget_show(menu_capteurs);
}




void
on_ajouter_valeurs_clicked              (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *menu_capteurs, *fenetre_ajouter_valeur;
GtkWidget *combo;
	FILE *f;
	char id[30];
menu_capteurs=lookup_widget(objet,"menu_capteurs");
gtk_widget_destroy(menu_capteurs);
fenetre_ajouter_valeur=create_fenetre_ajouter_valeur();
combo=lookup_widget(fenetre_ajouter_valeur,"combobox4");
	f=fopen("capteurs.txt","r");
	while(fscanf(f,"%s %*s %*s %*s  \n",id)!=EOF)
	{
		gtk_combo_box_append_text(GTK_COMBO_BOX(combo),id);
	}
	fclose(f);
gtk_widget_show(fenetre_ajouter_valeur);
}


void
on_radiobutton7_toggled                (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if (gtk_toggle_button_get_active(GTK_RADIO_BUTTON(togglebutton)))
z=2;
}


void
on_radiobutton8_toggled                (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if (gtk_toggle_button_get_active(GTK_RADIO_BUTTON(togglebutton)))
z=1;
}


void
on_retour_vers_menu_valeur_clicked     (GtkWidget      *objet,
                                        gpointer         user_data)
{
GtkWidget *menu_capteurs, *fenetre_ajouter_valeur;
fenetre_ajouter_valeur=lookup_widget(objet,"fenetre_ajouter_valeur");
gtk_widget_destroy(fenetre_ajouter_valeur);
menu_capteurs=create_menu_capteurs();
gtk_widget_show(menu_capteurs);
}

void
on_ajouter_valeur_clicked              (GtkWidget       *objet,

                                        gpointer         user_data)
{
char id[20],val[20];
  GtkWidget *input1;
  GtkWidget *input2;
  GtkWidget *input3;
  GtkWidget *input4;


    

  GtkWidget *combobox1;

  int jj,mm,aa;
 

 
  GtkWidget *fenetre_ajouter_valeur;


fenetre_ajouter_valeur=lookup_widget(objet,"fenetre_ajouter_valeur");
 
	 
 input1 = lookup_widget(objet, "entry2");
 input2= lookup_widget(objet,"spinbutton1");
input3=lookup_widget(objet,"spinbutton2");
input4=lookup_widget(objet,"spinbutton3");
 combobox1 = lookup_widget(objet, "combobox4");

 strcpy(id, gtk_combo_box_get_active_text(GTK_COMBO_BOX(combobox1)));



 strcpy(val, gtk_entry_get_text(GTK_ENTRY(input1)));



 

jj= gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(input2));
mm= gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(input3));
aa= gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(input4));
  if (w==1)  ajouter_valeur(id,jj,mm,aa,val,"temperature.txt");
if (w==2)  ajouter_valeur(id,jj,mm,aa,val,"humidité.txt");
 
}



/////////////////////WALID--ouvrier//////////////////////////////



void
on_retour_vers_menu_ouvrier_clicked            (GtkWidget       *objet,
                                        	gpointer         user_data)
{
GtkWidget *menu_ouvriers, *fenetre_ajout_ouvrier;

	fenetre_ajout_ouvrier=lookup_widget(objet,"fenetre_ajout_ouvrier");
	

	gtk_widget_destroy(fenetre_ajout_ouvrier);
	menu_ouvriers=create_menu_ouvriers();
	gtk_widget_show(menu_ouvriers);
}
                           
void
on_ajouter_ouvrier_clicked                     (GtkWidget       *objet,
                                       	 	gpointer         user_data)
{
ouvrier o;

GtkWidget *input1, *input2, *input3, *input4, *input5, *input6;
GtkWidget *fenetre_ajout_ouvrier;

fenetre_ajout_ouvrier=lookup_widget(objet,"fenetre_ajout_ouvrier");

input1=lookup_widget(objet,"nom"); 
input2=lookup_widget(objet,"numero");
input3=lookup_widget(objet,"email");
input4=lookup_widget(objet,"cin");
input5=lookup_widget(objet,"sexe");


strcpy(o.Nomouvrier,gtk_entry_get_text(GTK_ENTRY(input1)));
strcpy(o.Numeroouvrier,gtk_entry_get_text(GTK_ENTRY(input2)));
strcpy(o.Emailouvrier,gtk_entry_get_text(GTK_ENTRY(input3)));
strcpy(o.CINouvrier,gtk_entry_get_text(GTK_ENTRY(input4)));
strcpy(o.Sexeouvrier,gtk_entry_get_text(GTK_ENTRY(input5)));


ajouter_ouvrier(o);
}



void
on_afficher_ouvrier_clicked                    (GtkWidget        *objet,
                                        	gpointer         user_data)
{
GtkWidget *fenetre_ajout_ouvrier;
GtkWidget *fenetre_afficher_ouvrier;
GtkWidget *treeview1_ouvrier;

fenetre_ajout_ouvrier=lookup_widget(objet,"fenetre_ajout_ouvrier");

gtk_widget_destroy(fenetre_ajout_ouvrier);
fenetre_afficher_ouvrier=lookup_widget(objet,"fenetre_afficher_ouvrier");
fenetre_afficher_ouvrier=create_fenetre_afficher_ouvrier();

gtk_widget_show(fenetre_afficher_ouvrier);

treeview1_ouvrier=lookup_widget(fenetre_afficher_ouvrier,"treeview1_ouvrier");

afficher_ouvrier(treeview1_ouvrier);
}


void
on_treeview1_ouvrier_row_activated             (GtkTreeView     *treeview1_ouvrier,
                                        	GtkTreePath     *path,
                                        	GtkTreeViewColumn *column,
                                        	gpointer         user_data)
{
	GtkTreeIter iter;
	gchar* nom;
	gchar* numero;
	gchar* email;
	gchar* cin;
	gchar* sexe;
	
	ouvrier o;

	GtkTreeModel *model = gtk_tree_view_get_model(treeview1_ouvrier);

	if(gtk_tree_model_get_iter(model, &iter, path))
	{
		//obtention des valeurs de la ligne selectionnée
		gtk_tree_model_get (GTK_LIST_STORE(model),&iter, 0, &nom, 1, &numero, 2, &email, 3, &cin, 4, &sexe,-1);
		//copie des valeurs dans la variable o de type ouvrier pour passer a la fonction de suppression 
		strcpy(o.Nomouvrier,nom);
		strcpy(o.Numeroouvrier,numero);
		strcpy(o.Emailouvrier,email);
		strcpy(o.CINouvrier,cin);
		strcpy(o.Sexeouvrier,sexe);
		
		//appel de la fonction de suppression
		supprimer_ouvrier(o);
		//mise a jour de l'affichage de la treeview
		afficher_ouvrier(treeview1_ouvrier);
	}
}



void
on_retour_ouvrier_clicked                      (GtkWidget       *objet,
                                        	gpointer         user_data)
{
	GtkWidget *menu_ouvriers, *fenetre_afficher_ouvrier;

	fenetre_afficher_ouvrier=lookup_widget(objet,"fenetre_afficher_ouvrier");
	

	gtk_widget_destroy(fenetre_afficher_ouvrier);
	menu_ouvriers=create_menu_ouvriers();
	gtk_widget_show(menu_ouvriers);
}



void
on_afficher_ouvriers_clicked             (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *menu_ouvriers;
GtkWidget *fenetre_afficher_ouvrier;
GtkWidget *treeview1_ouvrier;

menu_ouvriers=lookup_widget(objet,"menu_ouvriers");
gtk_widget_destroy(menu_ouvriers);

fenetre_afficher_ouvrier=lookup_widget(objet,"fenetre_afficher_ouvrier");
fenetre_afficher_ouvrier=create_fenetre_afficher_ouvrier();

gtk_widget_show(fenetre_afficher_ouvrier);

treeview1_ouvrier=lookup_widget(fenetre_afficher_ouvrier,"treeview1_ouvrier");

afficher_ouvrier(treeview1_ouvrier);
}

void
on_ajouter_ouvriers_clicked              (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *menu_ouvriers, *fenetre_ajout_ouvrier;

	menu_ouvriers=lookup_widget(objet,"menu_ouvriers");
	

	gtk_widget_destroy(menu_ouvriers);
	fenetre_ajout_ouvrier=create_fenetre_ajout_ouvrier();
	gtk_widget_show(fenetre_ajout_ouvrier);
}

void
on_chercher_ouvriers_clicked             (GtkWidget       *objet,
                                          gpointer         user_data)
{
GtkWidget *menu_ouvriers, *fenetre_rechercher_ouvrier;

	menu_ouvriers=lookup_widget(objet,"menu_ouvriers");
	

	gtk_widget_destroy(menu_ouvriers);
	fenetre_rechercher_ouvrier=create_fenetre_rechercher_ouvrier();
	gtk_widget_show(fenetre_rechercher_ouvrier);
}

void
on_supprimer_ouvriers_clicked              (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *menu_ouvriers, *fenetre_supprimer_ouvrier;

	menu_ouvriers=lookup_widget(objet,"menu_ouvriers");
	

	gtk_widget_destroy(menu_ouvriers);
	fenetre_supprimer_ouvrier=create_fenetre_supprimer_ouvrier();
	gtk_widget_show(fenetre_supprimer_ouvrier);
}

void
on_modifier_ouvriers_clicked             (GtkWidget       *objet,
                                         gpointer         user_data)
{
GtkWidget *menu_ouvriers, *fenetre_modifier_ouvrier;

	menu_ouvriers=lookup_widget(objet,"menu_ouvriers");
	

	gtk_widget_destroy(menu_ouvriers);
	fenetre_modifier_ouvrier=create_fenetre_modifier_ouvrier();
	gtk_widget_show(fenetre_modifier_ouvrier);

}

void
on_rechercher_ouvrier_clicked                  (GtkWidget       *objet,
                                        	gpointer         user_data)
{
GtkWidget *cin,*sortie;
char Cin[20];
FILE *f=NULL;
	char chnom[20],chnumero[20],chemail[20];
	char chcin[20],chsexe[20];
int trouv=-1;


cin = lookup_widget (objet, "rech_id_ouvrier");
strcpy(Cin, gtk_entry_get_text(GTK_ENTRY(cin)));


f=fopen("ouvriers.txt","r");
if(f!=NULL)
{
while(fscanf(f,"%s %s %s %s %s \n",chnom,chnumero,chemail,chcin,chsexe)!=EOF)
{

if (strcmp(chcin,Cin)==0)
{strcat(chnom," ");
strcat(chnom,chcin);
strcat(chnom," ");
strcat(chnom,chnumero);
sortie = lookup_widget(objet, "label19");
gtk_label_set_text(GTK_LABEL(sortie),chnom);
trouv=1;
}
}
if (trouv!=1)
{
sortie = lookup_widget(objet, "label19");
gtk_label_set_text(GTK_LABEL(sortie),"Cin n'existe pas");
}
}
}

void
on_retour_menu1_ouvrier_clicked                (GtkWidget       *objet,
                                        	gpointer         user_data)
{
GtkWidget *menu_ouvriers, *fenetre_rechercher_ouvrier;

	fenetre_rechercher_ouvrier=lookup_widget(objet,"fenetre_rechercher_ouvrier");
	

	gtk_widget_destroy(fenetre_rechercher_ouvrier);
	menu_ouvriers=create_menu_ouvriers();
	gtk_widget_show(menu_ouvriers);
}

void
on_supprimer_ouvrier_clicked                   (GtkWidget       *objet,
                                        	gpointer         user_data)
{
GtkWidget *cin,*sortie;
char Cin[20];

int trouv;
cin = lookup_widget (objet, "supp_id_ouvrier");

strcpy(Cin, gtk_entry_get_text(GTK_ENTRY(cin)));
trouv=Chercher_ouvrier (Cin);

if (trouv==1)
{
Supprimer_ouvrier(Cin);
sortie = lookup_widget(objet, "label23");
gtk_label_set_text(GTK_LABEL(sortie),"ouvrier supprimé avec succée!");
//printf("\n ouvrier supprimer avec succée!");
}
else 
{
sortie = lookup_widget(objet, "label23");
gtk_label_set_text(GTK_LABEL(sortie),"Cin introuvable!");

}
}

void
on_retour_menu2_ouvrier_clicked                (GtkWidget       *objet,
                                       		 gpointer         user_data)
{
GtkWidget *fenetre_supprimer_ouvrier, *menu_ouvriers;

	fenetre_supprimer_ouvrier=lookup_widget(objet,"fenetre_supprimer_ouvrier");
	

	gtk_widget_destroy(fenetre_supprimer_ouvrier);
	menu_ouvriers=create_menu_ouvriers();
	gtk_widget_show(menu_ouvriers);
}

void
on_modifier_ouvrier_clicked            		(GtkWidget       *objet,
                                       		 gpointer         user_data)
{
GtkWidget *cin,*sortie;
GtkWidget *modifier_ouvrier, *modification_ouvrier;
char Cin[20];

int trouv;
cin = lookup_widget (objet, "modif_id_ouvrier");

strcpy(Cin, gtk_entry_get_text(GTK_ENTRY(cin)));
trouv=Chercher_ouvrier (Cin);

if (trouv==1)
{
sortie = lookup_widget(objet, "label27");
gtk_label_set_text(GTK_LABEL(sortie),"ouvrier trouvé!");

modifier_ouvrier=lookup_widget(objet,"modifier_ouvrier");
	

	//gtk_widget_destroy(modifier_ouvrier);
	modification_ouvrier=create_modification_ouvrier();
	gtk_widget_show(modification_ouvrier);
}
else 
{
sortie = lookup_widget(objet, "label27");
gtk_label_set_text(GTK_LABEL(sortie),"Cin introuvable!");

}
}


void
on_retour_menu3_ouvrier_clicked                (GtkWidget       *objet,
                                       		 gpointer         user_data)
{
GtkWidget *fenetre_modifier_ouvrier, *menu_ouvriers;

	fenetre_modifier_ouvrier=lookup_widget(objet,"fenetre_modifier_ouvrier");
	

	gtk_widget_destroy(fenetre_modifier_ouvrier);
	menu_ouvriers=create_menu_ouvriers();
	gtk_widget_show(menu_ouvriers);
}



void
on_retour_menu4_ouvrier_clicked        		(GtkWidget       *objet,
                                       		 gpointer         user_data)
{
GtkWidget *modification_ouvrier, *menu_ouvriers;

	modification_ouvrier=lookup_widget(objet,"modification_ouvrier");
	

	gtk_widget_destroy(modification_ouvrier);
	menu_ouvriers=create_menu_ouvriers();
	gtk_widget_show(menu_ouvriers);
}


void
on_modifier_confirmer_ouvrier_clicked  		(GtkWidget       *objet,
                                       		 gpointer         user_data)
{
GtkWidget *cin;
GtkWidget *input1, *input2, *input3, *input4, *input5;

	char chnom[20],chnumero[20],chemail[20],Cin[20];
	char chcin[20],chsexe[20];
FILE *f=NULL;
FILE *p=NULL;


cin = lookup_widget (objet, "modif2_cin_ouvrier");
strcpy(Cin, gtk_entry_get_text(GTK_ENTRY(cin)));

f=fopen("ouvriers.txt","r");
p=fopen("temp.txt","w");
if(f!=NULL)
{
while(fscanf(f,"%s %s %s %s %s \n",chnom,chnumero,chemail,chcin,chsexe)!=EOF)
{
if (strcmp(chcin,Cin)==0)
{
input1=lookup_widget(objet,"nnom"); 
input2=lookup_widget(objet,"nnumero");
input3=lookup_widget(objet,"nemail");
input4=lookup_widget(objet,"ncin");
input5=lookup_widget(objet,"nsexe");


strcpy(chnom,gtk_entry_get_text(GTK_ENTRY(input1)));
strcpy(chnumero,gtk_entry_get_text(GTK_ENTRY(input2)));
strcpy(chemail,gtk_entry_get_text(GTK_ENTRY(input3)));
strcpy(chcin,gtk_entry_get_text(GTK_ENTRY(input4)));
strcpy(chsexe,gtk_entry_get_text(GTK_ENTRY(input5)));

fprintf(p,"%s %s %s %s %s \n",chnom,chnumero,chemail,chcin,chsexe);
}
else
fprintf(p,"%s %s %s %s %s \n",chnom,chnumero,chemail,chcin,chsexe);
}
fclose(f);
fclose(p);
}
remove("ouvriers.txt");
rename("temp.txt","ouvriers.txt");

}


void
on_modif_chercher_ouvrier_clicked      		(GtkWidget       *objet,
                                       		 gpointer         user_data)
{
GtkWidget *cin,*sortie;
GtkWidget *modifier_ouvrier, *modification_ouvrier;
char Cin[20];

int trouv;
cin = lookup_widget (objet, "modif2_cin_ouvrier");

strcpy(Cin, gtk_entry_get_text(GTK_ENTRY(cin)));
trouv=Chercher_ouvrier (Cin);

if (trouv==1)
{
sortie = lookup_widget(objet, "label29");
gtk_label_set_text(GTK_LABEL(sortie),"ouvrier trouvé!");

}
else 
{
sortie = lookup_widget(objet, "label29");
gtk_label_set_text(GTK_LABEL(sortie),"Cin introuvable!");

}
}
////////////////////////OUSSEMA_CLIENT///////////////


void
on_ajouter_clicked                     (GtkWidget       *objet,
                                        gpointer         user_data)
{
Client c;

GtkWidget *input1, *input2, *input3, *input4, *input5, *input6;
GtkWidget *fenetre_ajout;

fenetre_ajout=lookup_widget(objet,"fenetre_ajout");

input1=lookup_widget(objet,"nom"); 
input2=lookup_widget(objet,"prenom");
input3=lookup_widget(objet,"email");
input4=lookup_widget(objet,"id");
input5=lookup_widget(objet,"numero");


strcpy(c.Nomclient,gtk_entry_get_text(GTK_ENTRY(input1)));
strcpy(c.Prenomclient,gtk_entry_get_text(GTK_ENTRY(input2)));
strcpy(c.Emailclient,gtk_entry_get_text(GTK_ENTRY(input3)));
strcpy(c.IDclient,gtk_entry_get_text(GTK_ENTRY(input4)));
strcpy(c.Numeroclient,gtk_entry_get_text(GTK_ENTRY(input5)));


ajouter_client(c);
}


void
on_afficher_clicked                    (GtkWidget        *objet,
                                        gpointer         user_data)
{
GtkWidget *fenetre_ajout;
GtkWidget *fenetre_afficher;
GtkWidget *treeview1;

fenetre_ajout=lookup_widget(objet,"fenetre_ajout");

gtk_widget_destroy(fenetre_ajout);
fenetre_afficher=lookup_widget(objet,"fenetre_afficher");
fenetre_afficher=create_fenetre_afficher();

gtk_widget_show(fenetre_afficher);

treeview1=lookup_widget(fenetre_afficher,"treeview1");

afficher_client(treeview1);
}


void
on_treeview1_row_activated             (GtkTreeView     *treeview1,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data)
{
	GtkTreeIter iter;
	gchar* nom;
	gchar* prenom;
	gchar* email;
	gchar* id;
	gchar* numero;
	
	Client c;

	GtkTreeModel *model = gtk_tree_view_get_model(treeview1);

	if(gtk_tree_model_get_iter(model, &iter, path))
	{
		//obtention des valeurs de la ligne selectionnée
		gtk_tree_model_get (GTK_LIST_STORE(model),&iter, 0, &nom, 1, &prenom, 2, &email, 3, &id, 4, &numero,-1);
		//copie des valeurs dans la variable t de type troupeau pour passer a la fonction de suppression 
		strcpy(c.Nomclient,nom);
		strcpy(c.Prenomclient,prenom);
		strcpy(c.Emailclient,email);
		strcpy(c.IDclient,id);
		strcpy(c.Numeroclient,numero);
		
		//appel de la fonction de suppression
		supprimer_client(c);
		//mise a jour de l'affichage de la treeview
		afficher_client(treeview1);
	}



}


void
on_retour_clicked                      (GtkWidget       *objet,
                                        gpointer         user_data)
{
	GtkWidget *menu_client, *fenetre_afficher;

	fenetre_afficher=lookup_widget(objet,"fenetre_afficher");
	

	gtk_widget_destroy(fenetre_afficher);
	menu_client=create_menu_client();
	gtk_widget_show(menu_client);
}


void
on_retour_vers_menu_clicked            (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *menu_client, *fenetre_ajout;

	fenetre_ajout=lookup_widget(objet,"fenetre_ajout");
	

	gtk_widget_destroy(fenetre_ajout);
	menu_client=create_menu_client();
	gtk_widget_show(menu_client);
}


void
on_afficher_client_clicked             (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *menu_clients;
GtkWidget *fenetre_afficher;
GtkWidget *treeview1;

menu_clients=lookup_widget(objet,"menu_clients");
gtk_widget_destroy(menu_clients);

fenetre_afficher=lookup_widget(objet,"fenetre_afficher");
fenetre_afficher=create_fenetre_afficher();

gtk_widget_show(fenetre_afficher);

treeview1=lookup_widget(fenetre_afficher,"treeview1");

afficher_client(treeview1);
}


void
on_ajouter_client_clicked              (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *menu_clients, *fenetre_ajouter;

	menu_clients=lookup_widget(objet,"menu_clients");
	

	gtk_widget_destroy(menu_clients);
	fenetre_ajouter=create_fenetre_ajouter();
	gtk_widget_show(fenetre_ajouter);
}


void
on_chercher_client_clicked             (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *menu_client, *rechercher_client;

	menu_client=lookup_widget(objet,"menu_client");
	

	gtk_widget_destroy(menu_client);
	rechercher_client=create_rechercher_client();
	gtk_widget_show(rechercher_client);
}


void
on_supprimer_client_enter              (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *menu_clients, *supprimer_client;

	menu_clients=lookup_widget(objet,"menu_clients");
	

	gtk_widget_destroy(menu_clients);
	supprimer_client=create_supprimer_client();
	gtk_widget_show(supprimer_client);
}


void
on_modifier_client_clicked             (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *menu_clients, *modifier_client;

	menu_clients=lookup_widget(objet,"menu_clients");
	

	gtk_widget_destroy(menu_clients);
	modifier_client=create_modifier_client();
	gtk_widget_show(modifier_client);

}


void
on_rendez_vous_clicked                 (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *menu_clients, *rendezvous_client;

	menu_clients=lookup_widget(objet,"menu_clients");
	

	gtk_widget_destroy(menu_clients);
	rendezvous_client=create_rendezvous_client();
	gtk_widget_show(rendezvous_client);
}


void
on_rechercher_clicked                  (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *id,*sortie;
char Id[20];
FILE *f=NULL;
char chId[20], chNum[20];
char Rnom[50],Rprenom[20],Remail[20];
int trouv=-1;


id = lookup_widget (objet, "rech_id");
strcpy(Id, gtk_entry_get_text(GTK_ENTRY(id)));


f=fopen("clients.txt","r");
if(f!=NULL)
{
while(fscanf(f,"%s %s %s %s %s \n",Rnom,Rprenom,Remail,chId,chNum)!=EOF)
{

if (strcmp(chId,Id)==0)
{strcat(Rnom," ");
strcat(Rnom,Rprenom);
strcat(Rnom," ");
strcat(Rnom,chNum);
sortie = lookup_widget(objet, "label19");
gtk_label_set_text(GTK_LABEL(sortie),Rnom);
trouv=1;
}



}
if (trouv!=1)
{
sortie = lookup_widget(objet, "label19");
gtk_label_set_text(GTK_LABEL(sortie),"Id n'existe pas");
}
}
}


void
on_retour_menu1_clicked                (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *menu_client, *rechercher_client;

	rechercher_client=lookup_widget(objet,"rechercher_client");
	

	gtk_widget_destroy(rechercher_client);
	menu_client=create_menu_client();
	gtk_widget_show(menu_client);
}


void
on_retour_menu3_clicked                (GtkWidget       *objet,
                                        gpointer         user_data)
{

}


void
on_modifier_clicked                    (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *id,*sortie;
GtkWidget *modifier_client, *modification_client;
char Id[20];

int trouv;
id = lookup_widget (objet, "modif_id");

strcpy(Id, gtk_entry_get_text(GTK_ENTRY(id)));
trouv=Chercher_client (Id);

if (trouv==1)
{
sortie = lookup_widget(objet, "label34");
gtk_label_set_text(GTK_LABEL(sortie),"Client trouvée!");
//////
modifier_client=lookup_widget(objet,"modifier_client");
	

	//gtk_widget_destroy(modifier_client);
	modification_client=create_modification_client();
	gtk_widget_show(modification_client);
}
else 
{
sortie = lookup_widget(objet, "label34");
gtk_label_set_text(GTK_LABEL(sortie),"Id introuvable!");

}
}


void
on_supprimer_clicked                   (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *id,*sortie;
char Id[20];

int trouv;
id = lookup_widget (objet, "supp_id");

strcpy(Id, gtk_entry_get_text(GTK_ENTRY(id)));
trouv=Chercher_client (Id);

if (trouv==1)
{
Supprimer_client(Id);
sortie = lookup_widget(objet, "label23");
gtk_label_set_text(GTK_LABEL(sortie),"Client supprimé avec succée!");
//printf("\n Client supprimer avec succée!");
}
else 
{
sortie = lookup_widget(objet, "label23");
gtk_label_set_text(GTK_LABEL(sortie),"Id introuvable!");

}
}


void
on_retour_menu2_clicked                (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *supprimer_client, *menu_client;

	supprimer_client=lookup_widget(objet,"supprimer_client");
	

	gtk_widget_destroy(supprimer_client);
	menu_client=create_menu_client();
	gtk_widget_show(menu_client);
}


void
on_modifier_confirmer_clicked          (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *id;
GtkWidget *input1, *input2, *input3, *input4, *input5;

char chId[20],Id[20], Rnum[20];
char Rnom[20],Rprenom[20],Remail[20];
FILE *f=NULL;
FILE *p=NULL;


id = lookup_widget (objet, "modif2_id");
strcpy(Id, gtk_entry_get_text(GTK_ENTRY(id)));

f=fopen("clients.txt","r");
p=fopen("temp.txt","w");
if(f!=NULL)
{
while(fscanf(f,"%s %s %s %s %s \n",Rnom,Rprenom,Remail,chId,Rnum)!=EOF)
{
if (strcmp(chId,Id)==0)
{
input1=lookup_widget(objet,"mnom"); 
input2=lookup_widget(objet,"mprenom");
input3=lookup_widget(objet,"memail");
input4=lookup_widget(objet,"mid");
input5=lookup_widget(objet,"mnumero");


strcpy(Rnom,gtk_entry_get_text(GTK_ENTRY(input1)));
strcpy(Rprenom,gtk_entry_get_text(GTK_ENTRY(input2)));
strcpy(Remail,gtk_entry_get_text(GTK_ENTRY(input3)));
strcpy(chId,gtk_entry_get_text(GTK_ENTRY(input4)));
strcpy(Rnum,gtk_entry_get_text(GTK_ENTRY(input5)));

fprintf(p,"%s %s %s %s %s \n",Rnom,Rprenom,Remail,chId,Rnum);
}
else
fprintf(p,"%s %s %s %s %s \n",Rnom,Rprenom,Remail,chId,Rnum);
}
fclose(f);
fclose(p);
}
remove("clients.txt");
rename("temp.txt","clients.txt");

}


void
on_retour_menu5_clicked                (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *modification_client, *menu_client;

	modification_client=lookup_widget(objet,"modification_client");
	

	gtk_widget_destroy(modification_client);
	menu_client=create_menu_client();
	gtk_widget_show(menu_client);
}


void
on_modif_chercher_clicked              (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *id,*sortie;
GtkWidget *modifier_client, *modification_client;
char Id[20];

int trouv;
id = lookup_widget (objet, "modif2_id");

strcpy(Id, gtk_entry_get_text(GTK_ENTRY(id)));
trouv=Chercher_client (Id);

if (trouv==1)
{
sortie = lookup_widget(objet, "label37");
gtk_label_set_text(GTK_LABEL(sortie),"Client trouvée!");

}
else 
{
sortie = lookup_widget(objet, "label37");
gtk_label_set_text(GTK_LABEL(sortie),"Id introuvable!");

}
}


void
on_valider_rdv_clicked                 (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *Combobox2;
//GtkWidget *Combobox1;
char id_client[20][10];
int n,i;

/*
Date dt_resr;
Jour=lookup_widget(objet_graphique, "jour");
Mois=lookup_widget(objet_graphique, "mois");
Annee=lookup_widget(objet_graphique, "annee");
Combobox1=lookup_widget(objet_graphique, "combobox1");
Combobox2=lookup_widget(objet_graphique, "combobox2");

dt_resr.jour=gtk_spin_button_get_value_as_int (GTK_SPIN_BUTTON (Jour));
dt_resr.mois=gtk_spin_button_get_value_as_int (GTK_SPIN_BUTTON (Mois));
dt_resr.annee=gtk_spin_button_get_value_as_int (GTK_SPIN_BUTTON (Annee));

if(strcmp("9h==>12h15",gtk_combo_box_get_active_text(GTK_COMBO_BOX(Combobox1)))==0)
hr_resr=1;
else
hr_resr=2;*/
//Combobox1=lookup_widget(objet_graphique, "combobox1");
Combobox2=lookup_widget(objet_graphique, "combobox2");
/*if(strcmp("9h==>12h15",gtk_combo_box_get_active_text(GTK_COMBO_BOX(Combobox1)))==0)
hr_resr=1;
else
hr_resr=2;*/

n=tableau_client_disponible(id_client);
for(i=0; i<n; i++)
{
  gtk_combo_box_append_text (GTK_COMBO_BOX (Combobox2),_(id_client[i]));

}
}


void
on_confirmer_rdv_clicked               (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *Jour;
GtkWidget *Mois;
GtkWidget *Anneer;
GtkWidget *Combobox1;
GtkWidget *Combobox2;
GtkWidget *sortie;
ReservationClient s;

Combobox1=lookup_widget(objet_graphique, "combobox1");
sortie=lookup_widget(objet_graphique, "label40");
Jour=lookup_widget(objet_graphique, "jour");
Mois=lookup_widget(objet_graphique, "mois");
Anneer=lookup_widget(objet_graphique, "annee");
Combobox2=lookup_widget(objet_graphique, "combobox2");

s.dt_resr.jour=gtk_spin_button_get_value_as_int (GTK_SPIN_BUTTON (Jour));
s.dt_resr.mois=gtk_spin_button_get_value_as_int (GTK_SPIN_BUTTON (Mois));
s.dt_resr.annee=gtk_spin_button_get_value_as_int (GTK_SPIN_BUTTON (Anneer));

if(strcmp("9h==>12h15",gtk_combo_box_get_active_text(GTK_COMBO_BOX(Combobox1)))==0)
s.hr_resr=1;
else
s.hr_resr=2;

strcpy(s.IDclient,gtk_combo_box_get_active_text(GTK_COMBO_BOX(Combobox2)));
reservation_client(s);
gtk_label_set_text(GTK_LABEL(sortie),"Reservation reussite!");
};




void
on_retour_menu6_clicked                (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *rendezvous_client, *menu_client;

	rendezvous_client=lookup_widget(objet,"rendezvous_client");
	

	gtk_widget_destroy(rendezvous_client);
	menu_client=create_menu_client();
	gtk_widget_show(menu_client);
}


void
on_retour_menu7_clicked                (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *plus_seche, *menu_client;

	plus_seche=lookup_widget(objet,"plus_seche");
	

	gtk_widget_destroy(plus_seche);
	menu_client=create_menu_client();
	gtk_widget_show(menu_client);
}


void
on_afficher_plusseche_clicked          (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *sortie;
GtkWidget *Annee;
int annee,seche;
char plusseche[20];


Annee=lookup_widget(objet_graphique, "anneeseche");
annee=gtk_spin_button_get_value_as_int (GTK_SPIN_BUTTON (Annee));
seche=annee_plus_seche(annee);


sprintf(plusseche,"%d",seche);
sortie = lookup_widget(objet_graphique, "label47");
gtk_label_set_text(GTK_LABEL(sortie),plusseche);
}



void
on_annee_plusseche_clicked             (GtkButton       *objet,
                                        gpointer         user_data)
{
GtkWidget *plus_seche, *menu_client;

	menu_client=lookup_widget(objet,"menu_client");
	

	gtk_widget_destroy(menu_client);
	plus_seche=create_plus_seche();
	gtk_widget_show(plus_seche);
}

///////////////////////////////////CHAIMA_Troupeau/////////////////
void
on_retour_vers_menu_troupeau_clicked    (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *menu_troupeaux, *fenetre_ajout_troupeau;

	fenetre_ajout_troupeau=lookup_widget(objet,"fenetre_ajout_troupeau");
	

	gtk_widget_destroy(fenetre_ajout_troupeau);
	menu_troupeaux=create_menu_troupeaux();
	gtk_widget_show(menu_troupeaux);
}

void
on_ajouter_troupeau_clicked             (GtkWidget       *objet,
                                        gpointer         user_data)
{
Troupeau t;

GtkWidget *input1, *input2, *input3, *input4, *input5, *input6;
GtkWidget *fenetre_ajout_troupeau;

fenetre_ajout_troupeau=lookup_widget(objet,"fenetre_ajout_troupeau");

input1=lookup_widget(objet,"identifiantid"); 
input2=lookup_widget(objet,"type");
input3=lookup_widget(objet,"dateajout");
input4=lookup_widget(objet,"sexe");
input5=lookup_widget(objet,"poids");


strcpy(t.IDtroupeau,gtk_entry_get_text(GTK_ENTRY(input1)));
strcpy(t.Typetroupeau,gtk_entry_get_text(GTK_ENTRY(input2)));
strcpy(t.Datetroupeau,gtk_entry_get_text(GTK_ENTRY(input3)));
strcpy(t.Sexetroupeau,gtk_entry_get_text(GTK_ENTRY(input4)));
strcpy(t.Poidstroupeau,gtk_entry_get_text(GTK_ENTRY(input5)));


ajouter_troupeau(t);
}

void
on_afficher_troupeau_clicked            (GtkWidget        *objet,
                                        gpointer         user_data)
{
GtkWidget *fenetre_ajout_troupeau;
GtkWidget *fenetre_afficher_troupeau;
GtkWidget *treeview1_troupeau;

fenetre_ajout_troupeau=lookup_widget(objet,"fenetre_ajout_troupeau");

gtk_widget_destroy(fenetre_ajout_troupeau);
fenetre_afficher_troupeau=lookup_widget(objet,"fenetre_afficher_troupeau");
fenetre_afficher_troupeau=create_fenetre_afficher_troupeau();

gtk_widget_show(fenetre_afficher_troupeau);

treeview1_troupeau=lookup_widget(fenetre_afficher_troupeau,"treeview1_troupeau");

afficher_troupeau(treeview1_troupeau);
}

void
on_treeview1_troupeau_row_activated    (GtkTreeView     *treeview1_troupeau,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data)
{
	GtkTreeIter iter;
	gchar* identifiantid;
	gchar* type;
	gchar* dateajout;
	gchar* sexe;
	gchar* poids;
	
	Troupeau t;

	GtkTreeModel *model = gtk_tree_view_get_model(treeview1_troupeau);

	if(gtk_tree_model_get_iter(model, &iter, path))
	{
		//obtention des valeurs de la ligne selectionnée
		gtk_tree_model_get (GTK_LIST_STORE(model),&iter, 0, &identifiantid, 1, &type, 2, &dateajout, 3, &sexe, 4, &poids,-1);
		//copie des valeurs dans la variable t de type troupeau pour passer a la fonction de suppression 
		strcpy(t.IDtroupeau,identifiantid);
		strcpy(t.Typetroupeau,type);
		strcpy(t.Datetroupeau,dateajout);
		strcpy(t.Sexetroupeau,sexe);
		strcpy(t.Poidstroupeau,poids);
		
		//appel de la fonction de suppression
		supprimer_troupeau(t);
		//mise a jour de l'affichage de la treeview
		afficher_troupeau(treeview1_troupeau);
	}



}

void
on_retour_troupeau_clicked             (GtkWidget       *objet,
                                        gpointer         user_data)
{
	GtkWidget *menu_troupeaux, *fenetre_afficher_troupeau;

	fenetre_afficher_troupeau=lookup_widget(objet,"fenetre_afficher_troupeau");
	

	gtk_widget_destroy(fenetre_afficher_troupeau);
	menu_troupeaux=create_menu_troupeaux();
	gtk_widget_show(menu_troupeaux);
}


void
on_afficher_troupeaux_clicked             (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *menu_troupeaux;
GtkWidget *fenetre_afficher_troupeau;
GtkWidget *treeview1_troupeau;

menu_troupeaux=lookup_widget(objet,"menu_troupeaux");
gtk_widget_destroy(menu_troupeaux);

fenetre_afficher_troupeau=lookup_widget(objet,"fenetre_afficher_troupeau");
fenetre_afficher_troupeau=create_fenetre_afficher_troupeau();

gtk_widget_show(fenetre_afficher_troupeau);

treeview1_troupeau=lookup_widget(fenetre_afficher_troupeau,"treeview1_troupeau");

afficher_troupeau(treeview1_troupeau);
}

void
on_ajouter_troupeaux_clicked           (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *menu_troupeaux, *fenetre_ajouter_troupeau;

	menu_troupeaux=lookup_widget(objet,"menu_troupeaux");
	

	gtk_widget_destroy(menu_troupeaux);
	fenetre_ajouter_troupeau=create_fenetre_ajouter_troupeau();
	gtk_widget_show(fenetre_ajouter_troupeau);
}

void
on_chercher_troupeaux_clicked          (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *menu_troupeaux, *fenetre_rechercher_troupeau;

	menu_troupeaux=lookup_widget(objet,"menu_troupeaux");
	

	gtk_widget_destroy(menu_troupeaux);
	fenetre_rechercher_troupeau=create_fenetre_rechercher_troupeau();
	gtk_widget_show(fenetre_rechercher_troupeau);
}

void
on_supprimer_troupeaux_clicked         (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *menu_troupeaux, *fenetre_supprimer_troupeau;

	menu_troupeaux=lookup_widget(objet,"menu_troupeaux");
	

	gtk_widget_destroy(menu_troupeaux);
	fenetre_supprimer_troupeau=create_fenetre_supprimer_troupeau();
	gtk_widget_show(fenetre_supprimer_troupeau);
}

void
on_modifier_troupeaux_clicked          (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *menu_troupeaux, *fenetre_modifier_troupeau;

	menu_troupeaux=lookup_widget(objet,"menu_troupeaux");
	

	gtk_widget_destroy(menu_troupeaux);
	fenetre_modifier_troupeau=create_fenetre_modifier_troupeau();
	gtk_widget_show(fenetre_modifier_troupeau);

}

void
on_rechercher_troupeau_clicked         (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *id,*sortie;
char Id[20];
FILE *f=NULL;
	char chid[20];
	char chtype[20];
	char chdate[20];
	char chsexe[20];
	char chpoids[20];
int trouv=-1;


id = lookup_widget (objet, "rech_id_troupeau");
strcpy(Id, gtk_entry_get_text(GTK_ENTRY(id)));


f=fopen("troupeaux.txt","r");
if(f!=NULL)
{
while(fscanf(f,"%s %s %s %s %s \n",chid,chtype,chdate,chsexe,chpoids)!=EOF)
{

if (strcmp(chid,Id)==0)
{	strcat(chtype," ");
	strcat(chtype,chsexe);
	strcat(chtype," ");
	strcat(chtype,chpoids);
sortie = lookup_widget(objet, "label19");
gtk_label_set_text(GTK_LABEL(sortie),chtype);
trouv=1;
}
}
if (trouv!=1)
{
sortie = lookup_widget(objet, "label19");
gtk_label_set_text(GTK_LABEL(sortie),"Id n'existe pas");
}
}
}

void
on_retour_menu1_troupeau_clicked       (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *menu_troupeaux, *fenetre_rechercher_troupeau;

	fenetre_rechercher_troupeau=lookup_widget(objet,"fenetre_rechercher_troupeau");
	

	gtk_widget_destroy(fenetre_rechercher_troupeau);
	menu_troupeaux=create_menu_troupeaux();
	gtk_widget_show(menu_troupeaux);
}

void
on_supprimer_troupeau_clicked          (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *id,*sortie;
char Id[20];

int trouv;
id = lookup_widget (objet, "supp_id_troupeau");

strcpy(Id, gtk_entry_get_text(GTK_ENTRY(id)));
trouv=Chercher_troupeau (Id);

if (trouv==1)
{
Supprimer_troupeau(Id);
sortie = lookup_widget(objet, "label23");
gtk_label_set_text(GTK_LABEL(sortie),"troupeau supprimé avec succée!");
//printf("\n troupeau supprimé avec succée!");
}
else 
{
sortie = lookup_widget(objet, "label23");
gtk_label_set_text(GTK_LABEL(sortie),"Id introuvable!");

}
}

void
on_retour_menu2_troupeau_clicked       (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *fenetre_supprimer_troupeau, *menu_troupeaux;

	fenetre_supprimer_troupeau=lookup_widget(objet,"fenetre_supprimer_troupeau");
	

	gtk_widget_destroy(fenetre_supprimer_troupeau);
	menu_troupeaux=create_menu_troupeaux();
	gtk_widget_show(menu_troupeaux);
}

void
on_retour_menu3_troupeau_clicked       (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *fenetre_modifier_troupeau, *menu_troupeaux;

	fenetre_modifier_troupeau=lookup_widget(objet,"fenetre_modifier_troupeau");
	

	gtk_widget_destroy(fenetre_modifier_troupeau);
	menu_troupeaux=create_menu_troupeaux();
	gtk_widget_show(menu_troupeaux);
}

void
on_modifier_troupeau_clicked          (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *id,*sortie;
GtkWidget *modifier_troupeau, *modification_troupeau;
char Id[20];

int trouv;
id = lookup_widget (objet, "modif_id_troupeau");

strcpy(Id, gtk_entry_get_text(GTK_ENTRY(id)));
trouv=Chercher_troupeau (Id);

if (trouv==1)
{
sortie = lookup_widget(objet, "label37");
gtk_label_set_text(GTK_LABEL(sortie),"troupeau trouvée!");
modifier_troupeau=lookup_widget(objet,"modifier_troupeau");
	

	//gtk_widget_destroy(modifier_troupeau);
	modification_troupeau=create_modification_troupeau();
	gtk_widget_show(modification_troupeau);
}
else 
{
sortie = lookup_widget(objet, "label37");
gtk_label_set_text(GTK_LABEL(sortie),"Id introuvable!");

}
}

void
on_retour_menu4_troupeau_clicked      (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *modification_troupeau, *menu_troupeaux;

	modification_troupeau=lookup_widget(objet,"modification_troupeau");
	

	gtk_widget_destroy(modification_troupeau);
	menu_troupeaux=create_menu_troupeaux();
	gtk_widget_show(menu_troupeaux);
}


void
on_modifier_confirmer_troupeau_clicked (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *id;
GtkWidget *input1, *input2, *input3, *input4, *input5;      //,chid,chtype,chdate,chsexe,chpoids//
	char Id[20];
	char chid[20];
	char chtype[20];
	char chdate[20];
	char chsexe[20];
	char chpoids[20];
FILE *f=NULL;
FILE *p=NULL;


id = lookup_widget (objet, "modif2_id_troupeau");
strcpy(Id, gtk_entry_get_text(GTK_ENTRY(id)));

f=fopen("troupeaux.txt","r");
p=fopen("temp.txt","w");
if(f!=NULL)
{
while(fscanf(f,"%s %s %s %s %s \n",chid,chtype,chdate,chsexe,chpoids)!=EOF)
{
if (strcmp(chid,Id)==0)
{
input1=lookup_widget(objet,"nvid"); 
input2=lookup_widget(objet,"nvtype");
input3=lookup_widget(objet,"nvdate");
input4=lookup_widget(objet,"nvsexe");
input5=lookup_widget(objet,"nvpoids");


strcpy(chid,gtk_entry_get_text(GTK_ENTRY(input1)));
strcpy(chtype,gtk_entry_get_text(GTK_ENTRY(input2)));
strcpy(chdate,gtk_entry_get_text(GTK_ENTRY(input3)));
strcpy(chsexe,gtk_entry_get_text(GTK_ENTRY(input4)));
strcpy(chpoids,gtk_entry_get_text(GTK_ENTRY(input5)));

fprintf(p,"%s %s %s %s %s \n",chid,chtype,chdate,chsexe,chpoids);
}
else
fprintf(p,"%s %s %s %s %s \n",chid,chtype,chdate,chsexe,chpoids);
}
fclose(f);
fclose(p);
}
remove("troupeaux.txt");
rename("temp.txt","troupeaux.txt");

}


void
on_modif_chercher_troupeau_clicked     (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *id,*sortie;
GtkWidget *modifier_troupeau, *modification_troupeau;
char Id[20];

int trouv;
id = lookup_widget (objet, "modif2_id_troupeau");

strcpy(Id, gtk_entry_get_text(GTK_ENTRY(id)));
trouv=Chercher_troupeau (Id);

if (trouv==1)
{
sortie = lookup_widget(objet, "label36");
gtk_label_set_text(GTK_LABEL(sortie),"troupeau trouvée!");

}
else 
{
sortie = lookup_widget(objet, "label36");
gtk_label_set_text(GTK_LABEL(sortie),"Id introuvable!");

}
}
////////////////////////////////////////////////






void
on_menu_principal_ouvrier_clicked      (GtkWidget       *objet,

                                        gpointer         user_data)
{
GtkWidget *menu_ouvriers, *menu_principal;
menu_principal=lookup_widget(objet,"menu_principal");
gtk_widget_destroy(menu_principal);
menu_ouvriers=create_menu_ouvriers();
gtk_widget_show(menu_ouvriers);
}


void
on_menu_principal_troupeau_clicked     (GtkWidget       *objet,

                                        gpointer         user_data)
{
GtkWidget *menu_troupeaux, *menu_principal;
menu_principal=lookup_widget(objet,"menu_principal");
gtk_widget_destroy(menu_principal);
menu_troupeaux=create_menu_troupeaux();
gtk_widget_show(menu_troupeaux);
}




void
on_menu_principal_equipement_clicked   (GtkWidget       *objet,

                                        gpointer         user_data)
{/*
GtkWidget *menu_equipement, *menu_principal;
menu_principal=lookup_widget(objet,"menu_principal");
gtk_widget_destroy(menu_principal);
menu_equipements=create_menu_equipements();
gtk_widget_show(menu_equipements);*/
}


void
on_menu_principal_capteur_clicked   (GtkWidget       *objet,

                                        gpointer         user_data)
{
GtkWidget *menu_capteurs, *menu_principal;
menu_principal=lookup_widget(objet,"menu_principal");
gtk_widget_destroy(menu_principal);
menu_capteurs=create_menu_capteurs();
gtk_widget_show(menu_capteurs);
};
void
on_menu_principal_client_clicked       (GtkWidget       *objet,

                                        gpointer         user_data)
{
GtkWidget *menu_client, *menu_principal;
menu_principal=lookup_widget(objet,"menu_principal");
gtk_widget_destroy(menu_principal);
menu_client=create_menu_client();
gtk_widget_show(menu_client);
};




void
on_ajouter_equipement_clicked          (GtkWidget       *objet,

                                        gpointer         user_data)
{

}


void
on_afficher_equipement_clicked         (GtkWidget       *objet,

                                        gpointer         user_data)
{

}


void
on_retour_vers_menu_equipement_clicked (GtkWidget       *objet,

                                        gpointer         user_data)
{

}


void
on_treeview1_equipement_row_activated  (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data)
{

}


void
on_retour_equipement_clicked           (GtkWidget       *objet,

                                        gpointer         user_data)
{

}


void
on_afficher_equipements_clicked        (GtkWidget       *objet,

                                        gpointer         user_data)
{

}


void
on_ajouter_equipements_clicked         (GtkWidget       *objet,

                                        gpointer         user_data)
{

}


void
on_chercher_equipements_clicked        (GtkWidget       *objet,

                                        gpointer         user_data)
{

}


void
on_supprimer_equipements_clicked       (GtkWidget       *objet,

                                        gpointer         user_data)
{

}


void
on_modifier_equipements_clicked        (GtkWidget       *objet,

                                        gpointer         user_data)
{

}


void
on_rechercher_equipement_clicked       (GtkWidget       *objet,

                                        gpointer         user_data)
{

}


void
on_retour_menu1_equipement_clicked     (GtkWidget       *objet,

                                        gpointer         user_data)
{

}


void
on_supprimer_equipement_clicked        (GtkWidget       *objet,

                                        gpointer         user_data)
{

}


void
on_retour_menu2_equipement_clicked     (GtkWidget       *objet,

                                        gpointer         user_data)
{

}


void
on_modifier_equipement_clicked         (GtkButton       *button,
                                        gpointer         user_data)
{

}


void
on_retour_menu3_equipement_clicked     (GtkButton       *button,
                                        gpointer         user_data)
{

}


void
on_retour_menu4_equipement_clicked     (GtkButton       *button,
                                        gpointer         user_data)
{

}


void
on_modifier_confirmer_equipement_clicked
                                        (GtkButton       *button,
                                        gpointer         user_data)
{

}


void
on_modif_chercher_equipement_clicked   (GtkButton       *button,
                                        gpointer         user_data)
{

}


//////////////////////////



void
on_retour_menu_principal_capteur_clicked
                                        (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *menu_capteurs, *menu_principal;
menu_capteurs=lookup_widget(objet,"menu_capteurs");
gtk_widget_destroy(menu_capteurs);
menu_principal=create_menu_principal();
gtk_widget_show(menu_principal);
}


void
on_retour_menu_principal_ouvrier_clicked
                                        (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *menu_ouvriers, *menu_principal;
menu_ouvriers=lookup_widget(objet,"menu_ouvriers");
gtk_widget_destroy(menu_ouvriers);
menu_principal=create_menu_principal();
gtk_widget_show(menu_principal);
}


void
on_retour_menu_principal_client_clicked
                                        (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *menu_client, *menu_principal;
menu_client=lookup_widget(objet,"menu_client");
gtk_widget_destroy(menu_client);
menu_principal=create_menu_principal();
gtk_widget_show(menu_principal);
}


void
on_retour_menu_principal_troupeau_clicked
                                        (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *menu_troupeaux, *menu_principal;
menu_troupeaux=lookup_widget(objet,"menu_troupeaux");
gtk_widget_destroy(menu_troupeaux);
menu_principal=create_menu_principal();
gtk_widget_show(menu_principal);
}



