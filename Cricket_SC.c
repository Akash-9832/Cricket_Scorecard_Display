#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <stdlib.h>
int n, m, p, x, y, z, a1 = 0, a2 = 0, e1, e2, w1 = 0, w2 = 0, r1, r2, line = 1;
char toss[10], str[30], team1_name[50], team2_name[50], m_name[40], username[50], password[20], pass[20], pass1[20], temp[20], choice, date[15], venue[50];
FILE *fp;
struct team1_batsman
{
  char name[50];
  int runs, balls, ones, twos, threes, fours, sixes, t1_max_run;
  float SR;
} pl1[100], pl2;

struct team1_all
{
  char name[50];
  int runs, ones, twos, threes, fours, sixes, i, balls, overs, wickets, given_run, t1_all_max_run, t1_all_max_w;
  float SR, eco;
} pa1[100], pa11;

struct team1_bowler
{
  char name[50];
  int wickets, given_run, t1_max_w;
  float overs, eco;
} pl3[100], pl4;

struct team2_batsman
{
  char name[50];
  int runs, score, balls, toruns, tobal, ones, twos, threes, fours, sixes, t2_max_run;
  float SR;
} pl5[100], pl6;

struct team2_all
{
  char name[50];
  int runs, ones, twos, threes, fours, sixes, i, balls, overs, wickets, given_run, t2_all_max_run, t2_all_max_w;
  float SR, eco;
} pa2[100], pa22;

struct team2_bowler
{
  char name[50];
  int wickets, given_run, t2_max_w;
  float overs, eco;
} pl7[100], pl8;

void team1();
void team2();
void menu(void);
void first_innings(void);
void second_innings(void);
void match_summary(void);
void post_match(void);

void New()
{
  fp = fopen("Cricket.txt", "w");
  printf("\n\n\t\t\t\t*** Create your Username and password to continue ***\n");
  printf("\nUsername must contain only characters and numbers(E.g: Akash2023, akash_123)");
  printf("\nEnter Username: ");
  scanf("%s", m_name);
  fscanf(fp, "%s", m_name);
  fprintf(fp, "%s\n", m_name);
  fclose(fp);
  printf("\nEnter your Mail ID: ");
  scanf("%s", username);
  fp = fopen("Cricket.txt", "a");
  fscanf(fp, "%s", username);
  fprintf(fp, "%s\n", username);
  fclose(fp);
  printf("\nCreate a strong Password: ");
  scanf("%s", password);
  fp = fopen("Cricket.txt", "a");
  fscanf(fp, "%s", password);
  fprintf(fp, "%s", password);
  fclose(fp);
  system("cls");
  printf("\nKindly Re-enter your password: ");
  scanf("%s", pass);
  if (strcmp(password, pass) == 0)
  {
    printf("\n\t\t\tWelcome back...You are successfully login\n");
    printf("\nEnter the name of first team: ");
    gets(team1_name);
    gets(team1_name);
    printf("\nEnter the name of second team: ");
    gets(team2_name);
    printf("\nDate:- ");
    gets(date);
    printf("\nStadium:- ");
    gets(venue);
    system("cls");
    // printf("Which team won the toss? ");
    // fgets(str,30,stdin);
    // printf("What do you want to do Bat or Bowl? ");
    // scanf("%s",toss);
    // printf("%s won the toss and opts to %s first ",str,toss);
  }
  else
  {
    printf("\n\t\t\t*Warning, Please enter your correct password !!!\n");
    abort();
  }
  fflush(stdin);
}

void Existing()
{
  fp = fopen("Cricket.txt", "r");
  // Read the string from the file
  printf("\nEnter your password: ");
  // gets(pass1);
  // gets(pass1);
  fgets(pass1, 20, stdin);
  fgets(pass1, 20, stdin);
  // Remove the newline character from the end of the input string
  pass1[strcspn(pass1, "\n")] = '\0';
  while (fgets(temp, 20, fp))
  {
    temp[strcspn(temp, "\n")] = '\0';
    if (line == 3)
    {
      if (strcmp(temp, pass1) == 0)
      {
        printf("\n\t\t\tWelcome back...You are successfully login\n");
        printf("\nEnter the name of first team: ");
        gets(team1_name);
        // team1_name[strcspn(team1_name, "\n")] = '\0';
        printf("\nEnter the name of second team: ");
        gets(team2_name);
        printf("\nDate:- ");
        gets(date);
        printf("\nStadium:- ");
        gets(venue);
        system("cls");
      }
      else
      {
        printf("\n\t\t\t*Warning, Please enter your correct password !!!\n");
        abort();
      }
    }
    line += 1;
  }
  fclose(fp);
  fflush(stdin);
}

