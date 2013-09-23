            /*      Lecture-04 Exercise-02
                     CHAIN TREE EXERCISE
                    ISLAM,MOHAMMAD MUINUL
                  MATRICULATION NO:-2581908
            INFORMATION AND AUTOMATION ENGINEERING
                     UNIVERSITY OF BREMEN
                     CREATED: 15.11.2012

                        PROPOSED TASK
            Create an application that builds a
            dynamically allocated tree with five
            nodes. Use the following structure for
            the nodes:

                struct Node_T
                    {
                        double m_dValue;
                        Node_T * m_pNext1;
                        Node_T * m_pNext2;
                    };

            Create a function that takes the
            root pointer of your tree and
            prints the values of all nodes to
            the screen.

            Create a function that uses the
            root pointer to search for a
            specific element within the tree.
            */

            #include <iostream>
            #include <limits>
            #include <time.h>

            using namespace std;

            struct Node_T
                {
                    double m_dValue;
                    Node_T * m_pNext1;
                    Node_T * m_pNext2;
                };




            void show_entry(Node_T *pRoot);
            double fInput();
            void entry(Node_T *&pRoot);
            //void entry(Node_T **pRoot);
            Node_T * search_entry(Node_T * pRoot, double search);
            void date();
            char cInput();
            void menu();




            void date()
                {
                    char buff[100];
                    time_t now = time (0);
                    strftime (buff, 100, "%Y-%m-%d %H:%M:%S.000", localtime (&now));
                    cout<<"  "<<buff<<"\n";
                }




            int main()
                {
                    menu();
                    return 0;
                }




            void menu()
                {
                    cout<<"\n\t\t*********************************\n";
                    cout<<"\n\t\t      CHAIN TREE EXERCISE\n";
                    cout<<"\t\t  ";date();
                    cout<<"\n\t\t*********************************\n\n";

                    Node_T *pRoot;
                    entry(pRoot);
                    //entry ((&pRoot));
                    char cInput1;
                    do
                        {
                            cout<<"\n\nMAIN MENU: \n";
                            cout<<"press the key <c> or <C> to see all the Node element.\n";
                            cout<<"press the key <s> or <S> to search for a Node element.\n";
                            cout<<"press the key <t> or <T> to terminate the program.\n";

                            cout<<"press the key: ";
                            cInput1=cInput();
                            if (cInput1 =='c' || cInput1 =='C')
                                {
                                    cout<<"\nyou wanted to see all the Node element.\n\n";
                                    show_entry(pRoot);
                                }
                            else if (cInput1 =='s' || cInput1 =='S')
                                {
                                    cout<<"\nyou wanted to search for a Node element.\n";
                                    cout<<"\ngive a Real Number(figure) to search the Node element: ";
                                    double dIn;
                                    dIn=fInput();
                                    if(search_entry(pRoot,dIn)!=0);
                                    else cout<<"\ndidn't found the element";
                                }
                            else
                                {
                                    if(cInput1=='t' || cInput1=='T');
                                    else
                                        {
                                            cout<<"\nplease give correct character......\n";
                                        }
                                };
                        }
                    while(cInput1 !='t' && cInput1 !='T');
                    cout<<"\n";
                }


            /*
            Ques: Why we used a & reference in the following line?
            Ans: Because We dont need a copy of the address but to point a pointer or point to a address.
             */

            void entry(Node_T *&pRoot)
                {


                    pRoot = new Node_T;
                    //(*pRoot)=new Node_T;
                    (pRoot)->m_dValue = 0;
                    (pRoot)->m_pNext1 = NULL;
                    (pRoot)->m_pNext2 = NULL;
                    //(*pRoot)->m_dValue = 0;
                    //(*pRoot)->m_pNext1 = NULL;
                    //(*pRoot)->m_pNext2 = NULL;

                    Node_T * pTemp1 = new Node_T;
                    Node_T * pTemp2 = new Node_T;
                    Node_T * pTemp3 = new Node_T;
                    Node_T * pTemp4 = new Node_T;

                    (pRoot)->m_pNext1 = pTemp1;
                    (pRoot)->m_pNext2 = pTemp2;
                    //(*pRoot)->m_pNext1 = pTemp1;
                    //(*pRoot)->m_pNext2 = pTemp2;

                    pTemp1->m_dValue = 11;
                    pTemp1->m_pNext1 = NULL;
                    pTemp1->m_pNext2 = NULL;

                    pTemp2->m_dValue = 22;
                    pTemp2->m_pNext1 = pTemp3;
                    pTemp2->m_pNext2 = pTemp4;

                    pTemp3->m_dValue = 33;
                    pTemp3->m_pNext1 =NULL;
                    pTemp3->m_pNext2=NULL;

                    pTemp4->m_dValue=44;
                    pTemp4->m_pNext1=NULL;
                    pTemp4->m_pNext2=NULL;

                }




            void show_entry(Node_T * pRoot )
                {
                    if(pRoot == NULL ) return;
                    cout<<"\t"<<pRoot->m_dValue<<endl;
                    show_entry(pRoot->m_pNext1);
                    show_entry(pRoot->m_pNext2);
                }




            Node_T *search_entry(Node_T *pRoot, double search)
                {
                       if(pRoot == NULL )  return 0;
                       if(pRoot->m_dValue == search)
                            {
                               cout<<"\nfound the element: "<<pRoot->m_dValue;
                               return pRoot;
                            }

            /*
            Ques-1: Why we need a temporary variable like Node_T * pRoot1?
            Ans: Not to return the the current value of pRoot.
            Ques-2: Why we used a condition like "if (pRoot1!=NULL)" ?
            Ans: Because if pRoot1 already points to a NULL,then it does not make any sense to return a NULL pointer.
            */
                       Node_T * pRoot1 =  (search_entry(pRoot->m_pNext1 , search)) ;
                       if (pRoot1!=NULL)
                           {
                               return (pRoot1);
                           }

                       pRoot1 = (search_entry(pRoot->m_pNext2 , search)) ;
                       if (pRoot1!=NULL)
                           {
                               return (pRoot1);
                           }

                       return 0;
                }




            double fInput()
                {
                    double fNumber;
                    while(!(cin >> fNumber))
                        {
                            cin.clear();
                            cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
                            cout<<"\nplease give correct value: ";
                        }
                    cout<<"entered: "<<fNumber<<"\n";
                    return (fNumber);
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






















