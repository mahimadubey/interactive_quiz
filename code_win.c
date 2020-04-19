#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<string.h>
#include <windows.h> 
int q,r_in,i,size1=10,size2=10,size3=10,ans,count=0,score=0,max=0;
double total_time = 0.0, t;
char max_name[50]="--------";
clock_t begin,end;
char questions[3][10][500]= {{"\nQ.The 2006 World Cup Football Tournament held in: ",
        "\nQ.Satellite launching station is located at: ",
        "\nQ.The 'Black flag' signifies: ",
        "\nQ.Study of earthquakes is known as: ",
        "\nQ.Super conductivity is a phenomenon in which the resistance of a substance: ",
        "\nQ.Rabindranath Tagore receive Nobel Prize in 1913 in the field of: ",
        "\nQ.The air we inhale is mixture of gases. Which of the following gases in the mixture is highest in percentage?: ",
        "\nQ.Penicillin is widely used as: ",
        "\nQ.Rana Pratap Sagar (Rajasthan) is famous for: ",
        "\nQ. Pythagoras was first to ____ the universal validity of geometrical theorem. "
    },
    {
        "\nQ.School of Aviation Medicine (Air Force) is located at: ",
        "\nQ.Soil acidity is generally corrected by: ",
        "\nQ.When is the World's Diabetes Day?: ",
        "\nQ.When is the International Workers' Day?: ",
        "\nQ.When and where was basketball introduced in Olympics as a medal event?: ",
        "\nQ.India's first atomic power station was set up at: ",
        "\nQ.In which year of First World War Germany declared war on Russia and France?: ",
        "\nQ.ICAO stands for: ",
        "\nQ.India's first Technicolor film ____ in the early 1950s was produced by ____: ",
        "\nQ.India has largest deposits of ____ in the world.: "
    },
    {
        "\nQ.The Olympic Flame, was, for the first time, ceremonially lighted and burnt in a giant torch at the entrance of the stadium at: ",
        "\nQ.The range of missile Agni is approximately: ",
        "\nQ.The Sports Authority of India is was registered as a society in: ",
        "\nQ.The national flag was adopted by the Constituent Assembly of India on: ",
        "\nQ.The National Convention framed the new Republican constitution of France in 1795, according to which: ",
        "\nQ.The number of chromosomes in human body is: ",
        "\nQ.The Pilotless target aircraft, fabricated at the Aeronautical Development Establishment, Bangalore, is: ",
        "\nQ.The only Indian woman who become President of the World Health Organisation so far is/was: ",
        "\nQ.Which company manufacturers low and high power communication equipment like radius for the use of defence services and paramilitary organisations?: ",
        "\nQ.Where is the permanent secretariat of the SAARC: "
    }
};
char options[3][10][500]= {{"\n\t1.France\n\t2.China\n\t3.Germany\n\t4.Brazil",
        "\n\t1.Sriharikotta(Andhra Pradesh)\n\t2.Solapur(Maharashtra)\n\t3.Salem(Tamilnadu)\n\t4.Warangal(Andhra Pradesh)",
        "\n\t1.revolution/danger\n\t2.peace\n\t3.protest\n\t4.truce",
        "\n\t1.ecology\n\t2.seismology\n\t3.numismatics\n\t4.None of these",
        "\n\t1.increases with temperature\n\t2.decreases with temperature\n\t3.does not change with temperature\n\t4.becomes zero at very low temperature",
        "\n\t1.physics\n\t2.peace\n\t3.literature\n\t4.economy",
        "\n\t1.Carbon Dioxide\n\t2.Nitrogen \n\t3.Oxygen\n\t4.Carbon Monoxide",
        "\n\t1.an antiseptic\n\t2.a disinfectant\n\t3.an antibiotic\n\t4.an insectiside",
        "\n\t1.hydropower generation\n\t2.aluminum industry\n\t3.brassware\n\t4.sports goods",
        "\n\t1.give\n\t2.prove\n\t3.both\n\t4.none"
    },
    {
        "\n\t1.Allahabad\n\t2.Hyderabad\n\t3.Bengaluru\n\t4.Jalahalli",
        "\n\t1.proper irrigation\n\t2.adding sodium hydroxide\n\t3.liming\n\t4.application of fertilizers",
        "\n\t1.14th November\n\t2.11th December\n\t3.15th October\n\t4.1st July",
        "\n\t1.15th April\n\t2.12th December\n\t3.1st May\n\t4.1st August",
        "\n\t1.1992 at Barcelona\n\t2.1928 at Paris\n\t3.1936 at Berlin\n\t4.1900 at Athens",
        "\n\t1.Surat (Gujarat)\n\t2.Tarapur (Maharashtra)\n\t3.Trombay (Maharashtra)\n\t4.Solapur (Maharashtra)",
        "\n\t1.1914\n\t2.1915\n\t3.1916\n\t4.1917",
        "\n\t1.International Civil Aviation Organization\n\t2.Indian Corporation of Agriculture Organization\n\t3.Institute of Company of Accounts Organization\n\t4.None of the above",
        "\n\t1.'Jhansi Ki Rani', Sir Syed Ahmed\n\t2.'Jhansi Ki Rani', Sohrab Modi\n\t3.'Mirza Ghalib', Sohrab Modi\n\t4.'Mirza Ghalib', Munshi Premchand",
        "\n\t1.gold\n\t2.copper\n\t3.silver\n\t4.mica"
    },
    {
        "\n\t1.Athens Games (1896)\n\t2.London Games (1908)\n\t3.Paris Games (1924)\n\t4.Amsterdam Games (1928)",
        "\n\t1.150 km\n\t2.1200-2000 km\n\t3.500 m to 9 km\n\t4.4 km",
        "\n\t1.1982\n\t2.1983\n\t3.1984\n\t4.1985",
        "\n\t1.August 15, 1947\n\t2.July 22, 1947\n\t3.January 26, 1950\n\t4.January 2, 1950",
        "\n\t1.the executive authority of the state was vested in a committee of five directors, called the Directory\n\t2.a bicameral legislature was established\n\t3.both (a) and (b)\n\t4.None of the above",
        "\n\t1.44\n\t2.43\n\t3.48\n\t4.46",
        "\n\t1.Lakshya\n\t2.Cheetah\n\t3.Nishanth\n\t4.Arjun",
        "\n\t1.Smt. Kamala Devi Chattopadhyaya\n\t2.Raj Kumari Amrit Kaur\n\t3.Smt. Vijayalakshmi Pandit\n\t4.Dr. Sushila Nayar",
        "\n\t1.Bharat Electronics Limited (BEL)\n\t2.God Shipyard Limited (GSL)\n\t3.Bharat Dynamic Limited (BDL)\n\t4.None of the above",
        "\n\t1.New Delhi\n\t2.Islamabad\n\t3.Colombo\n\t4.Kathmandu"
    }
};
int answers[3][10]= {{3,1,3,2,4,3,2,3,1,2},{3,3,1,3,3,2,1,1,2,4},{4,2,3,2,3,4,1,2,1,4}};

