#include <stdio.h>
#include <string.h>

#define SIZE 20

struct Team
{
	char teamName[SIZE];
	char teamTown[SIZE];
	int teamScore;
};

struct Team SetName();
void ShowInfo(struct Team temp);
void MainSet(struct Team* value, const int length);
void MainShow(struct Team* value, const int length);
void SearchMaximum(struct Team* value, const int length);
int main(void) 
{
	int s = 3;
	struct Team list[3];

	MainSet(&list[0], s);
	MainShow(&list[0], s);
	SearchMaximum(&list[0], s);

  	return 0;
}

struct Team SetName()
{
	struct Team value;

	fprintf(stdout, "Team: ");
	fgets(value.teamName, SIZE, stdin);
	fprintf(stdout, "Town: ");
	fgets(value.teamTown, SIZE, stdin); //fflush(stdin);
	fprintf(stdout, "Score: ");
	scanf("%d", &value.teamScore);getchar();

	return value;
}

void ShowInfo(struct Team temp)
{	
	fprintf(stdout, "\n");
	fprintf(stdout, "Name team: %s", temp.teamName);
	fprintf(stdout, "Name town: %s", temp.teamTown);
	fprintf(stdout, "Score: %d", temp.teamScore);
	fprintf(stdout, "\n");
}

void MainSet(struct Team* value, const int length)
{
	for (int i = 0; i < length; i++)
	{
		value[i] = SetName();
	}
}

void MainShow(struct Team* value, const int length)
{
	for (int i = 0; i < length; i++)
	{
		ShowInfo(value[i]);
	}
}

void SearchMaximum(struct Team* value, const int length)
{
	int maxScoreTeam = value[0].teamScore;
	int teamID;
	
	for (int i = 0; i < length; i++)
	{
		if (value[i].teamScore > maxScoreTeam)
		{
			maxScoreTeam = value[i].teamScore;
			teamID = i;
		}
		
	}
	fprintf(stdout, "\nMax score team: \n");
	ShowInfo(value[teamID]);
}
