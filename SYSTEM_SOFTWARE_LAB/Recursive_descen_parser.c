#include<stdio.h>
#include<string.h>
#include<stdlib.h>

#define Error(str) (printf("Error!!:"str" \n"), abort())

/**
 * GRAMMER USED:
 *
 * E->TE'
 * E'->+TE'|
 * T->FT'
 * T'->*FT'|
 * F->(E)|
 */

int i=0;
char input[100];
void E_prime();
void T();
void T_prime();  
void F();

void advance()
{
  i++;
  while(isspace(input[i]))i++;
} 

void E()
{
  T();
  E_prime();
}

void E_prime()
{
  if(input[i]=='+')
    {
      advance();
      T();
      E_prime();
    }
}

void T()
{
  F();
  T_prime();
}

void T_prime()
{
  if(input[i]=='*')
    {
      advance();
      F();
      T_prime();
    }
}

void F()
{
  if(isalpha(input[i]))advance();
  else
    {
      if(input[i]=='(')
	{
	  advance();
	  E();
	  if(input[i]==')')advance();
	  else Error("Expected ) ");
	}
      else Error("Expected id ");
    }
}

main()
{
  printf("Enter the string:\n");
  fgets(input,100,stdin);
  E();
  if(i==strlen(input)) printf("Accepted\n");
  else Error("Unexpected end of string");
}


/**
   OUTPUT:
   _______
   
   s0901@T-R-SL-1-35:~/s6$ gcc re_pas.c
   s0901@T-R-SL-1-35:~/s6$ ./a.out 
   Enter the string:
   i+t
   Accepted
   s0901@T-R-SL-1-35:~/s6$ ./a.out 
   Enter the string:
   i*t+y
   Accepted
   s0901@T-R-SL-1-35:~/s6$ ./a.out 
   Enter the string:
   ((i+t)+e)*y
   Accepted
   s0901@T-R-SL-1-35:~/s6$ ./a.out 
   Enter the string:
   *y
   Error!!:Expected id  
   Aborted
   s0901@T-R-SL-1-35:~/s6$ ./a.out 
   Enter the string:
   a+
   Error!!:Expected id  
   Aborted
   s0901@T-R-SL-1-35:~/s6$ exit

*/
