/*        Exercise-1, Number-03
            BOOK DATABASE
        ISLAM,MOHAMMAD MUINUL
      MATRICULATION NO:-2581908
INFORMATION AND AUTOMATION ENGINEERING
         UNIVERSITY OF BREMEN
         CREATED: 10.11.2012

            PROPOSED TASK
Create a program for the administration of a "book database". The database should be able to provide
the following information for each registered book:
     Author's first name
     Author's last name
     Title of the book
     Publisher
     Price
     Range of topics, for which only the following possibilities are available:
         Chemistry
         Physics
         Electrical-engineering
         Computer Science
         Software
     Reading state (specifies if the book has been already read by its owner [true/false]
The user should be able to perform the following activities:
(a) New book entry
(b) Show book entry
(c) Change book entry
(d) Search a certain last name
(e) Save the search results in a file
(f) Program termination
At the end of the program, the database should be cleared completely.

Use the following data-types for the implementation of the program:
 Enumeration type (enum)
 Structured data-type (struct)
 Data-types from the standard library (vector and string)

*/

#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <limits>
#include <fstream>
#include <cassert>
#include <time.h>


using namespace std;

struct book_info
    {
        string Author_first_name;
        string Author_last_name;
        string Title_of_the_book;
        string Publisher;
        string Topic;
        int Price;
        string Reading_state;
        int book_number;
    };

fstream myfile;
vector<book_info> myvector;
string topics_selection();
void Choice();
void date();
void date1();
int  New_Entry();
void show_entry();
void Change_entry();
book_info Change_entry1();
void Search_last_name();
int iInput();
char cInput();




void date()
    {
        char buff[100];
        time_t now = time (0);
        strftime (buff, 100, "%Y-%m-%d %H:%M:%S.000", localtime (&now));
        cout<<"  "<<buff<<"\n";
    }




void date1()
    {
        char buff[100];
        time_t now = time (0);
        strftime (buff, 100, "%Y-%m-%d %H:%M:%S.000", localtime (&now));
        myfile<<"  "<<buff<<"\n";
    }




int New_Entry()
    {
        book_info Topics;
        string N_o_b_1;
        int Number_of_books=0,a,n;      
        cout<<"\nHow many books do you want to entry: ";
        cin.clear();
        cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
        n=iInput();
        Number_of_books=n-1;
        for(a=0;a<=Number_of_books;a++)
            {
                cout<<"\n*********************\nEnter Book Number: ";
                cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
                Topics.book_number=iInput();

                cout << "\nEnter Author's first name: ";
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(),'\n');
                getline (cin,Topics.Author_first_name);
                
                cout << "\nEnter Author's last name: ";
                getline (cin,Topics.Author_last_name);

                cout << "\nEnter Title of the book: ";
                getline (cin,Topics.Title_of_the_book);

                cout << "\nEnter Publisher name: ";
                getline (cin,Topics.Publisher);

                cout<<"\nselect a topic: ";
                Topics.Topic=topics_selection();

                cout<<"\nEnter price of the book: ";
                cin.clear();
                Topics.Price=iInput();

                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(),'\n');
                char cIn;
                do
                    {
                        cout<<"\nhave you read the book?\npress <y> or <Y> for read and <n> or <N> for unread.";
                        cout<<"\npress <f> or <F> to go NEXT.";
                        cout<<"\npress:";
                        cin.clear();
                        cIn=cInput();
                        if (cIn=='y' || cIn=='Y')
                            {
                                Topics.Reading_state="read";
                                cout<<"\nyou already have read the book.\n";
                            }
                        else if(cIn=='n' || cIn== 'N')
                            {
                                Topics.Reading_state="unread";
                                cout<<"\nyou didn't' read the book.\n";
                            }

                        else
                            {
                                if(cIn=='f' || cIn=='F');
                                else
                                cout<<"\nplease give correct character......\n";
                            };

                    }
                while(cIn !='f' && cIn !='F');
                myvector.push_back(Topics);
            }

            cout<<"\nyou stored "<<n<<" books now";
            cout << "\nWith this eddition now total " << (int)myvector.size() << " books are saved to the database.\n\n";
            return 0;
        }




