#include <stdio.h>
#include <locale.h>
#include <stdbool.h>

/*
    G8 - garrafa 8, G5 - garrafa 5, G3 - garrafa 3
    A garrafa G8 já começa cheia

*/
void atualizar(int g3, int g5, int g8, int jogada);
void Deposita(int *g3, int *g5, int *g8,int gRetira);
void Retira(int *g3, int *g5, int *g8, int *jogada);
bool vitoria(int g1, int g2);

int main(){
    setlocale(LC_ALL, "pt_BR.UTF-8"); // Define o locale para Português do Brasil

    int G8 =8, G5=0, G3 =0, jogadas = 0, op =0;

    printf("\nOlá! Digite 1 para iniciar ou 2 para Sair: ");
    scanf("%i",&op);

    while(true){




        if(op!=1 && op!=2){
            printf("\nDigito Errado");
        }else{
            if(op == 2){
                break;
            }else{
                atualizar(G3,G5,G8,jogadas);
                Retira(&G3, &G5,&G8, &jogadas);
                atualizar(G3,G5,G8,jogadas);

                if (vitoria(G8, G5))
                {
                    printf("\nParabéns! Vitória!");
                    printf("\nNúmero de jogadas: %d", jogadas);
                    break;
                }


                printf("\n1 para Continuar ou 2 para Sair: ");
                scanf("%i",&op);
            }
        }
    }

    return 0;
}

bool vitoria(int g1, int g2){
    if(g1 ==4 && g2 == 4){
        return true;
    }else{
        return false;
    }
}




void atualizar(int g3, int g5, int g8, int jogada){
    printf("\nG1 - Garrafa de 8L:%d\n",g8);
    printf("\nG2 - Garrafa de 5L:%d\n",g5);
    printf("\nG3 - Garrafa de 3L:%d\n",g3);
    printf("\nJogadas:%d\n",jogada);

}


void Deposita(int *g3, int *g5, int *g8, int gRetira) {
    int garrafaDeposita = 0;

    while (true) {
        printf("\nQual garrafa vai depositar a água? Escolha entre 1, 2 e 3: ");
        scanf("%d", &garrafaDeposita);

        if (garrafaDeposita == gRetira) {
            printf("\nVocê não pode depositar nessa garrafa!");
        } else {
            switch (garrafaDeposita) {
                case 1:
                    switch (gRetira) {
                        case 2:
                            if (*g8 + *g5 <= 8) {
                                *g8 += *g5;
                                *g5 = 0;
                            } else {
                                *g5 -= (8 - *g8);
                                *g8 = 8;
                            }
                            break;
                        case 3:
                            if (*g8 + *g3 <= 8) {
                                *g8 += *g3;
                                *g3 = 0;
                            } else {
                                *g3 -= (8 - *g8);
                                *g8 = 8;
                            }
                            break;
                    }
                    break;
                case 2:
                    switch (gRetira) {
                        case 1:
                            if (*g5 + *g8 <= 5) {
                                *g5 += *g8;
                                *g8 = 0;
                            } else {
                                *g8 -= (5 - *g5);
                                *g5 = 5;
                            }
                            break;
                        case 3:
                            if (*g5 + *g3 <= 5) {
                                *g5 += *g3;
                                *g3 = 0;
                            } else {
                                *g3 -= (5 - *g5);
                                *g5 = 5;
                            }
                            break;
                    }
                    break;
                case 3:
                    switch (gRetira) {
                        case 1:
                            if (*g3 + *g8 <= 3) {
                                *g3 += *g8;
                                *g8 = 0;
                            } else {
                                *g8 -= (3 - *g3);
                                *g3 = 3;
                            }
                            break;
                        case 2:
                            if (*g3 + *g5 <= 3) {
                                *g3 += *g5;
                                *g5 = 0;
                            } else {
                                *g5 -= (3 - *g3);
                                *g3 = 3;
                            }
                            break;
                    }
                    break;
                default:
                    printf("\nDigito Errado!\n");
                    break;
            }
            break; // Sai do loop while
        }
    }
}


void Retira(int *g3, int *g5, int *g8, int *jogada){
    int garrafaRetira=0;

    while(true){
        printf("\nQual garrafa vai tirar a água? escolha entre 1,2 e 3: ");
        scanf("%i",&garrafaRetira);
        switch (garrafaRetira)
            {
            case 1:
                Deposita(g3, g5,  g8, garrafaRetira);
                (*jogada)++;
                break;
            case 2:
               Deposita(g3, g5,  g8, garrafaRetira);
               (*jogada)++;
                break;
            case 3:
               Deposita(g3, g5,  g8, garrafaRetira);
               (*jogada)++;
                break;

            default:
                printf("\nDigito Errado\n");
                break;
            }
        break;
    };


}
