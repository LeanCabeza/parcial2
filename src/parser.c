/*
 * parser.c
 *
 *  Created on: 24 jun. 2020
 *      Author: leand
 */

#include <stdio.h>
#include <stdlib.h>
#include "articulo.h"
#include "LinkedList.h"

int parser_articuloFromText(FILE* pFile , LinkedList* pArray)
{
	int ret=0;
		char buffer[5][128];
		int cant=0;
		eArticulo* pAux=NULL;

		if(pFile!=NULL && pArray !=NULL)
		{
				 fscanf(pFile, "%[^,],%[^,],%[^,],%[^,],%[^\n]\n", buffer[0], buffer[1], buffer[2],buffer[3], buffer[4]);

				 while(!feof(pFile))
				 {
					 cant=fscanf(pFile,"%[^,],%[^,],%[^,],%[^,],%[^\n]\n",buffer[0], buffer[1], buffer[2],buffer[3], buffer[4]);
				     if(cant < 5)
				     {
				    	 ret=0;
				    	 break;
				     }
				     else
				     {
				    	 if((pAux= articulo_newParametros(buffer[0], buffer[1], buffer[2], buffer[3], buffer[4]))!=NULL)
				    	 {
				    		 ll_add(pArray,pAux);
				    		 ret=1;
				    	 }
				    	 else
				    	 {
				    		 ret=-1;
				    		 printf("\nAlgo revento en el parser cuando hice el !feof");
				    		 break;
				    	 }
				     }
				 }
		}
	    return ret;
}