void show_entry()
    {
        int Select2;
        do
            {
                    unsigned int i;
                    cout << "\ntotal " << (int)myvector.size() << " books are saved to the database.\n";
                    cout << "\n\nSHOW ENTRY SUB MENU.\nRange of Choices\n";
                    cout <<"index\tchoice\n";
                    cout << "1  \tsee the entire book database\n";
                    cout << "2  \tread the specific one.\n";
                    cout << "3  \tread from the file.\n";
                    cout << "4  \tto return to the MAIN MENU.\n";
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(),'\n');
                    cout << "\nmake a choice by giving index number: ";
                    Select2=iInput();
                    enum show_data{total=1,part,file_read};
                    switch (Select2)
                        {
                            case total:
                                {
                                    for(i=0;i<myvector.size();i++)
                                       {
                                            cout <<"\n**********************\nBook Number: ";
                                            cout <<myvector[i].book_number<<endl;
                                            cout <<"\nAuthor's first name: ";
                                            cout <<myvector[i].Author_first_name<< endl;
                                            cout <<"\nAuthor's last name: " <<myvector[i].Author_last_name << endl;
                                            cout <<"\nTitle of the book: "<<myvector[i].Title_of_the_book << endl;
                                            cout <<"\nPublisher name: "<<myvector[i].Publisher << endl;
                                            cout <<"\nTopic: "<<myvector[i].Topic<<endl;
                                            cout <<"\nprice: "<<myvector[i].Price << endl;
                                            cout <<"\nreading state of the book: "<<myvector[i].Reading_state<<endl;

                                        }
                                }
                            break;

                            case part:
                            {
                                    cout<<"\ngive a number: ";
                                    int iN;
                                    cin.clear();
                                    cin.ignore(numeric_limits<streamsize>::max(),'\n');
                                    iN=iInput();
                                    i=iN-1;
                                        {
                                            cout <<"\n*****************\nBook Number: ";
                                            cout <<myvector[i].book_number<<endl;
                                            cout <<"\nAuthor's first name: ";
                                            cout<<myvector[i].Author_first_name<< endl;
                                            cout <<"\nAuthor's last name: " <<myvector[i].Author_last_name << endl;
                                            cout <<"\nTitle of the book: "<<myvector[i].Title_of_the_book << endl;
                                            cout <<"\nPublisher name: "<<myvector[i].Publisher << endl;
                                            cout <<"\nTopic: "<<myvector[i].Topic<<endl;
                                            cout <<"\nprice: "<<myvector[i].Price << endl;
                                            cout <<"\nreading state of the book: "<<myvector[i].Reading_state<<endl;

                                        }
                             }

                             break;

                             case file_read:
                                {

                                    string line;
                                    myfile.open("search_file.txt", ios::in);
                                    if (myfile.is_open())
                                        {
                                            while (! myfile.eof() )
                                            {
                                                getline (myfile,line);
                                                cout << line << endl;
                                            }
                                        myfile.close();
                                        }
                                        else cout << "Unable to open file";
                                }
                            break;

                            default:
                                {
                                    if(Select2==4);
                                    else
                                    cout<<"\nplease give correct number......\n";
                                }

                        }
                }
        while(Select2 != 4);
        cout<<"\n";
    }




void Change_entry()
    {

        unsigned int i,e;
        cout << "\nChoose the book to edit: ";

        cin.ignore(numeric_limits<streamsize>::max(),'\n');
        e=iInput();
        cin.clear();
        i=e-1;
        (e<=myvector.size());

        cout <<"\n******************\nBook Number: ";
        cout <<myvector[i].book_number<<endl;
        cout <<"\nAuthor's first name: ";
        cout<<myvector[i].Author_first_name<< endl;
        cout <<"\nAuthor's last name: " <<myvector[i].Author_last_name << endl;
        cout <<"\nTitle of the book: "<<myvector[i].Title_of_the_book << endl;
        cout <<"\nPublisher name: "<<myvector[i].Publisher << endl;
        cout <<"\nChosed Topic: "<<myvector[i].Topic<<endl;
        cout <<"\nprice: "<<myvector[i].Price << endl;
        cout <<"\nreading state of the book: "<<myvector[i].Reading_state<<endl;
        myvector[i]=Change_entry1();
    }




