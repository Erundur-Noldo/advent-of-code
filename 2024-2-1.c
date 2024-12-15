/* advent of code 2024, 2.1 */

#include <stdio.h>
#include <stdlib.h>


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

/* this is very annoying.... */
int **interpert_input(char *input) {
	int input_size = 1;
	for(int i=0; input[i] != '\0'; i++) {
		if(input[i] == '\n') input_size++;
	}

	int **output = malloc(input_size * sizeof(int *));
	if(output == NULL) return NULL;


	int i=0;
	input--;
	do {
		int *a = malloc(8 * sizeof(int));
		if(a == NULL) return NULL;
		output[i] = a;
		a[0] = 0;
		for(int i=1; i<8; i++) a[i] = -1;

		input++;
		int j=0;
		while(*input == ' ' || (*input >= '0' && *input <= '9')) {
			if(*input == ' ') {
				j++;
				a[j] = 0;
			} else {
				a[j] *= 10;
				a[j] += *input - '0';
			}
			input++;
		}

		i++;
	} while (*input != '\0');

	return output;
}

int is_safe(int *a, int size) {
	if(size == 1) return 1;
	int direction = (a[0] < a[1])*2-1; /* plus or minus 1 */
	for(int i=0; i<size-1; i++) {
		if(a[i+1] == -1) return 1;
		int delta = a[i+1] - a[i];
		if(delta * direction < 1 || delta * direction > 3) return 0;
	}
	return 1;
}

int main() {
	char input[25000];
	load_file("2024-2-1-input", input);
	int **a = interpert_input(input);
	if(a == NULL) {
		printf("oh nooooo!!\n");
		return 1;
	}
	
	int total_safe = 0;
	for(int i=0; i<1000; i++) {
		total_safe += is_safe(a[i], 8);

		for(int j=0; j<8; j++) printf("%d, ", a[i][j]);
		printf("\n%d\n", is_safe(a[i], 8));
	}

	printf("%d\n", total_safe);


	return 0;
}