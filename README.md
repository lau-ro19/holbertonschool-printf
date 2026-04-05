_printf - Custom Implementation 🚀
Description
Ce projet est une réimplémentation personnalisée de la célèbre fonction printf de la bibliothèque standard C (stdio.h). L'objectif est de produire une sortie formatée sur la sortie standard (stdout) en gérant différents spécificateurs de conversion.

Ce projet a été réalisé dans le cadre du cursus Holberton School pour approfondir la compréhension des fonctions variadiques, du parsing de chaînes de caractères et de la gestion de la mémoire en C.

Fonctionnalités
Notre fonction _printf copie le comportement du printf original pour les cas suivants :
Spécificateur,Description
%c,Imprime un caractère unique.
%s,Imprime une chaîne de caractères (gère le cas NULL).
%%,Imprime le symbole de pourcentage.
%d,Imprime un entier signé en base 10.
%i,Imprime un entier (identique à %d).

Structure du Projet
Le code est organisé de manière modulaire pour faciliter la maintenance et l'ajout de nouveaux spécificateurs :

_printf.c : Point d'entrée principal. Contient la boucle de parsing de la chaîne de format.

main.h : Fichier d'en-tête contenant les définitions de structures, les prototypes et les macros.

get_print_func.c : Le "Dispatcher". Il contient le tableau de structures qui fait le lien entre un spécificateur et sa fonction.

print_basic.c : Logique d'affichage pour les caractères, les chaînes et le symbole %.

print_numbers.c : Logique d'affichage récursive pour les entiers %d et %i, gérant les nombres négatifs et les limites (INT_MIN).

utils.c : Contient la fonction _putchar.

_printf.3 : Page de manuel (man page) du projet.

Installation et Compilation
Pour utiliser cette fonction, clonez le dépôt et compilez les fichiers .c avec votre programme :

Bash
gcc -Wall -Werror -Wextra -pedantic -std=gnu89 *.c -o printf_test
Exemple d'utilisation
C
#include "main.h"

int main(void)
{
    int len;

    len = _printf("Un caractère : [%c]\n", 'H');
    _printf("Une chaîne : [%s]\n", "Hello Holberton");
    _printf("Un entier : [%d]\n", -1024);
    _printf("Nombre de caractères imprimés : %d\n", len);

    return (0);
}
Page de Manuel
Vous pouvez consulter la documentation détaillée en utilisant :

Bash
man ./_printf.3
Auteurs
ROSE-ANTOINETTE Laurent - [lau-ro19]
