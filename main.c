#include <stdio.h>

void EncryptRotation(int key, FILE *input, FILE *output); //this function encrypts text using rotation, the inputs are the rotation key and plain text
void DecryptRotation(int key, FILE *input, FILE *output); //this function decrypts text using rotation, the inputs are the rotation key and cypher text
void EncryptSubstitution(char key[], FILE *input, FILE *output); //this function encrypts text using substitution, the inputs are the cypher key and plain text
void DecryptSubstitution(char key[], FILE *input, FILE *output); //this function decrypts text using substitution, the inputs are the cypher key and cypher text 

int main() {

    /*  the task is to create a program where a task will be selected, as well as a key, and then given a text to either decrypt or encrypt
        there will be a function for each task, with the function selected based on a variable entered or hard-coded
        then resulting text will then be printed to the user
        */
    FILE *input;
    FILE *output;
    input = fopen("input.txt", "r");
    output = fopen("output.txt", "w");
    int task = 4; //for task selection
    int RotationKey = 2; //rotation key
    char SubstitutionKey[] = "CBADEFGHIJKLMNOPQRSTUVWXYZ"; //hardcoded substitution key
    
    // for the final program the user will be prompted to enter the file name

    //now displays a menu and prompts the user to enter the task number
    //     printf("Please enter the number corresponding to the task:\n(1) Rotation Encryption\n(2) Rotation Decryption\n(3) Substitution Encryption\n(4) Substitution Decryption\n");
    //     scanf("%d", &task);

    if (task == 1) {
        // printf("\nEnter rotation key: ");  //prompts user to enter rotation key
        // scanf("%d", &RotationKey);
        // printf("Enter message to encrypt: ");  //prompts user to enter text, still unsure of how to scan the text

        //scanf("%c", &text);
        //repeatedly read in characters
        //if the number of characters read so far is above the max string length, 
        //terminate the string, and stop reading
        //if the character is not a newline, store it in a string
        //otherwise, terminate the string

        EncryptRotation(RotationKey, input, output);
    } else if (task == 2) {
        DecryptRotation(RotationKey, input, output);
    } else if (task == 3) {
        EncryptSubstitution(SubstitutionKey, input, output);
    } else if (task == 4) {
        DecryptSubstitution(SubstitutionKey, input, output);
    } else {
        printf("not a valid option\n"); // once scanf is implemented this could print the users selection
    }

    return 0;
}

// function definitions
void EncryptRotation(int key, FILE *input, FILE *output) { //this function is now working for what it can do
    //for each character c in text
    //set c in text to the rotated version of c
    while(feof(input) == 0)   {
    char character; //the character that is being read from the input file
    fscanf(input, "%c", &character);
        if (character >= 65 && character <= 90) { //only does this if it is a capital letter
            character = character - 65;
            character = (character + key) % 26;
            character = character + 65;
        } else if (character >= 97 && character <= 122) { //changes lower case to upper case while encrypting
            character = character - 97;
            character = (character + key) % 26;
            character = character + 65;
        }
        fprintf(output, "%c", character);
   
}
}

void DecryptRotation(int key, FILE *input, FILE *output) { //this function also works
   while(feof(input) == 0)   {
    char character;
    fscanf(input, "%c", &character);
    
        if (character >= 65 && character <= 90) {
            character = character - 65;
            character = (character - key + 26) % 26;
            character = character + 65;
        } else if (character >= 97 && character <= 122) {
            character = character - 97;
            character = (character - key + 26) % 26;
            character = character + 65;
        }
         fprintf(output, "%c", character);
        
    
}
}

void EncryptSubstitution(char key[], FILE *input, FILE *output) { //this function works
    while(feof(input) == 0)   {
    char character;
    fscanf(input, "%c", &character);
    int LetterNumber; //this int is used to the letter at a certain position in the key
        if (character >= 65 && character <= 90) { //only does this if it is a capital letter
            LetterNumber = character - 65;
            character = key[LetterNumber];
        } else if (character >= 97 && character <= 122) { //changes lower case to upper case and encrypts
            LetterNumber = character - 97;
            character = key[LetterNumber];
        }
        fprintf(output, "%c", character);
        
}
}

void DecryptSubstitution(char key[], FILE *input, FILE *output) {
    while(feof(input) == 0)   {
    char character;
    fscanf(input, "%c", &character);
    int PositionNumber; 
    char Alphabet[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ"; //correct alphabet to compare key to 
        if (character >= 65 && character <= 90) {
            for (PositionNumber = 0; character != key[PositionNumber]; PositionNumber++) { //counting method to find what letter in the substitution key is equal to the letter being substituted
            }
            character = Alphabet[PositionNumber];
            fprintf(output, "%c", character);
        } else if (character >= 97 && character <= 122) { //decrypts lowercase text
            character = character - 32; {
                for (PositionNumber = 0; character != key[PositionNumber]; PositionNumber++) {
                }
                character = Alphabet[PositionNumber];
                fprintf(output, "%c", character);
            }
        } else { //this is so it will print things that aren't letters, just as they are
            fprintf(output, "%c", character);
        }
        
    
}
}
