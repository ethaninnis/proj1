#include <stdio.h>

 void EncryptRotation(int key, char text[]);   //this function encrypts text using rotation, the inputs are the rotation key and plain text
 void DecryptRotation(int key, char text[]);   //this function decrypts text using rotation, the inputs are the rotation key and cypher text
 void EncryptSubstitution(char key[], char text[]);   //this function encrypts text using substitution, the inputs are the cypher key and plain text
 void DecryptSubstitution(char key[], char text[]);   //this function decrypts text using substitution, the inputs are the cypher key and cypher text 

int main()  {

/*  the task is to create a program where a task will be selected, as well as a key, and then given a text to either decrypt or encrypt
    there will be a function for each task, with the function selected based on a variable entered or hard-coded
    then resulting text will then be printed to the user
    */
 
 int task = 4;  //for task selection
 int RotationKey = 3;   //rotation key
 char SubstitutionKey[] = "AZERTYUIOPQSDFGHJKLMWXCVBN"; //hardcoded substitution key
 char text[] = "MIOL MIOFU CGKQL MGG";
 // for the final program the user will be prompted to enter the file name
 
 //now displays a menu and prompts the user to enter the task number
 //     printf("Please enter the number corresponding to the task:\n(1) Rotation Encryption\n(2) Rotation Decryption\n(3) Substitution Encryption\n(4) Substitution Decryption\n");
 //     scanf("%d", &task);
 
 if(task == 1)   {
     // printf("\nEnter rotation key: ");  //prompts user to enter rotation key
     // scanf("%d", &RotationKey);
     // printf("Enter message to encrypt: ");  //prompts user to enter text, still unsure of how to scan the text
     
     //scanf("%c", &text);
     //repeatedly read in characters
        //if the number of characters read so far is above the max string length, 
            //terminate the string, and stop reading
        //if the character is not a newline, store it in a string
        //otherwise, terminate the string
     
     EncryptRotation(RotationKey, text);
 }  else if(task == 2)   {
     DecryptRotation(RotationKey, text);
 }  else if(task == 3)   {
     EncryptSubstitution(SubstitutionKey, text);
 }  else if(task == 4)   {
     DecryptSubstitution(SubstitutionKey, text);
 }  else    {
     printf("not a valid option\n");    // once scanf is implemented this could print the users selection
 }

  return 0;
}
 
 
 // function definitions
 void EncryptRotation(int key, char text[])   {         //this function is now working for what it can do
     //for each character c in text
        //set c in text to the rotated version of c
        int i = 0;
        while(text[i] != '\0') {
            if(text[i] >= 65 && text[i] <= 90)  {   //only does this if it is a capital letter
                text[i] = text[i] - 65;
                text[i] = (text[i] + key)%26;
                text[i] = text[i] + 65;
        }
            else if(text[i] >= 97 && text[i] <= 122)  {     //changes lower case to upper case while encrypting
               text[i] = text[i] - 97;   
               text[i] = (text[i] + key)%26;
               text[i] = text[i] + 65;
            } 
            printf("%c", text[i]);
            i++;
        }
        printf("\n");
 }
 
 void DecryptRotation(int key, char text[])   {            //this function also works
       int i = 0;
        while(text[i] != '\0') {
            if(text[i] >= 65 && text[i] <= 90)  {
                text[i] = text[i] - 65;
                text[i] = (text[i] - key + 26)%26;
                text[i] = text[i] + 65;
            }  
            else if(text[i] >= 97 && text[i] <= 122)    {
                text[i] = text[i] - 97;
                text[i] = (text[i] - key + 26)%26;
                text[i] = text[i] + 65;
            }
            printf("%c", text[i]);
            i++;
        }
        printf("\n");
 } 
 
 void EncryptSubstitution(char key[], char text[])  {   //this function works
     int i = 0;
     int LetterNumber;  //this int is used to the letter at a certain position in the key
 while(text[i] != '\0') {
            if(text[i] >= 65 && text[i] <= 90)  {   //only does this if it is a capital letter
                LetterNumber = text[i] - 65;
                text[i] = key[LetterNumber];
        }
            else if(text[i] >= 97 && text[i] <= 122)  {     //changes lower case to upper case and encrypts
               LetterNumber = text[i] - 97;
               text[i] = key[LetterNumber];
            } 
            printf("%c", text[i]);
            i++;
        }
        printf("\n");
 }
 
 void DecryptSubstitution(char key[], char text[])   {
     int i = 0;
     int LetterNumber; 
     char Alphabet[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";    //correct alphabet to compare key to
 while(text[i] != '\0') {
            if(text[i] >= 65 && text[i] <= 90)  {  
                LetterNumber = text[i] - 65;
                //text[i] = key[LetterNumber];
        }
            else if(text[i] >= 97 && text[i] <= 122)  {   
               LetterNumber = text[i] - 97;
               //text[i] = key[LetterNumber];
            } 
            printf("%c", Alphabet[LetterNumber]);
            i++;
        }
        printf("\n");
 }
 