void t1_batsman(int n)
{
  char arr1[2], arr[2] = "y";
  for (int i = 0; i < n; i++)
  {
    printf("Enter the name of batsman(%d): ", i + 1);
    gets(pl1[i].name);
    gets(pl1[i].name);
    printf("Did %s bat today?(y/n): ", pl1[i].name);
    scanf("%s", &arr1);
    if (strcmp(arr1, arr) == 0)
    {
      printf("Enter the number of ones scored by %s: ", pl1[i].name);
      scanf("%d", &pl1[i].ones);
      printf("Enter the number of twos scored by %s: ", pl1[i].name);
      scanf("%d", &pl1[i].twos);
      printf("Enter the number of threes scored by %s: ", pl1[i].name);
      scanf("%d", &pl1[i].threes);
      printf("Enter the number of fours scored by %s: ", pl1[i].name);
      scanf("%d", &pl1[i].fours);
      printf("Enter the number of sixes scored by %s: ", pl1[i].name);
      scanf("%d", &pl1[i].sixes);
      printf("Enter the balls played by the %s: ", pl1[i].name);
      scanf("%d", &pl1[i].balls);
      pl1[i].runs = (1 * pl1[i].ones + 2 * pl1[i].twos + 3 * pl1[i].threes + 4 * pl1[i].fours + 6 * pl1[i].sixes);
      pl1[i].SR = (pl1[i].runs * 100) / pl1[i].balls;
      printf("Total run made by '%s' is '%d' with strike rate of %.2f\n\n", pl1[i].name, pl1[i].runs, pl1[i].SR);
      a1 += pl1[i].runs;
    }
  }
}

void t1_all_rounder(int p)
{
  char ans[2], ans2[2], ans3[2] = "y";
  for (int k = 0; k < p; k++)
  {
    printf("Enter the name of all-rounder(%d): ", k + 1);
    gets(pa1[k].name);
    gets(pa1[k].name);
    printf("Did %s bat today?(y/n): ", pa1[k].name);
    scanf("%s", ans);
    if (strcmp(ans, ans3) == 0)
    {
      printf("Enter the number of ones scored by %s: ", pa1[k].name);
      scanf("%d", &pa1[k].ones);
      printf("Enter the number of twos scored by %s: ", pa1[k].name);
      scanf("%d", &pa1[k].twos);
      printf("Enter the number of threes scored by %s: ", pa1[k].name);
      scanf("%d", &pa1[k].threes);
      printf("Enter the number of fours scored by %s: ", pa1[k].name);
      scanf("%d", &pa1[k].fours);
      printf("Enter the number of sixes scored by %s: ", pa1[k].name);
      scanf("%d", &pa1[k].sixes);
      printf("Enter the balls played by the %s: ", pa1[k].name);
      scanf("%d", &pa1[k].balls);
      pa1[k].runs = (1 * pa1[k].ones + 2 * pa1[k].twos + 3 * pa1[k].threes + 4 * pa1[k].fours + 6 * pa1[k].sixes);
      pa1[k].SR = (pa1[k].runs * 100) / pa1[k].balls;
      printf("Total run made by '%s' is '%d' with strike rate of %.2f\n\n", pa1[k].name, pa1[k].runs, pa1[k].SR);
      a1 += pa1[k].runs;
    }
    printf("Did %s bowl today?(y/n): ", pa1[k].name);
    scanf("%s", ans2);
    if (strcmp(ans2, ans3) == 0)
    {
      printf("Enter the number overs bowled by %s: ", pa1[k].name);
      scanf("%d", &pa1[k].overs);
      printf("Enter the number of wickets taken by %s: ", pa1[k].name);
      scanf("%d", &pa1[k].wickets);
      printf("Enter the runs given by the %s: ", pa1[k].name);
      scanf("%d", &pa1[k].given_run);
      pa1[k].eco = pa1[k].given_run / pa1[k].overs;
      printf("The economy of '%s' is: %.2f\n\n", pa1[k].name, pa1[k].eco);
      w1 += pa1[k].wickets;
    }
  }
}

