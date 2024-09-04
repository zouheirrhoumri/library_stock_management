#include <stdio.h>
typedef struct livre
{
    int id;
    char titre[25];
    char auteur[25];
    float prix;
    int qty;
} livre;
livre L[100];
int dim = 0;
int ID = 0;
void ajouter_livre(livre L[])
{
    L[dim].id = ID + 1;

    printf("\t\t titre: \n");
    getchar();
    scanf("%[^\n]", &L[dim].titre);
    getchar();
    printf("\t\t auteur: \n");
    scanf("%[^\n]", &L[dim].auteur);
    getchar();

    printf("\t\tprix: \n");
    scanf("%f", &L[dim].prix);

    printf("\t\tentrez la quntite\n");
    scanf("%d", &L[dim].qty);
    dim++;
    ID++;
}

void afficher_livre(livre L[])
{
    printf("\t\t+-------------------------------------------------------------------+\n");
    printf("\t\t| Id |        TITRE         |      AUTEUR     | PRIX |    QUNTITE   |\n");
    printf("\t\t+-------------------------------------------------------------------+\n");
    for (int i = 0; i < dim; i++)
    {
        printf("\t\t |%-2d  |%-17s | %-17s  | %-3d  | %-3d", L[i].id, L[i].titre, L[i].auteur, L[i].prix, L[i].qty);
    }
    printf("\t\t+-------------------------------------------------------------------+\n");
}

int menu()
{
    int opt;
    while (1)
    {
        printf("\t================= STOCK MANGEMENT =================");
        printf("\n     1. Ajouter un livre au stock.");
        printf("\n     2. Afficher tous les livres disponibles.");
        printf("\n     3. Rechercher un livre par son titre.");
        printf("\n     4. Mettre à jour la quantité d'un livre.");
        printf("\n     5. Supprimer un livre du stock.");
        printf("\n     6. Afficher le nombre total de livres en stock.");
        printf("\n     7. EXIT ");
        printf("\n\nveullez selectez une option :");
        scanf("%d", &opt);
        switch (opt)
        {
        case 1:
            ajouter_livre(L);
            break;
        case 2:
            afficher_livre(L);
            break;
        default:
            printf("error");
            break;
        }
    }

    printf("\n\n");
}
int main()
{
    menu();
    return 0;
}