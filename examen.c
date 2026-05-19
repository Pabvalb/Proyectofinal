#include <stdio.h>
int leervotos(int votosoyentes[100][3]);
void calcularvotoscanciones(int votosoyentes[100][3], int numerooyentes, int puntoscanciones [10]);
void determinarganadores(int puntoscanciones [10], int topdos[2]);
void determinarganadorpremio(int votosoyentes [100][3], int numerooyentes, int topdos[2]);
int main()
    {
    int votosoyentes [100][3];
    int puntoscanciones[10] = {0};
    int topdos [2];
    int numerooyentes;
    printf("    Concurso emisora de radio     \n");
    numerooyentes = leervotos(votosoyentes);
    if (numerooyentes > 0)
      {
        calcularvotoscanciones(votosoyentes, numerooyentes, puntoscanciones);
        determinarganadores(puntoscanciones, topdos);
        determinarganadorpremio(votosoyentes, numerooyentes, topdos);
      }
    else 
      {
        printf("No se registraron votos \n");
      }
      return 0;
    }
int leervotos(int votosoyentes[100][3])
    {
    int cont = 0, v1, v2, v3;
    printf("Ingrese los votos (Cancion 1, Cancion 2, Cancion 3). Use -1 para finalizar \n");
    while (cont < 100)
          {
            printf("Oyente %d: ", cont);
            if (scanf("%d", &v1) != 1 || v1 == -1)
                break;
          scanf("%d %d", &v2, &v3);
          votosoyentes[cont][0] = v1;
          votosoyentes[cont][1] = v2;
          votosoyentes[cont][2] = v3;
          cont++;
          }
          return cont;
    }
void calcularvotoscanciones(int votosoyentes[100][3], int numerooyentes, int puntoscanciones[10])
    {
    int cont;
    for (cont = 0; cont < numerooyentes; cont++)
        {
        puntoscanciones[votosoyentes[cont][0]] += 3;
        puntoscanciones[votosoyentes[cont][1]] += 2;
        puntoscanciones[votosoyentes[cont][2]] += 1;
        }
    }
void determinarganadores(int puntoscanciones[10], int topdos[2])
    {
    int cont;
    int max1 = -1, max2 = -1;
    int c1 = 0, c2 = 0;
    for (cont = 0; cont < 10; cont++)
        {
        printf("Cancion %d: %d puntos\n", cont, puntoscanciones[cont]);
        if (puntoscanciones[cont] > max1)
            {
            max2 = max1; c2 = c1;
            max1 = puntoscanciones[cont]; c1 = cont;
            }
        else if (puntoscanciones[cont] > max2)
            {
            max2 = puntoscanciones[cont]; c2 = cont;
            }
        }
        topdos[0] = c1;
        topdos[1] = c2;
        printf("1a cancion: %d\n2a canción: %d\n", c1, c2);
    }
void determinarganadorpremio (int votosoyentes [100][3], int numerooyentes, int topdos[2])
    {
    int cont, j;
    int maxpuntosoyente = -1, ganadorId = 0;
    for (cont = 0; cont < numerooyentes; cont++)
        {
        int acertotop1 = 0, acertotop2 = 0;
        int puntosesteoyente = 0;
        for (j = 0; j < 3; j++)
            {
            if (votosoyentes[cont][j] == topdos[0])
                {
                acertotop1 = 1;
                }
            if (votosoyentes[cont][j] == topdos[1])
                {
                acertotop2 = 1;
                }
            }
            if (acertotop1 == 1) puntosesteoyente += 30;
            if (acertotop1 == 1) puntosesteoyente += 20;
            if (acertotop1 && acertotop2) puntosesteoyente += 10;
            printf("Oyente %d: %d puntos\n", cont, puntosesteoyente);
            if (puntosesteoyente > maxpuntosoyente)
                {
                maxpuntosoyente = puntosesteoyente;
                ganadorId = cont;
                }
        }
        printf("Ganador: el oyente numero %d\n", ganadorId);
    }
