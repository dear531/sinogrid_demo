#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

struct link {
	struct link *next;
	int data;
};
struct link *link_create(struct link *head, struct link *node)
{
	if (NULL == node) return head;
	if (NULL == head) return node;
	node->next = head;
	head = node;
	return head;
}

void link_show(struct link *head)
{
	struct link *p;
	for (p = head; NULL != p; p = p->next) {
		fprintf(stdout, "%d\n", p->data);
	}
	return;
}

struct link *link_reverse(struct link *head)
{
	struct link *crr, *prv, *nxt;
	for (prv = NULL, crr = head; NULL != crr;) {
		nxt = crr->next;
		crr->next = prv;
		prv = crr;
		crr = nxt;
	}
	return prv;
}
int main(int argc, char *argv[])
{
	struct link *head = NULL, *tmp = NULL;
	int i;
	for (i = 0; 10 > i; i++) {
		tmp = malloc(sizeof(*tmp));
		if (NULL == tmp) {
			fprintf(stderr, "malloc error :%s\n",
					strerror(errno));
			goto failure;
		}
		tmp->data = i;
		head = link_create(head, tmp);
	}
	link_show(head);
	fprintf(stdout, "====\n");
	head = link_reverse(head);
	link_show(head);
	return 0;
failure:
	exit(EXIT_FAILURE);
}
