#ifndef __WATCHPOINT_H__
#define __WATCHPOINT_H__

#include "common.h"

typedef struct watchpoint
{
	int NO;
	char s[50];
	struct watchpoint *next;

	/* TODO: Add more members if necessary */

} WP;

WP *new_wp();

void free_wp(WP *wp);

#endif
