#include <stdio.h>

void EncryptRotation(int key, FILE * input, FILE * output);
void DecryptRotation(int key, FILE * input, FILE * output);
void EncryptSubstitution(char key[], FILE * input, FILE * output);
void DecryptSubstitution(char key[], FILE * input, FILE * output);

int main() {

   /*  This program program allows the user to select a task (rotation encryption, rotation decryption, substitution encryption, or substitution decryption), based off the user interface menu, and then a key,and the program will modify the text from an existing file and then print the resulting text to a different file.
   There is a function for each task.
   First the user will have to enter the files to encrypt/decrypt, then the file to print to, then based of the task they choose they will be prompted to enter the key to be used.
   If the user enters an invalid file or task number, they will be notified and the program will not run.
       */

   char InputFile[50]; // This char array will be what the user enters as the input file to read off, length 50 as this is more than enough to fit a file's name
   char OutputFile[50]; // Similarly, but this time the output file, where the resulting text is printed to 
   int task; // Integer used for task selection, user is prompter to choose a number, corresponding to the task they want to do.
   int RotationKey; // Integer used for the rotation key, user enters the rotation amount.
   char SubstitutionKey[26]; // This array will be used to store the substitution alphabet, which is why its length it 26, this is used as the substitution key.

   // User is now prompted to enter the name of the file which will be read from and encrypted/decrypted.
   printf("\nEnter the name of the file you would like to encrypt/decrypt: ");
   scanf("%s", InputFile);  // The file name they enter is stored in the array InputFile.
   FILE * input = fopen(InputFile, "r");  // This function opens the file for reading.
   if (input == NULL) { 
      perror("fopen()");  // This function prints an error if the entered file does not exist, then stops the program.
      return 0;
   }

   // User is then prompted to enter the name of the file that the program will print to, with a similar error function.
   printf("\nEnter the name of the file you would like to print to: ");
   scanf("%s", OutputFile); // The file the user enters is stroed as OutputFile.
   FILE * output = fopen(OutputFile, "w");  // As the program needs to write to this output file, it is opened for writing.
   if (input == NULL) {
      perror("fopen()");
      return 0;
   }

   // Task selection menu is then printed, with its corresponding integers to guide the user.
   printf("\nPlease enter the number corresponding to the task:\n(1) Rotation Encryption\n(2) Rotation Decryption\n(3) Substitution Encryption\n(4) Substitution Decryption\n");
   scanf("%d", & task); // User enters the task number, the integer is then assigned to 'task'.

   // if/else if statements cause the program to complete the task chosen by the user, based on the value of 'task'.
   if (task == 1) {
      printf("\nEnter rotation key: "); // Prompts user to enter rotation key for encryption.
      scanf("%d", & RotationKey); // Gives RotationKey the value of the entered integer
      // The tasks all take place in seperate functions.
      EncryptRotation(RotationKey, input, output);
      printf("\nEncryption complete!\n");  // After each task is done, a completion message is printed to the screen.
   } else if (task == 2) {
      printf("\nEnter rotation key: "); // Prompts user to enter rotation key for decryption.
      scanf("%d", & RotationKey);  // Task operates very similarly to task 1.
      DecryptRotation(RotationKey, input, output);
      printf("\nDecryption complete!\n");

   } else if (task == 3) {
      printf("\nEnter substitution key: "); // Prompts the user to enter the substitution alphabet key.
      scanf("%s", SubstitutionKey); // This array of letters must be of length 26, as that is the chosen size for SubstitutionKey and is also the length of the alphabet it is replacing.
      EncryptSubstitution(SubstitutionKey, input, output);
      printf("\nEncryption complete!\n");
   } else if (task == 4) {
      printf("\nEnter substitution key: "); // Prompts user to enter the substitution alphabet.
      scanf("%s", SubstitutionKey); // The same concept as the last task, but this time the key is used to decrypt.
      DecryptSubstitution(SubstitutionKey, input, output);
      printf("\nDecryption complete!\n");
   } else {
      printf("\n'%d' is not a valid option.\n", task); // If the integer entered does not relate to a task, this will be printed as the user has not selected a valid option
   }

   fseek(output, -1L, SEEK_END);  // After some research I found that this eliminates the error where a character was added to the end of the output file, by moving one character space back and replacing the last character with a space.
   fprintf(output, " ");

   return 0;
}

// Function definitions:

