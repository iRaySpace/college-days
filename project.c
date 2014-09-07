/**
*	WHAT MY GUT TELLS ME 
*   This program is a quiz-type of game in which
*	it test your knowledge about history, computers, and etc.
*	
*	@author Agbayani, Almeneana, Altomera
*	@version 0.7
*	@since 2014-09-07
*/

#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<windows.h>

// Defining constants
#define PLAYERS 2
#define MAX_QUESTIONS 10

// Defining structures to be used
typedef struct {
	char *text;
	char *choices;
	int answer;
} Question;

typedef struct {
	char name[32];
	int answer;
	int score;
} Player;

// Initialization
int maxQuestion = 0;
int curQuestion = 0;

// Declaration
Question quiz[90];
Player player[PLAYERS];

/**
*	This is an inline method,
*	which sets the var curQuestion
*	to the random number within 0 - 90
*
*	@param Nothing.
*	@return Nothing.
*	@see https://gcc.gnu.org/onlinedocs/gcc/Inline.html
*/
inline void getRandomQuestion() {
	curQuestion = rand() % 90;
	printf("%s %s", quiz[curQuestion]);
}

// Function Prototypes
void initQuestions();
void mainMenu();
void rules();
void exitScreen();

void color();
void getInfo();

void displayHUD();
void evaluateAns();
void getAllPlayerAns();

void whoGotHighScore();
void conclusion();

void playerAns(Player *a);

int getHighScore();

/**
*	The main method
*
*	@param Nothing.
*	@return int This returns if the program is successful run(0) or not.
*/
int main()
{
	maxQuestion = MAX_QUESTIONS;
	
	// Random seed generator
	// @see http://www.codingunit.com/c-reference-stdlib-h-function-srand-initialize-random-number-generator
	srand(time(NULL));
	
	initQuestions();
	mainMenu();	system("color A0");
	getInfo(); system("cls");
	color(); system("color F0");
	
	// Limiting the question asked.
	// @see MAX_QUESTIONS(above)
	do
	{ 
	
		maxQuestion -= 1;
		displayHUD();
		getRandomQuestion();
		getAllPlayerAns();
		evaluateAns(); system("pause");	system("cls");
		
	} while(maxQuestion > 0);
	
	conclusion(); system("color 0E");
	
	getch();
	return 0;
}

/**
*	This method is responsible for displaying the HUD
*	or the Heads-up Display, that certainly displays
*	the specific info of the game like scores, and etc.
*
*	@param Nothing.
*	@return Nothing.
*/
void displayHUD()
{
	int i;
	
	for(i = 0; i < PLAYERS; i++) printf("%s, SCORE : %d\n", player[i].name, player[i].score);	
	
	printf("QUESTIONS LEFT : %d\n", maxQuestion);
}

/**
*	This method is responsible for getting inputs
*	from the user specifically the name of the user
*
*	@param Nothing.
*	@return Nothing.
*/
void getInfo()
{
	int i;
	
	for(i = 0; i < PLAYERS; i++)
	{
	    printf("Player %d, enter your name: ", i+1);
	    scanf(" %[^\n]s", &player[i]);
	}
}

/**
*	This method is responsible for getting the answer
*	of the player of the game, and puts stores it
*	into a specific variable that is passed by
*	reference.
*
*	@param a It is a pointer to struct Player,
*			 In which it is used to display the name, and
*			 Get the answer of the user
*	@return Nothing.
*	@see typedef struct Player(above)
*/
void playerAns(Player *a)
{
	printf("\n%s, enter your answer: ", a->name);
	scanf("%d", &(a->answer));
}

/**
*	This method calls the playerAns method,
*	in which it iterates over the player array,
*	that would be used to be pass to the playerAns
*	specifically the address of the specific player element
*
*	@param Nothing.
*	@return Nothing.
*/
void getAllPlayerAns()
{
	int i;
	
	for(i = 0; i < PLAYERS; i++) playerAns(&player[i]);
}

