	#include <stdio.h>
	#include <windows.h>
	#include <time.h>
	#include <stdlib.h>
	#include <conio.h>

	SYSTEMTIME tempo; 
	
	//**** definiçao de boleana
	
	typedef int bool; //DEFINIÇÃO TIPO VARIAVEL BOOLEANA
	#define verdadeira 1
	#define falso 0
	
	//============ STRUCT( definir tipo de variavel (TIPO PARTICIPANTE)============
	
	typedef struct{
			char nome[30], email [15], escolha_de_assento[5];
		    int cpf, tipo_participante;
			float data , horas;
			bool cadeirante;
	}Participante;
	
	//***Variaveis globais ( PODEM SER ACESSADAS EM QUALQUER LUGAR DO ARQUIVO )
	
	Participante participante;
	int assento_professor = 20;
	int assento_cadeirante = 5;
	int assento_aluno = 75;
	char assentos [10][10]={{" "}};
	
	//============ CHAMADA DE FUNÇÕES ============
    //( CHAMAR EM OUTRAS FUNCOES)	
	void cadastro();
	void sorteio();
	void menu();
	void mostrarFileira(char assentos[10][10]);
    void selecionar_assento();
	//	void verificar_vagas();
	
	//============ Função Principal ============
	// (1 FUNÇÃO QUE RODA)
	int main(){
		
		
		
		char assento[5][5];
		
		printf("  Palestra Direito LGBTs\n");//imprime o nome da palestra;
		
		printf ("\nLocal: Teatro Unip");	
			GetLocalTime(&tempo);
			printf("\n\nData Atual %d/%d/%d", tempo.wDay ,tempo.wMonth ,tempo.wYear);//imprime dia, mes e ano
			printf("\tHora: %d - Min %d", tempo.wHour, tempo.wMinute); //imprime hora e minuto
		
		menu();
	
		return 0;
	}
	//============ Funções ============
	
	//*** abre o menu de opçoes;
	void menu(){
		int escolha;
		printf("\nDigite opcao desejada de 1 a 2:\n");
		printf("1 cadastro, 2 sorteio\n ");
	    fflush(stdin); 
		scanf ("%d", &escolha);
		
		switch ( escolha){
		 	case 1: 
		 		cadastro(participante);
				break;
			case 2:
				sorteio();
				break;
			default :
				printf("escolha invalida!\n");
		}
	}
	
// APRESENTAR FILEIRA NA TELA
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
	
	// função que realiza cadastro do usuario;
	void cadastro (){
		fflush(stdin);
		
		//****CADASTRO DE INFORMAÇOES PESSOAIS
		
		printf("\n\nParticipante: "); //imprime o nome participante; 
		fflush(stdin);
		scanf("%[^\n]s",participante.nome);
		
		printf("\nDigite email: "); //imprime o emall;
		fflush(stdin);
		scanf("%s",participante.email);
		
		
		printf("\nInforme CPF: "); //imprime cpf;
		fflush(stdin);
		scanf("%d",&participante.cpf );
	    	
		// printf("Antes da funcao mostrarFileira\n\n");
		
		// *****ESCOLHA DE TIPO DE PARTICIPANTE
	
		printf("\nDigite 1 professor/convidado, Digite 2 aluno");
		fflush(stdin);
		scanf("%d",&participante.tipo_participante);
			
			
		char escolhaPCD;
		printf("\n Voce e portador de necessidades especiais?[s/n]\n");
		fflush(stdin);
		scanf("%c",&escolhaPCD);

//		printf("mostrar PCD: %c", escolhaPCD);
//		system("pause");
		if(escolhaPCD == 's' ){
			participante.cadeirante = verdadeira;	
		}
		else if (escolhaPCD == 'n'){
			participante.cadeirante = falso;
		}
//		printf("resposta cadeirante : %d\n",participante.cadeirante);
//		system("pause");
//		
		//*****ESCOLHA DE ASSENTO
		
		
		system("cls");// limpa tela
		mostrarFileira(assentos); // mostrar os assentos da tela
//		printf("Depois da funcao mostrarFileira\n\n");
	
		
		selecionar_assento();
		
		system ("cls");
		mostrarFileira(assentos);
		
		//VERIFICANDO SE E CADEIRANTE
	    
		if (participante.cadeirante == verdadeira){ 
	    	assento_cadeirante --; //DECREMENTANDO QUANTIDADE DE CADEIRA -1 (RESTANTES)
//	    	printf("assentos restantes cadeirantes %d\n", assento_cadeirante);
		}else{
			
			if (participante.tipo_participante == 1){
				assento_professor -- ;
//				printf("assentos restantes professor %d\n", assento_professor);
			}	
			else if( participante.tipo_participante == 2 ){
				assento_aluno --;
//				printf("assentos restantes aluno %d\n", assento_aluno);
			}
		}
//		system("pause"); // SERVE APENAS PARA PARAR O PROGRAMA MOMENTANEAMENTE
		menu(); // VOLTAR PARA O MENU
	}
	
	
	void sorteio(){
		int i;
		printf("\nAssentos Sorteados");
		srand(time(NULL));
		for (i = 0; i < 6; i++){
			
			/*gerando numeros aleatorios entre zero e 75*/
			printf("\t%d",rand() % 75);
		}
	    getch();
		system("PAUSE");
		menu();
	}
       
	   // ESCOLHA DE ASSENTO
	void selecionar_assento(){ 
		
		printf("\nSelecione o assento. Exemplo:'A 2'\n"); // 
		fflush(stdin);
		scanf("%[^\n]s",participante.escolha_de_assento);// LÊ ATE O USUARIO SELECIONAR O ENTER
	//	printf("\nescolha_de_assento: %s", escolha_de_assento);
	    
		int escolha_fileira = participante.escolha_de_assento[0] - 65;// pegado a escolha da fileira. 65 na tabela ascii = A
//		printf("escolha de fileira: %d\n", escolha_fileira);
	    fflush(stdin);
		
		int escolha_coluna;
		sscanf(participante.escolha_de_assento, "%*[^0-9]%d", &escolha_coluna); // pegando somente o inteiro do conteúdo do endereço da variavel de escolha de assento
		escolha_coluna --; 
//		printf("escolha de coluna: %d\n", escolha_coluna); 
		
		if(participante.tipo_participante == 1 && escolha_fileira > 7  ){// CASO O TIPO DE PARIICIPANTE SEJA PROFESSOR (1)  E SUA ESCOLHA SEJA I OU j
			assentos[ escolha_fileira][escolha_coluna] = 'x';
		} 
		else if (participante.tipo_participante == 2 && escolha_fileira <= 7){
			assentos[ escolha_fileira][escolha_coluna] = 'x';
		}else{ 
			printf(" voce não pode escolher essa fileira\n");
//			printf(" escolha de fileira: %d\n",escolha_fileira);
//			printf(" tipo de participante: %d\n",participante.tipo_participante);
//			
			selecionar_assento();//chamar função seleção de assento novamente 
		}		
	} 
	
