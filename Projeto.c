
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
 
#define N 2

struct student 
{
            int id;
            char name[20];
            double percentage;
};
 
void func(struct student record);


char Menu()
{
	char opcao;
	system("cls");
	printf("######################################################\n");
	printf("#### Sistema Gerenciador de Cadastro de Produtos #####\n");
	printf("######################################################\n");
	printf(" ::: ( I )ncluir \n");
	printf(" ::: ( B )uscar \n");
	printf(" ::: ( L )istar \n");
	printf("\n\n::: Digite a opcao desejada e pressione ENTER: ");
	scanf("%c", &opcao);
	printf("\n Vc escolheu a opcao %c!\n", opcao);
	
	return( opcao );
}

void Incluir()
{
	// insere um novo registro
	struct student st;	
    printf("\nInforme o ID: ");         scanf("%d", &st.id);
    printf("\nInforme o NOME: ");       scanf("%s", &st.name);
    printf("\nInforme o PERCENTUAL: "); scanf("%lf", &st.percentage);
    
    FILE* arq = fopen("dados.bin", "ab");
    if( arq == NULL )
    {
    	printf("\n::: Erro abrindo arquivo para salvar dados!\n");
    	exit(-1);
	}
	fwrite(&st, sizeof(struct student), 1, arq);
	fclose(arq);
	printf("\n Registro incluido com sucesso! Pressione qualquer tecla!\n");
	char x = getch();
}


void Buscar() {}
void Listar() {}

int main() 
{
	
	
	while( true )
	{
		char Resp = Menu(); //printf("**** %c ****", Resp);
		switch( Resp )
		{
			case 'I': Incluir(); break;
			case 'B': Buscar();  break;
			case 'L': Listar();  break;
			default:
				printf("\n::: Obrigado! good bye! :::\n");
				exit(0);
				break;
		}
		
	}
	
	
			int i = 0;
            struct student record;
 
            //record.id=1;
            //strcpy(record.name, "Raju");
            //record.percentage = 86.5;
 
            
			struct student *Dados = (struct student*)malloc(N * sizeof(struct student));
			if( Dados == NULL )			
			{
				printf("\nErro alocando memoria!\n");
				exit(-1);
			}
			
			Dados[0].id = 11;
			Dados[0].percentage = 99.922222222;
			strcpy(Dados[0].name, "Filipo");

			Dados[1].id = 22;
			Dados[1].percentage = 88.8;
			strcpy(Dados[1].name, "Mariazinha");
			
			char x = Menu();
			
			FILE* arq = fopen("dados.bin", "wb");
			if( arq == NULL)
			{
				printf("\nErro abrindo arquivo!\n");
				exit(-1);
			}
			
			for(i = 0; i < N; i++)
			{
				printf("::: Dados[%2d].id = %2d\n::: Dados[%2d].name = %s\n::: Dados[%2d].percentage = %4.4lf\n\n", i, Dados[i].id, 
				                                                                                                 i, Dados[i].name, 
																												 i, Dados[i].percentage );
			}
			
			fwrite(Dados, sizeof(struct student), N, arq);
			fclose(arq);
			
			struct student *DadosLidos = (struct student*)malloc(N * sizeof(struct student));
			if( DadosLidos == NULL )			
			{
				printf("\nErro alocando memoria!\n");
				exit(-1);
			}
			
			
			FILE* arq2 = fopen("dados.bin", "rb");
			if( arq == NULL)
			{
				printf("\nErro abrindo arquivo!\n");
				exit(-1);
			}
			
			fread(DadosLidos, sizeof(struct student), N, arq2);
			fclose(arq2);

			for(i = 0; i < N; i++)
			{
				printf("::: DadosLidos[%2d].id = %2d\n::: DadosLidos[%2d].name = %s\n::: DadosLidos[%2d].percentage = %4.4lf\n\n", i, DadosLidos[i].id, 
				                                                                                                                i, DadosLidos[i].name, 
																												                i, DadosLidos[i].percentage );
			}
	
			
			//func(record);
            return 0;
}
 
void func(struct student record)
{
            printf(" Id is: %d \n", record.id);
            printf(" Name is: %s \n", record.name);
            printf(" Percentage is: %f \n", record.percentage);
}
