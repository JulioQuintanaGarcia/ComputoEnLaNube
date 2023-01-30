#include <iostream>
#include <omp.h>
#include <time.h>
/* En esta seccion se define la canitdad de elemntos en los arregos por la variable N, Chunk define le tamaño de los pedazos de los arreglos para dividir cada hilo por la canitdad de elementos
la variable mostrar permite la canitdad de datos a imprimir, finalemnte ImprimieArreglo es la funcion para imprimir los arreglos */
#define N 1000 
#define chunk 100 
#define mostrar 10 

void imprimeArreglo(float* d); 
/* En la sigueinte seccion se declaran tres arreglos donde se almacenaran los valores de arreglo a, b y el resultado despues de la suma de los dos primeros arreglos, cada arreglo consta de 10 elementos
 en la linea 15 se genera una funcion para diferenciar la ejecucion de cada elemento en el arreglo.
 En el ciclo for se generaran los valores aleatorios para cada arreglo, para el arreglo b se generan arreglos multiplicados por 3.5 para diferenciar el arreglo a.*/
int main()
{
    srand(time(NULL)); 
    std::cout << "Sumando Arreglos en Paralelo!\n";
    float a[N], b[N], r[N]; 
    int i;

    for (i = 0; i < N; i++) 
    {
        int random = rand() % 10; 
        a[i] = i * random; 
        b[i] = (i + random) * 3.5; 
    }
    /*Se dedlcara la variable pedazos y se asigna la constante chunk para el tamaño de hilo*/
    int pedazos = chunk; 

    //En esta parte se ejecutan las operaciones de manera paralela dentro del ciflo for a traves de open mp
#pragma omp parallel for \
    shared(a, b, c, pedazos) private(i) \
    schedule(static,pedazos)

    for (i = 0; i < N; i++)
        r[i] = a[i] + b[i];

 /*en estas siguientes fucniones se realiza la impresion de los arreglos y su resultante, con la funcion void de la linea 47 */
    std::cout << "Imprimiendo los primeros " << mostrar << " valores del arreglo a: " << std::endl; 
    imprimeArreglo(a);
    std::cout << "Imprimiendo los primeros " << mostrar << " valores del arreglo b: " << std::endl; 
    imprimeArreglo(b);
    std::cout << "Imprimiendo los primeros " << mostrar << " valores del arreglo r: " << std::endl; 
    imprimeArreglo(r);
}

void imprimeArreglo(float* d) 
{
    for (int x = 0; x < mostrar; x++)
        std::cout << d[x] << " - ";
    std::cout << std::endl;
}