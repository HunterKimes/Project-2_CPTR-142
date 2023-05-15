#include <string>
#include <cmath>
#include <iostream>
#include <vector>
#include <cctype>
#include <iomanip>
using namespace std;
bool debug = false;

// Can't have extra spaces.
 int words (string paragraph) {
     if (debug == true){cout << "*words running" << endl; }
 int temp = 0, i;
for (i = 0; i < paragraph.length(); i++){
    if (paragraph.at(i) == (' ')) {
        temp = temp + 1;
    }
}
temp += 1;
return temp;
}
// Finds number of words in a paragraph.

// Must have all sentences formated corectly.
int complexwords (string paragraph) {
    if (debug == true){cout << "*complexwords running" << endl; }
    int temp = 0, i, j = 0, wordl = 0;
    for (i = 0; i < paragraph.length(); i++) {
        j++;
    if ((paragraph.at(i) == (' ')) || (paragraph.at(i) == ('.')) || (paragraph.at(i) == ('?') || (paragraph.at(i) == ('!')))) {
        wordl = j;
         j = 0;
    if (wordl > 3) {temp += 1;}
    wordl = 0;
    } 
    }
   return temp;
}
// outputs num of words over 3 sylibles.

 // Must have all sentences formated corectly. (no extra spaces or periods.)
double avewordl (string paragraph) {
    if (debug == true){cout << "*avewordl running" << endl; }
    int i;
    double temp=0;
    for (i=0;i < paragraph.length(); i++) {
        if (((paragraph.at(i) == ('a')) || (paragraph.at(i) == ('e')) || (paragraph.at(i) == ('i') || (paragraph.at(i) == ('o')) || (paragraph.at(i) == ('u'))
        || (paragraph.at(i) == ('A')) || (paragraph.at(i) == ('E')) || (paragraph.at(i) == ('I')) || (paragraph.at(i) == ('O')) || (paragraph.at(i) == ('U')))) && 
        !((paragraph.at(i+1) == ('a')) || (paragraph.at(i+1) == ('e')) || (paragraph.at(i+1) == ('i') || (paragraph.at(i+1) == ('o')) || (paragraph.at(i+1) == ('u'))
        || (paragraph.at(i+1) == ('A')) || (paragraph.at(i+1) == ('E')) || (paragraph.at(i+1) == ('I')) || (paragraph.at(i+1) == ('O')) || (paragraph.at(i+1) == ('U'))))) {
            temp += 1;
        }
    }
    temp=temp/words(paragraph);
    return temp;
}
// returns average sylibuls per word.

// Must have all sentences formated corectly. (No extra periods)
int numofsentence (string paragraph){
    if (debug == true){cout << "*numofsentence running" << endl; }
    int temp = 0, i;
for (i = 0; i < paragraph.length(); i++){
    if ((paragraph.at(i) == ('.')) || (paragraph.at(i) == ('!')) || (paragraph.at(i) == ('?'))) {
        temp += 1;
    }
}
return temp;
}
// returns number of sentences in paragraph.

// Paragraph needs to be formated without repeating spaces or periods.
int longSentence (string paragraph){
    if (debug == true){cout << "*longSentence running" << endl; }
    int temp = 0, i, words = 0;
for (i = 0; i < paragraph.length(); i++){
    if (paragraph.at(i) == (' ')) {
        words += 1;
    }
    if (paragraph.at(i) == ('.')){
        words += 1;
    if (words > 15) {temp += 1;}
    words = -1;
    }
}
return temp;
}
// Output a number for every sentence over 15 words which is consided average.


int char1 (string paragraph) {
    if (debug == true){cout << "*char1 running" << endl; }
    int i, temp = 0;
    for (i = 0; i < paragraph.length(); i++){
        if (isalpha(paragraph.at(i))){
            temp += 1;
        }
    }
    return temp;
}

