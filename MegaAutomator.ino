/**************************************************************************************/
/* LIBRARIES                                                                          */
/**************************************************************************************/

#include <LiquidCrystal.h>
#include <Servo.h>
#include <SPI.h>
#include <SD.h>

/**************************************************************************************/
/* COMPONANT MANAGEMENT                                                               */
/**************************************************************************************/

/******************************************************************/
/* BUTTON CONTROLS                                                */
/******************************************************************/

/*****************************************************/
/* PINS                                              */
/*****************************************************/

const int   _UP                        =  32;
const int   _A                         =  33;
const int   _DOWN                      =  34;
const int   _B                         =  35;
const int   _LEFT                      =  36;
const int   _X                         =  37;
const int   _RIGHT                     =  38;
const int   _Y                         =  39;
const int   _HOME                      =  40;
const int   _RESET                     =  41;

const int   MAN                        =  31;

int counter = 0;

/*****************************************************/
/* DEFINITIONS                                       */
/*****************************************************/

const int   up                         =  0;
const int   a                          =  1;
const int   down                       =  2;
const int   b                          =  3;
const int   left                       =  4;
const int   x                          =  5;
const int   right                      =  6;
const int   y                          =  7;
const int   start                      =  8;
const int   select                     =  9;
const int   manual                     =  10;
const int   NUMBER_BUTTON              =  10;

const int   PUSH                       =  120;

int         Press[11]                  =  {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};

/******************************************************************/
/* LCD CONTROLS                                                   */
/******************************************************************/

/*****************************************************/
/* PINS                                              */
/*****************************************************/

const int   RS                         =  42;
const int   E                          =  43;
const int   D4                         =  44;
const int   D5                         =  45;
const int   D6                         =  46;
const int   D7                         =  47;

/*****************************************************/
/* DEFINITIONS                                       */
/*****************************************************/

const int   LCD_X                        =  20;
const int   LCD_Y                        =  4;

/******************************************************************/
/* ANALOG CONTROLS                                                */
/******************************************************************/

/*****************************************************/
/* PINS                                              */
/*****************************************************/

const int   PHOTO                        =  A0;

/*****************************************************/
/* DEFINITIONS                                       */
/*****************************************************/

/******************************************************************/
/* SD CARD CONTROLS                                               */
/******************************************************************/

/*****************************************************/
/* PINS                                              */
/*****************************************************/

const int   CS                           =  53;

/*****************************************************/
/* DEFINITIONS                                       */
/*****************************************************/

const int   TOTAL_POKEMON                =  721;

char        PokedexList[11];
String      pkmnSearch;
int         NatNumSearch[3]              =  {0, 0, 0};


/******************************************************************/
/* SERVO CONTROLS                                                 */
/******************************************************************/

/*****************************************************/
/* PINS                                              */
/*****************************************************/

const int   SERVO_A                        =  2;
const int   SERVO_B                        =  3;
const int   SERVO_C                        =  4;
const int   SERVO_D                        =  5;
const int   SERVO_E                        =  6;

/*****************************************************/
/* DEFINITIONS                                       */
/*****************************************************/

const int   _CLOSE_A                       =  90;
const int   _CLOSE_B                       =  95;
const int   _CLOSE_C                       =  90;
const int   _CLOSE_D                       =  90;
const int   _CLOSE_E                       =  90;

int   push                                 =  250;

// Servo A
const int   _A_                            =  70;
const int   _X_                            =  110;
// Servo B
const int   _Y_                            =  75;
const int   _B_                            =  115;
// Servo C
const int   _RESET_                        =  70;
const int   _HOME_                         =  110;
// Servo D
const int   _DOWN_                         =  68;
const int   _RIGHT_                        =  107;
// Servo E
const int   _UP_                           =  72;
const int   _LEFT_                         =  124;

/**************************************************************************************/
/* MENU MANAGEMENT                                                                    */
/**************************************************************************************/

const int   MENU                           =  1;
const int   GAME_MENU                      =  2;
const int   ROUTINE_MENU                   =  3;

const int   INIT_BREED                     =  4;
const int   PARENT_OPTION                  =  5;

int         MenuBack                       =  0;

/******************************************************************/
/* HOME MENU                                                      */
/******************************************************************/

const int   SELECT_GAME                    =  0;
const int   ACCOUNTS                       =  1;
const int   SD_MANAGE                      =  2;
const int   SETTINGS                       =  3;

const int   OPEN_LIST                      =  4;
const char* menuList[OPEN_LIST]            =  { "Select a Game",
                                                "Manage Accounts",
                                                "SD Card Management",
                                                "Settings"
                                              };

/******************************************************************/
/* GAME SELECTION MENU                                            */
/******************************************************************/

/*****************************************************/
/* GAME LIST                                         */
/*****************************************************/

const int   ORAS                           =  0;
const int   XY                             =  1;
const int   B2W2                           =  2;
const int   BW                             =  3;
const int   HGSS                           =  4;
const int   PT                             =  5;
const int   DP                             =  6;
const int   FRLG                           =  7;
const int   EM                             =  8;
const int   RUSA                           =  9;

const int   GAME_COUNT                     =  10;
const char* indexGame[GAME_COUNT]          =  { "O.Ruby / A.Sapphire",
                                                "X / Y",
                                                "Black 2 / White 2",
                                                "Black / White",
                                                "H.Gold / S.Silver",
                                                "Platinum",
                                                "Diamond / Pearl",
                                                "F.Red / L.Green",
                                                "Emerald",
                                                "Ruby / Sapphire"
                                              };

/*****************************************************/
/* ROUTINE LIST                                      */
/*****************************************************/

const int   BREED                          =  0;
const int   NAME                           =  1;
const int   EV_TRAIN                       =  2;
const int   LEVEL_TRAIN                    =  3;
const int   SOFT_RESET                     =  4;
const int   CATCH                          =  5;
const int   PICKUP                         =  6;
const int   RELEASE                        =  7;
const int   BASIC_ANALYSIS                 =  8;
const int   ADVANCED_ANALYSIS              =  9;
const int   WONDER_TRADE                   =  10;
const int   CHAIN_FISH                     =  11;
const int   COMPOST                        =  12;
const int   APRICORN                       =  13;
const int   HGSS_BERRY                     =  14;
const int   XY_BERRY                       =  15;
const int   ORAS_BERRY                     =  16;

const int   MENU_LIST_COUNT                =  17;
const char* gameMenuList[MENU_LIST_COUNT]  =  { "Breed",
                                                "Name",               // X
                                                "EV Train",
                                                "Level Train",        // X
                                                "Soft Reset",
                                                "Catch Pokemon",      // X
                                                "Pickup",             // X
                                                "Release",
                                                "Basic Analysis",
                                                "Advanced Analysis",
                                                "Wonder Trade",       // X
                                                "Chain Fish",         // X
                                                "Manage Berries",     // X
                                                "Produce Compost",    // Only with XY
                                                "Gather Apricorns"    // Only with HGSS
                                              };

/*
 *  Basic Analysis is defined as:
 *    Nature
 *    Ability
 *    Moves
 *    Level
 *    Ball
 *    Shiny
 *    PokeRus
 *    Gender
 *
 *  Advanced Analysis is defined as:
 *    EVs
 *    IVs
 *      Known
 *      Time Machine Method
 *      IV Judge (all emcompassed-Potential,reading,high,low)
 *    Characteristic
 *    Hidden Power
 */

int indexGameMenu[GAME_COUNT][MENU_LIST_COUNT] =  { {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1}, // O.Ruby / A. Sapphire
                                                    {0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1}, // X / Y
                                                    {0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1}, // Black 2 / White 2
                                                    {0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1}, // Black / White
                                                    {0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 1, 0}, // H.Gold / S.Silver
                                                    {0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1}, // Platinum
                                                    {0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1}, // Diamond / Pearl
                                                    {0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1}, // F.Red / L.Green
                                                    {0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1}, // Emerald
                                                    {0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 1, 1, 1, 1}  // Ruby / Sapphire
                                                    };

/*****************************************************/
/* BREED ROUTINE                                     */
/*****************************************************/

const char* breedMenu[3]                      =  { "Continue",
                                                   "Options",
                                                   "Instructions"
                                                 };

const char* breedInst[11]                     =  { "Leave the breeding",
                                                   " pair in the Battle",
                                                   " Resort Day Care.",
                                                   "Place Flame Body:",
                                                   "  Fletchinder",
                                                   "  Talonflame",
                                                   "  Volcarona",
                                                   " with Fly in empty",
                                                   " party.",
                                                   "Initiate routine in",
                                                   " Battle Resort."
                                                 };

