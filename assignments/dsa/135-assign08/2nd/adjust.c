#include <stdlib.h>
#include "grades.h"

#define MAX_GRADES  10  /* The max. number of grades per student. */

int main(){
  int i;                          /* Looping variable.                   */
  float adjustments[MAX_GRADES];  /* Grade adjustments for all students. */
  int numGrades;                  /* Number of adjustments.              */
  int numStudents;                /* Number of students.                 */
  int studentNum;                 /* Index of current student.           */
  float grades[MAX_GRADES];       /* Grades for current student.         */

  printf("How many grades per student? ");
  scanf("%d", &numGrades);

  if (numGrades < 1 || numGrades > MAX_GRADES) {
    printf("I can only handle 1..%d grades!", MAX_GRADES);
    exit(1);  /* Terminate program, return error status. */
  }

  i = 0;

  while (i < numGrades) {
    printf("\nEnter an adjustment> ");
    scanf("%f", &adjustments[i++]);
  }

  printf("\nHow many students? ");
  scanf("%d", &numStudents);

  for (studentNum = 1; studentNum <= numStudents; studentNum++) {
    printf("\n");  /* Blank line */

    /* Get each grade for the current student. */

    printf("Student #%d\n", studentNum);

    for (i = 0; i < numGrades; i++) {
      printf("\nEnter grade for HW%d> ", i+1);
      scanf("%f", &grades[i]);
    }

    /* Print grades before and after adjustment. */

    printf("\n\nOld Student #%d grades:", studentNum);
    PrintGrades(grades, numGrades);

    AdjustGrades(grades, adjustments, numGrades);

    printf("\nNew Student #%d grades:", studentNum);
    PrintGrades(grades, numGrades);
  }

  return 0;
}

