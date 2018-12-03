#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct NODE
{
	int value;
	struct NODE *NEXT;
} NODE;

void initialize_NODE(NODE* temp)
{
	temp->value = 0;
	temp->NEXT = NULL;
}

typedef struct LIST
{
	NODE* head;
	NODE* current_pointer;
} LIST;

void initialize_LIST(LIST *new_list) {
	new_list->head =  (NODE *)malloc(sizeof(NODE));
	initialize_NODE(new_list->head);
	new_list->current_pointer = new_list->head;
}
void append(LIST *current_list, int val)
{
	current_list->current_pointer->NEXT = (NODE *)malloc(sizeof(NODE));
	initialize_NODE(current_list->current_pointer->NEXT);
	current_list->current_pointer = current_list->current_pointer->NEXT;
	current_list->current_pointer->value = val;
}

void move_current_pointer_of_the_list_to_num(LIST *current_list, int sequence)
{
	int i;
	current_list->current_pointer = current_list->head;
	for(i=0; i<sequence; i++) current_list->current_pointer = current_list->current_pointer->NEXT;
}

int main(void) 
{
	char temp_string[100] = {0,};
	int i=0, cnt_sum;
	LIST list;
	initialize_LIST(&list);
	printf("Input Number (Ctrl+Z to Exit) : ");
	while(gets(temp_string) != NULL)
	{
		i++;
		append(&list, atoi(temp_string));
	}
	cnt_sum = i;
	move_current_pointer_of_the_list_to_num(&list, 1);
	printf("Values in a correct sequence :\n");
	for(i=0; i<cnt_sum; i++)
	{
		printf("%d ", list.current_pointer->value);
		list.current_pointer = list.current_pointer->NEXT;
	}
	printf("\n\nNumber of the argument : %d\n", cnt_sum);
	if(cnt_sum%2 == 1)
	{
		move_current_pointer_of_the_list_to_num(&list, cnt_sum/2+1);
		printf("\nMiddle value is %dth argument, Value is : %d\n", cnt_sum/2+1, list.current_pointer->value);
	}
	else
	{
		move_current_pointer_of_the_list_to_num(&list, cnt_sum/2);
		printf("\nMiddle value is %dth, %dth argument, Value is : %d, %d\n", cnt_sum/2,cnt_sum/2+1, list.current_pointer->value, list.current_pointer->NEXT->value);
	}
	move_current_pointer_of_the_list_to_num(&list, cnt_sum);
	printf("\nValues in a reverse sequence :\n");
	for(i=cnt_sum; i>0; i--)
	{
		printf("%d ", list.current_pointer->value);
		move_current_pointer_of_the_list_to_num(&list, i-1);
	}
	NODE* temp;
	for(i=0;i<cnt_sum/2;i++)
	{
		temp = list.current_pointer->NEXT->NEXT;
		free(list.current_pointer->NEXT);
		list.current_pointer->NEXT = temp;
		list.current_pointer = list.current_pointer->NEXT;
	}
	move_current_pointer_of_the_list_to_num(&list, 1);
	printf("\n\nValues in a correct sequence(removed odd-numbered order values) : \n");
	for(i=0;i<cnt_sum/2;i++)
	{
		printf("%d ", list.current_pointer->value);
		list.current_pointer = list.current_pointer->NEXT;
	}
	return 0;
}
