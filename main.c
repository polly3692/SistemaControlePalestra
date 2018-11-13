	#include <stdio.h>
	#include <windows.h>
//	#include <time.h>
	#include <stdlib.h>
	SYSTEMTIME tempo;
	
	void mostrarFileira(char assentos[10][10]){
		char fileira_alfa; 
		int coluna;
		int fileira = 0;
		printf("   1  2  3  4  5  6  7  8  9  10\n" );
		for ( fileira_alfa = 'A'; fileira_alfa != 'K'; fileira_alfa ++){
			printf("%c ", fileira_alfa);
			for (coluna= 0; coluna <10; coluna ++){
				printf( "[%c]" , assentos[fileira][coluna]);
			}
			printf("\n");
			fileira++;
		}	
	}
 
	int main(){
	char nome[30], email [15], assento[5][5],tipo_participante;
	float data , horas;
	printf("  Palestra Direito LGBTs\n");//imprime o nome da palestra;
	
	printf ("\nLocal: Teatro Unip");	
		GetLocalTime(&tempo);
		printf("\n\nData Atual %d/%d/%d", tempo.wDay ,tempo.wMonth ,tempo.wYear);//imprime dia, mes e ano
		printf("\tHora: %d - Min %d", tempo.wHour, tempo.wMinute); //imprime hora e minuto
		
		
	printf("\n\nParticipante: "); //imprime o nome participante; 
	scanf("%[^\n]s",nome);
	
	printf("\nDigite email: "); //imprime o emall;
	scanf("%s",email);
	
	int cpf;
	printf("\nInforme CPF: "); //imprime cpf;
	scanf("%d",&cpf );
	
	
// printf("Antes da funcao mostrarFileira\n\n");
	
	char assentos [10][10]={{" "}};
		system("cls");
	mostrarFileira(assentos); // mostrar os assentos da tela
	
	fflush(stdin);
//	printf("Depois da funcao mostrarFileira\n\n");

	char escolha_de_assento[5];
	printf("\nSelecione o assento. Exemplo:'A 2'\n"); // 
	scanf("%[^\n]s", escolha_de_assento);
//	printf("\nescolha_de_assento: %s", escolha_de_assento);
	
	int escolha_fileira = escolha_de_assento[0] - 65;// pegado a escolha da fileira. 65 na tabela ascii = A
	printf("escolha de fileira: %d\n", escolha_fileira);
    fflush(stdin);
	int escolha_coluna;
	sscanf(escolha_de_assento, "%*[^0-9]%d", &escolha_coluna); // pegando somente o inteiro do conteúdo do endereço da variavel de escolha de assento
	escolha_coluna --; 
	printf("escolha de coluna: %d\n", escolha_coluna); 
	
	assentos[ escolha_fileira][escolha_coluna] = 'x';
	printf ("assento marcado: %c\n" );
	system ("cls");
	mostrarFileira(assentos);
    char escolha_de_participante;
	
//	tipo_participante;
//	printf("\Digite 2 professor/convidado, Digite 1 aluno, Digite 3 PCD");
//	scanf("%d" selecione"&Categoria);  
//    5% cadeirantes, 20% destinados a professores e convidados


	int i;
	printf("\n\Assentos Sorteados");
	srand(time(NULL));
	for (i = 0; i < 6; i++){
	
	/*gerando numeros aleatorios entre zero e 75*/
	printf("\t%d",rand() % 75);
}
    getch();
	system("PAUSE");
	return 0;
	}
	



