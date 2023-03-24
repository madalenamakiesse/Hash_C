#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
# define M 19

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int ficheiros(char e[], char s[]);

void hash(char e[], char s[]);

int main(int argc, char *argv[]) {
	
	//Madalena Makiesse
	
	setlocale(LC_ALL,"Portuguese");
	
	int a = ficheiros("entrada.txt", "saida.txt");
	if(a==1){
		hash("entrada.txt", "saida.txt");
	}
	return 0;
}

int ficheiros(char e[], char s[]){
	FILE *fiche;
	FILE *fichs;
	
	fiche=fopen(e, "rt");
	fichs=fopen(s,"wt");
	
	//Avaliar se é possível abrir o ficheiro
	if(fiche==NULL){
		printf("\nInsucesso ao abrir o ficheiro de entrada!");
	}
	else printf("\nSucesso ao abrir o ficheiro de entrada!");
	
	if(fichs==NULL){
		printf("\nInsucesso ao abrir o ficheiro de saída!\n\n");
	}
	else printf("\nSucesso ao abrir o ficheiro de saída!\n\n");
	
	return ((!fiche==NULL) && (!fichs==NULL))? 1 : 0;
}

void hash(char e[], char s[]){
	setlocale(LC_ALL,"Portuguese");
	
	FILE *fiche = fopen("entrada.txt", "rt");
	FILE *fichs = fopen("saida.txt","wt");
	
	//Declaração de um vetor de chars
	char texto[100],hash[M];
	char *teste;
	float fator_peso;
	int hash_table[M];
	int tam,i,k,chave,j,soma, veri;;
	
	printf("Foi possível ler: \n");
	while(!feof(fiche)){
		teste=fgets(texto,100,fiche);
		
		if(teste){
			printf("\t%s",texto);
		}
		
		tam=strlen(texto);
		fator_peso=(float)tam/M;
		
		for(i=0;i<M;i++){
			hash_table[i]=0;
		} 
		
		if(fator_peso<=1){
			k=0;
			for(i=0;texto[i]!='\0' && k<M ;i++){
				chave=texto[i]%7;
							
				if(hash_table[chave]==0 && texto[i]!='/0'){
					hash_table[chave]=texto[i];
					k++;
				}
				
				else{
					while(hash_table[chave]!= 0){
						chave++;
					}
					
					hash_table[chave]=texto[i];
					k++;
				}
			}
		}
		else{
			i=0;
			k=0;
			veri=(int)fator_peso;
			
			while(texto[i]!='\0' && k<M ){
				j=0;
				soma=0;	
				if(k+1==M-1  && texto[i]!='/0'){
					soma=soma+texto[i];
					i++;
				}
				while(j<fator_peso){
					soma=soma+texto[i];
					i++;
					j++;
				}	
				chave=soma%7;	
				if(hash_table[chave]==0 && texto[i]!='/0'){
					
					hash_table[chave]=texto[i];
					k++;
				}
				else{
					while(hash_table[chave]!= 0){
						chave++;
						}
					hash_table[chave]=texto[i];
					k++;
				}
			}
			
			
		}
		
		for ( i = 0, j = 0; i < M; ++i, j += 1){
			sprintf((hash + j), "%.01X", hash_table[i] & 0xff);
		}
		fflush(stdin);
		fwrite(hash,sizeof(char), 19,fichs);
		fprintf(fichs, "\n");
	}	
	printf("\n\n<<Fim do programa.Por favor, verifique o ficheiro de saída.>> ");
	//Finalização do ficheiro
	fclose(fiche);
	fclose(fichs);
}


