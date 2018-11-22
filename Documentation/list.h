//
//  list.h
//  Documentation
//
//  Created by Armen Aristakessyan on 21/11/2018.
//  Copyright © 2018 ISIMA. All rights reserved.
//

#ifndef list_h
#define list_h

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct cellule {
	/**
	 * content of cell
	 */
	char text[255];
	
	/**
	 * pointer on the next cell
	 */
	struct cellule * suiv;
} cellule_t;

typedef struct liste {
	/**
	 * the pointer on the head of the list
	 */
	cellule_t * tete;
	
	/**
	 * the pointer on the end of the list
	 */
	cellule_t * fin;
} liste_t;

/**
 * @brief read the string entered by the user and
 * call insert_at_end() function
 * @param liste_t *l
 */
void lire(liste_t *);

/**
 * @brief read the string from file in path str
 * and add the string in list l
 * @param liste_t *l, const char *path
 */
void lire_from_file(liste_t *, const char *);

/**
 * @brief write the content of the list l in file
 * on path path
 * @param liste_t l, const char *path
 */
void write_to_file(liste_t l, const char * path);

/**
 * @brief insert the string str at the end of list l
 * @param liste_t *l, char *str
 */
void insert_at_end(liste_t *, char *);

/**
 * @brief display the list l
 * @param liste_t l
 */
void display_list(liste_t);

#endif /* list_h */
