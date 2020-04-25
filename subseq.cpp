#include <stdio.h>
#include <stdlib.h>



void subseq(int vet[], int n){
	int seqs[n];
	int seqsnum[n][254];
	
	
	for(int i=0;i<n;i++){
		int sub = 0;
		int ultimo=0;
		int idcpst = 0;
		for(int j=(i+1);j<n;j++){	
			if(vet[j]> vet[j-1] && vet[j-1]>ultimo){
				sub++;
				seqsnum[i][idcpst] = vet[j-1];
				idcpst++;
				ultimo = vet[j-1];
			}
			if(j+1 == n){
				if(vet[j] > ultimo){
					sub++;
					seqsnum[i][idcpst] = vet[j];
					idcpst++;
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
	
	printf("\n Vetor de maior subsequencias:{ ",idc);
	for(int i=0;i<seqs[idc];i++){
		printf( " %d,", seqsnum[idc][i]);
	}
	printf("}");
	printf("\n a maior sequencia eh de tamanho: %d \n",seqs[idc]);
}

int main(){
	int vet[9] = {1,4,3,6,9,5,2,7,8};
	subseq(vet,9);

  system("pause");
}
