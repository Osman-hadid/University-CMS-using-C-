#include <iostream>
#include <string.h>
#include <fstream>
using namespace std;
int i=0,m=0,y=1;
int a2=0,a3=0,a4=0,a5=0;
int h=1;



void Com1();
void MAN();
void BCS();
void BBA();
void LAW();
void JOR();
void MARKS();
void ATTENDANCE();

ofstream output_jor("jor.CSV",ios::app);
ofstream output_law("law.CSV",ios::app);
ofstream output_bcs("bcs.CSV",ios::app);
ofstream output_bba("bba.CSV",ios::app);


class Log_in
{

public:
    string department,gender,id,Id,email;
    char name[10];
    char l_name[10];
    char password[];
    bool ba=true;
    int present,absent;


    void get_n()
    {
        cout<<"\t\t\t\t\tPlease enter your information: "<<endl;
        cout<<"\t\t\t\t\tEnter your name: ";
        cin>>name;
        int o1 = strlen(name);
        for (int i=0 ; i<o1 ; i++)
        {
            if (name[i]>='A'&&name[i]<='z')
            {
                ba=true;
            }
                else
                {
                    ba=false;
                    cout<<"\t\t\t\t\t###########################"<<endl<<endl;
                    cout<<"\t\t\t\t\tName must be only alphabet!"<<endl<<endl;
                    cout<<"\t\t\t\t\t###########################"<<endl<<endl;
                    get_n();
                }
        }
        if (ba==true)
        {
            get_l();
            ba=false;
        }

    }

    void get_l()
    {
        cout<<"\t\t\t\t\tEnter your last name: ";
        cin>>l_name;

        int o1 = strlen(l_name);
        for (int i=0 ; i<o1 ; i++)
        {
            if (l_name[i]>='A'&&l_name[i]<='z')
            {

                ba=true;
            }
                else
                {
                    ba=false;
                    cout<<"\t\t\t\t\t###########################"<<endl<<endl;
                    cout<<"\t\t\t\t\tLast name must be only alphabet!"<<endl<<endl;
                    cout<<"\t\t\t\t\t###########################"<<endl<<endl;
                    get_l();
                }
        }
        if (ba==true)
        {
            get_e();
            ba=false;
        }

    }

    void get_e()
    {
        cout<<"\t\t\t\t\tEnter your email: ";
        cin>>email;

        string gmail="@gmail.com";
        string yahoo="@yahoo.com";

            if (strstr(email.c_str(),gmail.c_str()) || strstr(email.c_str(),yahoo.c_str()))
            {

                get_p();
            }
                else
                {
                    cout<<"\t\t\t\t\t##########################"<<endl<<endl;
                    cout<<"\t\t\t\t\tPlease enter a valid email"<<endl<<endl;
                    cout<<"\t\t\t\t\t##########################"<<endl<<endl;
                    get_e();
                }
            if (email==" ")
            {
                cout<<"\t\t\t\t\tPlease fill the blank!"<<endl;
                get_e();
            }
    }

    void get_p()
    {
        bool ch=true;
        cout<<"\t\t\t\t\tEnter your password: ";
        cin>>password;
        int o1 = strlen(password);

        int alphabet=65;
        int number=48;

        for (int i=0 ; i<o1 ; i++)
        {
            if (password[i]>=alphabet || password[i]>=number)
            {

                ch=true;
            }
                else
                {
                    ch=false;
                    break;
                }
        }



        if (o1<=8 && ch==true)
        {
            get_g();
        }
            else
            {
                cout<<endl;
                cout<<"\t\t\t\t\tTRY AGAIN\nYour password must be less than or equal to 8!\n And only alphabets and number!"<<endl<<endl;
                get_p();
            }
    }

    void get_g()
    {
        cout<<"\t\t\t\t\tEnter your gender male/female: ";
        cin>>gender;

        string male="male";
        string female="female";

        if (strstr(gender.c_str(),male.c_str()) || strstr(gender.c_str(),female.c_str()))
        {

            get_id();
        }

            else
            {
                cout<<"\t\t\t\t\tPlease try again"<<endl;
                get_g();
            }



    }
    void get_id()
    {
        cout<<"\t\t\t\t\tEnter ID: ";
        cin>>id;
        string Default = "RX-200-";

        if (strstr(id.c_str(),Default.c_str()))
        {

        }
        else
        {
            cout<<"Wrong ID please try again"<<endl;
            get_id();
        }
    }

    void s_box()
    {
        cout<<"************************************************************************************************************************"<<endl;
        cout<<"\t\t\t\t\tEnter ID: ";
        cin>>Id;
        cout<<"************************************************************************************************************************"<<endl;
    }

    void display()
    {
        if (gender=="male")
        {
            cout<<"\t\t\t\t\tWelcome Mr "<<name<<endl;
            cout<<"\t\t\t\t\tLast name is: "<<l_name<<endl;
            cout<<"\t\t\t\t\tEmail is: "<<email<<endl;
            cout<<"\t\t\t\t\tID is: "<<id<<endl;
        }


            else
            {
                cout<<"\t\t\t\t\tWelcome Miss "<<name<<endl;
                cout<<"\t\t\t\t\tLast name is: "<<l_name<<endl;
                cout<<"\t\t\t\t\tEmail is: "<<email<<endl;
                cout<<"\t\t\t\t\tID is: "<<id<<endl;
            }


    }


    void dis_att ()
    {
        cout<<"Present days are: "<<present<<endl;
        cout<<"Absent days are: "<<absent<<endl;
        if (absent>=30)
        {
            cout<<"You are not eligible for exam"<<endl;
            Com1();
        }
    }

};
//////////////////////////////////

class mark_check_bcs_1 : public Log_in
{
public:

    float algebra,english,islamic,it,ip,physics;

    void dis_bcs_1()
    {
        double average=(algebra+physics+ip+it+islamic+english)/6;
        cout<<"Algebra mark is: "<<algebra<<endl;
        cout<<"Physics mark is: "<<physics<<endl;
        cout<<"Ip mark is: "<<ip<<endl;
        cout<<"It mark is: "<<it<<endl;
        cout<<"Islamic mark is: "<<islamic<<endl;
        cout<<"English mark is: "<<english<<endl;
        cout<<"****************"<<endl;
        cout<<"Your average is: "<<average<<endl;
        if (average>=90)
        {
            cout<<"A"<<endl;
            Com1();
        }
            else if (average>=80)
            {
                cout<<"B"<<endl;
                Com1();
            }
                else if (average>=70)
                {
                    cout<<"C"<<endl;
                    Com1();
                }
                    else if (average>=60)
                    {
                        cout<<"D"<<endl;
                        Com1();
                    }
                        else
                        {
                            cout<<"Sorry!"<<endl;
                            Com1();
                        }
    }

};
//////////////////////////////////////////////////////////////////////////////// SECOND SEMESTER
class mark_check_bcs_2 : public Log_in
{
public:

    float calculus,b_com,history,d_com,oop,b_study;

    void dis_bcs_2()
    {
        double average=(calculus+b_study+oop+d_com+history+b_com)/6;
            cout<<"Calculus mark is: "<<calculus<<endl;
            cout<<"B_study mark is: "<<b_study<<endl;
            cout<<"Oop mark is: "<<oop<<endl;
            cout<<"D_com mark is: "<<d_com<<endl;
            cout<<"History mark is: "<<history<<endl;
            cout<<"B_com mark is: "<<b_com<<endl;
            cout<<"****************"<<endl;
            cout<<"Your average is: "<<average<<endl;
            if (average>=90)
            {
                cout<<"A"<<endl;
                Com1();
            }
                else if (average>=80)
                {
                    cout<<"B"<<endl;
                    Com1();
                }
                    else if (average>=70)
                    {
                        cout<<"C"<<endl;
                        Com1();
                    }
                        else if (average>=60)
                        {
                            cout<<"D"<<endl;
                            Com1();
                        }
                            else
                            {
                                cout<<"You are borrower!"<<endl;
                                Com1();
                            }
    }

};
//////////////////////////////////////////////////////////////////////////////// THIRD SEMESTER
class mark_check_bcs_3 : public Log_in
{
public:

    float S1,S2,S3,S4,S5,S6;

    void dis_bcs_3()
    {
        double average=(S1+S2+S3+S4+S5+S6)/6;
        cout<<"S1 mark is: "<<S1<<endl;
        cout<<"S2 mark is: "<<S2<<endl;
        cout<<"S3 mark is: "<<S3<<endl;
        cout<<"S4 mark is: "<<S4<<endl;
        cout<<"S5 mark is: "<<S5<<endl;
        cout<<"S6 mark is: "<<S6<<endl;
        cout<<"****************"<<endl;
        cout<<"Your average is: "<<average<<endl;
        if (average>=90)
        {
            cout<<"A"<<endl;
            Com1();
        }
            else if (average>=80)
            {
                cout<<"B"<<endl;
                Com1();
            }
                else if (average>=70)
                {
                    cout<<"C"<<endl;
                    Com1();
                }
                    else if (average>=60)
                    {
                        cout<<"D"<<endl;
                        Com1();
                    }
                        else
                        {
                            cout<<"You are borrower!"<<endl;
                            Com1();
                        }
    }

};
///////////////////////////////////////////////////////////////////////////// FOURTH SEMESTER
class mark_check_bcs_4 : public Log_in
{
public:

    float S1,S2,S3,S4,S5,S6;

    void dis_bcs_4()
    {
        double average=(S1+S2+S3+S4+S5+S6)/6;
        cout<<"S1 mark is: "<<S1<<endl;
        cout<<"S2 mark is: "<<S2<<endl;
        cout<<"S3 mark is: "<<S3<<endl;
        cout<<"S4 mark is: "<<S4<<endl;
        cout<<"S5 mark is: "<<S5<<endl;
        cout<<"S6 mark is: "<<S6<<endl;
        cout<<"****************"<<endl;
        cout<<"Your average is: "<<average<<endl;
        if (average>=90)
        {
            cout<<"A"<<endl;
            Com1();
        }
            else if (average>=80)
            {
                cout<<"B"<<endl;
                Com1();
            }
                else if (average>=70)
                {
                    cout<<"C"<<endl;
                    Com1();
                }
                    else if (average>=60)
                    {
                        cout<<"D"<<endl;
                        Com1();
                    }
                        else
                        {
                            cout<<"You are borrower!"<<endl;
                            Com1();
                        }
    }

};
///////////////////////////////////////////////////////////////////////////// FIFTH SEMESTER
class mark_check_bcs_5 : public Log_in
{
public:

    float S1,S2,S3,S4,S5,S6;

    void dis_bcs_5()
    {
        double average=(S1+S2+S3+S4+S5+S6)/6;
        cout<<"S1 mark is: "<<S1<<endl;
        cout<<"S2 mark is: "<<S2<<endl;
        cout<<"S3 mark is: "<<S3<<endl;
        cout<<"S4 mark is: "<<S4<<endl;
        cout<<"S5 mark is: "<<S5<<endl;
        cout<<"S6 mark is: "<<S6<<endl;
        cout<<"****************"<<endl;
        cout<<"Your average is: "<<average<<endl;
        if (average>=90)
        {
            cout<<"A"<<endl;
            Com1();
        }
            else if (average>=80)
            {
                cout<<"B"<<endl;
                Com1();
            }
                else if (average>=70)
                {
                    cout<<"C"<<endl;
                    Com1();
                }
                    else if (average>=60)
                    {
                        cout<<"D"<<endl;
                        Com1();
                    }
                        else
                        {
                            cout<<"You are borrower!"<<endl;
                            Com1();
                        }
    }

};
///////////////////////////////////////////////////////////////////////////// SIXTH SEMESTER
class mark_check_bcs_6 : public Log_in
{
public:

