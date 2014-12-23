// Sean Staz
// 10-28-2014
// CSci_423

/* Program to compute Pi using Monte Carlo methods */
#include <stdio.h>
#include <string.h>
#include <pthread.h>
#include <math.h>
#include <stdlib.h>

int i         = 0;	
int amtWanted = 0;
int totalPts  = 0;

void *count(void *X)
{ 
    /* initialize random numbers */
    for (i=0; i < amtWanted; i++)
    {	
        double X = (double)rand() / RAND_MAX;
        double Y = (double)rand() / RAND_MAX;
        
        if (((X * X) + (Y * Y)) <= 1)
        {
            totalPts++;
        }
    }
    return NULL;
}

int main()
{
    printf("\n\nWelcome to Threaded Monte Carlo, by Sean Staz\n\n");
    srand(time(NULL));
    pthread_t thread;

    do
	{
        printf("Please enter a positive number for the amount of points you would like to generate? \n");
        scanf("%d", &amtWanted);  	
	}while (amtWanted <= 0);
  
    pthread_create(&thread, NULL, &count, NULL);
    pthread_join(thread, NULL);
    
    double points = 4.0 * totalPts;
    double pi = points / amtWanted;
    printf("The approximate value of pi for the desired amount of points (%d) is: %f \n", amtWanted, pi);  
    return 0;
}
