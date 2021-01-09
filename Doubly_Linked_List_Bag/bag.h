#pragma once
#include "node.h"
#include <cassert>
#include <cstdlib>

class bag
{
public:
	typedef std::size_t size_type;
	typedef double value_type;
	bag();
	bag(const bag& source);
	~bag();
	void operator=(const bag& source);
	void operator+=(const bag& addend);
	bool erase_one(const value_type& target);
	size_type count(const value_type& target) const;
	value_type grab();
	void insert(const value_type& entry);
private:
	node* head_ptr;
	size_type many_nodes;
};

bag::bag()
{
	head_ptr = NULL;
	many_nodes = 0;
}

bag::bag(const bag& source)
{
	node* tail_ptr;
	node* temp = NULL;
	temp->list_copy(source.head_ptr, head_ptr, tail_ptr);
	many_nodes = source.many_nodes;
}
bag::~bag()
{
	node* temp = NULL;
	temp->list_clear(head_ptr);
	many_nodes = 0;
}
void bag::operator=(const bag& source)
{
	node* tail_ptr;
	node* temp = NULL;
	if (this == &source)
		return;
	temp->list_clear(head_ptr);
	temp->list_copy(source.head_ptr, head_ptr, tail_ptr);
	many_nodes = source.many_nodes;
}
void bag::operator+=(const bag& addend)
{
	node* copy_tail_ptr;
	node* copy_head_ptr;
	node* temp = NULL;
	if (addend.many_nodes > 0)
	{
		temp->list_copy(addend.head_ptr, copy_head_ptr, copy_tail_ptr);
		copy_tail_ptr->set_link(head_ptr);
		head_ptr = copy_head_ptr;
		many_nodes += addend.many_nodes;
	}

}

bool bag::erase_one(const value_type& target)
{
	node* target_ptr=NULL;
	node* temp = NULL;

	target_ptr ->list_search(head_ptr, target);
	if (target_ptr == NULL)
		return false;
	target_ptr->set_data(head_ptr->data());
	temp->list_head_remove(head_ptr);
	--many_nodes;
	return true;
}

bag::size_type bag::count(const value_type& target) const
{
	size_type answer = 0;
	const node* cursor;
	node* temp = NULL;
	cursor= temp->list_search(head_ptr, target);
	while (cursor != NULL)
	{
		++answer;
		cursor = cursor->link();
		cursor = temp->list_search(cursor, target);
	}
	return answer;
}
bag::value_type bag::grab()
{
	size_type i;
	const node* cursor;
	node* temp = NULL;
	assert(many_nodes> 0);

	i = (rand() % many_nodes) + 1;
	cursor = temp->list_locate(head_ptr, i);
	return cursor->data();
}

void bag::insert(const value_type& entry)
{
	node* temp = NULL;
	temp->list_head_insert(head_ptr, entry);
	++many_nodes;
}