#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

int win(char matrix[3][3],char player)
{
	int i,j,q;
	
	for(i=0;i<3;i++)
	{
		q=0;
		for(j=0;j<3;j++)
		{
			if(matrix[i][j]==player)
			{
				q++;
				continue;
			}
		}
		if(q==3)
		{
			return 1;
		}	
	}

	for(j=0;j<3;j++)
	{
		q=0;
		for(i=0;i<3;i++)
		{
			if(matrix[i][j]==player)
			{
				q++;
				continue;
			}
		}
		if(q==3)
		{
			return 1;
		}	
	}

	q=0;
	for(i=0;i<3;i++)
	{
		
		if(matrix[i][i]==player)
		{
			q++;
		}
	}
	if(q==3)
	{
		return 1;
	}
	
	q=0;
	for(i=0,j=2;i<3 && j>=0;i++,j--)
	{
		
		if(matrix[i][j]==player)
		{
			q++;
		}
	}
	
	if(q==3)
	{
		return 1;
	}
	
	return 0;
}

int playGame()
{
	int reference[9][2];
	char matrix[3][3],player1[30],player2[30],enter;
	int i,k,j,p=0,row,col,result,inputPos,Xcount,Ocount,DrawCount,Total;
	FILE *fp;
	fp=fopen("Scoreboard.txt","r");

	if(fp==NULL)
	{
		Xcount=0;
		Ocount=0;
		DrawCount=0;
		Total=0;
	}
	else
	{
		fscanf(fp,"%d %d %d %d",&Xcount,&Ocount,&DrawCount,&Total);
	}

	for(i=0;i<3;i++)
	{
		for(k=0;k<3;k++)
		{
			matrix[i][k]=' ';
		}
	}

	for(i=0;i<3;i++)
	{
		for(j=0;j<3;j++)
		{
			reference[p][0]=i;
			reference[p][1]=j;
			p++;
		}
	}

	printf("\n\tENTER NAME OF PLAYER 1: ");
	scanf("%s",player1);
	printf("\n\tENTER NAME OF PLAYER 2: ");
	scanf("%s",player2);

	for(i=1;i<10;i++)
	{
	
		if(i%2!=0)
		{
			printf("\n\n\t%s's turn(X) ! \n\tEnter position: ",player1);
			scanf("%d",&inputPos);

			row=reference[inputPos-1][0];
			col=reference[inputPos-1][1];

			while(inputPos<1 || inputPos>9  || matrix[row][col]=='X' || matrix[row][col]=='O')
			{
				printf("\n\tSorry! Enter valid position\n");
				scanf("%d",&inputPos);
				row=reference[inputPos-1][0];
				col=reference[inputPos-1][1];
			}
			
			matrix[row][col]='X';

			result=win(matrix,'X');

			if(result==1)
			{
				printf("\n\n Congratulations! %s wins!\n",player1);
				Xcount++;
				break;
			}
		}
		else 
		{
			printf("\n\n\t%s's turn(O) ! \n\tEnter position: ",player2);
			scanf("%d",&inputPos);

			row=reference[inputPos-1][0];
			col=reference[inputPos-1][1];

			while(inputPos<1 || inputPos>9  || matrix[row][col]=='X' || matrix[row][col]=='O')
			{
				printf("\n\tSorry! Enter valid position\n");
				scanf("%d",&inputPos);
				row=reference[inputPos-1][0];
				col=reference[inputPos-1][1];
			}

			matrix[row][col]='O';

			result=win(matrix,'O');

			if(result==1)
			{
				printf("\n\n Congratulations! %s wins!\n",player2);
				Ocount++;
				break;
			}

		}
		printf("\n\n\t");
		for(j=0;j<13;j++)
	    {
	        printf("-");
	    }
	    printf("\n");
	    
	    for(k=0;k<3;k++)
	    {
	        printf("\t|");
	        for(j=0;j<3;j++)
	        {
	            printf(" %c |",matrix[k][j]);
	        }
	        printf("\n\t");
	        
	        for(j=0;j<13;j++)
	        {
	            printf("-");
	        }
	        printf("\n");
	        
   		}
   		printf("\n\n");
	}

	if(i==10)
	{
		printf("\n\tGame draw!\n");
		DrawCount++;
	}
	else
	{
		printf("\n\n\t");
		for(j=0;j<13;j++)
	    {
	        printf("-");
	    }
	    printf("\n");
	    
	    for(i=0;i<3;i++)
	    {
	        printf("\t|");
	        for(j=0;j<3;j++)
	        {
	            printf(" %c |",matrix[i][j]);
	        }
	        printf("\n\t");
	        
	        for(j=0;j<13;j++)
	        {
	            printf("-");
	        }
	        printf("\n");
	    }
	    printf("\n\n");
	}

	Total++;
	fclose(fp);
	fp=fopen("Scoreboard.txt","w");

	fprintf(fp,"%d %d %d %d",Xcount,Ocount,DrawCount,Total);
	fclose(fp);

	printf("\n\tPress enter key to continue!\n");
	scanf("%c%c",&enter,&enter);

	return 0;
}

void printScore()
{
	FILE *fp;
	int Xcount,Ocount,DrawCount,Total;
	char enter;	
	fp = fopen("Scoreboard.txt","r");

	if(fp==NULL)
	{
		printf("\tX Wins: 0\n\tO Wins: 0\n\tTotal Draws: 0\n\tTotal Games: 0\n");
	}	
	else
	{
		fscanf(fp,"%d %d %d %d",&Xcount,&Ocount,&DrawCount,&Total);
		printf("\tX Wins: %d\n\tO Wins: %d\n\tTotal Draws: %d\n\tTotal Games: %d\n",Xcount,Ocount,DrawCount,Total);
	}

	printf("\n\tPress enter key to continue!\n");
	scanf("%c%c",&enter,&enter);
}

void instruct()
{
	int k,j,count=1;
	char enter;

	printf("\n\n\t");
	for(j=0;j<13;j++)
    {
        printf("-");
    }
    printf("\n");
    
    for(k=0;k<3;k++)
    {
        printf("\t|");
        for(j=0;j<3;j++)
        {
            printf(" %d |",count);
            count++;
        }
        printf("\n\t");
        
        for(j=0;j<13;j++)
        {
            printf("-");
        }
        printf("\n");
        
	}
	printf("\n\n");	

	printf("Enter the value inside the box to insert in that box! \n");

	printf("\n\tPress enter key to continue!\n");
	scanf("%c%c",&enter,&enter);

}

int main()
{

	int choice;
	char enter;
	while(1)
	{
		printf("\n\n*********************************\n");
		printf("*\t\t\t\t*\n*\t\t\t\t*\n*\t\t\t\t*\n*\t    WELCOME\t\t*\n*\t      TO\t\t*\n*\t  TIC TAC TOE\t\t*\n*\t\t\t\t*\n*\t\t\t\t*\n*\t\t\t\t*\n");
		printf("*********************************\n\n");
		
		printf("\tPRESS ANY KEY TO BEGIN\n");
		scanf("%c",&enter);
		printf(" 1.New Game\t2.Scoreboard\t3.Instructions\t4.Exit\n");
		scanf("%d",&choice);

		switch(choice)
		{
			case 1:playGame();
			break;
			case 2:printScore();
			break;
			case 3:instruct();
			break;
			case 4:exit(0);

		}
	}
	return 0;
}