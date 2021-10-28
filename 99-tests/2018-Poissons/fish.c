#include <stdio.h>

int main() {
  float average_r = 0;
  float average_b = 0;

  int index = 0;
  int tmp = 0;
  int no_redfish = 0;
  int no_blackfish = 0;

  /* Saisi des nombres de poissons */
  fscanf(stdin, "%d", &no_redfish);
  fscanf(stdin, "%d", &no_blackfish);

  /* Somme des poissons rouge */
  for (index=0; index < no_redfish; index++) {
    fscanf(stdin, "%d", &tmp);
    average_r += tmp;
  }

  /* Somme des poissons noirs */
  for (index=0; index < no_blackfish; index++) {
    fscanf(stdin, "%d", &tmp);
    average_b += tmp;
  }

  /* Calcul des moyennes */
  average_r /= (float)no_redfish;
  average_b /= (float)no_blackfish;
    
  /* Affichage du résultat */
  if (average_r > average_b)
    printf("R\r\n");
  else if (average_b > average_r)
    printf("N\r\n");
  else
    printf("RN\r\n");

  return 0;
}
