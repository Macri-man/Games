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
	PlayerInfo p1;
	PlayerInfo p2;
}GameInfo;

//function prototypes
void initBoard(GameInfo game);
void readPos(GameInfo game);
void initPlayers(GameInfo game);
void initPlayer(PlayerInfo player);
void drawBoard(GameInfo game);
void AI(GameInfo game);
void twoPlay(GameInfo game);
void onePlay(GameInfo game);

//function implementation
void initBoard(GameInfo game){
	int size;
	do{
		fprintf(stdout,"How big is the grid? (input number)\n");
		size=fgetc(stdin);
		fprintf(stdout,"size: %d\n",size);
	}while(size<3);
	game.board=malloc(sizeof(BoardInfo*)*size);
	int i,j;
	for(i=0;i<size;i++){
		game.board[i]=malloc(sizeof(BoardInfo)*size);
		for(j=0;j<size;j++){
			game.board[i][j].xo=' ';
		}
	}
	fprintf(stdout,"made board\n");
}

void readPos(GameInfo game){
	int row,column;
	game.p1.lenPos++;
	game.p1.position=realloc(game.p1.position,sizeof(game.p1.position)*game.p1.lenPos);
  do{
  	printf("What is your move? (row enter column)\n");
    row=fgetc(stdin);
    column=fgetc(stdin);
  }while(game.size<row||row<1||game.size<column||column<1);
  game.board[row][column].xo=game.p1.xo;
}

void readMulPos(GameInfo game){
	int row,column;
	if(game.turn%2==0){
		game.p1.lenPos++;
		game.p1.position=realloc(game.p1.position,sizeof(game.p1.position)*game.p1.lenPos);
  }else{
  	game.p1.lenPos++;
		game.p1.position=realloc(game.p1.position,sizeof(game.p1.position)*game.p1.lenPos);
  }
  do{
  	printf("What is your move? (row column)\n");
    scanf("%d %d",&row,&column);
  }while(game.size<=row||row<1||game.size<=column||column<1);
  if(game.turn%2==0){
  	game.board[row][column].xo=game.p1.xo;
  }else{
  	game.board[row][column].xo=game.p2.xo;
  }
}

void initPlayers(GameInfo game){
	do{
		fprintf(stdout,"How many players are playing?\n");
		game.numPlayer=fgetc(stdin)-'0';
		printf("numplayer: %d\n",game.numPlayer);
		while(fgetc(stdin) != '\n'); 
	}while(game.numPlayer<0||game.numPlayer>2);
	switch(game.numPlayer){
		case 0:
			printf("Nothing to do!\n");
			break;
		case 1:
			game.p1.xo='X';
			game.p1.position=NULL;
			game.p1.lenPos=0;
			game.p2.xo='O';
			game.p2.position=NULL;
			game.p2.lenPos=0;
			printf("p1: %c p2: %c\n",game.p1.xo,game.p2.xo);
			break;
		case 2:
		fprintf(stdout,"numplayer: %d\n",game.numPlayer);
			game.p1.xo='X';
			game.p1.position=NULL;
			game.p1.lenPos=0;
			game.p1.win=1;
			game.p2.xo='O';
			game.p2.position=NULL;
			game.p2.lenPos=0;
			game.p2.win=1;
			printf("p1: %c p2: %c\n",game.p1.xo,game.p2.xo);
			break;
	}
}

void drawBoard(GameInfo game){
fprintf(stdout,"draw board\n");
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
printf("play a game\n");
	while(game.p1.win!=0||game.p2.win!=0){
  	drawBoard(game);
  	readMulPos(game);
  	game.turn++;
  }
  if(game.p1.win==0){
  	printf("Player 1: WINS\n");
  }else{
  	printf("Player 2: WINS\n");
  }
}

void onePlay(GameInfo game){
	while(game.p1.win!=0||game.p2.win!=0){
  	drawBoard(game);
  	readPos(game);
  	game.turn++;
  	if(game.turn%2==1){
  		AI(game);
  	}
  }
  if(game.p1.win==0){
  	printf("Player 1: WINS\n");
  }else{
  	printf("Player 2: WINS\n");
  }
}

int main(int argc,const char** argv){
	fprintf(stdout,"This is TicTocToe. You know the rules. Have fun.\n");
  GameInfo game;
  initPlayers(game);
  initBoard(game);
  switch(game.numPlayer){
  	case 0:
  		fprintf(stdout,"need to impliment");
  		break;
  	case 1:
  		fprintf(stdout,"need  to implement");
  		break;
  	case 2:
  		twoPlay(game);
  		break;
  }
  return 0;
};
