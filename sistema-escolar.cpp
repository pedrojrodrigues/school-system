#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h> 
#include <locale.h> 

typedef struct{
	char nome[50], data[20], sexo[2], curso[20], renda[10];
 
}registro;

registro *cadastrar;
int tam;
int continuar;

void cadastro();
void pesquisa();
void alterar();
void listar();

void cadastro(){
	int i, c=0;
    FILE *arq;
    arq=fopen("dados.dat", "a+");
    setlocale(LC_ALL, "Portuguese");
	
    cadastrar=(registro*)malloc(sizeof(registro)*tam);
	
    printf("\t_____________________________________________________________\n");
	printf("\t--------------------- SISTEMA ESCOLAR -----------------------\n");
	printf("\n\n\t\tQuantos cadastros deseja realizar? ");
	fflush(stdin);
    scanf ("%d", &tam);
	system ("cls");
	
	printf("\t_____________________________________________________________\n");
	printf("\t--------------------- SISTEMA ESCOLAR -----------------------\n");
    for (i=0; i<tam; i++){
		c++;
		printf("\n\t\t[CADASTRO %d]\n", c);
		printf("\n\t\tDigite seu nome: ");
		fflush(stdin);
		scanf("%s",cadastrar[i].nome);
		
		fflush(stdin);
		printf("\t\tData de Nascimento: ");
		scanf("%s",cadastrar[i].data);
	
		fflush(stdin);
		printf("\t\tSexo(M/F): ");
		scanf("%s",cadastrar[i].sexo);
		
		fflush(stdin);
		printf("\t\tDigite seu Curso: ");
		scanf("%s",cadastrar[i].curso);
		
		fflush(stdin);
		printf("\t\tRenda Familiar: ");
		scanf("%s",cadastrar[i].renda);
		
        fprintf(arq,"%s %s %s %s %s\n", cadastrar[i].nome, cadastrar[i].data, cadastrar[i].sexo, cadastrar[i].curso, cadastrar[i].renda);
		
        system("cls");
		printf("\t_____________________________________________________________\n");
	    printf("\t--------------------- SISTEMA ESCOLAR -----------------------\n");
	}
	fclose(arq);
}

void pesquisa(){
   
    FILE *arq;
	int i,a;
	arq = fopen("dados.dat","r");

	registro temp;
	
	while(1){
		fscanf(arq,"%s %s %s %s %s\n",&temp.nome,&temp.data,&temp.sexo,&temp.curso,&temp.renda);
		fprintf(arq,"%s %s %s %s %s\n",temp.nome,temp.data,temp.sexo,temp.curso,temp.renda);
		system("cls");	
		i++;
		if(feof(arq)) break;
	}
	fclose(arq);
	
	registro vetorOrd[i];
    arq=fopen("dados.dat","r");
    a=0;
    
    while(1){
		fscanf(arq,"%s %s %s %s %s\n",&vetorOrd[a].nome,&vetorOrd[a].data,&vetorOrd[a].sexo,&vetorOrd[a].curso,&vetorOrd[a].renda);
		system("cls");	
		a++;
		if(feof(arq)) break;
	}
    fclose(arq);
    
    
 
    char nome_busca[50];
    int nao_tem=999;

	printf("\t_____________________________________________________________\n");
	printf("\t--------------------- SISTEMA ESCOLAR -----------------------\n"); 
    printf("\n\t\t[BUSCA]\n");
    printf("\n\n\t\tInforme o Nome Completo: ");
    fflush(stdin);
    gets(nome_busca);
    
           
    for(a=0;a<i;a++){
      
            if(strcmp(vetorOrd[a].nome,nome_busca)==0){
                                                                                               
        	printf("\n\n");                        
            printf("\t\tAluno: %s",vetorOrd[a].nome);
            printf("\n\t\tData de Nascimento: %s", vetorOrd[a].data);
            printf("\n\t\tSexo(M/F): %s",vetorOrd[a].sexo);
            printf("\n\t\tCurso: %s",vetorOrd[a].curso); 
            printf("\n\t\tRenda Familiar: R$ %s", vetorOrd[a].renda);
            printf("\n"); 
                     
            nao_tem=0;
     
        }
        fclose(arq);
        
    }
    
    if(nao_tem==999){
    	system("cls");
    	printf("\t_____________________________________________________________\n");
		printf("\t--------------------- SISTEMA ESCOLAR -----------------------\n");
    	printf("\n\n\tNao foi encontrado nenhum dado correspondente. \n\n");
    	printf("\tCertifique-se de que as palavras estejam escritas corretamente.\n\n\n\n\n\n");
    }
                      
    system("pause");                
    system("cls");
    printf("\t_____________________________________________________________\n");
	printf("\t--------------------- SISTEMA ESCOLAR -----------------------\n");
    printf("\n\t\tDeseja continuar?   \n\n");
    printf("\t\t(1) - Sim   \n\n\t\t(2) - Nao\n\n");
    printf("\n\t\tSelecione a opcao que deseja: ");
	scanf("%d",&continuar);
    system("cls");
     
    while(continuar!=1 && continuar!=2){
        system("cls");
    	printf("\t_____________________________________________________________\n");
		printf("\t--------------------- SISTEMA ESCOLAR -----------------------\n");
    	printf("\n\t\tDeseja continuar?   \n\n");
    	printf("\t\t(1) - Sim   \n\n\t\t(2) - Nao\n\n");
    	printf("\n\t\tSelecione a opcao que deseja: ");
		scanf("%d",&continuar);                   
    }
             
    if(continuar==1){
      pesquisa();
    } 
    system("cls");
}

