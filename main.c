#include <stdio.h>

int main  {

/*  the task is to create a program where a task will be selected, as well as a key, and then given a text to either decrypt or encrypt
    there will be a function for each task, with the function selected based on a variable entered or hard-coded
    then resulting text will then be printed to the user
    */
 
 //function drafts, names, arguements, and return values may change later on
 void EncryptRotation(int key, int text);   //this function encrypts text using rotation, the inputs are the rotation key and plain text
 void DecryptRotation(int key, int text);   //this function decrypts text using rotation, the inputs are the rotation key and cypher text
 void EncryptSubstitution(int key, int text);   //this function encrypts text using substitution, the inputs are the cypher key and plain text
 void DecryptSubstitution(int key, int text);   //this function decrypts text using substitution, the inputs are the cypher key and cypher text 
 
 
 int task = 1;  //hard-coded task selection
 int RotationKey = 1;   //hard-coded key, rotation of 1
 int SubstitutionKey = QWERTYUIOPASDFGHJKLZXCVBNM   //not sure on the datatype yet
 char text[] = "some text";
 // for the final program the user will be prompted to enter these values/letters
 
 
 
 if(task = 1)   {
     EncryptRotation(RotationKey, text);
 }  else if(task = 2)   {
     DecryptRotation(RotationKey, text);
 }  else if(task = 3)   {
     EncryptSubstitution(SubstitutionKey, text);
 }  else if(task = 4)   {
     DecryptSubstitution(SubstitutionKey, text);
 }  else    {
     printf("not a valid option\n");    // once scanf is implemented this could print the users selection
 }

  return 0;
}
 
 
 // function definitions
 void EncryptRotation(int key, int text);   {
     
 }
 
 void DecryptRotation(int key, int text);   {
     
 } 
 
 void EncryptSubstitution(int key, int text);   {
     
 }
 
 void DecryptSubstitution(int key, int text);   {
     
 }