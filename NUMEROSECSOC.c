#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define TAILLE_MOIS 10
#define TAILLE_DEPT 3
#define MAX_SECSOC 14
#define MAX_LIBELLE 9
#define NON_TROUVE -1
#define MAX 200

// Déclaration du type global
// La déclaration de ce type doit être avant
// les procédure de tri qui l'utilise
struct numerosecsoc
{
    char nomsec[MAX_SECSOC];
    char libelle[MAX_LIBELLE];
    char depart[TAILLE_DEPT];
    char mois[TAILLE_MOIS];
    int sexe;
    int annee;
    int mois2;
    int commune;
    int numordre;
};
// Déclaration des varaibles globales
struct numerosecsoc tabnumss[MAX];   
int nbnumss=0;
int a_sauvegarder=0;

// Déclarations préliminaires
void accueil();
void saisie();
void affichage();
void sauvegarde();
void chargement();
int recherche(char nomrech[TAILLE_MOIS]);
void lance_recherche();
void conv_maj(char chaine[]);
void quitter();
void verif_sauvegarde();
void modification();
void suppression() ;

// ------------------------------------
int main()
{
  int choix = -1 ;
  int choix2 = -1;

  while (choix != 0) {
        accueil();
        scanf("%d", &choix);

        switch (choix) {
            case 1:
                do {
                    printf("+------------------------------------------------+\n");
                    printf("|                  Menu de visiteur              |\n");
                    printf("+------------------------------------------------+\n");
                    printf("| -1- Saisir un numéro de sécurité sociale       |\n");
                    printf("| -2- Afficher les résultats                     |\n");
                    printf("| -3- Rechercher votre numéro de sécurité sociale|\n");
                    printf("| -4- Retourner à la page d'accueil              |\n");
                    printf("+------------------------------------------------+\n");
                    printf("Choix : ");
                    scanf("%d", &choix2);
                    switch (choix2) {
                        case 1:
                            saisie();
                            break;
                        case 2:
                            affichage();
                            break;
                        case 3:
                            lance_recherche();
                            break;
                        case 4:
                            break; // rendre à page d'accueil
                        default:
                            printf("\n\nErreur, veuillez entrer une option valide.\n\n");
                    }
                } while (choix2 != 4); // continue jusq'à  utilisateur select 4
                break;
            case 2:
                do {
                    printf("+------------------------------------------------+\n");
                    printf("|              Menu d'administrateur             |\n");
                    printf("+------------------------------------------------+\n");
                    printf("| -1- Saisir un numéro de sécurité sociale       |\n");
                    printf("| -2- Afficher les résultats                     |\n");
                    printf("| -3- Sauvegarder les résultats                  |\n");
                    printf("| -4- Charger un fichier                          |\n");
                    printf("| -5- Rechercher votre numéro de sécurité sociale|\n");
                    printf("| -6- Modifier les données                       |\n");
                    printf("| -7- Supprimer les données                      |\n");
                    printf("| -8- Retourner à la page d'accueil              |\n");
                    printf("+------------------------------------------------+\n");
                    printf("Choix : ");
                    scanf("%d", &choix2);
                    switch (choix2) {
                        case 1:
                            saisie();
                            break;
                        case 2:
                            affichage();
                            break;
                        case 3:
                            sauvegarde();
                            break;
                        case 4:
                            chargement();
                            break;
                        case 5:
                            lance_recherche();
                            break;
                        case 6:
                            modification();
                            break;
                        case 7:
                            suppression();
                            break;
                        case 8:
                            break; // rendre à page d'accueil
                        default:
                            printf("\n\nErreur, veuillez entrer une option valide.\n\n");
                    }
                } while (choix2 != 8); // Kcontinue jusq'à  utilisateur select 4
                break;
            case 0:
                quitter();
                break;
            default:
                printf("\n\nErreur, veuillez entrer une option valide.\n\n");
        }
    }//fin while
    return 0;
}


