#include <stdio.h>
#include <stdlib.h>





int main (void){
	
	int op,op2,op3;
	
	FILE *arq1, *arq2, *arq3;
	
	
	op=menu();
	system("cls");
	do{
		
		switch (op){
			case 1: op3=menu2();
					system("cls");
						do{
						
						switch (op3){
							case 1: //bubbleSort();
								break;
							case 2: insertionSort(arq2);
								break;
							case 3: //mergeSort();
								break;
							case 4: op=menu();
									system("cls");
								break;
							default: printf("Opcao invalida!!");
						}
					}while(op3!=4);
				 
				break;
			case 2: 
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

void insertionSort (FILE *arq2){
	int *p;
	int i,tam=100000;
	char filename[30];
	printf("Digite o nome do arq: ");
	fflush(stdin);
	scanf("%s", filename);
	printf("%s",filename);
	
	if(!(arq2=fopen(filename,"r"))){
		printf("\nERRO na leitura do arquivo");
		exit(0);
	}
	else{
		printf("ok!");
	}
	
	if(p=(int*)calloc,(tam*sizeof(int)==NULL)){
		printf("Erro na alocacao");
		exit(0);
	}
	
	i=0;
	while(!feof(arq2)){
	
	fscanf(arq2,"%d",&p[i]);
	i++;
}
}

