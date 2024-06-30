// name: Di-En Sung
// email: sung.di@northeastern.edu.tw


// please start with a copy of your hw7.c, rename it to hw.8
// and then complete the assignment

// format of document is a bunch of data lines beginning with an integer (rank which we ignore)
// then a ',' followed by a double-quoted string (city name)
// then a ',' followed by a double-quoted string (population) - ignore commas and covert to int; or (X) - convert to 0
// then a lot of entries that are ignored


#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <time.h>

#define MAXSTRING 200
#define BUCKET_SIZE 400

struct bucket* hashTable1 = NULL;
struct bucket* hashTable2 = NULL; 
struct bucket* hashTable3 = NULL;  


// node struct
struct node {

    // Add your code here
    char* key;
    int value;
    struct node* next;
};

// bucket struct
struct bucket{

    // Add your code here
    struct node* head;
    int count;

};

// create a new node 
struct node* createNode(char* key, int value){
    struct node* newNode;

    // Add your code here
    newNode = malloc(sizeof(struct node));
    if (newNode == NULL){
        printf("Memory allocation failed\n");
        return NULL;
    }

    newNode->key = malloc(strlen(key)+1);
    if (newNode->key == NULL){
        printf("Memory allocation failed\n");
        return NULL;
    }
    strcpy(newNode->key, key); // Copy key into newNode->key
    newNode->value = value;
    newNode->next = NULL;
    return newNode;
}
int hashFunction1(char* key){
    return strlen(key) % BUCKET_SIZE;
}

int hashFunction2(char* key){
    int sum = 0;
    for (int i=0; i<strlen(key); i++){
        sum += key[i];
    }
    return sum % BUCKET_SIZE;
}

int hashFunction3(char* key){
    int product;
    product = key[0]*key[1];
    return product % BUCKET_SIZE;
}

// insert a new key
void add1(char* key, int value){
    int hashIndex = hashFunction1(key);
    //printf("THIS :%s !!!!\n", key);

    struct node* newNode = createNode(key, value);
    // when node is empty
    if (hashTable1[hashIndex].count == 0){
        hashTable1[hashIndex].count = 1;
        hashTable1[hashIndex].head = newNode; 
    }
    // when node has a key
    else{
        newNode->next = hashTable1[hashIndex].head;
        hashTable1[hashIndex].head = newNode;
        hashTable1[hashIndex].count++;
    }
}

void add2(char* key, int value){
    int hashIndex = hashFunction2(key);

    struct node* newNode = createNode(key, value);
    // when node is empty
    if (hashTable2[hashIndex].count == 0){
        hashTable2[hashIndex].count = 1;
        hashTable2[hashIndex].head = newNode; 
    }
    // when node has a key
    else{
        newNode->next = hashTable2[hashIndex].head;
        hashTable2[hashIndex].head = newNode;
        hashTable2[hashIndex].count++;
    }
}

void add3(char* key, int value){
    int hashIndex = hashFunction3(key);

    struct node* newNode = createNode(key, value);
    // when node is empty
    if (hashTable3[hashIndex].count == 0){
        hashTable3[hashIndex].count = 1;
        hashTable3[hashIndex].head = newNode; 
    }
    // when node has a key
    else{
        newNode->next = hashTable3[hashIndex].head;
        hashTable3[hashIndex].head = newNode;
        hashTable3[hashIndex].count++;
    }
}



// finite state machine states
#define STARTSTATE 0
#define S1 1
#define S2 2
#define S3 3
#define S4 4
#define S5 5
#define S6 6
#define ACCEPTSTATE 10
#define ERRORSTATE 11

// check if a character c is a digit
bool isDigit(char c) {
  if ('0' <= c && c <= '9') {
    return true;
  } else {
    return false;
  }
}

// append character c to string s
void appendChar(char* s, char c) {
  char charToStr[2];           // convert char to string
    charToStr[0] = c;
    charToStr[1] = '\0';          // put NUL to terminate string of one character
    strcat(s, charToStr);
}

void display(int type, struct bucket* hashtable){
    struct node* iterator;

    printf("\n***** HASH TABLE %d ***** \n", type);
    printf("\n======================== \n");
    for (int i = 0; i<BUCKET_SIZE; i++){
        iterator = hashtable[i].head;
        printf("Table[%d] : \n", i);
        while (iterator != NULL)
        {
            printf("key/value: [%s] / [%d]\n", iterator->key, iterator->value);
            iterator = iterator->next;
        }
        printf("\n");
    }
    printf("\n======================== \n");
}