    float S1,S2,S3,S4,S5,S6;

    void dis_bcs_6()
    {
        double average=(S1+S2+S3+S4+S5+S6)/6;
        cout<<"S1 mark is: "<<S1<<endl;
        cout<<"S2 mark is: "<<S2<<endl;
        cout<<"S3 mark is: "<<S3<<endl;
        cout<<"S4 mark is: "<<S4<<endl;
        cout<<"S5 mark is: "<<S5<<endl;
        cout<<"S6 mark is: "<<S6<<endl;
        cout<<"****************"<<endl;
        cout<<"Your average is: "<<average<<endl;
        if (average>=90)
        {
            cout<<"A"<<endl;
            Com1();
        }
            else if (average>=80)
            {
                cout<<"B"<<endl;
                Com1();
            }
                else if (average>=70)
                {
                    cout<<"C"<<endl;
                    Com1();
                }
                    else if (average>=60)
                    {
                        cout<<"D"<<endl;
                        Com1();
                    }
                        else
                        {
                            cout<<"You are borrower!"<<endl;
                            Com1();
                        }
    }

};
///////////////////////////////////////////////////////////////////////////// SEVENTH SEMESTER
class mark_check_bcs_7 : public Log_in
{
public:

    float S1,S2,S3,S4,S5,S6;

    void dis_bcs_7()
    {
        double average=(S1+S2+S3+S4+S5+S6)/6;
        cout<<"S1 mark is: "<<S1<<endl;
        cout<<"S2 mark is: "<<S2<<endl;
        cout<<"S3 mark is: "<<S3<<endl;
        cout<<"S4 mark is: "<<S4<<endl;
        cout<<"S5 mark is: "<<S5<<endl;
        cout<<"S6 mark is: "<<S6<<endl;
        cout<<"****************"<<endl;
        cout<<"Your average is: "<<average<<endl;
        if (average>=90)
        {
            cout<<"A"<<endl;
            Com1();
        }
            else if (average>=80)
            {
                cout<<"B"<<endl;
                Com1();
            }
                else if (average>=70)
                {
                    cout<<"C"<<endl;
                    Com1();
                }
                    else if (average>=60)
                    {
                        cout<<"D"<<endl;
                        Com1();
                    }
                        else
                        {
                            cout<<"You are borrower!"<<endl;
                            Com1();
                        }
    }

};
///////////////////////////////////////////////////////////////////////////// EIGHT SEMESTER
class mark_check_bcs_8 : public Log_in
{
public:

    float S1,S2,S3,S4,S5,S6;

    void dis_bcs_8()
    {
        double average=(S1+S2+S3+S4+S5+S6)/6;
        cout<<"S1 mark is: "<<S1<<endl;
        cout<<"S2 mark is: "<<S2<<endl;
        cout<<"S3 mark is: "<<S3<<endl;
        cout<<"S4 mark is: "<<S4<<endl;
        cout<<"S5 mark is: "<<S5<<endl;
        cout<<"S6 mark is: "<<S6<<endl;
        cout<<"****************"<<endl;
        cout<<"Your average is: "<<average<<endl;
        if (average>=90)
        {
            cout<<"A"<<endl;
            Com1();
        }
            else if (average>=80)
            {
                cout<<"B"<<endl;
                Com1();
            }
                else if (average>=70)
                {
                    cout<<"C"<<endl;
                    Com1();
                }
                    else if (average>=60)
                    {
                        cout<<"D"<<endl;
                        Com1();
                    }
                        else
                        {
                            cout<<"You are borrower!"<<endl;
                            Com1();
                        }
    }

};
/////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////
//                                      BBA
///////////////////////////////////////////////////////////// FIRST SEMESTER
class mark_check_bba_1 : public Log_in
{
public:

    float S1,S2,S3,S4,S5,S6;

    void dis_bba_1()
    {
        double average=(S1+S2+S3+S4+S5+S6)/6;
        cout<<"S1 mark is: "<<S1<<endl;
        cout<<"S2 mark is: "<<S2<<endl;
        cout<<"S3 mark is: "<<S3<<endl;
        cout<<"S4 mark is: "<<S4<<endl;
        cout<<"S5 mark is: "<<S5<<endl;
        cout<<"S6 mark is: "<<S6<<endl;
        cout<<"****************"<<endl;
        cout<<"Your average is: "<<average<<endl;
        if (average>=90)
        {
            cout<<"A"<<endl;
            Com1();
        }
            else if (average>=80)
            {
                cout<<"B"<<endl;
                Com1();
            }
                else if (average>=70)
                {
                    cout<<"C"<<endl;
                    Com1();
                }
                    else if (average>=60)
                    {
                        cout<<"D"<<endl;
                        Com1();
                    }
                        else
                        {
                            cout<<"You are borrower!"<<endl;
                            Com1();
                        }
    }

};
//////////////////////////////////////////////////////////////  SECOND SEMESTER
class mark_check_bba_2 : public Log_in
{
public:

    float S1,S2,S3,S4,S5,S6;

    void dis_bba_2()
    {
        double average=(S1+S2+S3+S4+S5+S6)/6;
        cout<<"S1 mark is: "<<S1<<endl;
        cout<<"S2 mark is: "<<S2<<endl;
        cout<<"S3 mark is: "<<S3<<endl;
        cout<<"S4 mark is: "<<S4<<endl;
        cout<<"S5 mark is: "<<S5<<endl;
        cout<<"S6 mark is: "<<S6<<endl;
        cout<<"****************"<<endl;
        cout<<"Your average is: "<<average<<endl;
        if (average>=90)
        {
            cout<<"A"<<endl;
            Com1();
        }
            else if (average>=80)
            {
                cout<<"B"<<endl;
                Com1();
            }
                else if (average>=70)
                {
                    cout<<"C"<<endl;
                    Com1();
                }
                    else if (average>=60)
                    {
                        cout<<"D"<<endl;
                        Com1();
                    }
                        else
                        {
                            cout<<"You are borrower!"<<endl;
                            Com1();
                        }
    }

};
//////////////////////////////////////////////////////////  THIRD SEMESTER
class mark_check_bba_3 : public Log_in
{
public:

    float S1,S2,S3,S4,S5,S6;

    void dis_bba_3()
    {
        double average=(S1+S2+S3+S4+S5+S6)/6;
        cout<<"S1 mark is: "<<S1<<endl;
        cout<<"S2 mark is: "<<S2<<endl;
        cout<<"S3 mark is: "<<S3<<endl;
        cout<<"S4 mark is: "<<S4<<endl;
        cout<<"S5 mark is: "<<S5<<endl;
        cout<<"S6 mark is: "<<S6<<endl;
        cout<<"****************"<<endl;
        cout<<"Your average is: "<<average<<endl;
        if (average>=90)
        {
            cout<<"A"<<endl;
            Com1();
        }
            else if (average>=80)
            {
                cout<<"B"<<endl;
                Com1();
            }
                else if (average>=70)
                {
                    cout<<"C"<<endl;
                    Com1();
                }
                    else if (average>=60)
                    {
                        cout<<"D"<<endl;
                        Com1();
                    }
                        else
                        {
                            cout<<"You are borrower!"<<endl;
                            Com1();
                        }
    }

};
/////////////////////////////////////////////////////   FOURTH SEMESTER
class mark_check_bba_4 : public Log_in
{
public:

    float S1,S2,S3,S4,S5,S6;

    void dis_bba_4()
    {
        double average=(S1+S2+S3+S4+S5+S6)/6;
        cout<<"S1 mark is: "<<S1<<endl;
        cout<<"S2 mark is: "<<S2<<endl;
        cout<<"S3 mark is: "<<S3<<endl;
        cout<<"S4 mark is: "<<S4<<endl;
        cout<<"S5 mark is: "<<S5<<endl;
        cout<<"S6 mark is: "<<S6<<endl;
        cout<<"****************"<<endl;
        cout<<"Your average is: "<<average<<endl;
        if (average>=90)
        {
            cout<<"A"<<endl;
            Com1();
        }
            else if (average>=80)
            {
                cout<<"B"<<endl;
                Com1();
            }
                else if (average>=70)
                {
                    cout<<"C"<<endl;
                    Com1();
                }
                    else if (average>=60)
                    {
                        cout<<"D"<<endl;
                        Com1();
                    }
                        else
                        {
                            cout<<"You are borrower!"<<endl;
                            Com1();
                        }
    }

};
////////////////////////////////////////////////////    FIFTH SEMESTER
class mark_check_bba_5 : public Log_in
{
public:

    float S1,S2,S3,S4,S5,S6;

    void dis_bba_5()
    {
        double average=(S1+S2+S3+S4+S5+S6)/6;
        cout<<"S1 mark is: "<<S1<<endl;
        cout<<"S2 mark is: "<<S2<<endl;
        cout<<"S3 mark is: "<<S3<<endl;
        cout<<"S4 mark is: "<<S4<<endl;
        cout<<"S5 mark is: "<<S5<<endl;
        cout<<"S6 mark is: "<<S6<<endl;
        cout<<"****************"<<endl;
        cout<<"Your average is: "<<average<<endl;
        if (average>=90)
        {
            cout<<"A"<<endl;
            Com1();
        }
            else if (average>=80)
            {
                cout<<"B"<<endl;
                Com1();
            }
                else if (average>=70)
                {
                    cout<<"C"<<endl;
                    Com1();
                }
                    else if (average>=60)
                    {
                        cout<<"D"<<endl;
                        Com1();
                    }
                        else
                        {
                            cout<<"You are borrower!"<<endl;
                            Com1();
                        }
    }

};
//////////////////////////////////////////////////////////  SIXTH SEMESTER
class mark_check_bba_6 : public Log_in
{
public:

    float S1,S2,S3,S4,S5,S6;

    void dis_bba_6()
    {
        double average=(S1+S2+S3+S4+S5+S6)/6;
        cout<<"S1 mark is: "<<S1<<endl;
        cout<<"S2 mark is: "<<S2<<endl;
        cout<<"S3 mark is: "<<S3<<endl;
        cout<<"S4 mark is: "<<S4<<endl;
        cout<<"S5 mark is: "<<S5<<endl;
        cout<<"S6 mark is: "<<S6<<endl;
        cout<<"****************"<<endl;
        cout<<"Your average is: "<<average<<endl;
        if (average>=90)
        {
            cout<<"A"<<endl;
            Com1();
        }
            else if (average>=80)
            {
                cout<<"B"<<endl;
                Com1();
            }
                else if (average>=70)
                {
                    cout<<"C"<<endl;
                    Com1();
                }
                    else if (average>=60)
                    {
                        cout<<"D"<<endl;
                        Com1();
                    }
                        else
                        {
                            cout<<"You are borrower!"<<endl;
                            Com1();
                        }
    }

};
/////////////////////////////////////////////////   SEVENT SEMESTER
class mark_check_bba_7 : public Log_in
{
public:

