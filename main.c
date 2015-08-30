#include <stdio.h>
#include <stdlib.h>
#include "Student.h"
#include "Str.h"

int main() {
	Student * student = malloc(sizeof(Student));
	initStudent(student);
	addStudent(student, 20142397, "Hoang Kien");
	addStudent(student, 20145583, "Tran Khanh");
	addStudent(student, 20143274, "Nguyen Nhai");
	addStudent(student, 20142397, "Nhan");
	Student * p = findCode(student, 20143274);
	PreNode(student, p);
	ForNode(student, p);
	findCode(student, 2014354);
	findName(student, "Ho3ng Kien");
	deleteStudent(student, findCode(student, 20145583));
	releaseStudent(student);
	return 0;
}
