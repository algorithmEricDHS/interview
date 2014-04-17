#include <stdio.h>
#include <malloc.h>
#include <string.h>
/* utf-8: 0xc0, 0xe0, 0xf0, 0xf8, 0xfc */
unsigned char mblen_table_utf8[] = 
{
        1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
        1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
        1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
        1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
        1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
        1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
        1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
        1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
        1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
        1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
        1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
        1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
        2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2,
        2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2,
        3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3,
        4, 4, 4, 4, 4, 4, 4, 4, 5, 5, 5, 5, 6, 6, 1, 1
};
/* 1. For ASCII, only int array can store all the index
 * 2. For utf-8, a work can be represented by several chars, List have to be used to store such information 
 * */
typedef struct mData{
	char data[7];
	int count;
	struct mData *next; 
}mD;
typedef struct mChar{
	int len;
	int count;
	mD *data;
} mChar;

#define MBLEN(x)  mblen_table_utf8[(x)]

/*
 *1. Using list makes free complicated, implement it by myself
 * */
void myFree(mChar *in, int len) {
	mChar * tmp;
	for(int i=len-1;i>=0;i--) {
		tmp = in+i;
		while (tmp->data) {
			free (tmp->data);
			tmp->data = tmp->data->next;
		}
	
	}
	if (in) free (in);
	return;
}
char *unDup( char * in) {
	
	char *tmp;
	mChar* a;
	mChar *b;
	int t;
	char *c;
	int len;
	int i;
	int index;
	mD *d1;
	mD *d2, *d3;
	bool found;
//r represents return value, since array a will be freed after unDup, malloc extra memory for return value
	char *r = (char *) malloc (sizeof(char) * 7);
//Array will be used, if word has several chars, a list will be used to store thses words. Index in array depends on the first word's char
	a = (mChar *) malloc(sizeof(mChar) * 256); 
	if (!a) {
		printf("Cannot init mChar array, return\n");
		return NULL;
	} 
	memset(a, 0, sizeof(mChar) * 256);
	
	if (!in) {
		myFree(a, 256);
		return NULL;
	}
	tmp = in;
	while (*tmp != '\0') {
		c = tmp;
		len = MBLEN((unsigned char)*c);		
		index = (unsigned char)(*tmp);
		b = a+index;
		b->len = len;
		d1 = (mD *) malloc (sizeof(mD));
		if (!d1) {
			printf("Cannot init data memory, return\n");
                        myFree(a, 256);
                        return NULL;
		}
		memset (d1, 0, sizeof(mD));
		d2 = b->data;
		d3 = d2;
		found = false;
		while (d2) {
			if (0 == memcmp (d2->data, c, len)) {
				found = true;
				d2->count++;
				break;
			}
			d3 = d2;
			d2 = d2->next;
		} 
		if (!found) {
			if (!d3) {
				b->data = d1;
			} else {
				d3->next = d1;
			}	
			memcpy (d1->data, c, len);
			d1->data[len]='\0';
			d1->count++;
		} 
		b->count ++;	
		tmp+=len;	
	}
	tmp = in;
	while (*tmp != '\0') {
		c=tmp;
		len = MBLEN((unsigned char)*c);
		index = (unsigned char)(*c);
		b = a + index;
		if (1 == b->count ) {
			memcpy (r, b->data->data, (len+1));
			myFree(a, 256);
			return r;
		} else if ((b->count > 1) && (len > 1 )) {
			d1 = b->data;
			while (d1) {
				if (d1->count == 1 && (0==memcmp(d1->data, c, len)) ) {
					memcpy (r, d1->data, (len+1));
					myFree(a, 256);
					return r;
				}
				d1=d1->next;
			}	
		}
		tmp+=len;
	}
	printf("cannot find undup character\n");
	myFree(a, 256);
	return NULL;
	
	
}
int main(int argc, char *argv[]) {
	char a[] = "你你好aaaaaabbbcccdfff";
	char b[] = "aaaaaa呵呵7bbbbbb";
	char *c;
	c = unDup (a);
	if (c) {
		printf ("First undup character in %s is: %s \n", a,c);
		free(c);
	}
	c = unDup (b);
	if (c) {
		printf ("First undup character in %s is: %s \n", b,c);
		free(c);
	}
	return 0;
}
