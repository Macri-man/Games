// Created by ALexander Macri

//includes
#include <stdio.h>
#include <stdlib.h>


//objects
typedef struct{
  int row;
  int column;
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

GameInfo game;

//function prototypes
void initBoard();
void readPos();
void initPlayers();
void initPlayer();
void drawBoard();
void drawHelper(char c, int i,int j);
int winCheck(char c);
int checkBounds(int row,int column);
int checkMove(int row,int column);
void AI();
void twoPlay();
void onePlay();

//function implementation
void initBoard(){
	do{
		fprintf(stdout,"How big is the grid? (input number)\n");
		scanf("%d",&game.size);
		fprintf(stdout,"size: %d\n",game.size);
	}while(game.size<3||game.size>3);
	game.board=malloc(sizeof(BoardInfo*)*game.size);
	int i,j;
	for(i=0;i<game.size;i++){
		game.board[i]=malloc(sizeof(BoardInfo)*game.size);
		for(j=0;j<game.size;j++){
			game.board[i][j].xo=' ';
		}
	}
	fprintf(stderr,"made board\n");
}

void initPlayers(){
	do{
		fprintf(stderr,"How many players are playing? (from 0 to 2 players allowed)\n");
		scanf("%d",&game.numPlayer);
		fprintf(stderr,"numplayer: %d\n",game.numPlayer);
	}while(game.numPlayer<0||game.numPlayer>2);
	game.p1.xo='X';
	game.p1.position=NULL;
	game.p1.lenPos=0;
	game.p1.win=0;
	game.p2.xo='O';
	game.p2.position=NULL;
	game.p2.lenPos=0;
	game.p2.win=0;
	switch(game.numPlayer){
		case 0:
			printf("Nothing to do!\n");
			break;
		case 1:
			printf("p1: %c p2: %c\n",game.p1.xo,game.p2.xo);
			break;
		case 2:
			printf("p1: %c p2: %c\n",game.p1.xo,game.p2.xo);
			break;
	}
}

void readMulPos(){
	int row,column;
  	do{
  		fprintf(stderr,"What is your move? (row column)\n");
    	scanf("%d %d",&row,&column);
  	}while(checkBounds(row,column)==0||checkMove(row,column)==0);
  	if(game.turn%2==0){
  		game.p1.lenPos++;
		game.p1.position=realloc(game.p1.position,sizeof(game.p1.position)*game.p1.lenPos);
  		game.board[row][column].xo=game.p1.xo;
  		game.p1.position.row=row;
  		game.p1.position.column=column;
  	}else{
  		game.p2.lenPos++;
		game.p2.position=realloc(game.p2.position,sizeof(game.p2.position)*game.p2.lenPos);
  		game.board[row][column].xo=game.p2.xo;
  		game.p2.position.row=row;
  		game.p2.position.column=column;
  	}
}

int checkBounds(int row,int column){
	return (game.size<row||row<0||game.size<column||column<0)?0:1;
}

int checkMove(int row,int column){
	return (game.board[row][column].xo==' ')?2:0;
}

int winCheck(char c){
	int i=(c==game.p1.xo)?1:2;
	if(c==game.board[0][0].xo&&c==game.board[0][1].xo&&c==game.board[0][2].xo)return i;
	if(c==game.board[1][0].xo&&c==game.board[1][1].xo&&c==game.board[1][2].xo)return i;
	if(c==game.board[2][0].xo&&c==game.board[2][1].xo&&c==game.board[2][2].xo)return i;
	if(c==game.board[0][0].xo&&c==game.board[1][0].xo&&c==game.board[2][0].xo)return i;
	if(c==game.board[0][1].xo&&c==game.board[1][1].xo&&c==game.board[2][1].xo)return i;
	if(c==game.board[0][2].xo&&c==game.board[1][2].xo&&c==game.board[2][2].xo)return i;
	if(c==game.board[0][0].xo&&c==game.board[1][1].xo&&c==game.board[2][2].xo)return i;
	if(c==game.board[0][2].xo&&c==game.board[1][1].xo&&c==game.board[2][0].xo)return i;
	return 0;
}

/*void drawBoard(){
fprintf(stderr,"draw board game size: %d\n",game.size);
	int j,i;
	for(i=0;i<game.size*2;i++){
		(i%2==0)?fprintf(stderr,"|"):fprintf(stderr,"-");
		for(j=0;j<game.size*2;j++){
			if(j%2==1){
				fprintf(stderr,"|");
			}else{
				fprintf(stderr,"%c",game.board[i/2][j/2].xo);
			}
		}
		fprintf(stderr,"\n");
	}
}*/

void drawBoard(){
	fprintf(stderr,"draw board game size: %d\n",game.size);
	drawHelper(' ',0,0);
	fprintf(stderr, "DONE!\n");
}

void drawHelper(char c,int i,int j){
	fprintf(stderr, "%c",c);
	if(i<(game.size*2)+1){
		if(j<((game.size*2)+1)){
			if(i%2==0){
				drawHelper('-',i,j+1);
			}else{
				if(j%2==0){
					drawHelper('|',i,j+1);
				}else{
					drawHelper(game.board[i/2][j/2].xo,i,j+1);
				}
			}
		}else{
			fprintf(stderr, "\n");
			drawHelper(' ',i+1,0);
		}
	}
}

void AI(){
	
}

void twoPlay(){
	fprintf(stderr,"play a game\n");
	while(game.p1.win!=1&&game.p2.win!=2){
  		drawBoard();
  		readMulPos();
  		game.p1.win=winCheck('X');
  		game.p2.win=winCheck('0');
  		fprintf(stderr, "%d\n",game.p1.win);
  		fprintf(stderr, "%d\n",game.p2.win);
  		game.turn++;
  	}
  	if(game.p1.win==1){
  		drawBoard();
  		fprintf(stderr,"Player 1: WINS\n");
  	}else{
  		drawBoard();
  		fprintf(stderr,"Player 2: WINS\n");
  	}
}

void onePlay(){
	fprintf(stderr,"play a game\n");
	while(game.p1.win!=1&&game.p2.win!=2){
  		drawBoard();
  		if(game.turn%2==0){
  			readMulPos();
  		}else{
  			AI();
  		}
  		game.p1.win=winCheck('X');
  		game.p2.win=winCheck('0');
  		fprintf(stderr, "%d\n",game.p1.win);
  		fprintf(stderr, "%d\n",game.p2.win);
  		game.turn++;
  		
  	}
  	if(game.p1.win==1){
  		drawBoard();
  		fprintf(stderr,"Player 1: WINS\n");
  	}else{
  		drawBoard();
  		fprintf(stderr,"Player 2: WINS\n");
  	}
}

int main(int argc,const char** argv){
  fprintf(stdout,"This is TicTocToe. You know the rules. Have fun.\n");

  initPlayers();
  initBoard();
  switch(game.numPlayer){
  	case 0:
  		fprintf(stdout,"need to impliment");
  		break;
  	case 1:
  		fprintf(stdout,"need  to implement");
  		break;
  	case 2:
  		twoPlay();
  		break;
  }
  return 0;
};
