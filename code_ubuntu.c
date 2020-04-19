#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<string.h>
#include <unistd.h>
unsigned int sleep();
useconds_t s =4;
//set parameters
#define RED "\x1b[31m"
#define GREEN "\x1b[32m"
#define MAGENTA "\x1b[35m"
#define YELLOW "\x1b[33m"
#define BLUE "\x1b[34m"
#define CYAN "\x1b[36m"
#define BOLD "\e[1m"
#define UNDER "\e[4m"
#define BLINK "\e[5m"
//reset parameters
#define RESET_CLR "\x1b[0m"
#define RESET_BOLD "\e[21m"
#define RESET_UNDER "\e[24m"
#define RESET_BLINK "\e[25m"

int start_menu();
int interaction(char name[50]);
void start();
int quiz();
void correct();
void wrong();
void highest_score();
void reset();
void help();

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
int q,r_in,i,size1=10,size2=10,size3=10,ans,count=0,score=0,max=0;
double total_time = 0.0 , t=0;
clock_t begin,end;
char max_name[50]="--------";

int main()
{
    system("clear");
    
    printf(BLUE"\t\t\tC PROGRAM QUIZ GAME\n"RESET_CLR);
    printf(CYAN"\n\t\t________________________________________\n"RESET_CLR);
    printf(RED "\n\t\t\t        WELCOME "RESET_CLR );
    printf(RED"\n\t\t\t           to "RESET_CLR);
    printf(RED"\n\t\t\t        THE GAME "RESET_CLR);
    printf(CYAN"\n\t\t________________________________________"RESET_CLR);
    
    start_menu();
}

int start_menu()
{
    int choice;
    printf(CYAN"\n\t\t________________________________________\n"RESET_CLR);
    printf(BLUE"\n\t\t > Press 1 :"RESET_CLR MAGENTA" START"RESET_CLR);
    printf(BLUE"\n\t\t > Press 2 :"RESET_CLR MAGENTA" HIGHEST SCORE  "RESET_CLR);
    printf(BLUE"\n\t\t > Press 3 :"RESET_CLR MAGENTA" RESET SCORE"RESET_CLR);
    printf(BLUE"\n\t\t > press 4 :"RESET_CLR MAGENTA" HELP            "RESET_CLR);
    printf(BLUE"\n\t\t > press 5 :"RESET_CLR MAGENTA" QUIT             "RESET_CLR);
    printf(CYAN"\n\t\t________________________________________\n\n"RESET_CLR);
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
    			system("aplay -c 1 -t wav -q KBC_EXIT.wav &");
    			printf(RED"\n\t\t\tTHANKS FOR PLAYING WITH US"RESET_CLR CYAN"\n\t\t\t  HOPE TO SEE YOU AGAIN\n\n"RESET_CLR);
      		return 0;
      		break;
    	default:
        		printf("\n\t\tONLY 1-5 ALLOWED\n");
        		start_menu();
        		break;
    }
}

int interaction(char name[50])
{
	system("clear");
	system("aplay -c 1 -t wav -q KBCstart.wav &");
	char k;
	printf(BOLD RED UNDER BLINK"\n\n\n\t\t\tWELCOME %s"RESET_BOLD RESET_CLR RESET_BLINK RESET_UNDER,name);
	printf("\n\n\t\t Press " BLUE "ENTER"RESET_CLR  " to Start the game\n\n\n\n");
	scanf("%c",&k);	
}

void start()
{
    system("clear");
    
    printf(YELLOW"\n\t_________________________________________________________\n"RESET_CLR);
    printf(RED"\n\t\t\t        START "RESET_CLR);
    printf(YELLOW"\n\t_________________________________________________________\n"RESET_CLR);
    char name[50];
    printf("\n\t\t Enter Name: ");
    getchar();
    scanf("%s",name);
    getchar();
    interaction(name);
    quiz();
    system("clear");
	system("aplay -c 1 -t wav -q KBCFinalScore.wav &");
    printf(YELLOW"\n\t_________________________________________________________\n"RESET_CLR);
    printf(RED"\n\t\t\t        YOUR SCORE "RESET_CLR);
    printf(YELLOW"\n\t_________________________________________________________\n"RESET_CLR);
    printf("\n\t\tSCORE: \t\t\t%d ",score);
    printf("\n");
    printf("\n\t\tTIME TAKEN: \t\t%lf s",total_time);
    printf("\n");
    if(total_time<300)
    {
        printf(BLUE"\n\t\t\t\t  EXCELLENT!!!\n");
        printf("\t\tYOU TOOK LESS THAN 5 MINUTES TO FINISH THE GAME!!!\n"RESET_CLR);
    }
    if(total_time>300 && total_time<600)
    {
        printf(MAGENTA"\n\t\t\t\t  GOOD!!!\n");
        printf("\t\tYOU TOOK LESS THAN 10 MINUTES TO FINISH THE GAME!!!\n"RESET_CLR);
    }
    if(total_time>900)
    {
        printf(YELLOW"\n\t\t\t   SCOPE FOR IMPROVEMENT!\n");
        printf("\t\tYOU TOOK MORE THAN 15 MINUTES TO FINISH THE GAME!!!\n"RESET_CLR);
    }
    printf("\n");
    if(score>max)
        {
        printf(RED"\t\t\t\tCONGRATULATIONS!!!\n"RESET_CLR);
        printf(CYAN"\t\t\tYOU ARE THE NEW HIGH SCORER\n"RESET_CLR);
        max=score;
        strcpy(max_name,name);
        }
    printf("\n");
  
    start_menu();
}

