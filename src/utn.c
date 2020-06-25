#include <stdio.h>
//#include <stdio_ext.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "utn.h"



/** \brief Solicita el ingreso de un string y valida su tamaño
* \param resultado char* Puntero a la variable donde se almacena el string ingresado
* \param mensaje char* Mensaje a mostrar
* \param mensajeError char* Mensaje de error a mostrar
* \param minimo int Tamaño minimo del string
* \param maximo int Tamaño minimo del string Tamaño = elementos+1(\0)
* \param reintentos int* Puntero a la cantidad de reintentos para ingresar el string solicitado
* \return int Return (-1) si Error [tamaño invalido o NULL pointer] - (0) si Ok
*/

int getString(char* msg, char* msgError, int min, int max, int* reintentos, char* resultado)
{
    int retorno=-1;
    char bufferStr[max+10];

    if(msg!=NULL && msgError!=NULL && min<=max && reintentos>=0 && resultado!=NULL)
    {
        do
        {
            printf("%s",msg);
            fgets(bufferStr,sizeof(bufferStr),stdin);
            bufferStr[strlen(bufferStr)-1]='\0';

            if(strlen(bufferStr)>=min && strlen(bufferStr)<max)
            {
                strncpy(resultado,bufferStr,max);
                retorno=0;
                break;
            }
            printf("%s, Reintentos: [%d] \n",msgError,reintentos);
            (reintentos)--;
        }
        while((*reintentos)>=0);
    }
    return retorno;
}


int validarLetra (char letras[])
{
    int ret=0;
    int i=0;
    int CantidadLetras;
    CantidadLetras=strlen(letras);
    while (i<CantidadLetras && ret==0)
    {
        if (isalpha(letras[i])!=0)
        {
            i++;
        }
        else
        {
            ret=1;
        }
    }
    return ret;
}

/** \brief Solicita el ingreso de un int y valida su tamaño
* \param resultado int* Puntero a la variable donde se almacena el int ingresado
* \param mensaje char* Mensaje a mostrar
* \param mensajeError char* Mensaje de error a mostrar
* \param minimo int Tamaño minimo del string
* \param maximo intTamaño minimo del string Tamaño = elementos+1(\0)
* \param reintentos int* Puntero a la cantidad de reintentos para ingresar el string solicitado
* \return int Return (-1) si Error [tamaño invalido o NULL pointer] - (0) si Ok
*/
int getInt(int *resultado, char *mensaje, char *mensajeError, int minimo, int maximo, int reintentos)
{
    int retorno = -1;
    int i;
    int buffer;

    if(mensaje != NULL && mensajeError != NULL && resultado != NULL && maximo >= minimo && reintentos>=0)
    {
        for(i=0; i<=reintentos; i++)
        {
            printf("%s", mensaje);
            scanf("%d",&buffer);
            if(!isValidInt(buffer, maximo, minimo))
            {
                *resultado = buffer;
                retorno = 0;
                break;
            }
            else
            {
                printf("\n %s", mensajeError);
            }
        }
    }
    return retorno;
}

int isValidInt(int numero, int maximo, int minimo)
{
    int ret = -1;
    if(numero<=maximo && numero>=minimo)
    {
        ret = 0;
    }
    return ret;
}

int validarNumero (char numeros[])
{
    int ret=0;
    int i=0;
    int CantidadNumeros;
    CantidadNumeros=strlen(numeros);
    while (i<CantidadNumeros && ret==0)
    {
        if (isdigit(numeros[i])!=0)
        {
            i++;
        }
        else
        {
            ret=1;
        }
    }
    return ret;
}

/** \brief Solicita el ingreso de un float y valida su tamaño
* \param resultado int* Puntero a la variable donde se almacena el int ingresado
* \param mensaje char* Mensaje a mostrar
* \param mensajeError char* Mensaje de error a mostrar
* \param minimo int Tamaño minimo del string
* \param maximo intTamaño minimo del string Tamaño = elementos+1(\0)
* \param reintentos int* Puntero a la cantidad de reintentos para ingresar el string solicitado
* \return int Return (-1) si Error [tamaño invalido o NULL pointer] - (0) si Ok
*/
int getFloat(float *resultado, char *mensaje, char *mensajeError, float minimo, float maximo, int reintentos)
{
    int retorno = -1;
    float buffer;

    if(mensaje!= NULL && mensajeError != NULL && resultado != NULL && minimo<=maximo && reintentos>=0)
    {
        do
        {
            printf("%s", mensaje);
            scanf("%f",&buffer);
            if(isValidFloat(buffer, maximo, minimo))
            {
                *resultado = buffer;
                retorno = 0;
                break;
            }
            else
            {
                printf("%s", mensajeError);
            }
            reintentos--;
        }
        while(reintentos>=0);
    }
    return retorno;
}

