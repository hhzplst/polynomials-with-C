/************************************************************
*   Program Name: cis27Spring2016WanqiChangLab4Ex1.c
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
}

typedef struct FractionWanqiC FractionWanqi;
typedef struct PolyTermWanqiC PolyTermWanqi;
typedef struct PolyNodeWanqiC PolyNodeWanqi;

typedef FractionWanqi* FractionPtrWanqi;
typedef PolyTermWanqi* PolyTermPtrWanqi;
typedef PolyNodeWanqi* PolyNodePtrWanqi;

typedef PolyNodePtrWanqi PolyListWanqi;
typedef PolyListWanqi* PolyListPtrWanqi;

//Function Prototypes

//Program Drive

//Function Definitions

/********************OUTPUT***********************



******************END OF OUTPUT*******************/


/********************COMMENT**********************

                    NO COMMENT

**************************************************/