/**
*	This method is used to initialize the following questions
*	to be used during the quiz game. It includes the question,
*	answers, and choices.
*
*	@param Nothing.
*	@return Nothing.
*/
void initQuestions()
{
	// Questions
	quiz[0].text = "\nWhat is the name of a print made by cutting a design in a wood block?\n";
	quiz[1].text = "\nWho was the author of the 1970 fiction book \"Love Story\"?\n";
	quiz[2].text = "\nVincent Van Gogh\'s paintings are known for bright colors and what kind of compositions?\n";
	quiz[3].text = "\nIn the \"Harry Potter\" series, what is the name of Ron Weasley\'s sister?\n";
	quiz[4].text = "\nWho does Mr Brownlow rescue?\n";
	quiz[5].text = "\nWho wrote the play \"Waiting for Godot\"?\n";
	quiz[6].text = "\nVermilion is a particular pigment of which color?\n";
	quiz[7].text = "\nWhat is the name of the style that is a realistic representation of people, places or things?\n";
	quiz[8].text = "\nRaphael\'s \"School of Athens\" features all but which famous figure?\n";
	quiz[9].text = "\nAuthor Samuel Langhorne Clemens used what pen name?\n";
	quiz[10].text = "\nWhat classic song contains the lyrics \"And the forests will echo with laughter..\"?\n";
	quiz[11].text = "\nWhat was the name of the 1986 independent debut EP from Guns N\' Roses?\n";
	quiz[12].text = "\nWhich 2011 album was a collaboration between Lou Reed and Metallica?\n";
	quiz[13].text = "\nWho won the MTV Video of the Year Award in 2008 for \"Piece of Me\"?\n";
	quiz[14].text = "\nWhich band was fronted by a married couple?\n";
	quiz[15].text = "\nHow are the Screaming Trees\' Wan Conner and Gary Lee Conner related to each other?\n";
	quiz[16].text = "\nWho penned the classics songs \"Bad Moon Rising\", \"Who\'ll Stop the Rain\", and \"Lodi\"?\n";
	quiz[17].text = "\nWhat was the name of Metallica\'s first album?\n";
	quiz[18].text = "\nWith which song did Lulu win the Eurovision song contest?\n";
	quiz[19].text = "\nWhich band is not from Scotland?\n";
	quiz[20].text = "\nWhat condition do you have when you have decreased red blood cells or low red blood cell count?\n";
	quiz[21].text =	"\nWhich scientist was born in Germany in 1879, became a Swiss citizen in 1901 and later became a U.S. citizen in 1940?\n",
	quiz[22].text =	"\nWhere in Europe is the Barbary Ape most likely found?\n";
	quiz[23].text =	"\nWhat is a stag with twelve-point antlers known as?\n";
	quiz[24].text =	"\nWhat does on OLF unit measure?\n";
	quiz[25].text =	"\nIn computing, how many bits make one byte?\n";
	quiz[26].text =	"\nWhat type of power did the ancient Persians use to grind grains?\n";
	quiz[27].text =	"\nWhich of these is a heavy gas used in specialized electric lamp?\n";
	quiz[28].text =	"\nWhat will usually happen to matter that is cooled?\n";
	quiz[29].text =	"\nWith which name do we refer to a female cat?\n";
	quiz[30].text =	"\nWhat Cape will you find at the tip of Africa?\n"; 
	quiz[31].text =	"\nOf the following countries which is most renowned for making chocolate?\n";
	quiz[32].text =	"\nWhich volcano showers ash on Sicily?\n";
	quiz[33].text =	"\nWhich city is known as the \"City of Brotherly Love\"?\n";
	quiz[34].text =	"\nIn which sea would you find the Cayman Islands?\n";
	quiz[35].text =	"\nIn which city does the National Assembly of Wales sit?\n";
	quiz[36].text =	"\nWhich country has a larger population?\n";
	quiz[37].text =	"\nWhich nation in Southeastern Asia gained its independance from France on September 2, 1945?\n";
	quiz[38].text =	"\nThe name of Argentina's Rio Negro has what English translation?\n";
	quiz[39].text =	"\nCrocodiles, but not alligators, make which of these countries their home?\n";
	quiz[40].text =	"\nWhich is the correct name of a professional sports team?\n"; 
	quiz[41].text =	"\nWhich boxer earned the nickname \"Smokin\'n Joe\"?\n";
	quiz[42].text =	"\nHow many members make up a relay team in a Track and Field relay race?\n";
	quiz[43].text =	"\nWhich of these pitchers struck out four batters in one inning on April 27, 2012?\n";
	quiz[44].text =	"\nMajor League Baseball\'s Ivan Rodriguez plays which position?\n";
	quiz[45].text =	"\nWhich baseball star hit over 60 homeruns in a season for the Cubs?\n";
	quiz[46].text =	"\nHow many Major League Baseball teams does New York City have?\n";
	quiz[47].text =	"\nIn 2007 Preakness Stakes was won by which chestnut stallion?\n";
	quiz[48].text =	"\nWho caught Tim Tebow\'s 80-yard TD pass in the Broncos\' 2011 playoff game against the Steelers?\n";
	quiz[49].text =	"\nWhat does the checkered flag signal in NASCAR racing?\n";
	quiz[50].text =	"\nEvil Manta is a character in which animated film?\n"; 
	quiz[51].text =	"\nIn which film did Dustin Hoffman play the character of Jack Crabb?\n";
	quiz[52].text =	"\nWhich film was not directed by Stanley Kubrick?\n";
	quiz[53].text =	"\nWho plays Superman in \"Superman Returns\"?\n";
	quiz[54].text =	"\nWhat famous pop singer stars in the movie \"Alpha Dog\"?\n";
	quiz[55].text =	"\nHarry Potter marries which character following the events of \"The Deathly Hallows\"?\n";
	quiz[56].text =	"\nThomas O\'Malley is a cat in which film?\n";
	quiz[57].text =	"\nWhich profession did Kevin James take up in a 2011 film directed by Frank Coraci?\n";
	quiz[58].text =	"\nWho plays Jackie Moon in the 2008 film \"Semi-Pro\"?\n";
	quiz[59].text =	"\nWho voiced Artie in the 2007 movie \"Shrek the Third\"?\n";
	quiz[60].text =	"\nWhich characters finish their \"Lost Summer Trip\" in the first episode of season 5 of \"Gossip Girl\"?\n"; 
	quiz[61].text =	"\nWho guest starred on TV\'s \"ER\" as Madame X, the Alzheimer\'s stricken singer?\n";
	quiz[62].text =	"\nOn \"Chuck\"; what is the nickname for Elle\'s boyfriend Devon?\n";
	quiz[63].text =	"\nWhich of the following story book characters did not appear in the first 12 episodes of \"Once Upon a Time\"?\n";
	quiz[64].text =	"\nWho was left at the altar in the 2007 season finale of \"Grey\'s Anatomy\"?\n";
	quiz[65].text =	"\nWho is the Dean of Medicine on the TV show \"House\"?\n";
	quiz[66].text =	"\nJoanna Kerns and Tracy Gold starred in which TV show?\n";
	quiz[67].text =	"\nWho portrayed surveillance chief Ed Deline on TV\'s \"Las Vegas\"?\n";
	quiz[68].text =	"\nIn 2009, who started dating Robin in \"How I Met Your Mother\"?\n";
	quiz[69].text =	"\nWhat city does \"Nurse Jackie\" work in?\n";
	quiz[70].text =	"\nWhat often caused the poor of Ancient Rome to riot?\n"; 
	quiz[71].text =	"\nIn which city was the Titanic built?\n";
	quiz[72].text =	"\nWho was the first Prime Minister of Great Britain?\n";
	quiz[73].text =	"\nWhich major British newspaper closed down for almost a year in 1978?\n";
	quiz[74].text =	"\nWhat natural disaster is believed to have caused the decline of the culture of Ancient Crete?\n";
	quiz[75].text =	"\nWhat did the Bolshevics rename themselves in 1918?\n";
	quiz[76].text =	"\nIn what year was President George W. Bush born?\n";
	quiz[77].text =	"\nWhich President is not on Mount Rushmore?\n";
	quiz[78].text =	"\nWhat famous lady was a radio actress before gaining political power?\n";
	quiz[79].text =	"\nWhat U.S. state had a re-count of votes for the Presidential election in 2000?\n";
	quiz[80].text =	"\nWhat company bought YouTube for $1.65 billion in 2006?\n"; 
	quiz[81].text =	"\nWhat is a website allowing users to edit content?\n";
	quiz[82].text =	"\nWhat company did the Hyundai borrow technology from to launch its vehicles?\n";
	quiz[83].text =	"\nWhat can be used to start a computer?\n";
	quiz[84].text =	"\nWhich computer company ran the infamous 1984 commercial during the 1984 Super Bowl?\n";
	quiz[85].text =	"\nIn 2008, what was the most common computer port?\n";
	quiz[86].text =	"\nWhat was the first four-wheel drive vehicle?\n";
	quiz[87].text =	"\nWhich airplane did Scandinavian airline SAS first operate in 2001?\n";
	quiz[88].text =	"\nWhat kind of main memory is used in PCs?\n";
	quiz[89].text =	"\nIn what year was celluloid film introduced?\n";
	
	// Choices
	quiz[0].choices = "\t[1] Model \n\t[2] Painting \n\t[3] Woodcut \n\t[4] Sculptor";
	quiz[1].choices = "\t[1] Erich Segal \n\t[2] Francis Hackett \n\t[3] James Truslow Adams \n\t[4] John Galsworthy";
	quiz[2].choices = "\t[1] Complex \n\t[2] Linear \n\t[3] Funny \n\t[4] Simple";
	quiz[3].choices = "\t[1] Ginny \n\t[2] Mary \n\t[3] Hermione \n\t[4] Cho";
	quiz[4].choices = "\t[1] Tom Brown \n\t[2] Huckleberry Finn \n\t[3] Oliver Twist \n\t[4] Tom Jones";
	quiz[5].choices = "\t[1] George Bernard Shaw \n\t[2] Andrew Lloyd Webber \n\t[3] Vladimir Nabokov \n\t[4] Samuel Beckett";
	quiz[6].choices = "\t[1] Green \n\t[2] Blue \n\t[3] Purple \n\t[4] Red";
	quiz[7].choices = "\t[1] Realism \n\t[2] Romanticism \n\t[3] Idealism \n\t[4] Abstract";
	quiz[8].choices = "\t[1] Pythagoras \n\t[2] Socrates \n\t[3] Plato \n\t[4] George Washington";
	quiz[9].choices = "\t[1] Mary Shelley \n\t[2] L. Frank Baum \n\t[3] Jules Verne \n\t[4] Mark Twain";
	quiz[10].choices = "\t[1] Gallows Pole \n\t[2] Stairway to Heaven \n\t[3] The Song Remains the Same \n\t[4] Dancing Days";
	quiz[11].choices = "\t[1] Top Hat Sessions \n\t[2] Live! Like a Suicide \n\t[3] Cooked and Loaded \n\t[4] Patience N\' Lies";
	quiz[12].choices = "\t[1] Lulu \n\t[2] Garage Inc. \n\t[3] Thirteen \n\t[4] Songs for Drella";
	quiz[13].choices = "\t[1] Rihanna \n\t[2] Eric Clapton \n\t[3] Britney Spears \n\t[4] Jesus Jones";
	quiz[14].choices = "\t[1] America \n\t[2] ELP \n\t[3] Wings \n\t[4] Cream";
	quiz[15].choices = "\t[1] Father and son \n\t[2] None \n\t[3] Brothers \n\t[4] Cousins";
	quiz[16].choices = "\t[1] Pete Townsend \n\t[2] John Fogerty \n\t[3] Joe Cocker \n\t[4] Glenn Frye";
	quiz[17].choices = "\t[1] Master of Puppets \n\t[2] Metallica \n\t[3] Load \n\t[4] Kill \'Em All";
	quiz[18].choices = "\t[1] Diggi Loo Diggi Ley \n\t[2] Ding a Dong \n\t[3] Boom Bang a Bang \n\t[4] A Ba Ni Bi";
	quiz[19].choices = "\t[1] Nazareth \n\t[2] Simple Minds \n\t[3] Stone the Crows \n\t[4] Saw Doctors";
	quiz[20].choices = "\t[1] Cessation \n\t[2] Subcutaneous \n\t[3] Intraperitoneal \n\t[4] Anemia";
	quiz[21].choices = "\t[1] Niels Bohr \n\t[2] Albert Einstein \n\t[3] Max Planck \n\t[4] Ludwig Boltzmann";
	quiz[22].choices = "\t[1] Greece \n\t[2] Gibralta \n\t[3] Bulgaria \n\t[4] Portugal";
	quiz[23].choices = "\t[1] Baron \n\t[2] Royal \n\t[3] Duke \n\t[4] Ambassador";
	quiz[24].choices = "\t[1] Light \n\t[2] Heat \n\t[3] Smell \n\t[4] Taste";
	quiz[25].choices = "\t[1] 4 \n\t[2] 8 \n\t[3] 16 \n\t[4] 12";
	quiz[26].choices = "\t[1] Electricity \n\t[2] Wind Power \n\t[3] Fossil Fuels \n\t[4] Solar Power";
	quiz[27].choices = "\t[1] Xenon \n\t[2] Hydrogen \n\t[3] Helium \n\t[4] Nitrous Oxide";
	quiz[28].choices = "\t[1] It Will Change Taste \n\t[2] It Contracts \n\t[3] It Does Nothing \n\t[4] It Expands";
	quiz[29].choices = "\t[1] Queen \n\t[2] Doe \n\t[3] Kitty \n\t[4] Bitch";
	quiz[30].choices = "\t[1] Cape of Good Hope \n\t[2] Cape Gris-Nez \n\t[3] Cape Fear \n\t[4] Cape Cod";
	quiz[31].choices = "\t[1] Belgium \n\t[2] Sweden \n\t[3] Denmark \n\t[4] England";
	quiz[32].choices = "\t[1] Etna \n\t[2] Vesuvius \n\t[3] Ararat \n\t[4] Ida";
	quiz[33].choices = "\t[1] Miami \n\t[2] Los Angeles \n\t[3] New York \n\t[4] Philadelphia";
	quiz[34].choices = "\t[1] Coral Sea \n\t[2] Carribean Sea \n\t[3] Mediterranean Sea \n\t[4] Aegean Sea";
	quiz[35].choices = "\t[1] Newport \n\t[2] Swansea \n\t[3] St. Davids \n\t[4] Cardiff";
	quiz[36].choices = "\t[1] San Marino \n\t[2] Oman \n\t[3] French Guiana \n\t[4] Argentina";
	quiz[37].choices = "\t[1] Rwanda \n\t[2] Tajikistan \n\t[3] Vietnam \n\t[4] Brazil";
	quiz[38].choices = "\t[1] Black River \n\t[2] Brown River \n\t[3] Salt Lake \n\t[4] Red Sea";
	quiz[39].choices = "\t[1] Australia \n\t[2] United States of America \n\t[3] Mexico \n\t[4] Paraguay";
	quiz[40].choices = "\t[1] Dallas Mavericks \n\t[2] Memphis Nuggets \n\t[3] Boston Grizzlies \n\t[4] Denver Celtics";
	quiz[41].choices = "\t[1] Joe DiMaggio \n\t[2] Joe McCarthy \n\t[3] Joe Louis \n\t[4] Joe frazier";
	quiz[42].choices = "\t[1] Six \n\t[2] Five \n\t[3] Four \n\t[4] Three";
	quiz[43].choices = "\t[1] Philip Humber \n\t[2] Ryan Cook \n\t[3] Felix Hernandez \n\t[4] Justin Verlander";
	quiz[44].choices = "\t[1] Pitcher \n\t[2] Outfielder \n\t[3] Shortstop \n\t[4] Catcher";
	quiz[45].choices = "\t[1] Sammy Sosa \n\t[2] David Ortiz \n\t[3] Jason Giambi \n\t[4] Carlos Lee";
	quiz[46].choices = "\t[1] Two \n\t[2] Three \n\t[3] One \n\t[4] Zero";
	quiz[47].choices = "\t[1] Street Sense \n\t[2] Hard Pun \n\t[3] King of the Roxy \n\t[4] Curlin";
	quiz[48].choices = "\t[1] D\'Andre Goodwin \n\t[2] Demaryius Thomas \n\t[3] Eddie Royal \n\t[4] Matthew Willis";
	quiz[49].choices = "\t[1] The Race is Over \n\t[2] Accident Ahead \n\t[3] The Beginning of the Race \n\t[4] Start Your Engines";
	quiz[50].choices = "\t[1] Shrek \n\t[2] The Little Mermaid \n\t[3] Finding Nemo \n\t[4] A Bug\'s Life";
	quiz[51].choices = "\t[1] Little Big Man \n\t[2] The Graduate \n\t[3] Rain Man \n\t[4] Marathon Man";
	quiz[52].choices = "\t[1] 2001 \n\t[2] The Shining \n\t[3] Dr. Strangelove \n\t[4] One flew over the cuckoo\'s nest";
	quiz[53].choices = "\t[1] Sam Huntington \n\t[2] Brandon Routh \n\t[3] Kal Penn \n\t[4] Ashton Kutcher";
	quiz[54].choices = "\t[1] Billy Idol \n\t[2] Justin Timberlake \n\t[3] John Mayer \n\t[4] Justin Guarini";
	quiz[55].choices = "\t[1] Hermione Granger \n\t[2] Narcissa Malfoy \n\t[3] Ginny Weasley \n\t[4] Luna Lovegood";
	quiz[56].choices = "\t[1] Lethal Weapon \n\t[2] Aristocats \n\t[3] Die Hard \n\t[4] Dumbo";
	quiz[57].choices = "\t[1] Taxi Driver \n\t[2] Zookeeper \n\t[3] Cable Guy \n\t[4] Mall Cop";
	quiz[58].choices = "\t[1] Stephen Colbert \n\t[2] Will Ferrell \n\t[3] Michael Scott \n\t[4] Andy Richter";
	quiz[59].choices = "\t[1] Eddi Murphy \n\t[2] Eric Idle \n\t[3] Justin Timberlake \n\t[4] Brad Pitt";
	quiz[60].choices = "\t[1] Mark and Dan \n\t[2] Ron and Fez \n\t[3] Chuck and Nate \n\t[4] Blair and Louis";
	quiz[61].choices = "\t[1] Kathleen Battle \n\t[2] Beverly Sills \n\t[3] Rosemary Clooney \n\t[4] Piper Laurie";
	quiz[62].choices = "\t[1] The Devonator \n\t[2] The Professor \n\t[3] D-Smooth \n\t[4] Captain Awesome";
	quiz[63].choices = "\t[1] Red Riding Hood \n\t[2] Snow White \n\t[3] Cinderella \n\t[4] Rumplestiltskin";
	quiz[64].choices = "\t[1] George \n\t[2] Meredith \n\t[3] Christina \n\t[4] Burke";
	quiz[65].choices = "\t[1] Dr. Lisa Cuddy \n\t[2] Dr. Allison Cameron \n\t[3] Dr. Eric Foreman \n\t[4] Dr. James Wilson";
	quiz[66].choices = "\t[1] The Facts of Life \n\t[2] Growing Pains \n\t[3] My Two Dads \n\t[4] The Golden Girls";
	quiz[67].choices = "\t[1] Darryl Frank \n\t[2] James Caan \n\t[3] Gary Scott Thompson \n\t[4] Josh Duhamel";
	quiz[68].choices = "\t[1] Barney \n\t[2] Ted \n\t[3] Ralph \n\t[4] Bob";
	quiz[69].choices = "\t[1] Washington D.C. \n\t[2] Chicago \n\t[3] New York City \n\t[4] Los Angeles";
	quiz[70].choices = "\t[1] Bad News \n\t[2] Conscription \n\t[3] Elections \n\t[4] Lack of Food";
	quiz[71].choices = "\t[1] Liverpool \n\t[2] Belfast \n\t[3] Southampton \n\t[4] Glasgow";
	quiz[72].choices = "\t[1] William Pitt The Elder \n\t[2] Winston Churchill \n\t[3] Michael Portillo \n\t[4] Robert Walpole";
	quiz[73].choices = "\t[1] The Times \n\t[2] The Sun \n\t[3] The Telegraph \n\t[4] The Mirror";
	quiz[74].choices = "\t[1] A Plague \n\t[2] A Hurricane \n\t[3] A Volcanic Eruption \n\t[4] An Earthquake";
	quiz[75].choices = "\t[1] Comrades \n\t[2] Communist Party \n\t[3] Mensheviks \n\t[4] Leninists";
	quiz[76].choices = "\t[1] 1923 \n\t[2] 1946 \n\t[3] 1909 \n\t[4] 1958";
	quiz[77].choices = "\t[1] Theodore Roosevelt \n\t[2] Franklin Roosevelt \n\t[3] George Washington \n\t[4] Abraham Lincoln";
	quiz[78].choices = "\t[1] Jackie Kennedy \n\t[2] Eva Peron \n\t[3] Susan B Anthony \n\t[4] Imelda Marcos";
	quiz[79].choices = "\t[1] California \n\t[2] Texas \n\t[3] New York \n\t[4] Florida";
	quiz[80].choices = "\t[1] Microsoft \n\t[2] Yahoo \n\t[3] Excite \n\t[4] Google";
	quiz[81].choices = "\t[1] Gateway \n\t[2] Listserv \n\t[3] Wiki \n\t[4] Portal";
	quiz[82].choices = "\t[1] Nissan \n\t[2] Kia \n\t[3] Mitsubishi \n\t[4] Toyota";
	quiz[83].choices = "\t[1] Base Station \n\t[2] Boot Disk \n\t[3] Floppy Disk \n\t[4] Router";
	quiz[84].choices = "\t[1] Coleco \n\t[2] Microsoft \n\t[3] IBM \n\t[4] Apple";
	quiz[85].choices = "\t[1] USB \n\t[2] URL \n\t[3] Ethernet \n\t[4] UDP";
	quiz[86].choices = "\t[1] Jeep \n\t[2] Escalade \n\t[3] Beetle \n\t[4] Minivan";
	quiz[87].choices = "\t[1] Airbus A330 \n\t[2] Airbus A340 \n\t[3] Airbus A319 \n\t[4] Boeing 737";
	quiz[88].choices = "\t[1] ROM \n\t[2] Flash \n\t[3] DRAM \n\t[4] Magnetic Tape";
	quiz[89].choices = "\t[1] 1839 \n\t[2] 1965 \n\t[3] 1887 \n\t[4] 1972";
	
	// Answers
	quiz[0].answer = 3;
	quiz[1].answer = 1;
	quiz[2].answer = 4;
	quiz[3].answer = 1;
	quiz[4].answer = 3;
	quiz[5].answer = 4;
	quiz[6].answer = 4;
	quiz[7].answer = 1;
	quiz[8].answer = 4;
	quiz[9].answer = 4;
	quiz[10].answer = 2;
	quiz[11].answer = 2;
	quiz[12].answer = 1;
	quiz[13].answer = 3;
	quiz[14].answer = 3;
	quiz[15].answer = 3;
	quiz[16].answer = 2;
	quiz[17].answer = 4;
	quiz[18].answer = 3;
	quiz[19].answer = 4;
	quiz[20].answer = 4;
	quiz[21].answer = 2;
	quiz[22].answer = 2;
	quiz[23].answer = 2;
	quiz[24].answer = 3;
	quiz[25].answer = 2;
	quiz[26].answer = 2;
	quiz[27].answer = 1;
	quiz[28].answer = 2;
	quiz[29].answer = 1;
	quiz[30].answer = 1;
	quiz[31].answer = 1;
	quiz[32].answer = 1;
	quiz[33].answer = 4;
	quiz[34].answer = 2;
	quiz[35].answer = 4;
	quiz[36].answer = 4;
	quiz[37].answer = 3;
	quiz[38].answer = 1;
	quiz[39].answer = 1;
	quiz[40].answer = 1;
	quiz[41].answer = 4;
	quiz[42].answer = 3;
	quiz[43].answer = 2;
	quiz[44].answer = 4;
	quiz[45].answer = 1;
	quiz[46].answer = 1;
	quiz[47].answer = 4;
	quiz[48].answer = 2;
	quiz[49].answer = 1;
	quiz[50].answer = 2;
	quiz[51].answer = 1;
	quiz[52].answer = 4;
	quiz[53].answer = 2;
	quiz[54].answer = 2;
	quiz[55].answer = 3;
	quiz[56].answer = 2;
	quiz[57].answer = 2;
	quiz[58].answer = 2;
	quiz[59].answer = 3;
	quiz[60].answer = 3;
	quiz[61].answer = 3;
	quiz[62].answer = 4;
	quiz[63].answer = 1;
	quiz[64].answer = 3;
	quiz[65].answer = 1;
	quiz[66].answer = 2;
	quiz[67].answer = 2;
	quiz[68].answer = 1;
	quiz[69].answer = 3;
	quiz[70].answer = 4;
	quiz[71].answer = 2;
	quiz[72].answer = 4;
	quiz[73].answer = 1;
	quiz[74].answer = 3;
	quiz[75].answer = 2;
	quiz[76].answer = 2;
	quiz[77].answer = 2;
	quiz[78].answer = 2;
	quiz[79].answer = 4;
	quiz[80].answer = 4;
	quiz[81].answer = 3;
	quiz[82].answer = 3;
	quiz[83].answer = 2;
	quiz[84].answer = 4;
	quiz[85].answer = 1;
	quiz[86].answer = 1;
	quiz[87].answer = 2;
	quiz[88].answer = 3;
	quiz[89].answer = 3;
	
}

