#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"


static Node* getNode(LinkedList* this, int nodeIndex);
static int addNode(LinkedList* this, int nodeIndex,void* pElement);

/** \brief Crea un nuevo LinkedList en memoria de manera dinamica
 *
 *  \param void
 *  \return LinkedList* Retorna (NULL) en el caso de no conseguir espacio en memoria
 *                      o el puntero al espacio reservado
 */
LinkedList* ll_newLinkedList(void)
{
	//RESERVA ESPACIO DE MEMORIA PARA UNA LINKED LIST Y LE ASIGNA EL FIRSTNODE NULL Y EL SIZE EN 0
    LinkedList* this;
    this = (LinkedList *)malloc(sizeof(LinkedList));
    if(this != NULL)
    {
        this->size=0;
        this->pFirstNode = NULL;
    }
    return this;
}

/** \brief Retorna la cantidad de elementos de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna (-1) si el puntero es NULL o la cantidad de elementos de la lista
 *
 */
int ll_len(LinkedList* this)
{
	// SIMPLEMENTE RETORNA EL SIZE DE LA LINKED LIST , RETORNARIA EL NRO DE NODOS QUE TIENE
	int returnAux = -1;
	    if(this != NULL)
	    {
	        returnAux = this-> size;
	    }
	    return returnAux;
}


/** \brief  Obtiene un nodo de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param index int Indice del nodo a obtener
 * \return Node* Retorna  (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        (pNode) Si funciono correctamente
 *
 */
static Node* getNode(LinkedList* this, int nodeIndex)
{
	// TRAE EL PUNTERO A NODO INDICADO EN EL INDEX , QUE SERIA EL NUMERO DE SIZE
	Node* pNode = NULL;
	    if(this != NULL && nodeIndex >= 0 && nodeIndex < ll_len(this)) // ACA EVALUO QUE SEA RAZONABLE , QUE EL NODO QUE PIDE NO SEA MAYOR AL LEN(SIZE)
	    {
	        pNode = this->pFirstNode;

	        if(pNode != NULL)
	        {
	            for(int i = 0 ; i<nodeIndex ; i++)
	            {
	                pNode = pNode->pNextNode;
	            }
	        }
	    }
	    return pNode;
}

/** \brief  Permite realizar el test de la funcion getNode la cual es privada
 *
 * \param this LinkedList* Puntero a la lista
 * \param index int Indice del nodo a obtener
 * \return Node* Retorna  (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        (pElement) Si funciono correctamente
 *
 */
Node* test_getNode(LinkedList* this, int nodeIndex)
{
    return getNode(this, nodeIndex);
}


/** \brief Agrega y enlaza un nuevo nodo a la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion donde se agregara el nuevo nodo
 * \param pElement void* Puntero al elemento a ser contenido por el nuevo nodo
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
static int addNode(LinkedList* this, int nodeIndex,void* pElement)
{
	int returnAux = -1;
	    Node* newNode = malloc(sizeof(Node));
	    Node* pActualNode = NULL;

	    newNode->pElement = pElement;

	    if(this != NULL && nodeIndex >= 0 && nodeIndex <= ll_len(this))
	    {
	    	// Si EL NODO QUE QUIERO AGREGAR ESTA AL PRINCIPIO
	    	if(nodeIndex == 0)
	    	{
	    		newNode->pNextNode = this->pFirstNode;
	    		this->pFirstNode = newNode;
	    		this->size ++;
	    		returnAux = 0;
	    	}
	    	else
	    	{
	    		pActualNode = getNode(this,nodeIndex - 1);
	    		newNode->pNextNode = pActualNode->pNextNode;
	    		pActualNode->pNextNode = newNode;
	    		this->size++;
	    		returnAux = 0;

	    	}
	    }
	    return returnAux;
}

/** \brief Permite realizar el test de la funcion addNode la cual es privada
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion donde se agregara el nuevo nodo
 * \param pElement void* Puntero al elemento a ser contenido por el nuevo nodo
  * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
int test_addNode(LinkedList* this, int nodeIndex,void* pElement)
{
    return addNode(this,nodeIndex,pElement);
}


/** \brief  Agrega un elemento a la lista
 * \param pList LinkedList* Puntero a la lista
 * \param pElement void* Puntero al elemento a ser agregado
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 0) Si funciono correctamente
 *
 */
