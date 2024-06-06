#include <iostream>
#include <stdlib.h>
#include <fstream>
#include <time.h>
#include <string.h>

#define ESC "\033["
#define RED_TXT "31"
#define ORANGE_TXT "33"
#define YELLOW_TXT "36"
#define GREEN_TXT "32"
#define BLUE_TXT "34"
#define PURPLE_TXT "35"
#define RESET "\033[m"

using namespace std;
class colors {
public:
   colors (string colorString, colors* headSTart);
   string GetNodeData();
   void InsertAfter(colors* newColor);
   void getSpecialQuestion();
   colors* GetNext();
   string FinalQuestion();
   private:
   string dataVal;
   colors* nextNodePtr;
   colors* headNode;
};

colors::colors(string colorString, colors* head) { // Constructor
   if(colorString == "-1"){
   headNode = head;
   }
   this->dataVal = colorString;
   nextNodePtr = nullptr;
}

string colors::GetNodeData() { // Get node value
   return this->dataVal;
}

colors* colors::GetNext() { // Get pointer to next node
   return this->nextNodePtr;
}

/* Insert node after this node.
   Before: this -- next
   After:  this -- node -- next
*/
void colors::InsertAfter(colors* newColor) {
   colors* tempNext = this->nextNodePtr;
   this->nextNodePtr = newColor;
   newColor->nextNodePtr = tempNext;
}

string colors::FinalQuestion(){
   string colorCombo[4];
   headNode->GetNext();
   colorCombo[0]= headNode->GetNodeData();
   int y = 1;
   while(headNode->GetNext() != NULL){
   headNode = headNode->GetNext();
   colorCombo[y] = headNode->GetNodeData();
   colorCombo[0] = colorCombo[0] + headNode->GetNodeData();
   y++;
   }
return colorCombo[0];
}

   void getSpecialQuestion(){
   colors* head = new colors("-1", head);
   colors* current;
   colors* previous;
   previous = head;
   int random;
      srand(time(NULL));
      for (int v = 0; v < 4; v++){
      random = rand() % 6;
      switch(random){

      case 0:
      current = new colors("R", head);
      previous->InsertAfter(current);
      previous = current;
      cout << "Red ";
      break;

      case 1:
      current = new colors("O", head);
      previous->InsertAfter(current);
      previous = current;
      cout << "Orange ";
      break;
      case 2:
      current = new colors("Y", head);
      previous->InsertAfter(current);
      previous = current;
      cout << "Yellow ";
      break;
      case 3:
      current = new colors("G", head);
      previous->InsertAfter(current);
      previous = current;
      cout << "Green ";
      break;
      case 4:
      current = new colors("B", head);
      previous->InsertAfter(current);
      previous = current;
      cout << "Blue ";
      break;
      case 5:
      current = new colors("P", head);
      previous->InsertAfter(current);
      previous = current;
      cout << "Purple ";
      break;
      default:
      current = new colors("-1", head);
      previous->InsertAfter(current);
      previous = current;
      break;
      }
      }
      cout << endl;
   }

int main() {
   ifstream inFS;
   int lives = 3;
   string questionInfo[5];
   string answer;
   string input;
   bool gameover = false;
   bool finalQuestion;
   string colorsCombo;
   colors* myColorSequence;

   inFS.open("quiz_Questions.txt");
           if (!inFS.is_open()) {
            cout << "Could not open file" << endl;
            return 1; // 1 indicates error
        }
      for (int o = 0; o <= 25; ++o) {
      system("cls");
      if(o == 2){
            getSpecialQuestion();
      for (int p = 0; p < 5; p++){
      getline(inFS,questionInfo[p]);
      cout << questionInfo[p] << endl;
      }
      getline(inFS,answer);
      }
      else if (o == 25){


      cout << "I hope you remembered!" << endl;
      cout << ESC << ";" << GREEN_TXT << "m" <<  "R - Red " << RESET << endl;
      cout <<  ESC << ";" << PURPLE_TXT << "m" << "O - Orange "<< RESET << endl;
      cout << ESC << ";" << BLUE_TXT <<  "m" << "Y - Yellow "<< RESET << endl;
      cout << ESC << ";" << RED_TXT << "m" << "G - Green "<< RESET << endl;
      cout << ESC << ";" << ORANGE_TXT << "m" << "B - Blue "<< RESET << endl;
      cout << ESC << ";" << YELLOW_TXT << "m" << "P - Purple " << RESET << endl;
      cout << "WASN'T ABLE TO GET THIS ONE DONE IN TIME :(" << endl;
      break;
      }
      else {
      for (int p = 0; p < 5; p++){
      getline(inFS,questionInfo[p]);
      cout << questionInfo[p] << endl;
      }
       getline(inFS,answer);
      }
      while (input.compare(answer) != 0){
      cin >> input;

      if (input.compare(answer) != 0){
            lives = lives - 1;
      cout << " Wrong! " << lives << " lives remaining" << endl;
            if(lives <= 0){
            gameover = true;
            break;
            }
      }
      }
      input = "";
      if (gameover == true){
      cout << "Game Over!" << endl;
      inFS.close();
      break;
      }
      }
      inFS.close();
      return 0;
}
