#include "agenda.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

void crearContacto()
{
    //creación de un contacto auxiliar de forma dinamica
    contacto * aux = new contacto;
    //petición de datos de nuevo contacto al usuario
    printf("Nombre: \n");
    scanf("%s", aux->nombre);
    printf("Apellido: \n");
    scanf("%s", aux->apellido);
    printf("Número telefónico: \n");
    scanf("%d", &aux->numero_telefono);
    printf("Email: \n");
    scanf("%s", aux->email);
    printf("Grupo: \n");
    scanf("%s", aux->grupo);
    //apertura de archivo
    FILE * indice = fopen("../dat/indice.txt", "a+");
    FILE * agenda = fopen("../dat/contactos.txt", "a+");
    //escritura de archivo según los datos pedidos
    fprintf(agenda, "\n");
    fprintf(agenda, "%s", aux->nombre);
    fprintf(agenda, " ");
    fprintf(agenda, "%s", aux->apellido);
    fprintf(agenda, " ");
    fprintf(agenda, "%d", aux->numero_telefono);
    fprintf(agenda, " ");
    fprintf(agenda, "%s", aux->email);
    fprintf(agenda, " ");
    fprintf(agenda, "%s", aux->grupo);
    //cierre de archivo y eliminación de objeto
    delete aux;
    fclose(agenda);
    fclose(indice);
}

//lista la agenda completa en "contactos.txt"
void listarAgenda()
{
    //apertura de archivo
    FILE * agenda = fopen("../dat/contactos.txt", "a+");
    //interfaz
    imprimirNombresColumnas();
    //bucle que itera hasta el fin de archivo
    while (!feof(agenda))
    {
        //creación de contacto de forma dinamica
        contacto * aux = new contacto;
        //escaneo de datos
        fscanf(agenda, "%s", aux->nombre);
        fscanf(agenda, "%s", aux->apellido);
        fscanf(agenda, "%d", &aux->numero_telefono);
        fscanf(agenda, "%s", aux->email);
        fscanf(agenda, "%s", aux->grupo);
        //muestra de datos por pantalla
        printf("\t%s\t%s\t%d\t%s\t%s\n", (aux->nombre), (aux->apellido), (aux->numero_telefono), (aux->email), (aux->grupo));
        //cierre de archivo y eliminación de objeto
        delete aux;
    }
    fclose(agenda);
}

//pregunta por un grupo al usuario e imprime por pantalla todos los contactos que lo contengan
void listarGrupo()
{
    printf("Ingrese el nombre del grupo: ");
    char grupo_aux[30];
    scanf("%s", grupo_aux);
    //apertura de archivo
    FILE * agenda = fopen("../dat/contactos.txt", "a+");

    imprimirNombresColumnas();
    //bucle que itera hasta el fin de archivo
    while (!feof(agenda))
    {
        //creación de contacto de forma dinamica
        contacto * aux = new contacto;
        //escaneo de datos
        fscanf(agenda, "%s", aux->nombre);
        fscanf(agenda, "%s", aux->apellido);
        fscanf(agenda, "%d", &aux->numero_telefono);
        fscanf(agenda, "%s", aux->email);
        fscanf(agenda, "%s", aux->grupo);
        //comparación: grupo ingresado con usuarios con grupos guardados
        if (!strcmp(grupo_aux, aux->grupo))
        {
            printf("\t%s %s %d %s %s\n", (aux->nombre), (aux->apellido), (aux->numero_telefono), (aux->email), (aux->grupo));
        }
        //eliminación de memoria dinamica
        delete aux;
    }
    //cierre de archivo
    fclose(agenda);
}


void editarContacto()
{   
    //impresion de agenda
    printf("\nAGENDA\n");
    imprimirNombresColumnas();
    listarAgenda();
    //interfaz
    printf("\n\nEscriba el nombre del contacto que desea editar: ");
    char nombre_completo_aux[60];
    scanf("%s", nombre_completo_aux);
    printf("\n");
    printf("\nElija el campo que desea editar:\n");
    printf("\t1. Nombre.\n");
    printf("\t2. Apellido.\n");
    printf("\t3. Número telefónico.\n");
    printf("\t4. Email.\n");
    printf("\t5. Grupo.\n");
    printf("\n");
    int seleccion;
    scanf("%d", &seleccion);
    //apertura de archivo
    FILE * agenda = fopen("../dat/contactos.txt", "a+");
    //bucle que itera hasta el fin de archivo
    switch (seleccion)
    {
    //editar nombre
    case 1:
        {
            printf("Ingrese el nuevo nombre para el contacto: ");
            char nombre_aux[30];
            scanf("%s", nombre_aux);
            printf("\n");
            //apertura de archivo
            FILE * agenda = fopen("../dat/contactos.txt", "a+");
            //bucle que itera hasta el fin de archivo
            while (!feof(agenda))
            {
                //creación de contacto de forma dinamica
                contacto * aux = new contacto;
                //escaneo de datos
                fscanf(agenda, "%s", aux->nombre);
                fscanf(agenda, "%s", aux->apellido);
                fscanf(agenda, "%d", &aux->numero_telefono);
                fscanf(agenda, "%s", aux->email);
                fscanf(agenda, "%s", aux->grupo);
                //comparación: grupo ingresado con usuarios con grupos guardados
                if (!strcmp(nombre_aux, aux->grupo))
                {
                    printf("%s %s %d %s %s\n", (aux->nombre), (aux->apellido), (aux->numero_telefono), (aux->email), (aux->grupo));
                }
                //eliminación de memoria dinamica
                delete aux;
            }
            //cierre de archivo
            fclose(agenda);
        }
        break;
    
    default:
        printf("Selección invalida");
        break;
    }
    
    /*
    while (!feof(agenda))
    {
        //creación de contacto de forma dinamica
        contacto * aux = new contacto;
        //escaneo de datos
        fscanf(agenda, "%s", aux->nombre);
        fscanf(agenda, "%s", aux->apellido);
        fscanf(agenda, "%d", &aux->numero_telefono);
        fscanf(agenda, "%s", aux->email);
        fscanf(agenda, "%s", aux->grupo);
        //muestra de datos por pantalla
        printf("%s %s %d %s %s\n", (aux->nombre), (aux->apellido), (aux->numero_telefono), (aux->email), (aux->grupo));
        // eliminación de objeto
        delete aux;
    }
    delete seleccion;
    //cierre de archivo 
    fclose(agenda);
    */
}