void t1_bowler(int m)
{
  char arr2[2], arr[2] = "y";
  for (int j = 0; j < m; j++)
  {
    printf("Enter the name of bowler(%d): ", j + 1);
    gets(pl3[j].name);
    gets(pl3[j].name);
    printf("Did %s bowl today?(y/n): ", pl3[j].name);
    scanf("%s", &arr2);
    if (strcmp(arr2, arr) == 0)
    {
      printf("Enter the number overs bowled by %s: ", pl3[j].name);
      scanf("%f", &pl3[j].overs);
      printf("Enter the number of wickets taken by %s: ", pl3[j].name);
      scanf("%d", &pl3[j].wickets);
      printf("Enter the runs given by the %s: ", pl3[j].name);
      scanf("%d", &pl3[j].given_run);
      pl3[j].eco = pl3[j].given_run / pl3[j].overs;
      printf("The economy of '%s' is: %.2f\n", pl3[j].name, pl3[j].eco);
      w1 += pl3[j].wickets;
    }
  }
}

void t2_batsman(int x)
{
  char arr3[2], arr[2] = "y";
  for (int i = 0; i < x; i++)
  {
    printf("Enter the name of batsman(%d): ", i + 1);
    gets(pl5[i].name);
    gets(pl5[i].name);
    printf("Did %s bat today?(y/n): ", pl5[i].name);
    scanf("%s", &arr3);
    if (strcmp(arr3, arr) == 0)
    {
      printf("Enter the number of ones scored by %s: ", pl5[i].name);
      scanf("%d", &pl5[i].ones);
      printf("Enter the number of twos scored by %s: ", pl5[i].name);
      scanf("%d", &pl5[i].twos);
      printf("Enter the number of threes scored by %s: ", pl5[i].name);
      scanf("%d", &pl5[i].threes);
      printf("Enter the number of fours scored by %s: ", pl5[i].name);
      scanf("%d", &pl5[i].fours);
      printf("Enter the number of sixes scored by %s: ", pl5[i].name);
      scanf("%d", &pl5[i].sixes);
      printf("Enter the balls played by the %s: ", pl5[i].name);
      scanf("%d", &pl5[i].balls);
      pl5[i].runs = (1 * pl5[i].ones + 2 * pl5[i].twos + 3 * pl5[i].threes + 4 * pl5[i].fours + 6 * pl5[i].sixes);
      pl5[i].SR = (pl5[i].runs * 100) / pl5[i].balls;
      printf("Total run made by '%s' is '%d' with strike rate of %.2f\n\n", pl5[i].name, pl5[i].runs, pl5[i].SR);
      a2 += pl5[i].runs;
    }
  }
}

