#include <ctype.h>
#include <stdlib.h>
#include <stdio.h>

void freeArr(char * keyArr, char * fKeyArr, char * pTextArr);

int main(int argc, char **argv){

char *fname = argv[1];
FILE *key = fopen(fname, "r");
char *keyArr;
char *fKeyArr;
char* pTextArr;
char cipherTxt[512];
char fpTextArr[512];
int letters = 0, lettersP = 0;
int k = 0,p = 0, c = 0;
int counter = 0, counterP = 0, counterC = 0;

//Check if the first file is entered and if it is continue on to the program
if(key == 0)
    printf("Could not open file!\n");
    else printf("\n");
char* fname2 = argv[2];
FILE *ptext = fopen(fname2, "r");
//Check if the second file is entered and if it is continue on to the program
if(ptext == 0)
        printf("Could not open file!\n");
else printf("\n");

//Get the length of the first file
fseek(key, 0, SEEK_END);
int buffer = ftell(key);
fseek(key, 0, SEEK_SET);
//Allocate memory for an array the length of the buffer size + 1
keyArr = calloc(buffer, sizeof(char) + 1);

//Get the length of the second file
fseek(ptext, 0, SEEK_END);
int buffer2 = ftell(ptext);
fseek(ptext, 0, SEEK_SET);
//Allocate memory for an array the length of the buffer size + 1
pTextArr = calloc(buffer2, sizeof(char) + 1);

//Get the input from the first file into an array, and make everything lowercase
for(int i = 0; i < buffer; i++){
keyArr[i] = tolower(fgetc(key)); 
}

//Check how many alphabetic characters there are and store that in the variable 'letters'
for(int j = 0; j < buffer; j++){
    if(keyArr[j] >= 'a' && keyArr[j] <= 'z')
    letters+=1;
}

//Allocate memory for an array the size of the amount of alphabetic characters
fKeyArr = calloc(letters, sizeof(char) + 1);  

//Filter out the original array and pass in only the alphabetic characters into the new array
for(int j = 0; j < buffer; j++){
    if(k > 512)
    break;
    if(keyArr[j] >= 'a' && keyArr[j] <= 'z'){
    fKeyArr[k] = keyArr[j];
    k += 1;
    }
}

//Get the input from the first file into an array, and make everything lowercase
for(int i = 0; i < buffer2; i++){
pTextArr[i] = tolower(fgetc(ptext)); 
}

//Check how many alphabetic characters there are and store that in the variable 'lettersP'
for(int j = 0; j < buffer2; j++){
    if(pTextArr[j] >= 'a' && pTextArr[j] <= 'z')
    lettersP+=1;
}

//Filter out the original array and pass in only the alphabetic characters into a new array of size 512
for(int j = 0; j < buffer2; j++){
    if(p > 512)
    break;
    if(pTextArr[j] >= 'a' && pTextArr[j] <= 'z'){
    fpTextArr[p] = pTextArr[j];
    p += 1;
    }
}
//If the array doesn't fill up 512 spaces, pad with 'x'
for(int i = lettersP; i < 512; i++){
    fpTextArr[i] = 'x';
}

//Print the key in a row 80 columns wide
printf("Vigenere Key: \n\n");
for(int j = 0; j < letters; j++){
  if(counter == 80){
  printf("\n");
  counter = 0;
  }
  printf("%c", fKeyArr[j]);
  counter += 1;
}

//Print the plaintext in a row 80 columns wide
printf("\n\n\n");
printf("Plaintext: \n\n");
for(int i = 0; i < 512; i++){
  if(counterP == 80){
  printf("\n");
  counterP = 0;
  }
  printf("%c", fpTextArr[i]);
  counterP += 1;
}

//Compare the key and plaintext and perform the Vigenerre cipher logic and store results in new array
printf("\n\n\n");
printf("Ciphertext: \n\n");
for(int i = 0; i < 512; i++){
if(c == letters){
c = 0;
}
int sample = 0;
sample = (((fpTextArr[i] - 'a') + (fKeyArr[c] - 'a')) % 26);
sample = sample + 'a';
cipherTxt[i] = sample;
c += 1;

//Print the Ciphertext in a row 80 columns wide
}
for(int i = 0; i < 512; i++){
if(counterC == 80){
printf("\n");
counterC = 0;
}
printf("%c", cipherTxt[i]);
counterC += 1;
}

//Free all the dynamically allocated memory
freeArr(keyArr, fKeyArr, pTextArr);
//Close the opened files
fclose(key);
fclose(ptext);
return 0;


}

void freeArr(char * keyArr, char * fKeyArr, char * pTextArr){

    free(keyArr);
    free(fKeyArr);
    free(pTextArr);
}