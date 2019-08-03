/*group members
  p.venkatesh
  v.ajay kumar
  s.sai jyothi kumar
  v.rohit pawar
  a.m.d.venkatesh
  p.sai veera pavan reddy*/
#include <stdio.h>
#include <string.h>

int main()
{
    int i = 0,j = 0, k = 0, l = 0, m = 0, n = 0, sum = 0, length, rem = 0, num = 0, num1 = 0, num2 = 0, num3 = 0, num4 = 0, num5 = 0;
    int a = 0, b = 0, c = 0, d = 0, e = 0, sum1 = 0,sum2 = 0,sum3 = 0, sum4 = 0,sum5 = 0;
    char result;
    char name[1000];
    char city1[100];
    char city2[100];
    char city3[100];
    char city4[100];
    char city5[100];


    printf("please enter your name:\n");
    gets(name);


    while(name[i] != '\0')
    {
        printf("\nthe ASCII value of the Character %c = %d\n", name [i], name [i]);
        sum = sum + name [i];
        i++;
    }
    printf("\n sum of all characters : %d \n", sum);
    num = sum % 9;
    if(num == 0)
        num = 9;
    else
        num = sum % 9;
    printf("\n your lucky number from your name is = %d\n", num);



    printf("enter 5 cities that you like one by one: \n");

    printf("enter 1stcity you like:\n");
    gets(city1);

    printf("enter 2ndcity you like:\n");
    gets(city2);

    printf("enter 3rdcity you like:\n");
    gets(city3);

    printf("enter 4thcity you like:\n");
    gets(city4);

    printf("enter 5thcity you like:\n");
    gets(city5);



    while(city1[j] != '\0')
    {
        printf("\nthe ASCII value of the Character %c = %d\n", city1 [j], city1 [j]);
        sum1 = sum1 + city1 [j];
        j++;
    }
    printf("\n sum of all characters : %d \n", sum1);
    num1 = sum1 % 9;
    if(num1 == 0)
        num1 = 9;
    else
        num1 = sum1 % 9;
    printf("\n lucky number of your city %s is = %d\n", city1, num1);



    while(city2[k] != '\0')
    {
        printf("\nthe ASCII value of the Character %c = %d\n", city2 [k], city2 [k]);
        sum2 = sum2 + city2 [k];
        k++;
    }
    printf("\n sum of all characters : %d \n", sum2);
    num2 = sum2 % 9;
    if(num2 == 0)
        num2 = 9;
    else
        num2 = sum2 % 9;
    printf("\n lucky number of your city %s is = %d\n", city2, num2);



    while(city3[l] != '\0')
    {
        printf("\nthe ASCII value of the Character %c = %d\n", city3[l], city3 [l]);
        sum3 = sum3 + city3 [l];
        l++;
    }
    printf("\n sum of all characters : %d \n", sum3);
    num3 = sum3 % 9;
    if(num3 == 0)
        num3 = 9;
    else
        num3 = sum3 % 9;
    printf("\n lucky number of your city %s is = %d\n", city3, num3);



    while(city4[m] != '\0')
    {
        printf("\nthe ASCII value of the Character %c = %d\n", city4 [m], city4 [m]);
        sum4 = sum4 + city4 [m];
        m++;
    }
    printf("\n sum of all characters : %d \n", sum4);
    num4 = sum4 % 9;
    if(num4 == 0)
        num4 = 9;
    else
        num4 = sum4 % 9;
    printf("\n lucky number of your city %s is = %d\n", city4, num4);



    while(city5[n] != '\0')
    {
        printf("\nthe ASCII value of the Character %c = %d\n", city5 [n], city5 [n]);
        sum5 = sum5 + city5 [n];
        n++;
    }
    printf("\n sum of all characters : %d \n", sum5);
    num5 = sum5 % 9;
    if(num5 == 0)
        num5 = 9;
    else
        num5 = sum5 % 9;
    printf("\n lucky number of your city %s is = %d\n\n\n\n", city5, num5);



    printf("\n your lucky number from your name is = %d\n", num);
    printf("\n lucky number of your city %s is = %d\n", city1, num1);
    printf("\n lucky number of your city %s is = %d\n", city2, num2);
    printf("\n lucky number of your city %s is = %d\n", city3, num3);
    printf("\n lucky number of your city %s is = %d\n", city4, num4);
    printf("\n lucky number of your city %s is = %d\n", city5, num5);


    if(num > num1)
        a = num - num1;
    else
        a = num1 - num;


    if(num > num2)
        b = num - num2;
    else
        b = num2 - num;


    if(num > num3)
        c = num - num3;
    else
        c = num3 - num;


    if(num > num4)
        d = num - num4;
    else
        d = num4 - num;


    if(num > num5)
        e = num - num5;
    else
        e = num5 - num;


    if(a<b&&a<c&&a<d&&a<e)
        printf("\nyou will do well if you join in %s\n",city1);
    else if(b<c&&b<d&&b<e)
        printf("\nyou will do well if you join in %s\n",city2);
    else if(c<d&&c<e)
        printf("\nyou will do well if you join in %s\n",city3);
    else if(d<e)
        printf("\nyou will do well if you join in %s\n",city4);
    else if(a==b||a==c||a==d||a==e||b==c||b==d||b==e||c==d||c==e||d==e)
    {

        char min_city [100];
        strcpy(min_city,city1);
        int min;

        min = a;

        if(min>b)
        {
            min == b ;
            min_city == city2;
        }
        else if(min==b)
        {
            if (strcmp(min_city,city2)>0)
            {
                strcpy(min_city,city2);
                min=b;
            }
        }


        if(min>c)
        {
            min == c ;
            min_city ==city3;
        }
        else if(min==c)
        {
            if (strcmp(min_city,city3)>0)
            {
                strcpy(min_city,city3);
                min=c;
            }
        }


        if(min>d)
        {
            min == d ;
            min_city == city4;
        }
        else if(min==d)
        {
            if (strcmp(min_city,city4)>0)
            {
                strcpy(min_city,city4);
                min=d;
            }
        }


        if(min>e)
        {
            min == e ;
            min_city == city5;
        }
        else if(min==e)
        {
            if (strcmp(min_city,city5)>0)
            {
                strcpy(min_city,city5);
                min=e;
            }
        }

        printf("\n\n\nyou will do well if you join in %s\n\n\n",min_city);
    }
    else
        printf("\n\n\nyou will do well if you join in %s\n\n\n",city5);


    return 0;
}
