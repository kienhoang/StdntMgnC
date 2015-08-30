#include "Student.h"

void initStudent(Student * student) {
	student->code = 0;
	student->name = "";
	student->next = 0;
}
void releaseStudent(Student * student) {
	Student * p = student;
	while (1) {
		if (p->next != 0) {
			Student * n = p->next;
			free(p);
			p = n;
		}
		else {
			free(p);
			break;
		}
	}
}
Student * lastPoint(Student * student) {
	Student * p = student;
	while (p->next != 0) {
		p = p->next;
	}
	return p;
}
Student * findCode(Student * student, int code) {
	Student * p = student;
	int isFound = 0;
	while (1) {
		if (p->code == code) {
			isFound = 1;
			break;
		}
		p = p->next;
		if (p == 0) {
			break;
		}
	}
	return p;
}
Student * findName(Student * student, char * name) {
	Student * p = student;
	int isFound = 0;
	while (1) {
		if (cmp(p->name, name) == 0) {
			isFound = 1;
			break;
		}
		p = p->next;
		if (p == 0) {
			break;
		}
	}
	return p;
}

Student * PreNode(Student * student, Student * p) {
	Student * n = student;
	while (n->next != p) {
		n = n->next;
		if (n == 0) {
			break;
		}
	}
	return n;
}
Student * ForNode(Student * student, Student * p) {
	return p->next;
}

int addStudent(Student * student, int code, char * name) {
	if (findCode(student, code) == 0) {
		Student * p = lastPoint(student);
		if (student->name == "" && student->code == 0 && student->next == 0) {
			p->code = code;
			p->name = name;
			p->next = 0;
		}
		else {
			p->next = malloc(sizeof(Student));
			p->next->code = code;
			p->next->name = name;
			p->next->next = 0;
		}
		return 0;
	}
	else {
		return -1;
	}
}
void deleteStudent(Student * student, Student * p) {
	if (p == student) {
		if (student->next != 0) {
			p = p->next;
			student->name = student->next->name;
			student->code = student->next->code;
			student->next = student->next->next;
			free(p);
		}
		else {
			student->name = "";
			student->code = 0;
			student->next = 0;
		}
	}
	else if (p == lastPoint(student)) {
		PreNode(student, p)->next = 0;
		free(p);
	}
	else if(p != 0) {
		PreNode(student, p)->next = ForNode(student, p);
		free(p);
	}
}