void t2_all_rounder(int y)
{
  char ans[2], ans2[2], ans3[2] = "y";
  for (int i = 0; i < y; i++)
  {
    printf("Enter the name of all-rounder(%d): ", i + 1);
    gets(pa2[i].name);
    gets(pa2[i].name);
    printf("Did %s bat today?(y/n): ", pa2[i].name);
    scanf("%s", &ans);
    if (strcmp(ans, ans3) == 0)
    {
      printf("Enter the number of ones scored by %s: ", pa2[i].name);
      scanf("%d", &pa2[i].ones);
      printf("Enter the number of twos scored by %s: ", pa2[i].name);
      scanf("%d", &pa2[i].twos);
      printf("Enter the number of threes scored by %s: ", pa2[i].name);
      scanf("%d", &pa2[i].threes);
      printf("Enter the number of fours scored by %s: ", pa2[i].name);
      scanf("%d", &pa2[i].fours);
      printf("Enter the number of sixes scored by %s: ", pa2[i].name);
      scanf("%d", &pa2[i].sixes);
      printf("Enter the balls played by the %s: ", pa2[i].name);
      scanf("%d", &pa2[i].balls);
      pa2[i].runs = (1 * pa2[i].ones + 2 * pa2[i].twos + 3 * pa2[i].threes + 4 * pa2[i].fours + 6 * pa2[i].sixes);
      pa2[i].SR = (pa2[i].runs * 100) / pa2[i].balls;
      printf("Total run made by '%s' is '%d' with strike rate of %.2f\n\n", pa2[i].name, pa2[i].runs, pa2[i].SR);
      a2 += pl5[i].runs;
    }
    printf("Did %s bowl today?(y/n): ", pa2[i].name);
    scanf("%s", &ans2);
    if (strcmp(ans2, ans3) == 0)
    {
      printf("Enter the number overs bowled by %s: ", pa2[i].name);
      scanf("%d", &pa2[i].overs);
      printf("Enter the number of wickets taken by %s: ", pa2[i].name);
      scanf("%d", &pa2[i].wickets);
      printf("Enter the runs given by the %s: ", pa2[i].name);
      scanf("%d", &pa2[i].given_run);
      pa2[i].eco = pa2[i].given_run / pa2[i].overs;
      printf("The economy of '%s' is: %.2f\n", pa2[i].name, pa2[i].eco);
      w2 += pa2[i].wickets;
    }
  }
}

void t2_bowler(int z)
{
  char arr4[2], arr[2] = "y";
  for (int j = 0; j < z; j++)
  {
    printf("\nEnter the name of bowler(%d): ", j + 1);
    gets(pl7[j].name);
    gets(pl7[j].name);
    printf("Did %s bowl today?(y/n): ", pl7[j].name);
    scanf("%s", &arr4);
    if (strcmp(arr4, arr) == 0)
    {
      printf("Enter the number overs bowled by %s: ", pl7[j].name);
      scanf("%f", &pl7[j].overs);
      printf("Enter the number of wickets taken by %s: ", pl7[j].name);
      scanf("%d", &pl7[j].wickets);
      printf("Enter the runs given by the %s: ", pl7[j].name);
      scanf("%d", &pl7[j].given_run);
      pl7[j].eco = pl7[j].given_run / pl7[j].overs;
      printf("The economy of '%s' is: %.2f\n", pl7[j].name, pl7[j].eco);
      w2 += pl7[j].wickets;
    }
  }
}

int main()
{
  printf("\n\t\t\t\t.......WELCOME TO CRICKET WORLD.......\n");
  printf("1. New User\n\n");
  printf("2. Existing User\n");
  printf("\nPress '1' for New User  or  Press '2' for Existing User: ");
  scanf("%c", &choice);
  if (choice == '1')
  {
    New();
  }
  else if (choice == '2')
  {
    Existing();
  }
  else
  {
    printf("\n\t\tPlease enter either '1' or '2'");
    abort();
  }
  sleep(1);
  for (int k = 10; k >= 1; k--)
  {
    system("cls");
    printf("\n\n\n\n\t\t\t\t\t\t\t\t\tThe game will start soon... %d ", k);
    sleep(1);
  }
  system("cls");
  printf("\n\t\t\t\t\tCreate the team for '%s'\n\n", team1_name);
  printf("\nEnter the number of batsman: ");
  scanf("%d", &n);
  t1_batsman(n);
  printf("\nEnter the number of all-rounders: ");
  scanf("%d", &p);
  t1_all_rounder(p);
  printf("\nEnter the number of bowlers: ");
  scanf("%d", &m);
  t1_bowler(m);
  printf("\nExtras: ");
  scanf("%d", &e1);
  printf("No. of Runout: ");
  scanf("%d", &r1);
  system("cls");
  printf("\n\t\t\t\t\tCreate the team for '%s'\n\n", team2_name);
  printf("\nEnter the number of batsman: ");
  scanf("%d", &x);
  t2_batsman(x);
  printf("\nEnter the number of all-rounders: ");
  scanf("%d", &y);
  t2_all_rounder(y);
  printf("\nEnter the number of bowlers: ");
  scanf("%d", &z);
  t2_bowler(z);
  printf("\nExtras: ");
  scanf("%d", &e2);
  printf("No. of Runouts: ");
  scanf("%d", &r2);
  system("cls");
  menu();
  return 0;
}

