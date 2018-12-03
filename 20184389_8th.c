#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct{
	int year;
	int month;
	int date;
}BDAY;

typedef struct{
	char name[20];
	BDAY birthday;
	char gender[4];
	int number;
}STATEMENT;

void swap(STATEMENT *i, STATEMENT *j);
int daychecker(STATEMENT* person);
int bdayexists(BDAY myday);
void sort_bday(STATEMENT** stc_ary, int T);
void sort_name(STATEMENT** stc_ary, int T);
STATEMENT stscan();
void stprint(STATEMENT argv);

int main(void){
	int i, T;
	printf("입력할 명세서의 갯수를 입력하세요(단, T는 10 이하): ");
	scanf("%d", &T);
	while(T>10 || T<0){
		printf("잘못 입력되었습니다. 다시 입력 해주세요(T는 10 이하)");
		scanf("%d", &T);
	}
	STATEMENT** list = (STATEMENT **)malloc(sizeof(STATEMENT *)*T);
	for(i=0; i<T; i++) list[i] = (STATEMENT *)malloc(sizeof(STATEMENT));
	for(i=0; i<T; i++) {
		*list[i]=stscan();
	}
	printf("\n------------현재 입력된 리스트------------\n");	
	printf("%s\t%s\t%s\t%s\n", "Name", "Birthday", "Gender", "Phone Number");
	for(i=0; i<T; i++) stprint(*list[i]);
	printf("\n------------이름 내림차순 정렬------------\n");
	sort_name(list, T);
	printf("%s\t%s\t%s\t%s\n", "Name", "Birthday", "Gender",  "Phone Number");
	for(i=T-1; i>=0; i--) stprint(*list[i]);
	printf("\n------------생일 오름차순 정렬------------\n");
	sort_bday(list, T);
	printf("%s\t%s\t%s\t%s\n", "Name", "Birthday", "Gender", "Phone Number");
	for(i=0; i<T; i++) stprint(*list[i]);
	return 0;
}

void swap(STATEMENT *i, STATEMENT *j){
	STATEMENT temp = *i;
	*i = *j;
	*j = temp;
}

int daychecker(STATEMENT* person){
	return person->birthday.year*10000 + person->birthday.month*100 + person->birthday.date;
}

int bdayexists(BDAY myday){
	int month_all[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
	if (((myday.year % 4) == 0) && ((myday.year % 100) != 0) || ((myday.year % 400) == 0))month_all[1] = 29;
	else month_all[1] = 28;
	if(myday.month>12 || myday.month<1 || myday.year<0 || myday.year > 2018 || myday.date<1 || myday.date > month_all[myday.month-1]) return 1;
	else return 0;
}

void sort_bday(STATEMENT** stc_ary, int T){	
	int i, j;
	for(i=0; i<T-1; i++){
		for(j=i; j>=0 && daychecker(stc_ary[j]) >= daychecker(stc_ary[j+1]); j--)
		{
			if(daychecker(stc_ary[j])==daychecker(stc_ary[j+1]) && strcmp(stc_ary[j]->name, stc_ary[j+1]->name) < 0) continue; 
			else swap(stc_ary[j], stc_ary[j+1]);
		}
	}
}

void sort_name(STATEMENT** stc_ary, int T){
	int i, j;
	for(i=0; i<T-1; i++){
		for(j=i; j>=0 && strcmp(stc_ary[j]->name, stc_ary[j+1]->name) >= 0; j--){
			if(strcmp(stc_ary[j]->name, stc_ary[j+1]->name) == 0 &&	daychecker(stc_ary[j]) < daychecker(stc_ary[j+1])) continue;
			else swap(stc_ary[j], stc_ary[j+1]);
		}
	}
}
STATEMENT stscan(){
	STATEMENT temp={0};
	printf("명세서를 입력하십시오: ");
	scanf("%s", temp.name);
	scanf("%d/%d/%d", &temp.birthday.year, &temp.birthday.month, &temp.birthday.date);
	scanf("%s", temp.gender);
	scanf("%d", &temp.number);
	while(bdayexists(temp.birthday)){
		printf("존재하지 않는 날짜입니다. 날짜만 다시 입력하십시오: ");
		scanf("%d/%d/%d", &temp.birthday.year, &temp.birthday.month, &temp.birthday.date);
	}
	while(temp.number < 100000000 ||temp.number>9999999999){
		printf("잘못된 번호 입력입니다. 번호만 다시 입력하십시오: ");
		scanf("%d", &temp.number);
	}
	return temp;
}
void stprint(STATEMENT argv){
	printf("%s", argv.name);
	if(argv.birthday.month>9) printf("\t%d.%d.%d", argv.birthday.year, argv.birthday.month, argv.birthday.date); 
	else printf("\t%d.0%d.%d", argv.birthday.year, argv.birthday.month, argv.birthday.date);
	printf("\t%s", argv.gender);
	if(argv.number < 1000000000)printf("\t0%d-%d-%d\n", argv.number/100000900, (argv.number%10000000)/10000, argv.number%10000);
	else printf("\t0%d-%d-%d\n", argv.number/100000000, (argv.number%100000000)/10000, argv.number%10000);
}