int start_menu();
void help();
void start();
void highest_score();
void reset();
int quiz();
void mark();
void SetColor(int ForgC);
void correct()
{
    PlaySound(TEXT("KBCClaps.wav"), NULL,SND_ASYNC);
    SetColor(34);
    printf("\n");
    printf("\n                       ___  ___  ___  ___   ___  ___ _____                          ");
    printf("\n                      |    |   ||   ||   | |    |      |            /                ");
    printf("\n                      |    |   ||___||___| |--- |      |           /                 ");
    printf("\n                      |___ |___|| |__| |__ |___ |___   |         \\/                   ");
    printf("\n");
    SetColor(7);
    Sleep(3000);
    PlaySound(TEXT("bgm.wav"), SND_ALIAS,SND_ASYNC);
}
void wrong()
{
    PlaySound(TEXT("KBCwrong.wav"), NULL,SND_ASYNC);
    SetColor(4);
    printf("\n");
    printf("\n                                  ___  ___  _    ___       \\  /               ");
    printf("\n                            |   ||   ||   || | ||           \\/                  ");
    printf("\n                            | | ||___||   || | || --.       /\\                    ");
    printf("\n                            |_|_|| |__|___|| |_||___|      /  \\                 ");
    printf("\n");
    SetColor(7);
    Sleep(3000);
    PlaySound(TEXT("bgm.wav"), SND_ALIAS,SND_ASYNC);
}
int main()
{
    system("cls");
    PlaySound(TEXT("KBCbg.wav"), SND_ALIAS,SND_ASYNC);
    SetColor(3);
    printf("\n\n");
    printf("\t\t\tC PROGRAM QUIZ GAME\n");
    SetColor(6);
    printf("\n\t\t________________________________________\n");
    SetColor(4);

    printf("\n\t\t\t        WELCOME ");
    printf("\n\t\t\t           TO ");
    printf("\n\t\t\t        THE GAME ");
    SetColor(6);
    printf("\n\t\t________________________________________");
    SetColor(7);
    Sleep(3000);
    start_menu();
}
void SetColor(int ForgC)
{
    WORD wColor;
    //This handle is needed to get the current background attribute

    HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_SCREEN_BUFFER_INFO csbi;
    //csbi is used for wAttributes word

    if(GetConsoleScreenBufferInfo(hStdOut, &csbi))
    {
        //To mask out all but the background attribute, and to add the color
        wColor = (csbi.wAttributes & 0xF0) + (ForgC & 0x0F);
        SetConsoleTextAttribute(hStdOut, wColor);
    }
    return;
}
int start_menu()
{

    int choice;
    SetColor(6);
    printf("\n\t\t________________________________________\n");
    SetColor(3);
    printf("\n\t\t > Press 1 : ");
    SetColor(13);
    printf("START");
    SetColor(3);
    printf("\n\t\t > Press 2 : ");
    SetColor(13);
    printf("HIGHEST SCORE");
    SetColor(3);
    printf("\n\t\t > Press 3 : ");
    SetColor(13);
    printf("RESET SCORE");
    SetColor(3);
    printf("\n\t\t > Press 4 : ");
    SetColor(13);
    printf("HELP");
    SetColor(3);
    printf("\n\t\t > Press 5 : ");
    SetColor(13);
    printf("EXIT");
    SetColor(6);
    printf("\n\t\t________________________________________\n\n");
    SetColor(7);
    printf("\n\t\t CHOICE:");
    scanf("%d",&choice);
    switch(choice)
    {
    case 1:
        start();
        break;
    case 2:
        highest_score();
        break;
    case 3:
        reset();
        break;
    case 4:
        help();
        break;
    case 5:
        SetColor(13);
        printf("\t\t\tTHANKS FOR PLAYING");
        PlaySound(TEXT("KBC_EXIT.wav"),NULL,NULL);
        SetColor(6);
        return 0;
        break;
    default:
        printf("\n\t\tTry something else!!!");
        start_menu();
    }
}
void help()
{
    system("cls");
    SetColor(6);
    printf("\n\t_______________________________________________________");
    SetColor(4);
    printf("\n\t\t\t        HELP ");
    SetColor(6);
    printf("\n\t_______________________________________________________\n");
    SetColor(11);
    printf("\n > You will be given with 10 different questions (one at a time)");
    printf("\n > Your response time will be calculated.");
    printf("\n > Criteria for the next question:");
    printf("\n - If you take more than 1 minute to answer , an easier question will be asked.");
    printf("\n - If you take less than 1 minute to answer, a moderate question will be asked.");
    printf("\n - If you take less than 30 seconds to answer, a difficult question will be asked.");
    printf("\n > Based on your performance, you will be given a certain rating.");
    SetColor(4);
    printf("\n\n\n GOOD LUCK!!!");
    SetColor(7);
    start_menu();
}
void start()
{
    system("cls");
    SetColor(6);
    printf("\n\t_________________________________________________________\n");
    SetColor(4);
    printf("\n\t\t\t        START ");
    SetColor(6);
    printf("\n\t_________________________________________________________\n");
    SetColor(7);
    char name[50];
    printf("\n\t\t Enter Name: ");
    getchar();
    gets(name);
    for(int i=2; i<10; i++)
    {
        system("cls");
        SetColor(i);
        printf("\n");
        printf("\n");
        printf("                 WELCOME!!! %s\n",name);
        Sleep(400);
        SetColor(7);

    }
    printf("\n\n\n\n");
    printf("                   PRESS ENTER TO START THE QUIZ\n");
    getchar();




    quiz();
    Sleep(3000);
    PlaySound(TEXT("KBCFinalScore.wav"),NULL,SND_ASYNC);
    system("cls");
    SetColor(6);
    printf("\n\t_________________________________________________________");
    SetColor(4);
    printf("\n\t\t\t        YOUR SCORE ");
    SetColor(6);
    printf("\n\t_________________________________________________________\n");
    SetColor(7);
    printf("\n\t\tSCORE: \t\t\t%d ",score);
    printf("\n\t\tNAME: \t\t\t%s",name);
    printf("\n");
    printf("\n\t\tTIME TAKEN: \t\t%lf s\n",total_time);
    if(total_time<300)
    {
        SetColor(3);
        printf("\t\tEXCELLENT!!!\n");
        SetColor(7);
        printf("\n");
        printf("\t\tYOU TOOK LESS THAN 5 MINUTES TO FINISH THE GAME!!!\n");
    }
    if(total_time>300 && total_time<600)
    {
        SetColor(3);
        printf("\t\tGOOD!!!\n");
        SetColor(7);
        printf("\t\tYOU TOOK LESS THAN 10 MINUTES TO FINISH THE GAME!!!\n");
    }
    if(total_time>900)
    {
        SetColor(3);
        printf("\t\tSCOPE FOR IMPROVEMENT!\n");
        SetColor(7);
        printf("\t\tYOU TOOK MORE THAN 15 MINUTES TO FINISH THE GAME!!!\n");
    }
    printf("\n");
    if(score>max)
    {
        SetColor(4);
        printf("\t\tCONGRATULATIONS!!!\n");
        printf("\t\tYOU ARE THE NEW HIGH SCORER\n");
        SetColor(7);
        max=score;
        strcpy(max_name,name);
    }
    printf("\n");
    Sleep(4000);
    start_menu();


}
void highest_score()
{
    system("cls");
    SetColor(6);
    printf("\n\t_________________________________________________________");
    SetColor(4);
    printf("\n\t\t\t        HIGHEST SCORE ");
    SetColor(6);
    printf("\n\t_________________________________________________________\n");
    SetColor(7);
    printf("\n\t\tSCORE: \t\t\t%d ",max);
    SetColor(6);
    printf("\n\t_________________________________________________________\n");
    SetColor(7);
    printf("\n\t\tNAME: \t\t\t%s ",max_name);

    start_menu();
}
void reset()
{
    system("cls");
    max=0;
    strcpy(max_name,"---------");
    printf("\n\t\tScore is reseted successfully\n");

    start_menu();
}