const char* parentTitle[2]                   =  { "Father", "Mother"       };

const int   parentListCnt                    =  6;
const char* parentList[parentListCnt]        =  { "Pokemon",
                                                  "Nature",
                                                  "Item",
                                                  "IVs",
                                                  "Nationality"
                                                };

const int   natureListCnt                    =  26;
const char* natureList[natureListCnt]        =  { "-",
                                                  "Adamant",
                                                  "Bashful",
                                                  "Bold",
                                                  "Brave",
                                                  "Calm",
                                                  "Careful",
                                                  "Docile",
                                                  "Gentle",
                                                  "Hardy",
                                                  "Hasty",
                                                  "Impish",
                                                  "Jolly",
                                                  "Lax",
                                                  "Lonely",
                                                  "Mild",
                                                  "Modest",
                                                  "Naive",
                                                  "Naughty",
                                                  "Quiet",
                                                  "Quirky",
                                                  "Rash",
                                                  "Relaxed",
                                                  "Sassy",
                                                  "Serious",
                                                  "Timid"
                                                };


const int   breedItemsCnt                     =  19;
const char* breedItems[breedItemsCnt]         =  { "-",
                                                   "Destiny Knot",
                                                   "Everstone",
                                                   "Power Weight",
                                                   "Power Bracer",
                                                   "Power Belt",
                                                   "Power Lens",
                                                   "Power Band",
                                                   "Power Anklet",
                                                   "Light Ball",
                                                   "Full Incense",
                                                   "Lax Incense",
                                                   "Luck Incense",
                                                   "Odd Incense",
                                                   "Pure Incense",
                                                   "Rock Incense",
                                                   "Rose Incense",
                                                   "Sea Incense",
                                                   "Wave Incense"
                                                 };

const int   NationalityCnt                    =  8;
const char* Nationality[NationalityCnt]       =  { "-",
                                                   "English",
                                                   "Japanese",
                                                   "French",
                                                   "Spanish",
                                                   "German",
                                                   "Italian",
                                                   "Korean"
                                                 };

const int   FATHER                             =  0;
const int   MOTHER                             =  1;

const int   PARENT_SPECIE                      =  0;
const int   PARENT_NATURE                      =  1;
const int   PARENT_ITEM                        =  2;
const int   PARENT_IV                          =  3;
const int   PARENT_NATION                      =  4;

const int   NATURE                             =  0;
const int   ITEM                               =  1;
const int   NATION                             =  2;

const int   ParentInfoCnt                      =  3;
int         ParentInfoTemp[ParentInfoCnt][2];
int         ParentInfo[ParentInfoCnt][2];

const int   ParentNameCnt                      = 11;
char        Father[ParentNameCnt];
char        Mother[ParentNameCnt];

int         FatherCnt;
int         MotherCnt;

const int   IVCnt                              = 6;
int         ParentIV[IVCnt][2];

int         IVList[3][2];
const int   HP                                 = 0;
const int   ATK                                = 1;
const int   DEF                                = 2;
const int   SATK                               = 3;
const int   SDEF                               = 4;
const int   SPD                                = 5;

const int   Dark                               = 270;
int         Light                              = 670;

int         partyCnt;
int         hatchCnt;
int         collectCnt;
int         keepParty;
int         keepHatch;
int         keepCollect;
int         selectNum;
int         resetNote;

int         in_out;

/*****************************************************/
/* NAME ROUTINE                                      */
/*****************************************************/
/*****************************************************/
/* EV TRAIN ROUTINE                                  */
/*****************************************************/
/*****************************************************/
/* LEVEL TRAIN ROUTINE                               */
/*****************************************************/
/*****************************************************/
/* SOFT RESET ROUTINE                                */
/*****************************************************/
/*****************************************************/
/* CATCH ROUTINE                                     */
/*****************************************************/
/*****************************************************/
/* PICKUP ROUTINE                                    */
/*****************************************************/
/*****************************************************/
/* RELEASE ROUTINE                                   */
/*****************************************************/
/*****************************************************/
/* BASIC ANALYSIS ROUTINE                            */
/*****************************************************/
/*****************************************************/
/* ADVANCED ANALYSIS ROUTINE                         */
/*****************************************************/
/*****************************************************/
/* WONDER TRADE ROUTINE                              */
/*****************************************************/
/*****************************************************/
/* CHAIN FISH ROUTINE                                */
/*****************************************************/
/*****************************************************/
/* BERRIES ROUTINE                                   */
/*****************************************************/
/*****************************************************/
/* COMPOST ROUTINE                                   */
/*****************************************************/
/*****************************************************/
/* APRICORNS ROUTINE                                 */
/*****************************************************/
/******************************************************************/
/* ACCOUNT MANAGEMENT                                             */
/******************************************************************/
/******************************************************************/
/* SD CARD MANAGEMENT                                             */
/******************************************************************/
/******************************************************************/
/* SETTINGS MANAGEMENT                                            */
/******************************************************************/
/******************************************************************/
/* MENU CREATION MANAGEMENT                                       */
/******************************************************************/

const int   NO_LOOP                        =  0;
const int   LOOP                           =  1;
const int   REVERSE_LOOP                   =  2;
const int   FORWARD_LOOP                   =  3;

int         Masuda;
int         MasudaCon;

int         SELECT[LCD_X];

int         Manual[10][2]                  =  {   {1  , 1},         // Up
  {19 , 2},         // A
  {1  , 3},         // Down
  {18 , 3},         // B
  {0  , 2},         // Left
  {18 , 1},         // X
  {2  , 2},         // Right
  {17 , 2},         // Y
  {10 , 2},         // Start
  {8  , 2}
};  // Select

/*****************************************************/
/* CUSTOM CHARACTERS                                 */
/*****************************************************/

const int   CURSOR                         =  0;
const int   UPWARD                         =  1;
const int   DOWNWARD                       =  2;
const int   ZERO                           =  3;
const int   THIRTY                         =  4;
const int   THIRTYONE                      =  5;
const int   NULLMARKER                     =  6;

byte  Cursor[8]                            =  {   B10000,
                                                  B11000,
                                                  B11100,
                                                  B11110,
                                                  B11100,
                                                  B11000,
                                                  B10000
                                              };

byte  Upward[8]                            =  {   B00000,
                                                  B00000,
                                                  B00100,
                                                  B01110,
                                                  B11111,
                                                  B00000,
                                                  B00000
                                              };

byte  Downward[8]                          =  {   B00000,
                                                  B00000,
                                                  B11111,
                                                  B01110,
                                                  B00100,
                                                  B00000,
                                                  B00000
                                              };

byte  Zero[8]                              =  {   B00000,
                                                  B01110,
                                                  B10001,
                                                  B10001,
                                                  B10001,
                                                  B01110,
                                                  B00000
                                              };

byte  Thirty[8]                            =  {   B00000,
                                                  B01110,
                                                  B11111,
                                                  B11111,
                                                  B10001,
                                                  B01110,
                                                  B00000
                                              };

byte  ThirtyOne[8]                         =  {   B00000,
                                                  B01110,
                                                  B11111,
                                                  B11111,
                                                  B11111,
                                                  B01110,
                                                  B00000
                                              };

byte  NullMarker[8]                        =  {   B00000,
                                                  B01110,
                                                  B10101,
                                                  B11111,
                                                  B10101,
                                                  B01110,
                                                  B00000
                                              };

/******************************************************************/
/* MISCELLANIOUS                                                  */
/******************************************************************/

int         i;
int         j;
int         k;

const int   STOP                           =  -1;

/**************************************************************************************/
/* INITIALIZATION                                                                     */
/**************************************************************************************/

LiquidCrystal lcd(RS, E, D4, D5, D6, D7);

Servo         servoA;
Servo         servoB;
Servo         servoC;
Servo         servoD;
Servo         servoE;

File pokedex;

