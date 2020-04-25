#include <stdio.h>
#include <stdlib.h>



void subseq(int vet[], int n){
	int seqs[n];
	int seqsnum[n][254];
	
	
	for(int i=0;i<n;i++){
		int sub = 0;
	//	printf("\n--------------- roda i -----------------\n");
		int ultimo=0;
		int idcpst = 0;
		for(int j=(i+1);j<n;j++){
			
		//	printf("\n comprando %d com %d", vet[j],vet[j-1]);
			//printf("\n valor de j %d valor de n %d", j,n);
			
			if(vet[j]> vet[j-1] && vet[j-1]>ultimo){
			//	printf("   --- >entrou %d , valor do ultuimo %d", vet[j-1],ultimo);
				sub++;
				seqsnum[i][idcpst] = vet[j-1];
				idcpst++;
				//printf("\n -----------------------------------valor gravado em seqsnum na pos [%d][%d] = %d", i,idcpst,vet[j-1]);
				ultimo = vet[j-1];
			}
			if(j+1 == n){
				if(vet[j] > ultimo){
					//printf("\n validei ultimo caso");
					//printf("   --- >entrou last case %d , valor do ultuimo %d, valor de vetj %d", vet[j-1],ultimo,vet[j]);
					sub++;
					seqsnum[i][idcpst] = vet[j-1];
					idcpst++;
				//	printf("\n -----------------------------------valor gravado em seqsnum na pos [%d][%d] = %d", i,idcpst,vet[j]);
					ultimo = vet[j];
				}
			}
			
		}
		seqs[i] = sub;
	}
	
	
	int aux = seqs[0];
	int idc = 0;
	for(int i=0;i<n;i++){
		if(seqs[i]>aux){
			aux = seqs[i];
			idc = i;
		}	
	}
	
	
	for(int i=0;i<n;i++){
		printf("\n");
		for(int j = 0;j<seqs[idc];j++){
				printf( "pos [%d][%d] = %d ,",i,j,seqsnum[i][j]);
		}
	}
	/*
	printf("\n Vetor valor de idc %d: ",idc);
	for(int i=0;i<seqs[idc];i++){
		printf( "%d ,", seqsnum[idc][i]);

	}
	*/
	printf("\n a maior sequencia eh %d \n",seqs[idc]);
}

int main(){

	int vet[9] = {1,4,3,6,9,5,2,7,8};

	subseq(vet,9);

  system("pause");
}
