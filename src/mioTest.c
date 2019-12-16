#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <errno.h>
#include "sparse.h"

#define MsgSe(condizione,msg)					\
	do {							\
		if(condizione)					\
		{						\
			printf("DEBUG: "#msg"\n");		\
		}						\
	} while(0)


int main()
{

	printf("=========================\n");
	printf("PROVE DEL PROGETTO SPARSE\n");
	printf("=========================\n");


	int exitvalue;
	double numero;

	printf("Creo la matrice vuota:\n");
	smatrix_t* matrice = new_smat(10,8);
	print_smat(stdout, matrice);



	printf("Inserisco elemento");
	exitvalue = put_elem (matrice, 5, 2, 172.68);
	printf(" (esito: %d)\n", exitvalue);
	print_smat(stdout, matrice);

	printf("Inserisco elemento");
	exitvalue = put_elem (matrice, 5, 2, 0);
	printf(" (esito: %d)\n", exitvalue);
	print_smat(stdout, matrice);

	printf("Inserisco elemento");
	exitvalue = put_elem (matrice, 1, 1, 172.68);
	printf(" (esito: %d)\n", exitvalue);
	print_smat(stdout, matrice);

	printf("Inserisco elemento");
	exitvalue = put_elem (matrice, 4, 6, 100.2);
	printf(" (esito: %d)\n", exitvalue);
	print_smat(stdout, matrice);


	printf("Inserisco elemento");
	exitvalue = put_elem (matrice, 4, 0, 45.7);
	printf(" (esito: %d)\n", exitvalue);
	print_smat(stdout, matrice);


	printf("Inserisco elemento");
	exitvalue = put_elem (matrice, 4, 3, 17536.8);
	printf(" (esito: %d)\n", exitvalue);
	print_smat(stdout, matrice);






	printf("Creo la matrice vuota:\n");
	smatrix_t* matriceB = new_smat(8,12);
	print_smat(stdout, matriceB);



	printf("Inserisco elemento");
	exitvalue = put_elem (matriceB, 5, 2, 12.198);
	printf(" (esito: %d)\n", exitvalue);
	print_smat(stdout, matriceB);

	printf("Inserisco elemento");
	exitvalue = put_elem (matriceB, 1, 1, 400);
	printf(" (esito: %d)\n", exitvalue);
	print_smat(stdout, matriceB);

	printf("Inserisco elemento");
	exitvalue = put_elem (matriceB, 4, 7, 40.77);
	printf(" (esito: %d)\n", exitvalue);
	print_smat(stdout, matriceB);


	printf("Inserisco elemento");
	exitvalue = put_elem (matriceB, 4, 0, 598.7413);
	printf(" (esito: %d)\n", exitvalue);
	print_smat(stdout, matriceB);


	printf("Inserisco elemento");
	exitvalue = put_elem (matriceB, 4, 3, 1.005574);
	printf(" (esito: %d)\n", exitvalue);
	print_smat(stdout, matriceB);






	FILE* fd = fopen("matBinaria", "wb");
	savebin_smat(fd, matriceB);
	fclose(fd);

	fd = fopen("matBinaria", "rb");
	smatrix_t* matriceC = loadbin_smat(fd);
	fclose(fd);

	if(matriceC==NULL) printf("Esito caricamento file binario: NULL\n");
	else
	{
	printf("Caricamento OK!\n");
	print_smat(stdout, matriceC);
	printf("Sono uguali? %d\n", is_equal_smat(matriceB, matriceC));
	}



	/*
	printf("Inserisci coordinate da leggere (-1 per uscire):\n\n");
	int x, y;
	scanf("%d", &x);
	scanf("%d", &y);
	while(x >= 0)
	{
		exitvalue = get_elem(matriceC, x, y, &numero);
		printf("(%d) L'elemento in posizione <%d, %d> ha valore %lf\n", exitvalue, x, y, numero);
		scanf("%d", &x);
		scanf("%d", &y);
	}
	*/
	



	printf("Dealloco\n");
	free_smat(&matrice);
	free_smat(&matriceB);
	free_smat(&matriceC);

	return 0;
}
