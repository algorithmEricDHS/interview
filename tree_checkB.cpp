#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>
#include <stack> 
#include <string.h>
#include<queue> 
using namespace std;

typedef struct Node {
	int data;
	int layer;
	struct Node *left;
	struct Node *right;
}Node;

Node * buildT (int count) {
	Node * h;
	Node *tmp;
	Node *c; 
	int i; 
	int l;
	queue<Node *> n;
	int len = sizeof(Node);
	h = (Node *) malloc (len);
	memset(h, 0 , len);
	h->data = 1;
	if (!h) return NULL;
	n.push (h);
	l = 1;
	i =2;
	h->layer = l;
	while (!n.empty()) {
		tmp = n.front();
		n.pop();
		if (i>count) break;
		c = (Node *) malloc (len);
		memset (c, 0, len);
		tmp->left =c ;
		c->layer = tmp->layer+1;
		c->data = i++;
		if (i>count) break;
		if (0 == i %1) {
			c = (Node *) malloc (len);
			memset (c,0,len);
			tmp->right = c ;
			c->layer = tmp->layer+1;
			c->data = i++;
			if (i>count) break;
			n.push(c);
		}
		n.push(tmp->left);
	
	}
	return h;
}
void printT(Node *h) {
	Node *tmp;
	
	if (!h) return;
	tmp = h;
	printT(tmp->left);
	printf ("data is %d, layer is %d\n", tmp->data, tmp->layer);
	printT(tmp->right);	

}

void printSL(Node *h, int l, int tl) {
	Node *tmp;
	tmp =h;
	if (!h ) return;
	if (l == tl) {
		printf("it is %d, leyer is %d\n", h->data, h->layer);
		return;
	}
	printSL(h->left,l+1, tl );
	printSL(h->right, l+1, tl);
}
void printL(Node *h) {
	Node *tmp; 
	queue<Node *> q;
	if (!h) return;
	tmp = h ;
	q.push(tmp);
	while(!q.empty()) {
		tmp = q.front();
		printf ("data is %d, layer is %d \n", tmp->data, tmp->layer);
		q.pop();
		if (tmp->left) q.push(tmp->left);
		if (tmp->right) q.push (tmp->right);
		
	}
}
int i = -1;
int i1 = -1;

int depth(Node *h) {
	int l, r;
	if (!h) return 0;
	l = depth(h->left);
	r = depth(h->right);
	return 1+(l>r?l:r); 
}
bool checkB (Node *h) {
	int d1, d2,d;
	d1 = depth(h->left);
	d2 = depth(h->right);
	d = (d1>d2?d1-d2:d2-d1);
	if (0==d || 1 == d){
		return true;
	}
	else return false;
	return checkB(h->left) && checkB(h->right) ;
	
}
int main (int argc, char* argv[]) {
	Node *h = buildT(1000);
	//printL(h);
	//bool r = checkB(h);
	//if (r) printf("Balance tree \n");
	//else printf ("Un-Balance tree \n");
	printSL(h, 1, 7);		
	return 0;
}
