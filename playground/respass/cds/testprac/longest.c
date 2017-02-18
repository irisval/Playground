#include <stdio.h>
#include <ctype.h>

int main() {
	int ch;
	int lineNum=1;
	int current=0;
	int longest=0;
	int longestLine=0;

	ch = getchar();
	while (ch != EOF) {
		if (ch == '\n') {
			
			if (current > longest) {
				longest = current;
				longestLine = lineNum;
			}
			lineNum++;
			current = 0;
		}
		else {
			current++;
		}
		ch = getchar();
	}
	if (current > longest) {
		longest = current;
		longestLine = lineNum;
	}
	printf ("Line %d is longest, with %d characters\n", longestLine, longest);
}