void setup() {

  Serial.begin(9600);

  pinMode(_UP, INPUT);
  pinMode(_DOWN, INPUT);
  pinMode(_LEFT, INPUT);
  pinMode(_RIGHT, INPUT);
  pinMode(_A, INPUT);
  pinMode(_B, INPUT);
  pinMode(_X, INPUT);
  pinMode(_Y, INPUT);
  pinMode(_HOME, INPUT);
  pinMode(_RESET, INPUT);
  pinMode(MAN, INPUT);

  lcd.begin(LCD_X, LCD_Y);

  SD.begin(CS);

  pinMode(PHOTO, INPUT);

  servoA.attach(SERVO_A);
  servoB.attach(SERVO_B);
  servoC.attach(SERVO_C);
  servoD.attach(SERVO_D);
  servoE.attach(SERVO_E);

  CloseAll();

  lcd.createChar(CURSOR, Cursor);
  lcd.createChar(UPWARD, Upward);
  lcd.createChar(DOWNWARD, Downward);
  lcd.createChar(ZERO, Zero);
  lcd.createChar(THIRTY, Thirty);
  lcd.createChar(THIRTYONE, ThirtyOne);
  lcd.createChar(NULLMARKER, NullMarker);
}

void loop() {

  initMenu();

  //SDStartup();

  //SearchPokemon(0,0);
  //SearchPokemonNum(0,0);
  //while (1);

  //Serial.println(phot());
}

/**************************************************************************************/
/* MENU FUNCTIONS                                                                     */
/**************************************************************************************/

/******************************************************************/
/* HOME MENU                                                      */
/******************************************************************/

void initMenu() {

  clearLine(LCD_Y);
  setScreen("Welcome", 1000, 0, 0, STOP);

  SDStartup();

  menu(SELECT_GAME);
}

void menu(int start) {

  int _POS = start;

  clearLine(LCD_Y);

  _POS = setList(menuList, "Home", OPEN_LIST, 0);//, MENU, SELECT_GAME);

  if (MenuBack) {

    MenuBack = 0;

    menu(SELECT_GAME);
  }

  switch (_POS) {

    case SELECT_GAME :

      gameIndexMenu(ORAS);

    case ACCOUNTS :

      error(1, 1000, ACCOUNTS);
      menu(1);

    case SD_MANAGE :

      error(1, 1000, SD_MANAGE);
      menu(2);

    case SETTINGS :

      error(1, 1000, SETTINGS);
      menu(3);

    default :

      menu(SELECT_GAME);
  }
}

void gameIndexMenu(int start) {

  int _POS = start;

  clearLine(LCD_Y);
  _POS = setList(indexGame, "Select a Game:", GAME_COUNT, start);//, MENU, SELECT_GAME);

  if (MenuBack) {

    MenuBack = 0;

    menu(SELECT_GAME);
  }

  routineMenu(_POS);
}

void routineMenu(int start) {

  const char* _GAME_INDEX[MENU_LIST_COUNT];

  int _SEND_ON[MENU_LIST_COUNT];

  int _CNT = 0;
  int _POS;

  clearLine(LCD_Y);

  for (i = 0; i < MENU_LIST_COUNT; i++) {

    if (indexGameMenu[start][i] == 0) {

      _GAME_INDEX[_CNT] = gameMenuList[i];
      _SEND_ON[i] = i;

      _CNT++;
    }
  }

  _CNT--;

  clearLine(LCD_Y);
  _POS = setList(_GAME_INDEX, indexGame[start], _CNT, _POS);//, GAME_MENU, start);

  if (MenuBack) {

    MenuBack = 0;

    gameIndexMenu(start);
  }

  if (_SEND_ON[_POS] == BREED) {

    initBreed(0);
  }
  else if (_SEND_ON[_POS] == NAME) {

    error(1, 1000, _SEND_ON[_POS]);
    routineMenu(_POS);
  }
  else if (_SEND_ON[_POS] == EV_TRAIN) {

    error(1, 1000, _SEND_ON[_POS]);
    routineMenu(_POS);
  }
  else if (_SEND_ON[_POS] == LEVEL_TRAIN) {

    error(1, 1000, _SEND_ON[_POS]);
    routineMenu(_POS);
  }
  else if (_SEND_ON[_POS] == SOFT_RESET) {

    error(1, 1000, _SEND_ON[_POS]);
    routineMenu(_POS);
  }
  else if (_SEND_ON[_POS] == CATCH) {

    error(1, 1000, _SEND_ON[_POS]);
    routineMenu(_POS);
  }
  else if (_SEND_ON[_POS] == PICKUP) {

    error(1, 1000, _SEND_ON[_POS]);
    routineMenu(_POS);
  }
  else if (_SEND_ON[_POS] == RELEASE) {

    initRelease(0);
  }
  else if (_SEND_ON[_POS] == BASIC_ANALYSIS) {

    error(1, 1000, _SEND_ON[_POS]);
    routineMenu(_POS);
  }
  else if (_SEND_ON[_POS] == ADVANCED_ANALYSIS) {

    error(1, 1000, _SEND_ON[_POS]);
    routineMenu(_POS);
  }
  else if (_SEND_ON[_POS] == WONDER_TRADE) {

    error(1, 1000, _SEND_ON[_POS]);
    routineMenu(_POS);
  }
  else if (_SEND_ON[_POS] == CHAIN_FISH) {

    error(1, 1000, _SEND_ON[_POS]);
    routineMenu(_POS);
  }
  /*if (_SEND_ON[_POS] == BERRIES){

      error(1,1000,_SEND_ON[_POS]);
      routineMenu(_POS);
  }*/
  else if (_SEND_ON[_POS] == COMPOST) {

    error(1, 1000, _SEND_ON[_POS]);
    routineMenu(_POS);
  }
  else if (_SEND_ON[_POS] == APRICORN) {

    error(1, 1000, _SEND_ON[_POS]);
    routineMenu(_POS);
  }
}

/**************************************************************************************/
/* BREED ROUTINE                                                                      */
/**************************************************************************************/

