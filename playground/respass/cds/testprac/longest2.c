#include <stdio.h>
#include <ctype.h>

int main() {
	int ch;
	int line=1;
	int current=0;
	int longest=0;
	int longest_line=0;

	ch = getchar();

	while (ch != EOF) {
		if (ch=='\n') {
			if (current>longest) {
				longest=current;
				longest_line=line;
			}
			line++;
			current=0;
		}
		else {
			current++;
		}
		ch=getchar();
	}

	if (current>longest) {
				longest=current;
				longest_line=line;
	}
	printf("Line %d is the longest, with %d characters.", longest_line, longest);
}