int quiz()
{
    system("cls");
    int a1[]= {7,1,3,8,2,0,4,6,9,5};
    int a2[]= {8,5,6,7,2,1,0,9,3,4};
    int a3[]= {8,5,6,7,2,1,0,9,3,4};
    size1=10,size2=10,size3=10,ans,count=0,score=0,total_time=0;
    int level=0,num;
    srand(time(0));
    r_in=rand()%size1;
    q=a1[r_in];
    for (i=r_in; i<size1; i++)
        a1[i] = a1[i+1];
    size1 --;
    num=q;
    while(1)
    {
        double time_spent=0.0;
        printf("%s",questions[level][num]);
        printf("%s",options[level][num]);
        begin=clock();
        while(1)
        {
		  printf("\n Your Answer (option): ");
		  scanf("%d",&ans);
		  if(ans>0&&ans<5)
		  	break;
		  else
		  	printf("\n\t\t PLEASE enter between '1-4'\n");	
	  }
        end=clock();
        if(ans==answers[level][num])
        {
            printf("\nCorrect Answer");
            score++;
            correct();
        }
        else
        {
            printf("\nCorrect Answer is option %d \n",answers[level][num]);
            wrong();
        }
        time_spent = time_spent + (((double)(end-begin))/CLOCKS_PER_SEC);
        t=time_spent*1;
        total_time+=t;
        count++;
        if (count==10)
            return 0;
        if (t<30)
        {
            srand(time(0));
            r_in=rand()%size3;
            q=a3[r_in];
            for (i=r_in; i<size3; i++)
                a3[i] = a3[i+1];
            size3 --;
            level=2;
            num=q;
        }
        else if ((t>30)&&(t<60))
        {
            srand(time(0));
            r_in=rand()%size2;
            q=a2[r_in];
            for (i=r_in; i<size2; i++)
                a2[i] = a2[i+1];
            size2 --;
            level=1;
            num=q;
        }
        else
        {
            srand(time(0));
            r_in=rand()%size1;
            q=a1[r_in];
            for (i=r_in; i<size1; i++)
                a1[i] = a1[i+1];
            size1 --;
            num=q;
            level=0;
        }
    }
}