void alterar(){
     
    FILE *arq;
	arq = fopen("dados.dat","r");
	
	fflush(stdin);
	
	char nome_busca[50];
	int nao_tem=999;
	int i=0,aux,j,a;
    
    registro temp;
	
	while(1){
		fscanf(arq,"%s %s %s %s %s\n",&temp.nome,&temp.data,&temp.sexo,&temp.curso,&temp.renda);
		fprintf(arq,"%s %s %s %s %s\n",temp.nome,temp.data,temp.sexo,temp.curso,temp.renda);
		system("cls");	
		i++;
		if(feof(arq)) break;
	}
	fclose(arq);
	arq=fopen("dados.dat","r");
	
	registro vetorOrd[i];
	a=0;
	
	while(1){
		fscanf(arq,"%s %s %s %s %s\n",&vetorOrd[a].nome,&vetorOrd[a].data,&vetorOrd[a].sexo,&vetorOrd[a].curso,&vetorOrd[a].renda);
		system("cls");	
		a++;
		if(feof(arq)) break;
    }
    fclose(arq);
	system("cls"); 
	
	printf("\t_____________________________________________________________\n");
	printf("\t--------------------- SISTEMA ESCOLAR -----------------------\n");  
    printf("\n\n\t\t[ ALTERAR ]\n\n");
    fflush(stdin); 
    printf("\n\t\tInforme o Nome Completo: ");
    gets(nome_busca);
    
    int tamV = i;
    
	for(i=0; i<tamV; i++){
    	if(strcmp(vetorOrd[i].nome,nome_busca)==0){
    		do{
    			system("cls");
                        printf("\t_____________________________________________________________\n");
	                    printf("\t--------------------- SISTEMA ESCOLAR -----------------------\n");
              			printf("\n\t\t[ALTERAR]\n");
        				printf("\n\t\t-----------------------------------------------------\n");                        
            			printf("\n\t\tNome: %s",vetorOrd[i].nome);
            			printf("\n");
            			printf("\t\tData de Nascimento: %s", vetorOrd[i].data);
            			printf("\n");
            			printf("\t\tSexo(M/F): %s",vetorOrd[i].sexo);
            			printf("\n");
            			printf("\t\tCurso: %s",vetorOrd[i].curso); 
            			printf("\n"); 
            			printf("\t\tRenda Familiar: R$ %s", vetorOrd[i].renda);
            			printf("\n"); 
            			printf("\n\t\t-----------------------------------------------------\n");
				printf("\n");
                printf("\t\t(1) Nome\n\t\t(2) Data de Nascimento\n\t\t(3) Sexo\n\t\t(4) Curso\n\t\t(5) Renda Familiar\n\t\t(6) Sair.\n\n");
                printf("\t\tSelecione a opcao que deseja alterar: ");
                scanf("%d",&a);
                printf("\n\n");
                system("cls");
                printf("\t_____________________________________________________________\n");
                printf("\t--------------------- SISTEMA ESCOLAR -----------------------\n");
				printf("\n\t\t[ALTERAR]\n");
                switch(a){
					case 1:
						fflush(stdin);
                    	printf("\n\t\tDigite um Nome:  ");
                    	gets(vetorOrd[i].nome);
                        printf("\n");
						break;
                    case 2:
                    	printf("\n\t\tData de Nascimento:  ");
                        scanf("%s", &vetorOrd[i].data);
                        printf("\n");
						break;
					case 3:
						printf("\n\t\tSexo(M/F): ");
						scanf("%s", vetorOrd[i].sexo);
						printf("\n");
						break;
					case 4:
						printf("\n\t\tCurso: ");
						scanf("%s", vetorOrd[i].curso);
						printf("\n");
						break;
                    case 5:
						printf("\n\t\tRenda Familiar: ");
						scanf("%s", &vetorOrd[i].renda);
						printf("\n");
						break;
					case 6:
						break;			
				}

			}while((a<1) || (a>6));
				nao_tem=0;		
		}
	}
    arq=fopen("dados.dat","w");
    for(i=0;i<tamV;i++){
 	fprintf(arq,"%s\n %s\n %s\n %s\n %s\n", vetorOrd[i].nome, vetorOrd[i].data, vetorOrd[i].sexo, vetorOrd[i].curso, vetorOrd[i].renda);
	fclose(arq);
	if(nao_tem==999){
    	system("cls");
    	printf("\t_____________________________________________________________\n");
		printf("\t--------------------- SISTEMA ESCOLAR -----------------------\n");
    	printf("\n\n\tNao foi encontrado nenhum dado correspondente. \n\n");
    	printf("\tCertifique-se de que as palavras estejam escritas corretamente.\n\n\n\n\n\n");
    }
                      
    system("pause");                
    system("cls");
    printf("\t_____________________________________________________________\n");
	printf("\t--------------------- SISTEMA ESCOLAR -----------------------\n");
    printf("\n\t\tDeseja continuar?   \n\n");
    printf("\t\t(1) - Sim   \n\n\t\t(2) - Nao\n\n");
    printf("\n\t\tSelecione a opcao que deseja: ");
	scanf("%d",&continuar);
    system("cls");
     
    while(continuar!=1 && continuar!=2){
        system("cls");
    	printf("\t_____________________________________________________________\n");
		printf("\t--------------------- SISTEMA ESCOLAR -----------------------\n");
    	printf("\n\t\tDeseja continuar?   \n\n");
    	printf("\t\t(1) - Sim   \n\n\t\t(2) - Nao\n\n");
    	printf("\n\t\tSelecione a opcao que deseja: ");
		scanf("%d",&continuar);                   
    }
             
    if(continuar==1){
      alterar();
    } 
 
    system("cls");
}
}
void listar(){
   	FILE *arq;
	arq = fopen("dados.dat","r");
	int i=0,aux,j,a;
	registro temp;
	
	while(1){
		fscanf(arq,"%s %s %s %s %s\n",&temp.nome,&temp.data,&temp.sexo,&temp.curso,&temp.renda);
		fprintf(arq,"%s %s %s %s %s\n",temp.nome,temp.data,temp.sexo,temp.curso,temp.renda);
		system("cls");	
		i++;
		if(feof(arq)) break;
	}
	fclose(arq);

   registro vetorOrd[i];
   arq=fopen("dados.dat","r");
   a=0;
   while(1){
		fscanf(arq,"%s %s %s %s %s\n",&vetorOrd[a].nome,&vetorOrd[a].data,&vetorOrd[a].sexo,&vetorOrd[a].curso,&vetorOrd[a].renda);
		system("cls");	
		a++;
		if(feof(arq)) break;
	}
    fclose(arq);
    int final = i;
   
   for(i=0; i<final-1; i++){
        	registro aux;
        	for (j=i+1;j<final;j++) {
        		if (strcmp(vetorOrd[i].nome, vetorOrd[j].nome)==1){ 
        		strcpy(aux.nome,vetorOrd[i].nome);
        		strcpy(aux.data,vetorOrd[i].data);
        		strcpy(aux.sexo,vetorOrd[i].sexo);     		  		
				strcpy(aux.curso,vetorOrd[i].curso);
				strcpy(aux.renda,vetorOrd[i].renda);   
				
				strcpy(vetorOrd[i].nome,vetorOrd[j].nome);
				strcpy(vetorOrd[i].data,vetorOrd[j].data);
				strcpy(vetorOrd[i].sexo,vetorOrd[j].sexo);
				strcpy(vetorOrd[i].curso,vetorOrd[j].curso);
				strcpy(vetorOrd[i].renda,vetorOrd[j].renda);
				
				strcpy(vetorOrd[j].nome,aux.nome);
				strcpy(vetorOrd[j].data,aux.data);
				strcpy(vetorOrd[j].sexo,aux.sexo);
				strcpy(vetorOrd[j].curso,aux.curso);
				strcpy(vetorOrd[j].renda,aux.renda);    		
				
				      		
				}
			}
        	
		}
		
		printf("\t_____________________________________________________________\n");
		printf("\t--------------------- SISTEMA ESCOLAR -----------------------\n");
		printf("\n\t\t[ALUNOS CADASTRADOS]\n");
        for (i=0;i<final;i++){
		
		printf("\n");	
		printf("\n\t\tAluno: %s",vetorOrd[i].nome);
		printf("\n\t\tData de Nascimento: %s",vetorOrd[i].data);
		printf("\n\t\tSexo(M/F): %s",vetorOrd[i].sexo);
		printf("\n\t\tCurso: %s",vetorOrd[i].curso);
		printf("\n\t\tRenda Familiar: R$ %s\n",vetorOrd[i].renda);
			
	}
	printf("\n\t\tDigite a tecla ENTER para voltar ao MENU PRINCIPAL");
	printf("\n\n");	
	system("pause");

}

