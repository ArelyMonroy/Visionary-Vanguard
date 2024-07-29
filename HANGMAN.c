#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include <time.h>

#define MAX_TRIES 6
#define WORD_COUNT 40

typedef struct {
    const char* word;
    const char* hint;
} WordHint;

void printHangman(int tries);
void printWord(char word[], int length, int correct[]);
int checkGuess(char guess, char word[], int length, int correct[]);
WordHint selectRandomWord();
WordHint getCustomWord();

int main() {
    srand(time(NULL)); // Seed for random number generator

    char choice;
    printf("Choose word source: \n1. Random from list \n2. Custom word\nEnter choice: ");
    scanf(" %c", &choice);

    WordHint wordHint;
    if (choice == '1') {
        wordHint = selectRandomWord();
    } else if (choice == '2') {
        wordHint = getCustomWord();
    } else {
        printf("Invalid choice. Exiting.\n");
        return 1;
    }

    const char* word = wordHint.word;
    const char* hint = wordHint.hint;
    int length = strlen(word);
    int correct[length];
    memset(correct, 0, sizeof(correct)); // Initialize all to 0 (false)

    printf("Hint: %s\n", hint);

    int tries = 0;
    int guessed = 0;
    char guess;

    while (tries < MAX_TRIES && !guessed) {
        printHangman(tries);
        printWord(word, length, correct);

        printf("\nEnter a guess: ");
        while (scanf(" %c", &guess) != 1 || !isalpha(guess)) {
            printf("Invalid input. Please enter a letter: ");
            while (getchar() != '\n'); // Clear the input buffer
        }
        guess = toupper(guess);

        if (!checkGuess(guess, word, length, correct)) {
            tries++;
        }

        guessed = 1;
        for (int i = 0; i < length; i++) {
            if (!correct[i]) {
                guessed = 0;
                break;
            }
        }
    }

    printHangman(tries);
    if (guessed) {
        printf("\nCongratulations! You guessed the word '%s'.\n", word);
    } else {
        printf("\nSorry, you lost. The word was '%s'.\n", word);
    }

    return 0;
}

void printHangman(int tries) {
    const char* hangman[] = {
        "  _______\n"
        " |     |\n"
        " |      \n"
        " |      \n"
        " |      \n"
        " |      \n"
        "_|_\n\n",

        "  _______\n"
        " |     |\n"
        " |     O\n"
        " |      \n"
        " |      \n"
        " |      \n"
        "_|_\n\n",

        "  _______\n"
        " |     |\n"
        " |     O\n"
        " |     |\n"
        " |      \n"
        " |      \n"
        "_|_\n\n",

        "  _______\n"
        " |     |\n"
        " |     O\n"
        " |    /|\n"
        " |      \n"
        " |      \n"
        "_|_\n\n",

        "  _______\n"
        " |     |\n"
        " |     O\n"
        " |    /|\\\n"
        " |      \n"
        " |      \n"
        "_|_\n\n",

        "  _______\n"
        " |     |\n"
        " |     O\n"
        " |    /|\\\n"
        " |    / \n"
        " |      \n"
        "_|_\n\n",

        "  _______\n"
        " |     |\n"
        " |     O\n"
        " |    /|\\\n"
        " |    / \\\n"
        " |      \n"
        "_|_\n\n"
    };

    printf("%s", hangman[tries]);
}

void printWord(char word[], int length, int correct[]) {
    printf("Word: ");
    for (int i = 0; i < length; i++) {
        if (correct[i]) {
            printf("%c ", word[i]);
        } else {
            printf("_ ");
        }
    }
    printf("\n");
}

int checkGuess(char guess, char word[], int length, int correct[]) {
    int found = 0;
    for (int i = 0; i < length; i++) {
        if (word[i] == guess && !correct[i]) {
            correct[i] = 1;
            found = 1;
        }
    }
    return found;
}

WordHint selectRandomWord() {
    static const WordHint wordHints[WORD_COUNT] = {
        {"PROGRAM", "A set of coded instructions"},
        {"COMPUTE", "To calculate"},
        {"HANGMAN", "The name of the game"},
        {"DEVELOPER", "A person who creates software"},
        {"PYTHON", "A popular programming language"},
        {"JAVA", "A programming language and computing platform"},
        {"HARDWARE", "The physical parts of a computer"},
        {"SOFTWARE", "The programs and other operating information"},
        {"ALGORITHM", "A process or set of rules to be followed"},
        {"DATABASE", "A structured set of data held in a computer"},
        {"NETWORK", "A group of interconnected computers"},
        {"SECURE", "To protect from threats"},
        {"CRYPTO", "Short for cryptography"},
        {"COMPILER", "A program that converts code into executable form"},
        {"DEBUG", "To identify and remove errors from code"},
        {"SCRIPT", "A file containing code to be executed"},
        {"VARIABLE", "A storage location paired with a symbolic name"},
        {"CLASS", "A blueprint for creating objects in OOP"},
        {"OBJECT", "An instance of a class in OOP"},
        {"INHERIT", "To derive characteristics from a parent class"},
        {"POLY", "Short for polymorphism in programming"},
        {"CHAIN", "A series of connected elements"},
        {"DECODE", "To convert into readable form"},
        {"BINARY", "A system of numerical notation"},
        {"ARRAY", "A collection of elements identified by index"},
        {"QUEUE", "A linear data structure following FIFO order"},
        {"STACK", "A linear data structure following LIFO order"},
        {"LINKED", "A type of list where elements point to next"},
        {"GRAPH", "A collection of nodes connected by edges"},
        {"HEAP", "A special tree-based data structure"},
        {"VECTOR", "A dynamic array"},
        {"TABLE", "A collection of data organized in rows and columns"},
        {"IMAGE", "A representation of visual information"},
        {"MODEL", "A representation of an object or system"},
        {"ENGINE", "A component that drives functionality"},
        {"QUERY", "A request for information from a database"},
        {"VALUE", "The worth assigned to a variable"},
        {"FORMAT", "To arrange or put into a specific form"},
        {"STRING", "A sequence of characters"}
    };
    return wordHints[rand() % WORD_COUNT];
}

WordHint getCustomWord() {
    static char customWord[100];
    static char customHint[100];

    printf("Enter a custom word: ");
    scanf("%s", customWord);
    printf("Enter a hint for the word: ");
    scanf(" %[^\n]s", customHint);

    // Convert word to uppercase
    for (int i = 0; customWord[i] != '\0'; i++) {
        customWord[i] = toupper(customWord[i]);
    }

    WordHint wordHint = {customWord, customHint};
    return wordHint;
}
