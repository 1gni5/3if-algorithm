#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct pair {
    char key[4];
    int cnt;
} pair_t;

/*
 * Calcul la longueur d'une chaîne de caractère.
 */
int strlen(const char* str) {

    int size = 0;
    const char* reader = str;

    /* Compte le nombre de caractères */
    while (*(reader++) != '\0' )
        size += 1;

    return size;
}

/* 
 * Compare 2 chaines de caractères.
 */
bool strcmp(const char* a, const char* b) {

    int length = strlen(a);
    int index = 0;

    /* 2 chaînes de taille différentes */
    if (length != strlen(b)) return false;

    for (index = 0; index < length; index++)
        if (a[index] != b[index]) return false;
 
    return true;
}

void count_words(const char* str) {

    int length = strlen(str);
    pair_t data[256];

}

int main() {

    return EXIT_SUCCESS;
}