struct list{
	int data;
	struct list *pre;
	struct list *next;
};

struct list *create_list(int number);
struct list* insert_list(struct list *head, int data);
struct list *search_list(struct list *head, int data);
struct list *delete_list(struct list *head, int data);
void print_list(struct list* head);

