#include <stdio.h> // biblioteca de comunicação com o usuário 
#include <stdlib.h> // biblioteca de alocação de espaço de memória
#include <locale.h> //biblioteca de alocação de texto por região
#include <string.h> // Biblioteca responsável por cuidar das string

int registro() // Função responsável por cadastrar os usuários dos sistema
{
	//início da criação de variáveis/string
	char arquivo[40];
	char cpf[40]; // char tipo de variável de caracteres/texto; [] significa string
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	//final da criação de variáveis/string
	
	printf("Digite o CPF a ser a cadastrado: ");// Coletando informações do usuários
	scanf("%s", cpf); // %s refere-se a string
	
	strcpy(arquivo, cpf); // Função copiar valores das string ficando arquivo = cpf
	
	FILE *ponteiro; // Cria variável ponteiro para o arquivo
	ponteiro = fopen(arquivo, "w"); // Cria o arquivo e o "w" significa escrever/criar, criando arquivo com o número do CPF
	fprintf(ponteiro,cpf); // Grava valor da variável no arquivo
	fclose(ponteiro); // Fecha o arquivo
	
	ponteiro = fopen(arquivo, "a"); // "a" é um arquivo existente 
	fprintf(ponteiro,","); // Escreve no arquivo ","
	fclose(ponteiro); // Fecha a função
	
	printf("Digite o nome a ser cadastrado: "); // apresenta tela com a informação
	scanf("%s",nome); // recebe a informação e salva na variável definida
	
	ponteiro = fopen(arquivo, "a"); // abre arquivo existente
	fprintf(ponteiro,nome); // escreve no arquivo o valor da variável
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
	
	
	
	//printf("Você escolheu o registro de nomes \n");
	//system("pause"); // Comando para pausar a tela/sistema
}

int consulta()
{
	setlocale(LC_ALL, "Portuguese"); // Definindo a linguagem que será usada 
	
	
	char cpf[40];
	char conteudo[200];
	
	printf("Digite o CPF a ser consultado: ");
	scanf("%s",cpf);
	
	FILE *ponteiro;
	ponteiro = fopen(cpf,"r"); // "r" para ler/read
	
	if(ponteiro == NULL)
	{
		printf("Não foi possível abrir o arquivo, não localizado! \n");
	}
	
	while(fgets(conteudo, 200, ponteiro) != NULL) // Busca no arquivo, enquanto for diferente de NULO
	{
		printf("\nEssas são as informações do usuário: ");
		printf("%s", conteudo);
		printf("\n\n");
	}
	
	system("pause");
	//printf("Você escolheu consultar nomes \n");
	//system("pause");
}

int deletar()
{
	char cpf[40];
	
	printf("Digite o CPF do usuário a ser deletado: ");
	scanf("%s",cpf);
	
	remove(cpf); // Apagar 
	
	FILE *ponteiro; // Entrar na biblioteca função FILE e abrir arquivo
	ponteiro = fopen(cpf,"r"); // Abrir cpf e ler/read
	
	if(ponteiro == NULL)
	{
		printf("\nO usuário não se encontra no sistema! \n\n");
		system("pause");
		
	}
	
	
	//printf("Você escolheu deletar nomes \n");
	//system("pause");
}


int main()
{
	int opcao=0; // Definindo variáveis
	int laco=1;
	
	for(laco=1;laco=1;) // Loop infinito
	{
	
		system("cls");
	
		setlocale(LC_ALL, "Portuguese"); // Definindo a linguagem que será usada 
	
		printf("### Cartório da EBAC ###\n\n"); //Início do menu
		printf("Escolha a opção desejada do menu:\n\n");
		printf("\t1 - Registrar nomes\n");
		printf("\t2 - Consultar nomes\n");
		printf("\t3 - Deletar nomes\n"); // Fim do menu
		printf("\t4 - Sair do sistema\n\n");
		printf("Opção:");
	
		scanf("%d", &opcao); // Armazenando a escolha do usuário / função de entrada
	
		system("cls"); // Limpar tela
		
		switch(opcao) // início da seleção do menu
		{
			case 1: // Case ... break;
			registro(); // Chamada de funções
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
			printf("Opção indisponível \n");
			system("pause");
			break;
		}
	
	
	}
}