int ll_add(LinkedList* this, void* pElement)
{
 // AGREGA UN NODO LLAMANDO A ADD NODE Y A ESE NODO LE CARGA EL PUNTERO AL ELEMENTO QUE SE RECIBIO POR PARAMETRO
	int returnAux = -1;
	    if(this != NULL) //Verifico que la lista sea distinta de NULL
	    {
	    	returnAux = addNode(this,this->size,pElement);//retorno el nodo nuevo al final de la lista

	    }
	    return returnAux;
}

/** \brief Permite realizar el test de la funcion addNode la cual es privada
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento a obtener
 * \return void* Retorna    (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                            (pElement) Si funciono correctamente
 *
 */
void* ll_get(LinkedList* this, int index)
{
	// TRAE EL PUNTERO A ELEMENTO INDICADO EN EL INDEX
	void *returnAux = NULL;
	Node *pNodeAux;

	if (this != NULL && index >= 0 && index < ll_len(this)) {
		pNodeAux = getNode(this, index);
		if (pNodeAux != NULL) {
			returnAux = pNodeAux->pElement;
		}
	}

	return returnAux;
}


/** \brief Modifica un elemento de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento a modificar
 * \param pElement void* Puntero al nuevo elemento
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
int ll_set(LinkedList* this, int index,void* pElement)
{
	//ASIGNO EL ELEMENTO QUE ME INDICARON POR PARAMETRO EN EL INDEX QUE ME INDICARON POR PARAMETRO
	int returnAux = -1;
	Node *pNodeAux;

	if (this != NULL && index >= 0 && index < ll_len(this)) {
		pNodeAux = getNode(this, index);
		pNodeAux->pElement = pElement;
		returnAux = 0;
	}
	return returnAux;
}


/** \brief Elimina un elemento de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento a eliminar
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
int ll_remove(LinkedList* this,int index)
{
	int returnAux = -1; //Variable de retorno
	Node *pNodeA = NULL;
	Node *pNodeB = NULL;

	if (this != NULL && index >= 0 && index < ll_len(this) && ll_len(this) > 0) {
		if (index != 0 && index != (ll_len(this))) {
			pNodeB = getNode(this, (index - 1)); // COPIO LA REFERENCIA DEL NODO ANTERIOR AL NODO QUE QUIERO BORRAR
			pNodeA = getNode(this, index); // COPIO LA REFERENCIA DEL NODO ACTUAL
			pNodeB->pNextNode = pNodeA->pNextNode; // AL NEXT NODE DEL NODO ANTERIOR AL ACTUAL , LE PONGO LA REFERENCIA QUE TENIA GUARDADA DEL SIGUIENTE QUE QUIERO BORRAR
			free(pNodeA); // LIBERO NODO A PORQUE YA NO LO VOY A USAR MAS.
		} else {
			if (index == 0) { // SI EL NODO QUE QUIERO REMOVER ES EL PRIMERO
				pNodeA = getNode(this, index);
				this->pFirstNode = pNodeA->pNextNode;
				free(pNodeA);
			} else { // SI EL NODO QUE QUIERO REMOVER ES EL ULTIMO
				if (index != 0 && index == (ll_len(this))) {
					free(pNodeA);
				}
			}
		}
		// SI PUDE REMOVER CORRECTAMENTE LO QUE ME INDICARON , RESTO EL SIZE DE LA LINKED LIST.
		this->size--;
		returnAux = 0;
	}
	return returnAux;
}


/** \brief Elimina todos los elementos de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 0) Si funciono correctamente
 *
 */

int ll_clear(LinkedList* this)
{
	// EN ESTA FUNCION SE ELIMINAN TODOS LOS ELEMENTOS DE LA LISTA
	int returnAux = -1;
	    int i;
	    int len;

	    len = ll_len(this);

	    if(this != NULL)
	    {
	    	for(i=len;i>=0;i++) // RECORRO LA LINKED LIST DESDE EL ULTIMO HACIA EL PRIMERO
	    	{
	    		ll_remove(this, i - 1);
	    	}
	    	returnAux = 0;
	    }

	    return returnAux;
}


/** \brief Elimina todos los elementos de la lista y la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 0) Si funciono correctamente
 *
 */

int ll_deleteLinkedList(LinkedList* this)
{
	// EN ESTA FUNCION SE ELIMINAN TODOS LOS ELEMENTOS DE LA LISTA Y LA LISTA , ESA ES LA DIFERENCIA CON LL_CLEAR
	int returnAux = -1;
	if (this != NULL)
	{
		ll_clear(this);
		free(this);
		returnAux = 0;
	}
	return returnAux;
}

