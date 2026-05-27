#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int valorCarta(char carta[]) {

    if (carta[0] == 'J' || carta[0] == 'Q' || carta[0] == 'K') {
        return 10;
    }

    if (carta[0] == 'A') {
        return 11;
    }

    return atoi(carta);
}

int main() {

    int totalj = 0;
    int totald = 0;
    int perg;

    const char *baralho[] = {
        "A","2","3","4","5","6","7","8","9","10","J","Q","K",
        "A","2","3","4","5","6","7","8","9","10","J","Q","K",
        "A","2","3","4","5","6","7","8","9","10","J","Q","K",
        "A","2","3","4","5","6","7","8","9","10","J","Q","K"
    };

    int topo = 51;

    srand(time(NULL));

    for (int i = 0; i < 52; i++) {

        int j = rand() % 52;

        const char *temp = baralho[i];
        baralho[i] = baralho[j];
        baralho[j] = temp;
    }

    // loop jogador
    do {

        printf("\n1 - Seguir\n");
        printf("2 - Parar\n");

        scanf("%d", &perg);

        if (perg == 1) {

            const char *carta = baralho[topo--];

            int valor = valorCarta((char*)carta);

            totalj += valor;

            printf("PLAYER: %d\n", totalj);
        }

        else if (perg == 2) {

            printf("PLAYER: %d\n", totalj);
        }

        else {

            printf("Valor invalido\n");
        }

    } while (totalj < 21 && perg != 2);

    // loop dealer
    do {

        const char *carta = baralho[topo--];

        int valor = valorCarta((char*)carta);

        totald += valor;

    } while (totald < totalj && totald <= 21);

    if (totalj > 21) {

        printf("PLAYER perdeu");

    } else if (totald > 21) {

        printf("DEALER: %d\n", totald);
        printf("PLAYER VENCEU!!!");

    } else if (totalj == 21) {

        printf("PLAYER VENCEU!!!");

    } else if (totalj > totald) {

        printf("PLAYER VENCEU!!!");

    } else if (totalj < totald) {

        printf("DEALER: %d\n", totald);
        printf("PLAYER perdeu");

    } else {

        printf("EMPATE!");
    }

    return 0;
}