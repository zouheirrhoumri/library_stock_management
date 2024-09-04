#include <stdio.h>
#include <string.h>
#include <ctype.h>
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

    printf("\t\tTitre: \n");
    getchar(); 
    scanf("%[^\n]", L[dim].titre);
    getchar(); 

    printf("\t\tAuteur: \n");
    scanf("%[^\n]", L[dim].auteur);
    getchar(); 

    printf("\t\tPrix: \n");
    scanf("%f", &L[dim].prix);

    printf("\t\tEntrez la quantite: \n");
    scanf("%d", &L[dim].qty);

    dim++;
    ID++;
}

void afficher_livre(livre L[])
{
    printf("\t\t+-------------------------------------------------------------------+\n");
    printf("\t\t| Id |        TITRE         |      AUTEUR     |  PRIX  | QUANTITe   |\n");
    printf("\t\t+-------------------------------------------------------------------+\n");
    for (int i = 0; i < dim; i++)
    {
        printf("\t\t |%-2d |%-17s | %-17s | %-6.2f | %-9d|\n", L[i].id, L[i].titre, L[i].auteur, L[i].prix, L[i].qty);
    }
    printf("\t\t+-------------------------------------------------------------------+\n");
}

void recherche_livre(livre L[])
{
    char title[25];
    printf("Entrez le titre du livre que vous recherchez : ");
    getchar(); 
    scanf("%[^\n]", title);

    for (int i = 0; title[i]; i++)
    {
        title[i] = toupper(title[i]);
    }

    for (int i = 0; i < dim; i++)
    {
        char tempTitre[25];
        strcpy(tempTitre, L[i].titre);
        for (int j = 0; tempTitre[j]; j++)
        {
            tempTitre[j] = toupper(tempTitre[j]);
        }
        if (strcmp(tempTitre, title) == 0)
        {
            printf("\t\t |%-2d |%-17s | %-17s | %-6.2f | %-9d|\n", L[i].id, L[i].titre, L[i].auteur, L[i].prix, L[i].qty);
            return;
        }
    }
    printf("Livre non trouve.\n");
}

void modifier_qty() {
    char titre[25];
    int num = 0;

    printf("Entrez le titre du livre: ");
    getchar();  
    scanf("%[^\n]", titre);  

    for (int i = 0; i < dim; i++) {
        if (strcmp(L[i].titre, titre) == 0) {
            num++;
            printf("Entrez la nouvelle quantite: ");
            scanf("%d", &L[i].qty);  
            printf("Quantite modifiee pour le livre '%s'.\n", L[i].titre);  
            break;  
        }
    }

    if (num == 0) {
        printf("\t\tIl n'y a pas de livre avec ce titre.\n");
    }
    printf("Press Enter to continue...");
    getchar(); 
    getchar(); 
}

int menu()
{
    int opt;
    while (1)
    {
        printf("\n================= STOCK MANAGEMENT =================\n");
        printf("\n     1. Ajouter un livre au stock.");
        printf("\n     2. Afficher tous les livres disponibles.");
        printf("\n     3. Rechercher un livre par son titre.");
        printf("\n     4. Mettre à jour la quantite d'un livre.");
        printf("\n     5. Supprimer un livre du stock.");
        printf("\n     6. Afficher le nombre total de livres en stock.");
        printf("\n     7. EXIT ");
        printf("\n\nVeuillez selectionner une option : ");
        scanf("%d", &opt);

        switch (opt)
        {
        case 1:
            ajouter_livre(L);
            break;
        case 2:
            afficher_livre(L);
            break;
        case 3:
            recherche_livre(L);
            break;
        case 4:
            modifier_qty(L);
            break;
        case 7:
            return 0; 
        default:
            printf("Option invalide. Veuillez reessayer.\n");
            break;
        }

        printf("Press Enter to continue...");
        while (getchar() != '\n');  
        getchar();
    }
}

int main()
{
    menu();
    return 0;
}