void initBreed(int start) {

  clearLine(LCD_Y);

  for (i = 0; i < IVCnt; i++) {

    for (j = 0; j < 2; j++) {

      ParentIV[i][j] = 2;
    }
  }
  for (i = 0; i < 3; i++) {

    for (j = 0; j < 2; j++) {

      ParentInfoTemp[i][j] = NULL;
    }
  }
  for (i = 0; i < ParentNameCnt; i++) {

    Father[i] = NULL;
    Mother[i] = NULL;
  }

  MasudaCon = 0;

  int _POS = start;
  int _pos = 0;

  _POS = setList(breedMenu, "Start Breed Routine", 3, 0);

  if (MenuBack) {

    MenuBack = 0;

    routineMenu(start);
  }

  if (_POS == 0) {

    ParentInfoSD();

    userBreedStart();
  }
  else if (_POS == 1) {

    breedOpt(0);
  }
  else if (_POS == 2) {

    _pos = setList(breedInst, "Instructions", 11, 0);

    if (MenuBack) {

      MenuBack = 0;

      initBreed(_POS);
    }
  }
}
void breedOpt(int start) {

  int _POS = start;
  int hold = 0;

  clearLine(LCD_Y);

  setScreen("Father", 0, 1, 0, 0);
  setScreen("Mother", 0, 1, 1, 0);
  setScreen("X: Save", 0, 10, 2, 0);
  setScreen("Y: Cancel", 0, 10, 3, 0);

  while (hold == 0) {

    button();

    setCharacter(CURSOR, 0, _POS);

    if (Press[up] == 1 || Press[down]) {

      if (_POS == 0) {

        _POS = 1;

        setScreen(" ", 0, 0, 0, STOP);
      }
      else {

        _POS = 0;

        setScreen(" ", 0, 0, 1, STOP);
      }
    }

    if (Press[x]) {

      ParentInfoSD();

      if (ParentInfoTemp[NATION][FATHER] != 0 && ParentInfoTemp[NATION][MOTHER] != 0) {

        if (ParentInfoTemp[NATION][FATHER] != ParentInfoTemp[NATION][MOTHER]) {

          MasudaCon = 1;
        }
        else {

          MasudaCon = 0;
        }
      }

      userBreedStart();
    }
    else if (Press[y]) {

      userBreedStart();
    }
    else if (Press[a]) {

      Parent(_POS, 0);
    }
    else if (Press[b]) {

      initBreed(1);
    }
  }
}
void ParentInfoSD() {

  pokedex = SD.open("Breed.txt", FILE_WRITE);

  pokedex.println("#========================================#");
  pokedex.println("| Parental Information                                                              |");
  pokedex.println("#========================================#");
  pokedex.println("| Father                                                                                    |");
  pokedex.println("#----------------------------------------------------------------------#");
  pokedex.print("Pokemon:      ");
  pokedex.println(Father);
  pokedex.print("Nature:          ");
  pokedex.println(natureList[ParentInfoTemp[NATURE][FATHER]]);
  pokedex.print("Item:              ");
  pokedex.println(breedItems[ParentInfoTemp[ITEM][FATHER]]);
  pokedex.print("IVs:               ");

  for (i = 0; i < 6; i++) {

    if (ParentIV[i][FATHER] == 0) {

      pokedex.print("00");
    }
    else if (ParentIV[i][FATHER] == 1) {

      pokedex.print("30");
    }
    else if (ParentIV[i][FATHER] == 2) {

      pokedex.print("xx");
    }
    else if (ParentIV[i][FATHER] == 3) {

      pokedex.print("31");
    }

    if (i < 5) {

      pokedex.print("/");
    }
    else if (i == 5) {

      pokedex.println();
    }
  }

  pokedex.print("Nationality:    ");
  pokedex.println(Nationality[ParentInfoTemp[NATION][FATHER]]);

  pokedex.println("#----------------------------------------------------------------------#");
  pokedex.println("| Mother                                                                                   |");
  pokedex.println("#----------------------------------------------------------------------#");
  pokedex.print("Pokemon:      ");
  pokedex.println(Mother);
  pokedex.print("Nature:          ");
  pokedex.println(natureList[ParentInfoTemp[NATURE][MOTHER]]);
  pokedex.print("Item:              ");
  pokedex.println(breedItems[ParentInfoTemp[ITEM][MOTHER]]);
  pokedex.print("IVs:               ");

  for (i = 0; i < 6; i++) {

    if (ParentIV[i][MOTHER] == 0) {

      pokedex.print("00");
    }
    else if (ParentIV[i][MOTHER] == 1) {

      pokedex.print("30");
    }
    else if (ParentIV[i][MOTHER] == 2) {

      pokedex.print("xx");
    }
    else if (ParentIV[i][MOTHER] == 3) {

      pokedex.print("31");
    }

    if (i < 5) {

      pokedex.print("/");
    }
    else if (i == 5) {

      pokedex.println();
    }
  }

  pokedex.print("Nationality:    ");
  pokedex.println(Nationality[ParentInfoTemp[NATION][MOTHER]]);

  pokedex.println("#========================================#");

  pokedex.close();
}
void Parent(int parent, int start) {

  int _POS = start;
  int hold = 0;

  while (hold == 0) {

    _POS = setList(parentList, parentTitle[parent], parentListCnt, 0);

    if (MenuBack) {

      MenuBack = 0;

      breedOpt(parent);
    }

    if (_POS == PARENT_SPECIE) {

      PokemonSelect(parent);
    }
    else if (_POS == PARENT_NATURE) {

      NatureSelect(parent);
    }
    else if (_POS == PARENT_ITEM) {

      ItemSelect(parent);
    }
    else if (_POS == PARENT_IV) {

      IVSelect(parent);
    }
    else if (_POS == PARENT_NATION) {

      NationSelect(parent);
    }
  }
}
void PokemonSelect(int parent) {

  int hold = 1;

  clearLine(LCD_Y);

  setScreen("What is the", 0, 0, 0, STOP);
  setScreen("?", 0, 18, 0, STOP);

  if (parent == FATHER) {

    setScreen("father", 0, 12, 0, STOP);
  }
  else {

    setScreen("mother", 0, 12, 0, STOP);
  }

  SearchPokemonNum(4, 2, 1);

  clearLine(LCD_Y);

  setScreen("Is this the correct", 0, 0, 0, STOP);
  setScreen("Pokemon?", 0, 0, 1, STOP);
  setScreen("A: Confirm", 0, 8, 2, STOP);
  setScreen("B: Cancel", 0, 8, 3, STOP);

  lcd.setCursor(9, 1);
  lcd.write(PokedexList);

  while (hold) {

    button();

    if (Press[a]) {

      if (parent == FATHER) {

        FatherCnt = 0;

        for (i = 0; i < 11; i++) {

          Father[i] = PokedexList[i];

          if (PokedexList[i] != NULL) {

            FatherCnt++;
          }

          PokedexList[i] = NULL;
        }
      }
      if (parent == MOTHER) {

        MotherCnt = 0;

        for (i = 0; i < 11; i++) {

          Mother[i] = PokedexList[i];

          if (PokedexList[i] != NULL) {

            MotherCnt++;
          }

          PokedexList[i] = NULL;
        }
      }

      for (i = 0; i < 3; i++) {

        SELECT[i] = 0;
      }

      hold = 0;

      delay(200);
    }
    if (Press[b]) {

      for (i = 0; i < 11; i++) {

        PokedexList[i] = NULL;
      }
      for (i = 0; i < 3; i++) {

        SELECT[i] = 0;
      }

      hold = 0;
      delay(200);
    }
  }

  Parent(parent, 0);
}
void NatureSelect(int parent) {

  ParentInfoTemp[NATURE][parent] = setList(natureList, "Nature", natureListCnt, 0);

  MenuBack = 0;
  Parent(parent, 1);
}
void ItemSelect(int parent) {

  ParentInfoTemp[ITEM][parent] = setList(breedItems, "Item", breedItemsCnt, 0);

  MenuBack = 0;
  Parent(parent, 2);
}
void IVSelect(int parent) {

  int cursorPos[3][2] = {{1, 0}, {0, 0}, {0, 0}};
  int cursorX[6]     = {0, 9, 0, 9, 0, 9};
  int cursorY[6]     = {1, 1, 2, 2, 3, 3};
  int cursorP[6]     = {8, 18, 8, 18, 8, 18};
  int cursorQ[3]     = {1, 2, 3};
  int marker[4]      = {ZERO, THIRTY, NULLMARKER, THIRTYONE};

  const int SetIV[9][6]  = { {0, 0, 0, 0, 0, 0},
    {3, 3, 3, 3, 3, 2},
    {3, 3, 3, 2, 3, 3},
    {3, 2, 3, 3, 3, 3},
    {2, 2, 2, 2, 2, 2},
    {3, 0, 3, 3, 3, 3},
    {3, 3, 3, 0, 3, 3},
    {3, 3, 3, 3, 3, 0},
    {3, 3, 3, 3, 3, 3}
  };

  int UD             = 0;
  int LR             = 0;
  int cnt            = 0;
  int IVcnt          = 4;
  int IVkeep         = 0;

  int hold     = 1;
  int keep     = 1;
  int holdA    = 0;
  int keepA    = 1;

  IVList[0][0] = ParentIV[0][parent];
  IVList[0][1] = ParentIV[1][parent];
  IVList[1][0] = ParentIV[2][parent];
  IVList[1][1] = ParentIV[3][parent];
  IVList[2][0] = ParentIV[4][parent];
  IVList[2][1] = ParentIV[5][parent];

  clearLine(LCD_Y);

  setScreen("IVs", 0, 9, 0, STOP);

  if (parent == FATHER) {

    setScreen("Father's", 0, 0, 0, STOP);
  }
  else {

    setScreen("Mother's", 0, 0, 0, STOP);
  }

  setScreen("HP", 0, 1, 1, STOP);
  setScreen("Atk", 0, 10, 1, STOP);
  setScreen("Def", 0, 1, 2, STOP);
  setScreen("S.Atk", 0, 10, 2, STOP);
  setScreen("S.Def", 0, 1, 3, STOP);
  setScreen("Spd", 0, 10, 3, STOP);

  while (hold) {

    button();

    if (keep) {

      cnt = 0;

      for (i = 0; i < 3; i++) {

        for (j = 0; j < 2; j++) {

          setScreen(" ", 0, cursorX[cnt], cursorY[cnt], STOP);

          setCharacter(marker[IVList[i][j]], cursorP[cnt], cursorY[cnt]);

          cursorPos[i][j] = 0;

          cnt++;
        }
      }

      cnt  = 0;

      cursorPos[UD][LR] = 1;

      for (i = 0; i < 3; i++) {

        for (j = 0; j < 2; j++) {

          if (cursorPos[i][j]) {

            setCharacter(CURSOR, cursorX[cnt], cursorY[cnt]);

            i = 3;
            j = 2;
          }

          cnt++;
        }
      }

      keep = 0;
    }
    else if (IVkeep) {

      IVkeep = 0;

      for (i = 0; i < 6; i++) {

        setCharacter(marker[SetIV[IVcnt][i]], cursorP[i], cursorY[i]);
      }
    }

    if (Press[start]) {

      j = 0;

      ParentIV[0][parent] = IVList[0][0];
      ParentIV[1][parent] = IVList[0][1];
      ParentIV[2][parent] = IVList[1][0];
      ParentIV[3][parent] = IVList[1][1];
      ParentIV[4][parent] = IVList[2][0];
      ParentIV[5][parent] = IVList[2][1];

      hold = 0;
    }
    if (Press[select]) {

      hold = 0;
    }

    if (Press[up]) {

      delay(100);

      UD = Toggle(UD, _UP, 3, LOOP);

      keep = 1;
    }
    else if (Press[down]) {

      delay(100);

      UD = Toggle(UD, _DOWN, 3, LOOP);

      keep = 1;
    }
    if (Press[left]) {

      delay(200);

      LR = Toggle(LR, _LEFT, 2, LOOP);

      keep = 1;
    }
    else if (Press[right]) {

      delay(200);

      LR = Toggle(LR, _RIGHT, 2, LOOP);

      keep = 1;
    }
    else if (Press[x]) {

      IVcnt++;

      if (IVcnt == 9) {

        IVcnt = 8;
      }

      IVkeep = 1;

      delay(100);
    }
    else if (Press[y]) {

      IVcnt--;

      if (IVcnt == -1) {

        IVcnt = 0;
      }

      IVkeep = 1;

      delay(100);
    }
    else if (Press[a]) {

      holdA = 1;
      delay(200);

      setScreen(" ", 0, cursorX[LR], cursorQ[UD], STOP);
      setCharacter(CURSOR, cursorP[LR] - 1, cursorQ[UD]);

      while (holdA) {

        button();

        if (Press[a]) {

          holdA = 0;
        }

        if (Press[up]) {

          delay(200);

          IVList[UD][LR] = Toggle(IVList[UD][LR], _DOWN, 4, NO_LOOP);

          keepA = 1;
        }
        else if (Press[down]) {

          delay(200);

          IVList[UD][LR] = Toggle(IVList[UD][LR], _UP, 4, NO_LOOP);

          keepA = 1;
        }

        if (keepA) {

          setCharacter(marker[IVList[UD][LR]], cursorP[LR], cursorQ[UD]);

          keepA = 0;
        }
      }

      delay(200);

      setScreen(" ", 0, cursorP[LR] - 1, cursorQ[UD], STOP);
      setCharacter(CURSOR, cursorX[LR], cursorQ[UD]);
    }
    else if (Press[b]) {

      Parent(parent, 3);
    }
  }

  Parent(parent, 3);
}
void NationSelect(int parent) {

  ParentInfoTemp[NATION][parent] = setList(Nationality, "Nationality", NationalityCnt, 0);

  MenuBack = 0;
  Parent(parent, 4);
}
void userBreedStart() {

  int hold           = 0;

  selectNum          = 0;
  partyCnt           = 0;

  clearLine(LCD_Y);

  setScreen("How many eggs?", 0, 0, 0, STOP);
  setScreen("A: Start", 0, 11, 2, STOP);
  setScreen("B: Cancel", 0, 11, 3, STOP);

  selectNumber(3, 7, 2, INIT_BREED, 0);

  selectNum = 100 * SELECT[0] + 10 * SELECT[1] + SELECT[2];

  if (selectNum == 0) {

    clearLine(LCD_Y);

    setScreen("Do you wish to", 0, 0, 0, STOP);
    setScreen("continue?  If not,", 0, 0, 1, STOP);
    setScreen("press B when the", 0, 0, 2, STOP);
    setScreen("menu reloads.", 0, 0, 3, STOP);

    delay(5000);

    userBreedStart();
  }

  partyCheck();
}
void partyCheck() {

  int hold = 0;

  clearLine(LCD_Y);

  setScreen("Start Party Eggs:", 0, 0, 0, STOP);

  while (hold == 0) {

    setNumber(partyCnt, 0, 14, 2, STOP);

    setCharacter(UPWARD, 14, 1);
    setCharacter(DOWNWARD, 14, 3);

    button();

    while (digitalRead(MAN) == HIGH) {

      manualControl();
    }

    if (Press[up]) {

      partyCnt++;

      if (partyCnt == 6) {

        partyCnt = 0;
      }
    }
    else if (Press[down]) {

      partyCnt--;

      if (partyCnt == -1) {

        partyCnt = 5;
      }
    }

    if (Press[a]) {

      hold = 1;
    }

    if (Press[b]) {

      userBreedStart();
    }
  }

  cycle();
}
void cycle() {

  hatchCnt       = 0;
  collectCnt     = selectNum;

  in_out         = 0;

  int cycleCnt   = 0;
  int startCnt   = 0;
  int runCnt     = 0;
  int pressServo = 0;

  clearLine(LCD_Y);

  setScreen("Eggs in party:", 0, 0, 0, STOP);
  setScreen("Eggs Hatched:", 0, 0, 2, STOP);
  setScreen("Eggs Remaining:", 0, 0, 3, STOP);

  setNumber(partyCnt, 0, 19, 0, STOP);
  countHatched();
  countRemaining();

  pokedex = SD.open("Breed.txt", FILE_WRITE);

  pokedex.println();
  pokedex.print("Eggs requested for hatching: ");
  pokedex.println(collectCnt);
  pokedex.print("Eggs already held: ");
  pokedex.println(partyCnt);
  pokedex.println();

  pokedex.close();

  if (partyCnt == 5) {

    resetPosition();

    Y(push);
    Up(push);
  }

  while (collectCnt > 0) {

    /*
     * Routine Starts Here
     */

    while (digitalRead(MAN)) {

      //ControlPanel();
    }

    if (partyCnt < 5 && hatchCnt + partyCnt < selectNum) {

      collectEgg(resetNote);

      CloseAll();

      Left(15 * push);

      if (phot() < Light) {

        eggHatch();
      }

      Up(3000 * push);

      if (phot() < Light) {

        eggHatch();
      }
    }
    else {

      Left(13 * push);

      if (phot() < Light) {

        eggHatch();
      }

      while (phot() > Light) {

        Up(0);
      }

      CloseE();

      eggHatch();
    }
  }

  pokedex = SD.open("Breed.txt", FILE_WRITE);

  pokedex.println();
  pokedex.println("#========================================#");
  pokedex.println(" Project completed successfully.");
  pokedex.print("Eggs hatched: ");
  pokedex.println(hatchCnt);
  pokedex.println("#========================================#");
  pokedex.println();

  initBreed(0);
}
void resetPosition() {

  int resetCnt   = 0;
  int cnt        = 0;
  int branch     = 0;

  resetNote = 1;

  for (i=0;i<15;i++){

      if (phot()-20 < Light){

          Light = phot()-20;
      }
  }

  CloseAll();

  X(push);
  A(push);

  delay(1300);

  A(push);

  Down(push);
  A(push);
  A(push);

  delay(1300);

  A(push);

  delay(12275);

  while (digitalRead(MAN)) {

    //ControlPanel();
  }
}
void collectEgg(int resetVal) {

  int collCnt = 0;
  int recCnt = 0;
  int cnt = 0;

  if (partyCnt > 5) {

    return;
  }
  if (resetVal == 0) {

    resetPosition();
  }

  CloseAll();

  Y(push);

  Up(push);

  Right(8 * push);

  if (phot() < Light) {

    eggHatch();
  }

  pokedex = SD.open("Breed.txt", FILE_WRITE);

  pokedex.println("Checking for a new egg...");

  A(push);

  delay(500);

  while (digitalRead(MAN)) {

    //ControlPanel();
  }

  while (phot() < Light) {

    A(push);

    cnt++;

    if (cnt == 6) {

      delay(3500);

      partyCnt++;

      setNumber(partyCnt, 0, 19, 0, STOP);

      pokedex.println("...a new egg has been found.");

      keepParty = 0;
    }
  }

  if (cnt < 6) {

    pokedex.println("...no new egg was found");
  }

  pokedex.print("Eggs held: ");
  pokedex.println(partyCnt);

  pokedex.close();

  resetNote = 0;
}
void eggHatch() {

  int resetCnt = 0;
  int trackLR  = 0;
  int trackUD  = 1;

  hatching();

  resetPosition();

  while (digitalRead(MAN)) {

    //ControlPanel();
  }

  Up(push * 2);

  delay(3000);

  Up(push);

  Right(2 * push);
  Up(6 * push);

  while (digitalRead(MAN)) {

    //ControlPanel();
  }

  deposit();

  Left(2 * push);
  Down(8 * push);

  delay(2600);

  while (digitalRead(MAN)) {

    //ControlPanel();
  }

  if (phot() < Light) {

    eggHatch();
  }

  if (partyCnt + hatchCnt == selectNum) {

    Y(push);
    Up(push);
  }
}