    float S1,S2,S3,S4,S5,S6;

    void dis_bba_7()
    {
        double average=(S1+S2+S3+S4+S5+S6)/6;
        cout<<"S1 mark is: "<<S1<<endl;
        cout<<"S2 mark is: "<<S2<<endl;
        cout<<"S3 mark is: "<<S3<<endl;
        cout<<"S4 mark is: "<<S4<<endl;
        cout<<"S5 mark is: "<<S5<<endl;
        cout<<"S6 mark is: "<<S6<<endl;
        cout<<"****************"<<endl;
        cout<<"Your average is: "<<average<<endl;
        if (average>=90)
        {
            cout<<"A"<<endl;
            Com1();
        }
            else if (average>=80)
            {
                cout<<"B"<<endl;
                Com1();
            }
                else if (average>=70)
                {
                    cout<<"C"<<endl;
                    Com1();
                }
                    else if (average>=60)
                    {
                        cout<<"D"<<endl;
                        Com1();
                    }
                        else
                        {
                            cout<<"You are borrower!"<<endl;
                            Com1();
                        }
    }

};
/////////////////////////////////////////////////////   EIGHT SEMESTER
class mark_check_bba_8 : public Log_in
{
public:

    float S1,S2,S3,S4,S5,S6;

    void dis_bba_8()
    {
        double average=(S1+S2+S3+S4+S5+S6)/6;
        cout<<"S1 mark is: "<<S1<<endl;
        cout<<"S2 mark is: "<<S2<<endl;
        cout<<"S3 mark is: "<<S3<<endl;
        cout<<"S4 mark is: "<<S4<<endl;
        cout<<"S5 mark is: "<<S5<<endl;
        cout<<"S6 mark is: "<<S6<<endl;
        cout<<"****************"<<endl;
        cout<<"Your average is: "<<average<<endl;
        if (average>=90)
        {
            cout<<"A"<<endl;
            Com1();
        }
            else if (average>=80)
            {
                cout<<"B"<<endl;
                Com1();
            }
                else if (average>=70)
                {
                    cout<<"C"<<endl;
                    Com1();
                }
                    else if (average>=60)
                    {
                        cout<<"D"<<endl;
                        Com1();
                    }
                        else
                        {
                            cout<<"You are borrower!"<<endl;
                            Com1();
                        }
    }

};
////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////
//                                      LAW
////////////////////////////////////////////////////////    FIRST SEMESTER
class mark_check_law_1 : public Log_in
{
public:

    float S1,S2,S3,S4,S5,S6;

    void dis_law_1()
    {
        double average=(S1+S2+S3+S4+S5+S6)/6;
        cout<<"S1 mark is: "<<S1<<endl;
        cout<<"S2 mark is: "<<S2<<endl;
        cout<<"S3 mark is: "<<S3<<endl;
        cout<<"S4 mark is: "<<S4<<endl;
        cout<<"S5 mark is: "<<S5<<endl;
        cout<<"S6 mark is: "<<S6<<endl;
        cout<<"****************"<<endl;
        cout<<"Your average is: "<<average<<endl;
        if (average>=90)
        {
            cout<<"A"<<endl;
            Com1();
        }
            else if (average>=80)
            {
                cout<<"B"<<endl;
                Com1();
            }
                else if (average>=70)
                {
                    cout<<"C"<<endl;
                    Com1();
                }
                    else if (average>=60)
                    {
                        cout<<"D"<<endl;
                        Com1();
                    }
                        else
                        {
                            cout<<"You are borrower!"<<endl;
                            Com1();
                        }
    }

};
////////////////////////////////////////////////////    SECOND SEMESTER
class mark_check_law_2 : public Log_in
{
public:

    float S1,S2,S3,S4,S5,S6;

    void dis_law_2()
    {
        double average=(S1+S2+S3+S4+S5+S6)/6;
        cout<<"S1 mark is: "<<S1<<endl;
        cout<<"S2 mark is: "<<S2<<endl;
        cout<<"S3 mark is: "<<S3<<endl;
        cout<<"S4 mark is: "<<S4<<endl;
        cout<<"S5 mark is: "<<S5<<endl;
        cout<<"S6 mark is: "<<S6<<endl;
        cout<<"****************"<<endl;
        cout<<"Your average is: "<<average<<endl;
        if (average>=90)
        {
            cout<<"A"<<endl;
            Com1();
        }
            else if (average>=80)
            {
                cout<<"B"<<endl;
                Com1();
            }
                else if (average>=70)
                {
                    cout<<"C"<<endl;
                    Com1();
                }
                    else if (average>=60)
                    {
                        cout<<"D"<<endl;
                        Com1();
                    }
                        else
                        {
                            cout<<"You are borrower!"<<endl;
                            Com1();
                        }
    }

};
/////////////////////////////////////////////////////   THIRD SEMESTER
class mark_check_law_3 : public Log_in
{
public:

    float S1,S2,S3,S4,S5,S6;

    void dis_law_3()
    {
        double average=(S1+S2+S3+S4+S5+S6)/6;
        cout<<"S1 mark is: "<<S1<<endl;
        cout<<"S2 mark is: "<<S2<<endl;
        cout<<"S3 mark is: "<<S3<<endl;
        cout<<"S4 mark is: "<<S4<<endl;
        cout<<"S5 mark is: "<<S5<<endl;
        cout<<"S6 mark is: "<<S6<<endl;
        cout<<"****************"<<endl;
        cout<<"Your average is: "<<average<<endl;
        if (average>=90)
        {
            cout<<"A"<<endl;
            Com1();
        }
            else if (average>=80)
            {
                cout<<"B"<<endl;
                Com1();
            }
                else if (average>=70)
                {
                    cout<<"C"<<endl;
                    Com1();
                }
                    else if (average>=60)
                    {
                        cout<<"D"<<endl;
                        Com1();
                    }
                        else
                        {
                            cout<<"You are borrower!"<<endl;
                            Com1();
                        }
    }

};
/////////////////////////////////////////////////   FOURTH SEMESTER
class mark_check_law_4 : public Log_in
{
public:

    float S1,S2,S3,S4,S5,S6;

    void dis_law_4()
    {
        double average=(S1+S2+S3+S4+S5+S6)/6;
        cout<<"S1 mark is: "<<S1<<endl;
        cout<<"S2 mark is: "<<S2<<endl;
        cout<<"S3 mark is: "<<S3<<endl;
        cout<<"S4 mark is: "<<S4<<endl;
        cout<<"S5 mark is: "<<S5<<endl;
        cout<<"S6 mark is: "<<S6<<endl;
        cout<<"****************"<<endl;
        cout<<"Your average is: "<<average<<endl;
        if (average>=90)
        {
            cout<<"A"<<endl;
            Com1();
        }
            else if (average>=80)
            {
                cout<<"B"<<endl;
                Com1();
            }
                else if (average>=70)
                {
                    cout<<"C"<<endl;
                    Com1();
                }
                    else if (average>=60)
                    {
                        cout<<"D"<<endl;
                        Com1();
                    }
                        else
                        {
                            cout<<"You are borrower!"<<endl;
                            Com1();
                        }
    }

};
////////////////////////////////////////////////////////    FIFTH SEMESTER
class mark_check_law_5 : public Log_in
{
public:

    float S1,S2,S3,S4,S5,S6;

    void dis_law_5()
    {
        double average=(S1+S2+S3+S4+S5+S6)/6;
        cout<<"S1 mark is: "<<S1<<endl;
        cout<<"S2 mark is: "<<S2<<endl;
        cout<<"S3 mark is: "<<S3<<endl;
        cout<<"S4 mark is: "<<S4<<endl;
        cout<<"S5 mark is: "<<S5<<endl;
        cout<<"S6 mark is: "<<S6<<endl;
        cout<<"****************"<<endl;
        cout<<"Your average is: "<<average<<endl;
        if (average>=90)
        {
            cout<<"A"<<endl;
            Com1();
        }
            else if (average>=80)
            {
                cout<<"B"<<endl;
                Com1();
            }
                else if (average>=70)
                {
                    cout<<"C"<<endl;
                    Com1();
                }
                    else if (average>=60)
                    {
                        cout<<"D"<<endl;
                        Com1();
                    }
                        else
                        {
                            cout<<"You are borrower!"<<endl;
                            Com1();
                        }
    }

};
/////////////////////////////////////////// SIXTH SEMESTER
class mark_check_law_6 : public Log_in
{
public:

    float S1,S2,S3,S4,S5,S6;

    void dis_law_6()
    {
        double average=(S1+S2+S3+S4+S5+S6)/6;
        cout<<"S1 mark is: "<<S1<<endl;
        cout<<"S2 mark is: "<<S2<<endl;
        cout<<"S3 mark is: "<<S3<<endl;
        cout<<"S4 mark is: "<<S4<<endl;
        cout<<"S5 mark is: "<<S5<<endl;
        cout<<"S6 mark is: "<<S6<<endl;
        cout<<"****************"<<endl;
        cout<<"Your average is: "<<average<<endl;
        if (average>=90)
        {
            cout<<"A"<<endl;
            Com1();
        }
            else if (average>=80)
            {
                cout<<"B"<<endl;
                Com1();
            }
                else if (average>=70)
                {
                    cout<<"C"<<endl;
                    Com1();
                }
                    else if (average>=60)
                    {
                        cout<<"D"<<endl;
                        Com1();
                    }
                        else
                        {
                            cout<<"You are borrower!"<<endl;
                            Com1();
                        }
    }

};
////////////////////////////////////////////////////    SEVENT SEMESTER
class mark_check_law_7 : public Log_in
{
public:

    float S1,S2,S3,S4,S5,S6;

    void dis_law_7()
    {
        double average=(S1+S2+S3+S4+S5+S6)/6;
        cout<<"S1 mark is: "<<S1<<endl;
        cout<<"S2 mark is: "<<S2<<endl;
        cout<<"S3 mark is: "<<S3<<endl;
        cout<<"S4 mark is: "<<S4<<endl;
        cout<<"S5 mark is: "<<S5<<endl;
        cout<<"S6 mark is: "<<S6<<endl;
        cout<<"****************"<<endl;
        cout<<"Your average is: "<<average<<endl;
        if (average>=90)
        {
            cout<<"A"<<endl;
            Com1();
        }
            else if (average>=80)
            {
                cout<<"B"<<endl;
                Com1();
            }
                else if (average>=70)
                {
                    cout<<"C"<<endl;
                    Com1();
                }
                    else if (average>=60)
                    {
                        cout<<"D"<<endl;
                        Com1();
                    }
                        else
                        {
                            cout<<"You are borrower!"<<endl;
                            Com1();
                        }
    }

};
/////////////////////////////////////////////////////   EIGHT SEMESTER
class mark_check_law_8 : public Log_in
{
public:

    float S1,S2,S3,S4,S5,S6;