int main() {
    string paragraph;
    int i,fog,Automated_readability,general;
    bool fail = true;
    string repeat;
   
cout << "Enter a paragraph that does not end in a space, have consecutive spaces or periods, or start with a space." << endl;
cout << "WARNING: If paragraph ends in a space the program will not run!" << endl;
do {

    fail = true;
    
cout << "Enter a paragraph: " << endl;
getline(cin, paragraph);
// paragraph = "hi mom.";
while (fail == true) {
    if (debug == true){cout << "*Checking paragraph format" << endl; }
    fail = false;
for (i = 0; i < paragraph.length(); i++) {
        if ((paragraph.at(i) == ' ') && (paragraph.at(i+1) == ' ')) {
cout << "The paragraph can't have two spaces consecutivly." << endl;
  fail = true; 
  break; }
}
    
for (i = 0; i < paragraph.length() - 1; i++) {
        if ((paragraph.at(i) == '.') && (paragraph.at(i+1) == '.')) {
cout << "The paragraph can't have two period's consecutivly." << endl;
  fail = true; 
  break;}
}
    
    
for (i = 0; i < paragraph.length(); i++) {
    if (paragraph.at(0) == ' ') {
cout << "The paragraph can't start with a space." << endl;
 fail = true; 
   break; }
}
    
 
    if (fail == true) {
         cout << "Enter a paragraph: " << endl;
        getline(cin, paragraph);
    }
   
}
cout << "=============================================================" << endl;
cout << setprecision(2);
cout << "Average sentence length (in words): " << fixed << double (words(paragraph)/numofsentence(paragraph)) << endl;
cout << "Average word length (in syllables): " << avewordl(paragraph) << endl;
cout << "percent of sentences that are long (over 15 words): " << double (static_cast<double>(longSentence(paragraph))/static_cast<double>(numofsentence(paragraph))*100) << " Percent." << endl;
cout << "Gunning fog index: ";
fog = .4*((words(paragraph)/numofsentence(paragraph)) + 100*(complexwords(paragraph)/words(paragraph)));
if (debug == true){cout << "*Gunning fog index finding difficulty" << endl; }
if( fog >= 17) cout <<	"College graduate" << endl;
else if( fog == 16) cout <<	"College senior" << endl;
else if( fog == 15) cout <<	"College junior" << endl;
else if( fog == 14) cout <<	"College sophomore" << endl;
else if( fog == 13) cout <<	"College freshman" << endl;
else if( fog == 12) cout <<	"High school senior" << endl;
else if( fog == 11) cout <<	"High school junior" << endl;
else if( fog == 10) cout <<	"High school sophomore" << endl;
else if( fog == 9) cout <<	"High school freshman" << endl;
else if( fog == 8) cout <<	"Eighth grade" << endl;
else if( fog == 7) cout <<	"Seventh grade" << endl;
else if( fog == 6) cout <<	"Sixth grade" << endl;
else {cout << "Undefined" << endl;}
cout << "Automated readability index: ";
Automated_readability = (4.71 * ((static_cast<double>(char1(paragraph)/words(paragraph)))) + (0.5*(static_cast<double>(words(paragraph)/numofsentence(paragraph))))) - 21.43;
if (debug == true){cout << "*Automated_readability finding difficulty" << endl; }
if( Automated_readability <= 1) cout <<	"Kindergarten" << endl;
else if(Automated_readability == 2) cout <<	"First/Second Grader" << endl;
else if(Automated_readability == 3) cout <<	"Third Grader" << endl;
else if(Automated_readability == 4) cout <<	"Fourth Grade" << endl;
else if(Automated_readability == 5) cout <<	"Fifth Grade" << endl;
else if(Automated_readability == 6) cout <<	"Sixth Grade" << endl;
else if(Automated_readability == 7) cout <<	"Seventh Grade" << endl;
else if(Automated_readability == 8) cout <<	"Eighth Grade" << endl;
else if(Automated_readability == 9) cout <<	"Ninth Grade" << endl;
else if(Automated_readability == 10) cout <<	"Tenth Grade" << endl;
else if(Automated_readability == 11) cout <<	"Eleventh Grade" << endl;
else if(Automated_readability == 12) cout <<	"Twelfth grade" << endl;
else if(Automated_readability == 13) cout <<	"College student" << endl;
else if(Automated_readability >= 14) cout <<	"Professor" << endl;

cout << "General dificulty: ";
if (debug == true){cout << "*General finding difficulty" << endl; }
general = (fog + Automated_readability)/2;
if (general <= 5) {cout << "Easy"<< endl;}
if ((general >= 6) && (general <= 10)) {cout << "Medium"<< endl;}
if (general >= 11) {cout << "Hard"<< endl;}
cout << "Do you want to analize another passage?(Y)es or (N)o" << endl;
getline(cin,repeat);

    }while(repeat=="Y");


return 0;
}

