#include <stdio.h>
#include <windows.h>
#include <conio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

const int GroundRows = 24;
const int GroundCols = 71;
char ground[GroundRows][GroundCols] = {
    {"######################################################################"},
    {"#                                                                    #"},
    {"#                                                        F           #"},
    {"#                         F  F  K                                    #"},
    {"#                      F                                             #"},
    {"#                                                                    #"},
    {"#                             *******                                #"},
    {"#                             *     *                                #"},
    {"#  F                          *     *                                #"},
    {"#                             *     *                                #"},
    {"#                             *     *                                #"},
    {"#                             *     *               F                #"},
    {"#                 F           *     *                                #"},
    {"#                             *******                                #"},
    {"#                                                                    #"},
    {"#                                                                    #"},
    {"#                                                                    #"},
    {"#                   F                      F                         #"},
    {"#                                                                    #"},
    {"#                                                                    #"},
    {"#                                                                    #"},
    {"#                                                                    #"},
    {"#                                                                    #"},
    {"######################################################################"} };
    
    
    char board[25][45]={
	{"-------------------------------------------"},
	{"|                                          |"},
	{"|                                          |"},
	{"|                                          |"},
	{"|                                          |"},
	{"|------------------------------------------|"},
	{"|                                          |"},
	{"|                                          |"},
	{"|------------------------------------------|"},
	{"|                                          |"},
	{"|                                          |"},
	{"|                                          |"},
	{"|                                          |"},
	{"|------------------------------------------|"},
	{"|                                          |"},
	{"|                                          |"},
	{"|                                          |"},
	{"|------------------------------------------|"},
	{"|                                          |"},
	{"|                                          |"},
	{"|                                          |"},
	{"|                                          |"},
	{"-------------------------------------------"},
};
//Global

int total_runs=0;
float overs=0;
int runs1=0;
int runs2=0;
int bowls1=0;
int bowls2=0;
int runs_bowler=0;
float bowler_overs=0;
int this_over[6]={0};
int on_strike=1;
int over_tracker=0;
int player_direction1=1;
int player_direction2=0;
int player1_xcoordinate=31;
int player1_ycoordinate=7;
int player2_xcoordinate=35;
int player2_ycoordinate=12;
int copy_player1=-1;
int copy_player2=-1;
int wickets_counter=0;
int bowler_wickets=0;
int innings_counter=1;
void gotoxy(short x, short y) {
    COORD jafar = { x,y };
    SetConsoleCursorPosition(
        GetStdHandle(STD_OUTPUT_HANDLE), jafar);
}
void printGround()
{
    for (int row = 0; row < 24; row = row + 1)
    {
        for (int col = 0; col < 71; col = col + 1)
        {
            printf("%c", ground[row][col]);
        }
        printf("\n");
    }
}
void printboard()
{
    for (int row = 0,next=1; row < 25; row = row + 1,next++)
    {
        for (int col = 0; col < 45; col = col + 1)
        {
            printf("%c", board[row][col]);
        }
        gotoxy(75,next);
       
    }
}

void remover_up(int x_coor,int y_coor)
{
	if(y_coor==12)
    {
    	return;
	}
	gotoxy(x_coor,++y_coor);
	printf(" ");

}
void remover_down(int x_coor,int y_coor)
{
	if(y_coor==7)
	{
		return;
	}
	gotoxy(x_coor,--y_coor);
	printf(" ");

}