/** \brief Busca el indice de la primer ocurrencia del elemento pasado como parametro
 *
 * \param this LinkedList* Puntero a la lista
 * \param pElement void* Puntero al elemento
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        (indice del elemento) Si funciono correctamente
 *
 */
int ll_indexOf(LinkedList* this, void* pElement)
{
	    int returnAux = -1;
	    Node* pNode = NULL;
	    int i;
	    int len;

	    len = ll_len(this);
	    if(this != NULL)
	    {
	    	for(i=0;i<len;i++)
	    	{
	    		pNode = getNode(this,i);
	    		if(pNode->pElement == pElement)
	    		{
	    			returnAux = i;
	    		}
	    	}
	    }
	    return returnAux;
}

/** \brief Indica si la lista esta o no vacia
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 0) Si la lista NO esta vacia
                        ( 1) Si la lista esta vacia
 *
 */
int ll_isEmpty(LinkedList* this)
 {
	// EN ESTA FUNCION SIMPLEMENTE SE EVALUA EL SIZE , SI EL SIZE ES 0 , ESTA VACIA , SINO TIENE ALGO CARGADO
	int returnAux = -1;

	if (this != NULL) {
		if (this->pFirstNode == NULL && this->size == 0) {
			returnAux = 1;
		} else {
			returnAux = 0;
		}
	}
	return returnAux;
}

/** \brief Inserta un nuevo elemento en la lista en la posicion indicada
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion donde se agregara el nuevo elemento
 * \param pElement void* Puntero al nuevo elemento
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
int ll_push(LinkedList* this, int index, void* pElement)
{
	int returnAux = -1;

	if (this != NULL && index >= 0 && index <= ll_len(this)) {
		returnAux = addNode(this, index, pElement);
	}
	return returnAux;
}


/** \brief Elimina el elemento de la posicion indicada y retorna su puntero
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento eliminar
 * \return void* Retorna    (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                            (pElement) Si funciono correctamente
 *
 */
void* ll_pop(LinkedList* this,int index)
{
	// ELIMINA EL NRO DEL INDEX INDICADO POR PARAMETRO Y RETORNO EL PUNTERO A ELEMENTO DE LO QUE BORRE.
	void *returnAux = NULL;
	if (this != NULL && index >= 0 && index <= ll_len(this)) {
		returnAux = ll_get(this, index);
		if (returnAux != NULL) {
			ll_remove(this, index);
		}
	}
	return returnAux;
}


/** \brief  Determina si la lista contiene o no el elemento pasado como parametro
 *
 * \param this LinkedList* Puntero a la lista
 * \param pElement void* Puntero del elemento a verificar
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 1) Si contiene el elemento
                        ( 0) si No contiene el elemento
*/
int ll_contains(LinkedList* this, void* pElement)
{
	int returnAux = -1;
	if (this != NULL) {
		if (ll_indexOf(this, pElement) == -1) {
			returnAux = 0;
		} else {
			// SI EL ELEMENTO INDICADO FORMA PARTE DE LA LISTA , RETORNA 1
			returnAux = 1;
		}
	}
	return returnAux;
}

/** \brief  Determina si todos los elementos de la lista (this2)
            estan contenidos en la lista (this)
 *
 * \param this LinkedList* Puntero a la lista
 * \param this2 LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si alguno de los punteros a las listas son NULL
                        ( 1) Si los elementos de (this2) estan contenidos en la lista (this)
                        ( 0) si los elementos de (this2) NO estan contenidos en la lista (this)
*/
int ll_containsAll(LinkedList* this,LinkedList* this2)
{
	int returnAux = -1;
	void *pElement;

	if (this != NULL && this2 != NULL) {
		returnAux = 1;
		for (int i = 0; i < ll_len(this2); i++) {
			pElement = ll_get(this2, i);
			if (!ll_contains(this, pElement)) {
				returnAux = 0;
				break;
			}
		}
	}
	return returnAux;
}