void hatching() {

  A(push);

  delay(19000);

  B(push);

  delay(2800);

  while (digitalRead(MAN)) {

    //ControlPanel();
  }

  collectCnt--;
  hatchCnt++;

  countRemaining();
  countHatched();

  pokedex = SD.open("Breed.txt", FILE_WRITE);

  pokedex.println("An egg has hatched!");
  pokedex.println("Depositing egg");
  pokedex.println();
  pokedex.print("Eggs remaining: ");
  pokedex.println(collectCnt);
  pokedex.print("Eggs hatched: ");
  pokedex.println(hatchCnt);
  pokedex.println();

  pokedex.close();

  if (MasudaCon) {

    Masuda++;

    BasicWrite();
  }
}

void deposit() {

  A(push);

  delay(1900);

  for (i = 0; i < 3; i++) {

    A(push);
  }

  delay(2100);

  Right(push);

  for (i = 0; i < 2; i++) {

    A(push);
  }

  if (hatchCnt % 30 == 1 && hatchCnt > 1) {

    Right(push);
  }

  A(push);

  partyCnt--;

  setNumber(partyCnt, 0, 19, 0, STOP);

  X(push);

  delay(2700);

  while (digitalRead(MAN)) {

    //ControlPanel();
  }
}

void countRemaining() {

  if (collectCnt > 99) {

    setNumber(collectCnt, 0, 17, 3, STOP);
  }
  else if (collectCnt > 9) {

    setNumber(collectCnt, 0, 18, 3, STOP);
    setScreen(" ", 0, 17, 3, STOP);
  }
  else {

    setNumber(collectCnt, 0, 19, 3, STOP);
    setScreen("  ", 0, 17, 3, STOP);
  }
}