    void dis_law_8()
    {
        double average=(S1+S2+S3+S4+S5+S6)/6;
        cout<<"S1 mark is: "<<S1<<endl;
        cout<<"S2 mark is: "<<S2<<endl;
        cout<<"S3 mark is: "<<S3<<endl;
        cout<<"S4 mark is: "<<S4<<endl;
        cout<<"S5 mark is: "<<S5<<endl;
        cout<<"S6 mark is: "<<S6<<endl;
        cout<<"****************"<<endl;
        cout<<"Your average is: "<<average<<endl;
        if (average>=90)
        {
            cout<<"A"<<endl;
            Com1();
        }
            else if (average>=80)
            {
                cout<<"B"<<endl;
                Com1();
            }
                else if (average>=70)
                {
                    cout<<"C"<<endl;
                    Com1();
                }
                    else if (average>=60)
                    {
                        cout<<"D"<<endl;
                        Com1();
                    }
                        else
                        {
                            cout<<"You are borrower!"<<endl;
                            Com1();
                        }
    }

};
/////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////
//                                      JOR
////////////////////////////////////////////////////////////    FIRST SEMESTER
class mark_check_jor_1 : public Log_in
{
public:

    float S1,S2,S3,S4,S5,S6;

    void dis_jor_1()
    {
        double average=(S1+S2+S3+S4+S5+S6)/6;
        cout<<"S1 mark is: "<<S1<<endl;
        cout<<"S2 mark is: "<<S2<<endl;
        cout<<"S3 mark is: "<<S3<<endl;
        cout<<"S4 mark is: "<<S4<<endl;
        cout<<"S5 mark is: "<<S5<<endl;
        cout<<"S6 mark is: "<<S6<<endl;
        cout<<"****************"<<endl;
        cout<<"Your average is: "<<average<<endl;
        if (average>=90)
        {
            cout<<"A"<<endl;
            Com1();
        }
            else if (average>=80)
            {
                cout<<"B"<<endl;
                Com1();
            }
                else if (average>=70)
                {
                    cout<<"C"<<endl;
                    Com1();
                }
                    else if (average>=60)
                    {
                        cout<<"D"<<endl;
                        Com1();
                    }
                        else
                        {
                            cout<<"You are borrower!"<<endl;
                            Com1();
                        }
    }

};
////////////////////////////////////////////////////////////////    SECOND SEMESTER
class mark_check_jor_2 : public Log_in
{
public:

    float S1,S2,S3,S4,S5,S6;

    void dis_jor_2()
    {
        double average=(S1+S2+S3+S4+S5+S6)/6;
        cout<<"S1 mark is: "<<S1<<endl;
        cout<<"S2 mark is: "<<S2<<endl;
        cout<<"S3 mark is: "<<S3<<endl;
        cout<<"S4 mark is: "<<S4<<endl;
        cout<<"S5 mark is: "<<S5<<endl;
        cout<<"S6 mark is: "<<S6<<endl;
        cout<<"****************"<<endl;
        cout<<"Your average is: "<<average<<endl;
        if (average>=90)
        {
            cout<<"A"<<endl;
            Com1();
        }
            else if (average>=80)
            {
                cout<<"B"<<endl;
                Com1();
            }
                else if (average>=70)
                {
                    cout<<"C"<<endl;
                    Com1();
                }
                    else if (average>=60)
                    {
                        cout<<"D"<<endl;
                        Com1();
                    }
                        else
                        {
                            cout<<"You are borrower!"<<endl;
                            Com1();
                        }
    }

};
////////////////////////////////////////////////////////////////////    THIRD SEMESTER
class mark_check_jor_3 : public Log_in
{
public:

    float S1,S2,S3,S4,S5,S6;

    void dis_jor_3()
    {
        double average=(S1+S2+S3+S4+S5+S6)/6;
        cout<<"S1 mark is: "<<S1<<endl;
        cout<<"S2 mark is: "<<S2<<endl;
        cout<<"S3 mark is: "<<S3<<endl;
        cout<<"S4 mark is: "<<S4<<endl;
        cout<<"S5 mark is: "<<S5<<endl;
        cout<<"S6 mark is: "<<S6<<endl;
        cout<<"****************"<<endl;
        cout<<"Your average is: "<<average<<endl;
        if (average>=90)
        {
            cout<<"A"<<endl;
            Com1();
        }
            else if (average>=80)
            {
                cout<<"B"<<endl;
                Com1();
            }
                else if (average>=70)
                {
                    cout<<"C"<<endl;
                    Com1();
                }
                    else if (average>=60)
                    {
                        cout<<"D"<<endl;
                        Com1();
                    }
                        else
                        {
                            cout<<"You are borrower!"<<endl;
                            Com1();
                        }
    }

};
////////////////////////////////////////////////////////////////    FOURTH SEMESTER
class mark_check_jor_4 : public Log_in
{
public:

    float S1,S2,S3,S4,S5,S6;

    void dis_jor_4()
    {
        double average=(S1+S2+S3+S4+S5+S6)/6;
        cout<<"S1 mark is: "<<S1<<endl;
        cout<<"S2 mark is: "<<S2<<endl;
        cout<<"S3 mark is: "<<S3<<endl;
        cout<<"S4 mark is: "<<S4<<endl;
        cout<<"S5 mark is: "<<S5<<endl;
        cout<<"S6 mark is: "<<S6<<endl;
        cout<<"****************"<<endl;
        cout<<"Your average is: "<<average<<endl;
        if (average>=90)
        {
            cout<<"A"<<endl;
            Com1();
        }
            else if (average>=80)
            {
                cout<<"B"<<endl;
                Com1();
            }
                else if (average>=70)
                {
                    cout<<"C"<<endl;
                    Com1();
                }
                    else if (average>=60)
                    {
                        cout<<"D"<<endl;
                        Com1();
                    }
                        else
                        {
                            cout<<"You are borrower!"<<endl;
                            Com1();
                        }
    }

};
////////////////////////////////////////////////////////////////////    FIFTH SEMESTER
class mark_check_jor_5 : public Log_in
{
public:

    float S1,S2,S3,S4,S5,S6;

    void dis_jor_5()
    {
        double average=(S1+S2+S3+S4+S5+S6)/6;
        cout<<"S1 mark is: "<<S1<<endl;
        cout<<"S2 mark is: "<<S2<<endl;
        cout<<"S3 mark is: "<<S3<<endl;
        cout<<"S4 mark is: "<<S4<<endl;
        cout<<"S5 mark is: "<<S5<<endl;
        cout<<"S6 mark is: "<<S6<<endl;
        cout<<"****************"<<endl;
        cout<<"Your average is: "<<average<<endl;
        if (average>=90)
        {
            cout<<"A"<<endl;
            Com1();
        }
            else if (average>=80)
            {
                cout<<"B"<<endl;
                Com1();
            }
                else if (average>=70)
                {
                    cout<<"C"<<endl;
                    Com1();
                }
                    else if (average>=60)
                    {
                        cout<<"D"<<endl;
                        Com1();
                    }
                        else
                        {
                            cout<<"You are borrower!"<<endl;
                            Com1();
                        }
    }

};
////////////////////////////////////////////////////////////////////    SIXTH SEMESTER
class mark_check_jor_6 : public Log_in
{
public:

    float S1,S2,S3,S4,S5,S6;

    void dis_jor_6()
    {
        double average=(S1+S2+S3+S4+S5+S6)/6;
        cout<<"S1 mark is: "<<S1<<endl;
        cout<<"S2 mark is: "<<S2<<endl;
        cout<<"S3 mark is: "<<S3<<endl;
        cout<<"S4 mark is: "<<S4<<endl;
        cout<<"S5 mark is: "<<S5<<endl;
        cout<<"S6 mark is: "<<S6<<endl;
        cout<<"****************"<<endl;
        cout<<"Your average is: "<<average<<endl;
        if (average>=90)
        {
            cout<<"A"<<endl;
            Com1();
        }
            else if (average>=80)
            {
                cout<<"B"<<endl;
                Com1();
            }
                else if (average>=70)
                {
                    cout<<"C"<<endl;
                    Com1();
                }
                    else if (average>=60)
                    {
                        cout<<"D"<<endl;
                        Com1();
                    }
                        else
                        {
                            cout<<"You are borrower!"<<endl;
                            Com1();
                        }
    }

};
////////////////////////////////////////////////////////////////////////    SEVENT SEMESTER
class mark_check_jor_7 : public Log_in
{
public:

    float S1,S2,S3,S4,S5,S6;

    void dis_jor_7()
    {
        double average=(S1+S2+S3+S4+S5+S6)/6;
        cout<<"S1 mark is: "<<S1<<endl;
        cout<<"S2 mark is: "<<S2<<endl;
        cout<<"S3 mark is: "<<S3<<endl;
        cout<<"S4 mark is: "<<S4<<endl;
        cout<<"S5 mark is: "<<S5<<endl;
        cout<<"S6 mark is: "<<S6<<endl;
        cout<<"****************"<<endl;
        cout<<"Your average is: "<<average<<endl;
        if (average>=90)
        {
            cout<<"A"<<endl;
            Com1();
        }
            else if (average>=80)
            {
                cout<<"B"<<endl;
                Com1();
            }
                else if (average>=70)
                {
                    cout<<"C"<<endl;
                    Com1();
                }
                    else if (average>=60)
                    {
                        cout<<"D"<<endl;
                        Com1();
                    }
                        else
                        {
                            cout<<"You are borrower!"<<endl;
                            Com1();
                        }
    }

};
////////////////////////////////////////////////////////////////////    EIGHT SEMESTER
class mark_check_jor_8 : public Log_in
{
public:

    float S1,S2,S3,S4,S5,S6;

    void dis_jor_8()
    {
        double average=(S1+S2+S3+S4+S5+S6)/6;
        cout<<"S1 mark is: "<<S1<<endl;
        cout<<"S2 mark is: "<<S2<<endl;
        cout<<"S3 mark is: "<<S3<<endl;
        cout<<"S4 mark is: "<<S4<<endl;
        cout<<"S5 mark is: "<<S5<<endl;
        cout<<"S6 mark is: "<<S6<<endl;
        cout<<"****************"<<endl;
        cout<<"Your average is: "<<average<<endl;
        if (average>=90)
        {
            cout<<"A"<<endl;
            Com1();
        }
            else if (average>=80)
            {
                cout<<"B"<<endl;
                Com1();
            }
                else if (average>=70)
                {
                    cout<<"C"<<endl;
                    Com1();
                }
                    else if (average>=60)
                    {
                        cout<<"D"<<endl;
                        Com1();
                    }
                        else
                        {
                            cout<<"You are borrower!"<<endl;
                            Com1();
                        }
    }

};
///////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////


Log_in s;      /////////// SEARCH BOX


/////////   OBJECTS
Log_in bcs[100];
Log_in bba[100];
Log_in law[100];
Log_in jor[100];
//////////
Log_in bcs_1[100];
Log_in bba_1[100];
Log_in law_1[100];
Log_in jor_1[100];
/////////

/////////   SEMESTERS
/////////   BCS
mark_check_bcs_1 bcs1[100];
mark_check_bcs_2 bcs2[100];
mark_check_bcs_3 bcs3[100];
mark_check_bcs_4 bcs4[100];
mark_check_bcs_5 bcs5[100];
mark_check_bcs_6 bcs6[100];
mark_check_bcs_7 bcs7[100];
mark_check_bcs_8 bcs8[100];
/////////////////////////

