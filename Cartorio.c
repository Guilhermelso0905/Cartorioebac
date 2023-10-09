#include <stdio.h> //biblioteca de comunicção com o usuário
#include  <stdlib.h> //biblioteca de alocação de espaço em memória
#include <locale.h> //biblioteca de alocação de texto por região
#include <string.h> //biblioteca responsavel por cuidar das string

int registro() //Função responsavel por cadastrar os usuarios no sistema
{
    //inicio da criação de variáveis/string
    char arquivo[40];
	char cpf[40];
	char nome[40];
    char sobrenome [40];
	char cargo[40];
    //final da criação de variáveis/string

	printf("Digite o CPF a ser cadastrado: "); //coletando o CPF do usuário
	scanf("%s", cpf); //%s refere-se a string
		
	strcpy(arquivo, cpf); //Responsavel por copiar os valores das string
	
	FILE *file;
	file = fopen(arquivo, "w"); //cria o arquivo na pasta e o "w" significa escrever
	fprintf(file,cpf); //salva o valor da variavel
	fclose(file); //fecha o arquivo 
	
	file = fopen(arquivo, "a"); //"a" atualiza o arquivo
	fprintf(file,","); //salva o valor da variavel
	fclose(file); //fecha o arquivo
	
	printf("Digite o nome a ser cadastrado: "); //coletando o nome do usuário
	scanf("%s",nome); 
	
	file = fopen(arquivo, "a"); 
	fprintf(file,nome); 
	fclose(file); 
	
	file = fopen(arquivo, "a"); 
	fprintf(file,",");
	fclose(file);
	
	printf("Digite o sobrenome a ser cadastrado: "); //coletando o sobrenome do usuário
	scanf("%s",sobrenome);
	
	file = fopen(arquivo, "a");
	fprintf(file,sobrenome);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file,",");
	fclose(file);
	
	printf("Digite o cargo a ser cadastrado: "); //coletando o cargo do usuário
	scanf("%s",cargo);
	
	file = fopen(arquivo, "a");
	fprintf(file,cargo);
	fclose(file);
	
	system("pause");
	
}

int consulta()
{
	setlocale(LC_ALL, "Portuguese"); //Definindo a linguagem
	
	//inicio da criação de variáveis/string
    char cpf[40];
    char conteudo[200];
    //final da criação de variáveis/string
    
    printf("Digite o CPF a ser consultado: "); //busca de qual usuário será consultado
    scanf("%s",cpf);
	
	FILE *file;
	file = fopen(cpf, "r");
	
	if(file == NULL)
	{
		printf("Não foi possivel abrir o arquivo,não localizado! \n"); //retorno qunado o CPF não estiver no banco de dados
    }     
    
    while(fgets(conteudo, 200, file) != NULL)
    {
    	printf("\nEssas são as informações do usuário: "); //informações do usuário retornadas
    	printf("%s", conteudo);
    	printf("\n\n");
	}
    system("pause");
}

int deletar()
{
    
	//inicio da criação de variáveis/string
	char cpf[40];
    //final da criação de variáveis/string
    
    printf("Digite o CPF a ser deletado: "); //busca de qual usuário será deletado
    scanf("%s",cpf);
    
    remove(cpf); //deleta o usuário
    
    FILE *file;
    file = fopen(cpf,"r");
    
    if(file == NULL)
    {
    	printf("O usuário não se encontra no sistema! \n"); //retorno qunado o CPF não estiver no banco de dados
    	system("pause");
    	
	}
    
    
}

int main()
{
	int opcao=0; //Definindo variáveis
	int laco=1;
	
	for(laco=1;laco=1;)
	{
	    system("cls"); //responsavel por limpar a tela
    	
    	setlocale(LC_ALL, "Portuguese"); //Definindo a linguagem
	
     	printf ("### Cartório da EBAC ### \n\n"); //inicio do menu
    	printf ("Escolha a opção desejada do menu: \n\n");
    	printf ("\t1 - Registrar nomes\n");
        printf ("\t2 - Consultar nomes\n");
        printf ("\t3 - Deletar nomes\n");
        printf ("\t4 - Sair do sistema?\n\n");
        printf ("Esse Software é de Guilherme Lima \n\n");
    	printf ("Opção: "); //fim do menu
    
        scanf("%d", &opcao); //armazenando a escolha do usuario
    
    system("cls");
    
    
    switch(opcao) //inicio da seleção do menu
    {
    	case 1:
    	registro(); //chamada de funções
    	break;
    	
    	case 2:
    	consulta();
		break;
		
		case 3:
		deletar();
		break;
		
		case 4:
		printf("Obrigado por utilizar o sistema!\n");
		return 0;
		break;

		default:
		printf("Essa opção não está disponivel!\n"); //retorno qunado a opção não estiver no menu
		system("pause");
		break; //fim da seleção do menu
	}
	
	}
	
}
