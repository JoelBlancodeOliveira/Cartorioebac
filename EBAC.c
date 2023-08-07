#include <stdio.h> // biblioteca de comunica��o com o usu�rio 
#include <stdlib.h> // biblioteca de aloca��o de espa�o de mem�ria
#include <locale.h> //biblioteca de aloca��o de texto por regi�o
#include <string.h> // Biblioteca respons�vel por cuidar das string

int registro() // Fun��o respons�vel por cadastrar os usu�rios dos sistema
{
	//in�cio da cria��o de vari�veis/string
	char arquivo[40];
	char cpf[40]; // char tipo de vari�vel de caracteres/texto; [] significa string
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	//final da cria��o de vari�veis/string
	
	printf("Digite o CPF a ser a cadastrado: ");// Coletando informa��es do usu�rios
	scanf("%s", cpf); // %s refere-se a string
	
	strcpy(arquivo, cpf); // Fun��o copiar valores das string ficando arquivo = cpf
	
	FILE *ponteiro; // Cria vari�vel ponteiro para o arquivo
	ponteiro = fopen(arquivo, "w"); // Cria o arquivo e o "w" significa escrever/criar, criando arquivo com o n�mero do CPF
	fprintf(ponteiro,cpf); // Grava valor da vari�vel no arquivo
	fclose(ponteiro); // Fecha o arquivo
	
	ponteiro = fopen(arquivo, "a"); // "a" � um arquivo existente 
	fprintf(ponteiro,","); // Escreve no arquivo ","
	fclose(ponteiro); // Fecha a fun��o
	
	printf("Digite o nome a ser cadastrado: "); // apresenta tela com a informa��o
	scanf("%s",nome); // recebe a informa��o e salva na vari�vel definida
	
	ponteiro = fopen(arquivo, "a"); // abre arquivo existente
	fprintf(ponteiro,nome); // escreve no arquivo o valor da vari�vel
	fclose(ponteiro); // fecha arquivo
	
	ponteiro = fopen(arquivo, "a");
	fprintf(ponteiro,",");
	fclose(ponteiro);
	
	printf("Digite o sobrenome a ser cadastrado: ");
	scanf("%s",sobrenome);
	
	ponteiro = fopen(arquivo, "a");
	fprintf(ponteiro,sobrenome);
	fclose(ponteiro);
	
	ponteiro = fopen(arquivo, "a");
	fprintf(ponteiro,",");
	fclose(ponteiro);
	
	printf("Digite o carga o ser cadastrado: ");
	scanf("%s",cargo);
	
	ponteiro = fopen(arquivo, "a");
	fprintf(ponteiro,cargo);
	fclose(ponteiro);
	
	
	
	//printf("Voc� escolheu o registro de nomes \n");
	//system("pause"); // Comando para pausar a tela/sistema
}

int consulta()
{
	setlocale(LC_ALL, "Portuguese"); // Definindo a linguagem que ser� usada 
	
	
	char cpf[40];
	char conteudo[200];
	
	printf("Digite o CPF a ser consultado: ");
	scanf("%s",cpf);
	
	FILE *ponteiro;
	ponteiro = fopen(cpf,"r"); // "r" para ler/read
	
	if(ponteiro == NULL)
	{
		printf("N�o foi poss�vel abrir o arquivo, n�o localizado! \n");
	}
	
	while(fgets(conteudo, 200, ponteiro) != NULL) // Busca no arquivo, enquanto for diferente de NULO
	{
		printf("\nEssas s�o as informa��es do usu�rio: ");
		printf("%s", conteudo);
		printf("\n\n");
	}
	
	system("pause");
	//printf("Voc� escolheu consultar nomes \n");
	//system("pause");
}

int deletar()
{
	char cpf[40];
	
	printf("Digite o CPF do usu�rio a ser deletado: ");
	scanf("%s",cpf);
	
	remove(cpf); // Apagar 
	
	FILE *ponteiro; // Entrar na biblioteca fun��o FILE e abrir arquivo
	ponteiro = fopen(cpf,"r"); // Abrir cpf e ler/read
	
	if(ponteiro == NULL)
	{
		printf("\nO usu�rio n�o se encontra no sistema! \n\n");
		system("pause");
		
	}
	
	
	//printf("Voc� escolheu deletar nomes \n");
	//system("pause");
}


int main()
{
	int opcao=0; // Definindo vari�veis
	int laco=1;
	
	for(laco=1;laco=1;) // Loop infinito
	{
	
		system("cls");
	
		setlocale(LC_ALL, "Portuguese"); // Definindo a linguagem que ser� usada 
	
		printf("### Cart�rio da EBAC ###\n\n"); //In�cio do menu
		printf("Escolha a op��o desejada do menu:\n\n");
		printf("\t1 - Registrar nomes\n");
		printf("\t2 - Consultar nomes\n");
		printf("\t3 - Deletar nomes\n"); // Fim do menu
		printf("\t4 - Sair do sistema\n\n");
		printf("Op��o:");
	
		scanf("%d", &opcao); // Armazenando a escolha do usu�rio / fun��o de entrada
	
		system("cls"); // Limpar tela
		
		switch(opcao) // in�cio da sele��o do menu
		{
			case 1: // Case ... break;
			registro(); // Chamada de fun��es
			break;
			
			case 2:
			consulta();
			break;
			
			case 3:
			deletar();
			break;
			
			case 4:
			printf("Obrigado por ulitizar o sistema\n");
			return 0;
			break;
			
			default:
			printf("Op��o indispon�vel \n");
			system("pause");
			break;
		}
	
	
	}
}
