#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct ContactNode_struct {
   /* Define ContactNode struct here. */
   char name[26];  //up to 25 letters
   char phone[13];
   struct ContactNode_struct *next;
   
} ContactNode;

/* Define the functions here. */

void InitializeContactNode(ContactNode *headNode, char *name, char *phone) {
  strcpy(headNode->name, name);
  strcpy(headNode->phone, phone);
  return;
}
  


void InsertAfter(ContactNode* thisNode, ContactNode* newContactNode) {
   thisNode->next = newContactNode;
   ContactNode* tempNext = thisNode->next;
   newContactNode->next = tempNext;
}

char* GetName(ContactNode* thisNode) {
   return thisNode->name;
}

char* GetPhoneNumber(ContactNode* thisNode) {
   return thisNode->phone;
}

ContactNode* GetNext(ContactNode* thisNode) {
   return thisNode->next;
}

void PrintContactNode(ContactNode* thisNode) {
   printf("Name: %s\n", thisNode->name);
   printf("Phone number: %s\n", thisNode->phone);
}

int main(void) {
   const int TEXT_LIMIT = 100;
   char fullName[TEXT_LIMIT];
   char phoneNumber[TEXT_LIMIT];
   ContactNode* headNode = NULL;
   ContactNode* contactEntry1 = NULL;
   ContactNode* contactEntry2 = NULL;
   ContactNode* contactEntry3 = NULL;
   ContactNode* currContactEntry = NULL;

   // Initialize headNode
   headNode = (ContactNode*)malloc(sizeof(ContactNode));
   InitializeContactNode(headNode, "Head", "-1");

   fgets(fullName, TEXT_LIMIT, stdin);    // Reads a full line
   fullName[strlen(fullName) - 1] = '\0';  // Replaces the newline character
   fgets(phoneNumber, TEXT_LIMIT, stdin);
   phoneNumber[strlen(phoneNumber) - 1] = '\0';

   printf("Person 1: %s, %s\n", fullName, phoneNumber);

   // First contact node (head of list)
   contactEntry1 = (ContactNode*)malloc(sizeof(ContactNode));
   InitializeContactNode(contactEntry1, fullName, phoneNumber);
   InsertAfter(headNode, contactEntry1);

   fgets(fullName, TEXT_LIMIT, stdin);    // Reads a full line
   fullName[strlen(fullName) - 1] = '\0';  // Replaces the newline character
   fgets(phoneNumber, TEXT_LIMIT, stdin);
   phoneNumber[strlen(phoneNumber) - 1] = '\0';

   printf("Person 2: %s, %s\n", fullName, phoneNumber);

   // Second contact node
   contactEntry2 = (ContactNode*)malloc(sizeof(ContactNode));
   InitializeContactNode(contactEntry2, fullName, phoneNumber);
   InsertAfter(contactEntry1, contactEntry2);

   fgets(fullName, TEXT_LIMIT, stdin);    // Reads a full line
   fullName[strlen(fullName) - 1] = '\0';  // Replaces the newline character
   fgets(phoneNumber, TEXT_LIMIT, stdin);
   phoneNumber[strlen(phoneNumber) - 1] = '\0';

   printf("Person 3: %s, %s\n", fullName, phoneNumber);

   // Third contact node
   contactEntry3 = (ContactNode*)malloc(sizeof(ContactNode));
   InitializeContactNode(contactEntry3, fullName, phoneNumber);
   InsertAfter(contactEntry2, contactEntry3);

   // Print contact list
   printf("\nCONTACT LIST\n");
   currContactEntry = GetNext(headNode);

   while (currContactEntry != NULL) {
      PrintContactNode(currContactEntry);
      printf("\n");
      currContactEntry = GetNext(currContactEntry);
   }

   return 0;
}

