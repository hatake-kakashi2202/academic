
/************************ Function Definitions *********************/
#include <stdio.h>
#include <stdlib.h>
#include "grades.h"
#define MAX_GRADES  10  /* The max. number of grades per student. */


void PrintGrades(float grades[MAX_GRADES], int howmany){
  int i;  /* loop variable */

  for (i = 0; i < howmany; i++) {
    printf(" %.2f", grades[i]);
  }

  printf("\n");  /* end of line */
}


void AdjustGrades(float grades[MAX_GRADES],float adjustments[MAX_GRADES],int howmany){
  float newGrade;
  int i;  /* loop variable */

  for (i = 0; i < howmany; i++) {
    /* This two-step assignment can be done in one step. */
    newGrade = AdjustedGrade(grades[i], adjustments[i]);
    grades[i] = newGrade;
  }
}


float AdjustedGrade(float grade, float adjustment){
  grade += adjustment;
  return grade;
}