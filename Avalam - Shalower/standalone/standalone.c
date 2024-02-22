#include <stdio.h>
#include <avalam.h>
#include <topologie.h>
#include <stdlib.h>
#include <string.h>

// Fonction pour écrire dans le fichier JSON
int genererJson(T_Position position, T_Score score, char argument[]);

int main(int nombreArguments, char *arguments[])
{
    int bonusJaune; // Variable du bonus jaune
    int malusJaune; // Variable du malus jaune
    int bonusRouge; // Variable du bonus rouge
    int malusRouge; // Variable du malus rouge
    int origine; // Origine du coup à jouer
    int destination; // Destination du coup à jouer
    T_Position position;
    T_ListeCoups listeCoups;
    T_Score score;

    position = getPositionInitiale();
    if (!genererJson(position, score, arguments[1])) return 0;

    // Détermination des bonus et malus
    /* Bonus jaune */
    do
    {
        printf("Saisissez la case du bonus jaune : ");
        scanf("%d", &bonusJaune);
        getchar();
        if (position.cols[bonusJaune].couleur != 1)
        {
            printf("Case non conventionnelle\n");
        }
    } while (position.cols[bonusJaune].couleur != 1);
    position.evolution.bonusJ = bonusJaune;
    if (!genererJson(position, score, arguments[1])) return 0;
    printf("Bonus Jaune : %d\n", bonusJaune);

    /* Bonus rouge */
    do
    {
        printf("Saisissez la case du bonus rouge : ");
        scanf("%d", &bonusRouge);
        getchar();
        if (position.cols[bonusRouge].couleur != 2)
        {
            printf("Case non conventionnelle\n");
        }
    } while (position.cols[bonusRouge].couleur != 2);
    position.evolution.bonusR = bonusRouge;
    if (!genererJson(position, score, arguments[1])) return 0;
    printf("Bonus Rouge : %d\n", bonusRouge);

    /* Malus jaune */
    do
    {
        printf("Saisissez la case du malus jaune : ");
        scanf("%d", &malusJaune);
        getchar();
        if (position.cols[malusJaune].couleur != 1 || (malusJaune == bonusJaune))
        {
            printf("Case non conventionnelle\n");
        }
    } while (position.cols[malusJaune].couleur != 1 || (malusJaune == bonusJaune));
    position.evolution.malusJ = malusJaune;
    if (!genererJson(position, score, arguments[1])) return 0;
    printf("Malus Jaune : %d\n", malusJaune);

    /* Malus rouge */
    do
    {
        printf("Saisissez la case du malus rouge : ");
        scanf("%d", &malusRouge);
        getchar();
        if (position.cols[malusRouge].couleur != 2 || (malusRouge == bonusRouge))
        {
            printf("Case non conventionnelle\n");
        }
    } while (position.cols[malusRouge].couleur != 2 || (malusRouge == bonusRouge));
    position.evolution.malusR = malusRouge;
    if (!genererJson(position, score, arguments[1])) return 0;
    printf("Malus Rouge : %d\n", malusRouge);

    do
    {
        // Saisie de l'origine et de la destination du coup, et exécution de la fonction qui effectue le coup
        if (position.trait == 1)
            printf("Trait aux Jaunes\n");
        if (position.trait == 2)
            printf("Trait aux Rouges\n");
        printf("--------------------------------------------------\n");
        printf("Emplacement du pion à déplacer : ");
        scanf("%d", &origine);
        getchar();
        printf("Emplacement de la destination : ");
        scanf("%d", &destination);
        getchar();
        printf("--------------------------------------------------\n");

        printf("Origine du coup : %d\nDestination du coup : %d\n", origine, destination);

        position = jouerCoup(position, origine, destination);

        // Mise à jour du score, du fichier JSON et des coups possibles
        score = evaluerScore(position);
        if (!genererJson(position, score, arguments[1])) return 0;
        listeCoups = getCoupsLegaux(position);
    } while (listeCoups.nb != 0);

    // Affichage du score final
    score = evaluerScore(position);
    printf("Score final : \n");
    afficherScore(score);
    if ((score.nbR > score.nbJ) || ((score.nbR > score.nbJ) && (score.nbR5 > score.nbJ5)))
        printf("Victoire des Rouges !!\n");
    else if ((score.nbJ > score.nbR) || ((score.nbJ > score.nbR) && (score.nbJ5 > score.nbR5)))
        printf("Victoire des Jaunes !!\n");
    else
        printf("Égalité !!\n");
    printf("Arrêt de l'application\n");
    return 1;
}

int genererJson(T_Position position, T_Score score, char argument[])
{
    FILE *fichierJson;
    int i;
    char nomFichier[100];
    if (argument != NULL)
    {
        sprintf(nomFichier, "./%s.js", argument);
        fichierJson = fopen(nomFichier, "w");
    }
    else
        fichierJson = fopen("./web/data/avalam-refresh.js", "w");

    if (fichierJson == NULL)
    {
        printf("Erreur lors de l'ouverture du fichier\n");
        return 0;
    }

    // Ajout dans le fichier JSON des différents éléments
    fprintf(fichierJson, "traiterJson({\n");
    fprintf(fichierJson, "\"trait\" : %d,\n", position.trait);
    fprintf(fichierJson, "\"scoreJ\" : %d,\n", score.nbJ);
    fprintf(fichierJson, "\"scoreJ5\" : %d,\n", score.nbJ5);
    fprintf(fichierJson, "\"scoreR\" : %d,\n", score.nbR);
    fprintf(fichierJson, "\"scoreR5\" : %d,\n", score.nbR5);
    fprintf(fichierJson, "\"bonusJ\" : %d,\n", position.evolution.bonusJ);
    fprintf(fichierJson, "\"malusJ\" : %d,\n", position.evolution.malusJ);
    fprintf(fichierJson, "\"bonusR\" : %d,\n", position.evolution.bonusR);
    fprintf(fichierJson, "\"malusR\" : %d,\n", position.evolution.malusR);
    fprintf(fichierJson, "\"cols\" : [\n");
    for (i = 0; i < NBCASES; i++)
    {
        fprintf(fichierJson, "\t{\"nb\" : %d, \"couleur\" : %d},\n", position.cols[i].nb, position.cols[i].couleur);
    }
    fprintf(fichierJson, "]\n");
    fprintf(fichierJson, "});");

    fclose(fichierJson);
    return 1;
}
