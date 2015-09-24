#include<stdio.h>

int number_of_days(int);
int leap_year(int);
int sign(int ,int);

int dd,mm,yy;

int main()
{

    double temp=0.03287671232;
    int i,j;
    long unsigned int total_day,remaning_day;
    int t;
    int nod;
    int flag =0;
    int new_mm,old_yy;
    long int DAYS,t_DAYS;
    long unsigned int total_month;

    while(1)
    {
	scanf("%ld%d%d%d",&DAYS,&dd,&mm,&yy);
	if( DAYS ==0 && dd==0 && mm==0 && yy==0)
	    break;
	t_DAYS = DAYS;
	total_month =  temp * DAYS;
	total_day = 0;  
	new_mm =0;old_yy=yy; 
	j=0;
	total_day = total_day + (number_of_days(mm) - dd);
	if((int) (DAYS - total_day)>0)
	{
	    DAYS = DAYS - total_day;
	    new_mm = mm+1;
	}
	else
	    DAYS = DAYS - DAYS;

	while(DAYS>27)
	{

	    if(new_mm>12)
	    {
		new_mm =1;
		yy = yy+1;
	    }
	    nod = number_of_days(new_mm);
	    total_day = total_day + nod ;
	    if((int)( DAYS - nod)>0)
	    {
		DAYS = DAYS - nod; 
		new_mm = new_mm + 1;
	    }
	    else 
		break;
	}
	remaning_day = DAYS ;
	if(remaning_day == 0)
	{ 
	    remaning_day = dd + t_DAYS;
	    new_mm = mm;
	}
	if(new_mm > 12 )
	    yy = yy+1;
	new_mm = new_mm % 12;
	if(new_mm==0)
	    new_mm = 12;
	printf("%ld %d %d\n",remaning_day,new_mm,yy);
    }

    return(0);

}

int leap_year(int yy)
{

    if((yy%100==0 && yy %400==0)||(yy%4==0 && yy%100!=0))
	return(1);

    return(0);

}

int number_of_days(int mm)
{

    switch(mm%12)
    {
	case 1:
	    return(31);	
	case 2:
	    if(leap_year(yy))
		return(29);
	    else
		return(28);
	case 3:
	    return(31);
	case 4:
	    return(30);
	case 5:
	    return(31);
	case 6:
	    return(30);
	case 7:
	    return(31);
	case 8:
	    return(31);
	case 9:
	    return(30);
	case 10:
	    return(31);
	case 11:
	    return(30);
	case 0:
	    return(31);
    }

}

