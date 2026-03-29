#include <stdio.h>


#define N 3


//tablero

void imprimirTablero(char tablero[N][N])

{

    for (int i = 0; i < N; i++) {

        for (int j = 0; j < N; j++) {

            printf("| %c |", tablero[i][j]);

        }

        printf("\n");

    }

}


//ganador 

char verificarGanador(char tablero[N][N])

{

    //verificaacion horizontal

    for (int i = 0; i < N; i++)

    {

        if (tablero[i][0] == tablero[i][1] && tablero[i][1] == tablero[i][2] && tablero[i][0] != ' ')

        {

            return tablero[i][0];

        }

        if (tablero[0][i] == tablero[1][i] && tablero[1][i] == tablero[2][i] && tablero[0][i] != ' ')

        {

            return tablero[0][i];

        }

    }


    //Verificacion en diagonal 

    if (tablero[0][0] == tablero[1][1] && tablero[1][1] == tablero[2][2] && tablero[0][0] != ' ')

    {

        return tablero[0][0];

    }

    if (tablero[0][2] == tablero[1][1] && tablero[1][1] == tablero[2][0] && tablero[0][2] != ' ')

    {

        return tablero[0][2];

    }

    

    //Verificacion de empate 

    for(int i=0;i<N;i++)

    {

        for(int j=0;j<N;j++)

        {

            if(tablero[i][j]==' ')

            {

                return ' '; 

            }

        }

    }

   

    return 'e';

}


//Movimientos 

void realizarMovimiento(char tablero[N][N], int fila, int columna, char jugador)

{

    if (tablero[fila][columna] == ' ')

    {

        tablero[fila][columna] = jugador;

    } else {

        printf("Casilla ocupada. Intenta de nuevo.\n");

    }

}


int main()

{


    int fila, columna;

    char jugador = 'X', ganador;

    char tablero[N][N] =

    {

        {' ', ' ', ' '},

        {' ', ' ', ' '},

        {' ', ' ', ' '}

    };

    

    printf("¡Hola, Vamos a jugar gato!\n");

    

    //ciclo 

    do

    {

       

        imprimirTablero(tablero);


       

        printf("Jugador %c, ingrese fila y columna (ejemplo: 1, enter, 2): ", jugador);

        scanf("%d %d", &fila, &columna);


        //Condicion para los movimientos 

        if (fila >= 1 && fila <= N && columna >= 1 && columna <= N)

        {

            fila--;

            columna--;


           

            realizarMovimiento(tablero, fila, columna, jugador);


           

            ganador = verificarGanador(tablero);

            if (ganador != ' '&& ganador!= 'e')

            {

                imprimirTablero(tablero);

                printf("¡Jugador %c es el ganador!\n", ganador);

                break;

            }

           

            jugador = (jugador == 'X') ? 'O' : 'X';


        } else {

            printf("Movimiento no válido. Por favor, ingrese fila y columna entre 1 y %d.\n", N);

        }

        

    } while (verificarGanador(tablero) == ' ' && jugador == 'X' || jugador == 'O');


   

    if (verificarGanador(tablero) == 'e')

    {

        imprimirTablero(tablero);

        printf("¡Es un empate!\n");

    }

}

