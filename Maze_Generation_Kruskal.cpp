#include<stdio.h>
#include<Windows.h>
#include<stdlib.h>
#include<time.h>

// kruskal
#define finishx 80
#define finishy 24
#define wall 219
#define way 32
#define visited_node 176
// djikstra
int startx,starty,targetx,targety;
char map[25][80];
struct node
{
	int cost;
	char status[5];
	struct node	*parent, *left, *right, *top,*bottom, *left_top, *left_bottom, *right_top, *right_bottom;
}

//Maze Generation

void gotoxy(int x, int y, int index)
{
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

	_COORD pos;
	pos.X = x;
	pos.Y = y;

	SetConsoleCursorPosition(hConsole, pos);
	printf("%c",index);
}

void init_map()
{
	for(int i = 0 ; i < finishy ; i ++)
	{
		for(int j = 0 ; j < finishx ; j ++)
		{
			map[i][j] = wall;
		}
	}
}

void view_map()
{
	for(int i = 0 ; i < finishy ; i ++)
	{
		for(int j = 0 ; j < finishx ; j ++)
		{
			printf("%c",map[i][j]);
		}
	}
}

void reload_map()
{
	//system("cls");
	//view_map();
	//gotoxy()
}

void init_visited(bool temp[])
{
	for(int i = 0 ; i < 4 ; i++)
		temp[i] = false;
}

bool is_clear(bool temp[])
{
	int counter=0;
	for(int i = 0 ; i < 4 ; i++)
		if(temp[i])
			counter++;
	if(counter==4)
		return true;
	else
		return false;
}

void dfs(int y, int x)
{
	Sleep(50);
	map[y][x] = way;
	gotoxy(x,y,way);

	srand(time(0));
	bool visited[4];
	init_visited(visited);
	

	while(!is_clear(visited))
	{
		int path = rand()%4;
		if(visited[path])
			continue;
		switch(path)
		{
		case 0:
			if((y-2)>0 && map[y-2][x]!=way)
			{
				map[y-1][x] = map[y-2][x] = way;
				gotoxy(x,y-1,way);
				gotoxy(x,y-2,way);
				dfs(y-2,x);
			}
			break;
		case 1:
			if((x+2)<finishx && map[y][x+2]!=way)
			{
				map[y][x+1] = map[y][x+2] = way;
				gotoxy(x+1,y,way);
				gotoxy(x+2,y,way);
				dfs(y,x+2);
			}
			break;
		case 2:
			if((y+2)<finishy && map[y+2][x]!=way)
			{
				map[y+1][x] = map[y+2][x] = way;
				gotoxy(x,y+1,way);
				gotoxy(x,y+2,way);
				dfs(y+2,x);
			}
			break;
		case 3:
			if((x-2)>0 && map[y][x-2]!=way)
			{
				map[y][x-1] = map[y][x-2] = way;
				gotoxy(x-1,y,way);
				gotoxy(x-2,y,way);
				dfs(y,x-2);
			}
			break;
		}
		visited[path] = true;
	}
}

void generate_map()
{
	init_map();
	view_map();
	dfs(0,0);
}

void ascii()
{
	for(int i = 0 ;i < 255; i++)
	{
		printf("%d : %c\n",i,i);
	}
}

// djikstra
void random_point()
{
	srand(time(0));
	startx = targetx = rand()%finishx;
	starty = targety = rand()%finishy;
	while( startx == targetx || starty == targety || abs(startx-targetx) < 30 || abs(starty-targety)<10 || map[starty][startx] != way || map[targety][targetx] != way)
	{
		startx = rand()%finishx;
		starty = rand()%finishy;
		targetx = rand()%finishx;
		targety = rand()%finishy;
	}
}

bool dead_end(int x, int y)
{
	if( map[x][y-1] !=way && map[x][y+1] !=way && map[x+1][y] !=way && map[x-1][y] !=way)
		return true;
	return false;
}

void expand_node(int x,int y)
{
	
}

void djikstra()
{
	random_point();
	gotoxy(startx,starty,1);
	gotoxy(targetx,targety,2);

	expand_node(startx, starty);
}

int main()
{
	generate_map();
	djikstra();
	//ascii();

	getchar();
	return 0;
}