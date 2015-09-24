#include<stdio.h>

#define DAYS 280
int number_of_days(int);
int leap_year(int);
int sign(int ,int);

int dd,mm,yy;

int main()
{


    int i,j;
    int total_day,remaning_day;
    int t;
    char input[9];
    int flag =0;
    int new_mm,old_yy;

    scanf("%d",&t);
    for(j=1;j<=t;j++)
    {
	scanf("%s",input);
	mm  = 10 * (input[0] - '0') + (input[1] - '0');
	dd  = 10 * (input[2] - '0') + (input[3] - '0');
	yy  = 1000 * (input[4] - '0') + 100 * (input[5] - '0') + 10 * (input[6] - '0') +  (input[7] - '0');
	total_day = 0;  
	new_mm =0;flag=0;old_yy=yy; 
	for(i=mm+1;i<=mm+8;i++)
	{
	    if(i>12 && !flag)
	    {
		flag = 1;
		yy = yy +1;
	    }
	    total_day = total_day + number_of_days(i);
	}
	total_day = total_day + (number_of_days(mm) - dd);
	remaning_day = DAYS - total_day;

	/*	printf("total_day = %d \n",total_day);
	//	printf("remaning_day = %d \n",remaning_day);
	 */
	new_mm = mm + 9;
	/*#if 0 */
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
	/*#endif
	//	printf("remaning_day = %d \n",remaning_day);

	//	printf("date = %2.2d/%2.2d/%4.4d\n",mm,dd,yy);
	//	printf("final date = %2.2d/%2.2d/%4.4d\n",new_mm,remaning_day,yy); 
	 */
	if(new_mm > 12 && old_yy == yy )
	    yy = yy+1;
	new_mm = new_mm % 12;
	if(new_mm==0)
	    new_mm = 12;
	printf("%d %2.2d/%2.2d/%4.4d ",j,new_mm,remaning_day,yy);
	sign(remaning_day,new_mm);
    }

    return(0);

}

int sign(int dd,int mm)
{

    switch(mm)
    {
	case 1:
	    if(dd>=21)
		printf("aquarius\n");
	    if(dd>=1 && dd<=20)
		printf("capricorn\n");
	    break;
	case 2:       
	    if(dd >= 1 && dd <= 19)
		printf("aquarius\n");
	    if(dd >= 20)
		printf("pisces\n");
	    break;
	case 3:
	    if(dd >= 1 && dd <= 20)
		printf("pisces\n");
	    if(dd >=21)
		printf("aries\n");
	    break;
	case 4:
	    if(dd >= 1 && dd <= 20)
		printf("aries\n");
	    if(dd >= 21)
		printf("taurus\n");
	    break;
	case 5:
	    if(dd >=1 && dd <=21 )
		printf("taurus\n");
	    if(dd >= 22)
		printf("gemini\n");
	    break;
	case 6:
	    if(dd >= 1 && dd <=21)
		printf("gemini\n");
	    if(dd>=22)
		printf("cancer\n");
	    break;
	case 7:
	    if(dd >= 1 && dd <= 22)
		printf("cancer\n");
	    if(dd>=23)		
		printf("leo\n");
	    break;
	case 8:
	    if(dd >= 1 && dd <= 21)
		printf("leo\n");
	    if(dd>=22)
		printf("virgo\n");
	    break;
	case 9:
	    if(dd>=1 && dd<=23)
		printf("virgo\n");
	    if(dd>=24)
		printf("libra\n"); 
	    break;
	case 10:
	    if(dd >= 1 && dd<=23)
		printf("libra\n"); 
	    if(dd>=24)
		printf("scorpio\n"); 
	    break;
	case 11:
	    if(dd >= 1 && dd <= 22)
		printf("scorpio\n"); 
	    if(dd>=23)
		printf("sagittarius\n");
	    break;
	case 12:
	    if(dd >=1 && dd <=22)
		printf("sagittarius\n");
	    if(dd>=23)
		printf("capricorn\n");
	    break;

    }
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