int player_mover1(int x_coor,int y_coor)
{
	gotoxy(x_coor,y_coor);
	printf("P");	
	if(player_direction1==1)
	{
		y_coor++;
	}
	else if(player_direction1==0){
	y_coor--;
}
return y_coor;
}
int player_mover2(int x_coor,int y_coor)
{
	gotoxy(x_coor,y_coor);
	printf("P");	
	if(player_direction2==1)
	{
		y_coor++;
	}
	else if(player_direction2==0){
	y_coor--;
}
usleep(50000);
	return y_coor;
}
void next_over2()
{
	sleep(2);
	bowler_overs=0;
	runs_bowler=0;
	bowler_wickets=0;
	over_tracker=0;
	for(int i=100;i<111;i++)
	{
		gotoxy(i,20);
		printf(" ");
	}
	for(int i=87;i<110;i++)
	{
		gotoxy(i,15);
		printf(" ");
	}
	if(overs==1)
	{
	gotoxy(87,15);
	printf("H.Rauf : 0 -0 (0.0 )");
	}
	else if(overs==2)
	{
	 gotoxy(87,15);
	 printf("M.Nawaz:0 -0 (0.0 )");
	}
	else if(overs==3)
	{
	 gotoxy(87,15);
	 printf("S.Khan: 0 -0 (0.0 )");
	}
	else if(overs==4)
	{
	 gotoxy(87,15);
	 printf("N.Shah: 0 -0 (0.0 )");
	}
	else if(overs==5)
	{
	 gotoxy(87,15);
	 printf("H.Ali : 0 -0 (0.0 )");
	}
	if(on_strike==1)
	{
		on_strike=2;
	}
	else {
		on_strike=1;
	}
}
void next_over1()
{

	sleep(2);
	bowler_overs=0;
	runs_bowler=0;
	bowler_wickets=0;
	over_tracker=0;
	for(int i=100;i<111;i++)
	{
		gotoxy(i,20);
		printf(" ");
	}
	for(int i=87;i<110;i++)
	{
		gotoxy(i,15);
		printf(" ");
	}
	if(overs==1)
	{
	gotoxy(87,15);
	printf("C.Green: 0 -0 (0.0 )");
	}
	else if(overs==2)
	{
	 gotoxy(87,15);
	 printf("M.Zampa: 0 -0 (0.0 )");
	}
	else if(overs==3)
	{
	 gotoxy(87,15);
	 printf("M.Hazel :0 -0 (0.0 )");
	}
	else if(overs==4)
	{
	 gotoxy(87,15);
	 printf("S.Warne: 0 -0 (0.0 )");
	}
	else if(overs==5)
	{
	 gotoxy(87,15);
	 printf("G.Maxel: 0 -0 (0.0 )");
	}
	if(on_strike==1)
	{
		on_strike=2;
	}
	else {
		on_strike=1;
	}

}
void over_over()
{
	gotoxy(94,7);
	printf("   ");
	gotoxy(94,7);
	overs+=1;
    int over=overs;
    overs=over;
	printf("%.0f",overs);
	gotoxy(102,15);
	printf("    ");
	bowler_overs=6;
	gotoxy(104,15);
	printf("%.0f",bowler_overs);
	if(innings_counter==1)
	{
		next_over1();
	}
	else{
	next_over2();
}
}
void over_reseter()
{
	if(over_tracker<5)
	{
		over_tracker++;
	}
	else{
	for(int i=100;i<111;i=i+2){
		gotoxy(i,2);
		printf(" ");
	}
}
}
void printdata()
{
	gotoxy(82,2);
	printf("Pak  = 0 -0");
	gotoxy(87,7);
	printf("Overs= 0.0");
	gotoxy(82,11);
	printf("B.Azam: 0 (0 )");
	gotoxy(102,11);
	printf("M.Rizwan: 0 (0 )");
	gotoxy(87,15);
	printf("M.Starc: 0 -0 (0.0 )");
	gotoxy(87,20);
	printf("This Over: -");
}
int random(int upper, int lower)
{
    int num = (rand() % (upper - lower + 1)) + lower;
    return num;
}
void strike_presentator(){
	if(on_strike==1)
	{
		gotoxy(80,11);
		printf("*");
		gotoxy(100,11);
		printf(" ");
	}
	else if(on_strike==2)
	{
		gotoxy(100,11);
		printf("*");
		gotoxy(80,11);
		printf(" ");
	}
}
void scorecard_runner(int runs)
{

	total_runs+=runs;
	overs+=0.1;
	bowler_overs+=0.1;
	runs_bowler+=runs;
	gotoxy(89,2);
	printf("%d",total_runs);
	gotoxy(94,7);
	printf("%.1f",overs);
	gotoxy(96,15);
	printf("%d",runs_bowler);
	gotoxy(102,15);
	printf(" %.1f",bowler_overs);
	this_over[over_tracker]=runs;
	if(over_tracker==0)
	{
	gotoxy(100,20);
	printf("%d",this_over[over_tracker]);
	if(runs==0)
	{
		printf("\bW");
	}
}
else if(over_tracker==1)
{
	gotoxy(102,20);
	printf("%d",this_over[over_tracker]);
	if(runs==0)
	{
		printf("\bW");
	}
}
else if(over_tracker==2)
{
	gotoxy(104,20);
	printf("%d",this_over[over_tracker]);
	if(runs==0)
	{
		printf("\bW");
	}
}
else if(over_tracker==3)
{
	gotoxy(106,20);
	printf("%d",this_over[over_tracker]);
	if(runs==0)
	{
		printf("\bW");
	}
}
else if(over_tracker==4)
{
	gotoxy(108,20);
	printf("%d",this_over[over_tracker]);
	if(runs==0)
	{
		printf("\bW");
	}
}
else if(over_tracker==5)
{
	gotoxy(110,20);
	printf("%d",this_over[over_tracker]);
	if(runs==0)
	{
		printf("\bW");
	}
}

	if(on_strike==1)
	{
	runs1+=runs;
	bowls1+=1;
	if(runs==0)
	{
		bowls1==0;
	}
	gotoxy(90,11);
	printf("%d",runs1);
	gotoxy(93,11);
	printf("%d",bowls1);
}
else if(on_strike==2)
{
	runs2+=runs;
	bowls2+=1;
	if(runs==0)
	{
		bowls2=0;
	}
	gotoxy(112,11);
	printf("%d",runs2);
	gotoxy(115,11);
	printf("%d",bowls2);
}
over_reseter();
}
void Innings_reseter()
{
	gotoxy(80,2);
	printf("    ");
	gotoxy(82,2);
	printf("Aus");
	
	gotoxy(82,11);
	printf("Finch:  0 (0 )");
	gotoxy(102,11);
	printf("D.Warner: 0 (0 )");
	gotoxy(87,15);
	printf("S.Afridi:0 -0 (0.0 )");
	runs1=0;
    runs2=0;
    bowls1=0;
    bowls2=0;
    overs=0;
    total_runs=0;
    runs_bowler=0;
    bowler_overs=0;
    on_strike=1;
    over_tracker=0;
    wickets_counter=0;
    bowler_wickets=0;
}
void bowler()
{
	int bowler_y=18;
    int bowler_copy=-1;    
    gotoxy(31,7);
	printf("P");
	gotoxy(35,12);
	printf("P");
    while(bowler_y>13)
    {
    gotoxy(31,bowler_y);
    printf("B");
    gotoxy(31,bowler_copy);
    printf(" ");
    usleep(300000);
    bowler_copy=bowler_y;
	bowler_y--;	
	}
	gotoxy(31,++bowler_y);
    printf(" ");
    
}

