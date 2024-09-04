#include <stdio.h>
typedef struct livre 
{
    int id ;
    char titre[25];
}livre;
livre L[100];
dim = 0;
id = 0;

void ajouter_livre(){
    int choix;



}

int main(){
    int opt;
    printf("\t================= STOCK MANGEMENT =================");
    printf("\n     1. Ajouter un livre au stock.");
    printf("\n     2. Afficher tous les livres disponibles.");
    printf("\n     3. Rechercher un livre par son titre.");
    printf("\n     4. Mettre à jour la quantité d'un livre.");
    printf("\n     5. Supprimer un livre du stock.");
    printf("\n     6. Afficher le nombre total de livres en stock.");
    printf("\n     7. EXIT ");


    printf("\n\nveullez selectez une option :");
    scanf("%d" ,&opt);

    switch (opt)
    {
    case 1 :
    printf(" combien de livre veux vouler enter:");
        break;
    
    default:
        break;
    }


    printf("\n\n");

}