// ------------------------------------
void accueil(){
    printf("+-------------------------------+\n");
    printf("|        Page d'accueil         |\n");
    printf("+-------------------------------+\n");
    printf("| -1- Vous etre visiteur        |\n");
    printf("| -2- Vous etre administrateur  |\n");
    printf("| -0- Quitter                   |\n");
    printf("|                               |\n");
    printf("+-------------------------------+\n");
    printf("Choix : ");
}
// ------------------------------------
void saisie(){
  int i ;
  struct numerosecsoc nss;

  // Boucle de saisie
  i=nbnumss;
  // Initalisation chaine vide
  nss.nomsec[0] = '\0' ; // identique à : strcpy(eleve.nom,"");

  while(strcmp(nss.nomsec,"FIN")!=0){
    printf("Entrez votre numéro de sécurité sociale (fin pour terminer) : ");
    scanf("%s",nss.nomsec);
    conv_maj(nss.nomsec);

    if(strcmp(nss.nomsec,"FIN")==0){
      break;
      
    }

    /*----instruction-----*/
    /*saisie du numero sous la forme d'une chaine de caractère */
    //nss = tabnumss[i];
    nss.sexe = nss.nomsec[0]-48;
    if(nss.sexe == 1){
      strcpy(nss.libelle,"Monsieur");
    }else{
      strcpy(nss.libelle,"Madame/mademoiselle");
    }
    /*recuperation de l'annee de naissance*/
    nss.annee =1900 + ((nss.nomsec[1] - 48) * 10) + (nss.nomsec[2] - 48);

    /*recuperation du mois de naissance*/
    nss.mois2 =(nss.nomsec[3]-48) * 10 + (nss.nomsec[4] - 48);
    
    switch( nss.mois2 ){
      case 1: strcpy(nss.mois,"Janvier");
              break;
      case 2: strcpy(nss.mois,"Février");
              break;
      case 3: strcpy(nss.mois,"Mars");
              break;
      case 4: strcpy(nss.mois,"Avirl");
              break;
      case 5: strcpy(nss.mois,"Mai");
              break;
      case 6: strcpy(nss.mois,"Juin");
              break;
      case 7: strcpy(nss.mois,"Juillet");
              break;
      case 8: strcpy(nss.mois,"Août");
              break;
      case 9: strcpy(nss.mois,"Septembre");
              break;
      case 10: strcpy(nss.mois,"October");
              break;
      case 11: strcpy(nss.mois,"Novembre");
              break;
      case 12: strcpy(nss.mois,"Decembre");
              break;
    }

    /*récuperation du departement*/
    nss.depart[0] = nss.nomsec[5];
    nss.depart[1] = nss.nomsec[6];
    nss.depart[2] = '\0';


    /*récuperation de la commune*/
    nss.commune = ((nss.nomsec[7] - 48 ) * 100 ) + ((nss.nomsec[8] - 48 ) * 10 ) + (nss.nomsec[9] - 48 );

    /*récuperation du numéro d'ordre*/
    nss.numordre = ((nss.nomsec[10] - 48 )* 100 ) + ((nss.nomsec[11] - 48) * 10) + (nss.nomsec[12] - 48 );

   
    
      
      tabnumss[i++] = nss;
      /*a_sauvegarder=1;*/
    
  }
  nbnumss = i;
}
void affichage(){
  int i ;
  struct numerosecsoc nss;

  if (nbnumss == 0)
  {
    printf("Aucun numéro sécurité sociale à afficher\n");
  }else{
    printf("Bonjour , voici les numéros de sécutité sociale : \n");
    printf("-----------------------------------------------------------------------------------------------------------------\n");
    printf("%-30s %-5s %-10s %-10s %-10s %-10s\n",
    "Numéro_sécutité_sociale",
    "Année_de_naissance",
    "Mois_de_naissance",
    "Département",
    "Commune",
    "le numéro d'ordre"
    );
    printf("-------------------------------------------------------------------------------------------------------------------\n");
    // Boucle d'affichage

  }


}
void sauvegarde(){}
void chargement(){}
int recherche(char nomrech[TAILLE_MOIS]){
  return 0;
}
void lance_recherche(){}
void conv_maj(char chaine[]){
  int i, taille;

  taille = strlen(chaine);
  for (i=0 ; i<taille ; i++)
  {
    chaine[i] = toupper(chaine[i]);
  }
}
void quitter(){
  verif_sauvegarde();
  printf("Au revoir\n");
}
void verif_sauvegarde(){}
void modification(){}
void suppression(){}
