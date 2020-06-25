/*
 ============================================================================
 Name        : parcial_laboratorio_2.c
 Author      : Leandro Cabeza
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "articulo.h"
#include "parser.h"
#include "utn.h"
#include "controller.h"


int main(void) {
	setbuf(stdout,NULL);

	LinkedList* listaArticulos = ll_newLinkedList();

	 char seguir='s';
	    int opcion;
	    int flag = 0;
		char nombreIngresado[50];

	    while (seguir=='s')
	    {
	        printf("\n------MENU------"
	        	   "\n1- Cargar los datos en un archivo ingresado(modo texto)."
		           "\n2- Ordenar por Nombre"
	        	   "\n3- Listar "
	        	   "\n4- Mappeado con descuento"
	        	   "\n5- Generar el archivo de salida: mapeado.csv"
	        	   "\n6-SALIR\n");

	        if(!getInt(&opcion,"\nIngrese la Operacion que desea Realizar: ", "\nError opcion invalida , debe ser un numero entre 1 y 6. Reintente ", 0,6,5))
	        {
				switch (opcion)
				{
				case 1:
						fflush(stdin);
						if(!utn_getTexto("Ingrese el nombre del archivo","ERROR",0,40,5,nombreIngresado))
						{
							controller_loadFromText("Datos_SP_LABO1.csv",listaArticulos);
							controller_saveAsText(nombreIngresado,listaArticulos);
							printf("\nDatos guardados exitosamente");
						}
					flag = 1;
					break;
				case 2:
						if (flag == 1) {
							controller_sortArticulos(listaArticulos);
							controller_saveAsText(nombreIngresado,listaArticulos);
							printf("\nOrdneado con exito");
						} else {
							printf("\n Para poder ordenar  , primero tenes que tener empleados cargados\n\n");
						}
						break;
				case 3:
						if (flag == 1) {
							controller_ListArticulo(listaArticulos);
						} else {
							printf("\n Para poder listar  , primero tenes que tener algo cargado \n");
						}
						break;
				case 4:
					if (flag == 1) {
					if(controller_saveMappeado(listaArticulos))
						{printf("\nSe mappeo con exito");}
					}
					break;
				case 5:
						if(!(controller_saveAsText("mappeado.csv", listaArticulos)))
							{printf("\nSe mappeo con exito");}
					break;
				case 6:
					printf("Hasta Pronto :D");
					seguir='n';
					break;
				}
	        }
	    }
	    return 0;
	}
