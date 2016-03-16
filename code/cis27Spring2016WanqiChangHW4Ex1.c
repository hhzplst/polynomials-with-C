/************************************************************
*   Program Name: cis27Spring2016WanqiChangHW4Ex1.c
*   Discussion:   Lab4 Exercise #1
*   Written By:   Wanqi Chang
*   Date:         2016/03/
************************************************************/

#include <stdio.h>
#include <stdlib.h>

//Type Definitions

struct FractionWanqiC { 
  int num;
  int denom; 
};

struct PolyTermWanqiC { 
  int ex;
  struct FractionWanqiC* coePtr;
};

struct PolyNodeWanqiC {
  struct PolyTermWanqiC* ptPtr;
  struct PolyNodeWanqiC* next;
};

typedef struct FractionWanqiC FractionWanqi;
typedef struct PolyTermWanqiC PolyTermWanqi;
typedef struct PolyNodeWanqiC PolyNodeWanqi;

typedef FractionWanqi* FractionPtrWanqi;
typedef PolyTermWanqi* PolyTermPtrWanqi;
typedef PolyNodeWanqi* PolyNodePtrWanqi;

typedef PolyNodePtrWanqi PolyListWanqi;
typedef PolyListWanqi* PolyListPtrWanqi;

//Function Prototypes

void mainMenuWanqiC(void);
FractionPtrWanqi createFractionWanqiC(void);
int findGCDWanqiC(int, int);
PolyTermPtrWanqi createPolyTermWanqiC(void);
PolyNodePtrWanqi createPolyNodeWanqiC(void);


//Program Drive

int main() {

  int mainSelection;

  printf("CIS 27 - C Programming\n"
         "Laney College\n"
         "Wanqi Chang\n\n"
         "Assignment Information --\n"
         "  Assignment Number:  Homework 04,\n"
         "                      Coding Assignment -- Excercise #1\n"
         "  Written by:         Wanqi Chang\n"
         "  Submitted Date:     2016/03/29\n");

  do {
    mainMenuWanqiC();
    scanf("%d", &mainSelection);

    switch(mainSelection) {
      case 1:
        break;
      case 2:
        break;
      case 3:
        break;
      case 4:
        break;
      case 5:
        break;
      case 6:
        exit(0);
      default:
        printf("\tYou should not be in this class!");
    }

  } while (mainSelection != 6);

  return 0;
}

//Function Definitions

void mainMenuWanqiC() {

  printf("\n*********************************\n"
             "*     POLYNOMIAL OPERATIONS   *\n"
             "* 1.  Creating polynomials    *\n"
             "* 2.  Adding polynomials      *\n"
             "* 3.  Multiplying polynomials *\n"
             "* 4.  Displaying polynomials  *\n"
             "* 5.  Clearing polynomials    *\n"
             "* 6.  Quit                    *\n"
             "************************************\n"
             "Select the option (1 through 6): ");

}

FractionPtrWanqi createFractionWanqiC() {
  int numTemp, denomTemp, gcd;
  FractionPtrWanqi myFractionPtr = NULL;

  myFractionPtr = (FractionPtrWanqi) malloc(sizeof(FractionWanqi));

  printf("\n       Please Enter the Numerator: ");
  scanf("%d", &numTemp);
  do {
    printf("\n       Please Enter a valid Denominator: ");
    scanf("%d", &denomTemp);
  } while (denomTemp == 0);

  gcd = findGCDWanqiC(numTemp, denomTemp);
  myFractionPtr->num = numTemp/gcd;

  if (denomTemp < 0) {
    myFractionPtr->num = -myFractionPtr->num;
    myFractionPtr->denom = -denomTemp/gcd;
  } else
    myFractionPtr->denom = denomTemp/gcd;

  return myFractionPtr;
}

int findGCDWanqiC(int n, int m) {
  int gcd, remainder;
  
  while(n != 0) {
    remainder = m % n;
    m = n;
    n = remainder;
  } 
    gcd = m;
   
    if (gcd < 0)
      return -gcd;
    else
      return gcd;
}

PolyTermPtrWanqi createPolyTermWanqiC() {
  int order;
  PolyTermPtrWanqi myPolyTermPtr = NULL;
  FractionPtrWanqi tempFractionPtr = NULL;

  myPolyTermPtr = (PolyTermPtrWanqi) malloc(sizeof(PolyTermWanqi));

  do {
    printf("\n       Please Enter the order: ");
    scanf("%d", &order);
  } while (order > 0);

  tempFractionPtr = createFractionWanqiC();
  myPolyTermPtr->ex = order;
  myPolyTermPtr->coePtr = tempFractionPtr;

  return myPolyTermPtr;
}

PolyNodePtrWanqi createPolyNodeWanqiC() {
  PolyNodePtrWanqi myPolyNodePtr = NULL;
  PolyTermPtrWanqi tempPolyTermPtr =NULL;

  myPolyNodePtr = (PolyNodePtrWanqi) malloc(sizeof(PolyNodeWanqi));
  tempPolyTermPtr = createPolyTermWanqiC();

  myPolyNodePtr->ptPtr = tempPolyTermPtr;
  myPolyNodePtr->next = NULL;

  return myPolyNodePtr;
}



/********************OUTPUT***********************



******************END OF OUTPUT*******************/


/********************COMMENT**********************

                    NO COMMENT

**************************************************/