int straight_fielder1(int fielder_x,int fielder_y)
{
	
	gotoxy(fielder_x,fielder_y);
	printf("F");
	printf(" ");
	return --fielder_x;
}
int straight_fielder2(int fielder_x,int fielder_y)
{
	gotoxy(fielder_x,fielder_y);
	printf(" ");
	printf("F");
	
	return ++fielder_x;
}
void wickets2()
{
	gotoxy(92,2);
	printf("%d",wickets_counter);
	gotoxy(31,7);
	printf("P");
	gotoxy(35,12);
	printf("P");
	if(on_strike==1)
	{
		for(int i=82;i<96;i++)
		{
			gotoxy(i,11);
			printf(" ");
		}
		gotoxy(82,11);
       if(wickets_counter==1)
	   {
	   	printf("S.Smith 0 (0 )");
		   }	
	  else if(wickets_counter==2)
	  {
	  	printf("M.Wade  0 (0 )");
	  }
	  else if(wickets_counter==3)
	  {
	  	printf("S.Marsh 0 (0 )");
	  }
	  else if(wickets_counter==4)
	  {
	  	printf("M.Marsh 0 (0 )");
	  }
	  else if(wickets_counter==5)
	  {
	  	printf("T.Head  0 (0 )");
	  }
	  else if(wickets_counter==6)
	  {
	  	printf("M.Stoni 0 (0 )");
	  }
	  else if(wickets_counter==7)
	  {
	  	printf("J.Agar  0 (0 )");
	  }
	  else if(wickets_counter==8)
	  {
	  	printf("M.Starc 0 (0 )");
	  }
	  else if(wickets_counter==9)
	  {
	  	printf("J.Hazel 0 (0 )");
	  }
	  bowls1--;
	  runs1=0;
	}
	
	if(on_strike==2)
	{
		for(int i=102;i<116;i++)
		{
			gotoxy(i,11);
			printf(" ");
		}
		gotoxy(102,11);
       if(wickets_counter==1)
	   {
	   	printf("S.Smith: 0 (0 )");
		   }	
	  else if(wickets_counter==2)
	  {
	  	printf("M.Wade  : 0 (0 )");
	  }
	  else if(wickets_counter==3)
	  {
	  	printf("S.Marsh:  0 (0 )");
	  }
	  else if(wickets_counter==4)
	  {
	  	printf("M.Marsh:  0 (0 )");
	  }
	  else if(wickets_counter==5)
	  {
	  	printf("T.Head:   0 (0 )");
	  }
	  else if(wickets_counter==6)
	  {
	  	printf("M.Stoni:  0 (0 )");
	  }
	  else if(wickets_counter==7)
	  {
	  	printf("J.Agar:   0 (0 )");
	  }
	  else if(wickets_counter==8)
	  {
	  	printf("M.Starc:  0 (0 )");
	  }
	  else if(wickets_counter==9)
	  {
	  	printf("J.Hazel:  0 (0 )");
	  }
	  bowls2--;
	  runs2=0;
	}
	bowler_wickets++;
	gotoxy(99,15);
	printf("%d",bowler_wickets);
	scorecard_runner(0);
}
void wickets()
{
	gotoxy(92,2);
	printf("%d",wickets_counter);
	gotoxy(31,7);
	printf("P");
	gotoxy(35,12);
	printf("P");
	if(on_strike==1)
	{
		for(int i=82;i<96;i++)
		{
			gotoxy(i,11);
			printf(" ");
		}
		gotoxy(82,11);
       if(wickets_counter==1)
	   {
	   	printf("H.Ali   0 (0 )");
		   }	
	  else if(wickets_counter==2)
	  {
	  	printf("S.Masod 0 (0 )");
	  }
	  else if(wickets_counter==3)
	  {
	  	printf("S.Malik 0 (0 )");
	  }
	  else if(wickets_counter==4)
	  {
	  	printf("M.hafez 0 (0 )");
	  }
	  else if(wickets_counter==5)
	  {
	  	printf("S.kahn  0 (0 )");
	  }
	  else if(wickets_counter==6)
	  {
	  	printf("A.Ali   0 (0 )");
	  }
	  else if(wickets_counter==7)
	  {
	  	printf("M.Wasim 0 (0 )");
	  }
	  else if(wickets_counter==8)
	  {
	  	printf("N.Shah  0 (0 )");
	  }
	  else if(wickets_counter==9)
	  {
	  	printf("H.Ali   0 (0 )");
	  }
	  bowls1--;
	  runs1=0;
	}
	
	if(on_strike==2)
	{
		for(int i=102;i<116;i++)
		{
			gotoxy(i,11);
			printf(" ");
		}
		gotoxy(102,11);
       if(wickets_counter==1)
	   {
	   	printf("H.Ali     0 (0 )");
		   }	
	  else if(wickets_counter==2)
	  {
	  	printf("S.Masod   0 (0 )");
	  }
	  else if(wickets_counter==3)
	  {
	  	printf("S.Malik   0 (0 )");
	  }
	  else if(wickets_counter==4)
	  {
	  	printf("M.Hafez   0 (0 )");
	  }
	  else if(wickets_counter==5)
	  {
	  	printf("S.kahn    0 (0 )");
	  }
	  else if(wickets_counter==6)
	  {
	  	printf("A.Ali     0 (0 )");
	  }
	  else if(wickets_counter==7)
	  {
	  	printf("I.Wasim   0 (0 )");
	  }
	  else if(wickets_counter==8)
	  {
	  	printf("N.Shah    0 (0 )");
	  }
	  else if(wickets_counter==9)
	  {
	  	printf("H.Ali     0 (0 )");
	  }
	  bowls2--;
	  runs2=0;
	}
	bowler_wickets++;
	gotoxy(99,15);
	printf("%d",bowler_wickets);
	scorecard_runner(0);
}
int leg_fielder1(int fielder_x,int fielder_y)
{
	gotoxy(fielder_x,fielder_y);
	printf("F");
	printf(" ");
	return --fielder_y;
}
int leg_fielder2(int fielder_x,int fielder_y)
{
	gotoxy(fielder_x,fielder_y);
	printf("F");
	printf(" ");
	return ++fielder_y;
}
void straight_one(int x_coor,int y_coor)
{
	player_direction1=1;
    player_direction2=0;
	player1_ycoordinate=7;
	player2_ycoordinate=12;
	int copy_x=-1;
	int copy_y=-1;
	gotoxy(32,3);
	printf(" ");
	gotoxy(32,5);
	printf("K");
	while(y_coor<18)
	{
		copy_x=x_coor;
			copy_y=y_coor;
			gotoxy(x_coor,y_coor);
			printf("O");
			gotoxy(20,17);
	        printf(" ");
			player1_ycoordinate=player_mover1(player1_xcoordinate,player1_ycoordinate);
			player2_ycoordinate=player_mover2(player2_xcoordinate,player2_ycoordinate);
			if(player_direction2==0)
			{
			copy_player2=player2_ycoordinate+1;
			remover_up(player2_xcoordinate,copy_player2);
		}
		
		else if(player_direction2==1)
		{
			copy_player2=player2_ycoordinate-1;
			remover_down(player2_xcoordinate,copy_player2);
		}
			if(player2_ycoordinate==12)
			{
				player_direction2=0;
			}
			else if(player2_ycoordinate==7)
			{
				player_direction2=1;
			}
		
		if(player_direction1==0)
			{
			copy_player1=player1_ycoordinate+1;
			remover_up(player1_xcoordinate,copy_player1);
		}
		else if(player_direction1==1)
		{ 
			copy_player1=player1_ycoordinate-1;
			remover_down(player1_xcoordinate,copy_player1);
		 }
			if(player1_ycoordinate==12)
			{
				player_direction1=0;
			}
			else if(player1_ycoordinate==7)
			{
				player_direction1=1;
			}
	
	        gotoxy(25,17);
	        printf("F");
			usleep(350000);
			gotoxy(copy_x,copy_y);
			printf(" ");
			x_coor-=1;
			y_coor++;
	}
	gotoxy(31,11);
	printf(" ");
	gotoxy(31,10);
	printf(" ");
	gotoxy(35,12);
	printf("P");
	gotoxy(35,9);
	printf(" ");
	gotoxy(31,7);
	printf("P");
	y_coor--;
		while(y_coor>7)
	{
		copy_x=x_coor;
			copy_y=y_coor;
			gotoxy(x_coor,y_coor);
			printf("O");
			usleep(350000);
			gotoxy(copy_x,copy_y);
			printf(" ");
			y_coor--;
	}
		
	player1_ycoordinate=7;
	player2_ycoordinate=12;
	gotoxy(29,7);
	printf("O");
	usleep(100000);
	gotoxy(29,7);
	printf(" ");
	gotoxy(23,17);
	printf("F");
	gotoxy(25,17);
	printf(" ");
	gotoxy(32,5);
	printf(" ");
	gotoxy(32,3);
	printf("K");
	player_direction1=1;
    player_direction2=0;
	player1_ycoordinate=7;
	player2_ycoordinate=12;
	scorecard_runner(1);
	if(on_strike==1)
	{
		on_strike=2;
	}
	else if(on_strike==2)
	{
		on_strike=1;
	}
}

