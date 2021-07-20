#include <stdio.h>

void exibir_local(int bomba1[], int bomba2[], int local1, int local2, int count){
    int i=0, j=1, control=0;

    for (i = 0; i < count; i++){
        printf("Local %d: %d %d\n", j, bomba1[i]+1, bomba2[i]+1);
        j++;
        if((bomba1[i]+1) == local1 && (bomba2[i]+1) == local2){
            control = 1;
        }
    }

    if(control==1){
        printf("Descanse na Força...\n");
    }
    else if(control == 0){
        printf("Ao resgate!\n");
    }
}
int bomba(int linha, int coluna, int M, int N, int mapa[N][M]){

    //DIAGONAL SUPERIOR ESQUERDA
    if(linha -1 > 0 && coluna -1 > 0 && mapa[linha-1][coluna-1] >= mapa[linha][coluna]){
        return 0;
    }
    //ESQUERDA
    else if(coluna -1 > 0 && mapa[linha][coluna-1] >= mapa[linha][coluna]){
        return 0;
    }
    //DIAGONAL INFERIOR ESQUERDA
    else if(linha + 1 < N && coluna -1 > 0 && mapa[linha+1][coluna-1] >= mapa[linha][coluna]){
        return 0;
    }
    //SUL
    else if(linha + 1 < N && mapa[linha+1][coluna] >= mapa[linha][coluna]){
        return 0;
    }
    //DIAGONAL INFERIOR DIREITA
    else if(linha + 1 < N && coluna + 1< M && mapa[linha+1][coluna+1] >= mapa[linha][coluna]){
        return 0;
    }
    //DIREITA
    else if(coluna + 1 < M  && mapa[linha][coluna+1] >= mapa[linha][coluna]){
        return 0;
    }
    //DIAGONAL SUPERIOR DIREITA
    else if(linha -1 > 0 && coluna +1 < M && mapa[linha-1][coluna+1] >= mapa[linha][coluna]){
        return 0;
    }
    //NORTE
    else if(linha -1 > 0 && mapa[linha-1][coluna] >= mapa[linha][coluna]){
        return 0;
    }
    else{
        return 1;
    }
}
void pontos_matriz(int N, int M, int mapa[N][M], int l1, int l2){
    int i=0, j=0, a=0, x_bomb[100], y_bomb[100];
    
    for (i = 0; i < N; i++){
        for (j = 0; j < M; j++){
            if(bomba(i, j, M, N, mapa) == 1){
                x_bomb[a] = i;
                y_bomb[a] = j;
                a++;
            }
        }
        
    }
    exibir_local(x_bomb, y_bomb, l1, l2, a);
}
int main(){
    int N=0, M=0, x=0, y=0, i=0, j=0;

    scanf(" %i %i", &N, &M);

    scanf(" %i %i", &x, &y);

    int matriz[N][M];

    for (i = 0; i < N; i++){
        for (j = 0; j < M; j++){
            scanf(" %i", &matriz[i][j]);
        }
    }
    pontos_matriz(N, M, matriz, x, y);
}