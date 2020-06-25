/*
 * articulo.h
 *
 *  Created on: 24 jun. 2020
 *      Author: leand
 */

#ifndef ARTICULO_H_
#define ARTICULO_H_

typedef struct
{
    int id;
    char articulo[300];
    char medida[300];
    int precio;
    int rubroId;

}eArticulo;

eArticulo* articulo_new();
eArticulo* articulo_newParametros(char* idStr,char* articulo,char* medida, char* precioStr,char* rubroIdStr);
int articulo_delete(eArticulo* this);

int articulo_setId(eArticulo* this,int id);
int articulo_getId(eArticulo* this,int* id);

int articulo_setArticulo(eArticulo* this,char* articulo);
int articulo_getArticulo(eArticulo* this,char* articulo);

int articulo_setMedida(eArticulo* this,char* medida);
int articulo_getMedida(eArticulo* this,char* medida);

int articulo_setPrecio(eArticulo* this,int precio);
int articulo_getPrecio(eArticulo* this,int* precio);

int articulo_setRubroId(eArticulo* this,int rubroId);
int articulo_getRubroId(eArticulo* this,int* rubroId);

int articulo_Print(eArticulo* this);
int articulo_PrintConString(eArticulo* this);

int articulo_compararPorNombre(void* this1, void* this2);

#endif /* ARTICULO_H_ */
