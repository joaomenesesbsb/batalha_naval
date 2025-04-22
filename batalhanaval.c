#include <stdio.h>

void criarTabuleiro(int eixoX, int eixoY){
    int posicao[eixoX][eixoY];

    printf("1 2 3 4 5 6 7 8 9 10 \n");

    for(int i = 0; i < eixoX ; i++)
    {
        for (int j = 0; j < eixoY; j++)
        {           
            posicao[eixoX][eixoY] = 0;
            printf("%d ", posicao[eixoX][eixoY]);
        }
        printf(" %d\n", 10 - i);
    }
}
int main(){
    criarTabuleiro(10,10);

    return 0;
}