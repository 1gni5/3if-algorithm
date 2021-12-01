#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_NUMBER_OBJECTS 10000

int** knapsack2(int bag_size, int no_objects, int* objects);
int pos_min(int arr[3]);
int min(int a, int b);

int main () {

    int bag_size = 0;
    int tmp_object = 0;
    int no_objects = 0;
    int result = -1;

    int* objects = NULL;
    int** results = NULL;

    int i = 0;

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
    results = knapsack2(bag_size, no_objects, objects);

    /* Extrait le résultat */
    for (i = 0; i <= bag_size; i++) {

        if (result > results[bag_size][i])
            result = results[bag_size][i];
    }

    printf("Nb d'objets = %d\n\r", result);

    /* Libère la mémoire */
    for (i = 0; i <= bag_size; i++)
        free(results[i]);
    free(results); free(objects);

    return EXIT_SUCCESS;
}

int** knapsack2(int bag_size, int no_objects, int* objects) {

    int space = 0;
    int i = 0, j = 0; // Indexes

    int** results = NULL;
    int possible_values[3];

    /* Création du tableau de résultat */
    results = (int**)malloc((bag_size + 1) * sizeof(int*));
    for (i = 0; i <= bag_size; i++) {
        results[i] = (int*)malloc(no_objects * sizeof(int));

        /* Initialisation */
        for (j = 0; j < no_objects; j++)
            results[i][j] = (i == 0) ? 0 : -1;
    }

    /* Parcours des capacités */
    for (i = 1; i <= bag_size; i++) {

        /* Parcours des objets */
        for (j = 1; j <= no_objects; j++) {

            space = i - objects[j - 1];

            /* Aucune solution possible */
            if (space < 0) continue;

            /* 3 solutions possibles */
            possible_values[0] = results[i][j];
            possible_values[1] = results[i][j - 1];
            possible_values[2] = results[space][j - 1];

            results[i][j] = pos_min(possible_values);
        }
    }

    return results;
}

int pos_min(int arr[3]) {

    int min = -1;
    int i = 0;

    for (i = 0; i < 3; i++) {

        if (arr[i] >= 0 && (min < 0 || arr[i] < min))
            min = arr[i];
    }

    return min;
}

int min(int a, int b) {
    return (a < b) ? a : b;
}