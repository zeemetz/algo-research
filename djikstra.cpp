#include<stdio.h>
#include<Windows.h>
#include<stdlib.h>

#define finishx 80
#define finishy 24
#define start 1
#define finish 2

#define expanded 176;

bool is_finish;
int map[finishy][finishx] = {};

void gotoxy(int x, int y, int index)
{
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

	_COORD pos;
	pos.X = x;
	pos.Y = y;

	SetConsoleCursorPosition(hConsole, pos);
	printf("%c",index);
}

struct node
{
	int x,y;
	int cost;
	struct node *parent;
	int stat;//0=un-visited 1=visited
}*source;

struct box
{
	struct node *expanded_node;
	struct box *next,*prev;
}*head, *curr, *tail;

struct optimal_path
{
	int x,y;
	struct optimal_path *next,*prev;
}*begin,*c,*end;

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

void init_map()
{
	map[10][10] = start;
	map[finishy-15][finishx-60] = finish;
}

void init_source()
{
	source = (struct node*) malloc (sizeof(struct node));
	source->cost = 0;
	source->parent = NULL;
	source->stat = 0;
	source->x = 10;
	source->y = 10;

	curr = (struct box*) malloc(sizeof(struct box));
	curr->expanded_node = source;
	curr->next = curr->prev = NULL;
	head = tail = curr;
}

void backtract(struct box *out)
{
	struct node *op = out->expanded_node;

	while(op->parent!=NULL)
	{
		c = (struct optimal_path *) malloc(sizeof(struct optimal_path));
		c->x = op->x;
		c->y = op->y;
		c->next = c->prev =NULL;

		if(begin == NULL)
		{
			begin = end = c;
		}
		else
		{
			end->next = c;
			c->prev = end;
			end = c;
		}
		op = op->parent;
	}
}

void pop(struct box *out)
{
	if( out == tail )
	{
		tail = tail->prev;
		free(out);
		tail->next = NULL;
	}
	else if( out == head )
	{
		head = head->next;
		free(out);
		head->prev = NULL;
	}
	else
	{
		out->prev->next = out->next;
		out->next->prev = out->prev;
		free(out);
	}
}

void push(int x, int y, int post_cost)
{
	source = (struct node*) malloc (sizeof(struct node));
	source->cost = 10+post_cost;
	source->stat = 0;
	source->x = x;
	source->y = y;

	curr = (struct box*) malloc(sizeof(struct box));
	curr->expanded_node = source;
	curr->next = curr->prev = NULL;

	tail->next = curr;
	curr->prev = tail;
	tail = curr;

	map[y][x] = expanded;
	gotoxy(x,y,176);
}

void expand_node(struct box *curr_expanded_node)
{
	if(curr_expanded_node->expanded_node->x == finishx-60 && curr_expanded_node->expanded_node->y == finishy-15)
	{
		is_finish = true;
		backtract(curr_expanded_node);
		return;
	}
	if( curr_expanded_node->expanded_node->x > 0 && map[curr_expanded_node->expanded_node->y][curr_expanded_node->expanded_node->x-1] != 176 )
	{
		push( curr_expanded_node->expanded_node->x-1, curr_expanded_node->expanded_node->y, curr_expanded_node->expanded_node->cost );
		tail->expanded_node->parent = curr_expanded_node->expanded_node;
	}
	if( curr_expanded_node->expanded_node->y > 0 && map[curr_expanded_node->expanded_node->y-1][curr_expanded_node->expanded_node->x] != 176 )
	{
		push( curr_expanded_node->expanded_node->x, curr_expanded_node->expanded_node->y-1, curr_expanded_node->expanded_node->cost );
		tail->expanded_node->parent = curr_expanded_node->expanded_node;
	}
	if( curr_expanded_node->expanded_node->x < finishx && map[curr_expanded_node->expanded_node->y][curr_expanded_node->expanded_node->x+1] != 176 )
	{
		push( curr_expanded_node->expanded_node->x+1, curr_expanded_node->expanded_node->y, curr_expanded_node->expanded_node->cost );
		tail->expanded_node->parent = curr_expanded_node->expanded_node;
	}
	if( curr_expanded_node->expanded_node->y < finishy && map[curr_expanded_node->expanded_node->y+1][curr_expanded_node->expanded_node->x] != 176 )
	{
		push( curr_expanded_node->expanded_node->x, curr_expanded_node->expanded_node->y+1, curr_expanded_node->expanded_node->cost );
		tail->expanded_node->parent = curr_expanded_node->expanded_node;
	}
	//map[curr_expanded_node->expanded_node->y][curr_expanded_node->expanded_node->x] = expanded;
	pop(curr_expanded_node);
}

void smallest()
{
	struct box *temp = head;
	curr = head;
	while(curr->next!=NULL)
	{
		curr = curr->next;
		if(curr->expanded_node->cost < temp->expanded_node->cost )
			temp = curr;
	}
	curr = temp;
}

void move()
{
	while(end!=NULL)
	{
		gotoxy(end->x,end->y,32);
		end=end->prev;
		Sleep(100);
	}
}

void djikstra()
{
	is_finish = false;
	init_map();
	view_map();
	init_source();

	while(head!=NULL && !is_finish)
	{
		smallest();
		expand_node(curr);
		Sleep(5);
	}
	gotoxy(10,10,start);
	gotoxy(finishx-60,finishy-15,finish);
	move();
}

void ascii()
{
	for(int i = 0 ; i < 255 ; i++)
		printf("%d %c\n",i,i);
}

int main()
{
	djikstra();
	//ascii();
	getchar();
	return 0;
}