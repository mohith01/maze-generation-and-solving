#include<iostream>
#include<stdlib.h>
#include <conio.h>
#include<time.h>
#define KEY_UP 72
#define KEY_DOWN 80
#define KEY_LEFT 75
#define KEY_RIGHT 77
using namespace std;
//top =0 , right =1, bot=2, left =3
const int r=5,cc=10;

const int gr = r*2 + 1;// no. of rows in grid
const int gc = cc*2 + 1;// no. of columns in grid
int s_top=-1;
class cell
{
	public:
		int top, bot, right, left, vis,status;
	cell()
	{
		top=0;
		bot=0;
		right=0;
		left=0;
		vis=0;
		status=0;
	}
};
class stack
{
	public:
		int i,j;
	visited()
	{
		i=-1;
		j=-1;
	}
}stack[50];


int toss()
{
	int choice=-1;
	choice=rand()%4;
	return choice;
}

//stack function
int push(int x,int y)
{
	s_top++;
	stack[s_top].i=x;
	stack[s_top].j=y;
}


int pop()
{
	if(s_top<=0)
		s_top=-1;
	else
		s_top--;
}
//end of stack func

// start of checking corners
bool checkCorTopLeft(int i,int j,int row,int col) 
{
	if(i==0 && j==0)
		return true;
	else
		return false;
	
}

bool checkCorTopRight(int i,int j,int row,int col)
{
	if(i==0 && j==col-1)
		return true;
	else
		return false;
}

bool checkCorBotLeft(int i,int j,int row,int col)
{
	if(i==row-1 && j==0)
		return true;
	else
		return false;
}

bool checkCorBotRight(int i,int j,int row,int col)
{
	if(i==row-1 && j==col-1)
		return true;
	else
		return false;
}
//end check corner

//start of check border
bool checkBorLeft(int i,int j,int row,int col)
{
	if(i>0 && i<row && j==0)
		return true;
	else 
		return false;
	
}

bool checkBorRight(int i,int j,int row,int col)
{
	if(i>0 && i<row && j==col-1)
		return true;
	else 
		return false;
	
}

bool checkBorTop(int i,int j,int row,int col)
{
	if(j>0 && j<col && i==0)
		return true;
	else 
		return false;
}

bool checkBorBot(int i,int j,int row,int col)
{
	if(j>0 && j<col && i==row-1)
		return true;
	else 
		return false;
}
// end of check border

//check if neghibour visited or not
bool Topvis(int i,int j,cell c[][cc])
{
	if(c[i-1][j].vis==1)
	{
		return true;
	}
	else
		return false;
}

bool Rightvis(int i,int j,cell c[][cc])
{
	if(c[i][j+1].vis==1)
	{
		return true;
	}
	else
		return false;
}

bool Botvis(int i,int j,cell c[][cc])
{
	if(c[i+1][j].vis==1)
	{
		return true;
	}
	else
		return false;
}

bool Leftvis(int i,int j,cell c[][cc])
{
	if(c[i][j-1].vis==1)
	{
		return true;
	}
	else
		return false;
}

bool TopRightvis(int i,int j,cell c[][cc])
{
	if(c[i-1][j].vis==1 && c[i][j+1].vis==1)
		return true;
	else
		return false;	
}

bool RightBotvis(int i,int j,cell c[][cc])
{
	if(c[i][j+1].vis==1 && c[i+1][j].vis==1)
		return true;
	else
		return false;	
}

bool BotLeftvis(int i,int j,cell c[][cc])
{
	if(c[i+1][j].vis==1 && c[i][j-1].vis==1)
		return true;
	else
		return false;	
}

bool LeftTopvis(int i,int j,cell c[][cc])
{
	if(c[i][j-1].vis==1 && c[i-1][j].vis==1)
		return true;
	else
		return false;	
}

bool TopBotvis(int i,int j,cell c[][cc])
{
	if(c[i-1][j].vis==1 && c[i+1][j].vis==1)
		return true;
	else
		return false;	
}

bool LeftRightvis(int i,int j,cell c[][cc])
{
	if(c[i][j-1].vis==1 && c[i][j+1].vis==1)
		return true;
	else
		return false;	
}