void straight_four(int x_coor,int y_coor)
{
	int copy_x=-1;
	int copy_y=-1;
	int fielder1_x=43;
	int fielder2_x=20;
	int fielder_y=17;
	player_direction1=1;
    player_direction2=0;
	gotoxy(32,3);
	printf(" ");
	gotoxy(32,5);
	printf("K");
	while(y_coor<23)
	{
		copy_x=x_coor;
			copy_y=y_coor;
			gotoxy(x_coor,y_coor);
			printf("O");
			fielder1_x=straight_fielder1(fielder1_x,fielder_y);
			fielder2_x=straight_fielder2(fielder2_x,fielder_y);
			player1_ycoordinate=player_mover1(player1_xcoordinate,player1_ycoordinate);
			player2_ycoordinate=player_mover2(player2_xcoordinate,player2_ycoordinate);
		
		
			if(player_direction2==0)
			{
			copy_player2=player2_ycoordinate+1;
			remover_up(player2_xcoordinate,copy_player2);
		}
		else if(player_direction2==1)
		{
			copy_player2=player2_ycoordinate-1;
			remover_down(player2_xcoordinate,copy_player2);
		}
			if(player2_ycoordinate==12)
			{
				player_direction2=0;
			}
			else if(player2_ycoordinate==7)
			{
				player_direction2=1;
			}
		
		if(player_direction1==0)
			{
			copy_player1=player1_ycoordinate+1;
			remover_up(player1_xcoordinate,copy_player1);
		}
		else if(player_direction1==1)
		{
			copy_player1=player1_ycoordinate-1;
			remover_down(player1_xcoordinate,copy_player1);
		}
			if(player1_ycoordinate==12)
			{
				player_direction1=0;
			}
			else if(player1_ycoordinate==7)
			{
				player_direction1=1;
			}
			usleep(300000);
			gotoxy(copy_x,copy_y);
			printf(" ");
			y_coor++;
	}
	gotoxy(++fielder1_x,fielder_y);
	printf(" ");
	gotoxy(fielder2_x,fielder_y);
	player1_ycoordinate=7;
	player2_ycoordinate=12;
	printf(" ");
	gotoxy(43,17);
	printf("F");
	gotoxy(20,17);
	printf("F");
	gotoxy(31,9);
	printf(" ");
	gotoxy(35,12);
	printf("P");
	gotoxy(35,10);
	printf(" ");
	gotoxy(31,7);
	printf("P");
	gotoxy(32,3);
	printf("K");
	gotoxy(32,5);
	printf(" ");
	scorecard_runner(4);
}
int off_fielder(int fielder_x,int fielder_y)
{
	gotoxy(fielder_x,fielder_y);
	printf("F");
	printf(" ");
	return --fielder_y;
}
void leg_two(int x_coor,int y_coor)
{
	
    player_direction1=1;
    player_direction2=0;
	player1_ycoordinate=7;
	player2_ycoordinate=12;
	int copy_x=-1;
	int copy_y=-1;
	gotoxy(32,3);
	printf(" ");
	gotoxy(32,5);
	printf("K");
	gotoxy(57,2);
	printf(" ");
	while(y_coor>2)
	{
		copy_x=x_coor;
			copy_y=y_coor;
			gotoxy(x_coor,y_coor);
			printf("O");
            
			player1_ycoordinate=player_mover1(player1_xcoordinate,player1_ycoordinate);
			player2_ycoordinate=player_mover2(player2_xcoordinate,player2_ycoordinate);
			if(player_direction2==0)
			{
			copy_player2=player2_ycoordinate+1;
			remover_up(player2_xcoordinate,copy_player2);
		}
		
		else if(player_direction2==1)
		{
			copy_player2=player2_ycoordinate-1;
			remover_down(player2_xcoordinate,copy_player2);
		}
			if(player2_ycoordinate==12)
			{
				player_direction2=0;
			}
			else if(player2_ycoordinate==7)
			{
				player_direction2=1;
			}
		
		if(player_direction1==0)
			{
			copy_player1=player1_ycoordinate+1;
			remover_up(player1_xcoordinate,copy_player1);
		}
		else if(player_direction1==1)
		{ 
			copy_player1=player1_ycoordinate-1;
			remover_down(player1_xcoordinate,copy_player1);
		 }
			if(player1_ycoordinate==12)
			{
				player_direction1=0;
			}
			else if(player1_ycoordinate==7)
			{
				player_direction1=1;
			}
	        gotoxy(50,2);
	        printf("F");
			usleep(700000);
			gotoxy(copy_x,copy_y);
			printf(" ");
			
			x_coor+=3;
			y_coor--;
	}
	gotoxy(31,11);
	printf(" ");
	gotoxy(31,7);
	printf("P");
	gotoxy(35,12);
	printf("P");
	gotoxy(35,8);
	printf(" ");
	x_coor-=2;
	y_coor++;
	
		while(y_coor<7)
	{
		copy_x=x_coor;
			copy_y=y_coor;
			gotoxy(x_coor,y_coor);
			printf("O");
			usleep(700000);
			gotoxy(copy_x,copy_y);
			printf(" ");
			x_coor-=4;
			y_coor++;
			gotoxy(31,7);
			printf(" ");
			gotoxy(35,12);
			printf(" ");
			gotoxy(31,9);
			printf("P");
			gotoxy(35,10);
			printf("P");
			gotoxy(31,9);
			printf(" ");
			gotoxy(31,7);
			printf("P");
			gotoxy(35,10);
			printf(" ");
			gotoxy(35,12);
			printf("P");
	}
	gotoxy(57,2);
	printf("F");
	gotoxy(50,2);
	printf(" ");
	gotoxy(32,5);
	printf(" ");
	gotoxy(32,3);
	printf("K");
	gotoxy(31,11);
	printf(" ");
	gotoxy(31,7);
	printf("P");
	gotoxy(35,8);
	printf(" ");
	gotoxy(35,12);
	printf("P");
	player_direction1=1;
    player_direction2=0;
	player1_ycoordinate=7;
	player2_ycoordinate=12;
	scorecard_runner(2);
}
void off_two(int x_coor,int y_coor)
{
    player_direction1=1;
    player_direction2=0;
	player1_ycoordinate=7;
	player2_ycoordinate=12;
	int counter=0;
	int copy_x=-1;
	int copy_y=-1;
	gotoxy(32,3);
	printf(" ");
	gotoxy(32,5);
	printf("K");
	while(x_coor>4)
	{
		copy_x=x_coor;
			copy_y=y_coor;
			gotoxy(x_coor,y_coor);
			printf("O");
			gotoxy(3,8);
	        printf(" ");
            if(counter==2)
            {
            	gotoxy(31,11);
            	printf(" ");
            	gotoxy(31,7);
            	printf("P");
            	gotoxy(35,8);
            	printf(" ");
            	gotoxy(35,12);
            	printf("P");
            	goto label;
			}
			player1_ycoordinate=player_mover1(player1_xcoordinate,player1_ycoordinate);
			player2_ycoordinate=player_mover2(player2_xcoordinate,player2_ycoordinate);
			if(player_direction2==0)
			{
			copy_player2=player2_ycoordinate+1;
			remover_up(player2_xcoordinate,copy_player2);
		}
		
		else if(player_direction2==1)
		{
			copy_player2=player2_ycoordinate-1;
			remover_down(player2_xcoordinate,copy_player2);
		}
			if(player2_ycoordinate==12)
			{
				player_direction2=0;
			}
			else if(player2_ycoordinate==7)
			{
				player_direction2=1;
			}
		
		if(player_direction1==0)
			{
			copy_player1=player1_ycoordinate+1;
			remover_up(player1_xcoordinate,copy_player1);
		}
		else if(player_direction1==1)
		{ 
			copy_player1=player1_ycoordinate-1;
			remover_down(player1_xcoordinate,copy_player1);
		 }
			if(player1_ycoordinate==12)
			{
				player_direction1=0;
				counter++;
			}
			else if(player1_ycoordinate==7)
			{
				player_direction1=1;
			}
			label:
	        gotoxy(3,6);
	        printf("F");
			usleep(350000);
			gotoxy(copy_x,copy_y);
			printf(" ");
			x_coor-=1;
	}
	gotoxy(31,8);
	printf(" ");
	gotoxy(31,7);
	printf("P");
	gotoxy(35,12);
	printf("P");
	gotoxy(35,11);
	printf(" ");
	y_coor--;
		while(x_coor<29)
	{
		copy_x=x_coor;
			copy_y=y_coor;
			gotoxy(x_coor,y_coor);
			printf("O");
			usleep(350000);
			gotoxy(copy_x,copy_y);
			printf(" ");
			x_coor+=1;
	}
	gotoxy(32,5);
	printf(" ");
	gotoxy(32,3);
	printf("K");
	player_direction1=1;
    player_direction2=0;
	player1_ycoordinate=7;
	player2_ycoordinate=12;
	scorecard_runner(2);
}	

