#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_NUMBER_OBJECTS 10000

bool knapsack2(int bag_size, int no_objects, int* objects);

int main () {

    int bag_size = 0;
    int tmp_object = 0;
    int no_objects = 0;
    bool result = false;
    int* objects = NULL;

    /* Saisie de la capacité */
    scanf("%d", &bag_size);
    objects = (int*)malloc(MAX_NUMBER_OBJECTS * sizeof(int));

    /* Saisie des objets */
    scanf("%d", &tmp_object);
    while (tmp_object != -1) {
        objects[no_objects++] = tmp_object;
        scanf("%d", &tmp_object);
    }

    /* Réallocation de la mémoire */
    objects = (int*)realloc(objects, no_objects * sizeof(int));

    /* Algorithme du sac à dos 2 */
    result = knapsack2(bag_size, no_objects, objects);
    printf("%s\n\r", result ? "Oui":"Non");

    /* Libère la mémoire */
    free(objects);

    return EXIT_SUCCESS;
}

bool knapsack2(int bag_size, int no_objects, int* objects) {

    bool** results = NULL;
    int space = 0;
    bool ret_val = false;
    int i = 0, j = 0; // Index

    /* Création du tableau de résultat */
    results = (bool**)malloc((bag_size + 1) * sizeof(bool*));
    for (i = 0; i <= bag_size; i++) {
        results[i] = (bool*)malloc(no_objects * sizeof(bool));

        /* Initialisation */
        for (j = 0; j < no_objects; j++)
            results[i][j] = (i == 0);
    }

    /* Parcours des capacités */
    for (i = 1; i <= bag_size; i++) {

        /* Parcours des objets */
        for (j = 1; j <= no_objects; j++) {

            space = i - objects[j - 1];
            results[i][j] |= !(space < 0) && (results[i][j - 1] || results[space][j - 1]);
        }
    }

    /* Extraction du résultat */
    for (i = 0; i <= no_objects; i++)
        ret_val |= results[bag_size][i];

    /* Libération de la mémoire */
    for (i = 0; i <= bag_size; i++)
        free(results[i]);
    free(results);

    return ret_val;
}