#include <stdio.h>
#include <stdlib.h>

/* 	Algoritmo de maior subsequencia em um vetor de n dimensao

	Feito por: Guilherme Henrique Moreira   RA: 22117039-2
	Professor: Guilherme Waches   Analise e Complexidade de Algoritmos
	(FEI)
*/

void subseq(int vet[], int n){
	//Vetores auxiliares
	int seqs[n];			//Vetor de armazenamento do tamanho de cada subsequencia;
	int seqsnum[n][254];	//Vetor de armazenamento dos elementos de cada subsequencia;
	
	for(int i=0;i<n;i++){
		//Variaveis auxiliares
		int sub = 0;	//Variavel de contagem de tamanho de subsequencia;
		int ultimo=0;	//Variavel para armazenar o ultimo numero adicionado a subsequencia;
		int idcpst = 0;	//Varivel de indice para armazenamento no vetor dos elementos de cada subsequencia;
		
		for(int j=(i+1);j<n;j++){	
			//If de comparação
			if(vet[j]> vet[j-1] && vet[j-1]>ultimo){
				sub++;									//Incrementacao do tamanho da subsequencia;
				seqsnum[i][idcpst] = vet[j-1];			//Armazenamento do elemento no no vetor dos elementos de cada subsequencia;
				idcpst++;								//Incremento do indice do vator dos elementos de cada subsequencia;
				ultimo = vet[j-1];						//Alteracao do ultimo elemento adicionado para proximas comparacoes;
			}
			//If de comparação do ultimo caso
			if(j+1 == n){
				if(vet[j] > ultimo){
					sub++;								//Incrementacao do tamanho da subsequencia;
					seqsnum[i][idcpst] = vet[j];		//Armazenamento do elemento no no vetor dos elementos de cada subsequencia;
					idcpst++;							//Incremento do indice do vator dos elementos de cada subsequencia;
					ultimo = vet[j];					//Alteracao do ultimo elemento adicionado para proximas comparacoes;
				}
			}
			
		}
		seqs[i] = sub;	//Armazenamento do tamanho da subsequencia;
	}
	
	
	//Variaveis auxiliares
	int aux = seqs[0];	//Variavel auxiliar para achar a maior subsequencia do vetor de tamanho das subsequencias;
	int idc = 0;		//Variavel para armazenar o indice da maior subsequencia (para conseguir ser encontrado no vetor dos elementos);
	
	for(int i=0;i<n;i++){
		//If de comparacao
		if(seqs[i]>aux){
			aux = seqs[i];
			idc = i;
		}	
	}
	
	
	//print do vetor de maior subsequencia (apatir do indice e do tamanho retirado no laço anterior);
	printf("\n Vetor de maior subsequencias:{ ",idc);
	for(int i=0;i<seqs[idc];i++){
		printf( " %d,", seqsnum[idc][i]);
	}
	printf("}");
	
	//Print do tamanho da maior subsequencia
	printf("\n a maior sequencia eh de tamanho: %d \n",seqs[idc]);
}

int main(){
	
	int vet[9] = {1,4,3,6,9,5,2,7,8};
	subseq(vet,9);
	
	
	system("pause");
}