/* This function reads the text from the input file, and encrypts it using the rotation cipher. The inputs are the integer for the rotation amount (RotationKey) , the input file, and the output file.
   It works by taking the ascii number for each letter, giving it a number corresponding to its place in the alphabet, and then adding the key and finding its modulus of 26, then adding 65 to make it the capital letter.
   If what is read is not a letter it will just be printed as it is.
   There is no return value (void), because the output is printed during the function, this is common to all the following functions as they operate similarly. 
   As all functions are reading from and printing to files, there are no restrictions to the length of text, but the key should be from 1-25
 */
void EncryptRotation(int key, FILE * input, FILE * output) {
   while (feof(input) == 0) { // Allows it to read until the end of the file.
      char character; // The character that is being read from the input file.
      fscanf(input, "%c", & character); // fscanf scans in one character at a time, allowing each to be manipulated.
      if (character >= 65 && character <= 90) { // Only does this if it is a capital letter.
         character = character - 65;
         character = (character + key) % 26;
         character = character + 65;
      } else if (character >= 97 && character <= 122) { // Changes lower case to upper case while encrypting.
         character = character - 97;
         character = (character + key) % 26;
         character = character + 65;
      }
      fprintf(output, "%c", character); // Once character is manipulated it prints it to the output file, then goes to the next character. This occurs at the end of each function.
   }
}

/* This function takes the integer of the rotation key, the input file, and output file, and then works similarly to the encryption function, but to decrypt it sort of does the opposite, subtracting the rotation key.
   Key should be from 1-25.
   Functionality is almost identical, refer to comments on previous function.
 */
void DecryptRotation(int key, FILE * input, FILE * output) {
   while (feof(input) == 0) {
      char character;
      fscanf(input, "%c", & character);
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
   It is given an array of the substitution alphabet (SubstitutionKey), input and output file.
   It works by taking a letter from the input file, finding its position in the alphabet and then assigning it with the letter from that position in the substitution key.
   The substitution key must have 26 different characters entered correctly, this is somewhat a resistriction and is also an element of the next function.
 */
void EncryptSubstitution(char key[], FILE * input, FILE * output) {
   while (feof(input) == 0) {
      char character;
      fscanf(input, "%c", & character); // Similar to how the other functions work.
      int LetterNumber; // This integer is used to find the letters position in the substitution key.
      if (character >= 65 && character <= 90) { // Only does this if it is a capital letter.
         LetterNumber = character - 65;
         character = key[LetterNumber]; // This is where the character is assigned the corresponding letter from the substitution key.
      } else if (character >= 97 && character <= 122) { // Changes lowercase to uppercase and encrypts.
         LetterNumber = character - 97;
         character = key[LetterNumber];
      }
      fprintf(output, "%c", character);
   }
}

/* This function reads from an input file, decrypts using the given substitution key, and prints to another file.
   Its inputs are the substitution alphabet array, and the input and output file.
   It works by counting up a position number until the letter at that position in the key is equal to the letter being read from the input file. Once it reaches the letter, it takes this position number and substitutes in the letter from the correct alphabet at that position, thus substituting the letter from the correct position.
 */
void DecryptSubstitution(char key[], FILE * input, FILE * output) {
   while (feof(input) == 0) {
      char character;
      fscanf(input, "%c", & character);
      int PositionNumber; // This integer is used to get the position of a letter in the substitution key.
      char Alphabet[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ"; // Correct alphabet to compare the substitution key to.
      if (character >= 65 && character <= 90) {
         for (PositionNumber = 0; character != key[PositionNumber]; PositionNumber++) { // Counting method to find what letter in the substitution key is equal to the letter being substituted. 
         }
         character = Alphabet[PositionNumber];  // Once the letters are the same, it uses this position number to assign the character its corresponding letter from the correct alphabet. 
         fprintf(output, "%c", character);  // Decrypted letter is then printed.
      } else if (character >= 97 && character <= 122) { // Decrypts lowercase text, prints it as uppercase.
         character = character - 32; {  // It first gets the character in the same range as before, then decrypts using the exact same method.
            for (PositionNumber = 0; character != key[PositionNumber]; PositionNumber++) {}
            character = Alphabet[PositionNumber];
            fprintf(output, "%c", character);
         }
      } else { // This is so it will print things that aren't letters, just as they are.
         fprintf(output, "%c", character);
      }
   }
}
