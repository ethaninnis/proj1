#include <stdio.h>

void EncryptRotation(int key, FILE *input, FILE *output); 
void DecryptRotation(int key, FILE *input, FILE *output); 
void EncryptSubstitution(char key[], FILE *input, FILE *output); 
void DecryptSubstitution(char key[], FILE *input, FILE *output); 

int main() {

    /*  This program program allows the user to select a task (rotation encryption, rotation decryption, substitution encryption, or substitution decryption), based off the user interface menu, and then a key,
        and the program will modify the text from an existing file and then print the resulting text to a different file.
        There is a function for each task.
        First the user will have to enter the files to encrypt/decrypt, then the file to print to, then based of the task they choose they will be prompted to enter the key to be used.
        */
    
    char InputFile[50];   // this will be what the user enters as the input file to read off, length 50 as this is more than enough to fit a file's name
    char OutputFile[50];   // similarly, but this time the output file, where the resulting text is printed to 
    int task;   // integer used for task selection, user is prompter to choose a number
    int RotationKey;    // integer used for the rotation key, user enters the rotation amount
    char SubstitutionKey[26];   // this array will be used to store the substitution alphabet, which is why its length it 26, this is used as the substitution key
    
    // user is now prompted to enter the name of the file which will be read from and encrypted/decrypted
    printf("\nEnter the name of the file you would like to encrypt/decrypt: ");
    scanf("%s", InputFile);
    FILE * input = fopen(InputFile, "r");
    if(input == NULL)  {   // this function prints an error if the entered file does not exist, then stops the program
        perror("fopen()");
        return 0;
    }
    
    // user is then prompted to enter the name of the file that the program will print to, with a similar error function
    printf("\nEnter the name of the file you would like to print to: ");
    scanf("%s", OutputFile);
    FILE * output = fopen(OutputFile, "w");
    if(input == NULL)  {
        perror("fopen()");
        return 0;
    }
  
    // task selection menu is then printed, with its corresponding integers
    printf("\nPlease enter the number corresponding to the task:\n(1) Rotation Encryption\n(2) Rotation Decryption\n(3) Substitution Encryption\n(4) Substitution Decryption\n");
    scanf("%d", &task);

    // if/else if statements cause the program to complete the task chosen by the user
    if (task == 1) {
        printf("\nEnter rotation key: ");  // prompts user to enter rotation key for encryption
        scanf("%d", &RotationKey);
        // the tasks all take place in seperate functions
        EncryptRotation(RotationKey, input, output);
        printf("\nEncryption complete!\n");
    } else if (task == 2) {
        printf("\nEnter rotation key: ");  // prompts user to enter rotation key for decryption
        scanf("%d", &RotationKey);
        DecryptRotation(RotationKey, input, output);
        printf("\nDecryption complete!\n");
       
    } else if (task == 3) {
        printf("\nEnter substitution key: ");  // prompts the user to enter the substitution alphabet key
        scanf("%s", SubstitutionKey);
        EncryptSubstitution(SubstitutionKey, input, output);
        printf("\nEncryption complete!\n");
    } else if (task == 4) {
        printf("\nEnter substitution key: ");
        scanf("%s", SubstitutionKey);
        DecryptSubstitution(SubstitutionKey, input, output);
        printf("\nDecryption complete!\n");
    } else {
        printf("\n'%d' is not a valid option.\n", task); // If the integer entered does not relate to a task, this will be printed as the user has not selected a valid option.
    }
    
fseek(output,-1L,SEEK_END);   // After some research I found that this eliminates the error where a character was added to the end of the output file, by moving one character space back and replacing it with a space.
fprintf(output, " ");
    
    return 0;
}

// function definitions

/* This function reads the text from the input file, and encrypts it using the rotation cipher. The inputs are the integer for the rotation amount, the input file, and the output file.
   It works by taking the ascii number for each letter, giving it a number corresponding to its place in the alphabet, and then adding the key and finding its modulus of 26, then adding 65 to make it the capital letter.
   If what is read is not a letter it will just be printed as it is.
   There is no return value (void), because the output is printed during the function, this is common to all the following functions as they operate similarly. 
   As all functions are reading from and printing to files, there are no restrictions to the length of text, but the key should be from 1-25
 */
void EncryptRotation(int key, FILE *input, FILE *output) { 
    while(feof(input) == 0)   {
    char character; // the character that is being read from the input file
    fscanf(input, "%c", &character);
        if (character >= 65 && character <= 90) { // only does this if it is a capital letter
            character = character - 65;
            character = (character + key) % 26;
            character = character + 65;
        } else if (character >= 97 && character <= 122) { // changes lower case to upper case while encrypting
            character = character - 97;
            character = (character + key) % 26;
            character = character + 65;
        }
        fprintf(output, "%c", character);
   
}
}

/* This function takes the integer of the rotation key, the input file, and output file, and then works similarly to the encryption function, but to decrypt it sort of does the opposite, subtracting the rotation key.
   Key should be from 1-25.
 */
void DecryptRotation(int key, FILE *input, FILE *output) { 
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

/* This function encrypts text from a file using a given substitution key and prints it to another file.
   It is given an array of the substitution alphabet, input and output file.
   It works by taking a letter from the input file, finding its position in the alphabet and then assigning it with the letter from that position in the substitution key.
   The substitution key must have 26 different characters entered correctly, this is somewhat a resistriction and is also an element of the next function.
 */
void EncryptSubstitution(char key[], FILE *input, FILE *output) {
    while(feof(input) == 0)   {
    char character;
    fscanf(input, "%c", &character);
    int LetterNumber;  // this integer is used to find the letters position in the substitution key
        if (character >= 65 && character <= 90) {  // only does this if it is a capital letter
            LetterNumber = character - 65;
            character = key[LetterNumber];
        } else if (character >= 97 && character <= 122) {  // changes lowercase to uppercase and encrypts
            LetterNumber = character - 97;
            character = key[LetterNumber];
        }
        fprintf(output, "%c", character);
        
}
}

/* This function reads from an input file, decrypts using the given substitution text, and prints to another file.
   Its inputs are the substitution alphabet array, and the input and output file.
   It works by counting up a position number until the letter at that position in the key is equal to the letter being read from the input file. Once it reaches the letter, it takes this position number and substitutes in the letter from the correct alphabet at that position, thus substituting the letter from the correct position.
   
 */
void DecryptSubstitution(char key[], FILE *input, FILE *output) {
    while(feof(input) == 0)   {
    char character;
    fscanf(input, "%c", &character);
    int PositionNumber; 
    char Alphabet[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";  // correct alphabet to compare the substitution key to 
        if (character >= 65 && character <= 90) {
            for (PositionNumber = 0; character != key[PositionNumber]; PositionNumber++) {  // counting method to find what letter in the substitution key is equal to the letter being substituted
            }
            character = Alphabet[PositionNumber];
            fprintf(output, "%c", character);
        } else if (character >= 97 && character <= 122) {  // decrypts lowercase text, prints it as uppercase
            character = character - 32; {
                for (PositionNumber = 0; character != key[PositionNumber]; PositionNumber++) {
                }
                character = Alphabet[PositionNumber];
                fprintf(output, "%c", character);
            }
        } else {  // this is so it will print things that aren't letters, just as they are
            fprintf(output, "%c", character);
        }
        
}
}
