#include<stdio.h>
#include<string.h>

#define max_rater 40001

int case_count, male_count, female_count, min_rating;

int lower_rating[max_rater],higher_rating[max_rater];
int male_rating[max_rater],female_rating[max_rater];

int lowest_count,highest_count;

void scanner()
{
	scanf("%d %d %d",&male_count,&female_count,&min_rating);

	for(int i = 0 ; i < male_count ; i++)
	{
		scanf("%d",&male_rating[i]);
	}

	for(int i = 0 ; i < female_count ; i++)
	{
		scanf("%d",&female_rating[i]);
	}

	if(male_count <= female_count)
	{
		lowest_count = male_count;
		highest_count = female_count;
		memcpy(&lower_rating,&male_rating,sizeof(male_rating));
		memcpy(&higher_rating,&female_rating,sizeof(female_rating));
	}
	else
	{
		lowest_count = female_count;
		highest_count = male_count;
		memcpy(&lower_rating,&female_rating,sizeof(female_rating));
		memcpy(&higher_rating,&male_rating,sizeof(male_rating));
	}


}

int binary_search(int index)
{
	int top=0;
	int down=highest_count-1;
	int middle;

	if( higher_rating[top] >= index )
		return highest_count;
	else if( higher_rating[down] < index )
		return 0;
	else
	{
		while((down-top)!=1)
		{
			middle = (top+down)/2;
			( higher_rating[middle]>=index ) ? down = middle : top = middle;
		}
		return highest_count - down;
	}
}

int main_loop()
{
	int result=0;

	if((lower_rating[lowest_count-1]+higher_rating[highest_count-1])<min_rating)
	{
		result = 0;
	}
	else
	{
		for(int i = 0 ; i < lowest_count ; i++)
		{
			result += binary_search(min_rating - lower_rating[i]);
		}
	}

	return result;
}

void solver(int index)
{
	int result = 0;
	scanner();

	result = main_loop();

	printf("Kasus #%d: %d\n",index+1,result);
}

int main()
{
	scanf("%d",&case_count);

	for(int i = 0 ; i < case_count ; i ++)
	{
		solver(i);
	}
	return 0;
}