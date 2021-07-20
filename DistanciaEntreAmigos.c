#include <stdio.h>

int main(){
    int andares[100], distancia[100], i, j, num, contagem=1, k, h, maior= 0, a=0;

    scanf(" %d", &num);

    //LER ANDARES DOS PREDIOS
    for (i = 0; i < num; i++){
        scanf(" %d", &andares[i]);
    }
    

    for (j = 0; j < num; j++){
        for (k = contagem; k < num; k++){
            //ANDARES - PERCURSO + B
            distancia[a] = andares[j] + andares[k] + abs(k- j);
            a++;
        }
        //ATUALIZAÇÃO DO LOOP
        contagem ++;
    }
    maior = distancia[0];
    //PARA DEFINIR A MAIOR DISTANCIA CALCULADA
    for (h = 0; h < a; h++){
        if(distancia[h] > maior){
            maior = distancia[h];
        }
        else if(distancia[h] = maior){
            maior = distancia[h];
        }
        else if(distancia[h] < maior){
            maior = maior;
        }
        
    }
    
    printf("%d", maior);

    return 0;
    
    
}