void countHatched() {

  if (hatchCnt > 99) {

    setNumber(hatchCnt, 0, 17, 2, STOP);
  }
  else if (hatchCnt > 9) {

    setNumber(hatchCnt, 0, 18, 2, STOP);
  }
  else {

    setNumber(hatchCnt, 0, 19, 2, STOP);
  }
}

void ControlPanel() {

  /*
   * Find a way to integrate:
   *
   *    - Manual Controls
   *    - Adjustments to eggs to collect, eggs hatched, and eggs in party
   *    - Prompts to reset position, and collect or deposit an egg
   *    - The ability to reset the value of a sensor
   *    - The ability to exit the program completely
   */
}

/**************************************************************************************/
/* RELEASE ROUTINE                                                                    */
/**************************************************************************************/

void initRelease(int start) {

  clearLine(LCD_Y);

  int _POS = start;
  int _pos = 0;

  _POS = setList(breedMenu, "Start Releasing?", 3, 0);

  if (MenuBack) {

    MenuBack = 0;

    routineMenu(RELEASE);
  }

  if (_POS == 0) {

    userReleaseStart();
  }
  else if (_POS == 1) {

    breedOpt(0);
  }
  else if (_POS == 2) {

    _pos = setList(breedInst, "Instructions", 11, 0);

    if (MenuBack) {

      MenuBack = 0;

      initRelease(2);
    }
  }
}

void userReleaseStart() {

  clearLine(LCD_Y);

  setScreen("How many Pokemon?", 0, 0, 0, STOP);
  setScreen("A: Start", 0, 11, 2, STOP);
  setScreen("B: Cancel", 0, 11, 3, STOP);

  selectNumber(3, 7, 2, INIT_BREED, 0);

  selectNum = 100 * SELECT[0] + 10 * SELECT[1] + SELECT[2];

  if (selectNum == 0) {

    userReleaseStart();
  }

  ORASRelease();
}
void ORASRelease() {

  int UD = 1;
  int LR = 1;
  int box = 1;

  int _push = 5 * push / 4;

  clearLine(LCD_Y);

  setScreen("Remaining", 0, 0, 0, STOP);
  setScreen("Position", 0, 0, 1, STOP);
  setScreen("X:", 0, 13, 1, STOP);
  setScreen("Y:", 0, 13, 2, STOP);
  setScreen("Box", 0, 13, 3, STOP);

  while (selectNum > 0) {

    if (selectNum > 99) {

      setNumber(selectNum, 0, 17, 0, STOP);
    }
    else if (selectNum > 9) {

      setNumber(selectNum, 0, 18, 0, STOP);
      setScreen(" ", 0, 17, 0, STOP);
    }
    else {

      setNumber(selectNum, 0, 19, 0, STOP);
      setScreen("  ", 0, 17, 0, STOP);
    }

    setNumber(LR, 0, 19, 1, STOP);
    setNumber(UD, 0, 19, 2, STOP);

    if (box > 9) {

      setNumber(box, 0, 18, 3, STOP);
    }
    else {

      setNumber(box, 0, 19, 3, STOP);
    }

    /*
     * Routine Start
     */

    A(_push);
    Up(push);
    Up(push);
    A(_push);
    Up(push);
    A(_push);

    delay(1000);
    selectNum--;

    A(_push);
    A(_push);

    LR++;

    if (LR == 7) {

      UD++;

      if (UD == 6) {

        UD = 1;
        box++;

        for (i = 0; i < 5; i++) {

          Up(push);
        }

        Right(push);
        Down(push);
      }
      else {

        Down(push);

        for (i = 0; i < 5; i++) {

          Left(push);
        }
      }

      LR = 1;
    }
    else {

      Right(push);
    }
  }
}

/**************************************************************************************/
/* PRESSING MECHANISMS                                                                */
/**************************************************************************************/

void Up(int DELAY) {

  servoE.write(_UP_);

  if (DELAY > 0) {

    delay(DELAY);
    CloseE();
  }
}
void Down(int DELAY) {

  servoD.write(_DOWN_);

  if (DELAY > 0) {

    delay(DELAY);
    CloseD();
  }
}
void Left(int DELAY) {

  servoE.write(_LEFT_);

  if (DELAY > 0) {

    delay(DELAY);
    CloseE();
  }
}
void Right(int DELAY) {

  servoD.write(_RIGHT_);

  if (DELAY > 0) {

    delay(DELAY);
    CloseD();
  }
}
void A(int DELAY) {

  servoA.write(_A_);

  if (DELAY > 0) {

    delay(DELAY);
    CloseA();
  }
}
void B(int DELAY) {

  servoB.write(_B_);

  if (DELAY > 0) {

    delay(DELAY);
    CloseB();
  }
}
void X(int DELAY) {

  servoA.write(_X_);

  if (DELAY > 0) {

    delay(DELAY);
    CloseA();
  }
}
void Y(int DELAY) {

  servoB.write(_Y_);

  if (DELAY > 0) {

    delay(DELAY);
    CloseB();
  }
}
void Home(int DELAY) {

  servoC.write(_HOME_);

  if (DELAY > 0) {

    delay(DELAY);
    CloseC();
  }
}
void Reset(int DELAY) {

  servoC.write(_RESET_);

  if (DELAY > 0) {

    delay(DELAY);
    CloseC();
  }
}
void CloseA() {

  servoA.write(_CLOSE_A);
  delay(push);
}
void CloseB() {

  servoB.write(_CLOSE_B);
  delay(push);
}
void CloseC() {

  servoC.write(_CLOSE_C);
  delay(push);
}
void CloseD() {

  servoD.write(_CLOSE_D);
  delay(push);
}
void CloseE() {

  servoE.write(_CLOSE_E);
  delay(push);
}
void CloseAll() {

  servoA.write(_CLOSE_A);
  servoB.write(_CLOSE_B);
  servoC.write(_CLOSE_C);
  servoD.write(_CLOSE_D);
  servoE.write(_CLOSE_E);
  delay(push);
}

/**************************************************************************************/
/* MENU MANAGEMENT FUNCTIONS                                                          */
/**************************************************************************************/

int button() {

  int set = 0;

  for (i = 0; i < NUMBER_BUTTON; i++) {

    if (digitalRead(_UP + i) == HIGH) {

      Press[i] = 1;

      if (digitalRead(MAN) == HIGH) {

        manualControl();
      }
    }
    else {

      Press[i] = 0;
    }
  }

  for (i = 0; i < NUMBER_BUTTON; i++) {

    set += Press[i];
  }

  if (digitalRead(MAN) == HIGH) {

    Press[manual] = 1;
  }
  if (digitalRead(MAN) == LOW) {

    Press[manual] = 0;
  }

  delay(PUSH);

  if (set > 0) {

    return 1;
  }
  else if (Press[10] == 1) {

    return 2;
  }
  else {

    return 0;
  }
}