bool TopRightBotvis(int i,int j,cell c[][cc])
{
	if(c[i-1][j].vis==1 && c[i][j+1].vis==1 && c[i+1][j].vis==1)
		return true;
	else
		return false;	
}

bool RightBotLeftvis(int i,int j,cell c[][cc])
{
	if(c[i][j+1].vis==1 && c[i+1][j].vis==1 && c[i][j-1].vis==1)
		return true;
	else
		return false;	
}

bool BotLeftTopvis(int i,int j,cell c[][cc])
{
	if(c[i+1][j].vis==1 && c[i][j-1].vis==1 && c[i-1][j].vis==1)
		return true;
	else
		return false;	
}

bool LeftTopRightvis(int i,int j,cell c[][cc])
{
	if(c[i][j-1].vis==1 && c[i-1][j].vis==1 && c[i][j+1].vis==1)
		return true;
	else
		return false;	
}

bool Allvis(int i, int j, cell c[][cc])
{
	if(checkCorTopLeft(i,j,r,cc))
	{
			if(RightBotvis(i,j,c))
				return true;
			else
				return false;
	}
	else if(checkCorTopRight(i,j,r,cc))
	{
		if(BotLeftvis(i,j,c))
			return true;
		else
			return false;
	}
	else if(checkCorBotRight(i,j,r,cc))
	{
		if(LeftTopvis(i,j,c))
			return true;
		else
			return false;
	}
	else if(checkCorBotLeft(i,j,r,cc))
	{
		if(TopRightvis(i,j,c))
			return true;
		else
			return false;
	}
	else if(checkBorLeft(i,j,r,cc))
	{
		if(TopRightBotvis(i,j,c))
			return true;
		else
			return false;
	}
	
	else if(checkBorTop(i,j,r,cc))
	{
		if(RightBotLeftvis(i,j,c))
			return true;
		else
			return false;
	}
	
	else if(checkBorRight(i,j,r,cc))
	{
		if(BotLeftTopvis(i,j,c))
			return true;
		else
			return false;
	}
	
	else if(checkBorBot(i,j,r,cc))
	{
		if(LeftTopRightvis(i,j,c))
			return true;
		else
			return false;
	}
	
	else
	{
		if(Topvis(i,j,c) && Rightvis(i,j,c) && Botvis(i,j,c) && Leftvis(i,j,c))
			return true;
		else
			return false;
	}
}


int godown(char ar[][gc],int &i,int &j, int &dest);
int goup(char ar[][gc],int &i,int &j, int &dest);
int goleft(char ar[][gc],int &i,int &j, int &dest);
int goright(char ar[][gc],int &i,int &j, int &dest);