void off_six(int x_coor,int y_coor)
{
	gotoxy(31,7);
	printf("P");
	player_direction1=1;
    player_direction2=0;
	gotoxy(35,12);
	printf("P");
	int copy_x=-1;
	int copy_y=-1;
	while(x_coor>1)
	{
		copy_x=x_coor;
			copy_y=y_coor;
			gotoxy(x_coor,y_coor);
			printf("O");
			usleep(200000);
			gotoxy(copy_x,copy_y);
			printf(" ");
			x_coor--;
	}
	scorecard_runner(6);
}
void off_one(int x_coor,int y_coor)
{
	player_direction1=1;
    player_direction2=0;
	player1_ycoordinate=7;
	player2_ycoordinate=12;
	int copy_x=-1;
	int copy_y=-1;
	gotoxy(32,3);
	printf(" ");
	gotoxy(32,5);
	printf("K");
	while(x_coor>4)
	{
		copy_x=x_coor;
			copy_y=y_coor;
			gotoxy(x_coor,y_coor);
			printf("O");
	        if(player1_ycoordinate==12)
	        {
	        	gotoxy(31,11);
	        	printf(" ");
	        	gotoxy(31,7);
	        	printf("P");
	        	gotoxy(35,8);
	        	printf(" ");
	        	gotoxy(35,12);
	        	printf("P");
	        	goto label;
			}
			player1_ycoordinate=player_mover1(player1_xcoordinate,player1_ycoordinate);
			player2_ycoordinate=player_mover2(player2_xcoordinate,player2_ycoordinate);
			if(player_direction2==0)
			{
			copy_player2=player2_ycoordinate+1;
			remover_up(player2_xcoordinate,copy_player2);
		}
		
		else if(player_direction2==1)
		{
			copy_player2=player2_ycoordinate-1;
			remover_down(player2_xcoordinate,copy_player2);
		}
			if(player2_ycoordinate==12)
			{
				player_direction2=0;
			}
			else if(player2_ycoordinate==7)
			{
				player_direction2=1;
			}
		
		if(player_direction1==0)
			{
			copy_player1=player1_ycoordinate+1;
			remover_up(player1_xcoordinate,copy_player1);
		}
		else if(player_direction1==1)
		{ 
			copy_player1=player1_ycoordinate-1;
			remover_down(player1_xcoordinate,copy_player1);
		 }
			if(player1_ycoordinate==12)
			{
				player_direction1=0;
			}
			else if(player1_ycoordinate==7)
			{
				player_direction1=1;
			}
	        label:
			usleep(100000);
			gotoxy(copy_x,copy_y);
			printf(" ");
			x_coor-=1;
	}
	
	y_coor--;
		while(x_coor<29)
	{
		copy_x=x_coor;
			copy_y=y_coor;
			gotoxy(x_coor,y_coor);
			printf("O");
			usleep(350000);
			gotoxy(copy_x,copy_y);
			printf(" ");
			x_coor++;
	}
		
	player1_ycoordinate=7;
	player2_ycoordinate=12;
	gotoxy(29,7);
	printf("O");
	usleep(100000);
	gotoxy(29,7);
	printf(" ");
	gotoxy(32,5);
	printf(" ");
	gotoxy(32,3);
	printf("K");
	player_direction1=1;
    player_direction2=0;
	player1_ycoordinate=7;
	player2_ycoordinate=12;
	scorecard_runner(1);
	if(on_strike==1)
	{
		on_strike=2;
	}
	else if(on_strike==2)
	{
		on_strike=1;
	}
}
void off_four(int x_coor,int y_coor)
{
	player1_ycoordinate=7;
	player2_ycoordinate=12;
	player_direction1=1;
    player_direction2=0;
	int copy_x=-1;
	int copy_y=-1;
	int fielder1_x=4;
	int fielder_y=12;
	gotoxy(3,8);
	printf(" ");
	int copy_fielder=6;
	gotoxy(32,3);
	printf(" ");
	gotoxy(32,5);
	printf("K");
	while(x_coor>0)
	{
		copy_x=x_coor;
			copy_y=y_coor;
			gotoxy(x_coor,y_coor);
			printf("O");
			if(fielder_y>4)
			{
			fielder_y=off_fielder(fielder1_x,fielder_y);
		}
		else{
			gotoxy(3,7);
			printf("F");
		}
			player1_ycoordinate=player_mover1(player1_xcoordinate,player1_ycoordinate);
			player2_ycoordinate=player_mover2(player2_xcoordinate,player2_ycoordinate);
		
		
			if(player_direction2==0)
			{
			copy_player2=player2_ycoordinate+1;
			remover_up(player2_xcoordinate,copy_player2);
		}
		else if(player_direction2==1)
		{
			copy_player2=player2_ycoordinate-1;
			remover_down(player2_xcoordinate,copy_player2);
		}
			if(player2_ycoordinate==12)
			{
				player_direction2=0;
			}
			else if(player2_ycoordinate==7)
			{
				player_direction2=1;
			}
		
		if(player_direction1==0)
			{
			copy_player1=player1_ycoordinate+1;
			remover_up(player1_xcoordinate,copy_player1);
		}
		else if(player_direction1==1)
		{
			copy_player1=player1_ycoordinate-1;
			remover_down(player1_xcoordinate,copy_player1);
		}
			if(player1_ycoordinate==12)
			{
				player_direction1=0;
			}
			else if(player1_ycoordinate==7)
			{
				player_direction1=1;
			}
			usleep(300000);
			gotoxy(copy_x,copy_y);
			printf(" ");
			copy_fielder=fielder_y;
		    gotoxy(fielder1_x,++copy_fielder);
		    printf(" ");
			x_coor--;
			if(x_coor==20)
			{
			y_coor--;
		}
	}
	gotoxy(3,7);
	printf(" ");
	player1_ycoordinate=7;
	player2_ycoordinate=12;
	gotoxy(31,9);
	printf(" ");
	gotoxy(35,12);
	printf("P");
	gotoxy(35,10);
	printf(" ");
	gotoxy(31,7);
	printf("P");
	gotoxy(32,3);
	printf("K");
	gotoxy(32,5);
	printf(" ");
	scorecard_runner(4);
}
void leg_six(int x_coor,int y_coor)
{
	player_direction1=1;
    player_direction2=0;
gotoxy(31,7);
	printf("P");
	gotoxy(35,12);
	printf("P");
	int copy_x=-1;
	int copy_y=-1;
	while(x_coor<68)
	{
		copy_x=x_coor;
			copy_y=y_coor;
			gotoxy(x_coor,y_coor);
			printf("O");
			usleep(200000);
			gotoxy(copy_x,copy_y);
			printf(" ");
			x_coor++;
	}
	scorecard_runner(6);	
}
void leg_four(int x_coor,int y_coor)
{
	int copy_x=-1;
	int copy_y=-1;
	int fielder_x=58;
	int fielder1_y=12;
	int fielder2_y=2;
	int copy_fielder1=12;
	int copy_fielder2=2;
	player_direction1=1;
    player_direction2=0;
	gotoxy(32,3);
	printf(" ");
	gotoxy(32,5);
	printf("K");
	gotoxy(57,2);
	printf(" ");
	gotoxy(52,11);
	printf(" ");
	while(x_coor!=68)
	{
		copy_x=x_coor;
			copy_y=y_coor;
			gotoxy(x_coor,y_coor);
			printf("O");
			if(fielder1_y>7 && fielder2_y<5)
			{
             //usleep(250000);
			fielder1_y=leg_fielder1(fielder_x,fielder1_y);
			fielder2_y=leg_fielder2(fielder_x,fielder2_y);
		}else {
			gotoxy(58,4);
			printf("F");
			gotoxy(58,10);
			printf("F");
		}
			player1_ycoordinate=player_mover1(player1_xcoordinate,player1_ycoordinate);
			player2_ycoordinate=player_mover2(player2_xcoordinate,player2_ycoordinate);
		    copy_fielder1=fielder1_y;
		    copy_fielder2=fielder2_y;
		
			if(player_direction2==0)
			{
			copy_player2=player2_ycoordinate+1;
			remover_up(player2_xcoordinate,copy_player2);
		}
		else if(player_direction2==1)
		{
			copy_player2=player2_ycoordinate-1;
			remover_down(player2_xcoordinate,copy_player2);
		}
			if(player2_ycoordinate==12)
			{
				player_direction2=0;
			}
			else if(player2_ycoordinate==7)
			{
				player_direction2=1;
			}
		
		if(player_direction1==0)
			{
			copy_player1=player1_ycoordinate+1;
			remover_up(player1_xcoordinate,copy_player1);
		}
		else if(player_direction1==1)
		{
			copy_player1=player1_ycoordinate-1;
			remover_down(player1_xcoordinate,copy_player1);
		}
			if(player1_ycoordinate==12)
			{
				player_direction1=0;
			}
			else if(player1_ycoordinate==7)
			{
				player_direction1=1;
			}

			usleep(100000);
			gotoxy(copy_x,copy_y);
			printf(" ");
			gotoxy(fielder_x,++copy_fielder1);
			printf(" ");
			gotoxy(fielder_x,--copy_fielder2);
			printf(" ");
			x_coor++;
	}
	gotoxy(fielder_x,++fielder1_y);
	printf(" ");
	gotoxy(fielder_x,fielder2_y);
	printf(" ");
	gotoxy(57,2);
	printf("F");
	gotoxy(52,11);
	printf("F");
	player1_ycoordinate=7;
	player2_ycoordinate=12;
	gotoxy(31,7);
	printf("P");
	gotoxy(35,12);
	printf("P");
	gotoxy(31,8);
	printf(" ");
	gotoxy(35,11);
	printf(" ");
	gotoxy(32,3);
	printf("K");
	gotoxy(32,5);
	printf(" ");
	scorecard_runner(4);
}
void leg_one(int x_coor,int y_coor)
{
	int fielder=11;
	int copy_fielder=11;
	player_direction1=1;
    player_direction2=0;
	player1_ycoordinate=7;
	player2_ycoordinate=12;
	int copy_x=-1;
	int copy_y=-1;
	gotoxy(32,3);
	printf(" ");
	gotoxy(32,5);
	printf("K");
	while(x_coor<52)
	{
		copy_x=x_coor;
			copy_y=y_coor;
			gotoxy(x_coor,y_coor);
			printf("O");
	        if(player1_ycoordinate==12)
	        {
	        	gotoxy(31,11);
	        	printf(" ");
	        	gotoxy(35,8);
	        	printf(" ");
	        	gotoxy(31,7);
	        	printf("P");
	        	gotoxy(35,12);
	        	printf("P");
	        	goto label;
			}
			player1_ycoordinate=player_mover1(player1_xcoordinate,player1_ycoordinate);
			player2_ycoordinate=player_mover2(player2_xcoordinate,player2_ycoordinate);
			if(player_direction2==0)
			{
			copy_player2=player2_ycoordinate+1;
			remover_up(player2_xcoordinate,copy_player2);
		}
		
		else if(player_direction2==1)
		{
			copy_player2=player2_ycoordinate-1;
			remover_down(player2_xcoordinate,copy_player2);
		}
			if(player2_ycoordinate==12)
			{
				player_direction2=0;
			}
			else if(player2_ycoordinate==7)
			{
				player_direction2=1;
			}
		
		if(player_direction1==0)
			{
			copy_player1=player1_ycoordinate+1;
			remover_up(player1_xcoordinate,copy_player1);
		}
		else if(player_direction1==1)
		{ 
			copy_player1=player1_ycoordinate-1;
			remover_down(player1_xcoordinate,copy_player1);
		 }
			if(player1_ycoordinate==12)
			{
				player_direction1=0;
			}
			else if(player1_ycoordinate==7)
			{
				player_direction1=1;
			}
	        label:
	        gotoxy(52,fielder);
	        printf("F");
			usleep(300000);
			gotoxy(copy_x,copy_y);
			printf(" ");
			x_coor+=1;
			if(fielder>7)
			{
			copy_fielder=fielder;
			gotoxy(52,copy_fielder);
			printf(" ");
		}
			if(fielder>7)
			{
			fielder--;
		}
	}
	
	x_coor--;
	y_coor--;
		while(x_coor>36)
	{
		copy_x=x_coor;
			copy_y=y_coor;
			gotoxy(x_coor,y_coor);
			printf("O");
			usleep(350000);
			gotoxy(copy_x,copy_y);
			printf(" ");
			x_coor--;
	}
		
	player1_ycoordinate=7;
	player2_ycoordinate=12;
	usleep(100000);
	gotoxy(52,11);
	printf("F");
	gotoxy(52,7);
	printf(" ");
	gotoxy(32,5);
	printf(" ");
	gotoxy(32,3);
	printf("K");
	player_direction1=1;
    player_direction2=0;
	player1_ycoordinate=7;
	player2_ycoordinate=12;
	scorecard_runner(1);
	if(on_strike==1)
	{
		on_strike=2;
	}
	else if(on_strike==2)
	{
		on_strike=1;
	}
}
void staright_two(int x_coor,int y_coor)
{
    player_direction1=1;
    player_direction2=0;
	player1_ycoordinate=7;
	player2_ycoordinate=12;
	int copy_x=-1;
	int copy_y=-1;
	gotoxy(32,3);
	printf(" ");
	gotoxy(32,5);
	printf("K");
	while(y_coor<17)
	{
		copy_x=x_coor;
			copy_y=y_coor;
			gotoxy(x_coor,y_coor);
			printf("O");
			gotoxy(43,17);
	        printf(" ");

			player1_ycoordinate=player_mover1(player1_xcoordinate,player1_ycoordinate);
			player2_ycoordinate=player_mover2(player2_xcoordinate,player2_ycoordinate);
			if(player_direction2==0)
			{
			copy_player2=player2_ycoordinate+1;
			remover_up(player2_xcoordinate,copy_player2);
		}
		
		else if(player_direction2==1)
		{
			copy_player2=player2_ycoordinate-1;
			remover_down(player2_xcoordinate,copy_player2);
		}
			if(player2_ycoordinate==12)
			{
				player_direction2=0;
			}
			else if(player2_ycoordinate==7)
			{
				player_direction2=1;
			}
		
		if(player_direction1==0)
			{
			copy_player1=player1_ycoordinate+1;
			remover_up(player1_xcoordinate,copy_player1);
		}
		else if(player_direction1==1)
		{ 
			copy_player1=player1_ycoordinate-1;
			remover_down(player1_xcoordinate,copy_player1);
		 }
			if(player1_ycoordinate==12)
			{
				player_direction1=0;
			}
			else if(player1_ycoordinate==7)
			{
				player_direction1=1;
			}
	        gotoxy(47,17);
	        printf("F");
			usleep(350000);
			gotoxy(copy_x,copy_y);
			printf(" ");
			
			x_coor+=1;
			y_coor++;
	}
	gotoxy(31,8);
	printf(" ");
	gotoxy(31,7);
	printf("P");
	gotoxy(35,12);
	printf("P");
	gotoxy(35,11);
	printf(" ");
	y_coor--;
		while(y_coor>6)
	{
		copy_x=x_coor;
			copy_y=y_coor;
			gotoxy(x_coor,y_coor);
			printf("O");
			usleep(350000);
			gotoxy(copy_x,copy_y);
			printf(" ");
			x_coor-=1;
			y_coor--;
	}
	gotoxy(43,17);
	printf("F");
	gotoxy(47,17);
	printf(" ");
	gotoxy(player2_xcoordinate,--player2_ycoordinate);
	printf(" ");
	gotoxy(35,12);
	printf("P");
	gotoxy(player1_xcoordinate,++player1_ycoordinate);
	printf(" ");
	gotoxy(31,7);
	printf("P");
	gotoxy(32,5);
	printf(" ");
	gotoxy(32,3);
	printf("K");
	player_direction1=1;
    player_direction2=0;
	player1_ycoordinate=7;
	player2_ycoordinate=12;
	scorecard_runner(2);
}
void straight_six(int x_coor,int y_coor)
{
	player_direction1=1;
    player_direction2=0;
	gotoxy(31,7);
	printf("P");
	gotoxy(35,12);
	printf("P");
	int copy_x=-1;
	int copy_y=-1;
	while(y_coor<23)
	{
		copy_x=x_coor;
			copy_y=y_coor;
			gotoxy(x_coor,y_coor);
			printf("O");
			usleep(200000);
			gotoxy(copy_x,copy_y);
			printf(" ");
			x_coor++;
			y_coor++;
	}
	scorecard_runner(6);
}

