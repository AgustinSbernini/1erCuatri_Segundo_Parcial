#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"

static Node* getNode(LinkedList* this, int nodeIndex);
static int addNode(LinkedList* this, int nodeIndex,void* pElement);

LinkedList* ll_newLinkedList()
{
    LinkedList* this;

    this = (LinkedList*) malloc(sizeof(LinkedList));

    if(this != NULL)
    {
		this->size = 0;
		this->pFirstNode = NULL;
    }

    return this;
}

int ll_len(LinkedList* this)
{
    int retorno = -1;

    if(this != NULL)
    {
    	retorno = this->size;
    }

    return retorno;
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
	Node* nodoAux = NULL;
	int len;

	if(this != NULL && nodeIndex >= 0)
	{
		len = ll_len(this);

		if(len >= 0 && nodeIndex < len)
		{
			for(int i = 0; i < len; i++)
			{
				if(i == 0)
				{
					nodoAux = this->pFirstNode;
				}
				else
				{
					nodoAux = nodoAux->pNextNode;
				}
				if(i == nodeIndex)
				{
					break;
				}
			}
		}
	}

    return nodoAux;
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
    int retorno = -1;
    Node* nuevoNodo;
    int len;

    if(this != NULL)
    {
		len = ll_len(this);

		if(len >= 0)
		{
			if(nodeIndex > -1 && nodeIndex <= len)
			{
				nuevoNodo = (Node*) malloc (sizeof(Node));
				if(nuevoNodo != NULL)
				{
					if(len == 0 || nodeIndex == 0)
					{
						if(this->pFirstNode != NULL)
						{
							nuevoNodo->pNextNode = this->pFirstNode;
						}
						else
						{
							nuevoNodo->pNextNode = NULL;
						}

						this->size++;
						this->pFirstNode = nuevoNodo;
						nuevoNodo->pElement = pElement;
					}
					else
					{
						Node* indice;
						indice = getNode(this, nodeIndex - 1);

						if(indice != NULL)
						{
							this->size++;
							indice->pNextNode = nuevoNodo;
							nuevoNodo->pElement = pElement;
							nuevoNodo->pNextNode = NULL;
						}
					}
					retorno = 0;
				}

			}
		}
    }

    return retorno;
}

int ll_add(LinkedList* this, void* pElement)
{
    int retorno = -1;

    if(this != NULL)
    {
    	int len;

    	len = ll_len(this);

    	if(len >= 0)
    	{
			if(addNode(this, len, pElement) == 0)
			{
				retorno = 0;
			}
    	}
    }

    return retorno;
}

void* ll_get(LinkedList* this, int index)
{
    void* retorno = NULL;

    if(this != NULL && index >= 0)
    {
    	Node* nodo;

    	nodo = getNode(this, index);

    	if(nodo != NULL)
    	{
    		retorno = nodo->pElement;
    	}
    }

    return retorno;
}

int ll_set(LinkedList* this, int index,void* pElement)
{
    int retorno = -1;
    int len;

    len = ll_len(this);

    if(this != NULL && index >= 0 && index < len)
    {
    	Node* modificarNodo;

    	modificarNodo = getNode(this, index);

    	if(modificarNodo != NULL)
    	{
    		modificarNodo->pElement = pElement;
    		retorno = 0;
    	}
    }

    return retorno;
}

int ll_remove(LinkedList* this,int index)
{
    int retorno = -1;
    int len;

    len = ll_len(this);

    if(this != NULL && index >= 0 && index < len)
    {
    	Node* anteriorNodo;
    	Node* nodoActual;

		nodoActual = getNode(this, index);

		if(nodoActual != NULL)
		{
			if(index == 0)
			{
				this->pFirstNode = nodoActual->pNextNode;
			}
			else
			{
				anteriorNodo = getNode(this, index - 1);

				if(anteriorNodo != NULL)
				{
					anteriorNodo->pNextNode = nodoActual->pNextNode;
				}
			}

			retorno = 0;
			this->size--;
			free(nodoActual);
		}
	}

    return retorno;
}

int ll_clear(LinkedList* this)
{
    int retorno = -1;
    int len;

    if(this != NULL)
    {
    	len = ll_len(this);

    	for(int i = len; i > 0; i--)
    	{
    		ll_remove(this, i);
    	}
    	this->size--;
    	retorno = 0;
    }

    return retorno;
}

int ll_deleteLinkedList(LinkedList* this)
{
    int retorno = -1;

    if(this != NULL)
    {
    	ll_clear(this);
    	free(this);
    	retorno = 0;
    }
    return retorno;
}

int ll_indexOf(LinkedList* this, void* pElement)
{
    int retorno = -1;

    if(this != NULL)
    {
    	Node* nodo;
    	int contador = 0;

    	nodo = this->pFirstNode;

    	while(nodo != NULL)
    	{
			if(nodo->pElement == pElement)
			{
				retorno = contador;
				break;
			}
			else
			{
				nodo = nodo->pNextNode;
				contador++;
			}
    	}
    }
    return retorno;
}

int ll_isEmpty(LinkedList* this)
{
    int retorno = -1;

    if(this != NULL)
    {
    	if(this->size == 0)
    	{
    		retorno = 1;
    	}
    	else
    	{
    		retorno = 0;
    	}
    }

    return retorno;
}