int quiz()
{
    system("clear");
    int a1[]= {0,1,2,3,4,5,6,7,8,9};
    int a2[]= {0,1,2,3,4,5,6,7,8,9};
    int a3[]= {0,1,2,3,4,5,6,7,8,9};
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
	  system("aplay -c 1 -t wav -q KBCques.wav &");
        printf("%s",questions[level][num]);
        printf("%s",options[level][num]);
        begin=clock();
        while(1)
        {
		  printf(MAGENTA"\n\t Your Answer (option): "RESET_CLR);
		  scanf("%d",&ans);
		  if(ans>0&&ans<5)
		  	break;
		  else
		  	printf(CYAN"\n\t\t PLEASE enter between '1-4'\n"RESET_CLR);	
	  }
	  end=clock();
        
        if(ans==answers[level][num])
        {
            score++;
            correct();
        }
        else
        {
            printf(GREEN"\n\t\t\t     Correct Answer is option %d \n"RESET_CLR, answers[level][num] );   
        	wrong();
        }
        
        time_spent = time_spent + (((double)(end-begin))/CLOCKS_PER_SEC);
        t=time_spent*1000000/(72*60);  //in my compiler for 72 min CLOCKS_PER_SEC gives 1000000 sec
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

void correct()
{
	system("aplay -c 1 -t wav -q KBCClaps.wav &");
    printf(GREEN"\n                       ___  ___  ___  ___   ___  ___ _____        /"RESET_CLR);
    printf(GREEN"\n                      |    |   ||   ||   | |    |      |         /  "RESET_CLR);
    printf(GREEN"\n                      |    |   ||___||___| |    |---   |        /  "RESET_CLR);
    printf(GREEN"\n                      |___ |___|| |__| |__ |___ |___   |      \\/  \n"RESET_CLR);
	sleep(s);
}

void wrong()
{
	
	system("aplay -c 1 -t wav -q KBCwrong.wav &");
    printf(RED"\n                                  ___  ___  _    ___      \\  /     "RESET_CLR);
    printf(RED"\n                            |   ||   ||   || | ||          \\/  "RESET_CLR);
    printf(RED"\n                            | | ||___||   || | || --.      /\\  "RESET_CLR);
    printf(RED"\n                            |_|_|| |__|___|| |_||___|     /  \\  \n"RESET_CLR);
	sleep(s);
}

void highest_score()
{
    system("clear");
    
    printf(YELLOW"\n\t_________________________________________________________"RESET_CLR);
    printf(RED"\n\t\t\t        HIGHEST SCORE "RESET_CLR);
    printf(YELLOW"\n\t_________________________________________________________\n"RESET_CLR);
    printf("\n\t\tNAME: \t\t\t%s ",max_name);
    printf("\n\t\tSCORE: \t\t\t%d ",max);
    printf(YELLOW"\n\t_________________________________________________________\n"RESET_CLR);
    
    start_menu();
}

void reset()
{
    system("clear");
    
    max=0;
    strcpy(max_name,"---------");
    printf("\n\t\tScore is reseted successfully\n");
    
    start_menu();
}

void help()
{
    system("clear");
    
    printf(YELLOW"\n\t_______________________________________________________\n"RESET_CLR);
    printf(RED"\n\t\t\t        HELP "RESET_CLR);
    printf(YELLOW"\n\t_______________________________________________________\n"RESET_CLR);
    printf("\n > You will be given with 10 different questions (one at a time)");
    printf("\n > Time will be calculated, for how long you are taking to answer");
    printf("\n > Based on the time taken, next question will be given from different categories like:");
    printf("\n   - If you take more than 2 minutes to answer then easier question will come");
    printf("\n   - If you take less than 1 minute to answer then moderate question will come ");
    printf("\n   - If you take less than 30 seconds to answer then difficult question will come ");
    printf(CYAN"\n\n\t\t\t   GOOD LUCK!! \n\n"RESET_CLR);
    
    start_menu();
}