book_info Change_entry1()
    {

        book_info Topics1;
        cout<<"\n******************\nEnter Book Number: ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(),'\n');
        Topics1.book_number=iInput();

        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(),'\n');
        cout << "\nEnter Author's first name: ";
        getline (cin,Topics1.Author_first_name);

        cin.clear();
        cout << "\nEnter Author's last name: ";
        cin.clear();
        getline (cin,Topics1.Author_last_name);

        cout << "\nEnter Title of the book: ";
        getline (cin,Topics1.Title_of_the_book);

        cin.clear();
        cout << "\nEnter Publisher name: ";
        getline (cin,Topics1.Publisher);

        cin.clear();
        cout<<"\nselect a topic: ";
        Topics1.Topic=topics_selection();

        cin.clear();
        cout<<"\nEnter price of the book: ";
        Topics1.Price=iInput();

        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(),'\n');

        char cIn;
        do
            {
                cout<<"\nhave you read the book?\npress <y> or <Y> for read and <n> or <N> for unread.";
                cout<<"\npress <f> or <F> to go NEXT.";
                cout<<"\npress:";
                cin.clear();
                cIn=cInput();
                if (cIn=='y' || cIn=='Y')
                    {
                        Topics1.Reading_state="read";
                        cout<<"\nyou already have read the book.\n";
                    }
                else if(cIn=='n' || cIn== 'N')
                    {
                        Topics1.Reading_state="unread";
                        cout<<"\nyou didn't' read the book.\n";
                    }

                else
                    {
                        if(cIn=='f' || cIn=='F');
                        else
                        cout<<"\nplease give correct character......\n";
                    };

            }
        while(cIn !='f' && cIn !='F');
        return (Topics1);

    }




void Search_last_name()
    {
        string name;
        int S=0;
        cout<<"Give a Author's Last name to search: ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(),'\n');
        getline(cin,name);
        
        for (unsigned int i = 0; i < myvector.size() ; i++)
            {
                  if (name==myvector[i].Author_last_name)
                      {
                          cout<<"\n##################################\n";
                          cout <<"\nBook Number: ";
                          cout <<myvector[i].book_number<<endl;
                          cout <<"\nAuthor's first name: ";
                          cout<<myvector[i].Author_first_name<< endl;
                          cout <<"\nAuthor's last name: " <<myvector[i].Author_last_name << endl;
                          cout <<"\nTitle of the book: "<<myvector[i].Title_of_the_book << endl;
                          cout <<"\nPublisher name: "<<myvector[i].Publisher << endl;
                          cout <<"\nTopic: "<<myvector[i].Topic<<endl;
                          cout <<"\nprice: "<<myvector[i].Price << endl;
                          cout <<"\nreading state of the book: "<<myvector[i].Reading_state<<endl;
                          S++;
                      }
                  else {}
            }
          cout<<"\nTotal "<<S<<" entries found.\n";

          cin.clear();
          char cChoice;

          do
              {
                  cout <<"\n\ndo you want to save the search result in a file?";
                  cout<<"\nif yes press <y> or <Y> and if no press <n> or <N>: ";
                  cout<<"\npress <f> or <F> to go to the MAIN MENU.";
                  cout<<"\npress:";
                  cChoice=cInput();
                  cin.clear();
                  if(cChoice=='y' || cChoice=='Y')
                      {
                          myfile.open("search_file.txt", ios::out | ios::ate | ios::app);
                          myfile <<"------------------------------\n";
                          myfile << "\tbook database\n";
                          date1();
                          myfile <<"------------------------------\n";
                          myfile <<"\nsearched word: "<<name;
                          myfile.close();
                          for(unsigned int i = 0; i < myvector.size() ; i++)
                              {
                                  if (name==myvector[i].Author_last_name)
                                      {
                                          myfile.open("search_file.txt", ios::out | ios::ate | ios::app);
                                          if (myfile.is_open())
                                              {

                                                  myfile <<"\n#############################\n";
                                                  myfile <<"\nBook Number: ";
                                                  myfile <<myvector[i].book_number<<endl;
                                                  myfile <<"\nAuthor's first name: ";
                                                  myfile <<myvector[i].Author_first_name<< endl;
                                                  myfile <<"\nAuthor's last name: " <<myvector[i].Author_last_name << endl;
                                                  myfile <<"\nTitle of the book: "<<myvector[i].Title_of_the_book << endl;
                                                  myfile <<"\nPublisher name: "<<myvector[i].Publisher << endl;
                                                  myfile <<"\nTopic: "<<myvector[i].Topic<<endl;
                                                  myfile <<"\nprice: "<<myvector[i].Price << endl;
                                                  myfile <<"\nreading state of the book: "<<myvector[i].Reading_state<<endl;
                                                  myfile.close();
                                              }
                                           else cout<<"unable to open file";
                                      }
                                  else {}
                              }
                          myfile.open("search_file.txt", ios::out | ios::ate | ios::app);
                          myfile<<"\nTotal "<<S<<" entries found.\n";
                          myfile.close();
                          cout<<"\n\nThe search result is saved\n";
                      }
                  else if(cChoice=='n' ||cChoice=='N')
                  cout<<"The search result is not saved";

                  else
                      {
                          if(cChoice=='f' || cChoice=='F');
                          else
                          cout<<"\nplease give correct character......\n";
                      };

              }
          while(cChoice !='f' && cChoice !='F');
          cout<<"\n";

    }




