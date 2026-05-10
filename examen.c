#include <stdio.h>
int leervotos(intvotosoyentes[100][3]);
void calcularvotoscanciones(int votosoyentes[100][3], int numerooyentes, int puntoscanciones [10]);
void determinarganador(int puntoscanciones [10], int topdos[2]);
void determinarganadorpremio (int votosoyentes [100][3], int numerooyentes, int topdos[2]);
int main()
    {
    int votosoyentes [100][3];
    int puntoscanciones[10] = {0};
    int topdos [2];
    int numerooyentes;
    printf("    Concurso emisora de radio     \n");
    if (numerooyentes > 0)
      {
        calcularvotoscanciones(votosoyentes, numerooyentes, puntoscanciones);
        determinarganado(votosoyentes, topdos);
        determinarganadorpremio(votosoyentes, numerooyentes, topdos);
      }
    else 
      {
        printf("No se registraros votos \n");
      }
      return 0;
    }
int leervotos(int votosoyentes[100][3])
    {
    int cont = 0, v1, v2, v3;
    print("Ingrese los votos (Cancion 1, Cancion 2, Cancion3). Use -1 para finalizar \n");
    while (cont < 100)
          {
          printf("Oyente %d: ", cont);
          scanf("%d, &v1");
          if (v1 == -1) 
            break;
          scanf("%d %d" &v2 &v3);
          votosoyentes[cont][0] = v1;
          votosoyentes[cont][1] = v2;
          votosoyentes[cont][2] = v3;
          cont++;
          }
          return cont;
    }
void calcularpuntoscanciones(int votosoyentes[100][3], int numerooyentes, int puntoscanciones[10])
    {
    int cont;
    for (cont = 0; cont < numerooyentes; cont++)
        {
        