/**
*	This method is used to compare
*	the players' answers to the questions' answers
*	by iterating over it.
*
*	@param Nothing.
*	@return Nothing.
*/
void evaluateAns()
{
	int i;
	
	for(i = 0; i < PLAYERS; i++)
	{
		if(player[i].answer == quiz[curQuestion].answer)
		{
			printf("\n%s, you are CORRECT!\n", player[i].name);
			player[i].score += 1;
		}
		
		else printf("\n%s, you are WRONG!\n", player[i].name);
	}
	
}

/**
*	This method is used only for displaying
*	the exit screen of the game.
*
*	@param Nothing.
*	@return Nothing.
*/
void exitScreen()
{
	system("color CF");
    printf("Game is EXITING...\n\n");
    system("pause");
    exit(0);
}

/**
*	The second starting point of the game.
*
*	This method is used to navigate
*	over the specific parts of the game,
*	like playing, reading rules, and exiting.
*
*	@param Nothing.
*	@return Nothing.
*/
void mainMenu()
{
	int choice = 0;
	
	system("color 0E");
	
	printf("*=============================================================================*\n");
    printf("*                                                                             *\n");
    printf(" *                  %c   WELCOME TO WHAT MY GUT TELLS ME!   %c                 *\n", 2,1);
    printf("*                                                                             *\n");
    printf("*=============================================================================*\n\n"); 
    
    printf("[1] Start Game\n");
    printf("[2] Mechanics and Rules\n");
    printf("[3] Exit\n");
    
    printf("YOUR CHOICE : ");
    scanf("%d", &choice);
    
    system("cls");
    
    switch(choice) {
    	case 1:
    		break;
    	case 2:
    		rules();
    		break;
    	case 3:
    		exitScreen();
    		break;
    	default:
    		mainMenu();
    }
}

