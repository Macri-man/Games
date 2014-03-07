// Created by ALexander Macri
//

#include <stdio.h>

typedef struct{
  int x;
  int y;
}pos;

typedef struct{
  pos* position;
  int lenPos;
  char xo;
  bool win;
}PlayerInfo;

typedef struct{
  char xo;
  int player;
}BoardInfo;

typedef struct{
	BoardInfo* board;
	int size;
	int numPlayer;
	int turn;
	PlayerInfo* players;
}GameInfo;

void readPos(GameInfo game){
	int row,column;
	game.players[turn%2].lenPos++;
	game.players[turn%2].position=realloc(game.players[turn%2].position,sizeof(game.players[turn%2].position)*game.players[turn%2].lenPos);
  do{
  	printf("What is your move? (row column)");
    scanf("%d %d",row,column);
  }while(game.size<row||row<1||game.size<column||column<1);
  game.board[row][column].xo=player.xo;
}

void initPlayer(GameInfo game){
	player.position=NULL;
	player.lenPos=0;
	do{
		printf("What Charactor do you want to be X or O ?");
		scanf("%c",player.xo);
	}while(player.xo!="x"||player.xo!="X"||player.xo!="o"||Player.xo!="O");
}

void initBoard(GameInfo game){
	int size;
	do{
		printf("How big is the grid? (input nummber)");
		scanf("%d",size);
	}while(size<=3);
	game.board[size][size];
	int i,j;
	for(i=0;i<size;i++){
		for(j=0;j<size,j++){
			board[i][j=" ";
		}
	}
}

void drawBoard(GameInfo game){
	int j=1,i=1;
	for(i;i<=3;i++){
		printf()
		for(j;j<=3;j++){
			
		}
	}
}

void initPlayers(GameInfo game){
	do{
		printf("How many players are playing?");
		scanf("%d",game.numPlayer)
	}while(game.numPlayer<1||game.numPlayer>2);
	game.players[game.numPlayer];
	if(game.numPlayer==1){
		initPlayer(game.players[0]);
	}else{
		initPlayer(game.players[0]);
		initPlayer(game.players[1]);
		game.turn=0;
	}
}

void AI(GameInfo game){
	
}

void 2play(GameInfo game){
	while(game.players[0].win==false||game.players[1].win==false){
  	drawBoard(game);
  	readPos(game);
  	game.turn++;
  }
  if(game.players[0].win==true){
  	printf("Player 1: WINS");
  }else{
  	printf("Player 2: WINS");
  }
}

void 1play(GameInfo game){
		while(game.players[0].win==false||game.players[1].win==false){
  	drawBoard(game);
  	readPos(game);
  	game.turn++;
  	if(turn%2==1){
  		AI(game);
  	}
  }
  if(game.players[0].win==true){
  	printf("Player 1: WINS");
  }else{
  	printf("Player 2: WINS");
  }
}

int main(int argc,const char** argv){
	printf("This is TicTocToe. You know the rules. Have fun.");
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
  		2play(game);
  		break;
  }
};