void ballmover(int runs,int move)
{

 if(runs==6 && move==1)
 {
 	strike_presentator();
 	straight_six(37,7);
 	
 }
 else if(runs==4 && move==1)
 {
    strike_presentator();
 	straight_four(34,14);
 	
 }
 else if(runs==2 && move==1)
 {
 	strike_presentator();
 	staright_two(37,7);
 }
 else if(runs==1 && move==1)
 {
 	
 	straight_one(30,14);
 	strike_presentator();
 }
 else if(runs==5)
 {
 	strike_presentator();
 	wickets_counter++;
 	if(innings_counter==1)
 	{
 	 wickets();	
	 }
	 else{
	 	wickets2();
	 }
 	
 }
 else if(runs==1 && move==2)
 {
 	leg_one(37,7);
 	strike_presentator();
 }
 else if(runs==2 && move==2)
 {
 	strike_presentator();
 	leg_two(37,7);
 }
 else if(runs==6 && move==2)
 {
 	strike_presentator();
 	leg_six(37,7);
 }
 else if(runs==4 && move==2)
 {
 	strike_presentator();
 	leg_four(37,7);
 }
 else if(runs==6 && move==3)
 {
 	strike_presentator();
 	off_six(29,7);
 }
 else if(runs==1 && move==3)
 {
 	strike_presentator();
 	off_one(29,8);
 }
 else if(runs==4 && move==3)
{
 	strike_presentator();
 	off_four(29,6);
 }
 else if(runs==2 && move==3)
{
 	strike_presentator();
 	off_two(29,6);
 }
}

