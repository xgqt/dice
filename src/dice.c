/*************************************************/
/* Copyright (c) 2020 XGQT <xgqt@protonmail.com> */
/* Licensed under the GNU GPL v3 license         */
/*************************************************/


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>


static char * dice_1 =
    "  _______  \n"
    " |       | \n"
    " |   o   | \n"
    " |       | \n"
    " '-------' \n";

static char * dice_2 =
    "  _______  \n"
    " | o     | \n"
    " |       | \n"
    " |     o | \n"
    " '-------' \n";

static char * dice_3 =
    "  _______  \n"
    " | o     | \n"
    " |   o   | \n"
    " |     o | \n"
    " '-------' \n";

static char * dice_4 =
    "  _______  \n"
    " | o   o | \n"
    " |       | \n"
    " | o   o | \n"
    " '-------' \n";

static char * dice_5 =
    "  _______  \n"
    " | o   o | \n"
    " |   o   | \n"
    " | o   o | \n"
    " '-------' \n";

static char * dice_6 =
    "  _______  \n"
    " | o   o | \n"
    " | o   o | \n"
    " | o   o | \n"
    " '-------' \n";

static char ** die_face = NULL;

static char * long_help =
    "Usage: dice [OPTION]... [NUMBER]\n"
    "Rolls some dice. \n"
    "\n"
    "Options:\n"
    "    -h                  Print short help\n"
    "           --help       Print long help\n"
    "    -v     --version    Print version number\n"
    "    -s     --small      Roll small dice\n"
    "    -0     --none       Only generate numbers\n"
    "\n"
    "Bugs: <https://gitlab.com/xgqt/dice/>\n"
    "Home: <https://gitlab.com/xgqt/dice/>\n"
    "Copyright (c) 2020, XGQT\n"
    "Licensed under the GNU GPL v3 license\n";

static char * short_help =
    "Usage: dice NUMBER\n";

static char * version =
    "dice version 1.0, (c) 2020 XGQT\n";


int generate_number ( void )
{
    // rand() % (max_number + 1 - minimum_number) + minimum_number
    return rand() % 6 + 1;
}


void roll_dice ( void )
{
   size_t random_int = generate_number() - 1;

   if(die_face == NULL)
       {
           die_face = malloc( sizeof( char* ) * 6 );

           die_face[0] = dice_1;
           die_face[1] = dice_2;
           die_face[2] = dice_3;
           die_face[3] = dice_4;
           die_face[4] = dice_5;
           die_face[5] = dice_6;
       }

    puts( die_face[random_int] );
}


// Put it all together
int main ( int argc, char ** argv )
{

    int rolls      = 1;

    int small_roll = 0;
    int none_roll  = 0;

    // Seed
    srand( time(NULL) );


    if ( argc >= 2 )
        {
            for ( int i = 0; i < argc; ++i)
                {
                    // Help
                    if ( ! strcmp(argv[i], "-h") )
                        {
                            puts( short_help );
                            exit(0);
                        }
                    else if ( ! strcmp(argv[i], "--help") )
                        {
                            printf( "%s", long_help );
                            exit(0);
                        }

                    // Version
                    else if ( ( ! strcmp(argv[i], "-v") ) || ( ! strcmp(argv[i], "--version") ) )
                        {
                            puts( version );
                            exit(0);
                        }

                    // Small dice
                    else if ( ( ! strcmp(argv[i], "-s") ) || ( ! strcmp(argv[i], "--small") ) )
                        {
                            small_roll = 1;
                        }

                    // Only numbers
                    else if ( ( ! strcmp(argv[i], "-0") ) || ( ! strcmp(argv[i], "--none") ) )
                        {
                            none_roll = 1;
                        }

                    // Assume other args are numbers
                    else
                        {
                            rolls = strtol( argv[i], NULL, 10 );
                        }
                }

            // Possible input error - guarantee at least 1 roll
            if ( rolls < 1 )
                {
                    rolls = 1;
                }

            // Small dice
            if ( small_roll )
                {
                    for ( int i = 0; i < rolls; i++ )
                        {
                            printf( " [%d]", generate_number() );
                        }
                    printf("\n");
                }
            // Only numbers
            else if ( none_roll )
                {
                    for ( int i = 0; i < rolls; i++ )
                        {
                            printf( " %d", generate_number() );
                        }
                    printf("\n");
                }
            // Normal (big) dice
            else
                {
                    for ( int i = 0; i < rolls; i++ )
                        {
                            roll_dice();
                        }
                }
        }
    else
        {
            roll_dice();
        }


    free(die_face);
    
    
    return 0;
}
