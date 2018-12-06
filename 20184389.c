#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <direct.h>
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
int char_counter(const char sentence[])
{
	const char* temp_sentence = sentence;
	int i, counted=0;
	for(i=0; temp_sentence[i]; i++)
	{
		if(temp_sentence[i] != ' ' && temp_sentence[i] != '\n') counted++;
	}
	return counted;
}
int word_counter(const char sentence[])
{
	int counted = 0, word = 0;
	const char* temp_sentence = sentence;
	do switch(*temp_sentence)
	{
		case('\0'):
		case ' ': case '\t': case '\n': case '\r':
            if (word) { word = 0; counted++; }
            break;
        default: word = 1;
	}while(*temp_sentence++);
	return counted;
}
int main(int argc,char* argv[])
{
	FILE *f1 = fopen(argv[1], "r");
	char *temp_file_name = strtok(argv[1], ".");
	const char *filename = strcat(temp_file_name, ".rev");
	FILE *f2 = fopen(filename, "w");
	int line_count=0, word_count=0, char_count=0, i;
	char temp_file_sentence[300];
	while(fgets(temp_file_sentence, 300, f1)) 
	{
		char_count += char_counter(temp_file_sentence);
		word_count += word_counter(temp_file_sentence);
		line_count++;
		for(i=0; temp_file_sentence[i]; i++)
		{
			if(isalpha(temp_file_sentence[i]))
			{
				if(islower(temp_file_sentence[i])) temp_file_sentence[i] = toupper(temp_file_sentence[i]);
				else if(isupper(temp_file_sentence[i])) temp_file_sentence[i] = tolower(temp_file_sentence[i]);	
			}
		}
		fputs(temp_file_sentence, f2);
	}
	printf("Line : %d\nWord : %d\nChar : %d\n", line_count, word_count, char_count);
	char *directory = _getcwd(NULL,0);
	printf("Saved File as %s in %s", filename, directory);
	return 0;
}


