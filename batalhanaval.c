#include <stdio.h>

//TABULEIRO
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

//POSICIONAR BARCOS
void posicionarBarco( int tamanhoDoBarco, char posicao, int tabuleiro[10][10], int posicaoInicialX, int posicaoInicialY){

    //Variavvel usada para testa se nao ultrapassa a borda
    int bordaX = posicaoInicialX + tamanhoDoBarco;
    int bordaY = posicaoInicialY + tamanhoDoBarco;

    //Testa se a posicao esta em um numero marior q zero
    if(posicaoInicialX >= 0 && posicaoInicialY >= 0){
        //printf("[DEBUG] - Posicao inicial maior que 0\n");

        //testa se a posicao e vertical e se a posicao inicial esta dentro do mapa e se a borda do barco esta dentro do mapa
        if(posicao == 'v' && posicaoInicialY < 10 && bordaX <= 10){

            //printf("[DEBUG] - Posicao inicial menor que 10 e borda menor q 10\n");
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
                    else 
                    {
                        printf("sobeposicao barco: %c - tamanho: %d - JA OCUPADA\n", posicao, tamanhoDoBarco);
                    }
                    
                }
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
                    else 
                    {
                        printf("sobeposicao barco: %c - tamanho: %d - JA OCUPADA\n", posicao, tamanhoDoBarco);
                    }
                }
        }
    
    else
    {
        //printf("[DEBUG] - Condicao falsa\n");
    }

    //testa se a posicao e diagonal \ descendo e se a posicao inicial esta dentro do mapa e se a borda do barco esta dentro do mapa
    if(posicao == 'd' && posicaoInicialX < 10 && posicaoInicialY < 10 && bordaY <= 10 && bordaX  <=10){

        int sobreposicao = 0;
        //percorre o mapa para ver se a posicao ja esta preenchida
        for (int i = 0; i < tamanhoDoBarco; i++)
        {
            (tabuleiro[posicaoInicialX + i][posicaoInicialY + i] != 0) ? sobreposicao = sobreposicao + 1 : sobreposicao;
        }
        //insere o barco no mapa
        for (int i = 0; i < tamanhoDoBarco; i++)
        {
            if(sobreposicao == 0)
            {
            tabuleiro[posicaoInicialX + i][posicaoInicialY + i] = tamanhoDoBarco;
            }
            else 
            {
                printf("sobeposicao barco: %c - tamanho: %d - JA OCUPADA\n", posicao, tamanhoDoBarco);
            }
        }
        
    }
    else
    {
    //printf("[DEBUG] - Condicao falsa\n");
    }

    //testa se a posicao e diagonal / subindo e se a posicao inicial esta dentro do mapa e se a borda do barco esta dentro do mapa
    if(posicao == 's' && posicaoInicialX < 10 && posicaoInicialY < 10 && bordaY <= 10 && bordaX  <=10){

        int sobreposicao = 0;
        //percorre o mapa para ver se a posicao ja esta preenchida
        for (int i = 0; i < tamanhoDoBarco; i++)
        {
            (tabuleiro[posicaoInicialX - i][posicaoInicialY + i] != 0) ? sobreposicao = sobreposicao + 1 : sobreposicao;
        }
        //insere o barco no mapa
        for (int i = 0; i < tamanhoDoBarco; i++)
        {
            if(sobreposicao == 0)
            {
            tabuleiro[posicaoInicialX - i][posicaoInicialY + i] = tamanhoDoBarco;
            }
            else 
            {
                printf("sobeposicao barco: %c - tamanho: %d - JA OCUPADA\n", posicao, tamanhoDoBarco);
            }
        }
        
    }
    else
    {
    //printf("[DEBUG] - Condicao falsa\n");
    }
        
        
}