void buscarNombre()
{
    printf("Ingrese un nombre para buscar: ");
    char nombre_aux[30];
    scanf("%s", nombre_aux);
    //apertura de archivo
    FILE * agenda = fopen("../dat/contactos.txt", "a+");
    //bucle que itera hasta el fin de archivo
    while (!feof(agenda))
    {
        //creación de contacto de forma dinamica
        contacto * aux = new contacto;
        //escaneo de datos
        fscanf(agenda, "%s", aux->nombre);
        fscanf(agenda, "%s", aux->apellido);
        fscanf(agenda, "%d", &aux->numero_telefono);
        fscanf(agenda, "%s", aux->email);
        fscanf(agenda, "%s", aux->grupo);
        //comparación: grupo ingresado con usuarios con grupos guardados
        if (!strcmp(nombre_aux, aux->nombre))
        {
            printf("%s %s %d %s %s\n", (aux->nombre), (aux->apellido), (aux->numero_telefono), (aux->email), (aux->grupo));
        }
        //eliminación de memoria dinamica
        delete aux, nombre_aux;
    }
    //cierre de archivo
    fclose(agenda);
}

void buscarApellido()
{
    printf("Ingrese el nombre del grupo: ");
    char apellido_aux[30];
    scanf("%s", apellido_aux);
    //apertura de archivo
    FILE * agenda = fopen("../dat/contactos.txt", "a+");
    //bucle que itera hasta el fin de archivo
    while (!feof(agenda))
    {
        //creación de contacto de forma dinamica
        contacto * aux = new contacto;
        //escaneo de datos
        fscanf(agenda, "%s", aux->nombre);
        fscanf(agenda, "%s", aux->apellido);
        fscanf(agenda, "%d", &aux->numero_telefono);
        fscanf(agenda, "%s", aux->email);
        fscanf(agenda, "%s", aux->grupo);
        //comparación: grupo ingresado con usuarios con grupos guardados
        if (!strcmp(apellido_aux, aux->apellido))
        {
            printf("%s %s %d %s %s\n", (aux->nombre), (aux->apellido), (aux->numero_telefono), (aux->email), (aux->grupo));
        }
        //eliminación de memoria dinamica
        delete aux;
    }
    //cierre de archivo
    fclose(agenda);
}


void eliminarContacto()
{

}



void imprimirNombresColumnas()
{
    printf("\tNombre\tApellido\tNúmero telefonico\tEmail\tGrupo\n");
    printf("\t----------------------------------------------------------------\n");
}




/*
void escanearContacto(FILE * agenda, contacto * aux)
{
        fscanf(agenda, "%s", aux->nombre);
        fscanf(agenda, "%s", aux->apellido);
        fscanf(agenda, "%d", &aux->numero_telefono);
        fscanf(agenda, "%s", aux->email);
        fscanf(agenda, "%s", aux->grupo);
}
*/




/*
void buscar(FILE * agenda, char busqueda[30])
{
    printf("Ingrese un nombre para buscar: ");
    scanf("%s", busqueda);
    //bucle que itera hasta el fin de archivo
    while (!feof(agenda))
    {
        //creación de contacto de forma dinamica
        contacto * aux = new contacto;
        //escaneo de datos
        fscanf(agenda, "%s", aux->nombre);
        fscanf(agenda, "%s", aux->apellido);
        fscanf(agenda, "%d", &aux->numero_telefono);
        fscanf(agenda, "%s", aux->email);
        fscanf(agenda, "%s", aux->grupo);
        //comparación: grupo ingresado con usuarios con grupos guardados
        if (!strcmp(busqueda, aux->nombre) || !strcmp(busqueda, aux->apellido) || !strcmp(busqueda, aux->email) || !strcmp(busqueda, aux->grupo))
        {
            printf("%s %s %d %s %s\n", (aux->nombre), (aux->apellido), (aux->numero_telefono), (aux->email), (aux->grupo));
        }
        //eliminación de memoria dinamica
        delete aux, busqueda;
    }
    //cierre de archivo
    fclose(agenda);
}

void buscar(FILE * agenda, int busqueda)
{
    printf("Ingrese un nombre para buscar: ");
    scanf("%s", busqueda);
    //bucle que itera hasta el fin de archivo
    while (!feof(agenda))
    {
        //creación de contacto de forma dinamica
        contacto * aux = new contacto;
        //escaneo de datos
        fscanf(agenda, "%s", aux->nombre);
        fscanf(agenda, "%s", aux->apellido);
        fscanf(agenda, "%d", &aux->numero_telefono);
        fscanf(agenda, "%s", aux->email);
        fscanf(agenda, "%s", aux->grupo);
        //comparación: grupo ingresado con usuarios con grupos guardados
        if (busqueda == aux->numero_telefono)
        {
            printf("%s %s %d %s %s\n", (aux->nombre), (aux->apellido), (aux->numero_telefono), (aux->email), (aux->grupo));
        }
        //eliminación de memoria dinamica
        delete aux, busqueda;
    }
    //cierre de archivo
    fclose(agenda);
}
*/