/* this would be so much nicer to do with Haskell... */

#include <stdio.h>
#include <stdbool.h>


void load_file(char *filename, char *buffer) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        printf("oof it didn't load %s\n", filename);
        return;
    }

    char c;
    while((c = getc(file)) != EOF)
    	*buffer++ = c;
    buffer = '\0';
}


int count_shit(char *a) {
	int sum=0;
	bool do_ = true;
	while(*a != EOF) {
		if(do_) {
			if(*a == 'm' && *(a+1) == 'u' && *(a+2) == 'l' && *(a+3) == '(') {
				a += 4;
				int num_one = 0;
				int num_two = 0;
				while(*a >= '0' && *a <= '9') {
					num_one *= 10;
					num_one += *a - '0';
					a++;
				}

				if(*a != ',') continue;
				a++;

				while(*a >= '0' && *a <= '9') {
					num_two *= 10;
					num_two += *a - '0';
					a++;
				}

				if(*a != ')') continue;

				sum += num_one * num_two;
			} else if(a[0] == 'd' && a[1] == 'o' && a[2] == 'n' && a[3] == '\'' && a[4] == 't' && a[5] == '(' && a[6] == ')') {/* nice and cursed */
				do_ = false;
			}
		} else {
			if(a[0] == 'd' && a[1] == 'o' && a[2] == '(' && a[3] == ')') do_ = true;
		}
		a++;
	}
	return sum;
}






int main() {
	char input[20000];
	load_file("2024-3-input", input);

	int sum = count_shit(input);
	printf("%d\n", sum);

	return 0;
}