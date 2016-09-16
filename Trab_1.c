#include <stdio.h>
#include <stdlib.h>


int menu ();
int menu2();
int abrir_arq(FILE *, int *, int *);
int bubbleSort(int *,int);
int insertionSort (int*,int );
int mergeSort(int *, int, int,int );


int main (void){
	
	int op,op2,op3, *size=NULL;
	int *p=NULL;
	int tam=0, posicaoInicio, posicaoFim;
	FILE *arq1;
	FILE *arq2;
	FILE *arq3;
	
	
	op=menu();
	system("cls");
	do{
		
		switch (op){
			case 1: op3=menu2();
					system("cls");
						
						
						switch (op3){
							case 1: p=abrir_arq(arq2,p,&size);
									bubbleSort(p,size);
								break;
							case 2: p=abrir_arq(arq2,p,&size);
									insertionSort(p,size);
								break;
							case 3: 
									p=abrir_arq(arq2,p,&size);
									posicaoInicio=0;
									posicaoFim = (int)size-1;
									mergeSort(p,posicaoInicio, posicaoFim,size);
								break;
							case 4: op=menu();
									system("cls");
								break;
							default: printf("Opcao invalida!!");
						}
			
				 
				break;
			case 2: p=abrir_arq(arq2,p,&size);
					bubbleSort(p,size);
					p=abrir_arq(arq2,p,&size);
					insertionSort(p,size);
					p=abrir_arq(arq2,p,&size);
					mergeSort(p,posicaoInicio, posicaoFim,size);
				break;
			case 3: 
				return EXIT_SUCCESS;
				break;
			default: printf("Opcao invalida!!");
		}
	}while(op3==4);

	
	return EXIT_SUCCESS;
	
}
int menu (){
	int opcao;
	
	printf("Menu: \n 1-Testar \n 2-Simular \n 3-Sair \n");
	printf("Digite a opcao desejada: ");
	scanf("%d",&opcao);
	
	return opcao;
}
int menu2(){
	int opcao;
	printf("Sub-Menu: \n 1-BubbleSort \n 2-InsertionSort \n 3-MergeSort \n 4-Retornar \n");
	printf("Digite a opcao desejada: ");
	scanf("%d", &opcao);
	
	return opcao;
}

int abrir_arq(FILE *arq2, int *p, int *size){
	int i;	
	char filename[30];
	
	//printf("Digite o nome do arq: ");
	//scanf("%s", filename);
	
	arq2 = fopen("teste2.txt","r");
	if(arq2==NULL){
	
		printf("ERRO");
		exit (1);
	}
	else{
		printf("Arquivo Carregado\n");
	}
	
	i=0;
	while(1){
		p=(int*)realloc(p,++*size*sizeof(int));
		fscanf(arq2,"%d", &p[i]);
		if(feof(arq2)){
			break;
		}
		i++;
	}
	
	printf("OK");
	return p;
}
int bubbleSort(int *p, int size){
	FILE *arquivo;
	int i, j, aux; 
	int compara=0;
	int movimenta=0;
	
	for(i=size-1; i >= 1; i--){  
        for(j=0; j < i ; j++){
        	compara++;
            if(p[j]>p[j+1]){
            	
                aux = p[j];
                p[j] = p[j+1];
                p[j+1] = aux;
                movimenta++;
            }
        }
    }
	    
    printf("\n");
	arquivo = fopen ("SaidaBubbleSort.txt","w");
	if(!arquivo){
		printf("Erro abrir arq saida");
		exit(1);
	}
	fprintf(arquivo,"Esse algoritmo necessitou de %d comparacoes e %d interacoes\n",compara,movimenta);
	for(i = 0; i < size-1; i++){
        fprintf(arquivo,"%d\n",p[i]);
        
    }
    
    fclose(arquivo);
	
	return p;
}

int insertionSort (int *p, int size){
	FILE *arquivo;
	int i, j, aux;
	
	int compara=0;
	int movimenta=0;
	

	for(j=1;j<size;j++){
		aux=p[j];
		i=j-1;
		compara++;
		while (i>=0 && p[i]>aux){
			p[i+1]=p[i];
			i=i-1;
			movimenta++;
		}
			p[i+1]=aux;
	}

	printf("\n");
	arquivo = fopen ("SaidaInsertionSort.txt","w");
	if(!arquivo){
		printf("Erro abrir arq saida");
		exit(1);
	}
	fprintf(arquivo,"Esse algoritmo necessitou de %d comparacoes e %d interacoes\n",compara,movimenta);
	for(i=0;i<size-1;i++){
		fprintf(arquivo,"%d\n",p[i]);
	}	
	
	fclose(arquivo);
	
	return p;
}

int mergeSort(int *p, int posicaoInicio, int posicaoFim, int size){
	int i, j, k, metadeTamanho, *vetorTemp;
	FILE *arquivo;
	int compara=0;
	int movimenta=0;
	 
	
if(posicaoInicio == posicaoFim) return 1;
    // ordenacao recursiva das duas metades
    metadeTamanho = (posicaoInicio + posicaoFim ) / 2;
    mergeSort(p, posicaoInicio, metadeTamanho,size);
    mergeSort(p, metadeTamanho + 1, posicaoFim,size);


    // intercalacao no vetor temporario t
    i = posicaoInicio;
    j = metadeTamanho + 1;
    k = 0;
    vetorTemp = (int *) malloc(sizeof(int) * (posicaoFim - posicaoInicio + 1));

    while(i < metadeTamanho + 1 || j  < posicaoFim + 1) {
        if (i == metadeTamanho + 1 ) { // i passou do final da primeira metade, pegar v[j]
            vetorTemp[k] = p[j];
            j++;
            k++;
            compara++;
            movimenta++;
        }
        else {
            if (j == posicaoFim + 1) { // j passou do final da segunda metade, pegar v[i]
                vetorTemp[k] = p[i];
                i++;
                k++;
                compara++;
            	movimenta++;
            }
            else {
                if (p[i] < p[j]) {
                    vetorTemp[k] = p[i];
                    i++;
                    k++;
                    compara++;
            		movimenta++;
                }
                else {
                    vetorTemp[k] = p[j];
                    j++;
                    k++;
                    compara++;
            		movimenta++;
                }
            }
        }

    }
    // copia vetor intercalado para o vetor original
    for(i = posicaoInicio; i <= posicaoFim; i++) {
        p[i] = vetorTemp[i - posicaoInicio];
        movimenta++;
    }
    free(vetorTemp);
    
	arquivo = fopen ("SaidaMergeSort.txt","w");
	if(!arquivo){
		printf("Erro abrir arq saida");
		exit(1);
	}
	fprintf(arquivo,"Esse algoritmo necessitou de %d comparacoes e %d interacoes\n",compara,movimenta);
	for(i = 0; i < size-1; i++){
        fprintf(arquivo,"%d\n",p[i]);
    }
    
    fclose(arquivo);
	
	return p;
}

