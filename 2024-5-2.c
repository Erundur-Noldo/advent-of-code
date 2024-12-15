#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

/* fifth day by Emika
  ____
 /    \
| _  _ |
|      |
 \    /
  \  /
   \/
*/

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


uint count_rules(char *data) {
    int count = 0;
    while(*data != '\n') {
        data += 6;
        count++;
    }
    return count;
}

uint count_lines(char *data) {
    while(*data != '\n') data += 6;
    data++;

    int count = 0;
    while(1) {
        if(*data == '\n') {
            count++;
            if(*(data+1) == '\n') break;
        }
        data++;
    }
    return count;
}


void load_rules(char *data, int *before, int *after) {
    /* every line we have to analyze is of the following for: [digit][digit]|[digit][digit] */
    /* returns the number of rules */
    char *here = data;
    int i=0;
    while(*here != '\n') {
        before[i] = 10*(here[0]-'0') + (here[1]-'0');
        after[i]  = 10*(here[3]-'0') + (here[4]-'0');
        i++;
        here+=6;
    }
}


void load_lines(char *data, int *list_lengths, int **list) {
    /* returns the number of lines */
    char *here = data;
    while(*here != '\n') here+=6;
    here++;
    /* now we're at the start */
    int i=0;
    while(*here != '\n') {
        uint line_length = 0;
        while(here[line_length] != '\n') line_length++;


        int *this_line = malloc(line_length*sizeof(int));
        list[i] = this_line;
        list_lengths[i] = line_length/3+1;

        for(int j=0; j<line_length/3+1; j++) {
            this_line[j] = 10*(here[3*j] - '0') + (here[3*j+1] - '0');
        }
        here += line_length+1;
        i++;
    }
}



bool sort(int *line, int line_length, int *before, int *after, int num_rules) {
    for(int i=0; i<line_length; i++) {
        for(int j=0; j<num_rules; j++) {
            if(line[i] == after[j]) {
                for(int k=i; k<line_length; k++) {
                    if(line[k] == before[j]) {
                        int buffer = line[i];
                        line[i] = line[k];
                        line[k] = buffer;
                        return false;
                    }
                }
            }
        }
    }
    return true;
}

int order(int *line, int line_length, int *before, int *after, int num_rules) {
    /* returns the middle number after ordering, only for wrongly ordered ones */
    bool was_correct = true;
    was_correct = sort(line, line_length, before, after, num_rules);
    if(was_correct) return 0;

    while(!sort(line, line_length, before, after, num_rules));
    return line[line_length/2];
}







int main() {
    char data[100000];
    load_file("2024-5-input", data);


    uint num_rules = count_rules(data);
    uint num_lines = count_lines(data);

    // printf("%d, %d\n", num_rules, num_lines);

    int rule_before[num_rules];
    int rule_after[num_rules];
    int *lines[num_lines];
    int line_length[num_lines];


    load_rules(data, rule_before, rule_after);
    load_lines(data, line_length, lines);



    int answer = 0;
    for(int i=0; i<num_lines; i++) answer += order(lines[i], line_length[i], rule_before, rule_after, num_rules);
    printf("%d\n", answer);


    return 0;
}

