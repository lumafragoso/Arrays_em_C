#include <stdio.h>
void printar_vetor(int vetor_falta[], int tamanho){
    int i=0;

    printf("[ ");
    for (i = 0; i < tamanho; i++){
        if(i< tamanho - 1){
            printf("%d, ", vetor_falta[i]);
        }
        else{
            printf("%d ", vetor_falta[i]);
        }
    }
    printf("]\n");
}

void checagem(int valores_coletados[], int vetor[], int M, int S){
    int l=0, vetor_falta[100], i=0, control =0, k=0;

    //VERIFICAR QUAIS VALORES DO VETOR QUE FALTAM PARA COMPLETAR
    for (i = 0; i < S; i++){
        for (k = 0; k < M; k++){
            //CASO TENHAM VALORES EM COMUM
            if(vetor[i] == valores_coletados[k]){
                control ++;
            } 
        }
        //CASO NÃO TENHAM VALORES EM COMUM
        if (control == 0){
            vetor_falta[l] = i;
            l++;
        }
        control = 0; 
    }
    // FUNÇÃO PARA EXIBIR OS NUMEROS QUE FALTAM PARA COMPLETAR
    printar_vetor(vetor_falta, l);
    
}

int main(){
    int S ,N, M, i, j, k, vetor[100], valores_coletados[100], valor =0;

    scanf(" %d %d", &S, &N);

    //VETOR PARA CALCULAR QUANTIDADE DE SIMBOLOS DO VETOR
    for (i = 0; i < S; i++){
        vetor[i] = i;
    }
    

    for (j = 0; j < N; j++){
        //LER A QUANTIADADE DE SIMBOLOS A SER COLETADO POR CADA INTEGRANTE
        scanf(" %d", &M);
        //COLOCAR NO VETOR OS SIMBOLOS COLETADOS
        for (k = valor; k < (valor + M); k++){
            scanf(" %d", &valores_coletados[k]);
        }
        //ATUALIZAÇÃO PARA CONTAR TAMANHO DO VETOR E MUDAR O INTERVALO DO LOOP
        valor += M;
    }
    
    //FUNÇÃO PARA ACHAR OS NUMEROS QUE NAO PERTENCEM AO VETOR E PERTENCEM AOS VALORES COLETADOS
    checagem(valores_coletados, vetor, valor, S);
    return 0;
}