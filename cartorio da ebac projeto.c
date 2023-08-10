#include <stdio.h> //biblioteca de comunicacao com os usuarios
#include <stdlib.h> //biblioteca de alocacao de espaco em memoria
#include <locale.h> //biblioteca de alocacoes de texto por regiao
#include <string.h> //biblioteca responsavel por cuidar das strings

int registro() //funcao responsavel por cadastrar os usuarios no sistema
{
	//inicio das criacoes de variaveis/strings
	char arquivo[40];
	char cpf [40];
	char nome [40];
	char sobrenome [40];
	char cargo [40];
	//fim da criacao de variaveis
	
	printf("Digite o CPF a ser cadastrado: "); //coletando informacao do usuario
	scanf("%s", cpf); //salvando na variavel string
	
	strcpy(arquivo, cpf); // responsavel por copiar os valores das strirngs
	
	FILE *file; // acessa a funcao FILE na biblioteca e o *file referencia o acesso ao arquivo
	file = fopen(arquivo, "w"); // cria o arquivo e o W significa escrever
	fprintf(file, cpf); // salvo o valor da variavel
	fclose(file); // fecha o arquivo
	
	file=fopen(arquivo, "a"); // o A atualiza o arquivo
	fprintf(file, ",");
	fclose(file);
	
	printf("Digite o nome a ser cadastrado: "); 
	scanf("%s",nome);
	
	file=fopen(arquivo, "a");
	fprintf(file,nome);
	fclose(file);
	
	file=fopen(arquivo, "a");
	fprintf(file, ",");
	fclose(file);
	
	printf("Digite o sobrenome a ser cadastrado: ");
	scanf("%s",sobrenome);

	file=fopen(arquivo, "a");
	fprintf(file, sobrenome);
	fclose(file);
	
	file=fopen(arquivo, "a");
	fprintf(file, ",");
	fclose(file);
	
	printf("Digite o cargo a ser cadastrado: ");
	scanf("%s", cargo);
	
	file=fopen(arquivo, "a");
	fprintf(file, cargo);
	fclose(file);
	
	system("pause"); // pause o looping do FOR para que p usuario tenha acesso a mensagem
}

int consultar() //funcao responsavel por consultar os usuarios no sistema
{
	//inico da criacao das variaves
	char cpf[40];
	char conteudo[200];
	//fim da criacao das variaveis
	
	printf("Digite o cpf a ser consultado:"); //coletando informacao do usuario
	scanf("%s", cpf); //fim da criacao de variaveis
	
	
	FILE*file; // acessa a funcao FILE na biblioteca e o *file referencia o acesso ao arquivo
	file= fopen(cpf, "r"); // abre o arquivo e o R le o que esta dentro
	
	if(file==NULL) //pergunta para validacao do conteudo no banco de dados
	{
		printf("Nao foi possivel abrir o arquivo, nao localizado!\n");
	}
	
	while(fgets(conteudo,200,file)!=NULL) //ciclo de repeticao referenciando respectivamente fgets=ir buscar/ler no arquivo, conteudo= string onde sera armazenada, 200= numero maximo de caracteres a serem lidos,file= arquivo que sera lido, !=null = o looping ira ler os caracteres ate vir nulo e parar 
	{
		printf("\n Essas sao as informacoes do usuario: ");
		printf("%s", conteudo); //salva o valor da string conteudo e mostra para o usuario o que foi salvo
		printf("\n\n");
	}
	
	system("pause");
}

int deletar() //funcao responsavel por deletar os usuarios no sistema
{ 
//inicio das criacoes de variaveis/strings
   char cpf[40];
   //fim das variaveis
   
   printf("digite o CPF do usuario a ser deletado: " ); //coletando informacao do usuario
   scanf("%s", cpf); //salvando na variavel string
   
   remove(cpf); // comando remvove ira deleter o arquivo referenciado na variavel cpf
 
  
   FILE*file;  // acessa a funcao FILE na biblioteca e o *file referencia o acesso ao arquivo
   file=fopen(cpf, "r");  // abre o arquivo e o R le o que esta dentro
   
   
   if (file==NULL) //pergunta para validacao do conteudo no banco de dados
   {
   	printf("O usuario nao se encontra no sistema. \n");
   	system("pause"); //pausa o looping do sistema
   }
   else // caso o cpf nao seja nulo mostra a mensagem de confirmacao
   {
   	printf("Usuario deletado! ");
   	system("pause"); //pausa o looping do sistema
   }
}

int main() //funcao principal/menu
{
    int opcao = 0;  //definindo as variaveis
    int laco = 1; //declarando e inicializando uma variável chamada laco do tipo int e atribuindo o valor 1 a ela. Essa variável será usada como um indicador para controlar a execução do loop

    for (laco = 1; laco = 1;) //iniciando um loop for. O primeiro campo (laco = 1) é a inicialização do loop, onde você atribui o valor 1 à variável laco. O segundo campo (laco = 1) é a condição de continuação do loop. Esta é uma condição de verificação que é avaliada antes de cada iteração do loop. Se a condição for verdadeira, o loop continuará a ser executado; se for falsa, o loop será interrompido.
    {

        system("cls"); //responsavel por limpar a tela

        setlocale(LC_ALL, "portuguese");  //definindo a linguagem

        printf("### Cartorio da EBAC ###\n\n");  //inicio do menu
        printf("escolha a opcao dessejada do menu:\n\n");
        printf("\t1 - Registrar nomes\n");
        printf("\t2 - Consultar nomes\n");
        printf("\t3 - Deletar nomes \n\n");
        printf("\t4 - Sair do sistema \n\n");
        printf("Opcao: ");  // fim do menu

        scanf("%d", &opcao); //armazenar escolha do usuario

        system("cls");

        switch (opcao) // incio do SwitchCase, que eh um encadeamento de IFS
        {
        case 1:
            registro(); //chamada de funcoes
            break;

        case 2:
            consultar(); //chamada de funcoes
            break;

        case 3:
            deletar(); //chamada de funcoes
            break;
            
        case 4:
        	printf("Obrigado por utilizar o sistema!\n");
        	return 0;
        	break;
            

        default:
            printf("Opcao invalida. Por favor, escolha uma opcao valida do menu.\n");
            system("pause");
            break;
        }
    }

}

