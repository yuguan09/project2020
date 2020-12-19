#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<cs50.h>


#define range 40


float tmp(float a,float b);
float nor(float a,float b);


int main(void)
{
    int n=get_int("dimension: ");
    
    float input[range][range];
    float output[range][range];
    float normal[range];
    float hot[range][range];

    int i,j,k;

    for(j=0;j<n;j++){
        input[0][j]=get_float("input the %d: ",j+1);
        normal[0]=tmp(input[0][j],normal[0]);
    }
//printf("%f\n",input[0][0]);
//printf("%f\n",normal[0]);

    for(j=0;j<n;j++){
        output[0][j]=nor(normal[0],input[0][j]);
    }
//printf("%f\n",output[0][0]);
    
    for(i=1;i<n;j++){
        for(j=0;j<n;j++){
            for(k=0;k<n;k++){
                input[i][k]=get_float("input the %d: ",k+1);
            }
        }
    }
    
    
    
}




float tmp(float a,float b)
{
    float c;
    c=a*a+b;
    return c;
}

float nor(float a,float b)
{
    float c;
    c=1/sqrt(a)*b;
    return c;
}