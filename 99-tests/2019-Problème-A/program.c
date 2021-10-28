#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int* concat_ints(int size_a, int* a, int size_b, int* b);
int knapsack2(int bag_size, int no_objects, int *objects);

int main(int argc, char **argv) {

  int work_time = 0;
  int no_tasks = 0;
  int index = 0;
  int *tasks = NULL;

  int task_type = 0;
  int task_time = 0;

  int no_atasks = 0;
  int no_btasks = 0;

  int *a_tasks = (int*)malloc(no_tasks * sizeof(int));
  int *b_tasks = (int*)malloc(no_tasks * sizeof(int));

  /* Saisie du temps de travail + nombre de tâches */
  scanf("%d", &work_time);
  scanf("%d", &no_tasks);

  /* Saisie des tâches */
  for (index = 0; index < no_tasks; index++) {
    scanf("%d", &task_type);
    scanf("%d", &task_time);

    /* Trie les tâches selon leur type */
    if (task_type == 1)
      a_tasks[no_atasks++] = task_time;
    else
      b_tasks[no_btasks++] = task_time;
  }

  /* Concatène les 2 listes */
  tasks = concat_ints(no_btasks, b_tasks, no_atasks, a_tasks);

  /* Libère la mémoire */
  free(a_tasks);
  free(b_tasks);

  printf("Result: %d\n", knapsack2(work_time, no_tasks, tasks) - no_btasks);

  free(tasks);
  return EXIT_SUCCESS;
}

int* concat_ints(int size_a, int* a, int size_b, int* b) {

  int index = 0;
  int *results = (int*)malloc((size_a + size_b) * sizeof(int));

  /* Copie de a */
  for (index = 0; index < size_a; index++)
    results[index] = a[index];
  
  /* Copie de b */
  for (index = 0; index < size_b; index++)
    results[index + size_a] = b[index];

  return results;
}

int knapsack2(int bag_size, int no_objects, int *objects) {

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
    if (results[bag_size][index]) return index;

  /* Libération du tableau de résultats */
  for (current_size = 0; current_size < bag_size + 1; current_size++)
    free(results[current_size]);
  free(results);

  return -1;
}
