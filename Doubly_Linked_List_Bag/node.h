#include <cstdlib>
#include <cassert>

class node
{
public:
	typedef double value_type;
	node(const value_type& init_data = value_type(), node* init_link = NULL)
	{
		data_field = init_data;
		link_field = init_link;
	}
	void set_data(const value_type& new_data)
	{
		data_field = new_data;
	}
	void set_link(node* new_link)
	{
		link_field = new_link;
	}	
	value_type data() const
	{
		return data_field;
	}
	const node* link() const
	{
		return link_field;
	}
	node* link()
	{
		return link_field;
	}
private:
	value_type data_field;
	node* link_field;
};

size_t list_length(const node* head_ptr)
{
	size_t answer = 0;
	const node* cursor;
	for (cursor = head_ptr; cursor != NULL; cursor = cursor->link())
		++answer;
	return answer;
}
void list_head_insert(node*& head_ptr, const node::value_type& entry)
{
	head_ptr = new node(entry, head_ptr);
}
void list_insert(node*& previous_ptr, const node::value_type& entry)
{
	previous_ptr->set_link(new node(entry, previous_ptr->link()));
}
node* list_search(node* head_ptr, const node::value_type& target)
{
	node* cursor;

	for (cursor = head_ptr; cursor != NULL; cursor = cursor->link())
	{
		if (target == cursor->data())
			return cursor;

		return NULL;
	}
}
const node* list_search(const node* head_ptr, const node::value_type& target)
{
	const node* cursor;

	for (cursor = head_ptr; cursor != NULL; cursor = cursor->link())
	{
		if (target == cursor->data())
			return cursor;
		return NULL;
	}
}
node* list_locate(node* head_ptr, size_t position)
{
	node* cursor = head_ptr;
	size_t i = 0;
	assert(0 < position);
	for (i = 1; (cursor != NULL && i < position); ++i)
	{
		cursor = cursor->link();
	}
	return cursor;
}
const node* list_locate(const node* head_ptr, size_t position)
{
	const node* cursor = head_ptr;
	size_t i = 0;
	assert(0 < position);
	for (i = 1; (cursor != NULL && i < position); ++i)
	{
		cursor = cursor->link();
	}
	return cursor;
}
void list_copy(const node* source_ptr, node*& head_ptr, node*& tail_ptr)
{
	head_ptr = NULL;
	tail_ptr = NULL;

	if (source_ptr == NULL)
		return;
	list_head_insert(head_ptr, source_ptr->data());
	tail_ptr = head_ptr;
	source_ptr = source_ptr->link();
	while (source_ptr != NULL)
	{
		list_insert(tail_ptr, source_ptr->data());
		tail_ptr = tail_ptr->link();
		source_ptr = source_ptr->link();
	}

}
void list_head_remove(node*& head_ptr)
{
	node* remove_ptr = head_ptr;

	head_ptr = remove_ptr->link();

	delete remove_ptr;
}
void list_remove(node*& previous_ptr)
{
	node* remove_ptr = previous_ptr->link();
	previous_ptr->set_link(remove_ptr->link());
	delete remove_ptr;
}
void list_clear(node*& head_ptr)
{
	while (head_ptr != NULL)
	{
		list_head_remove(head_ptr);
	}
}