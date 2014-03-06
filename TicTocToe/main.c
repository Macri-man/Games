// Created by ALexander Macri
//
//

#include <stdio.h>

typedef struct{
  int x;
  int y;
}pos;

typedef struct{
  pos* position;
  char xo;
}PlayerInfo;

typedef struct{
  char xo;
  int player;
}BoardInfo;



void readInput(PlayerInfo player){
	int row,column;
  do{
  	printf("What is your move? (row column)");
    scanf("%d %d",row,column);
  }while(row<1||row>3||column<1||column>3);
}


int main(int argc,const char** argv){
  
  BoardInfo* board[3][3];
  
  
};
