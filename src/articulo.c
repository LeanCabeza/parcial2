/*
 * articulo.c
 *
 *  Created on: 24 jun. 2020
 *      Author: leand
 */


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "articulo.h"
#include "utn.h"
#include "LinkedList.h"

eArticulo* articulo_new()
{
	eArticulo* this=(eArticulo*) malloc(sizeof(eArticulo));
	return this;
}

eArticulo* articulo_newParametros(char* idStr,char* articulo,char* medida, char* precioStr,char* rubroIdStr)
{
	eArticulo* this=articulo_new();

		if(this!=NULL)
		{
			articulo_setId(this,atoi(idStr));
			articulo_setArticulo(this,articulo);
			articulo_setMedida(this,medida);
			articulo_setPrecio(this,atoi(precioStr));
			articulo_setRubroId(this,atoi(rubroIdStr));

		}
		return this;

}

int articulo_delete(eArticulo* this)
{
	int ret=0;
	if(this!=NULL)
	{
		free(this);
		ret=1;
	}
	return ret;
}


//////////////////////////////////////////////////////////////////////////////////////////////////

int articulo_setId(eArticulo* this,int id)
{
	int ret=0;
	static int maxId=0;
	if (this!=NULL)
	{
		if(id<0)
		{
			maxId++;
			this->id=maxId;
		}
		else
		{
			if(id>maxId)
			{
				maxId=id;
			}
			this->id=id;
		}
		ret=1;
	}
	return ret;
}

int articulo_getId(eArticulo* this,int* id)
{
	int ret=0;
		if (this!=NULL && id !=NULL)
		{
			*id=this->id;
			ret=1;
		}
		return ret;
}

//////////////////////////////////////////////////////////////////////////////////////////////////

int articulo_setArticulo(eArticulo* this,char* articulo)
{
	int ret=0;
	if (this!=NULL && articulo!=NULL)
	{
		strcpy(this->articulo,articulo);
		ret=1;
	}
	return ret;
}

int articulo_getArticulo(eArticulo* this,char* articulo)
{
	int ret=0;
	if (this!=NULL && articulo!=NULL)
		{
			strcpy(articulo,this->articulo);
			ret=1;
		}
		return ret;
}

//////////////////////////////////////////////////////////////////////////////////////////////////

int articulo_setMedida(eArticulo* this,char* medida)
{
	int ret=0;
	if (this!=NULL && medida!=NULL)
	{
		strcpy(this->medida,medida);
		ret=1;
	}
	return ret;
}

int articulo_getMedida(eArticulo* this,char* medida)
{
	int ret=0;
	if (this!=NULL && medida!=NULL)
		{
			strcpy(medida,this->medida);
			ret=1;
		}
		return ret;
}

//////////////////////////////////////////////////////////////////////////////////////////////////

int articulo_setPrecio(eArticulo* this,int precio)
{
	int ret=0;
	if (this!=NULL && precio>=0)
	{
		this->precio=precio;
		ret=1;
	}
	return ret;
}


int articulo_getPrecio(eArticulo* this,int* precio)
{
	int ret=0;
	if (this!=NULL && precio!=NULL)
	{
		*precio=this->precio;
		ret=1;
	}
	return ret;
}

//////////////////////////////////////////////////////////////////////////////////////////////////


int articulo_setRubroId(eArticulo* this,int rubroId)
{
	int ret=0;
	if (this!=NULL && rubroId>=0)
	{
		this->rubroId=rubroId;
		ret=1;
	}
	return ret;
}


int articulo_getRubroId(eArticulo* this,int* rubroId)
{
	int ret=0;
	if (this!=NULL && rubroId!=NULL)
	{
		*rubroId=this->rubroId;
		ret=1;
	}
	return ret;
}


//////////////////////////////////////////////////////////////////////////////////////////////////

int articulo_Print(eArticulo* this)
{
	int ret=0;
	int id;
	char articulo[128];
	char medida[128];
	int precio;
	int rubroId;

	if (this!=NULL)
	{
		if(articulo_getId(this,&id) && articulo_getArticulo(this,articulo) && articulo_getMedida(this,medida) && articulo_getPrecio(this,&precio)&& articulo_getRubroId(this,&rubroId))
		{
			printf("ID: %d	||| ARTICULO: %s  ||| MEDIDA: %s ||| PRECIO: $%d ||| RUBRO ID: %d \n",
					id,articulo,medida,precio,rubroId);
			ret=1;
		}
	}
	return ret;
}

//////////////////////////////////////////////////////////////////////////////////////////////////

int articulo_PrintConString(eArticulo* this)
{
	int ret=0;
	int id;
	char articulo[128];
	char medida[128];
	int precio;
	int rubroId;

	if (this!=NULL)
	{
		if(articulo_getId(this,&id) && articulo_getArticulo(this,articulo) && articulo_getMedida(this,medida) && articulo_getPrecio(this,&precio)&& articulo_getRubroId(this,&rubroId))
		{
			if(rubroId==1)
			{
				printf("ID: %d	||| ARTICULO: %s  ||| MEDIDA: %s ||| PRECIO: $%d ||| RUBRO :Cuidado de Ropa \n",
				id,articulo,medida,precio);
			}else if(rubroId == 2)
			{
				printf("ID: %d	||| ARTICULO: %s  ||| MEDIDA: %s ||| PRECIO: $%d ||| RUBRO :Limpieza y desinfeccion \n",
								id,articulo,medida,precio);
			}else if (rubroId==3)
			{
				printf("ID: %d	||| ARTICULO: %s  ||| MEDIDA: %s ||| PRECIO: $%d ||| RUBRO :Cuidado personal e higiene \n",
				id,articulo,medida,precio);
			}else{
				printf("ID: %d	||| ARTICULO: %s  ||| MEDIDA: %s ||| PRECIO: $%d ||| RUBRO :Cuidado del automotor \n",
								id,articulo,medida,precio);
			}


			ret=1;
		}
	}
	return ret;
}


//////////////////////////////////////////////////////////////////////////////////////////////////

int articulo_compararPorNombre(void* this1, void* this2)
{
    char auxNombreA[4096];
    char auxNombreB[4096];

    articulo_getArticulo((eArticulo*)this1, auxNombreA);
    articulo_getArticulo((eArticulo*)this2, auxNombreB);

    if(strcmp(auxNombreA, auxNombreB) > 0)
    {
        return 1;
    }
    if(strcmp(auxNombreA, auxNombreB) < 0)
    {
        return -1;
    }
    return 0;
}































