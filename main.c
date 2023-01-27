//A project to implement Caeasar shift cipher.

#include <stdio.h>
#include <ctype.h>

struct message_variables {
    int shift_size;
    char input_string[500];
    char result_answer[500];
    char ch;
};

int main() {

    struct message_variables cipher;

    printf("Enter input string:");
    fgets(cipher.input_string, 500, stdin);
    printf("Enter shift size: ");
    scanf("%i", &cipher.shift_size);

//    printf("The shift size is: %i\n", cipher.shift_size); // checking purposes
//    printf("Enter input string is: %s\n", cipher.input_string); // checking purposes

    for (int i = 0; cipher.input_string[i] != '\0'; ++i) {
        cipher.ch = cipher.input_string[i];

        if (isalnum(cipher.ch)) {

            if (islower(cipher.ch)) {
                cipher.ch = (cipher.ch - 'a' + cipher.shift_size) % 26 + 'a';
            }
            if (isupper(cipher.ch)) {
                cipher.ch = (cipher.ch - 'A' + cipher.shift_size) % 26 + 'A';
            }
            if (isdigit(cipher.ch)) {
                cipher.ch = (cipher.ch - '0' + cipher.shift_size) % 9 + '0';
            }
        }
        cipher.result_answer[i] += cipher.ch;
    }
    printf("answer: %s", cipher.result_answer);
    return 0;
}
