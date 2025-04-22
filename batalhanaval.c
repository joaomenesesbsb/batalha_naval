#include <stdio.h>

void criarTabuleiro(int tabuleiro[10][10]){
    for(int i = 0; i < 10 ; i++)
    {
        for (int j = 0; j < 10; j++)
        {           
            tabuleiro[i][j] = 0;
        }
    }
}

void mostrarTabuleiro(int tabuleiro[10][10]){
    //mostra os nomeros de cima do tabuleiro
    printf("    0 1 2 3 4 5 6 7 8 9 \n");

    for(int i = 0; i < 10 ; i++)
    {
        //mostra os numeros da lateral do tabuleiro
        ( i != 10) ? printf("%d | ", i) : printf("%d| ", i);
        for (int j = 0; j < 10; j++)
        {           
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }

}

void posicionarBarco( int tamanhoDoBarco, char posicao, int tabuleiro[10][10], int posicaoInicialX, int posicaoInicialY){

    //Variavvel usada para testa se nao ultrapassa a borda
    int bordaX = posicaoInicialX + tamanhoDoBarco;
    int bordaY = posicaoInicialY + tamanhoDoBarco;

    //Testa se a posicao esta em um numero marior q zero
    if(posicaoInicialX >= 0 && posicaoInicialY >= 0){
        printf("[DEBUG] - Posicao inicial maior que 0\n");

        //testa se a posicao e vertical e se a posicao inicial esta dentro do mapa e se a borda do barco esta dentro do mapa
        if(posicao == 'v' && posicaoInicialY < 10 && bordaX <= 10){

            printf("[DEBUG] - Posicao inicial menor que 10 e borda menor q 10\n");
                int sobreposicao = 0;
                //percorre o mapa para ver se a posicao ja esta preenchida
                for (int i = 0; i < tamanhoDoBarco; i++)
                {
                    (tabuleiro[posicaoInicialX + i][posicaoInicialY] != 0) ? sobreposicao = sobreposicao + 1 : sobreposicao;
                }
                //insere o barco no mapa
                for (int i = 0; i < tamanhoDoBarco; i++)
                {
                    if(sobreposicao == 0)
                    {
                    tabuleiro[posicaoInicialX + i][posicaoInicialY] = tamanhoDoBarco;
                    }
                    
                }
                printf("sobeposicao barco: %c - tamanho: %d - JA OCUPADA\n", posicao, tamanhoDoBarco);
        }
    }

    //testa se a posicao e hotizontal e se a posicao inicial esta dentro do mapa e se a borda do barco esta dentro do mapa
        if(posicao == 'h' && posicaoInicialX < 10 && bordaY <= 10){

                int sobreposicao = 0;
                //percorre o mapa para ver se a posicao ja esta preenchida
                for (int i = 0; i < tamanhoDoBarco; i++)
                {
                    (tabuleiro[posicaoInicialX][posicaoInicialY + i] != 0) ? sobreposicao = sobreposicao + 1 : sobreposicao;
                }
                //insere o barco no mapa
                for (int i = 0; i < tamanhoDoBarco; i++)
                {
                    if(sobreposicao == 0)
                    {
                    tabuleiro[posicaoInicialX][posicaoInicialY + i] = tamanhoDoBarco;
                    }
                    
                }
                printf("sobeposicao barco: %c - tamanho: %d - JA OCUPADA\n", posicao, tamanhoDoBarco);
        }
    
    else
    {
        printf("[DEBUG] - Condicao falsa\n");
    }
        
        
}

int main(){

    int tabuleiro[10][10];

    criarTabuleiro(tabuleiro);
    mostrarTabuleiro(tabuleiro);

    printf("\nBarco posicionado na vertical:\n");
    posicionarBarco(3,'v',tabuleiro,5,9);
    mostrarTabuleiro(tabuleiro);

    printf("\nBarco posicionado na horizontal:\n");
    posicionarBarco(3,'h',tabuleiro,5,7);
    mostrarTabuleiro(tabuleiro);
    return 0;
}