#include "Str.h"

int length(char * s) {
	int i = 0;
	while (s[i] != 0) {
		i++;
	}
	return i;
}
int cmp(char * s1, char * s2) {
	if (length(s1) != length(s2)) {
		return -1;
	}
	else {
		int isCmp = 0;
		for (int i = 0; i < length(s1); i++) {
			if (s1[i] != s2[i]) {
				isCmp = -1;
				break;
			}
		}
		return isCmp;
	}
}
