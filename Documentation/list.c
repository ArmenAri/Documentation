//
//  list.c
//  Documentation
//
//  Created by Armen Aristakessyan on 21/11/2018.
//  Copyright © 2018 ISIMA. All rights reserved.
//

/**
 * @author Armen Aristakesyan
 *
 */

#include "list.h"

void lire(liste_t * l) {
	char str[255];
	printf("Entrez une chaîne de caractère : ");
	fgets(str, 255, stdin);
	str[strlen(str) - 1] = 0;
	insert_at_end(l, str);
}

void lire_from_file(liste_t * l, const char * path) {
	FILE * fd = fopen(path, "r");
	char str[255];
	while(!feof(fd)) {
		fgets(str, 255, fd);
		str[strlen(str) - 1] = 0;
		if(str[0] == '/' || str[0] == '#' || (str[0] == ' ' && str[1] == '*')) {	//commentaire, documentation et préprocesseur
			insert_at_end(l, str);
		}
		if((str[0] > 'a' && str[0] < 'z')) {	//prototypes
			if(path[strlen(path) - 1] == 'c') {
				str[strlen(str) - 1] = 0;
				str[strlen(str) - 1] = ';';
			} else if(path[strlen(path) - 1] == 'h'){
				if(str[0] == 't' && str[1] == 'y') {
					str[strlen(str) - 1] = 0;
					str[strlen(str) - 1] = ';';
				}
			}
			insert_at_end(l, str);
		}
	}
}

void write_to_file(liste_t l, const char * path) {
	FILE * fd = fopen(path, "w");
	cellule_t * cour = l.tete;
	while (cour != NULL) {
		fprintf(fd, "%s\n", cour->text);
		cour = cour->suiv;
	}
}

void insert_at_end(liste_t * l, char * str) {
	cellule_t * c = malloc(sizeof(cellule_t));
	strcpy(c->text, str);
	c->suiv = NULL;
	if (l->tete == NULL) {
		l->tete = c;
	}
	if(l->fin != NULL)
	{
		(l->fin)->suiv = c;
	}
	
	l->fin = c;
}

void display_list(liste_t l) {
	cellule_t * cour = l.tete;
	while (cour != NULL){
		printf("%s\n", cour->text);
		cour = cour->suiv;
	}
}


