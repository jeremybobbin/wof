#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define WHITE_SPACE 0
#define TOKEN       1

int main() {
	int len, i, offset, prev = WHITE_SPACE;
	char buf[BUFSIZ];
	while ((len = read(0, buf, BUFSIZ)) > 0) {
		for (i = 0; i < len; i++) {
			if (!(isalpha(buf[i]))) {
				if (prev == TOKEN) {
					putchar('\n');
				}
				prev = WHITE_SPACE;
				continue;
			}
			if (prev == WHITE_SPACE) {
				printf("%d ", i + offset);
			}
			putchar(buf[i]);
			prev = TOKEN;
		}
		offset += i;
	}
}
