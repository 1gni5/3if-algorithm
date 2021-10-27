#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAXIMUM_BAG_SIZE 10000

bool knapsack(int bag_size, int no_objects, int *objects);
bool* bool_array(int size, bool value);

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
  printf("%d\n\r", knapsack(bag_size, no_objects, objects));
  
  free(objects);
  return EXIT_SUCCESS;
}

bool knapsack(int bag_size, int no_objects, int *objects) {

  int current_size = 0;
  int index = 0;
  
  bool return_value = false;
  int space_remaining = 0;
  bool *results = bool_array(bag_size + 1, false);

  /* Parcours des tailles de sac */
  for (current_size = 0; current_size < bag_size + 1; current_size++) {

    /* Parcours des objets */
    for (index = 0; index < no_objects; index++) {

      space_remaining = current_size - objects[index];

      results[current_size] = space_remaining >= 0 &&
	(space_remaining == 0 || results[space_remaining]);

      /* Réponse trouvée pour cette taille */
      if (results[current_size]) break;

    }
  }

  return_value = results[bag_size];
  free(results);
  
  return return_value;
}

bool* bool_array(int size, bool value) {

  int index = 0;
  bool *results = (bool*)malloc(size * sizeof(bool));

  /* Initialisation */
  for (index = 0; index < size; index++)
    results[index] = value;

  return results;
}