int main()
{
	system("Color 0A");
	gotoxy(34,11);
	printf("Welcome to Qazafi Cricket Stadium, Lahore.");
	sleep(3);
	system("cls");
	gotoxy(34,11);
	printf("Its a 5 Over Match Between Pakistan and Austrailia.");
	sleep(3);
	system("cls");
	gotoxy(34,11);
	printf("Its a flat pitch, And its very Hot in the middle.");
	sleep(3);
	gotoxy(34,11);
	printf("Pakistan has won the Toss and elected to bat first.");
	sleep(3);
	system("cls");
	gotoxy(11,11);
	system("color 0C");
	printf("The line up for the respective teams is as follws:");
	gotoxy(11,13);
	printf("Pakistan:");
	gotoxy(11,14);
	printf("B.Azam (c)  M.Rizwan  H.Ali  S.Masood  M.Hafeez S.Malik A.ALi S.Khan I.Waseem M.Waseem H.Ali\n");
	gotoxy(11,16);
	printf("Austrailia:\n");
	gotoxy(11,17);
	printf("A.Finch (c)  D.Warner  U.Khawaja  S.Smith  G.Maxewell  M.Wade  C.Green  P.Cummins  A.Zampa M.Starc J.Hazel");
	sleep(5);
	system("cls");
	
	system("color 03");
printGround();
gotoxy(75,0);
printboard();
printdata();

int runs=0;
int move=0;
int counter=0;

	srand(time(NULL));
	while(overs<5 && wickets_counter<10)
	{
			if(counter==6)
		{
			over_over();
			counter=0;
		}
		bowler();
	 runs=random(6,1);
	 move=random(3,1);
	 if(runs==3)
	 {
	 	runs=2;
	 }
	 
 	 ballmover(runs,move);
	 sleep(1);
	 counter++;
}
system("cls");
gotoxy(30,15);
printf("Paksitan has set the target of :%d",total_runs+1);
sleep(4);
system("cls");
printGround();
gotoxy(75,0);
printboard();
printdata();
gotoxy(88,24);
printf("Target:210");
int total_1=total_runs;
innings_counter=2;
Innings_reseter();

	while(overs<5 && wickets_counter<10 && total_runs<=total_1)
	{
			if(counter==6)
		{
			over_over();
			counter=0;
		}
		bowler();
	 runs=random(6,1);
	 move=random(3,1);
	 if(runs==3)
	 {
	 	runs=2;
	 }
	 
 	 ballmover(runs,move);
	 sleep(1);
	 counter++;
}
int total_2=total_runs;
gotoxy(30,20);
system("cls");
if(total_1>total_2)
{
	printf("Pakistan Won the Match.");
}
else
{
	printf("Austrailia has Won the Match.");
}
sleep(3);
system("cls");
gotoxy(35,15);
printf("Thanks for Playing.");


printf("\n\n\n\n");
gotoxy(4,30);


    return 0;
}





