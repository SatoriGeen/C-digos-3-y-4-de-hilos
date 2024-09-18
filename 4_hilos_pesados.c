//Hilos Pesados: Compresión de Archivos //
//VERSION 1//
//EQUIPO: MIOPÍA//
//INTEGRANTES://
//GONZÁLEZ ESCALANTE KEVIN JEREMY //
//HERNÁNDEZ ALVIRDE MARÍA GUADALUPE//
//DÍAZ CASTAÑAREZ AILTON DAVID//
//PÉREZ OLIVARES JÓSE JULIO//

#include <stdio.h>
#include <pthread.h>
#include <unistd.h>

void* comprimir_archivo(void* archivo) {
    char* nombre_archivo = (char*) archivo;
    printf("Comenzando compresión del archivo: %s\n", nombre_archivo);
    sleep(3); // Simula la compresión con un retardo de 3 segundos
    printf("Archivo %s comprimido\n", nombre_archivo);
    return NULL;
}

int main() {
    pthread_t hilos[3];
    char* archivos[] = {"archivo1.txt", "archivo2.txt", "archivo3.txt"};

    for (int i = 0; i < 3; i++) {
        pthread_create(&hilos[i], NULL, comprimir_archivo, (void*) archivos[i]);
    }

    for (int i = 0; i < 3; i++) {
        pthread_join(hilos[i], NULL);
    }

    printf("Todos los archivos han sido comprimidos.\n");
    return 0;
}