void menu(void)
{
  int choice2;
  do
  {
    printf("\n\n\t\t\t****** CRICKET SCORE CARD SYSTEM ******\n");
    printf("1. First Team Playing-XI\n");
    printf("2. Second Team Playing-XI\n");
    printf("3. 1st Innings\n");
    printf("4. 2nd Innings\n");
    printf("5. Match Summary\n");
    printf("6. Post Match Presentation\n");
    printf("7. Exit\n");
    printf("What do you want to see?\n");
    printf("Enter your choice: ");
    scanf("%d", &choice2);
    switch (choice2)
    {
    case 1:
      team1();
      break;
    case 2:
      team2();
      break;
    case 3:
      first_innings();
      break;
    case 4:
      second_innings();
      break;
    case 5:
      match_summary();
      break;
    case 6:
      post_match();
      break;
    case 7:
      printf("\t\t\nHope you will come back again...\n\n");
      break;
      abort();
    default:
      printf("Invalid Choice!");
    }
  } while (choice2 != 6);
}

void team1()
{
  for (int i = 0; i < n; i++)
  {
    printf("\n\t\t%s", pl1[i].name);
  }
  for (int k = 0; k < p; k++)
  {
    printf("\n\t\t%s", pa1[k].name);
  }
  for (int j = 0; j < m; j++)
  {
    printf("\n\t\t%s", pl3[j].name);
  }
}

void team2()
{
  for (int i = 0; i < x; i++)
  {
    printf("\n\t\t%s", pl5[i].name);
  }
  for (int i = 0; i < y; i++)
  {
    printf("\n\t\t%s", pa2[i].name);
  }
  for (int j = 0; j < z; j++)
  {
    printf("\n\t\t%s", pl7[j].name);
  }
}

void first_innings(void)
{
  printf("\n\n\t                   *********FIRST INNINGS*********\n\n");
  printf("                          Batting of %s\n", team1_name);
  printf("============================================================================\n");
  printf(" Batter        Runs           Balls          4s         6s            S/R   \n");
  printf("============================================================================\n");
  for (int i = 0; i < n; i++)
  {
    printf(" %-15s %-14d %-13d %-11d %-11d %-9.2f\n\n", pl1[i].name, pl1[i].runs, pl1[i].balls, pl1[i].fours, pl1[i].sixes, pl1[i].SR);
  }
  for (int k = 0; k < p; k++)
  {
    printf(" %-15s %-14d %-13d %-11d %-11d %-9.2f\n\n", pa1[k].name, pa1[k].runs, pa1[k].balls, pa1[k].fours, pa1[k].sixes, pa1[k].SR);
  }

  printf("                         Bowling of %s\n", team2_name);
  printf("=====================================================================\n");
  printf(" Bowler          Overs        Runs Given        Wicket       Economy\n");
  printf("=====================================================================\n");
  for (int i = 0; i < z; i++)
  {
    printf(" %-15s %-14.1f %-13d %-11d %-9.2f\n\n", pl7[i].name, pl7[i].overs, pl7[i].given_run, pl7[i].wickets, pl7[i].eco);
  }
  for (int j = 0; j < y; j++)
  {
    printf(" %-15s %-14.1f %-13d %-11d %-9.2f\n\n", pa2[j].name, pa2[j].overs, pa2[j].given_run, pa2[j].wickets, pa2[j].eco);
  }
  printf("\n\n\t\t*Total Runs scored by %s: %d/%d\n", team1_name, a1 + e1, w2 + r1);
}