/** \brief Crea y retorna una nueva lista con los elementos indicados
 *
 * \param pList LinkedList* Puntero a la lista
 * \param from int Indice desde el cual se copian los elementos en la nueva lista
 * \param to int Indice hasta el cual se copian los elementos en la nueva lista (no incluido)
 * \return LinkedList* Retorna  (NULL) Error: si el puntero a la listas es NULL
                                o (si el indice from es menor a 0 o mayor al len de la lista)
                                o (si el indice to es menor o igual a from o mayor al len de la lista)
                         (puntero a la nueva lista) Si ok
*/
LinkedList* ll_subList(LinkedList* this,int from,int to)
{
	 LinkedList* cloneArray = NULL;
	    void* pElement;
	    int i;
	    // VALIDA QUE EL FROM Y EL TO , SEAN LOGICOS , OSEA QUE NO SE PASEN DEL SIZE
	    if(this != NULL && from >= 0 && to <= this->size)
	    {
	    	cloneArray = ll_newLinkedList();
	    	for(i=from;i<to;i++)
	    	{
	    		pElement = ll_get(this,i);
	    		ll_add(cloneArray,pElement);
	    	}
	    }
	    return cloneArray;
}


/** \brief Crea y retorna una nueva lista con los elementos de la lista pasada como parametro
 *
 * \param pList LinkedList* Puntero a la lista
 * \return LinkedList* Retorna  (NULL) Error: si el puntero a la listas es NULL
                                (puntero a la nueva lista) Si ok
*/
LinkedList* ll_clone(LinkedList* this)
{
	LinkedList* cloneArray = NULL;

	    if(this != NULL)
	    {
	    	cloneArray = ll_subList(this,0,ll_len(this));
	    }
	    return cloneArray;
}


/** \brief Ordena los elementos de la lista utilizando la funcion criterio recibida como parametro
 * \param pList LinkedList* Puntero a la lista
 * \param pFunc (*pFunc) Puntero a la funcion criterio
 * \param order int  [1] Indica orden ascendente - [0] Indica orden descendente
 * \return int Retorna  (-1) Error: si el puntero a la listas es NULL
                                ( 0) Si ok
 */
int ll_sort(LinkedList* this, int (*pFunc)(void* ,void*), int order)
{
	int returnAux = -1;
	int flagSwap;
	void *pElementA;
	void *pElementB;

	if (this != NULL && pFunc != NULL && (order == 0 || order == 1)) {
		do {
			flagSwap = 0;
			for (int i = 0; i < ll_len(this) - 1; i++) {
				pElementA = ll_get(this, i);
				pElementB = ll_get(this, i + 1);

				if ((pFunc(pElementA, pElementB) < 0 && !order) || (pFunc(pElementA, pElementB) > 0 && order))
				{
					ll_set(this, i, pElementB);
					ll_set(this, i + 1, pElementA);
					flagSwap = 1;
				}
			}
		} while (flagSwap);
		returnAux = 0;
	}
	return returnAux;
}

/** \brief Recorre la lista y a cada uno de los elementos se los pasa como param al puntero a funcion
    segun esa funcion criterio, va a modificar a cada elemento que llame, y por ende, a la lista original.
 * \param this LinkedList* Puntero a la lista
 * \param pFunc (*pFunc) Puntero a la funcion criterio
 * \return int Retorna  (-1) Error: si alguno de los punteros a las listas o el puntero a funcion son NULL
                       ( 0) si modifico los elementos de thiscontenidos en la lista.
 */

int ll_map(LinkedList* this, int (*pFunc)(void*))
{
    int returnAux =-1;
    void* pElement;

    if(this != NULL && pFunc != NULL)
    {
        for(int i = 0 ; i< ll_len(this);  i++)
        {

            pElement = ll_get(this,i);
            if(pFunc(pElement))
            {
                returnAux = 0;
            }
        }
    }
    return returnAux;
}

/** \brief Determina si este elemento integra o no la lista devuelviendo verdadero o falso.
    y lo cuenta si cumple con la funcion criterio.
 * \param pList LinkedList* Puntero a la lista.
 * \param pFunc (*pFunc) Puntero a la funcion criterio.
 * \return int Retorna (-1) Error: si alguno de los punteros a las listas o el puntero a funcion son NULL
                       (int) cuantos elementos de this contenidos en la lista segun la funcion criterio pasada como parametro de la funcion.

 */
int ll_count(LinkedList* this, int (*pFunc)(void* pElement))
{
    int contador = 0;
    int i;
    void* pElement;
    if(this != NULL && pFunc != NULL)
    {
        for(i=0;i<ll_len(this);i++)
        {
            pElement = ll_get(this, i);
            if(pFunc(pElement) == 1)
            {
                contador++;
            }
        }
    }
    return contador;
}