/**
*	This method displays the rules in the game.
*
*	Nothing fancy!
*
*	@param Nothing.
*	@return Nothing.
*/
void rules()
{
	system("cls");
	system("color E0");
	
	printf("RULES:\n\n");
	printf("[1] The computer will generate randomly the questions to be displayed.\n\n");
	printf("[2] Each player should then answer the question when asked.\n\n");
	printf("[3] Type the number corresponding your answer and press ENTER.\n");
	printf("    [3a] If a player is correct, 1 point will be rewarded to the player who\n");
	printf("         got the correct answer.\n");
	printf("    [3b] If a player is wrong, the score will remain the same.\n");
	printf("    [3c] If a player inputs an answer that is neither 1 or 2 or 3 or 4, it is\n");
	printf("         considered wrong.\n\n");
	printf("[4] After 10 questions, the game will end. The players can then either choose\n");
	printf("    to save or to not save the game results.\n\n");

	system("pause");
	system("cls");
	
	mainMenu();
}

/**
*	This method animates through a series of colours.
*
*	@param Nothing.
*	@return Nothing.
*/
void color()
{
	system("color E0");	Sleep(250);
	system("color 40");	Sleep(250);
	system("color 90");	Sleep(250);
	system("color A0");	Sleep(250);
	system("color B0");	Sleep(250);	
	system("color D0");	Sleep(250);
	system("cls");
}

