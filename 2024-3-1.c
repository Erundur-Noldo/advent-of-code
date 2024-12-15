/* this would be so much nicer to do with Haskell... */

#include <stdio.h>



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
	while(*a != EOF) {
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