int main () {

  char inputLine[MAXSTRING];   // temporary string to hold input line
  char cityStr[MAXSTRING];     // city name
  int  lineNum;                // line number (city rank)
  int  popInt;                 // population
  int  state;                  // FSM state
  int  nextChar;               // index of next character in input string
  char temp[MAXSTRING];        // temp string to build up extracted strings from input characters
  hashTable1 = (struct bucket *)malloc(BUCKET_SIZE * sizeof(struct bucket));
  hashTable2 = (struct bucket *)malloc(BUCKET_SIZE * sizeof(struct bucket));
  hashTable3 = (struct bucket *)malloc(BUCKET_SIZE * sizeof(struct bucket));
  for (int i = 0; i < BUCKET_SIZE; i++) {
      hashTable1[i].head = NULL;
      hashTable1[i].count = 0;

      hashTable2[i].head = NULL;
      hashTable2[i].count = 0;

      hashTable3[i].head = NULL;
      hashTable3[i].count = 0;
    }
 
  FILE* fp;
  fp = fopen("pop.csv","r");

  if (fp != NULL) {
    fgets(inputLine, MAXSTRING, fp); // prime the pump for the first line

    // ***** BEGIN FINTITE STATE MACHINE *****
    
    // STARTSTATE: digit -> S1
    // S1: digit -> S1; , -> S2
    // S2: " -> S3
    // S3: !" -> S3; " -> S4
    // S4: , -> S5
    // S5: " -> S6; ( -> ACCEPTSTATE
    // S6: digit -> S6; , -> S6; " -> ACCEPTSTATE; 
    // ACCEPTSTATE: done!
    // else go to ERRORSTATE
    //
    while (feof(fp) == 0){

      nextChar = 0;
      state = STARTSTATE; 
      strcpy(temp,"");       // temp = ""

      if (nextChar >= strlen(inputLine)){
	// if no input string then go to ERRORSTATE
	state = ERRORSTATE;
      } 

      while ((state != ERRORSTATE) && (state != ACCEPTSTATE)) {
	switch (state) {
	  case STARTSTATE:
	    // look a digit to confirm a valid line
	    if (isDigit(inputLine[nextChar])) {
	      state = S1;
	      appendChar(temp, inputLine[nextChar]); 
	    } else {
	      state = ERRORSTATE;
	    }  
	    break;


	  // ADD YOUR CODE HERE
    case S1:
      ; // add ";" to avoid error
        // error: a label can only be part of a statement and a declaration is not a statement
      int comma = ',';
      if (isDigit(inputLine[nextChar])){
        state = S1;
      }
      else if(inputLine[nextChar] == comma)
      {
        state = S2;
      }
      break;
    
    case S2:
      ;
      int quotation = '\"';
      if (inputLine[nextChar] == quotation){
        state = S3;
        strcpy(cityStr,""); // cityStr = ""  (initialize the variable)
      }
      break;

    case S3:

      if (inputLine[nextChar] == quotation){
        state = S4;
      }
      else {
        appendChar(cityStr, inputLine[nextChar]); // append character to cityStr
      }
      break;
    
    case S4:
     if (inputLine[nextChar] == comma){
        state = S5;
     }
     break;

    case S5:
      if (inputLine[nextChar] == quotation){
        state = S6;
        popInt = 0; // initialize popInt to 0;
      }
      else{
        state = ACCEPTSTATE;
        popInt = 0;
      }
      break;
    
    case S6:
      if (inputLine[nextChar] == comma){
        state = S6;
      }
      else if (isDigit(inputLine[nextChar]))
      {
        popInt = 10*popInt + (int)inputLine[nextChar] - '0'; // Convert a character digit to the corresponding integer
        state = S6;
      }
      else{
        state = ACCEPTSTATE;
      }
      break;
      
      
      
	    
	  case ACCEPTSTATE:
	    // nothing to do - we are done!
	    break;
	    
	  default:
	    state = ERRORSTATE;
	    break;
	} // end switch

	// advance input
	nextChar++;
	
      }	// end while state machine loop

      // ***** END FINITE STATE MACHINE *****
	  

      // process the line - print out raw line and the parsed fields
      //printf("> %.60s\n", inputLine);
      //printf("[%.30s]: %d\n", cityStr, popInt);
      add1(cityStr, popInt);
      add2(cityStr, popInt);
      add3(cityStr, popInt);
      //printf("%s\n", cityStr);

      // get next line
      fgets(inputLine, MAXSTRING, fp);
      
    } // end while file input loop
    

    fclose(fp);
    
    display(1, hashTable1);
    display(2, hashTable2);
    display(3, hashTable3);
  
  } else {
    printf("File not found!\n");
  }
  return 0;
}

