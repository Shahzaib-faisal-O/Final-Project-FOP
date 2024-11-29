#include <stdio.h>
#include <stdlib.h>
#include <unistd.h> // using sleep mode like smooth rukh kay jo arhay hay input cool feature hay!Aatir
#include <string.h> // using getchar for wide spaces zaroori nahi hay
void displayScreen();// 1
void Gamestart(); // 2
void Showboard(int size ,int **board); // 3
void logic_of_game(int size,int **board,int **check); // 4
bool endgame(int size , int **board); // 5
bool win_condition(int size ,int **board ,int y,int x,int **check); // 6
bool valid_move(int size , int **board , int x , int y); // 7
 
bool computer = false;
bool computer_as_what = false; //false means eater true means passer // at what type computer play 
void displayScreen(){
	int choice;
	system("cls");
	printf(" \t\tPROJECT FOR FUNDAMENTAL OF PROGRAMING \n");
	printf("Enter the mode of the game : \n");
	printf("Press\n 1)Multiplayer \n 2)Player VS COMPUTER \n");
	scanf("%d",&choice);
	switch(choice){
		case 1:
			computer = false; // if the person choose multiplayer mode
			printf("%%%  Playing Multiplayer   %%%");
			break;
			case 2:
			computer = true; // we are going for the selection for computer
			printf("Select\n 1)Computer as EATER \n 2)Computer as PASSER \n");
			int secondchoice;
			scanf("%d",&secondchoice);
			if(secondchoice == 1){ // if and else for computer choices
				computer_as_what = false;
				printf("Computer has now become EATER");
			}else if(secondchoice == 2){
				printf("Computer has now become PASSER");
				computer_as_what = true;
			}else {
				printf("WRONG CHOICE RECONSIDER YOUR CHOICE \n");
			}
			break;
			default:
			printf("Invalid OPTION Contacting  developer(shahzaib.faisal) \nRestarting the game in 3 second \nPlz wait.......\n");
			sleep(2.9);
			printf("\nHI Thank you for contacting the Admin Don't worry the game will Restart\nSelect from the given option plz\n");
			sleep(3.3); // sleep for input second
			displayScreen(); // again call the function
	}
	printf("\nStarting your game in 5 second wait Plz \n");
	sleep (5.2);
	system("cls"); // clear the screen
	Gamestart(); //  
}
void Gamestart(){
	int size;
	printf("Enter the size of the Board :");
	scanf("%d",&size);
	
	int ** board = (int**)malloc(sizeof(int*)*size);
    for(int i=0; i<size; i++)
        *(board+i) = (int*)malloc(sizeof(int)*size);
        
        for(int i = 0 ; i<size ; i++){
		for(int j =0 ; j<size ; j++){
		board[i][j] = 0; // initillazing ALL the board with zero
		}
	}
	int ** check = (int**)malloc(sizeof(int*)*size);
    for(int i=0; i<size; i++)
        *(check+i) = (int*)malloc(sizeof(int)*size);
	for(int i = 0 ; i<size ; i++){
		for(int j =0 ; j<size ; j++){
			check[i][j] = 0;
		}
	}

	logic_of_game(size,board,check);
	Showboard(size , board);
}
void Showboard(int size ,int **board){ // all the property for the board kasa dhikay ga board
	printf("   ROW:COLUMN:");
	for(int i=0;i<size;i++){
		printf("   %d   ",i); // 
	}
	printf("\n");
	for(int i=0;i<size;i++){
		printf(" \t%d ",i); // row 
		for(int j=0;j<size;j++){
			switch(board[i][j]){ //value store in array of that point 
			case 0:
					printf(" \t|*| " ); //no value shows thisif zero // column
					break;
				case 1:
					printf("  |P|"); //if 1 update with p
					break;
				case 2:
					printf("  |E|"); //if 2 update with e
					break;	
			}
		}
		printf("\n"); //new line to show like matrix
	}
}
void logic_of_game(int size,int **board,int **check){// important
	bool end = false;
	int p_column,p_row,e_column,e_row,i;
//	using while loop 
while(!endgame(size,board)&& !end){
	Showboard(size,board); //call show board to displayboard
	// if computer is playing as Passer we are using randomize system
	if(computer && computer_as_what){
		while(true){
				p_column = (rand() % (size - 0 + 1)) + 0; //using random function
				p_row = (rand() % (size - 0 + 1)) + 0;
			if(p_column<size && p_row<size && board[p_column][p_row] == 0 ){
				printf("Computer move : Row:%d Column:%d" , p_row , p_column);
				break;
			}
		}
	}
	else{
		while(true){
				printf("Passer Enter Your move \n passer ROW:");
				scanf("%d" , &p_row);
				printf("passer Column:");
				scanf("%d",&p_column);
				if(p_column<size && p_row<size && board[p_row][p_column] == 0 ){
				break;
				}else{
					printf("Your move is  not valid!\n please Enter again");
				}
			}
	}
	// same condition for the Eater as about for passer 
		// if computer is playing as Eater we are using randomize system for the computer 
	if(computer && !computer_as_what){
			while(true){
				e_column = (rand() % (size - 0 + 1)) + 0;
				e_row = (rand() % (size - 0 + 1)) + 0;
			
			if( e_column<size && e_row<size && board[e_row][e_column] == 0 ){
				printf("Computer move : Row:%d Column:%d \n" , e_row , e_column);
				break;
			}
		}
			
		}
		// eater is playing as second player 
		else{
		
		while(true){
			printf("Eater enter move \nEater ROW:");
			scanf("%d" , &e_row);
			printf("eater Column:");
			scanf("%d" , &e_column);
			if( e_column<size && e_row<size && board[e_row][e_column] == 0 ){
				break;
			}else{
				printf("move not valid please enter again");
			}
		}
	}
	board[p_row][p_column] = 1; // on showboard uppdate the element for 1 |p|
	board[e_row][e_column] = 2; // for 2 |E|
	int i = 0 ;
		for(i = 0 ; i<size ; i++){
			if(win_condition(size , board , 0 ,i , check)){
				system("cls");
				Showboard(size,board);	
				printf("\n");
				Showboard(size,check);			
				printf("passer win\n enter any key to continue");
				getchar();
				getchar();
				end = true;
				displayScreen();	
			}
		}
		getchar();
		getchar();
		system("cls");	
	
}
}
bool endgame(int size , int **board){
	int i,j;
	for(int i =0 ; i<size ; i++){
		for(int j = 0 ; j<size ; j++){
			if(board[i][j] == 0){
				return false; // check the board is full or not 
			}
		}	
	}
	printf("Eater won\n");
	Showboard(size,board);
	getchar(); // use because to wait for the user to press any key and then display the menu 
	getchar();
	displayScreen();
	return true;
}

bool win_condition(int size ,int **board ,int y,int x,int **check){
	if(y == size-1 && board[y][x]==1){
		check[y][x] = 1;
	
		return true;
	}
	if(valid_move(size , board , y ,x)){
		if(check[y][x] == 1){
			return false;
		}
		check[y][x] = 1;
		
		if(win_condition(size,board, y+1 ,x ,check)){
			return true;
		}		
		if(win_condition(size,board,y+1,x+1,check)){
			return true;
		}		
		if(win_condition(size,board,y+1,x-1,check)){
			return true;
		}		
		
		check[y][x] = 0;
		return false;
	}
	return false;
}
bool valid_move(int size , int **board , int y , int x ){
	if(x < size && y < size && x >= 0 && y >= 0 && board[y][x] == 1 ){
	//		printf("valid move\n");
		return true;
	}
//	printf("not valid move\n");
	return false;
}
int main(){
  displayScreen();	
  return 0;
}