void excluir(){
    FILE *arq;
    arq = fopen("dados.dat","w+b");
    if (arq == NULL){
	printf("Erro");
    }
    else{
         fflush(stdin);
         printf("Tudo foi excluido!!");
	fclose(arq);
    getch();
    system("cls"); 
}
}

int main(){
    system("color b");
	int op;
	
	registro *cadastrar;
	cadastrar = (registro*)malloc(sizeof(registro));
		
	while(op!=6){
		system ("cls");
		printf("\t_____________________________________________________________\n");
		printf("\t--------------------- SISTEMA ESCOLAR -----------------------\n");
		printf("\n\t\t(1)-Cadastrar\n");
		printf("\t\t(2)-Pesquisar\n");
		printf("\t\t(3)-Alterar\n");
		printf("\t\t(4)-Lista de Cadastros\n");
		printf("\t\t(5)-Excluir\n");
		printf("\t\t(6)-Sair\n");
		
		printf("\n\t\tSelecione a opcao que deseja: ");
		fflush(stdin);
		scanf("%i", &op);			
		system ("cls");
		if (op==1){
			cadastro();
		}
		if (op==2){
			pesquisa();
		}
		if (op==3){
			alterar();
		}
		if (op==4){
			listar();
		}
		if (op==5){
  			excluir();
		}
	    if (op==6){
        	exit(0);
        }
	}
	
	system("pause");	
	return 0;	
}

