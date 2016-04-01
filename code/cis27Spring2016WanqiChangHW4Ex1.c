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
void removeMenuWanqiC(void);

int findGCDWanqiC(int, int);
FractionPtrWanqi createFractionWanqiC(void);
FractionPtrWanqi addFractionWanqiC(FractionPtrWanqi, FractionPtrWanqi);
FractionPtrWanqi multiplyFractionWanqiC(FractionPtrWanqi, FractionPtrWanqi);

PolyTermPtrWanqi createPolyTermWanqiC(void);
PolyNodePtrWanqi createPolyNodeWanqiC(void);
PolyNodePtrWanqi createEmptyPolyNodeWanqiC(void);

int insertPolyNodeWanqiC(PolyListPtrWanqi, PolyNodePtrWanqi);
int removePolyNodeWanqiC(PolyListPtrWanqi, int);
int performRemovePolyNodeWanqiC(PolyListPtrWanqi);

void printPolyWanqiC(PolyNodePtrWanqi);
void displayPolyWanqiC(PolyListWanqi);

PolyListPtrWanqi addPolyWanqiC(PolyListWanqi, PolyListWanqi);
PolyListPtrWanqi multiplyPolyWanqiC(PolyListWanqi, PolyListWanqi);

//Program Drive

int main() {

  int mainSelection, subSelection, removeSelection, result;
  PolyNodePtrWanqi tempNodePtr = NULL;

  PolyListWanqi leftPolyList = NULL;
  PolyListWanqi rightPolyList = NULL;
  PolyListWanqi addResultPolyList = NULL;
  PolyListWanqi multiResultPolyList = NULL;

  PolyListPtrWanqi leftPolyListPtr = (PolyListPtrWanqi) malloc
                                        (sizeof(PolyListWanqi));

  PolyListPtrWanqi rightPolyListPtr= (PolyListPtrWanqi) malloc
                                        (sizeof(PolyListWanqi));

  PolyListPtrWanqi addResultPolyListPtr = (PolyListPtrWanqi) malloc
                                            (sizeof(PolyListWanqi));

  PolyListPtrWanqi multiResultPolyListPtr = (PolyListPtrWanqi) malloc
                                              (sizeof(PolyListWanqi));

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

          if (subSelection == 1) {
            tempNodePtr = createPolyNodeWanqiC();
            result = insertPolyNodeWanqiC(leftPolyListPtr, tempNodePtr);

            if (result == 1)
              printf("\n\tPoly Node successfully inserted!");
            else
              printf("\n\t  Something went wrong!");
          } else if (subSelection == 2) {
              tempNodePtr = createPolyNodeWanqiC();
              result = insertPolyNodeWanqiC(rightPolyListPtr, tempNodePtr);

              if (result == 1)
                printf("\n\tPoly Node successfully inserted!");
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
          printf("\n\tBoth Left and Right Polylists should be created first!");
        else {
          printf("\n\tMultiplying the Polynomials...");
          multiResultPolyListPtr = multiplyPolyWanqiC(leftPolyList, rightPolyList);
          printf("\n\tDone!");
        }
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
        do {
          removeMenuWanqiC();
          scanf("%d", &removeSelection);

          switch(removeSelection) {
            case 1:
              printf("\n\tRemoving from the Left Polynomial...");
              result = performRemovePolyNodeWanqiC(leftPolyListPtr);
              if (result == 1)
                printf("\n\tDone!");
              else
                printf("\n\tSomething went wrong...");
              break;
            case 2:
              printf("\n\tRemoving from the Right Polynomial...");
              result = performRemovePolyNodeWanqiC(rightPolyListPtr);
              if (result == 1)
                printf("\n\tDone!");
              else
                printf("\n\tSomething went wrong...");
              break;
            case 3:
              break;
            defalt:
              printf("\tWrong Option!");
          }
        } while (removeSelection != 3);
        break;
      case 6:
        printf("\n\tHaving Fun!\n");
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

void removeMenuWanqiC() {

  printf("\n\n  ***************************\n"
             "  *     CLEAR POLYNOMIAL    *\n"
             "  * 1.  Left Polynomial     *\n"
             "  * 2.  Right polynomial    *\n"
             "  * 3.  Back                *\n"
             "  ***************************\n"
             "  Select the option (1 through 3): ");

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

PolyNodePtrWanqi createEmptyPolyNodeWanqiC() {
  PolyNodePtrWanqi myPolyNodePtr = NULL;
  PolyTermPtrWanqi tempPolyTermPtr =NULL;

  myPolyNodePtr = (PolyNodePtrWanqi) malloc(sizeof(PolyNodeWanqi));
  tempPolyTermPtr = (PolyTermPtrWanqi) malloc(sizeof(PolyTermWanqi));

  myPolyNodePtr->ptPtr = tempPolyTermPtr;
  myPolyNodePtr->next = NULL;

  return myPolyNodePtr;
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

int insertPolyNodeWanqiC(PolyListPtrWanqi myListPtr, 
                                        PolyNodePtrWanqi myNodePtr) {
  int found = 0;
  FractionPtrWanqi tempFractionPtr = NULL;
  PolyNodePtrWanqi currentNodePtr = *myListPtr;

  if (*myListPtr == NULL) {
    *myListPtr = myNodePtr;
  } else if (currentNodePtr->next == NULL){
    //one node in ths list
    if (myNodePtr->ptPtr->ex == currentNodePtr->ptPtr->ex) {
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
        if (myNodePtr->ptPtr->ex == currentNodePtr->ptPtr->ex) {
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

FractionPtrWanqi multiplyFractionWanqiC(FractionPtrWanqi a, FractionPtrWanqi b) {
  int gcd, numTemp, denomTemp;
  FractionPtrWanqi resultFraction = NULL;

  resultFraction = (FractionPtrWanqi) malloc(sizeof(FractionWanqi));

  numTemp = (a->num)*(b->num);
  denomTemp = (a->denom)*(b->denom);
  gcd = findGCDWanqiC(numTemp, denomTemp);

  resultFraction->num = numTemp/gcd;
  resultFraction->denom = denomTemp/gcd;

  return resultFraction;
}

int removePolyNodeWanqiC(PolyListPtrWanqi myPolyListPtr, int order) {
  int found = 0, step = 0;
  PolyNodePtrWanqi prev = NULL;
  PolyNodePtrWanqi cur = *myPolyListPtr; 

  while(cur && !found) {
    if (cur->ptPtr->ex == order) {
      if (step == 0)
        *myPolyListPtr = cur->next;
      else {
        prev->next = cur->next;
        free(cur->ptPtr->coePtr);
        free(cur->ptPtr);
        free(cur);
      }
      found = 1;
    }
    prev = cur;
    cur = cur->next;
    step++;
  }
  
  if (found == 0) {
    printf("\t\nCan't find the node with order %d!", order);
    return 0; 
  }
  return 1;
}

int performRemovePolyNodeWanqiC(PolyListPtrWanqi myPolyListPtr) {
  int order, result;
  if (*myPolyListPtr == NULL) {
    printf("\n\tCan't remove from Empty List!");
    return 0;
  }
  printf("\n\tWhich order would you like to remove: ");
  scanf("%d", &order);

  result = removePolyNodeWanqiC(myPolyListPtr, order);

  return result;
}

void printPolyWanqiC(PolyNodePtrWanqi myPolyNodePtr) {
  int order = myPolyNodePtr->ptPtr->ex;
  int num = myPolyNodePtr->ptPtr->coePtr->num;
  int denom = myPolyNodePtr->ptPtr->coePtr->denom;
  int adjNum = (num>0)? num:-num;

  if (num>0) {
    if (order == 0)
      printf(" + %d/%d", adjNum, denom);
    else if (order == 1)
      printf(" + %d/%dx", adjNum, denom);
    else 
      printf(" + %d/%dx%d", adjNum, denom, order);
  } else {
    if (order ==0)
      printf(" - %d/%d", adjNum, denom);
    else if (order == 1)
      printf(" - %d/%dx", adjNum, denom);
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
  PolyNodePtrWanqi tempPolyNodePtr = createEmptyPolyNodeWanqiC();

  *resultPolyListPtr = tempPolyNodePtr;

  PolyNodePtrWanqi currentLeftNodePtr = leftPolyList;
  PolyNodePtrWanqi currentRightNodePtr = rightPolyList;

  FractionPtrWanqi tempFractionPtr = NULL;

  while(currentLeftNodePtr && currentRightNodePtr) {
    
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
      tempPolyNodePtr->next->ptPtr = (PolyTermPtrWanqi) malloc(sizeof(PolyTermWanqi));

      tempPolyNodePtr = tempPolyNodePtr->next;
      tempPolyNodePtr->next = NULL;
    }
  }

  while(currentLeftNodePtr || currentRightNodePtr) {
    tempPolyNodePtr->next = createEmptyPolyNodeWanqiC();

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

PolyListPtrWanqi multiplyPolyWanqiC(PolyListWanqi leftPolyList, PolyListWanqi rightPolyList) {
  int result;
  PolyListPtrWanqi resultPolyListPtr = (PolyListPtrWanqi) malloc(sizeof(PolyListWanqi));
  PolyNodePtrWanqi tempPolyNodePtr = NULL;

  PolyNodePtrWanqi currentLeftNodePtr = leftPolyList;
  PolyNodePtrWanqi currentRightNodePtr = NULL;

  FractionPtrWanqi tempFractionPtr = NULL;

  while(currentLeftNodePtr) {
    currentRightNodePtr = rightPolyList;
    while(currentRightNodePtr) {
      tempPolyNodePtr = createEmptyPolyNodeWanqiC();

      tempFractionPtr = multiplyFractionWanqiC(currentLeftNodePtr->ptPtr->coePtr, currentRightNodePtr->ptPtr->coePtr);
      tempPolyNodePtr->ptPtr->coePtr = tempFractionPtr;
      tempPolyNodePtr->ptPtr->ex = currentLeftNodePtr->ptPtr->ex + currentRightNodePtr->ptPtr->ex;
      result = insertPolyNodeWanqiC(resultPolyListPtr, tempPolyNodePtr);
      if (result == 0)
        printf("\n\t  Something went wrong...");
      currentRightNodePtr = currentRightNodePtr->next;
    }
    currentLeftNodePtr = currentLeftNodePtr->next;
  }
  return resultPolyListPtr;
}

/********************OUTPUT***********************

CIS 27 - Data Structures and Algorithms
Laney College
Wanqi Chang

Assignment Information --
  Assignment Number:  Homework 04,
                      Coding Assignment -- Excercise #1
  Written by:         Wanqi Chang
  Submitted Date:     2016/04/05


*******************************
*     POLYNOMIAL OPERATIONS   *
* 1.  Creating polynomials    *
* 2.  Adding polynomials      *
* 3.  Multiplying polynomials *
* 4.  Displaying polynomials  *
* 5.  Clearing polynomials    *
* 6.  Quit                    *
*******************************
Select the option (1 through 6): 1


  ***************************
  *     CREATE POLYNOMIAL   *
  * 1.  Left Polynomial     *
  * 2.  Right polynomial    *
  * 3.  Back                *
  ***************************
  Select the option (1 through 3): 1

  Creating a Term...
  Please Enter the order: 0

  Creating the Coefficient...
  Please Enter the Numerator: 5
  Please Enter a valid Denominator: 12

  Poly Node successfully inserted!

  ***************************
  *     CREATE POLYNOMIAL   *
  * 1.  Left Polynomial     *
  * 2.  Right polynomial    *
  * 3.  Back                *
  ***************************
  Select the option (1 through 3): 1

  Creating a Term...
  Please Enter the order: 2

  Creating the Coefficient...
  Please Enter the Numerator: 1
  Please Enter a valid Denominator: 1

  Poly Node successfully inserted!

  ***************************
  *     CREATE POLYNOMIAL   *
  * 1.  Left Polynomial     *
  * 2.  Right polynomial    *
  * 3.  Back                *
  ***************************
  Select the option (1 through 3): 1

  Creating a Term...
  Please Enter the order: 1

  Creating the Coefficient...
  Please Enter the Numerator: 3
  Please Enter a valid Denominator: 4

  Poly Node successfully inserted!

  ***************************
  *     CREATE POLYNOMIAL   *
  * 1.  Left Polynomial     *
  * 2.  Right polynomial    *
  * 3.  Back                *
  ***************************
  Select the option (1 through 3): 2

  Creating a Term...
  Please Enter the order: 2

  Creating the Coefficient...
  Please Enter the Numerator: 3
  Please Enter a valid Denominator: -7

  Poly Node successfully inserted!

  ***************************
  *     CREATE POLYNOMIAL   *
  * 1.  Left Polynomial     *
  * 2.  Right polynomial    *
  * 3.  Back                *
  ***************************
  Select the option (1 through 3): 2

  Creating a Term...
  Please Enter the order: 0

  Creating the Coefficient...
  Please Enter the Numerator: 2
  Please Enter a valid Denominator: 11

  Poly Node successfully inserted!

  ***************************
  *     CREATE POLYNOMIAL   *
  * 1.  Left Polynomial     *
  * 2.  Right polynomial    *
  * 3.  Back                *
  ***************************
  Select the option (1 through 3): 2

  Creating a Term...
  Please Enter the order: 1

  Creating the Coefficient...
  Please Enter the Numerator: 4
  Please Enter a valid Denominator: 9

  Poly Node successfully inserted!

  ***************************
  *     CREATE POLYNOMIAL   *
  * 1.  Left Polynomial     *
  * 2.  Right polynomial    *
  * 3.  Back                *
  ***************************
  Select the option (1 through 3): 2

  Creating a Term...
  Please Enter the order: 4

  Creating the Coefficient...
  Please Enter the Numerator: 1
  Please Enter a valid Denominator: 1

  Poly Node successfully inserted!

  ***************************
  *     CREATE POLYNOMIAL   *
  * 1.  Left Polynomial     *
  * 2.  Right polynomial    *
  * 3.  Back                *
  ***************************
  Select the option (1 through 3): 3


*******************************
*     POLYNOMIAL OPERATIONS   *
* 1.  Creating polynomials    *
* 2.  Adding polynomials      *
* 3.  Multiplying polynomials *
* 4.  Displaying polynomials  *
* 5.  Clearing polynomials    *
* 6.  Quit                    *
*******************************
Select the option (1 through 6): 4

  Left Poly Pointer: 0x7fac38500030
    1/1x2 + 3/4x + 5/12
  Right Poly Pointer: 0x7fac38500110
    1/1x4 - 3/7x2 + 4/9x + 2/11
  Lastest Add Result Pointer
  (perform another add operation to see the new result): 0x0
    Empty List!
  Lastest Multiply Result Pointer
  (perform another add operation to see the new result): 0x0
    Empty List!

*******************************
*     POLYNOMIAL OPERATIONS   *
* 1.  Creating polynomials    *
* 2.  Adding polynomials      *
* 3.  Multiplying polynomials *
* 4.  Displaying polynomials  *
* 5.  Clearing polynomials    *
* 6.  Quit                    *
*******************************
Select the option (1 through 6): 2

  Adding the Polynomials...
  Done!

*******************************
*     POLYNOMIAL OPERATIONS   *
* 1.  Creating polynomials    *
* 2.  Adding polynomials      *
* 3.  Multiplying polynomials *
* 4.  Displaying polynomials  *
* 5.  Clearing polynomials    *
* 6.  Quit                    *
*******************************
Select the option (1 through 6): 3

  Multiplying the Polynomials...
  Done!

*******************************
*     POLYNOMIAL OPERATIONS   *
* 1.  Creating polynomials    *
* 2.  Adding polynomials      *
* 3.  Multiplying polynomials *
* 4.  Displaying polynomials  *
* 5.  Clearing polynomials    *
* 6.  Quit                    *
*******************************
Select the option (1 through 6): 4

  Left Poly Pointer: 0x7fac38500030
    1/1x2 + 3/4x + 5/12
  Right Poly Pointer: 0x7fac38500110
    1/1x4 - 3/7x2 + 4/9x + 2/11
  Lastest Add Result Pointer
  (perform another add operation to see the new result): 0x7fac38500150
    1/1x4 + 4/7x2 + 43/36x + 79/132
  Lastest Multiply Result Pointer
  (perform another add operation to see the new result): 0x7fac38500210
    1/1x6 + 3/4x5 - 1/84x4 + 31/252x3 + 311/924x2 + 191/594x + 5/66

*******************************
*     POLYNOMIAL OPERATIONS   *
* 1.  Creating polynomials    *
* 2.  Adding polynomials      *
* 3.  Multiplying polynomials *
* 4.  Displaying polynomials  *
* 5.  Clearing polynomials    *
* 6.  Quit                    *
*******************************
Select the option (1 through 6): 5


  ***************************
  *     CLEAR POLYNOMIAL    *
  * 1.  Left Polynomial     *
  * 2.  Right polynomial    *
  * 3.  Back                *
  ***************************
  Select the option (1 through 3): 1

  Removing from the Left Polynomial...
  Which order would you like to remove: 0

  Done!

  ***************************
  *     CLEAR POLYNOMIAL    *
  * 1.  Left Polynomial     *
  * 2.  Right polynomial    *
  * 3.  Back                *
  ***************************
  Select the option (1 through 3): 2

  Removing from the Right Polynomial...
  Which order would you like to remove: 0

  Done!

  ***************************
  *     CLEAR POLYNOMIAL    *
  * 1.  Left Polynomial     *
  * 2.  Right polynomial    *
  * 3.  Back                *
  ***************************
  Select the option (1 through 3): 3


*******************************
*     POLYNOMIAL OPERATIONS   *
* 1.  Creating polynomials    *
* 2.  Adding polynomials      *
* 3.  Multiplying polynomials *
* 4.  Displaying polynomials  *
* 5.  Clearing polynomials    *
* 6.  Quit                    *
*******************************
Select the option (1 through 6): 4

  Left Poly Pointer: 0x7fac38500030
    1/1x2 + 3/4x
  Right Poly Pointer: 0x7fac38500110
    1/1x4 - 3/7x2 + 4/9x
  Lastest Add Result Pointer
  (perform another add operation to see the new result): 0x7fac38500150
    1/1x4 + 4/7x2 + 43/36x + 79/132
  Lastest Multiply Result Pointer
  (perform another add operation to see the new result): 0x7fac38500210
    1/1x6 + 3/4x5 - 1/84x4 + 31/252x3 + 311/924x2 + 191/594x + 5/66

*******************************
*     POLYNOMIAL OPERATIONS   *
* 1.  Creating polynomials    *
* 2.  Adding polynomials      *
* 3.  Multiplying polynomials *
* 4.  Displaying polynomials  *
* 5.  Clearing polynomials    *
* 6.  Quit                    *
*******************************
Select the option (1 through 6): 2

  Adding the Polynomials...
  Done!

*******************************
*     POLYNOMIAL OPERATIONS   *
* 1.  Creating polynomials    *
* 2.  Adding polynomials      *
* 3.  Multiplying polynomials *
* 4.  Displaying polynomials  *
* 5.  Clearing polynomials    *
* 6.  Quit                    *
*******************************
Select the option (1 through 6): 3

  Multiplying the Polynomials...
  Done!

*******************************
*     POLYNOMIAL OPERATIONS   *
* 1.  Creating polynomials    *
* 2.  Adding polynomials      *
* 3.  Multiplying polynomials *
* 4.  Displaying polynomials  *
* 5.  Clearing polynomials    *
* 6.  Quit                    *
*******************************
Select the option (1 through 6): 4

  Left Poly Pointer: 0x7fac38500030
    1/1x2 + 3/4x
  Right Poly Pointer: 0x7fac38500110
    1/1x4 - 3/7x2 + 4/9x
  Lastest Add Result Pointer
  (perform another add operation to see the new result): 0x7fac385000d0
    1/1x4 + 4/7x2 + 43/36x
  Lastest Multiply Result Pointer
  (perform another add operation to see the new result): 0x7fac385004a0
    1/1x6 + 3/4x5 - 3/7x4 + 31/252x3 + 1/3x2

*******************************
*     POLYNOMIAL OPERATIONS   *
* 1.  Creating polynomials    *
* 2.  Adding polynomials      *
* 3.  Multiplying polynomials *
* 4.  Displaying polynomials  *
* 5.  Clearing polynomials    *
* 6.  Quit                    *
*******************************
Select the option (1 through 6): 6

  Having Fun!                        

*********************END OF OUTPUT********************/

/***********************COMMENT************************

  Different approaches were used when implementing
  adding and multiplying functions.

  adding assumes that there's no previous implementation 
  of the function insertPolyNodeWanqiC() while multiplying
  takes advantage of the function in order to ensure
  that the resulting polynomial is in the decsending
  order based on the value of the exponents.

  very good excercise!

******************************************************/