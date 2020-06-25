/*
 * controller.h
 *
 *  Created on: 24 jun. 2020
 *      Author: leand
 */

#ifndef CONTROLLER_H_
#define CONTROLLER_H_


int controller_loadFromText(char* path , LinkedList* pArrayList);
int controller_ListArticulo(LinkedList* pArrayList);
int controller_saveAsText(char* path, LinkedList* pArrayList);
void nombreArchivoPorParametro(LinkedList* pArrayList);
int controller_sortArticulos(LinkedList* pArrayListEmployee);


void mapeadoArticulos(void* this);
int controller_saveMappeado(LinkedList* pArrayList);

#endif /* CONTROLLER_H_ */