void second_innings(void)
{
  printf("\n\n\t                     *********SECOND INNINGS*********\n\n");
  printf("                          Batting of %s\n", team2_name);
  printf("=============================================================================\n");
  printf(" Batter        Runs           Balls          4s         6s             S/R \n");
  printf("=============================================================================\n");
  for (int i = 0; i < n; i++)
  {
    printf(" %-15s %-14d %-13d %-11d %-11d %-9.2f\n\n", pl5[i].name, pl5[i].runs, pl5[i].balls, pl5[i].fours, pl5[i].sixes, pl5[i].SR);
  }
  for (int i = 0; i < y; i++)
  {
    printf(" %-15s %-14d %-13d %-11d %-11d %-9.2f\n\n", pa2[i].name, pa2[i].runs, pa2[i].balls, pa2[i].fours, pa2[i].sixes, pa2[i].SR);
  }

  printf("                         Bowling of %s\n", team1_name);
  printf("=====================================================================\n");
  printf(" Bowler          Overs         Runs Given        Wicket       Economy\n");
  printf("=====================================================================\n");
  for (int i = 0; i < z; i++)
  {
    printf(" %-15s %-14.1f %-13d %-11d %-9.2f\n\n", pl3[i].name, pl3[i].overs, pl3[i].given_run, pl3[i].wickets, pl3[i].eco);
  }
  for (int k = 0; k < p; k++)
  {
    printf(" %-15s %-14.1f %-13d %-11d %-9.2f\n\n", pa1[k].name, pa1[k].overs, pa1[k].given_run, pa1[k].wickets, pa1[k].eco);
  }
  printf("\n\n\t\t*Total Runs scored by %s: %d/%d", team2_name, a2 + e2, w1 + r2);
}

void match_summary(void)
{
  printf("Stadium:- %s \t\t\t\t\t\t\t\t Date:- %s\n", venue, date);
  printf("\n                                        ******Match Summary******\n\n");
  printf("\t%s                                  \t\t\t%s\n", team1_name, team2_name);
  printf("=======================================\t\t\t\t======================================= \n");
  printf(" Batsman        Runs           Balls   \t\t\t\tBowler         Overs           Wicket   \n");
  printf("=======================================\t\t\t\t======================================= \n");
  for (int j = 0; j < 3; j++)
  {
    printf(" %-15s %-14d %-13d  \t\t\t%-20s %-17.1f %-13d\n\n", pl1[j].name, pl1[j].runs, pl1[j].balls, pl7[j].name, pl7[j].overs, pl7[j].wickets);
  }

  printf("\n\n\t%s                                 \t\t\t%s\n", team2_name, team1_name);
  printf("=======================================\t\t\t\t======================================= \n");
  printf(" Batsman        Runs           Balls   \t\t\t\t Bowler         Overs           Wicket   \n");
  printf("=======================================\t\t\t\t======================================= \n");
  for (int j = 0; j < 3; j++)
  {
    printf(" %-15s %-14d %-13d  \t\t\t%-20s %-17.1f %-13d\n\n", pl5[j].name, pl5[j].runs, pl5[j].balls, pl3[j].name, pl3[j].overs, pl3[j].wickets);
  }
  if ((a1 + e1) > (a2 + e2))
  {
    printf("\n\n\n\t\t\tCongratulation!, %s won the match by %d runs.\n\n", team1_name, ((a1 + e1) - (a2 + e2)));
  }
  else if ((a1 + e1) == (a2 + e2))
  {
    printf("\n\n\t\t\tWow!, Match Draw.\n\n");
  }
  else
  {
    printf("\n\n\n\t\t\tCongratulation!, %s won the match by %d wickets.\n\n", team2_name, (10 - w1));
  }
}

void post_match(void)
{
  // pl4.t1_max_w = 0, pl2.t1_max_run = 0;
  // printf("\n\t\t\t\t-:Post Match Presentation:-\n\n");
  // printf("\n-------- %s --------", team1_name);
  // for (int i = 0; i < n; i++)
  // {
  //   pl1[i].runs = (1 * pl1[i].ones + 2 * pl1[i].twos + 3 * pl1[i].threes + 4 * pl1[i].fours + 6 * pl1[i].sixes);
  //   if (pl2.t1_max_run < pl1[i].runs)
  //   {
  //     pl2.t1_max_run = pl1[i].runs;
  //     printf("\nMan of the match: %s (%d)",pl1[i].name,pl2.t1_max_run);
  //   }
  // }

  printf("Work in progress");
}