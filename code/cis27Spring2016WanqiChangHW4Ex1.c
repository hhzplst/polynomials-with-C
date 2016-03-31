/************************************************************
*   Program Name: cis27Spring2016WanqiChangHW4Ex1.c
*   Discussion:   Lab4 Exercise #1
*   Written By:   Wanqi Chang
*   Date:         2016/04/05
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
void subMenuWanqiC(void);
FractionPtrWanqi createFractionWanqiC(void);
int findGCDWanqiC(int, int);
PolyTermPtrWanqi createPolyTermWanqiC(void);
PolyNodePtrWanqi createPolyNodeWanqiC(void);
int insertPolyNodeWanqiC(PolyListPtrWanqi, PolyNodePtrWanqi);
FractionPtrWanqi addFractionWanqiC(FractionPtrWanqi, FractionPtrWanqi);
int removePolyNodeWanqiC(PolyListPtrWanqi, int);
void printPolyWanqiC(PolyNodePtrWanqi);
void displayPolyWanqiC(PolyListWanqi);

PolyListPtrWanqi addPolyWanqiC(PolyListWanqi, PolyListWanqi);
PolyListPtrWanqi multiplyPolyWanqiC(PolyListWanqi, PolyListWanqi);

//Program Drive

int main() {

  int mainSelection, subSelection, result;
  PolyNodePtrWanqi tempNodePtr = NULL;

  PolyListWanqi leftPolyList = NULL;
  PolyListWanqi rightPolyList = NULL;
  PolyListWanqi addResultPolyList = NULL;
  PolyListWanqi multiResultPolyList = NULL;

  PolyListPtrWanqi leftPolyListPtr = (PolyListPtrWanqi) malloc(
                                          sizeof(PolyListWanqi));

  PolyListPtrWanqi rightPolyListPtr= (PolyListPtrWanqi) malloc(
                                          sizeof(PolyListWanqi));

  PolyListPtrWanqi addResultPolyListPtr = (PolyListPtrWanqi) malloc(
                                            sizeof(PolyListWanqi));

  PolyListPtrWanqi multiResultPolyListPtr = (PolyListPtrWanqi) malloc(
                                            sizeof(PolyListWanqi));

  leftPolyListPtr = &leftPolyList;
  rightPolyListPtr = &rightPolyList;
  addResultPolyListPtr = &addResultPolyList;
  multiResultPolyListPtr = &multiResultPolyList;

  printf("CIS 27 - Data Structures and Algorithms\n"
         "Laney College\n"
         "Wanqi Chang\n\n"
         "Assignment Information --\n"
         "  Assignment Number:  Homework 04,\n"
         "                      Coding Assignment -- Excercise #1\n"
         "  Written by:         Wanqi Chang\n"
         "  Submitted Date:     2016/04/05\n");

  do {
    mainMenuWanqiC();
    scanf("%d", &mainSelection);

    switch(mainSelection) {
      case 1:
        if (addResultPolyList)
          free(addResultPolyList);
        if (multiResultPolyList)
          free(multiResultPolyList);
        do {
          subMenuWanqiC();
          scanf("%d", &subSelection);

          if (subSelection == 1){
            tempNodePtr = createPolyNodeWanqiC();
            result = insertPolyNodeWanqiC(leftPolyListPtr, tempNodePtr);

            if(result == 1)
              printf("\n\tPoly Node successfully inserted!");
            else
              printf("\n\t  Something went wrong!");
          } else if (subSelection == 2) {
              tempNodePtr = createPolyNodeWanqiC();
              result = insertPolyNodeWanqiC(rightPolyListPtr, tempNodePtr);

              if(result == 1)
                printf("\t  Poly Node successfully inserted!");
              else
                printf("\t  Something went wrong!");
          } else if (subSelection != 3)
            printf("\tYou should not be in this class!");
          
        } while (subSelection != 3);
        break;
      case 2:
        if (leftPolyList == NULL || rightPolyList == NULL)
          printf("\n\tBoth Left and Right Polylist should be created first!");
        else {
          printf("\n\tAdding the Polynomials...");
          addResultPolyListPtr = addPolyWanqiC(leftPolyList, rightPolyList);
          printf("\n\tDone!");
        }
        break;
      case 3:
        if (leftPolyList == NULL || rightPolyList == NULL)
          printf("\t  Both Left and Right Polylists should be created first!");
        break;
      case 4:
        printf("\n\tLeft Poly Pointer: %p\n", leftPolyList);
        displayPolyWanqiC(leftPolyList);

        printf("\n\tRight Poly Pointer: %p\n", rightPolyList);
        displayPolyWanqiC(rightPolyList);

        printf("\n\tLastest Add Result Pointer\n\t(perform another add operation to see the new result): %p\n", 
                                                                                      *addResultPolyListPtr);
        displayPolyWanqiC(*addResultPolyListPtr);

        printf("\n\tLastest Multiply Result Pointer\n\t(perform another add operation to see the new result): %p\n", 
                                                                                      *multiResultPolyListPtr);
        displayPolyWanqiC(*multiResultPolyListPtr);
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

  printf("\n\n*******************************\n"
           "*     POLYNOMIAL OPERATIONS   *\n"
           "* 1.  Creating polynomials    *\n"
           "* 2.  Adding polynomials      *\n"
           "* 3.  Multiplying polynomials *\n"
           "* 4.  Displaying polynomials  *\n"
           "* 5.  Clearing polynomials    *\n"
           "* 6.  Quit                    *\n"
           "*******************************\n"
            "Select the option (1 through 6): ");

}

void subMenuWanqiC() {

  printf("\n\n  ***************************\n"
           "  *     CREATE POLYNOMIAL   *\n"
           "  * 1.  Left Polynomial     *\n"
           "  * 2.  Right polynomial    *\n"
           "  * 3.  Back                *\n"
           "  ***************************\n"
           "  Select the option (1 through 3): ");

}

FractionPtrWanqi createFractionWanqiC() {
  int numTemp, denomTemp, gcd;
  FractionPtrWanqi myFractionPtr = NULL;

  myFractionPtr = (FractionPtrWanqi) malloc(sizeof(FractionWanqi));

  printf("\n\tCreating the Coefficient..."
         "\n\tPlease Enter the Numerator: ");
  scanf("%d", &numTemp);
  do {
    printf("\tPlease Enter a valid Denominator: ");
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
  printf("\n\tCreating a Term...");

  do {
    printf("\n\tPlease Enter the order: ");
    scanf("%d", &order);
  } while (order < 0);

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

int insertPolyNodeWanqiC(PolyListPtrWanqi myListPtr, 
                                        PolyNodePtrWanqi myNodePtr) {
  int found = 0;
  FractionPtrWanqi tempFractionPtr = NULL;
  PolyNodePtrWanqi currentNodePtr = *myListPtr;

  if (*myListPtr == NULL) {
    *myListPtr = myNodePtr;
  } else if (currentNodePtr->next == NULL){
    //one node in ths list
    if(myNodePtr->ptPtr->ex == currentNodePtr->ptPtr->ex) {
      //adding the coefficient
      tempFractionPtr = addFractionWanqiC(currentNodePtr->ptPtr->coePtr, 
                                              myNodePtr->ptPtr->coePtr);
      //update the fraction ptr
      currentNodePtr->ptPtr->coePtr = tempFractionPtr;
      //free Term and Node 
      free(myNodePtr->ptPtr);
      free(myNodePtr);
    } else if (myNodePtr->ptPtr->ex > currentNodePtr->ptPtr->ex) {
      *myListPtr = myNodePtr;
      myNodePtr->next = currentNodePtr;
    } else 
      currentNodePtr->next = myNodePtr;
  } else {
    // more than one node in the list
    if (myNodePtr->ptPtr->ex > currentNodePtr->ptPtr->ex) {
      *myListPtr = myNodePtr;
      myNodePtr->next = currentNodePtr;
    } else {
      while(currentNodePtr != NULL && found==0) {
        if(myNodePtr->ptPtr->ex == currentNodePtr->ptPtr->ex) {
          //adding the coefficient
          tempFractionPtr = addFractionWanqiC(currentNodePtr->ptPtr->coePtr, 
                                                  myNodePtr->ptPtr->coePtr);
          //update the fraction ptr
          currentNodePtr->ptPtr->coePtr = tempFractionPtr;
          //free Term and Node
          free(myNodePtr->ptPtr);
          found = 1;
        } else if (myNodePtr->ptPtr->ex < currentNodePtr->ptPtr->ex && 
                          currentNodePtr->next == NULL) {
          //currentNode is the last node in the list
          currentNodePtr->next = myNodePtr;
          found = 1;
        } else if (myNodePtr->ptPtr->ex > currentNodePtr->next->ptPtr->ex) {
          myNodePtr->next = currentNodePtr->next;
          currentNodePtr->next = myNodePtr;
          found = 1;
        } 
        currentNodePtr = currentNodePtr->next;
      }
    }
  }

  return 1;
}

FractionPtrWanqi addFractionWanqiC(FractionPtrWanqi a, FractionPtrWanqi b) {
  int gcd, numTemp, denomTemp;
  FractionPtrWanqi resultFractionPtr = NULL;

  resultFractionPtr = (FractionPtrWanqi) malloc(sizeof(FractionWanqi));

  numTemp = (a->num)*(b->denom) + (b->num)*(a->denom);
  denomTemp = (a->denom)*(b->denom);
  gcd = findGCDWanqiC(numTemp, denomTemp);

  resultFractionPtr->num = numTemp/gcd;
  resultFractionPtr->denom = denomTemp/gcd;

  return resultFractionPtr;
}

void printPolyWanqiC(PolyNodePtrWanqi myPolyNodePtr) {
  int order = myPolyNodePtr->ptPtr->ex;
  int num = myPolyNodePtr->ptPtr->coePtr->num;
  int denom = myPolyNodePtr->ptPtr->coePtr->denom;
  int adjNum = (num>0)? num:-num;

  if (num>0) {
    if (order ==0)
      printf(" + %d/%d", adjNum, denom);
    else
      printf(" + %d/%dx%d", adjNum, denom, order);
  } else {
    if (order ==0)
      printf(" - %d/%d", adjNum, denom);
    else
      printf(" - %d/%dx%d", adjNum, denom, order);
  }
}

void displayPolyWanqiC(PolyListWanqi myPolyList) {
  PolyNodePtrWanqi currentNodePtr = myPolyList;
  if (myPolyList != NULL) {
    //printing first node
    if (currentNodePtr->ptPtr->ex == 0)
      printf("\t  %d/%d", currentNodePtr->ptPtr->coePtr->num, currentNodePtr->ptPtr->coePtr->denom);
    else
      printf("\t  %d/%dx%d", currentNodePtr->ptPtr->coePtr->num, currentNodePtr->ptPtr->coePtr->denom, 
                                                                    currentNodePtr->ptPtr->ex);
    currentNodePtr = currentNodePtr->next;
    while(currentNodePtr) {
      if (currentNodePtr->ptPtr->coePtr->num != 0)
        printPolyWanqiC(currentNodePtr);
      currentNodePtr = currentNodePtr->next;
    }
  } else {
    printf("\t  Empty List!");
  }
}

PolyListPtrWanqi addPolyWanqiC(PolyListWanqi leftPolyList, PolyListWanqi rightPolyList) {
  PolyListPtrWanqi resultPolyListPtr = (PolyListPtrWanqi) malloc(sizeof(PolyListWanqi));

  PolyTermPtrWanqi tempPolyTermPtr = (PolyTermPtrWanqi) malloc(sizeof(PolyTermWanqi));
  PolyNodePtrWanqi tempPolyNodePtr = (PolyNodePtrWanqi) malloc(sizeof(PolyNodeWanqi));
  tempPolyNodePtr->ptPtr = tempPolyTermPtr;

  tempPolyNodePtr->next = NULL;
  *resultPolyListPtr = tempPolyNodePtr;

  PolyNodePtrWanqi currentLeftNodePtr = leftPolyList;
  PolyNodePtrWanqi currentRightNodePtr = rightPolyList;

  FractionPtrWanqi tempFractionPtr = NULL;

  while (currentLeftNodePtr && currentRightNodePtr) {
    
    if (currentLeftNodePtr->ptPtr->ex > currentRightNodePtr->ptPtr->ex) {
      tempPolyNodePtr->ptPtr = currentLeftNodePtr->ptPtr;
      currentLeftNodePtr = currentLeftNodePtr->next;
    } else if (currentLeftNodePtr->ptPtr->ex < currentRightNodePtr->ptPtr->ex) {
      tempPolyNodePtr->ptPtr = currentRightNodePtr->ptPtr;
      currentRightNodePtr = currentRightNodePtr->next;
    } else {
      tempFractionPtr = addFractionWanqiC(currentLeftNodePtr->ptPtr->coePtr, currentRightNodePtr->ptPtr->coePtr);
      tempPolyNodePtr->ptPtr->ex = currentLeftNodePtr->ptPtr->ex;
      tempPolyNodePtr->ptPtr->coePtr= tempFractionPtr;
      currentLeftNodePtr = currentLeftNodePtr->next;
      currentRightNodePtr = currentRightNodePtr->next;
    }
    if (currentLeftNodePtr && currentRightNodePtr) {
      tempPolyNodePtr->next = (PolyNodePtrWanqi) malloc(sizeof(PolyNodeWanqi));
      tempPolyNodePtr = tempPolyNodePtr->next;
      tempPolyNodePtr->next = NULL;
    }
  }
  while (currentLeftNodePtr || currentRightNodePtr) {
    tempPolyNodePtr->next = (PolyNodePtrWanqi) malloc(sizeof(PolyNodeWanqi));
    tempPolyNodePtr = tempPolyNodePtr->next;
    tempPolyNodePtr->next = NULL;
    if (currentLeftNodePtr) {
      tempPolyNodePtr->ptPtr = currentLeftNodePtr->ptPtr;
      currentLeftNodePtr = currentLeftNodePtr->next;
    }
    if (currentRightNodePtr) {
      tempPolyNodePtr->ptPtr = currentRightNodePtr->ptPtr;
      currentRightNodePtr = currentRightNodePtr->next;
    }
  }
  return resultPolyListPtr;
}
















































/********************OUTPUT***********************



******************END OF OUTPUT*******************/


/********************COMMENT**********************

                    NO COMMENT

**************************************************/