#include <stdio.h> //biblioteca de comunicação com o usuário
#include<stdlib.h> //biblioteca de alocação de espaço em memória
#include<locale.h> // biblioteca de alocações de texto por região	
#include<string.h> //biblioteca responsável por cuidar das string

int registro() //função responsavel por cadastrar os nomes no sistema
{
	
		
	char arquivo[40];
      char cpf[40];
      char nome[40];
      char sobrenome[40];
      char cargo[40];
      
      printf("Digite o CPF a ser cadastrado: ");
      scanf("%s", cpf);
      
      strcpy(arquivo, cpf); //responsavel por copiar os valores da string
      
      FILE*file; // cria o arquivo
      file= fopen(arquivo, "w"); // cria o arquivo e o"w" significa escrever
      fprintf(file, cpf); //salvo o valor da variavel
      fclose(file); // fecha o arquivo
      
      file = fopen(arquivo, "a");
      fprintf(file,",");
      fclose(file);
      
      printf("Digite o nome a ser cadastrado: ");
      scanf("%s",nome);
      
      file = fopen(arquivo, "a");
      fprintf(file,nome);
      fclose(file);
      
      file = fopen(arquivo, "a");
      fprintf(file,",");
      fclose(file);
      
      printf("digite o sobrenome a ser cadastrado: ");
      scanf("%s",sobrenome);
      
      file = fopen(arquivo, "a");
      fprintf(file,sobrenome);
      fclose(file);
      
      file = fopen(arquivo, "a");
      fprintf(file,",");
      fclose(file);
      
      printf("Digite o cargo a ser cadastrado: ");
      scanf("%s",cargo);
      
      file = fopen(arquivo, "a");
      fprintf(file,cargo);
      fclose(file);
      
       file = fopen(arquivo, "a");
      fprintf(file,",");
      fclose(file);
      
      system("pause");
      
      
      
      
      
      
      
      

}

int consultar()
{
	setlocale(LC_ALL, "portuguese"); //definindo a linguagem
		
    char cpf[40];
    char conteudo[200];
    
    printf("digite o cpf a ser consultado");
    scanf("%s",cpf);
    
    FILE *file;
    file = fopen(cpf,"r");
    
    if(file == NULL)
    {
    	printf("naõ foi posssivel abrir o arquivo, não localizado.\n");
	}
	
	while(fgets(conteudo,200, file) != NULL)
	{
		printf("\nEssas são as informações do usuário");
		printf("%s", conteudo);
		printf("\n\n");
	}
	
	system("pause");
}

int deletar()
{
	char cpf[40];
	
	printf("digite o CPF a ser deletado:");	
	scanf("%s",cpf);
	
	remove(cpf);
	
	FILE *file;
	file = fopen(cpf,"r");
	
	if(file == NULL)
	{
		printf("o usuario não se encontra no sistema!.\n");
		system("pause");
		
	}
}

int main()
{
	int opcao=0; //definindo variaveis
	int laco=1;

	for(laco=1;laco=1;)
{

     
    system("cls");
	setlocale(LC_ALL, "portuguese"); //definindo a linguagem
	printf("### Cartório da EBAC ###\n\n");
	printf("Escolha a opção desejada do menu:\n\n");
	printf("\t1 - registrar nomes\n");
	printf("\t2 - consultar nomes\n");
	printf("\t3 - Deletar nomes\n\n");
	printf("\t4 - Sair do sistema\n\n");
	printf("opção: "); //fim do menu

scanf("%d", &opcao);	


system("cls"); //responsavel por limpar a tela


switch(opcao)
{
	case 1: // chamada de funções
	registro();
	break;
	
	case 2:	
	consultar();
	break;
	
	case 3:	
	deletar();
	break;
	
	case 4:
	printf("Obrigado por utilizar o sistema!\n");
	return 0;
	break;
	
	
	default:
	printf("essa opção nao está disponivel\n");
	system("pause");
	break;		
}
}
}


