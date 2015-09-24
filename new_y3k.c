#include<stdio.h>

//#define DAYS 280
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
    int flag =0;
    int new_mm,old_yy;
    long int DAYS,t_DAYS;
    long unsigned int total_month;

    while(1)
    {
	//scanf("%s",input);
	scanf("%ld%d%d%d",&DAYS,&dd,&mm,&yy);
	if( DAYS ==0 && dd==0 && mm==0 && yy==0)
	    break;
	//	printf("dd = %d\n",dd);
	t_DAYS = DAYS;
	total_month =  temp * DAYS;
	//	printf("total_month = %ld\n", total_month);

	total_day = 0;  
	new_mm =0;flag=0;old_yy=yy; 
	j=0;

	total_day = total_day + (number_of_days(mm) - dd);
	//	printf("total_day = %ld \n",total_day);
	if((int) (DAYS - total_day)>0)
	{
	    DAYS = DAYS - total_day;

	    //	    printf(" DAYS  = %ld \n",DAYS);
	    new_mm = mm+1;
	}
	else
	{
	    DAYS = DAYS - DAYS;
	}


	while(DAYS>27)
	{

	    if(new_mm>12)
	    {
		new_mm =1;
		yy = yy+1;
	    }
	    total_day = total_day + number_of_days(new_mm);
	    // printf("total_day = %ld \n",total_day);
	    if((int)( DAYS - number_of_days(new_mm))>0)
	    {
		DAYS = DAYS - number_of_days(new_mm);
		new_mm = new_mm + 1;
	    }
	    else 
		break;
	}


	/*
	   for(i=mm+1;i<=mm+total_month-1;i++)
	   {
	   if(j>12)
	   j=0; 
	   total_day = total_day + number_of_days(i);
	   }
	   total_day = total_day + (number_of_days(mm) - dd);
	   remaning_day = total_month - total_day; */
	remaning_day = DAYS ;
	//	printf("total_day = %ld \n",total_day);
	//	printf("remaning_day = %ld \n",remaning_day);

	//new_mm = mm + total_month;
#if 0 

	if(remaning_day > 27)
	{  
	    if( remaning_day ==28 || remaning_day ==29 || remaning_day ==30 || remaning_day ==31 )
	    { 
	    }
	    else if(31 == number_of_days(new_mm))
	    {
		remaning_day = remaning_day -31;
		new_mm = new_mm +1;
	    }
	    else if(30 == number_of_days(new_mm))
	    {		remaning_day = remaning_day -30;
		new_mm = new_mm +1;
	    }

	    else  if(28 == number_of_days(new_mm))
	    {
		remaning_day = remaning_day -28;
		new_mm = new_mm +1;
	    }
	    else if(29 == number_of_days(new_mm))
	    {
		remaning_day = remaning_day -29;
		new_mm = new_mm +1;
	    }

	}
#endif
	/*	printf("remaning_day = %d \n",remaning_day);

	//	printf("date = %2.2d/%2.2d/%4.4d\n",mm,dd,yy);
	//	printf("final date = %2.2d/%2.2d/%4.4d\n",new_mm,remaning_day,yy); 
	 */
	if(remaning_day == 0)
	    remaning_day = dd + t_DAYS;

	if(new_mm > 12 )
	    yy = yy+1;
	new_mm = new_mm % 12;
	if(new_mm==0)
	    new_mm = 12;
	printf("%2.2ld/%2.2d/%4.4d\n",remaning_day,new_mm,yy);
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

