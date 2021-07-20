#include <stdio.h>

void createHistogram(int c, int h[c]) {
    int n, k, l, a=0, p, i;
    double final, inicio=0, notas[100], para=0;

    scanf("%i", &n);

    //COLOCAR AS NOTAS NO VETOR NOTAS
    for (i = 0; i < n; i++){
        scanf(" %lf", &notas[i]);
    }
    //COLOCAR ZEROS EM TODOS OS ÍNDICES DO VETOR
    for (p = 0; p < c; p++){
        h[p] = 0;
    }
    //VALOR INICIAL PARA A VARIÁVEL DE CONTROLE DO FINAL DO INTERVALO
    final = 10/ c;

    //LOOP EXTERNO CONTROLA AS NOTAS DO VETOR NOTAS
    for (a = 0; a < n; a++){
        //LOOP QUE CONTROLA O INDICE DOS INTERVALOS DO VETOR HISTOGRAMA
        for (k = 0; k < c; k++){
            //FINAL DO INTERVALO ABERTO, ATÉ O PENÚLTIMO LOOP
            if(k+1 != c && para ==0){
                if(inicio <= notas[a] && notas[a] < final){
                    //AUMENTA O O VALOR NO ÍNDICE DO INTERVALO
                    h[k]= h[k] + 1;
                    //VARIÁVEL QUE EVITA REPETIÇÕES DESNECESSÁRIAS
                    para = 1;
                }
            }
            //FINAL DO INTERVALO FECHADO (ÚLTIMO LOOP)
            else if(k+1 == c && para ==0){
                if(inicio <= notas[a] && notas[a] <= final){
                    h[k]= h[k] + 1;
                    para = 1;
                }
            }
            //ATUALIZAÇÃO PARA O LOOP MAIS INTERNO
            inicio = final;
            final+= 10/c;
        }
        //ATUALIZAÇÃO PARA O LOOP MAIS EXTERNO
        para = 0;
        inicio = 0;
        final= 10/c;
    }

    /*for (l = 0; l < c; l++){
        printf("indice :%d = %d\n", l, h[l]);
    }*/
}

void joinHistograms(int c, int h1[c], int h2[c], int joint[c]) {
    int i, l;
    
    //SOMAR OS VALORES DE MESMO ÍNDICE
    for (i = 0; i < c; i++){
        joint[i] = h1[i] + h2[i];
    }
}

void printHistogram(int c, int h[c]){
    char histo[100][4*c];
    int i=0, maior, f, d, m, a, y1=1, y2=2, b=0;

    
    maior = h[0];

    for (i = 0; i < c; i++){
        //MAIOR VALOR DO ARRAY
        if (h[i]>= maior){
            maior = h[i];
        }
        else{
            maior = maior;
        }
    }
    //MONTANDO A MATRIZ
    for (f = 0; f < maior; f++){
        for (d = 0; d < 4*c; d++){
            histo[f][d] = '_';
        }
    }

    //CONDIÇÕES DAS ##
    //PARA UM CONTEÚDO QUE SEJA DIFERENTE DE ZERO
    for (a = 0; a < maior; a++){
        for (m = 0; m < c; m++){
            //QUANDO O VALOR DO VETOR É ZERO VAMOS PULAR DUAS "_"
            if(h[m] == 0){
                y1+= 2;
                y2+= 2;
            }
            //CASO O VALOR DO VETOR SEJA DIFERENTE DE ZERO DEVEMOS IMPRIMIR "##" 
            else if(h[m] != 0){
                h[m] += -1;
                histo[maior - 1 + b][y1] = '#';
                histo[maior - 1 + b][y2] = '#';
                
                //ATUALIZAÇÃO PARA PULAR AS POSIÇÕES QUE FORAM COLOCADAS AGORA"##"
                y1+= 2;
                y2+= 2;
            }
            //ATUALIZAÇÃO DO LOOP INTERNO PARA PULAR AS DUAS LINHAS PADRÃO
            y1+= 2;
            y2+= 2;
        }
        //ATUALIZAR O VALOR DO LOOP PARA A PRÓXIMA LINHA
        b+= -1;
        y1= 1;
        y2= 2;

    }
    for (f = 0; f < maior; f++){
        for (d = 0; d < 4*c; d++){
            printf("%c", histo[f][d]);
        }
        printf("\n");   
    }
    printf("\n");    
}

int main(){
    int numCateg;
    scanf("%i", &numCateg);

    int histA[numCateg];
    int histB[numCateg];
    int histAll[numCateg];

    createHistogram(numCateg, histA);
    createHistogram(numCateg, histB);
    joinHistograms(numCateg, histA, histB, histAll);

    printHistogram(numCateg, histA);
    printHistogram(numCateg, histB);
    printHistogram(numCateg, histAll);

    return 0;
}