// Created by ALexander Macri

//includes
#include <stdio.h>
#include <stdlib.h>

//objects
typedef struct{
  int x;
  int y;
}pos;

typedef struct{
  pos* position;
  int lenPos;
  char xo;
  int win;
}PlayerInfo;

typedef struct{
  char xo;
  int player;
}BoardInfo;

typedef struct{
	BoardInfo** board;
	int size;
	int numPlayer;
	int turn;
	PlayerInfo* players;
}GameInfo;

//function prototypes
void initBoard(GameInfo game);
void readPos(GameInfo game);
void initPlayers(GameInfo game);
void initPlayer(GameInfo game);
void drawBoard(GameInfo game);
void AI(GameInfo game);
void twoPlay(GameInfo game);
void onePlay(GameInfo game);

//function implementation
void initBoard(GameInfo game){
	int size;
	do{
		printf("How big is the grid? (input nummber)\n");
		scanf("%d",&size);
	}while(size<=3);
	game.board=malloc(sizeof(BoardInfo*)*size);
	int i,j;
	for(i=0;i<size;i++){
		game.board[i]=malloc(sizeof(BoardInfo)*size);
		for(j=0;j<size;j++){
			game.board[i][j].xo=(char)' ';
		}
	}
}

void readPos(GameInfo game){
	int row,column;
	game.players[game.turn%2].lenPos++;
	game.players[game.turn%2].position=realloc(game.players[game.turn%2].position,sizeof(game.players[game.turn%2].position)*game.players[game.turn%2].lenPos);
  do{
  	printf("What is your move? (row column)\n");
    scanf("%d %d",&row,&column);
  }while(game.size<row||row<1||game.size<column||column<1);
  game.board[row][column].xo=game.players[game.turn%2].xo;
}

void initPlayers(GameInfo game){
	do{
		printf("How many players are playing?\n");
		scanf("%d",&game.numPlayer);
	}while(game.numPlayer<1||game.numPlayer>2);
	game.players=malloc(sizeof(PlayerInfo)*game.numPlayer);
	switch(game.numPlayer){
		case 0:
			printf("Nothing to do!\n");
			break;
		case 1:
			game.turn=0;
			initPlayer(game);
		case 2:
			game.turn=0;
			printf("%d\n",game.turn);
			initPlayer(game);
			game.turn++;
			printf("%d\n",game.turn);
			initPlayer(game);
			game.turn=0;
			break;
	}
}

void initPlayer(GameInfo game){
printf("INITPLAYERS\n");

	game.players[game.turn%2].position=NULL;
	game.players[game.turn%2].lenPos=0;
	do{
	printf("1:%d\n",game.turn%2);
	printf("2:%c\n",game.players[game.turn%2].xo);
		printf("What Charactor do you want to be X or O ?\n");
		scanf("%c",&game.players[game.turn%2].xo);
		printf("3:%d\n",game.turn%2);
	}while(game.players[game.turn%2].xo!='x'||game.players[game.turn%2].xo!='X'||game.players[game.turn%2].xo!='o'||game.players[game.turn%2].xo!='O');
}

void drawBoard(GameInfo game){
	int j,i;
	for(i=1;i<=game.size;i++){
		printf("%c | ",game.board[i][j].xo);
		for(j=1;j<=(game.size*2)-1;j++){
			if(j%2==1){
				printf("__");
			}else{
				printf("%c",game.board[i][j].xo);
			}
		}
	}
}

void AI(GameInfo game){
	
}

void twoPlay(GameInfo game){
	while(game.players[0].win==1||game.players[1].win==1){
  	drawBoard(game);
  	readPos(game);
  	game.turn++;
  }
  if(game.players[0].win==0){
  	printf("Player 1: WINS\n");
  }else{
  	printf("Player 2: WINS\n");
  }
}

void onePlay(GameInfo game){
		while(game.players[0].win==1||game.players[1].win==1){
  	drawBoard(game);
  	readPos(game);
  	game.turn++;
  	if(game.turn%2==1){
  		AI(game);
  	}
  }
  if(game.players[0].win==0){
  	printf("Player 1: WINS\n");
  }else{
  	printf("Player 2: WINS\n");
  }
}

int main(int argc,const char** argv){
	printf("This is TicTocToe. You know the rules. Have fun.\n");
  GameInfo game;
  initPlayers(game);
  initBoard(game);
  switch(game.numPlayer){
  	case 0:
  		printf("need to impliment");
  		break;
  	case 1:
  		printf("need  to implement");
  		break;
  	case 2:
  		twoPlay(game);
  		break;
  }
  return 0;
};