int ll_push(LinkedList* this, int index, void* pElement)
{
    int retorno = -1;
    int len;

    len = ll_len(this);

    if(this != NULL && index >= 0 && index <= len)
    {
    	Node* nodoAnterior;
    	Node* nodoAgregar;
    	Node* nodoPosterior;

    	nodoAgregar = (Node*) malloc (sizeof(Node));
    	nodoPosterior = getNode(this, index);

    	if(nodoAgregar != NULL)
    	{
			if(index == 0)
			{
				this->pFirstNode = nodoAgregar;
			}
			else
			{
				nodoAnterior = getNode(this, index - 1);
				if(nodoAnterior != NULL)
				{
					nodoAnterior->pNextNode = nodoAgregar;
				}
			}

			nodoAgregar->pNextNode = nodoPosterior;
			nodoAgregar->pElement = pElement;
			this->size++;
			retorno = 0;
    	}
    }

    return retorno;
}

void* ll_pop(LinkedList* this,int index)
{
    void* retorno = NULL;
    int len;

    len = ll_len(this);

    if(this != NULL && index >= 0 && index <= len)
    {
    	Node* nodoPop;
    	Node* nodoAnterior;

    	nodoPop = getNode(this, index);

    	if(nodoPop != NULL)
    	{
			if(index == 0)
			{
				this->pFirstNode = nodoPop->pNextNode;
			}
			else
			{
				nodoAnterior = getNode(this, index - 1);
				if(nodoAnterior != NULL)
				{
					nodoAnterior->pNextNode = nodoPop->pNextNode;
				}
			}

			this->size--;
			retorno = nodoPop->pElement;
    	}
    }
    return retorno;
}

int ll_contains(LinkedList* this, void* pElement)
{
    int retorno = -1;

   	if(this != NULL)
   	{
   		retorno = 0;

   		if(ll_indexOf(this, pElement) != -1)
   		{
   			retorno = 1;
   		}
   	}

    return retorno;
}

int ll_containsAll(LinkedList* this,LinkedList* this2)
{
    int retorno = -1;

    if(this != NULL && this2 != NULL)
    {
    	int len;

		retorno = 1;
    	len = ll_len(this2);

		for(int i = 0; i < len; i++)
		{
			if(ll_contains(this, ll_get(this2, i)) != 1)
			{
				retorno = 0;
				break;
			}
		}
    }
    return retorno;
}

LinkedList* ll_subList(LinkedList* this,int from,int to)
{
    LinkedList* cloneArray = NULL;
    cloneArray = ll_newLinkedList();
    int len;
    void* pElement;

    len = ll_len(this);

    if(this != NULL && from >= 0 && from < to && to <= len)
    {
    	for(int i = from; i < to; i++)
    	{
    		if(cloneArray != NULL)
    		{
    			pElement = ll_get(this,i);
				ll_add(cloneArray,pElement);
    		}
    	}
    }

    return cloneArray;
}

LinkedList* ll_clone(LinkedList* this)
{
    LinkedList* cloneArray = NULL;

    if(this != NULL)
    {
    	cloneArray = ll_subList(this, 0, ll_len(this));
    }

    return cloneArray;
}

int ll_sort(LinkedList* this, int (*pFunc)(void* ,void*), int order)
{
    int retorno =-1;

    if(this != NULL)
    {
    	if(pFunc != NULL && (order == 0 || order == 1))
    	{
			int len;
			void* primerElemento;
			void* segundoElemento;
			int respuesta;

			len = ll_len(this);

			for(int i = 0; i < len - 1; i++)
			{
				for(int j = i + 1; j < len; j++)
				{
					primerElemento = ll_get(this, i);
					segundoElemento = ll_get(this, j);

					respuesta = pFunc(primerElemento,segundoElemento);

					if(order == 1)
					{
						if(respuesta > 0)
						{
							ll_set(this, i, segundoElemento);
							ll_set(this, j, primerElemento);
						}
					}
					else
					{
						if(respuesta < 0)
						{
							ll_set(this, i, segundoElemento);
							ll_set(this, j, primerElemento);
						}
					}

					retorno = 0;
				}
			}
    	}
    }

    return retorno;

}

LinkedList* ll_map(LinkedList* this, void (*pFunc)(void*))
{
	if(this != NULL)
	{
		if(pFunc != NULL)
		{
			int len;
			len = ll_len(this);

			for(int i = 0; i < len; i++)
			{
				pFunc(ll_get(this, i));
			}
		}
	}
	return this;
}

LinkedList* ll_filter(LinkedList* this, int(*pFunc)(void*))
{
	LinkedList* listaFiltrada = NULL;

	if(this != NULL)
	{
		if(pFunc != NULL)
		{
			int len;
			void* pElement;

			len = ll_len(this);
			listaFiltrada = ll_newLinkedList();

			if(listaFiltrada != NULL)
			{
				for(int i = 0; i < len; i++)
				{
					pElement = ll_get(this, i);

					if(pFunc(pElement) == 1)
					{
						ll_add(listaFiltrada, pElement);
					}
				}
			}
		}
	}

	return listaFiltrada;
}
