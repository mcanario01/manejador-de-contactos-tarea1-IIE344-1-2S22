/* Universidad de La Frontera
* Ingeniería Civil Electrónica
*
* IIE-344 ESTRUCTURA DE DATOS Y ALGORITMOS
*
* Tarea 1
*
* Autor: Martin Tomás Canario Dauros (m.canario01@ufromail.cl)
* 
* Fecha: 23 de septiembre de 2022
* 
* Descripción general del programa:
* 
* Manejador de contactos es un programa que se dedica a ser una 
* interfaz sencilla para que el usuario pueda manejar una agenda 
* de contactos de forma simple y expedita. El programa no usa 
* argumentos de ejecución, sino más bien toda operación se ejecuta 
* dentro de una instancia del mismo. Tiene todas las funciones 
* básicas como: 
*   - Crear contactos. 
*   - Eliminar contactos. 
*   - Busqueda de contactos por nombre, apellido y grupo. 
*   - Edición de contacto.
*/

#include <stdio.h>
#include "agenda.h"

int main()
{
    bool termino = 1;
    while (termino)
    {
        printf("\n\nMANEJADOR DE AGENDA v1.0\n\n");
        printf("Increse la opción que quiere ejecutar:\n");
        printf("\t1. Crear contacto.\n");
        printf("\t2. Listar agenda.\n");
        printf("\t3. Listar un grupo.\n");
        printf("\t4. Editar un contacto.(no funciona)\n");
        printf("\t5. Buscar por nombre.\n");
        printf("\t6. Buscar por apellido.\n");
        printf("\t7. Eliminar un contacto.(sin terminar)\n");
        printf("\t8. Salir.\n");
        printf(">");
        int opcion;
        scanf("%d", &opcion);
        switch (opcion)
        {
        case 1:
            {
                crearContacto();
            }
            break;
        
        case 2:
            {
                listarAgenda();
            }
            break;
        
        case 3:
            {
                listarGrupo();
            }
            break;
        
        case 4:
            {
                editarContacto();
            }
            break;
        
        case 5:
            {
                buscarNombre();
            }
            break;
        
        case 6:
            {
                buscarApellido();
            }
            break;
        
        case 7:
            {
                eliminarContacto();
            }
            break;
        case 8:
            printf("Adios!\n");
            termino = 0;
            break;
        
        default:
            printf("Opcion invalida!\n");
            break;
        }
    }
    return 0;
}