#ifndef _STUDENT_H
#define _STUDENT_H
#include <stdlib.h>
#include "Str.h"

typedef struct node {
	char * name;
	int code;
	struct node * next;
} Student;

void initStudent(Student * student);
void releaseStudent(Student * student);
Student * lastPoint(Student * student);
int findptr(Student * student, Student * p);
Student * findCode(Student * student, int code);
Student * findName(Student * student, char * name);
Student * findName(Student * student, char * name);
Student * PreNode(Student * student, Student * p);
Student * ForNode(Student * student, Student * p);
int addStudent(Student * student, int code, char * name);
void deleteStudent(Student * student, Student * p);

#endif // _STUDENT_H