//HABILIDADES
void habilidadeCone(int posicaoX, int posicaoY, int tabuleiro[10][10]){

    //testa se esta dentro do mapa
    if(posicaoX >= 1 && posicaoX < 9 && posicaoY >= 2 && posicaoY < 8)
    {
        //topo
        tabuleiro[posicaoX - 1][posicaoY] = (tabuleiro[posicaoX - 1][posicaoY] == 3) ? 1 : 5;
        

        //meio
        tabuleiro[posicaoX][posicaoY - 1] = ( tabuleiro[posicaoX][posicaoY - 1] == 3) ? 1 : 5;
        tabuleiro[posicaoX][posicaoY] = ( tabuleiro[posicaoX][posicaoY] == 3) ? 1 : 5;
        tabuleiro[posicaoX][posicaoY + 1] = ( tabuleiro[posicaoX][posicaoY + 1] == 3) ? 1 : 5;

        //base
        tabuleiro[posicaoX + 1][posicaoY - 2] = ( tabuleiro[posicaoX + 1][posicaoY - 2] == 3) ? 1 : 5;
        tabuleiro[posicaoX + 1][posicaoY - 1] = ( tabuleiro[posicaoX + 1][posicaoY - 1] == 3) ? 1 : 5;
        tabuleiro[posicaoX + 1][posicaoY ] = ( tabuleiro[posicaoX + 1][posicaoY] == 3) ? 1 : 5;
        tabuleiro[posicaoX + 1][posicaoY + 1] = ( tabuleiro[posicaoX + 1][posicaoY + 1] == 3) ? 1 : 5;
        tabuleiro[posicaoX + 1][posicaoY + 2] = ( tabuleiro[posicaoX + 1][posicaoY + 2] == 3) ? 1 : 5;
    }
    else 
    {
        printf("Posicao invalida\n");
    }

}
void habilidadeCruz(int posicaoX, int posicaoY, int tabuleiro[10][10]){

    //testa se esta dentro do mapa
    if(posicaoX >= 1 && posicaoX < 9 && posicaoY >= 1 && posicaoY < 9)
    {
        //topo
        tabuleiro[posicaoX - 1][posicaoY] = (tabuleiro[posicaoX - 1][posicaoY] == 3) ? 1 : 5;
        

        //meio
        tabuleiro[posicaoX][posicaoY - 2] = ( tabuleiro[posicaoX][posicaoY - 2] == 3) ? 1 : 5;
        tabuleiro[posicaoX][posicaoY - 1] = ( tabuleiro[posicaoX][posicaoY - 1] == 3) ? 1 : 5;
        tabuleiro[posicaoX][posicaoY ] = ( tabuleiro[posicaoX][posicaoY] == 3) ? 1 : 5;
        tabuleiro[posicaoX][posicaoY + 1] = ( tabuleiro[posicaoX][posicaoY + 1] == 3) ? 1 : 5;
        tabuleiro[posicaoX][posicaoY + 2] = ( tabuleiro[posicaoX][posicaoY + 2] == 3) ? 1 : 5;

        //base
        tabuleiro[posicaoX + 1][posicaoY] = ( tabuleiro[posicaoX + 1][posicaoY] == 3) ? 1 : 5;
        
    }
    else 
    {
        printf("Posicao invalida\n");
    }

}

void habilidadeOctaedro(int posicaoX, int posicaoY, int tabuleiro[10][10]){

    //testa se esta dentro do mapa
    if(posicaoX >= 1 && posicaoX < 9 && posicaoY >= 2 && posicaoY < 10)
    {
        //topo
        tabuleiro[posicaoX - 1][posicaoY] = (tabuleiro[posicaoX - 1][posicaoY] == 3) ? 1 : 5;
        

        //meio
        tabuleiro[posicaoX][posicaoY - 1] = ( tabuleiro[posicaoX][posicaoY - 1] == 3) ? 1 : 5;
        tabuleiro[posicaoX][posicaoY ] = ( tabuleiro[posicaoX][posicaoY] == 3) ? 1 : 5;
        tabuleiro[posicaoX][posicaoY + 1] = ( tabuleiro[posicaoX][posicaoY + 1] == 3) ? 1 : 5;

        //base
        tabuleiro[posicaoX + 1][posicaoY] = ( tabuleiro[posicaoX + 1][posicaoY] == 3) ? 1 : 5;     
    }
    else 
    {
        printf("Posicao invalida\n");
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
    posicionarBarco(3,'h',tabuleiro,4,7);
    mostrarTabuleiro(tabuleiro);

    printf("\nBarco posicionado na diagonal descendo:\n");
    posicionarBarco(3,'d',tabuleiro,3,3);
    mostrarTabuleiro(tabuleiro);

    printf("\nBarco posicionado na diagonal subindo:\n");
    posicionarBarco(3,'s',tabuleiro,2,5);
    mostrarTabuleiro(tabuleiro);
    
    printf("\nHabilidade Cone:\n");
    habilidadeCone(8,7,tabuleiro);
    mostrarTabuleiro(tabuleiro);

    printf("\nHabilidade Cruz:\n");
    habilidadeCruz(7,1,tabuleiro);
    mostrarTabuleiro(tabuleiro);
    
    printf("\nHabilidade Octaedro:\n");
    habilidadeOctaedro(2,8,tabuleiro);
    mostrarTabuleiro(tabuleiro);

    return 0;
}