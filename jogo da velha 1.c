	#include <stdio.h>      
	#include <stdlib.h>
	#include <locale.h>
	
	int main() {
	  char jogo[3][3];
	  int l, c, linha, coluna, jogador, ganhou, jogadas, opcao;        //Opção = variavel com o valor que o usuário digitar
	  setlocale(LC_ALL ,"Portuguese");                                 //Linguagem da escrita do cod
	  
	  /*
	       
		   -----------
		      
		   -----------
	  */
	  
	  
	    do{
		  jogador = 1;
		  ganhou = 0;
		  jogadas = 0;
		  
		  //Iniciando a estrutura de jogo
		  for(l = 0; l < 3; l++){
		    for(c = 0; c < 3; c++){
		    	jogo [l] [c] = ' ';                                    //Atribuindo caracter espaço para cada posição da matriz
			}
		  }
		  
		  do {
		  	
		    //Imprimir o jogo
		    printf("\n\n\t 0   1   2\n");                              //Imprimindo indice da coluna, quando for 1,2 ou 3
		    for(l = 0; l < 3; l++){
		      for(c = 0; c < 3; c++){
		      	if(c == 0)
		      	    printf("\t");
		      	printf(" %c ", jogo[l] [c]);                           //Organizando - e | para o tabuleiro
		      	if(c < 2)
		      	    printf("|");
		      	if(c == 2)
		      	    printf(" %d", l);                                  //Imprimir indice da linha, quando for 1,2 ou 3
		  			 
		      }
		      if(l < 2)
		          printf("\n\t-----------");                           //Usando tabulação para deixar mais centralizado
		      printf("\n");
		    }
		    
		    //Ler cordenadas   
		    do{
		      printf("JOGADOR %d: Digite a linha e a coluna que deseja jogar: ", jogador);
		      scanf("%d%d", &linha, &coluna);
		    }while(linha < 0 || linha > 2 || coluna < 0 || coluna > 2 || jogo[linha][coluna] != ' ');
		    
		    //Salvar cordenadas jogada
		    if(jogador == 1){
		      jogo[linha][coluna] = '0';
		      jogador++;
		    }
		    else{
		      jogo[linha][coluna] = 'X';
		      jogador = 1;
		    }
		    
		    //Alguém ganhou por linha
		    for(l = 0; l < 3; l++){
		      if(jogo[l][0] != ' ' && jogo[l][0] == jogo[l][1] && jogo[l][0] == jogo[l][2]){
		        printf("\nParabéns! O jogador %d venceu!\n", jogo[l][0] == '0' ? 1 : 2);
		        ganhou = 1;
		      }
		    }
		    
		    //Alguém ganhou por coluna
		    for(c = 0; c < 3; c++){
		      if(jogo[0][c] != ' ' && jogo[0][c] == jogo[1][c] && jogo[0][c] == jogo[2][c]){
		        printf("\nParabéns! O jogador %d venceu!\n", jogo[0][c] == '0' ? 1 : 2);
		        ganhou = 1;
		      }
		    }
		    
		    //Alguém ganhou diagonal principal
		    if(jogo[0][0] != ' ' && jogo[0][0] == jogo[1][1] && jogo[0][0] == jogo[2][2]){
		      printf("\nParabéns! O jogador %d venceu!\n", jogo[0][0] == '0' ? 1 : 2);
		      ganhou = 1;
		    }
		    
		    //Alguém ganhou diagonal secundária
		    if(jogo[0][2] != ' ' && jogo[0][2] == jogo[1][1] && jogo[0][2] == jogo[2][0]){
		      printf("\nParabéns! O jogador %d venceu!\n", jogo[0][2] == '0' ? 1 : 2);
		      ganhou = 1;
		    }
		  } while(ganhou == 0 && jogadas < 9);
		  
		  if(ganhou == 0) //se em 9 jogadas não tiver um vencedor, mensagem de jogo sem ganhador irá aparecer
		     printf("\nO jogo finalizou sem ganhador!\n"); 
		  
		  printf("\nDigite 1 para jogar novamente: ");
		  scanf("%d", &opcao);
		  
	    }while(opcao == 1); //caso o jogador digite 1, o jogo irá reiniciar
	  
	  return 0;
	}