// main
int main()
{
	/*cout<<"Enter no. of row: ";cin>>r;
	cout<<"\nEnter no. of columns: ";cin>>c;*/
	
	time_t start, end;
	int choice=-1,x=-1,count=1,tot_cell=0,users;
	
	const int row=r;//no. of rows in maze
	const int col=cc; //no. of columns in maze;
	
	tot_cell=row*col;
	

	cell c[row][col];
	cout<<"\n";

	
	char grid[gr][gc];
	//grid construction
	for(int i=0;i<gr;i++)
	{
		for(int j=0;j<gc;j++)
		{
			grid[i][j]='|';
		}
	}
	for(int i=1;i<gr;i=i+2)
	{
		for(int j=1;j<gc;j=j+2)
		{
			grid[i][j]=' '; 
		}
	}
	
	grid[1][1]='@';
	//end of grid construction
	cout<<"Grid: \n";
	for(int a=0;a<gr;a++)
	{
		for(int b=0;b<gc;b++)
		{
			cout<<grid[a][b];
		}
		cout<<"\n";
	}
	int i=0,j=0;
	c[i][j].vis=1;
	// count=1
	push(i,j);
	while(count<tot_cell)
	{
		if(!Allvis(i,j,c))
		{	// check if corner cell
			if(checkCorTopLeft(i,j,row,col))
			{
				int ar[]={1,2};
				if( !Rightvis(i,j,c) && !Botvis(i,j,c))
				{
					x=rand()%2;
					choice=ar[x];
				}
				else if(!Rightvis(i,j,c))
				{
					choice=1;
				}
				else
					choice=2;
			}
			
			else if(checkCorTopRight(i,j,row,col))
			{
				int ar[]={2,3};
				if( !Botvis(i,j,c) && !Leftvis(i,j,c))
				{
					x=rand()%2;
					choice=ar[x];
				}
				else if(!Botvis(i,j,c))
				{
					choice=2;
				}
				else
					choice=3;
			}
			
			else if(checkCorBotRight(i,j,row,col))
			{
				int ar[]={3,0};
				if( !Leftvis(i,j,c) && !Topvis(i,j,c))
				{
					x=rand()%2;
					choice=ar[x];
				}
				else if(!Leftvis(i,j,c))
				{
					choice=3;
				}
				else
					choice=0;
			}
			
			else if( checkCorBotLeft(i,j,row,col))
			{
				int ar[]={0,1};
				if( !Topvis(i,j,c) && !Rightvis(i,j,c))
				{
					x=rand()%2;
					choice=ar[x];
				}
				else if(!Topvis(i,j,c))
				{
					choice=0;
				}
				else
					choice=1;
			}
			
			// check if border cell
			else if(checkBorLeft( i, j, row, col))
			{
				
				if( !Topvis(i,j,c) && !Rightvis(i,j,c) && !Botvis(i,j,c))
				{
					int ar[]={0,1,2};
					x=rand()%3;
					choice=ar[x];
				}
				else if(TopRightvis(i,j,c))
				{
					choice=2;
				}
				else if(RightBotvis(i,j,c))
				{
					choice=0;
				}
				else if(TopBotvis(i,j,c))
				{
					choice=1;
				}
				else if(Topvis(i,j,c))
				{
					int ar[]={1,2};
					x=rand()%2;
					choice=ar[x];
				}
				else if(Rightvis(i,j,c))
				{
					int ar[]={0,2};
					x=rand()%2;
					choice=ar[x];
				}
				else if(Botvis(i,j,c))
				{
					int ar[]={0,1};
					x=rand()%2;
					choice=ar[x];
				}
			}
			
			
			else if(checkBorTop( i, j, row, col))
			{
				if(!Rightvis(i,j,c) && !Botvis(i,j,c) && !Leftvis(i,j,c))
				{
					int ar[]={1,2,3};
					x=rand()%3;
					choice=ar[x];	
				}
				else if(RightBotvis(i,j,c))
				{
					choice=3;
				}
				else if(BotLeftvis(i,j,c))
				{
					choice=1;
				}
				else if(LeftRightvis(i,j,c))
				{
					choice=2;
				}
				else if(Rightvis(i,j,c))
				{
					int ar[]={2,3};
					x=rand()%2;
					choice=ar[x];	
				}
				else if(Botvis(i,j,c))
				{
					int ar[]={1,3};
					x=rand()%2;
					choice=ar[x];
				}
				else if(Leftvis(i,j,c))
				{
					int ar[]={1,2};
					x=rand()%2;
					choice=ar[x];
				}
			}
			else if(checkBorRight( i, j, row, col))
			{
				if( !Botvis(i,j,c) && !Leftvis(i,j,c) && !Topvis(i,j,c) )
				{
					int ar[]={0,2,3};
					x=rand()%3;
					choice=ar[x];
				}
				else if( BotLeftvis(i,j,c))
				{
					choice=0;
				}
				else if( LeftTopvis(i,j,c))
				{
					choice=2;
				}
				else if( TopBotvis(i,j,c))
				{
					choice=3;
				}
				else if( Botvis(i,j,c))
				{
					int ar[]={3,0};
					x=rand()%2;
					choice=ar[x];
				}
				else if( Leftvis(i,j,c))
				{
					int ar[]={0,2};
					x=rand()%2;
					choice=ar[x];
				}
				else if( Topvis(i,j,c))
				{
					int ar[]={2,3};
					x=rand()%2;
					choice=ar[x];
				}
			}
			
			else if(checkBorBot( i, j, row, col))
			{
				if( !Leftvis(i,j,c) && !Topvis(i,j,c) && !Rightvis(i,j,c) )
				{
					int ar[]={0,1,3};
					x=rand()%3;
					choice=ar[x];
				}
				else if( LeftTopvis(i,j,c) )
				{
					choice=1;
				}
				else if( TopRightvis(i,j,c) )
				{
					choice=3;
				}
				else if( LeftRightvis(i,j,c) )
				{
					choice=0;
				}
				else if( Leftvis(i,j,c) )
				{
					int ar[]={0,1};
					x=rand()%2;
					choice=ar[x];
				}
				else if( Topvis(i,j,c) )
				{
					int ar[]={3,1};
					x=rand()%2;
					choice=ar[x];
				}
				else if( Rightvis(i,j,c) )
				{
					int ar[]={3,0};
					x=rand()%2;
					choice=ar[x];
				}
			}
			
			// if cell not in border or corner
			else 
			{
				if(!Leftvis(i,j,c) && !Topvis(i,j,c) && !Rightvis(i,j,c) && !Botvis(i,j,c))
				{
					int ar[]={0,1,2,3};
					x=rand()%4;
					choice=ar[x];
				}
				else if(LeftTopRightvis(i,j,c))
				{
					choice=2;
				}
				else if(TopRightBotvis(i,j,c))
				{
					choice=3;
				}
				else if(RightBotLeftvis(i,j,c))
				{
					choice=0;
				}
				else if(BotLeftTopvis(i,j,c))
				{
					choice=1;
				}
				else if(LeftTopvis(i,j,c))
				{
					int ar[]={1,2};
					x=rand()%2;
					choice=ar[x];
				}
				else if(TopRightvis(i,j,c))
				{
					int ar[]={2,3};
					x=rand()%2;
					choice=ar[x];
				}
				else if(RightBotvis(i,j,c))
				{
					int ar[]={3,0};
					x=rand()%2;
					choice=ar[x];
				}
				else if(BotLeftvis(i,j,c))
				{
					int ar[]={0,1};
					x=rand()%2;
					choice=ar[x];
				}
				else if(LeftRightvis(i,j,c))
				{
					int ar[]={0,2};
					x=rand()%2;
					choice=ar[x];
				}
				else if(TopBotvis(i,j,c))
				{
					int ar[]={3,1};
					x=rand()%2;
					choice=ar[x];
				}
				else if(Leftvis(i,j,c))
				{
					int ar[]={0,1,2};
					x=rand()%3;
					choice=ar[x];
				}
				else if(Topvis(i,j,c))
				{
					int ar[]={1,2,3};
					x=rand()%3;
					choice=ar[x];
				}
				else if(Rightvis(i,j,c))
				{
					int ar[]={2,3,0};
					x=rand()%3;
					choice=ar[x];
				}
				else if(Botvis(i,j,c))
				{
					int ar[]={3,0,1};
					x=rand()%3;
					choice=ar[x];
				}
			}
			if(choice==0)
			{
				c[i][j].top=1;
				c[i-1][j].bot=1;
				i=i-1;
			}	
			else if(choice==1)
			{
				c[i][j].right=1;
				c[i][j+1].left=1;
				j=j+1;
			}
			else if(choice==2)
			{
				c[i][j].bot=1;
				c[i+1][j].top=1;
				i=i+1;
			}
			else if(choice==3)
			{
				c[i][j].left=1;
				c[i][j-1].right=1;
				j=j-1;
			}
			c[i][j].vis=1;
			count++;
			push(i,j);
			
		}
		else
		{
			pop();
			i=stack[s_top].i;
			j=stack[s_top].j;
		}
	}
	
	for(int i=0, a=1; i<row,a<gr; i++,a+=2)
	{
		for(int j=0, b=1; j<col,b<gc; j++,b+=2)
		{
			if(c[i][j].left==1)
			{
				grid[a][b-1]=' ';
			}
			if(c[i][j].top==1)
			{
				grid[a-1][b]=' ';
			}
			if(c[i][j].right==1)
			{
				grid[a][b+1]=' ';
			}
			if(c[i][j].bot==1)
			{
				grid[a+1][b]=' ';
			}	
		}
	}
	cout<<"\n\n\n\nMaze: \n";
	for(int a=0;a<gr;a++)
	{
		for(int b=0;b<gc;b++)
		{
			cout<<grid[a][b];
		}
		cout<<"\n";
	}
	
	//solving by user
	cout<<"\nEnter number of players...";
	cin>>users;
	int userstime[users];
	for(int a=0;a<users;a++)
	{
		char grid1[gr][gc];
		for(int i=0;i<gr;i++)
		{
			for(int j=0;j<gc;j++)
			{
				grid1[i][j]=grid[i][j];
			}
		}
		cout<<"\nGood Luck, Player "<<a+1;
		time(&start);
		int move = 0;
		int dest = 0;
		x=1;
		int y=1;
		grid1[gr-2][gc-2]='D';// destination
		// x =1, y =1 is starting point
	    while(dest==0)
	    {
	        move = 0;
	        move= getch();
			if(move==KEY_DOWN)
			{
				godown(grid1,x,y,dest);
				
			}
			if(move==KEY_UP)
			{
				goup(grid1,x,y,dest);
				
			}
			if(move==KEY_LEFT)
			{
				goleft(grid1,x,y,dest);
				
			}
			if(move==KEY_RIGHT)
			{
				goright(grid1,x,y,dest);
				
			}
			cout<<"\n\n\n";
			for(int a=0;a<gr;a++)
			{
				for(int b=0;b<gc;b++)
				{
					cout<<grid1[a][b];
				}
				cout<<"\n";
			}
	     	/*cout<<"\n"<<x<<" "<<y;
	     	cout<<"\n"<<gr-2<<" "<<gc-2;*/
			
	    }
	    if(dest==1)
	    {
	    	time(&end);
	    	cout<<"\n\nGOOD WORK!!!";
	    	double time_taken = double(end - start); 
	    	userstime[a]=time_taken;
			cout << "\nTime taken: "<<time_taken<<"seconds\n"; 

		}
	}
	int temp=userstime[0],winner;
	for(int i=0;i<users;i++)
	{
		if(userstime[i]<temp)
		{
			temp=userstime[i];
			winner=i;
		}			
	}
	
	cout<<"Player "<<winner+1<<" wins!!!";
	
	
	return 0;
}

