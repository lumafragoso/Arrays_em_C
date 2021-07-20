#include <stdio.h>

char esquerda(char direcao){
    if(direcao == 'S'){
        return direcao = 'L';
    }
    else if(direcao == 'O'){
        return direcao = 'S';
    }
    else if(direcao == 'N'){
        return direcao = 'O';
    }
    else if(direcao == 'L'){
        return direcao = 'N';
    }
}

char direita(char direcao){
    if(direcao == 'S'){
        return direcao = 'O';
    }
    else if(direcao == 'O'){
        return direcao = 'N';
    }
    else if(direcao == 'N'){
        return direcao = 'L';
    }
    else if(direcao == 'L'){
        return direcao = 'S';
    }
}

void movimentos(int x, int y, char direcao, int movimentos, int L, int C, char mapa[L][C]){
    int i=0, l_frente=x, c_frente=y;

    for (i = 0; i < movimentos; i++){

        //ATUALIZAÇÃO
        l_frente=x;
        c_frente=y;
        
        if(direcao == 'L'){
            c_frente = y+1;
        }
        else if(direcao == 'O'){
            c_frente = y-1;
        }
        else if(direcao == 'S'){
            l_frente = x+1; 
        }
        else if(direcao == 'N'){
            l_frente = x-1;
        }

        //FORA DA MATRIZ
        if(c_frente >= C){
            direcao= direita(direcao);
        }
        else if(l_frente >= L){
            direcao = direita(direcao);
        }
        else if(l_frente < 0){
            direcao= direita(direcao);
        }
        else if(c_frente < 0){
            direcao = direita(direcao);
        }
        else{
            //CAMINHO LIVRE
            if(mapa[l_frente][c_frente] == '.'){
                x = l_frente;
                y = c_frente;
            }
            //CAMINHO INTERDITADO
            else{
                //ROCHA
                if(mapa[l_frente][c_frente] == '*'){
                    direcao= esquerda(direcao);
                }
                //PAREDE
                else if(mapa[l_frente][c_frente] == '_' || mapa[l_frente][c_frente] == '|'){
                    direcao =direita(direcao);
                }
            }
            }
        }
        printf("Posição final: %d %d", x+1, y+1);
    }

int main(){
    char D;
    int i=0, j=0, L=0, C=0, I=0, J=0, M=0;

    //LER LARGURA E COMPRIMENTO
    scanf(" %d %d", &L, &C);

    char mapa[L][C];

    //CONSTRUIR A MATRIZ
    for (i = 0; i < L; i++){
        for (j = 0; j < C; j++){
            scanf(" %c", &mapa[i][j]);
        }
    }

    //LER COORDENADAS
    scanf(" %d %d %c", &I, &J, &D);

    //LER MOVIMENTOS
    scanf(" %d", &M);

    //CHAMAR FUNÇÃO DOS MOVIMENTOS
    movimentos(I-1, J-1, D, M, L, C, mapa);

}