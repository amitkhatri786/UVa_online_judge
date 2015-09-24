#include<stdio.h>
#include<string.h>

int main()
{
    int i,j,t;
    char solution[1000];
    char user_solution[1000];
    char *found;
    int wrong_attempt=0;
    int won,lost,got;
    while(1)
    {
	scanf("%d",&t);
	if(t==-1)
	    break;

	scanf("%s",solution);
	scanf("%s",user_solution);

	printf("Round %d\n",t);
	wrong_attempt = 7;
	won=0;
	lost=0;
	got =0;
	for(i=0; user_solution[i]!='\0'; i++)
	{
	    found  =  strchr(solution,user_solution[i]);
	    if(found != NULL)
		while(found !=NULL)
		{
		    got++;
		    solution[found-solution]= ' ';
		    found  =  strchr(found+1,user_solution[i]);
		}
	    else
		wrong_attempt--;

	    if(got==strlen(solution))
	    {
		won=1;
		break;
	    }
	    else 
		if(wrong_attempt==0)
		{
		    lost=1;
		    break;
		}

	}

	if(won==1)
	    printf("You win.\n");
	else
	    if(lost==1 )
		printf("You lose.\n");
	    else
		printf("You chickened out.\n");
	memset(solution,0,100);
	memset(user_solution,0,100);

    }
    return(0);
}

