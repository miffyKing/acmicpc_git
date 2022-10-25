#include <iostream>
#include <cstring>
#include <string.h>

using namespace std;

namespace   COMP_POS
{
   enum pos
   {
      CLERK = 1, SENIOR, ASSIST, MANGER
   };
}

class NameCard
{
private:
   char* name;
   char* corpname;
   char* pnum;
   int pos;
public:
   NameCard(char *name, char* corpname, char* pnum, int pos)
      :pos(pos)
   {
      name = new char[strlen(name) + 1];
      corpname = new char[strlen(corpname) + 1];
      pnum = new char[strlen(pnum) + 1];
       
      strcpy(this->name, name);
      strcpy(this->corpname, corpname);
      strcpy(this->pnum, pnum);
   }
   void ShowNameCardInfo() const
   {
      switch (pos)
      {
         case 1:
            cout << "이름: " << name << endl;
            cout << "회사: " << corpname << endl;
            cout << "전화번호: " << pnum << endl;
            cout << "직급: 사원" << endl;
            break;
         case 2:
            cout << "이름: " << name << endl;
            cout << "회사: " << corpname << endl;
            cout << "전화번호: " << pnum << endl;
            cout << "직급: 주임" << endl;
            break;
         case 3:
            cout << "이름: " << name << endl;
            cout << "회사: " << corpname << endl;
            cout << "전화번호: " << pnum << endl;
            cout << "직급: 대리" << endl;
            break;
         case 4:
            cout << "이름: " << name << endl;
            cout << "회사: " << corpname << endl;
            cout << "전화번호: " << pnum << endl;
            cout << "직급: 과장" << endl;
            break;
      }
   }
   ~NameCard()
   {
      delete []name;
      delete []corpname;
      delete []pnum;
   }
};

int main(void)
{
   NameCard manClerk("LEE", "ABCEng", "010-1111-2222", COMP_POS::CLERK);
   NameCard manSENIOR("Hong","Orangetng","010-3333-4444",COMP_POS::SENIOR);
   NameCard manAssist("Kim","SoGoodComp","910-5555-6656", COMP_POS::ASSIST);
   manClerk.ShowNameCardInfo();
   manSENIOR.ShowNameCardInfo();
   manAssist.ShowNameCardInfo();
   return (0);
}
