#ifndef TŌVC_H_INCLUDED 
#define TŌVC_H_INCLUDED

/*---Constantes---*/
#define MAX_NO_CHARS 999 //le nombre maximal des caracteres dans un bloc

// Numero des entetes
#define ENTETE_NUMERO_DERNIER_BLOC 1
#define ENTETE_POSLIBRE_DERNIER_BLOC 2
#define ENTETE_NOMBRE_CHAR_SUP 3

// representation d'un enregistrement
#define TAILLE_EFFECTIVE_ENREG 3 // la taille effective de la donne dans l'enregistrement est sur 3 octects
#define TAILLE_CHAR_EFFACEMENT_LOGIQUE 1 // "E": pour efface , "N" pour: non efface
#define TAILLE_CLE 20
// n le reste

/*--Structures--*/
typedef struct 
{
    char tab[MAX_NO_CHARS + 1];
}Bloc, Buffer;
typedef struct 
{
    int numeroDernierBloc;
    int positionLibreDernierBloc;
    int nbCharSupp;
}Entete;
typedef struct 
{
    Entete entete;
    FILE* fichier;
}TŌVC;


/*---Fonctions du modele abstrait---*/
//*****fonctions propres au modele****
void ouvrir(TŌVC* f,char nom_f[],char mode);
void fermer(TŌVC* f);
void lireBloc(TŌVC* f,int i,Buffer *buf);
void ecrireBloc(TŌVC* f,int i,Buffer* buf);
int entete(TŌVC* f,int i);
void affecterEntete(TŌVC* f,int i,int val);
void allouerBloc(TŌVC* f);

//*****fonctions necessaires aux traitements****
void lire_chaine(TŌVC* f,Buffer* buf,int* i,int* j,int taille,char *ch[]); // lire une chaine de caracteres a partir du fichier
void ecrire_chaine(TŌVC* f,Buffer* buf,int* i,int *j,int taille,char ch[]);// ecrire une chaine de caracteres au fichier
void afficher_entete(TŌVC* f); // afficher les caracteristiques du fichier
void afficher_bloc(TŌVC* f,int i); // afficher le contenu du bloc i
void afficher_fichier(TŌVC* f); // afficher le contenu du fichier
#endif // TŌVC_H_INCLUDED