void clearLine(int type) {

  if (type != STOP) {

    lcd.clear();
  }
}

void setScreen(const char* string, int t, int pos_x, int pos_y, int type) {

  lcd.setCursor(pos_x, pos_y);

  lcd.print(string);

  if (t != 0) {

    delay(t);
    clearLine(type);
  }
}

void reset() {

  for (i = 0; i < NUMBER_BUTTON; i++) {

    Press[i] = 0;
  }
}

void error(int Error, int error_delay, int pos) {

  lcd.clear();

  if (Error == 1) {

    setScreen("Error 1:", 0, 0, 0, 0);
    setScreen("This section has not", 0, 0, 1, 1);
    setScreen("yet been written", 0, 0, 2, 2);
  }

  delay(error_delay);
}

int Toggle (int DirVal, int dir, int Max, int state) {

  if (dir == _UP || dir == _LEFT) {

    DirVal--;

    if (DirVal < 0) {

      if (state == NO_LOOP || state == REVERSE_LOOP) {

        DirVal = 0;
      }
      else if (state == LOOP || state == FORWARD_LOOP) {

        DirVal = Max - 1;
      }
    }
  }
  else if (dir == _DOWN || dir == _RIGHT) {

    DirVal++;

    if (DirVal >= Max) {

      if (state == NO_LOOP || state == REVERSE_LOOP) {

        DirVal = Max - 1;
      }
      else if (state == LOOP || state == FORWARD_LOOP) {

        DirVal = 0;
      }
    }
  }

  return DirVal;
}

int setList(const char* show[], const char* header, int listCnt, int startPos) {

  /*
   listCnt  =  The number of elements in Show[]
   startPos =  The position of the cursor on the current menu
   */

  int     _POS = startPos;
  int     touch = 1;
  int     hold = 0;
  int     tempPos;
  int     BGN = 1;

  while (hold == 0) {

    if (BGN) {

      setScreen(header, 0, 0, 0, LCD_Y);
    }
    if (button() || BGN) {

      BGN = 0;

      tempPos = _POS;

      if (Press[up]) {

        touch = 1;

        _POS = Toggle(_POS, _UP, listCnt, LOOP);
      }
      else if (Press[down]) {

        touch = 1;

        _POS = Toggle(_POS, _DOWN, listCnt, LOOP);
      }

      PositionList(show, header, listCnt, _POS, touch);

      if (Press[a] || Press[right]) {

        delay(200);

        hold = 1;
      }

      if (Press[b] || Press[left]) {

        MenuBack = 1;
        hold     = 1;

        delay(200);
      }
    }
    while (digitalRead(MAN) == HIGH) {

      manualControl();
    }

    touch = 0;
  }

  //lcd.clear();
  reset();

  return _POS;
}

void setCharacter(int Byte, int pos_x, int pos_y) {

  lcd.setCursor(pos_x, pos_y);
  lcd.write(byte(Byte));
}

void setNumber(int num, int t, int pos_x, int pos_y, int type) {

  lcd.setCursor(pos_x, pos_y);

  lcd.print(num);

  if (t != 0) {

    delay(t);
    clearLine(type);
  }
}
/*
void buttonTest(int vis){

    if (vis == 1){

        for (i=0;i<10;i++){

            setCharacter(OFF,Manual[i][0],Manual[i][1]);
        }

        while (button() > 0){

            for (i=0;i<10;i++){

                if (Press[i] == 1){

                    setCharacter(ON,Manual[i][0],Manual[i][1]);
                }
                else{

                    setCharacter(OFF,Manual[i][0],Manual[i][1]);
                }
            }

            if (Press[up] == Press[down]){

                Press[up]      =0;
                Press[down]    =0;
            }
            if (Press[left] == Press[right]){

                Press[up]      =0;
                Press[down]    =0;
            }
        }
    }
}
*/
void PositionList(const char* show[], const char* header, int listCnt, int _POS, int touch) {

  if (_POS == 0 && touch == 1) {

    lcd.clear();
    setScreen(header, 0, 0, 0, STOP);

    setScreen(show[0], 0, 1, 1, 1);
    setScreen(show[1], 0, 1, 2, 2);
    setScreen(show[2], 0, 1, 3, 3);

    setScreen(" ", 0, 0, 2, STOP);
    setScreen(" ", 0, 0, 3, STOP);

    setCharacter(CURSOR, 0, 1);
  }
  else if (_POS == listCnt - 1 && touch == 1) {

    lcd.clear();
    setScreen(header, 0, 0, 0, STOP);

    setScreen(show[listCnt - 3], 0, 1, 1, 1);
    setScreen(show[listCnt - 2], 0, 1, 2, 2);
    setScreen(show[listCnt - 1], 0, 1, 3, 3);

    setScreen(" ", 0, 0, 1, STOP);
    setScreen(" ", 0, 0, 2, STOP);

    setCharacter(CURSOR, 0, 3);
  }
  else if (touch == 1) {

    lcd.clear();
    setScreen(header, 0, 0, 0, STOP);

    setScreen(show[_POS - 1], 0, 1, 1, 1);
    setScreen(show[_POS], 0, 1, 2, 2);
    setScreen(show[_POS + 1], 0, 1, 3, 3);

    setScreen(" ", 0, 0, 1, STOP);
    setScreen(" ", 0, 0, 3, STOP);

    setCharacter(CURSOR, 0, 2);
  }
}

void manualControl() {

  while (digitalRead(_A) == HIGH ^ digitalRead(_X)) {

    if (digitalRead(_A) == HIGH) {

      A(0);
    }
    else {

      X(0);
    }
  }
  CloseA();

  while (digitalRead(_B) == HIGH ^ digitalRead(_Y)) {

    if (digitalRead(_B) == HIGH) {

      B(0);
    }
    else {

      Y(0);
    }
  }

  CloseB();

  while (digitalRead(_HOME) == HIGH ^ digitalRead(_RESET)) {

    if (digitalRead(_HOME) == HIGH) {

      Home(0);
    }
    else {

      Reset(0);
    }
  }

  CloseC();

  while (digitalRead(_DOWN) == HIGH ^ digitalRead(_RIGHT)) {

    if (digitalRead(_DOWN) == HIGH) {

      Down(0);
    }
    else {

      Right(0);
    }
  }

  CloseD();

  while (digitalRead(_UP) == HIGH ^ digitalRead(_LEFT)) {

    if (digitalRead(_UP) == HIGH) {

      Up(0);
    }
    else {

      Left(0);
    }
  }

  CloseE();
}

int phot() {

  return analogRead(PHOTO);
}

void selectNumber(int Size, int pos_x, int pos_y, int returnMenu, int type) {

  int cursorPos[Size];
  int selectPos      = 0;
  int hold           = 0;
  int keepUD         = 0;
  int keepLR         = 0;

  selectNum          = 0;

  for (i = 0; i < LCD_X; i++) {

    SELECT[i] = 0;
  }

  for (i = 0; i < Size; i++) {

    cursorPos[i] = 0;
  }

  cursorPos[0] = 1;

  while (hold == 0) {

    while (digitalRead(MAN) == HIGH) {

      manualControl();
    }

    if (keepUD == 0) {

      for (i = 0; i < Size; i++) {

        setNumber(SELECT[i], 0, pos_x + i, pos_y, STOP);
      }

      keepUD = 1;
    }

    if (button() && Press[left] == 1) {

      selectPos = Toggle(selectPos, _LEFT, Size, LOOP);

      keepLR = 0;
    }
    else if (button() && Press[right] == 1) {

      selectPos = Toggle(selectPos, _RIGHT, Size, LOOP);

      keepLR = 0;
    }
    else if (Press[up] == 1) {

      SELECT[selectPos]++;

      if (selectPos == 0 && SELECT[0] > 9) {

        SELECT[0] = 0;
      }
      if (selectPos == 1 && SELECT[1] > 9) {

        SELECT[0]++;
        SELECT[1] = 0;

        if (SELECT[0] > 9) {

          SELECT[0] = 0;
        }
      }
      if (selectPos == 2 && SELECT[2] > 9) {

        SELECT[1]++;
        SELECT[2] = 0;

        if (SELECT[1] > 9) {

          SELECT[0]++;
          SELECT[1] = 0;
        }
        if (SELECT[0] > 9) {

          SELECT[0] = 0;
        }
      }

      keepUD = 0;
    }
    else if (Press[down] == 1) {

      SELECT[selectPos]--;

      if (selectPos == 0 && SELECT[0] < 0) {

        SELECT[0] = 0;
      }
      if (selectPos == 1 && SELECT[1] < 0) {

        SELECT[1] = 9;
        SELECT[0]--;

        if (SELECT[0] < 0) {

          SELECT[0] = 0;
        }
      }
      if (selectPos == 2 && SELECT[2] < 0) {

        SELECT[2] = 9;
        SELECT[1]--;

        if (SELECT[1] < 0) {

          SELECT[1] = 9;
          SELECT[0]--;
        }
        if (SELECT[0] < 0) {

          SELECT[0] = 9;
        }
      }

      keepUD = 0;
    }
    else if (Press[a] == 1) {

      hold = 1;
    }
    else if (Press[b] == 1) {

      if (returnMenu == INIT_BREED) {

        initBreed(0);
      }
    }

    for (i = 0; i < Size; i++) {

      cursorPos[i] = 0;
    }

    cursorPos[selectPos] = 1;

    if (keepLR == 0) {

      if (type == 0) {

        for (i = 0; i < Size; i++) {

          setScreen(" ", 0, pos_x + i, pos_y - 1, STOP);
          setScreen(" ", 0, pos_x + i, pos_y + 1, STOP);
        }

        setCharacter(UPWARD, pos_x + selectPos, pos_y - 1);
        setCharacter(DOWNWARD, pos_x + selectPos, pos_y + 1);
      }
      else if (type == 1) {

        for (i = 0; i < Size; i++) {

          setScreen(" ", 0, pos_x + i, pos_y + 1, STOP);
        }

        setCharacter(UPWARD, pos_x + selectPos, pos_y + 1);
      }

      keepLR = 1;
    }
  }
}

