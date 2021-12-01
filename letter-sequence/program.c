#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct pair {
    char str[4];
    int occ;
} pair_t;

int len(const char* str);
bool cmp(const char* a, const char* b);

void cpy(char* dest, const char* src, int length);

int main() {

    char msg[2049] = "abc-bca-abc-cba-acb-bca-acb-bac\0";

    int no_pair = 1;
    pair_t results[256];
    char* reader = msg;

    char tmp[4];
    int i = 0;

    /* Ajoute la première occurence */
    results[0].occ = 1;
    cpy(results[0].str, reader, 3);

    reader += 3;
    while(*reader != '\0') {
        cpy(tmp, ++reader, 3);

        /* Parcours toutes les paires existantes */
        for (i = 0; i < no_pair; i++) {

            /* Incrémente le compteur */
            if (cmp(results[i].str, tmp)) {
                results[i].occ++;
                reader += 3;
                break; // Inutile de chercher plus loin
            }

            /* Ajoute une nouvelle paire */
            results[++no_pair].occ = 1;
            cpy(results[no_pair].str, tmp, 3);
            reader += 3;
        }
    }

    for (i = 0; i < no_pair; i++) {
        printf("%s : %d\n\r", results[i].str, results[i].occ);
    }

    return EXIT_SUCCESS;
}

int len(const char* str) {

    int lenght = 0;
    const char* reader = str;

    /* Mesure la longueur de la chaîne */
    while (*reader != '\0') {
        lenght++; reader++;
    }

    return lenght;
}

bool cmp(const char* a, const char* b) {

    int i = 0;

    /* Chaîne de longueur différentes */
    if (len(a) != len(b)) return false;

    /* Compare les 2 chaînes */
    for (i = 0; i < len(a); i++) {

        if (a[i] != b[i]) return false;
    }

    return true;
}

void cpy(char* dest, const char* src, int length) {

    int i = 0;

    /* Copie la chaîne de caractère */
    for (i = 0; i < length; i++)
        dest[i] = src[i];
    dest[i] = '\0';
}