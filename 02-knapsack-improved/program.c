#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAXIMUM_BAG_SIZE 10000

bool knapsack2(int bag_size, int no_objects, int *objects);
bool** init_results(int size, bool value);

int main(int argc, char **argv) {

  int bag_size = 0;
  int no_objects = 0;
  int tmp_object = 0;
  int *objects = NULL;

  /* Création du sac */
  objects = (int*)malloc(MAXIMUM_BAG_SIZE * sizeof(int));
  scanf("%d", &bag_size);

  /* Saisie du poid des objets */
  scanf("%d", &tmp_object);
  while (tmp_object != -1) {
    objects[no_objects] = tmp_object;
    no_objects++;
    scanf("%d", &tmp_object);
  }

  /* Redimensionnement du tableau d'objet */
  objects = (int*)realloc(objects, no_objects * sizeof(int));
  
  /* Calcul et affiche les résultats */
  printf("%d\n\r", knapsack2(bag_size, no_objects, objects));
  
  free(objects);
  return EXIT_SUCCESS;
}


bool knapsack2(int bag_size, int no_objects, int *objects) {

  int current_size = 0;
  int index = 0;
  int space_remaining = 0;

  /* Création du tableau de résultats */
  bool **results = (bool **)malloc((bag_size + 1) * sizeof(bool*));
  for (current_size = 0; current_size < bag_size + 1; current_size++) {
    results[current_size] = (bool *)malloc((no_objects) * sizeof(bool));

    /* Initialisation */
    for (index = 0; index < no_objects; index++) {
      results[current_size][index] = current_size == 0;
    }
  }

  /* Parcours des capacitées */
  for (current_size = 1; current_size < bag_size + 1; current_size++) {

    /* Parcours des objets */
    for (index = 1; index <= no_objects; index++) {
      
      space_remaining = current_size - objects[index - 1];

      /* Condition de validation */
      results[current_size][index] = !(space_remaining < 0) &&
	(results[current_size][index - 1] || results[space_remaining][index - 1]);

      /* Valeur trouvé, inutile de continuer */
      if (results[current_size][index])
	break;
    }
  }


  /* Recherche des résultats */
  for (index = 1; index <= no_objects; index++)
    if (results[bag_size][index]) return true;

  /* Libération du tableau de résultats */
  for (current_size = 0; current_size < bag_size + 1; current_size++)
    free(results[current_size]);
  free(results);

  return false;
}
