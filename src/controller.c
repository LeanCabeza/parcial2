/*
 * controller.c
 *
 *  Created on: 24 jun. 2020
 *      Author: leand
 */
#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "articulo.h"
#include "parser.h"

int controller_loadFromText(char* path , LinkedList* pArrayList)
{
	FILE* pFile;
	int retorno = -1;
	if(pArrayList != NULL)
	{
		pFile = fopen(path,"r");
		if(pFile != NULL)
		{
			retorno = parser_articuloFromText(pFile,pArrayList);
			fclose(pFile);
		}else{
			printf("Algo revento mientras se parceaba");
		}
	}else{
		printf("\n algo revento en la validacion pArrayList != NULL ");
	}
	return retorno;
}

int controller_ListArticulo(LinkedList* pArrayList)
{
	int tam;
	int i;
	eArticulo* eAux=NULL;
	if(pArrayList!=NULL)
	{
		tam=ll_len(pArrayList);
		if (tam>0)
		{
			printf("\n\n****Listado ****\n");
			for (i=0; i < tam; i++)
			{
				eAux=ll_get(pArrayList,i);
				if(eAux!=NULL)
				{
					articulo_PrintConString(eAux);
				}
			}
		}
		else
		{
			printf("\n\n\nEl sitema no posee datos\n");
		}
	}
	system("PAUSE()");
    return 1;
}

int controller_saveAsText(char* path, LinkedList* pArrayList)
{
    int ret = -1;
    FILE* pFileAux = NULL;
    eArticulo *Articulo = NULL;

    int auxId;
    char auxArticulo[200];
    char medida[200] ;
    int precio;
    int rubroId;

    if(path != NULL && pArrayList != NULL)
    {
        pFileAux = fopen(path, "w");
        if(pFileAux != NULL)
        {
            for(int i =0; i<ll_len(pArrayList); i++)
            {
            	Articulo = ll_get(pArrayList, i);

                	 if(articulo_getId(Articulo,&auxId) &&
                        articulo_getArticulo(Articulo,auxArticulo) &&
                        articulo_getMedida(Articulo,medida) &&
						articulo_getPrecio(Articulo,&precio) &&
                        articulo_getRubroId(Articulo,&rubroId))
                {
                    fprintf(pFileAux,"%d , %s , %s , %d , %d \n", auxId,auxArticulo,medida,precio,rubroId );
                    ret = 0;
                }
                else
                {
                    articulo_delete(Articulo);
                }
            }
        }
        fclose(pFileAux);
    }
    return ret;
}

int controller_sortArticulos(LinkedList* pArrayList)
{
    int ret = -1;

    if(pArrayList != NULL)
    {
        ll_sort(pArrayList, articulo_compararPorNombre, 1);
        ret=0;
    }
    return ret;
}


int mapeadoArticulos(void* this)
{
	int auxPrecio;
	int descuento ;
	int precioFinal;
	int auxRubro;
	int ret = -1;


	if (this != NULL) {

		this=(eArticulo*)this;

		articulo_getPrecio((eArticulo*) this, &auxPrecio);
		articulo_getRubroId((eArticulo*) this, &auxRubro);

		if (auxPrecio >= 120 && auxRubro == 1)
		{
			ret =1 ;
			descuento = auxPrecio * 20 /100;
			precioFinal = auxPrecio - descuento;
			articulo_setPrecio((eArticulo*) this,precioFinal);

		}else if (auxPrecio >= 200 && auxRubro == 2)
		{
			ret = 1;
			descuento = auxPrecio * 10 / 100;
			precioFinal = auxPrecio - descuento;
			articulo_setPrecio((eArticulo*) this, precioFinal);
		}else{
			ret = 1;
			articulo_getPrecio((eArticulo*) this, &auxPrecio);
			articulo_setPrecio((eArticulo*) this,auxPrecio);
		}
	}
	return ret ;
}


int controller_saveMappeado(LinkedList* pArrayList)
{
    int ret = -1;

    if( pArrayList != NULL)
    {
            ll_map(pArrayList, mapeadoArticulos);
            ret = 1 ;
    }
    return ret;
}


//////////////////////////////////////////////////////////////////////////////////////////////////



int articulos_rubro1 (void* this)
{
    int ret = 0;
    int auxRubro;

    if(this!= NULL)
    {
        articulo_getRubroId((eArticulo*)this, &auxRubro);

        if(auxRubro ==1 )
        {
            ret=1;
        }
    }
    return ret;
}

////////////////////////////////////////////////////////////////////////

int articulos_Mayores100 (void* this)
{
    int ret = 0;
    int auxPrecio;

    if(this!= NULL)
    {
        articulo_getPrecio((eArticulo*)this,&auxPrecio);
        if(auxPrecio > 100)
        {
            ret=1;
        }
    }
    return ret;
}

////////////////////////////////////////////////////////////////////////

int controller_informes( LinkedList* pArrayList)
{
    int ret = -1;
    int cantidadVentasMayores100;
    int cantidadRubro1 ;

    if(pArrayList != NULL)
    {

            cantidadVentasMayores100 = ll_count(pArrayList,articulos_Mayores100);
            cantidadRubro1 = ll_count(pArrayList,articulos_rubro1);

            printf("\n----INFORMES-----\n");
            printf("\nCantidad de Articulos con el precio mayor a $ 100 : %d\n",cantidadVentasMayores100);
            printf("\nCantidad de articulos del rubro 1 : %d\n",cantidadRubro1);

            ret= 0 ;
        }
    return ret;
}
