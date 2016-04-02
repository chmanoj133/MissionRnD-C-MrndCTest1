/*
Q4: Two dates are given in a 8 node single linked list form,where each node
has one digit only, dates 01-31, months 01-12, year 0000-9999.

Find the number of days in between those two dates .[Exclusive]

Ex : Date1:  0->1->0->1->2->0->0->4 .
     Date2 : 0->5->0->1->2->0->0->4 should return 3 .
As there are 3 days between Jan1st 2004 and Jan 5th 2004.

Ex 2 : Date1 : 3->1->1->2->2->0->1->2.
       Date2 : 0->2->0->1->2->0->1->3 should return 1 .
(There is only one day between 31st Dec 2012 and 2nd  Jan 2013 .)

Note : Consecutive Days and Same Days should return 0;
->Return -1 for NULL Inputs .
->Between Days have to be calculated by not including start and end date .
->The SLL will have 8 Nodes in all cases . Month 9 will be represented as 09.

Difficulty : Hard 
*/
#include <stdlib.h>
#include <stdio.h>
#include <math.h>

struct node{
	int data;
	struct node *next;
};


int between_days(struct node *date1head, struct node *date2head)
{
	int d1, d2, m1, m2, y1, y2;
	int ans = 0;
	int i, temp;

	if (date1head == NULL || date2head == NULL)
		return -1;

	d1 = date1head->data * 10 + date1head->next->data;
	date1head = date1head->next->next;
	m1 = date1head->data * 10 + date1head->next->data;
	date1head = date1head->next->next;
	y1 = date1head->data * 1000 + date1head->next->data * 100 + date1head->next->next->data * 10 + date1head->next->next->next->data;

	d2 = date2head->data * 10 + date2head->next->data;
	date2head = date2head->next->next;
	m2 = date2head->data * 10 + date2head->next->data;
	date2head = date2head->next->next;
	y2 = date2head->data * 1000 + date2head->next->data * 100 + date2head->next->next->data * 10 + date2head->next->next->next->data;

	if (y1 > y2)
	{
		ans = ans + 365 * (y1 - y2 - 1) + (y1 - y2 - 1) / 4;

		ans = ans + 30 * (12 - m2);
		for (i = m2; i <= 12; i++)
		{
			if (i == 1 || i == 3 || i == 5 || i == 7 || i == 8 || i == 10 || i == 12)
				ans = ans + 1;

			if (i == 2)
				ans = ans - 2;
		}

		ans = ans + 30 * (m1 - 1);
		for (i = 1; i <= m1; i++)
		{


			if (i == 1 || i == 3 || i == 5 || i == 7 || i == 8 || i == 10 || i == 12)
				ans = ans + 1;
			if (i == 2)
				ans = ans - 2;
		}

		i = m2;

		if (i == 1 || i == 3 || i == 5 || i == 7 || i == 8 || i == 10 || i == 12)
			ans = ans + 31 - d2;

		else if (i == 2)
			ans = ans + 28 - d2;

		else
			ans = ans + 30 - d2;

		ans = ans + d1 - 1;
	}

	else if (y1 < y2)
	{
		ans = ans + 365 * (y2 - y1 - 1) + (y2 - y1 - 1) / 4;

		ans = ans + 30 * (12 - m1);
		for (i = m1; i <= 12; i++)
		{
			if (i == 1 || i == 3 || i == 5 || i == 7 || i == 8 || i == 10 || i == 12)
				ans = ans + 1;

			if (i == 2)
				ans = ans - 2;
		}

		ans = ans + 30 * (m2 - 1);

		for (i = 1; i <= m2; i++)
		{


			if (i == 1 || i == 3 || i == 5 || i == 7 || i == 8 || i == 10 || i == 12)
				ans = ans + 1;
			if (i == 2)
				ans = ans - 2;
		}

		i = m1;

		if (i == 1 || i == 3 || i == 5 || i == 7 || i == 8 || i == 10 || i == 12)
			ans = ans + 31 - d1;

		else if (i == 2)
			ans = ans + 28 - d1;

		else
			ans = ans + 30 - d1;

		ans = ans + d2 - 1;
	}
	else
	{
		if (m1 == m2)
		{
			if (d1 > d2)
			{
				ans = ans + (d1 - d2 - 1);
			}
			else if (d2 > d1)
			{
				ans = ans + (d2 - d1 - 1);
			}
		}
		else
		{
			if (m1 > m2)
			{
				temp = m1;
				m1 = m2;
				m2 = temp;

				temp = d1;
				d1 = d2;
				d2 = temp;
			}

			i = m1;

			if (i == 1 || i == 3 || i == 5 || i == 7 || i == 8 || i == 10 || i == 12)
				ans = ans + 31 - d1;

			else if (i == 2)
				ans = ans + 28 - d1;

			else
				ans = ans + 30 - d1;

			ans = ans + d2 - 1;

			
		}
	}

	return ans;
}