/**
*	This method takes the highest param,
*	that is used to displays who got the
*	highest score within the game.
*
*	@param highest It is an int. It is used, mainly in
*				   comparison with the players' scores.
*	@return Nothing.
*/
void whoGotHighScore(int highest)
{
	int i;
	int first;
	
	int j = 0;
	
	for(i = 0; i < PLAYERS; i++) {
		
		if(highest == player[i].score)
		{
			j++;
			if(j == 1) printf("\n%s got the high score!\n", player[i].name);
			else printf("\n%s got also the high score!\n", player[i].name);
			first = i;
		}
			
	}
	
	if(j == 1) printf("\n%s WON THE GAME!\n", player[first].name);
	else printf("\n- IT'S A TIE!\n");
}

/**
*	This method uses selection sort-style algorithm,
*	In which it iterates over remaining n-1 elements
*	Then compares it with the current element value 
*	e.g. value of j.
*
*	It then sets the highest score, if remaining
*	n - 1 element is greater than.
*
*	@param Nothing.
*	@return highest It is an int, that defines the highest score of the game recently played.
*	@see http://en.wikipedia.org/wiki/Selection_sort
*/
int getHighScore()
{
	int i;
	int j;
	int first;
	int highest;
	
	highest = player[0].score;
	
	// Selection sort-style Algorithm
	for(i = 0; i < PLAYERS - 1; i++) 
	{
		for(j = 0 + 1; j < PLAYERS; j++) 
		{
			if(player[j - 1].score > player[j].score) highest = player[j - 1].score;
		}
	}
	
	return highest;
}

/**
*	It is method that calls another method
*	used to display the results of the game,
*	e.g. scores.
*	@param Nothing.
*	@return Nothing.
*/
void conclusion()
{
	int i;
	int highest;
	
	printf("****************\n");
	printf("*              *\n");
	printf("* GAME RESULTS *\n");
	printf("*              *\n");
	printf("****************\n");
	
	for(i = 0; i < PLAYERS; i++) printf("\n - %s got %d points\n", player[i].name, player[i].score);
	
	highest = getHighScore();
	
	if(highest != 0) {
		printf("\nThe highest score is %d\n", highest);
		whoGotHighScore(highest);
	} 
	
	else
	{
		printf("\nWHAT??? YOU GOT ZEROES!\n");
	}
	
}