/////////////////////////
/////////   BBA
mark_check_bba_1 bba1[100];
mark_check_bba_2 bba2[100];
mark_check_bba_3 bba3[100];
mark_check_bba_4 bba4[100];
mark_check_bba_5 bba5[100];
mark_check_bba_6 bba6[100];
mark_check_bba_7 bba7[100];
mark_check_bba_8 bba8[100];
////////    LAW
mark_check_law_1 law1[100];
mark_check_law_2 law2[100];
mark_check_law_3 law3[100];
mark_check_law_4 law4[100];
mark_check_law_5 law5[100];
mark_check_law_6 law6[100];
mark_check_law_7 law7[100];
mark_check_law_8 law8[100];
////////    JOR
mark_check_jor_1 jor1[100];
mark_check_jor_2 jor2[100];
mark_check_jor_3 jor3[100];
mark_check_jor_4 jor4[100];
mark_check_jor_5 jor5[100];
mark_check_jor_6 jor6[100];
mark_check_jor_7 jor7[100];
mark_check_jor_8 jor8[100];
/////////////////////////////////////


////// Computer Science department
void BCS()
{
    int w=1,q,j,mm;
    int semester;
    bool ab=true;
    char ch;
    char S[10];
    bool az;

    s.s_box();
    ifstream f2("bcs.CSV");

    f2 >> S;
    while (!f2.eof())
    {
        az=true;
        for (h ; h<100 ; h++)
        {
            bcs_1[h].id=S;
            break;
        }
        h++;
        while (az==true)
        {
            for (int k=0 ; k<10 ; k++)
            {
                if (s.Id==S)
                {
                    az=false;
                    break;
                }
                else
                {
                    az=true;
                    break;
                }
            }
            break;
        }
        if (az==false)
        {
            for (q=1 ; q<100 ; q++)
            {
                if (bcs[q].id==bcs_1[q].id || s.Id==bcs[q].id)
                {
                    if (bcs[q].id==bcs_1[q].id)
                    {
                        cout<<"\t\t\t\t\t----------------------------"<<endl;
                        cout<<"\t\t\t\t\tID is in database!"<<endl;
                        cout<<"\t\t\t\t\t----------------------------"<<endl;
                        Com1();
                    }
                    else
                    {
                        bcs[q].display();
                        ab=false;
                        cout<<"\t\t\tIf you want to see your marks press 1 . if you want to check attendance press 2: ";
                        cin>>mm;
                        if (mm==1)
                        {
                            cout<<"\t\t\t\t\tPlease enter your semester: ";   cin>>semester;

                            if (semester==1)
                            {
                                bcs1[q].dis_bcs_1();
                            }
                            else if (semester==2)
                            {
                                bcs2[q].dis_bcs_2();
                            }
                            else if (semester==3)
                            {
                                bcs3[q].dis_bcs_3();
                            }
                            else if (semester==4)
                            {
                                bcs4[q].dis_bcs_4();
                            }
                            else if (semester==5)
                            {
                                bcs5[q].dis_bcs_5();
                            }
                            else if (semester==6)
                            {
                                bcs6[q].dis_bcs_6();
                            }
                            else if (semester==7)
                            {
                                bcs7[q].dis_bcs_7();
                            }
                            else if (semester==8)
                            {
                                bcs8[q].dis_bcs_8();
                            }
                        }
                         else
                        {
                            bcs[q].dis_att();
                        }
                    }
                }
            }
        }
    f2 >> S;
    }
    ////////////////////////////

        if (ab)
        {
            cout<<"\t\t\t\t\tSorry TRY AGAIN"<<endl;
            BCS();
        }
        else
        {
            Com1();
        }


}
///////////////// BBA
void BBA()
{
    int f=50,j,w=1,q,y,mm;
    int semester;
    bool ab=true,az=true;
    char ch;
    char S[10];


    s.s_box();
    ifstream f2("bba.CSV");

    f2 >> S;
    while (!f2.eof())
    {
        az=true;
        for (h ; h<100 ; h++)
        {
            bba_1[h].id=S;
            break;
        }
        h++;
        while (az==true)
        {
            for (int k=0 ; k<10 ; k++)
            {
                if (s.Id==S)
                {
                    az=false;
                    break;
                }
                else
                {
                    az=true;
                    break;
                }
            }
            break;
        }
        if (az==false)
        {
            for (q=1 ; q<100 ; q++)
            {
                if (bba[q].id==bba_1[q].id || s.Id==bba[q].id)
                {
                    if (bba[q].id==bba_1[q].id)
                    {
                        cout<<"----------------------------"<<endl;
                        cout<<"\t\t\t\t\tID is in database!"<<endl;
                        cout<<"----------------------------"<<endl;
                        Com1();
                    }
                    else
                    {
                        bba[q].display();
                        ab=false;
                        cout<<"\t\t\tIf you want to see your marks press 1 . if you want to check attendance press 2: ";
                        cin>>mm;
                        if (mm==1)
                        {
                            cout<<"\t\t\t\t\tPlease enter your semester: ";   cin>>semester;

                            if (semester==1)
                            {
                                bba1[q].dis_bba_1();
                            }
                            else if (semester==2)
                            {
                                bba2[q].dis_bba_2();
                            }
                            else if (semester==3)
                            {
                                bba3[q].dis_bba_3();
                            }
                            else if (semester==4)
                            {
                                bba4[q].dis_bba_4();
                            }
                            else if (semester==5)
                            {
                                bba5[q].dis_bba_5();
                            }
                            else if (semester==6)
                            {
                                bba6[q].dis_bba_6();
                            }
                            else if (semester==7)
                            {
                                bba7[q].dis_bba_7();
                            }
                            else if (semester==8)
                            {
                                bba8[q].dis_bba_8();
                            }
                        }
                        else
                        {
                            bba[q].dis_att();
                        }
                    }
                }
            }
        }
    f2 >> S;
    }

        if (ab)
        {
            cout<<"\t\t\t\t\tSorry TRY AGAIN"<<endl;
            BBA();
        }
        else
        {
            Com1();
        }

}
///////////////// Law
void LAW()
{
    int j,w=1,q,y,mm;
    int semester;
    bool ab=true,az=true;
    char ch;
    char S[10];

    s.s_box();

    ifstream f2("law.CSV");

    f2 >> S;
    while (!f2.eof())
    {
        az=true;
        for (h ; h<100 ; h++)
        {
            law_1[h].id=S;
            break;
        }
        h++;
        while (az==true)
        {
            for (int k=0 ; k<10 ; k++)
            {
                if (s.Id==S)
                {
                    az=false;
                    break;
                }
                else
                {
                    az=true;
                    break;
                }
            }
            break;
        }
        if (az==false)
        {
            for (q=1 ; q<100 ; q++)
            {
                if (law[q].id==law_1[q].id || s.Id==law[q].id)
                {
                    if (law[q].id==law_1[q].id)
                    {
                        cout<<"----------------------------"<<endl;
                        cout<<"\t\t\t\t\tID is in database!"<<endl;
                        cout<<"----------------------------"<<endl;
                        Com1();
                    }
                    else
                    {
                        law[q].display();
                        ab=false;
                        cout<<"\t\t\tIf you want to see your marks press 1 . if you want to check attendance press 2: ";
                        cin>>mm;
                        if (mm==1)
                        {
                            cout<<"\t\t\t\t\tPlease enter your semester: ";   cin>>semester;

                            if (semester==1)
                            {
                                law1[q].dis_law_1();
                            }
                            else if (semester==2)
                            {
                                law2[q].dis_law_2();
                            }
                            else if (semester==3)
                            {
                                law3[q].dis_law_3();
                            }
                            else if (semester==4)
                            {
                                law4[q].dis_law_4();
                            }
                            else if (semester==5)
                            {
                                law5[q].dis_law_5();
                            }
                            else if (semester==6)
                            {
                                law6[q].dis_law_6();
                            }
                            else if (semester==7)
                            {
                                law7[q].dis_law_7();
                            }
                            else if (semester==8)
                            {
                                law8[q].dis_law_8();
                            }
                        }
                         else
                        {
                            law[q].dis_att();
                        }
                    }
                }
            }
        }
    f2 >> S;
    }

        if (ab)
        {
            cout<<"\t\t\t\t\tSorry TRY AGAIN"<<endl;
            LAW();
        }
        else
        {
            Com1();
        }

}
///////////////// Jor
void JOR()
{
    int f=50,j,w=1,q,y,mm;
    int semester;
    bool ab=true,az=true;
    char ch;
    char S[10];

    s.s_box();
    ifstream f2("jor.CSV");

    f2 >> S;
    while (!f2.eof())
    {
        az=true;
        for (h ; h<100 ; h++)
        {
            jor_1[h].id=S;
            break;
        }
        h++;
        while (az==true)
        {
            for (int k=0 ; k<10 ; k++)
            {
                if (s.Id==S)
                {
                    az=false;
                    break;
                }
                else
                {
                    az=true;
                    break;
                }
            }
            break;
        }
        if (az==false)
        {
            for (q=1 ; q<100 ; q++)
            {
                if (jor[q].id==jor_1[q].id || s.Id==jor[q].id)
                {
                    if (jor[q].id==jor_1[q].id)
                    {
                        cout<<"----------------------------"<<endl;
                        cout<<"\t\t\t\t\tID is in database!"<<endl;
                        cout<<"----------------------------"<<endl;
                        Com1();
                    }
                    else
                    {
                        jor[q].display();
                        ab=false;
                        cout<<"\t\t\tIf you want to see your marks press 1 . if you want to check attendance press 2: ";
                        cin>>mm;
                        if (mm==1)
                        {
                            cout<<"\t\t\t\t\tPlease enter your semester: ";   cin>>semester;

                            if (semester==1)
                            {
                                jor1[q].dis_jor_1();
                            }
                            else if (semester==2)
                            {
                                jor2[q].dis_jor_2();
                            }
                            else if (semester==3)
                            {
                                jor3[q].dis_jor_3();
                            }
                            else if (semester==4)
                            {
                                jor4[q].dis_jor_4();
                            }
                            else if (semester==5)
                            {
                                jor5[q].dis_jor_5();
                            }
                            else if (semester==6)
                            {
                                jor6[q].dis_jor_6();
                            }
                            else if (semester==7)
                            {
                                jor7[q].dis_jor_7();
                            }
                            else if (semester==8)
                            {
                                jor8[q].dis_jor_8();
                            }
                        }
                         else
                        {
                            jor[q].dis_att();
                        }
                    }
                }
            }
        }
    f2 >> S;
    }

        if (ab)
        {
            cout<<"\t\t\t\t\tSorry TRY AGAIN"<<endl;
            LAW();
        }
        else
        {
            Com1();
        }

}
///////////////// Admission
void ADMISSION()
{
    string depart;
    char ch;
    bool Again=true;
    cout<<"************************************************************************************************************************\n";
    cout<<"\t\t\t\t\tWelcome\n\t\t\t\t\tWhich Department do you want to join?"<<endl<<endl;
    cout<<"\t\t\t\t\t\tBCS\tBBA\tLAW\tJOR: ";
    cin>>depart;

    if (depart=="bcs")
    {
        while (Again)
        {
            for (a2 ; a2<100 ; a2++)
            {
                if (depart=="bcs")
                {
                    string Default = "BCS-";
                    bcs[a2].get_n();
                    output_bcs << bcs[a2].id;
                    output_bcs << endl;
                    if (strstr(bcs[a2].id.c_str(),Default.c_str()))
                    {
                        cout<<"\t\t\t\t\tIs there any new student? press y "<<endl;
                        cin>>ch;
                        if (ch=='y'||ch=='Y')
                        {
                            Again=true;
                            a2++;
                        }
                            else
                            {
                                Com1();
                            }
                    }
                        else
                        {
                            cout<<"ID wrong"<<endl;
                            ADMISSION();
                        }
                }

            }
        }
    }
    else if (depart=="bba")
    {
        while (Again)
        {
            for (a3 ; a3<100 ; a3++)
            {
                if (depart=="bba")
                {
                    string Default = "BBA-";
                    bba[a3].get_n();
                    output_bba << bba[a3].id;
                    output_bba << endl;
                    if (strstr(bba[a3].id.c_str(),Default.c_str()))
                    {
                       cout<<"\t\t\t\t\tIs there any new student? press y "<<endl;
                        cin>>ch;
                        if (ch=='y'||ch=='Y')
                        {
                            Again=true;
                            a3++;
                        }
                            else
                            {
                                Com1();
                            }
                    }
                            else
                            {
                                cout<<"Wrong ID"<<endl;
                                ADMISSION();
                            }
                }
            }
        }
    }
    else if (depart=="law")
    {
        while (Again)
        {
            for (a4 ; a4<100 ; a4++)
            {
                if (depart=="law")
                {
                    string Default = "LAW-";
                    law[a4].get_n();
                    output_law << law[a2].id;
                    output_law << endl;
                    if (strstr(law[a4].id.c_str(),Default.c_str()))
                    {
                       cout<<"\t\t\t\t\tIs there any new student? press y "<<endl;
                        cin>>ch;
                        if (ch=='y'||ch=='Y')
                        {
                            Again=true;
                            a4++;
                        }
                            else
                            {
                                Com1();
                            }
                    }
                            else
                            {
                                cout<<"Wrong ID"<<endl;
                                ADMISSION();
                            }
                }
            }
        }
    }
    else if (depart=="jor")
    {
        while (Again)
        {
            for (a5 ; a5<100 ; a5++)
            {
                if (depart=="jor")
                {
                    string Default = "JOR-";
                    jor[a5].get_n();
                    output_law << law[a2].id;
                    output_law << endl;
                    if (strstr(jor[a5].id.c_str(),Default.c_str()))
                    {
                       cout<<"\t\t\t\t\tIs there any new student? press y "<<endl;
                        cin>>ch;
                        if (ch=='y'||ch=='Y')
                        {
                            Again=true;
                            a5++;
                        }
                            else
                            {
                                Com1();
                            }
                    }
                            else
                            {
                                cout<<"Wrong ID"<<endl;
                                ADMISSION();
                            }
                }
            }
        }
    }
    else
    {
        cout<<"Wrong try again"<<endl;
        Com1();
    }
}
///////////////////// Management
void MAN ()
{
    char manage;
    string pass;
    cout<<"\t\t\t\t\tplease enter management password: ";  cin>>pass;
    if (pass=="RU123MA")
    {
        cout<<"\n\n******************************************************************************************"<<endl;
        cout<<"\t\t\t\t\tWhat do you want to do?"<<endl;
        cout<<"\t\t\t\t\tPress 1 for marks\n\t\t\t\t\tPress 2 for attendance"<<endl;
        cout<<"\t\t\t\t\t"; cin>>manage;
        if (manage=='1')
        {
        	MARKS();
        }
        else if (manage=='2')
        {

            ATTENDANCE();
		}
		else
		{
			cout<<"Sorry"<<endl;
			MAN();
		}
    }
        else
        {
            cout<<"Wrong please try again"<<endl;
            MAN();
        }
}
///////////////////// Marks
void MARKS ()
{
    string ID;
    string course;
    int semester;
    bool b=true,o=true;

    cout<<"Please enter your course: "; cin>>course;


    while (b)
    {
        if (course=="bcs")
        {
            cout<<"Select semester: ";  cin>>semester;

            if (semester==1)
            {
                cout<<"Enter student ID: "; cin>>ID;
                for (int i=1 ; i<100 ; i++)
                {

                    if (ID==bcs[i].id)
                    {
                        cout<<"Enter Algebra mark: ";    cin>>bcs1[i].algebra;
                        cout<<"Enter Physics mark: ";    cin>>bcs1[i].physics;
                        cout<<"Enter It mark: ";         cin>>bcs1[i].it;
                        cout<<"Enter Islamic mark: ";    cin>>bcs1[i].islamic;
                        cout<<"Enter English mark: ";    cin>>bcs1[i].english;
                        cout<<"Enter Ip mark: ";         cin>>bcs1[i].ip;
                        o=false;
                        b=false;
                        Com1();
                        break;
                    }
                }
            }
            ///////////////////////////////
            else if (semester==2)
             {
                cout<<"Enter student ID: "; cin>>ID;
                for (int i=1 ; i<100 ; i++)
                {
                    if (ID==bcs[i].id)
                    {
                        cout<<"Enter calculus mark: ";   cin>>bcs2[i].calculus;
                        cout<<"Enter B study mark: ";    cin>>bcs2[i].b_study;
                        cout<<"Enter D com mark: ";      cin>>bcs2[i].d_com;
                        cout<<"Enter History mark: ";    cin>>bcs2[i].history;
                        cout<<"Enter B com mark: ";      cin>>bcs2[i].b_com;
                        cout<<"Enter Oop mark: ";        cin>>bcs2[i].oop;
                        b=false;
                        Com1();
                        break;
                    }
                }
            }
            ///////////////////////////////
            else if (semester==3)
             {
                cout<<"Enter student ID: "; cin>>ID;
                for (int i=1 ; i<100 ; i++)
                {
                    if (ID==bcs[i].id)
                    {
                        cout<<"Enter S1 mark: ";    cin>>bcs3[i].S1;
                        cout<<"Enter S2 mark: ";    cin>>bcs3[i].S2;
                        cout<<"Enter S3 mark: ";    cin>>bcs3[i].S3;
                        cout<<"Enter S4 mark: ";    cin>>bcs3[i].S4;
                        cout<<"Enter S5 mark: ";    cin>>bcs3[i].S5;
                        cout<<"Enter S6 mark: ";    cin>>bcs3[i].S6;
                        b=false;
                        Com1();
                        break;
                    }
                }
            }
            ///////////////////////////////
            else if (semester==4)
             {
                cout<<"Enter student ID: "; cin>>ID;
                for (int i=1 ; i<100 ; i++)
                {
                    if (ID==bcs[i].id)
                    {
                        cout<<"Enter S1 mark: ";    cin>>bcs4[i].S1;
                        cout<<"Enter S2 mark: ";    cin>>bcs4[i].S2;
                        cout<<"Enter S3 mark: ";    cin>>bcs4[i].S3;
                        cout<<"Enter S4 mark: ";    cin>>bcs4[i].S4;
                        cout<<"Enter S5 mark: ";    cin>>bcs4[i].S5;
                        cout<<"Enter S6 mark: ";    cin>>bcs4[i].S6;
                        b=false;
                        Com1();
                        break;
                    }
                }
            }
            ///////////////////////////////
            else if (semester==5)
             {
                cout<<"Enter student ID: "; cin>>ID;
                for (int i=1 ; i<100 ; i++)
                {
                    if (ID==bcs[i].id)
                    {
                        cout<<"Enter S1 mark: ";    cin>>bcs5[i].S1;
                        cout<<"Enter S2 mark: ";    cin>>bcs5[i].S2;
                        cout<<"Enter S3 mark: ";    cin>>bcs5[i].S3;
                        cout<<"Enter S4 mark: ";    cin>>bcs5[i].S4;
                        cout<<"Enter S5 mark: ";    cin>>bcs5[i].S5;
                        cout<<"Enter S6 mark: ";    cin>>bcs5[i].S6;
                        b=false;
                        Com1();
                        break;
                    }
                }
            }
            //////////////////////////////
            else if (semester==6)
             {
                cout<<"Enter student ID: "; cin>>ID;
                for (int i=1 ; i<100 ; i++)
                {
                    if (ID==bcs[i].id)
                    {
                        cout<<"Enter S1 mark: ";    cin>>bcs6[i].S1;
                        cout<<"Enter S2 mark: ";    cin>>bcs6[i].S2;
                        cout<<"Enter S3 mark: ";    cin>>bcs6[i].S3;
                        cout<<"Enter S4 mark: ";    cin>>bcs6[i].S4;
                        cout<<"Enter S5 mark: ";    cin>>bcs6[i].S5;
                        cout<<"Enter S6 mark: ";    cin>>bcs6[i].S6;
                        b=false;
                        Com1();
                        break;
                    }
                }
            }
            /////////////////////////////
            else if (semester==7)
             {
                cout<<"Enter student ID: "; cin>>ID;
                for (int i=1 ; i<100 ; i++)
                {
                    if (ID==bcs[i].id)
                    {
                        cout<<"Enter S1 mark: ";    cin>>bcs7[i].S1;
                        cout<<"Enter S2 mark: ";    cin>>bcs7[i].S2;
                        cout<<"Enter S3 mark: ";    cin>>bcs7[i].S3;
                        cout<<"Enter S4 mark: ";    cin>>bcs7[i].S4;
                        cout<<"Enter S5 mark: ";    cin>>bcs7[i].S5;
                        cout<<"Enter S6 mark: ";    cin>>bcs7[i].S6;
                        b=false;
                        Com1();
                        break;
                    }
                }
            }
            /////////////////////////////
            else if (semester==8)
             {
                cout<<"Enter student ID: "; cin>>ID;
                for (int i=1 ; i<100 ; i++)
                {
                    if (ID==bcs[i].id)
                    {
                        cout<<"Enter S1 mark: ";    cin>>bcs8[i].S1;
                        cout<<"Enter S2 mark: ";    cin>>bcs8[i].S2;
                        cout<<"Enter S3 mark: ";    cin>>bcs8[i].S3;
                        cout<<"Enter S4 mark: ";    cin>>bcs8[i].S4;
                        cout<<"Enter S5 mark: ";    cin>>bcs8[i].S5;
                        cout<<"Enter S6 mark: ";    cin>>bcs8[i].S6;
                        b=false;
                        Com1();
                        break;
                    }
                }
             }
        }
        ////////////////////////////////////////////////////////////////////////////
        else if (course=="bba")
        {
            cout<<"Select semester: ";  cin>>semester;
            if (semester==1)
            {
                cout<<"Enter student ID: "; cin>>ID;
                for (int i=1 ; i<100 ; i++)
                {
                    if (ID==bba[i].id)
                    {
                        cout<<"Enter S1 mark: ";    cin>>bba1[i].S1;
                        cout<<"Enter S2 marks ";    cin>>bba1[i].S2;
                        cout<<"Enter S3 mark: ";    cin>>bba1[i].S3;
                        cout<<"Enter S4 mark: ";    cin>>bba1[i].S4;
                        cout<<"Enter S5 mark: ";    cin>>bba1[i].S5;
                        cout<<"Enter S6 mark: ";    cin>>bba1[i].S6;
                        b=false;
                        Com1();
                        break;
                    }
                }
            }
            ///////////////////////////////
            else if (semester==2)
            {
                cout<<"Enter student ID: "; cin>>ID;
                for (int i=1 ; i<100 ; i++)
                {
                    if (ID==bba[i].id)
                    {
                        cout<<"Enter S1 mark: ";    cin>>bba2[i].S1;
                        cout<<"Enter S2 marks ";    cin>>bba2[i].S2;
                        cout<<"Enter S3 mark: ";    cin>>bba2[i].S3;
                        cout<<"Enter S4 mark: ";    cin>>bba2[i].S4;
                        cout<<"Enter S5 mark: ";    cin>>bba2[i].S5;
                        cout<<"Enter S6 mark: ";    cin>>bba2[i].S6;
                        b=false;
                        Com1();
                        break;
                    }
                }
            }
            ///////////////////////////////
            else if (semester==3)
            {
                cout<<"Enter student ID: "; cin>>ID;
                for (int i=1 ; i<100 ; i++)
                {
                    if (ID==bba[i].id)
                    {
                        cout<<"Enter S1 mark: ";    cin>>bba3[i].S1;
                        cout<<"Enter S2 marks ";    cin>>bba3[i].S2;
                        cout<<"Enter S3 mark: ";    cin>>bba3[i].S3;
                        cout<<"Enter S4 mark: ";    cin>>bba3[i].S4;
                        cout<<"Enter S5 mark: ";    cin>>bba3[i].S5;
                        cout<<"Enter S6 mark: ";    cin>>bba3[i].S6;
                        b=false;
                        Com1();
                        break;
                    }
                }
            }
            ///////////////////////////////
            else if (semester==4)
            {
                cout<<"Enter student ID: "; cin>>ID;
                for (int i=1 ; i<100 ; i++)
                {
                    if (ID==bba[i].id)
                    {
                        cout<<"Enter S1 mark: ";    cin>>bba4[i].S1;
                        cout<<"Enter S2 marks ";    cin>>bba4[i].S2;
                        cout<<"Enter S3 mark: ";    cin>>bba4[i].S3;
                        cout<<"Enter S4 mark: ";    cin>>bba4[i].S4;
                        cout<<"Enter S5 mark: ";    cin>>bba4[i].S5;
                        cout<<"Enter S6 mark: ";    cin>>bba4[i].S6;
                        b=false;
                        Com1();
                        break;
                    }
                }
            }
            ///////////////////////////////
            else if (semester==5)
            {
                cout<<"Enter student ID: "; cin>>ID;
                for (int i=1 ; i<100 ; i++)
                {
                    if (ID==bba[i].id)
                    {
                        cout<<"Enter S1 mark: ";    cin>>bba5[i].S1;
                        cout<<"Enter S2 marks ";    cin>>bba5[i].S2;
                        cout<<"Enter S3 mark: ";    cin>>bba5[i].S3;
                        cout<<"Enter S4 mark: ";    cin>>bba5[i].S4;
                        cout<<"Enter S5 mark: ";    cin>>bba5[i].S5;
                        cout<<"Enter S6 mark: ";    cin>>bba5[i].S6;
                        b=false;
                        Com1();
                        break;
                    }
                }
            }
            //////////////////////////////
            else if (semester==6)
            {
                cout<<"Enter student ID: "; cin>>ID;
                for (int i=1 ; i<100 ; i++)
                {
                    if (ID==bba[i].id)
                    {
                        cout<<"Enter S1 mark: ";    cin>>bba6[i].S1;
                        cout<<"Enter S2 marks ";    cin>>bba6[i].S2;
                        cout<<"Enter S3 mark: ";    cin>>bba6[i].S3;
                        cout<<"Enter S4 mark: ";    cin>>bba6[i].S4;
                        cout<<"Enter S5 mark: ";    cin>>bba6[i].S5;
                        cout<<"Enter S6 mark: ";    cin>>bba6[i].S6;
                        b=false;
                        Com1();
                        break;
                    }
                }
            }
            //////////////////////////////
            else if (semester==7)
            {
                cout<<"Enter student ID: "; cin>>ID;
                for (int i=1 ; i<100 ; i++)
                {
                    if (ID==bba[i].id)
                    {
                        cout<<"Enter S1 mark: ";    cin>>bba7[i].S1;
                        cout<<"Enter S2 marks ";    cin>>bba7[i].S2;
                        cout<<"Enter S3 mark: ";    cin>>bba7[i].S3;
                        cout<<"Enter S4 mark: ";    cin>>bba7[i].S4;
                        cout<<"Enter S5 mark: ";    cin>>bba7[i].S5;
                        cout<<"Enter S6 mark: ";    cin>>bba7[i].S6;
                        b=false;
                        Com1();
                        break;
                    }
                }
            }
            //////////////////////////////
            else if (semester==8)
            {
                cout<<"Enter student ID: "; cin>>ID;
                for (int i=1 ; i<100 ; i++)
                {
                    if (ID==bba[i].id)
                    {
                        cout<<"Enter S1 mark: ";    cin>>bba8[i].S1;
                        cout<<"Enter S2 marks ";    cin>>bba8[i].S2;
                        cout<<"Enter S3 mark: ";    cin>>bba8[i].S3;
                        cout<<"Enter S4 mark: ";    cin>>bba8[i].S4;
                        cout<<"Enter S5 mark: ";    cin>>bba8[i].S5;
                        cout<<"Enter S6 mark: ";    cin>>bba8[i].S6;
                        b=false;
                        Com1();
                        break;
                    }
                }
            }
        }
        //////////////////////////////////////////////////////////////////////////////////
        else if (course=="law")
        {
            cout<<"Select semester: ";  cin>>semester;
            if (semester==1)
            {
                cout<<"Enter student ID: "; cin>>ID;
                for (int i=1 ; i<100 ; i++)
                {
                    if (ID==law[i].id)
                    {
                        cout<<"Enter S1 mark: ";    cin>>law1[i].S1;
                        cout<<"Enter S2 marks ";    cin>>law1[i].S2;
                        cout<<"Enter S3 mark: ";    cin>>law1[i].S3;
                        cout<<"Enter S4 mark: ";    cin>>law1[i].S4;
                        cout<<"Enter S5 mark: ";    cin>>law1[i].S5;
                        cout<<"Enter S6 mark: ";    cin>>law1[i].S6;
                        b=false;
                        Com1();
                        break;
                    }
                }
            }
            /////////////////////////////
            else if (semester==2)
            {
                cout<<"Enter student ID: "; cin>>ID;
                for (int i=1 ; i<100 ; i++)
                {
                    if (ID==law[i].id)
                    {
                        cout<<"Enter S1 mark: ";    cin>>law2[i].S1;
                        cout<<"Enter S2 marks ";    cin>>law2[i].S2;
                        cout<<"Enter S3 mark: ";    cin>>law2[i].S3;
                        cout<<"Enter S4 mark: ";    cin>>law2[i].S4;
                        cout<<"Enter S5 mark: ";    cin>>law2[i].S5;
                        cout<<"Enter S6 mark: ";    cin>>law2[i].S6;
                        b=false;
                        Com1();
                        break;
                    }
                }
            }
            ////////////////////////////
            else if (semester==3)
            {
                cout<<"Enter student ID: "; cin>>ID;
                for (int i=1 ; i<100 ; i++)
                {
                    if (ID==law[i].id)
                    {
                        cout<<"Enter S1 mark: ";    cin>>law3[i].S1;
                        cout<<"Enter S2 marks ";    cin>>law3[i].S2;
                        cout<<"Enter S3 mark: ";    cin>>law3[i].S3;
                        cout<<"Enter S4 mark: ";    cin>>law3[i].S4;
                        cout<<"Enter S5 mark: ";    cin>>law3[i].S5;
                        cout<<"Enter S6 mark: ";    cin>>law3[i].S6;
                        b=false;
                        Com1();
                        break;
                    }
                }
            }
            ////////////////////////////
            else if (semester==4)
            {
                cout<<"Enter student ID: "; cin>>ID;
                for (int i=1 ; i<100 ; i++)
                {
                    if (ID==law[i].id)
                    {
                        cout<<"Enter S1 mark: ";    cin>>law4[i].S1;
                        cout<<"Enter S2 marks ";    cin>>law4[i].S2;
                        cout<<"Enter S3 mark: ";    cin>>law4[i].S3;
                        cout<<"Enter S4 mark: ";    cin>>law4[i].S4;
                        cout<<"Enter S5 mark: ";    cin>>law4[i].S5;
                        cout<<"Enter S6 mark: ";    cin>>law4[i].S6;
                        b=false;
                        Com1();
                        break;
                    }
                }
            }
            ////////////////////////////
            else if (semester==5)
            {
                cout<<"Enter student ID: "; cin>>ID;
                for (int i=1 ; i<100 ; i++)
                {
                    if (ID==law[i].id)
                    {
                        cout<<"Enter S1 mark: ";    cin>>law5[i].S1;
                        cout<<"Enter S2 marks ";    cin>>law5[i].S2;
                        cout<<"Enter S3 mark: ";    cin>>law5[i].S3;
                        cout<<"Enter S4 mark: ";    cin>>law5[i].S4;
                        cout<<"Enter S5 mark: ";    cin>>law5[i].S5;
                        cout<<"Enter S6 mark: ";    cin>>law5[i].S6;
                        b=false;
                        Com1();
                        break;
                    }
                }
            }
            ////////////////////////////
            else if (semester==6)
            {
                cout<<"Enter student ID: "; cin>>ID;
                for (int i=1 ; i<100 ; i++)
                {
                    if (ID==law[i].id)
                    {
                        cout<<"Enter S1 mark: ";    cin>>law6[i].S1;
                        cout<<"Enter S2 marks ";    cin>>law6[i].S2;
                        cout<<"Enter S3 mark: ";    cin>>law6[i].S3;
                        cout<<"Enter S4 mark: ";    cin>>law6[i].S4;
                        cout<<"Enter S5 mark: ";    cin>>law6[i].S5;
                        cout<<"Enter S6 mark: ";    cin>>law6[i].S6;
                        b=false;
                        Com1();
                        break;
                    }
                }
            }
            ////////////////////////////
            else if (semester==7)
            {
                cout<<"Enter student ID: "; cin>>ID;
                for (int i=1 ; i<100 ; i++)
                {
                    if (ID==law[i].id)
                    {
                        cout<<"Enter S1 mark: ";    cin>>law7[i].S1;
                        cout<<"Enter S2 marks ";    cin>>law7[i].S2;
                        cout<<"Enter S3 mark: ";    cin>>law7[i].S3;
                        cout<<"Enter S4 mark: ";    cin>>law7[i].S4;
                        cout<<"Enter S5 mark: ";    cin>>law7[i].S5;
                        cout<<"Enter S6 mark: ";    cin>>law7[i].S6;
                        b=false;
                        Com1();
                        break;
                    }
                }
            }
            ////////////////////////////
            else if (semester==8)
            {
                cout<<"Enter student ID: "; cin>>ID;
                for (int i=1 ; i<100 ; i++)
                {
                    if (ID==law[i].id)
                    {
                        cout<<"Enter S1 mark: ";    cin>>law8[i].S1;
                        cout<<"Enter S2 marks ";    cin>>law8[i].S2;
                        cout<<"Enter S3 mark: ";    cin>>law8[i].S3;
                        cout<<"Enter S4 mark: ";    cin>>law8[i].S4;
                        cout<<"Enter S5 mark: ";    cin>>law8[i].S5;
                        cout<<"Enter S6 mark: ";    cin>>law8[i].S6;
                        b=false;
                        Com1();
                        break;
                    }
                }
            }
        }
        ////////////////////////////////////////////////////////////////////////////
        else if (course=="jor")
        {
            cout<<"Select semester: ";  cin>>semester;
            if (semester==1)
            {
                cout<<"Enter student ID: "; cin>>ID;
                for (int i=1 ; i<100 ; i++)
                {
                    if (ID==jor[i].id)
                    {
                        cout<<"Enter S1 mark: ";    cin>>jor1[i].S1;
                        cout<<"Enter S2 marks ";    cin>>jor1[i].S2;
                        cout<<"Enter S3 mark: ";    cin>>jor1[i].S3;
                        cout<<"Enter S4 mark: ";    cin>>jor1[i].S4;
                        cout<<"Enter S5 mark: ";    cin>>jor1[i].S5;
                        cout<<"Enter S6 mark: ";    cin>>jor1[i].S6;
                        b=false;
                        Com1();
                        break;
                    }
                }
            }
            //////////////////////////////
            else if (semester==2)
            {
                cout<<"Enter student ID: "; cin>>ID;
                for (int i=1 ; i<100 ; i++)
                {
                    if (ID==jor[i].id)
                    {
                        cout<<"Enter S1 mark: ";    cin>>jor2[i].S1;
                        cout<<"Enter S2 marks ";    cin>>jor2[i].S2;
                        cout<<"Enter S3 mark: ";    cin>>jor2[i].S3;
                        cout<<"Enter S4 mark: ";    cin>>jor2[i].S4;
                        cout<<"Enter S5 mark: ";    cin>>jor2[i].S5;
                        cout<<"Enter S6 mark: ";    cin>>jor2[i].S6;
                        b=false;
                        Com1();
                        break;
                    }
                }
            }

            //////////////////////////////
            else if (semester==3)
            {
                cout<<"Enter student ID: "; cin>>ID;
                for (int i=1 ; i<100 ; i++)
                {
                    if (ID==jor[i].id)
                    {
                        cout<<"Enter S1 mark: ";    cin>>jor3[i].S1;
                        cout<<"Enter S2 marks ";    cin>>jor3[i].S2;
                        cout<<"Enter S3 mark: ";    cin>>jor3[i].S3;
                        cout<<"Enter S4 mark: ";    cin>>jor3[i].S4;
                        cout<<"Enter S5 mark: ";    cin>>jor3[i].S5;
                        cout<<"Enter S6 mark: ";    cin>>jor3[i].S6;
                        b=false;
                        Com1();
                        break;
                    }
                }
            }
            //////////////////////////////
            else if (semester==4)
            {
                cout<<"Enter student ID: "; cin>>ID;
                for (int i=1 ; i<100 ; i++)
                {
                    if (ID==jor[i].id)
                    {
                        cout<<"Enter S1 mark: ";    cin>>jor4[i].S1;
                        cout<<"Enter S2 marks ";    cin>>jor4[i].S2;
                        cout<<"Enter S3 mark: ";    cin>>jor4[i].S3;
                        cout<<"Enter S4 mark: ";    cin>>jor4[i].S4;
                        cout<<"Enter S5 mark: ";    cin>>jor4[i].S5;
                        cout<<"Enter S6 mark: ";    cin>>jor4[i].S6;
                        b=false;
                        Com1();
                        break;
                    }
                }
            }
            //////////////////////////////
            else if (semester==5)
            {
                cout<<"Enter student ID: "; cin>>ID;
                for (int i=1 ; i<100 ; i++)
                {
                    if (ID==jor[i].id)
                    {
                        cout<<"Enter S1 mark: ";    cin>>jor5[i].S1;
                        cout<<"Enter S2 marks ";    cin>>jor5[i].S2;
                        cout<<"Enter S3 mark: ";    cin>>jor5[i].S3;
                        cout<<"Enter S4 mark: ";    cin>>jor5[i].S4;
                        cout<<"Enter S5 mark: ";    cin>>jor5[i].S5;
                        cout<<"Enter S6 mark: ";    cin>>jor5[i].S6;
                        b=false;
                        Com1();
                        break;
                    }
                }
            }
            //////////////////////////////
            else if (semester==6)
            {
                cout<<"Enter student ID: "; cin>>ID;
                for (int i=1 ; i<100 ; i++)
                {
                    if (ID==jor[i].id)
                    {
                        cout<<"Enter S1 mark: ";    cin>>jor6[i].S1;
                        cout<<"Enter S2 marks ";    cin>>jor6[i].S2;
                        cout<<"Enter S3 mark: ";    cin>>jor6[i].S3;
                        cout<<"Enter S4 mark: ";    cin>>jor6[i].S4;
                        cout<<"Enter S5 mark: ";    cin>>jor6[i].S5;
                        cout<<"Enter S6 mark: ";    cin>>jor6[i].S6;
                        b=false;
                        Com1();
                        break;
                    }
                }
            }
            //////////////////////////////
            else if (semester==7)
            {
                cout<<"Enter student ID: "; cin>>ID;
                for (int i=1 ; i<100 ; i++)
                {
                    if (ID==jor[i].id)
                    {
                        cout<<"Enter S1 mark: ";    cin>>jor7[i].S1;
                        cout<<"Enter S2 marks ";    cin>>jor7[i].S2;
                        cout<<"Enter S3 mark: ";    cin>>jor7[i].S3;
                        cout<<"Enter S4 mark: ";    cin>>jor7[i].S4;
                        cout<<"Enter S5 mark: ";    cin>>jor7[i].S5;
                        cout<<"Enter S6 mark: ";    cin>>jor7[i].S6;
                        b=false;
                        Com1();
                        break;
                    }
                }
            }
            //////////////////////////////
            else if (semester==8)
            {
                cout<<"Enter student ID: "; cin>>ID;
                for (int i=1 ; i<100 ; i++)
                {
                    if (ID==jor[i].id)
                    {
                        cout<<"Enter S1 mark: ";    cin>>jor8[i].S1;
                        cout<<"Enter S2 marks ";    cin>>jor8[i].S2;
                        cout<<"Enter S3 mark: ";    cin>>jor8[i].S3;
                        cout<<"Enter S4 mark: ";    cin>>jor8[i].S4;
                        cout<<"Enter S5 mark: ";    cin>>jor8[i].S5;
                        cout<<"Enter S6 mark: ";    cin>>jor8[i].S6;
                        b=false;
                        Com1();
                        break;
                    }
                }
            }
        }
        ///////////////////////////////////////////////////////////////////////////////////
        if (semester!=1||semester!=2||semester!=3||semester!=4
            ||semester!=5||semester!=6||semester!=7||semester!=8)
        {
            for (int i=0 ; i<100 ; i++)
            {
                if (ID!=bcs[i].id && ID!=bba[i].id && ID!=law[i].id && ID!=jor[i].id)
                {
                    cout<<"\t\t\t\t\tSorry"<<endl;
                    Com1();
                }
            }
        }
        cout<<"\t\t\t\t\tDo you want to add more press 1 . else press 2: ";
        int nn;
        switch (nn)
        {
            case 1: MARKS();
                break;
            case 2: Com1();
                break;
        }
    }
}
///////////////////// Attendance
void ATTENDANCE ()
{
    string ID;
    bool b=true;
    cout<<"Enter student ID: "; cin>>ID;

    while (b)
    {
        for (int i=0 ; i<50 ; i++)
        {
            if (ID==bcs[i].id)
            {
                cout<<"Enter Present days: ";   cin>>bcs[i].present;
                cout<<"Enter Absent days: ";    cin>>bcs[i].absent;
                b=false;
                Com1();
                break;
            }
        }
        for (int i=0 ; i<50 ; i++)
        {
            if (ID==bba[i].id)
            {
                cout<<"Enter Present days: ";   cin>>bba[i].present;
                cout<<"Enter Absent days: ";    cin>>bba[i].absent;
                b=false;
                Com1();
                break;
            }
        }
        for (int i=0 ; i<50 ; i++)
        {
            if (ID==law[i].id)
            {
                cout<<"Enter Present days: ";   cin>>law[i].present;
                cout<<"Enter Absent days: ";    cin>>law[i].absent;
                b=false;
                Com1();
                break;
            }
        }
        for (int i=0 ; i<50 ; i++)
        {
            if (ID==jor[i].id)
            {
                cout<<"Enter Present days: ";   cin>>jor[i].present;
                cout<<"Enter Absent days: ";    cin>>jor[i].absent;
                b=false;
                Com1();
                break;
            }
        }
        for (int i=0 ; i<50 ; i++)
        {
            if (ID!=bcs[i].id && ID!=bba[i].id && ID!=law[i].id && ID!=jor[i].id)
            {
                cout<<"\t\t\t\t\tSorry"<<endl;
                Com1();
            }
        }
    }
        cout<<"\t\t\t\t\tDo you want to add more press 1 . else press 2: ";
        int nn;
        switch (nn)
        {
            case 1: ATTENDANCE();
                break;
            case 2: Com1();
                break;
        }
}