int godown(char ar[][gc],int &i,int &j, int &dest)
{
	if(ar[i+1][j]==' ' || ar[i+1][j]=='D')
	{
		if(ar[i+1][j]=='D')
		{	dest=1; }
		ar[i][j]='*';
		ar[i+1][j]='@';
		i=i+1;
	}
	else if(ar[i+1][j]=='*')
	{
		ar[i][j]=' ';
		ar[i+1][j]='@';
		i=i+1;
	}
	
	
}
int goup(char ar[][gc],int &i,int &j, int &dest)
{
	if(ar[i-1][j]==' ' || ar[i-1][j]=='D')
	{
		if(ar[i-1][j]=='D')
		{	dest=1;}
		ar[i][j]='*';
		ar[i-1][j]='@';
		i=i-1;
	}
	else if(ar[i-1][j]=='*')
	{
		ar[i][j]=' ';
		ar[i-1][j]='@';
		i=i-1;
	}
}

int goleft(char ar[][gc],int &i,int &j, int &dest)
{
	if(ar[i][j-1]==' ' || ar[i][j-1]=='D')
	{
		if(ar[i][j-1]=='D')
			dest=1;
		ar[i][j]='*';
		ar[i][j-1]='@';
		j=j-1;
	}
	else if(ar[i][j-1]=='*')
	{
		ar[i][j]=' ';
		ar[i][j-1]='@';
		j=j-1;
	}
}

int goright(char ar[][gc],int &i,int &j, int &dest)
{
	if(ar[i][j+1]==' ' || ar[i][j+1]=='D')
	{
		if(ar[i][j+1]=='D')
		{	dest=1; }
		ar[i][j]='*';
		ar[i][j+1]='@';
		j=j+1;
	}
	else if(ar[i][j+1]=='*')
	{
		ar[i][j]=' ';
		ar[i][j+1]='@';
		j=j+1;
	}
}


