# Hangman

## Description
Hangman is a classic guessing game where one player thinks of a word, and the other player(s) attempt to guess it by suggesting letters within a limited number of guesses.

## How to Build
The application is implemented in multiple languages including C, C++, and Python. 

### Building in C:
1. Ensure you have GCC installed.
2. Navigate to the C directory.
3. Run `gcc -o hangman hangman.c`.
4. Execute the program with `./hangman`.

### Building in C++:
1. Ensure you have g++ installed.
2. Navigate to the C++ directory.
3. Run `g++ -o hangman hangman.cpp`.
4. Execute the program with `./hangman`.

### Building in Python:
1. Ensure you have Python installed.
2. Navigate to the Python directory.
3. Run `python hangman.py`.

## Functionality

### Game Mechanics
- The game randomly selects a word from a predefined list or database.
- The player inputs their guess (usually individual letters or numbers).
- The game displays the guessed letters' positions in the word.
- If guessed correctly, the letter is displayed in the correct position; if guessed incorrectly, part of the hangman is drawn.
- The game continues until the word is guessed correctly or the hangman figure is fully drawn, indicating a loss.

### Use Cases
#### Player says “yes” or “no” to playing the game:
**Description:** The game prompts the player to start a new game. The player can choose to start the game or exit.
**Steps:**
1. The game displays a prompt asking if the player wants to play.
2. The player inputs "yes" to start the game or "no" to exit.
3. If "yes", the game proceeds to select a word and begin the guessing phase.
4. If "no", the game exits.

#### Given input is correct:
**Description:** The player guesses a letter that is part of the word.
**Steps:**
1. The player inputs a letter.
2. The game checks if the letter is in the word.
3. If the letter is in the word, the game displays the letter in its correct position(s).
4. The game prompts the player to guess another letter.

#### Given input is incorrect:
**Description:** The player guesses a letter that is not part of the word.
**Steps:**
1. The player inputs a letter.
2. The game checks if the letter is in the word.
3. If the letter is not in the word, the game draws a part of the hangman figure.
4. The game prompts the player to guess another letter.

#### Game finished: win or loss:
**Description:** The game concludes either with the player guessing the word correctly or the hangman figure being fully drawn.
**Steps:**
1. The player continues to guess letters.
2. If the player guesses all letters correctly before the hangman is fully drawn, the game announces a win.
3. If the hangman figure is fully drawn before the word is guessed, the game announces a loss.
4. The game offers the player an option to play again or exit.
