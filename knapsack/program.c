#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_NUMBER_OF_ITEM 10000

bool knapsack(int bag_size, int no_objects, int* objects);

int main() {

    int bag_size = 0;
    int tmp_object = 0;
    int no_objects = 0;
    int* objects = NULL;

    bool result = false;

    /* Saisie de la capacité */
    scanf("%d", &bag_size);
    objects = (int*)malloc(MAX_NUMBER_OF_ITEM * sizeof(int));

    /* Saisie des objets */
    scanf("%d", &tmp_object);
    while (tmp_object != -1) {
        objects[no_objects++] = tmp_object;
        scanf("%d", &tmp_object);
    }

    /* Réallocation de la mémoire */
    objects = (int*)realloc(objects, bag_size * sizeof(int));

    /* Algorithme du sac à dos */
    result = knapsack(bag_size, no_objects, objects);
    printf("%s\n\r", result ? "Oui":"Non");

    /* Libération de la mémoire */
    free(objects);

    return EXIT_SUCCESS;
}

bool knapsack(int bag_size, int no_objects, int* objects) {

    bool *results = NULL;
    bool ret_value = false;
    int space_remaining = 0;
    int i = 0, j = 0; // loop index

    /* Initialise le tableau de résultat */
    results = (bool*)malloc((bag_size + 1) * sizeof(bool));
    for (i = 0; i <= bag_size; i++) results[i] = (i == 0);

    /* Vérifie pour chaque objets */
    for (i = 1; i <= bag_size; i++) {

        /* Vérifie pour chaque capacitée */
        for (j = 0; j < no_objects; j++) {
            space_remaining = i - objects[j];
            results[i] |= !(space_remaining < 0) && results[space_remaining];
        }
    }

    /* Récupère le résultat + libère la mémoire */
    ret_value = results[bag_size];
    free(results);

    return ret_value;
}