//Hilos Independientes: Simulación de Sensores de Monitoreo Ambiental //
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
#include <stdlib.h>

// Función que simula un sensor de temperatura
void* sensor_temperatura(void* arg) {
    while (1) {
        int temp = rand() % 40; // Simula una temperatura aleatoria entre 0 y 40 grados
        printf("Sensor de Temperatura: %d°C\n", temp);
        sleep(2); // Espera 2 segundos antes de la siguiente lectura
    }
    return NULL;
}

// Función que simula un sensor de humedad
void* sensor_humedad(void* arg) {
    while (1) {
        int humedad = rand() % 100; // Simula una humedad aleatoria entre 0 y 100%
        printf("Sensor de Humedad: %d%%\n", humedad);
        sleep(3); // Espera 3 segundos antes de la siguiente lectura
    }
    return NULL;
}

// Función que simula un sensor de presión
void* sensor_presion(void* arg) {
    while (1) {
        int presion = rand() % 200 + 800; // Simula una presión aleatoria entre 800 y 1000 hPa
        printf("Sensor de Presión: %d hPa\n", presion);
        sleep(4); // Espera 4 segundos antes de la siguiente lectura
    }
    return NULL;
}

int main() {
    pthread_t hilo_temperatura, hilo_humedad, hilo_presion;

    // Crear hilos para cada sensor
    pthread_create(&hilo_temperatura, NULL, sensor_temperatura, NULL);
    pthread_create(&hilo_humedad, NULL, sensor_humedad, NULL);
    pthread_create(&hilo_presion, NULL, sensor_presion, NULL);

    // Los hilos se ejecutan de forma independiente, por lo que no es necesario esperar por ellos
    // Si quisiéramos que el programa no termine de inmediato, podemos hacer que el hilo principal espere indefinidamente
    pthread_join(hilo_temperatura, NULL);
    pthread_join(hilo_humedad, NULL);
    pthread_join(hilo_presion, NULL);

    return 0;
}