///////////////////// Compare function
void Com1()
{
    a2++;
    a3++;
    a4++;
    a5++;


    string pass;
    char a;
    cout<<"************************************************************************************************************************"<<endl;
    cout<<"\n\n\t\t\t\t\tWelcome to Rana university!\n\t\t\t\t\tpress 1 for Admission\n\t\t\t\t\tpress 2 for students\n\t\t\t\t\tpress 3 for management"<<endl;
    cout<<"\t\t\t\t\t";
    cin>>a;

    if (a>='A' && a<='z')
    {
        cout<<"\t\t\t\t\tPlease enter a number"<<endl;
        Com1();
    }
        else if (a>='0'  && a<='9')
        {
            if (a=='1')
            {
                cout<<"\t\t\t\t\tPlease enter the password for enter: ";
                cin>>pass;

                if (pass=="RU123AD")
                {
                    ADMISSION();
                }

                    else
                    {
                        cout<<"\t\t\t\t\tWrong password please try again"<<endl;
                        Com1();
                    }
            }
                else if (a=='2')
                {
                    string get1;
                    cout<<"\t\t\t\t\tPlease enter your Department: 1-Bcs . 2-Bba . 3-Law . 4-Jor :";
                    cin>>get1;

                    if (get1=="Bcs"||get1=="BCS"||get1=="bcs")
                    {
                        BCS();
                    }
                        else if (get1=="Bba"||get1=="BBA"||get1=="bba")
                        {
                            BBA();
                        }
                            else if (get1=="Law"||get1=="LAW"||get1=="law")
                            {
                                LAW();
                            }
                                else if (get1=="Jor"||get1=="JOR"||get1=="jor")
                                {
                                    JOR();
                                }
                                    else
                                    {
                                        cout<<"\t\t\t\t\tInvalid Please try again"<<endl;
                                        Com1();
                                    }
                }
                else if (a=='3')
                {
                    MAN();
                }
        }


}
int main()
{
    /////////////// Calling the start function:
    Com1();


    return 0;
}