int isValidFloat(float numero, float maximo, float minimo)
{
    int ret = -1;
    if(numero<=maximo && numero>=minimo)
    {
        ret = 0;
    }
    return ret;
}

int validarFlotante(char* numeros)
{
    int ret = 1;
    if(numeros != NULL)
    {
        for(int i=0; numeros[i]!='\0'; i++)
        {
            if((numeros[i]<0 && numeros[i]>9) || numeros[i]!= '.')
            {
                ret = 0;
            }
        }
    }
    return ret;
}

/** \brief Solicita el ingreso de un char y valida su tamaño
* \param resultado int* Puntero a la variable donde se almacena el int ingresado
* \param mensaje char* Mensaje a mostrar
* \param mensajeError char* Mensaje de error a mostrar
* \param minimo int Tamaño minimo del string
* \param maximo intTamaño minimo del string Tamaño = elementos+1(\0)
* \param reintentos int* Puntero a la cantidad de reintentos para ingresar el string solicitado
* \return int Return (-1) si Error [tamaño invalido o NULL pointer] - (0) si Ok
*/
int getChar( char *resultado,char *mensaje, char *mensajeError, char minimo, char maximo, int reintentos)
{
    int retorno = -1;
    char buffer;
    if(mensaje != NULL && mensajeError != NULL && resultado != NULL && reintentos>=0)
    {
        do
        {
            printf("%s", mensaje);
            fflush( stdin ); //LIMPIA BUFFER WINDOWS
            //__fpurge(stdin); //LIMPIA BUFFER LINUX
            scanf("%c", &buffer);
            if(isValidChar(buffer, maximo, minimo))
            {
                *resultado = buffer;
                retorno=0;
                break;
            }
            else
            {
                printf("%s", mensajeError);
            }
            reintentos--;
        }
        while(reintentos>=0);
    }
    return retorno;
}

int isValidChar(char letra, char maximo, char minimo)
{
    int ret = 1;
    if(letra<=maximo && letra>=minimo)
    {
        ret = 0;
    }
    return ret;
}

int validNumber(char* numeros)
{
    int ret = 1;
    if(numeros != NULL)
    {
        for(int i=0; numeros[i]!='\0'; i++)
        {
            if(numeros[i]<'0' || numeros[i]>'9')
            {
                ret = 0;
            }
        }
    }
    return ret;
}

int validFecha(char* fecha)
{
    int ret = 1;
    if(fecha != NULL)
    {
        for(int i=0; fecha[i]!='\0'; i++)
        {
            if((fecha[i]<'0' || fecha[i]>'9') && (fecha[i]!= '/'))
            {
                ret = 0;
            }
        }
    }
    return ret;
}

int validCuit(char* cuit)
{
    int ret = 1;
    if(cuit != NULL)
    {
        for(int i=0; cuit[i]!='\0'; i++)
        {
            if((cuit[i]<'0' || cuit[i]>'9') && (cuit[i]!= '-'))
            {
                ret = 0;
            }
        }
    }
    return ret;
}

int validHorario(char* horario)
{
    int ret = 1;
    if(horario != NULL)
    {
        for(int i=0; horario[i]!='\0'; i++)
        {
            if((horario[i]<'0' || horario[i]>'9') && (horario[i]!= ';'))
            {
                ret = 0;
            }
        }
    }
    return ret;
}



int validFloat(char* numeros)
{
    int ret = 1;
    if(numeros != NULL)
    {
        for(int i=0; numeros[i]!='\0'; i++)
        {
            if((numeros[i]<'0' || numeros[i]>'9') && (numeros[i]!= '.'))
            {
                ret = 0;
            }
        }
    }
    return ret;
}


int isValidTexto(char* stringRecibido)
{
    int retorno=1;
    int i;
    for(i=0;stringRecibido[i]!='\0';i++)
    {
        if(stringRecibido[i]<' ' || stringRecibido[i]>'z')
        {
            retorno=0;
            break;
        }
    }
    return retorno;
}



int utn_getTexto(char* msg, char* msgError, int minSize, int maxSize, int reintentos, char* input)
{
    int retorno=-1;
    char bufferStr[maxSize];

    if(msg!=NULL && msgError!=NULL && minSize<maxSize && reintentos>=0 && input!=NULL)
    {
        do
        {
            if(!getString(msg,msgError,minSize,maxSize,&reintentos,bufferStr))
            {
                if(isValidTexto(bufferStr)==1)
                {
                    strncpy(input,bufferStr,maxSize);
                    retorno=0;
                    break;
                }
                else
                {
                    printf("%s\n Reintentos: [%d]\n ",msgError,reintentos);
                    reintentos--;
                }
            }
        }
        while(reintentos>=0);
    }
    return retorno;
}
