//A project to implement ceasar shift cipher.

#include <stdio.h>
#include <string.h>
#include <ctype.h>

struct message_variables {
    int shift_size;
    char input_string[500];
};

int main() {

    struct message_variables cipher;

    char result_answer[500];

    printf("Enter input string:");
    fgets(cipher.input_string, 500, stdin);
    printf("Enter shift size: ");
    scanf("%i", &cipher.shift_size);

//    printf("The shift size is: %i\n", cipher.shift_size); // checking purposes
//    printf("Enter input string is: %s\n", cipher.input_string); // checking purposes

    char ch;

    for (int i = 0; cipher.input_string[i] != '\0'; ++i) {
        ch = cipher.input_string[i];

        if (isalnum(ch)) {

            if (islower(ch)) {
                ch = (ch - 'a' + cipher.shift_size) % 26 + 'a';
            }
            if (isupper(ch)) {
                ch = (ch - 'A' + cipher.shift_size) % 26 + 'A';
            }
        }
//        } else {
//            printf("Invalid Message");
//        }
        result_answer[i] += ch;
    }

    printf("answer: %s", result_answer);
    return 0;
}
