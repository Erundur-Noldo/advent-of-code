/* seventh day */
/* I have been forgetting to free my shit the entire time, haven't I?? */
/* this one was quite fun except when it was about the size of the ints */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <stdint.h>

#define uchar unsigned char
#define ulong unsigned long



void load_file(char *filename, char *buffer) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        printf("oof it didn't load %s\n", filename);
        return;
    }

    char c;
    while((c = getc(file)) != EOF)
        if(c != ':') *buffer++ = c;
    *buffer = '\0';
}

uint count_lines(char *data) {
    uint counter = 0;
    while(*data++ != '\0')
        if(*data == '\n') 
            counter++;
    return counter;
}

uint line_length(char *data) {
    uint length=1;
    while(*data++ != '\n') 
        if(*data == ' ')
            length++;
    return length;
}

void read_lengths(char *data, uint *lengths) {
    lengths[0] = line_length(data);
    int i=1;
    while(*data != '\0') {
        if(*data == '\n')
            lengths[i++] = line_length(data+1);
        data++;
    }
}

int read_lines(char *data, uint *lengths, uint num_lines, uint64_t **lines) {

    for(int i=0; i<num_lines; i++) {
        int j=0;
        lines[i] = malloc(lengths[i] * sizeof(uint64_t));
        if(lines[i] == NULL) return 1;
        while(*data != '\n') {
            if(*data == ' ') {
                j++;
            } else {
                lines[i][j] *= 10;
                lines[i][j] += *data - '0';
            }
            data++;
        }
        data++;
    }
    return 0;

}


bool is_possible(uint64_t *a, uint length) {
    for(int i=0; i < 1<<(length-2); i++) { /*2^(n-1) options */
        uint64_t cul = a[1];
        for(int j=2; j<length; j++) {
            if((i & (1<<(j-2))) == 0) { /* why the *fuck* is & lower in precedence than == */
                cul += a[j];
            } else {
                cul *= a[j];
            }
        }

        if(cul == a[0]) return true;
    }
    return false;
}


bool is_possible_with_con(uint64_t *a, uint length) {
    for(long i=0; i < 1<<((length-2)*2); i++) {
        /* 00 ~ +
           01 ~ *
           10 ~ |
           11 ~ nothing */

        uint64_t cul = a[1];
        bool broken = false;
        for(long j=2; j<length; j++) {
            uchar choice = (i & (3<<((j-2)*2))) >> ((j-2)*2);
            if(choice == 0) {
                cul += a[j];
            } else if(choice == 1) {
                cul *= a[j];
            } else if(choice == 2) {
                uint64_t b = a[j];
                cul *= 10;
                while((b/=10) > 0) {
                    cul *= 10;
                }
                cul += a[j];
            } else if(choice == 3) {
                broken = true;
                break;
            }
        }
        if(!broken)
            if(cul == a[0]) return true;

    }


    return false;
}

ulong count_shit(uint64_t **line, bool *yes, uint num) {
    ulong counter=0;
    for(int i=0; i<num; i++) {
        counter += yes[i]*line[i][0];
    }
    return counter;
}





int main() {
    char data[100000];
    load_file("2024-7-input", data);

    uint num_lines = count_lines(data);

    uint line_length[num_lines];
    read_lengths(data, line_length);


    uint64_t *lines[num_lines]; /* tried int, tried long... oof, I have to use uint64_t I guess */
    if(read_lines(data, line_length, num_lines, lines) == 1) {
        printf("oops!\n");
        return 1;
    }




    bool possible[num_lines];
    for(int i=0; i<num_lines; i++) {
        possible[i] = is_possible(lines[i], line_length[i]);
    }

    ulong answer_one = count_shit(lines, possible, num_lines);
    printf("answer I:  %llu\n", answer_one); /* I had a bug for a while in that I tried to write as %u so it still only showed me the smol number... */




    for(int i=0; i<num_lines; i++) {
        possible[i] = is_possible_with_con(lines[i], line_length[i]);
    }
    ulong answer_two = count_shit(lines, possible, num_lines);
    printf("answer II: %llu\n", answer_two);




    for(int i=0; i<num_lines; i++)
        free(lines[i]);

    return 0;
}