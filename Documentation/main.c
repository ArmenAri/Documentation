//
//  main.c
//  Documentation
//
//  Created by Armen Aristakessyan on 21/11/2018.
//  Copyright © 2018 ISIMA. All rights reserved.
//

#include <stdio.h>
#include "list.h"

int main(int argc, const char * argv[]) {
	liste_t l;
	l.tete = NULL;
	l.fin = NULL;
	lire_from_file(&l, argv[1]);
	write_to_file(l, "/Users/armenaristakessyan/Documents/prog./c/tp_c_isima/Documentation/Documentation/doc.txt");
	return 0;
}
