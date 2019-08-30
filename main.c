	#include <stdio.h>
	#include <windows.h>
	#include <time.h>
    #include <stdlib.h>
	#include <conio.h>
    #include <bits/stdc++.h>
	#define SYSTEMTIME tempo; 
	
	// defini�ao de booleana
	
	typedef int bool; //defini�ao tipo variavel booleana
	#define verdadeira 1
	#define falso 0
	
	//============ STRUCT( definir tipo de variavel (TIPO PARTICIPANTE)============
	
	typedef struct{
			char name[30], email [14], escolha_de_assento[5];
			float data , horas;
		    int cpf, tipo_participante;
			bool cadeirante;
	}Participante;
	
	//***Variaveis globais ( PODEM SER ACESSADAS EM QUALQUER LUGAR DO ARQUIVO )
	
	Participante participante;
	int assento_professores = 20;
	int assento_cadeirante = 5;
	int assento_aluno = 75;
	char assentos [10][10]={{" "}};
    Participante p_list[100];

	//============ DECLARA��O DE FUN��ES ============
    
	//           CHAMAR EM OUTRAS FUNCOES
	void cadastro();   
	void sorteio();
	void menu();
	void mostrarFileira(char assentos[10][10]);
    void selecionar_assento();
	int verificar_lista(); // fun��o que retorna inteiro
	//	void verificar_vagas();
	
	//============ Fun��o Principal ============
	//           1� FUN��O QUE RODA
	int main(){
		
		
		
		char assento[5][5];
		
		printf("  Palestra Direito LGBTs\n");//imprime o nome da palestra;
		
		printf ("\nLocal: Teatro Unip");	

		time_t t = time(NULL);
		struct tm tm = *localtime(&t);
			printf("\n\nData Atual %d/%d/%d", tm.tm_mday ,tm.tm_mon ,tm.tm_year);//imprime dia, mes e ano
			printf("\tHora: %d - Min %d", tm.tm_hour, tm.tm_min); //imprime hora e minuto
		
		menu();
	
		return 0;
	}
	//============ Fun��es ============
	
	//*** abre o menu de op�oes;
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
				menu();
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
	
	// fun��o que realiza cadastro do usuario;
	void cadastro (){
		fflush(stdin);
		
		//****CADASTRO DE INFORMA�OES PESSOAIS
		
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
	
		printf("\nDigite 1 professor/convidado, Digite 2 aluno\n");
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
		
		int posicao_lista;// posi��o da lista vai ser igual ao valor que a fun��o retorna
		posicao_lista = verificar_lista();
		printf("posi��o vazia da lista encontrada :%d\n", posicao_lista);
		system("pause");
		if(posicao_lista >=100){
			printf(" n�o h� mais assentos\n");
			system("pause");
			menu();
		}
		
		
		
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
		
		p_list[posicao_lista] = participante;//colocando a variavel (participante) na 1 posi�ao que estiver vazia  
		
//		system("pause"); // SERVE APENAS PARA PARAR O PROGRAMA MOMENTANEAMENTE
		menu(); // VOLTAR PARA O MENU
	}
	
	
	void sorteio(){
		int i;
		int i_sorteio = 0;
		int usuario_sorteado;

		Participante p_sorteio [75];//struct 
		printf("\nAssentos Sorteados");
		srand(time(NULL));
		
		for (i = 0; i < 100; i++){
				
			if(p_list[i].tipo_participante == 2 ){
				p_sorteio [i_sorteio] = p_list[i]; // p_sorteio na posi��o [i_sorteio} vai ser igual ao p_list na posi��o i
				i_sorteio++; // [I] SIGNIFICA PECORRER A LISTA DO SORTEIO
			}
			
		}
		int p_aux[75];//posi��o auxiliar
		i = 0;
		while ( i < 6 ){
	   	
		   /*gerando numeros aleatorios entre zero e 75*/
			usuario_sorteado =(rand()% i_sorteio);
			if (p_aux[usuario_sorteado]== 0){
				p_aux[usuario_sorteado]= 1;
				printf("%s\n",p_sorteio[usuario_sorteado].escolha_de_assento);	
				i++;
			}
			
//	    	getch();
		}
	
		system("PAUSE");
		menu();
		
	}
       
	   // ESCOLHA DE ASSENTO
	void selecionar_assento(){ 
		
		printf("\nSelecione o assento. Exemplo:'A 2'\n"); // 
		fflush(stdin);
		scanf("%[^\n]s",participante.escolha_de_assento);// L� ATE O USUARIO SELECIONAR O ENTER
	//	printf("\nescolha_de_assento: %s", escolha_de_assento);
	    
		int escolha_fileira = participante.escolha_de_assento[0] - 65;// pegado a escolha da fileira. 65 na tabela ascii = A
//		printf("escolha de fileira: %d\n", escolha_fileira);
	    fflush(stdin);
		
		int escolha_coluna;
		sscanf(participante.escolha_de_assento, "%*[^0-9]%d", &escolha_coluna); // pegando somente o inteiro do conte�do do endere�o da variavel de escolha de assento
		escolha_coluna --; 
//		printf("escolha de coluna: %d\n", escolha_coluna); 
		
		
		if(participante.tipo_participante == 1 && escolha_fileira > 7  ){// CASO O TIPO DE PARIICIPANTE SEJA PROFESSOR (1)  E SUA ESCOLHA SEJA I OU j
			assentos[ escolha_fileira][escolha_coluna] = 'x';
		} 
		else if (participante.tipo_participante == 2 && escolha_fileira <= 7){
			assentos[ escolha_fileira][escolha_coluna] = 'x';
		}else{ 
			printf(" voce n�o pode escolher essa fileira\n");
//			printf(" escolha de fileira: %d\n",escolha_fileira);
//			printf(" tipo de participante: %d\n",participante.tipo_participante);
//		                                                                                                                           	
			selecionar_assento();//chamar fun��o sele��o de assento novamente 
		}		
	
	} 
	int verificar_lista(){
		int i;
		for (i =0; i<100; i++){
			if(p_list[i].escolha_de_assento[0]=='\0'){// verificando se o assento de elemento da lista esta vazio
				break;	
			}	
		} 		
		return i; //retornando a posi��o que esta vazia na lista 
	}
	
