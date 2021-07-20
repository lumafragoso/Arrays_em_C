#include <stdio.h>

void barcos(int x[], int y[]){
    char mapa[10][10];
    int i=0, j=0, l=0, k=0;

    //CONSTRUIR A MATRIZ
    for (i = 0; i < 10; i++){
        for (j = 0; j < 10; j++){
            mapa[i][j] = '~';
        }
    }

    for (i = 0; i < 7; i++){
        //CANOA
        if(i==0){
            mapa[x[i]][y[i]]= '*';  
        }
        //BARCO
        if(i==1){
            if(x[i] == x[i+1]){
                mapa[x[i]][y[i]]= '<';
                mapa[x[i]][y[i+1]]= '>';  
            }
            else if(y[i] == y[i+1]){
                mapa[x[i]][y[i]]= '^';
                mapa[x[i+1]][y[i]]= 'v'; 
            }
        }
        //FRAGATA
        if(i==3){
            if(x[i] == x[i+1]){
                mapa[x[i]][y[i]]= '<';
                mapa[x[i]][y[i+1]]= '=';  
                mapa[x[i]][y[i+2]]= '>';

            }
            else if(y[i] == y[i+1]){
                mapa[x[i]][y[i]]= '^';
                mapa[x[i+1]][y[i]]= '|'; 
                mapa[x[i+2]][y[i]]= 'v';
            }
        }
        //DESTROIER
        if(i==6){
            if(x[i] == x[i+1]){
                mapa[x[i]][y[i]]= '<';
                mapa[x[i]][y[i+1]]= '=';  
                mapa[x[i]][y[i+2]]= '=';
                mapa[x[i]][y[i+3]]= '>';

            }
            else if(y[i] == y[i+1]){
                mapa[x[i]][y[i]]= '^';
                mapa[x[i+1]][y[i]]= '|'; 
                mapa[x[i+2]][y[i]]= '|';
                mapa[x[i+3]][y[i]]= 'v';
            }
        }
    }

    //PRINTAR O MAPA
    for (k = 0; k < 10; k++){
        for (l = 0; l < 10; l++){
            printf("%c", mapa[k][l]);
        }
        printf("\n");
    }

}


int main(){
    int i, j, k, l, h; 
    int coluna[10]={0}, linha[10]={0};

    //LER VALORES DAS COLUNAS E LINHAS
    for (h = 0; h < 10; h++){
        scanf(" %d %d", &linha[h], &coluna[h]);
    }
     
    barcos(linha, coluna);
    return 0;
}