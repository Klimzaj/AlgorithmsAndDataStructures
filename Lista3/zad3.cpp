#include <iostream>

struct node {
	node* next;
	int value;

public:
	
	node() = default;

	node(int v, node* n = nullptr)
		: next(n), value(v) 
  {}

	node(const node& other)
		: next(other.next), value(other.value)
	{}

	node& operator=(const node& other)
	{
		if (this == &other)
			return *this;
		next = other.next;
		value = other.value;
		return *this;
	}
	node& operator=(const node*& other)
	{
		if (this == other)
			return *this;
		next = other->next;
		value = other->value;
		return *this;
	}
};

void insertion_sort(node *& list)
{
	if(list == nullptr || list->next == nullptr) {
		return;
	}
	node *t1 = list->next;
	
	while(t1 != nullptr) {

		int delta = t1->value;
		bool found = false;

		node *t2 = list;

		while(t2 != t1) {
			if(t2->value > t1->value	&& !found) 
      {
				delta = t2->value;
				t2->value = t1->value;
				found = true;
				t2 = t2->next;
			}
			else 
      {
				if(found) 
        {
					int temp = delta;
					delta = t2->value;
					t2->value = temp;
				}
				t2 = t2->next;
			}
		}
		t2->value = delta;
		t1 = t1->next;
	}
	
}

void print_list(node* list)
{
	node* current = list;

	while(current != nullptr )
	{
		std::cout << current->value << std::endl;
		current = current->next;
	}
}

int main()
{
	node * head = new node(25, new node(14, new node(-5, new node(18, new node(-10, new node(2))))));

	print_list(head);
	insertion_sort(head);

  std::cout << "******" << std::endl;
	
  print_list(head);
  return 0;
}