int main()
    {
        Choice();
        return 0;
    }




void Choice()
    {

        int iSelect1;
        do
            {
                cout <<"------------------------------\n";
                cout << "\tbook database\n";
                cout<<"";date();
                cout <<"------------------------------\n";
                cout << "\nMAIN MENU\nRange of Choices\n";
                cout <<"index\tchoice\n";
                cout << "1  \tNew book entry\n";
                cout << "2  \tShow book entry\n";
                cout << "3  \tChange book entry\n";
                cout << "4  \tSearch a book by Author's last name\n";
                cout << "5  \tTerminate the program\n";              
                enum book_data{New_book_entry=1,Show_book_entry,Change_book_entry,Search};
                cin.clear();
                cout << "\nmake a choice by giving index number: ";
                iSelect1=iInput();
                switch (iSelect1)
                    {
                        case New_book_entry:
                            {
                                cout << "\nyou want to entry new to the database.\n";
                                New_Entry();
                            }
                                break;

                        case Show_book_entry:
                            {
                                cout << "\nyou want to read from database.\n";
                                show_entry();
                            }
                                 break;

                        case Change_book_entry:
                            {
                                cout << "\nyou want to modify database.\n";
                                Change_entry();
                            }
                                 break;

                        case Search:
                            {
                                cout << "\nyou want to Search by a certain last name.\n";
                                Search_last_name();
                            }
                                 break;

                        default:
                            {
                                 if(iSelect1==5);
                                 else
                                 cout<<"\nplease give correct number......\n";
                            }

                    }

            }
        while(iSelect1!=5);
        myvector.clear();
        cout<<"\n";
    }




string topics_selection()
    {
        string mystr2;
        int Select;
        do
            {
                cout << "\nRange of topics\n";
                cout <<"index\ttopics\n";
                cout << "0  \tChemistry\n";
                cout << "1  \tPhysics\n";
                cout << "2  \tElectrical-Engineering\n";
                cout << "3  \tcomputer science\n";
                cout << "4  \tSoftware\n";
                cout << "5  \tenter 5 to go NEXT.\n\n";

                enum L_data{ Chemistry=0,Physics,Electrical_engineering,Computer_Science,Software};

                cin.clear();
                cout << "Select a topics by giving index number: ";
                Select=iInput();
                switch (Select)
                    {
                        case Chemistry:
                            {
                                cout << "\nyou have chosen Chemistry.\n";
                                mystr2="Chemistry";
                            }
                                break;

                        case Physics:
                            {
                                cout << "\nyou have chosen Physics.\n";
                                mystr2="Physics";
                            }
                                break;

                        case Electrical_engineering:
                            {
                               cout << "\nyou have chosen Electrical_engineering.\n";
                               mystr2="Electrical_engineering";
                            }
                                break;

                        case Computer_Science:
                            {
                                cout << "\nyou have chosen Computer_Science.\n";
                                mystr2="Computer_Science";
                            }
                                break;

                        case Software:
                            {
                                cout << "\nyou have chosen Software.\n";
                                mystr2="Software";
                            }
                                break;

                        default:
                            {
                                if(Select==5);
                                else
                                cout<<"\nplease give correct number......\n";
                            }


                    }
            }
        while(Select!=5);
        return (mystr2);
    }




int iInput()
    {
        int iNumber;
        while(!(cin >> iNumber))
            {
                cin.clear();
                cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
                cout<<"\nplease give correct value: ";
            }
        cout<<"\nentered: "<<iNumber<<"\n";
        return (iNumber);
    }




char cInput()
    {
        char cChar;
        while(!(cin >> cChar))
            {
                cin.clear();
                cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
            }
        cout<<"\nentered: "<<cChar<<"\n";
        return (cChar);

    }