void SearchPokemonNum(int pos_x, int pos_y, int limit) {

  int Char;
  int cnt    = 0;

  for (i = 0; i < 11; i++) {

    PokedexList[i] = NULL;
  }

  while (SELECT[0] + SELECT[1] + SELECT[2] == 0 && limit) {

    selectNumber(3, pos_x, pos_y, 1, 1);
  }

  if (SELECT[0] * 100 + SELECT[1] * 10 + SELECT[2] > TOTAL_POKEMON) {

    SELECT[0] = 7;
    SELECT[1] = 2;
    SELECT[2] = 1;
  }

  for (i = 0; i < 3; i++) {

    NatNumSearch[i] = SELECT[i];
  }

  Serial.print(" ");

  pokedex = SD.open("Pokedex.txt");

  if (!pokedex.available()) {

    clearLine(LCD_Y);

    setScreen("Error Reading Card", 0, 0, 0, STOP);
  }

  else {

    while (pokedex.available()) {

      if (pokedex.read() == NatNumSearch[0] + '0') {

        if (pokedex.read() == NatNumSearch[1] + '0') {

          if (pokedex.read() == NatNumSearch[2] + '0') {

            pokedex.read();

            for (i = 0; i < 11; i++) {

              Char = pokedex.read();

              if (Char == 13 || Char == -1) {

                i = 11;
              }
              else {

                PokedexList[i] = Char;
                cnt++;
              }
            }
          }
        }
      }
    }

    setScreen("   ", 0, pos_x, pos_y - 1, 0);
    setScreen("   ", 0, pos_x, pos_y + 1, 0);
    setScreen(PokedexList, 0, pos_x + 4, pos_y, 0);
  }

  pokedex.close();
}

void SDStartup() {

  int Char;

  pokedex = SD.open("Basic.txt");

  while (pokedex.available()) {

    if (pokedex.read() == 'M') {

      if (pokedex.read() == 'a') {

        if (pokedex.read() == 's') {

          if (pokedex.read() == 'u') {

            if (pokedex.read() == 'd') {

              if (pokedex.read() == 'a') {

                if (pokedex.read() == ' ') {

                  while (pokedex.available()) {

                    Char = pokedex.read();

                    if (Char != -1) {

                      Masuda = Masuda * 10 + Char - '0';
                    }
                  }
                }
              }
            }
          }
        }
      }
    }
  }
}

void BasicWrite() {

  SD.remove("Basic.txt");

  pokedex = SD.open("Basic.txt", FILE_WRITE);

  pokedex.print("Masuda ");
  pokedex.print(Masuda);

  pokedex.close();
}

/*void SearchPokemon(int pos_x,int pos_y){

  int Char;
  int cnt    =0;
  int hold   =0;
  int MaxCnt =26;
  int keep   =1;
  int reset  =1;
  int halt   =1;
  int change =0;

  int pressX =0;
  int pressY =0;

  int Upper  =1;
  int Lower  =0;
  int Number =0;
  int tempU  =0;
  int tempL  =0;

  int posRom =0;
  int posNum =0;

  int _POS   =0;
  int _POSLR =pos_x;
  int counter    =0;

  char CharAdd='A';

  lcd.clear();

  for (i=0;i<11;i++){

    PokedexList[i]=' ';
  }

  setCharacter(UPWARD,pos_x,pos_y+1);

  while (hold == 0){

    button();

    if (reset){

      SearchDex(cnt,pos_x,pos_y);

      if (counter > 0){

        _POS=PokedexList[counter]-CharAdd;
      }

      reset=0;

      lcd.setCursor(_POSLR,pos_y);
      lcd.write(_POS+CharAdd);
    }

    if (Press[up]){

      SearchDex(cnt,pos_x,pos_y);

      if (_POS > MaxCnt){

        _POS=0;
      }

      _POS=Toggle(_POS,_DOWN,MaxCnt,LOOP);

      reset=1;
    }
    else if (Press[down]){

      SearchDex(cnt,pos_x,pos_y);

      if (_POS > MaxCnt){

        _POS=0;
      }

      _POS=Toggle(_POS,_UP,MaxCnt,LOOP);

      reset=1;
    }

    else if (Press[x]){

      keep   =1;
      pressX =1;

      if (Upper){

        Upper=0;
        Lower=1;
      }
      else {

        Upper=1;
        Lower=0;
      }
    }
    else if (Press[y]){

      keep   =1;
      pressY =1;

      if (Number){

        Upper  =tempU;
        Lower  =tempL;
        Number =0;
      }
      else {

        tempU  =Upper;
        tempL  =Lower;

        Upper  =0;
        Lower  =0;
        Number =1;

        posRom =_POS;
      }
    }
    else if (Press[a]){

      _POSLR++;

      if (_POSLR == 11){

        _POSLR=10;
      }

      PokedexList[counter]=_POS+CharAdd;
      counter++;

      reset=1;

      setCharacter(UPWARD,_POSLR,pos_y+1);
      setScreen(" ",0,_POSLR-1,pos_y+1,STOP);
    }
    else if (Press[b]){

      for (i=0;i<11-counter;i++){

        setScreen(" ",0,pos_x,pos_y,STOP);
      }

      for (i=counter;i<11;i++){

        PokedexList[i]=' ';
      }

      lcd.setCursor(pos_x,pos_y);

      for (i=0;i<11;i++){

        lcd.write(PokedexList[i]);
      }

      _POSLR--;

      lcd.setCursor(_POSLR,pos_y);

      if (_POSLR == -1){

        _POSLR=0;
      }

      counter--;

      reset=1;

      setCharacter(UPWARD,_POSLR,pos_y+1);
      setScreen(" ",0,_POSLR+1,pos_y+1,STOP);
    }

    if (pressX || pressY){

      if (pressX){

        MaxCnt   =26;
        pressX   =0;

        if (Upper){

          CharAdd  ='A';
        }
        else if (Lower){

          CharAdd  ='a';
        }
      }
      else {

        MaxCnt   =10;
        pressY   =0;

        CharAdd  ='0';
      }
    }
  }
}

void SearchDex(int limit,int pos_x,int pos_y){

  int initChar;
  int Char;
  int hold   =1;

  pokedex=SD.open("Pokedex.txt");

  if (!pokedex.available()){

    clearLine(LCD_Y);

    setScreen("Error Reading Card",0,0,0,STOP);
  }

  while (pokedex.available() && hold){

    initChar=pokedex.read();

    for (i=10;i >= 0;i--){

      if (initChar == PokedexList[i] && i == limit){

        for (j=i+1;j<11;j++){

          Char=pokedex.read();

          if (Char == 13 || Char == -1){

            j=11;
          }
          else {

            PokedexList[j]=Char;
          }
        }

        hold=0;
      }
    }
  }

  pokedex.close();

  lcd.setCursor(pos_x,pos_y);
  lcd.write(PokedexList);
}*/
