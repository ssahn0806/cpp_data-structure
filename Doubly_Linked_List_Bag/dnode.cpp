#include "dnode.h"
#include <cassert>

size_t list_length_h(const dnode* head_ptr)
{
	size_t answer = 0;
	const dnode* cursor;
	for (cursor = head_ptr; cursor != NULL; cursor = cursor->blink())
	{
		++answer;
	}
	return answer;
}
size_t list_lenght_b(const dnode* tail_ptr)
{
	size_t answer = 0;
	const dnode* cursor;
	for (cursor = tail_ptr; cursor != NULL; cursor = cursor->flink())
	{
		++answer;
	}
	return answer;
}
void list_head_insert(dnode*& head_ptr, const dnode::value_type& entry)
{
	dnode* insert_ptr = new dnode(entry, NULL, head_ptr);
	head_ptr->set_flink(insert_ptr);
	head_ptr = insert_ptr;
}
void list_tail_insert(dnode*& tail_ptr, const dnode::value_type& entry)
{
	dnode* insert_ptr = new dnode(entry, tail_ptr, NULL);
	tail_ptr->set_blink(insert_ptr);
	tail_ptr = insert_ptr;
}
void list_insert(dnode* previous_ptr, const dnode::value_type& entry)
{
	dnode* insert_ptr = new dnode(entry, previous_ptr, previous_ptr->blink());
	previous_ptr->blink()->set_flink(insert_ptr);
	previous_ptr->set_blink(insert_ptr);

}
dnode* list_fsearch(dnode* head_ptr, const dnode::value_type& target)
{
	dnode* cursor;
	for (cursor = head_ptr; cursor != NULL; cursor = cursor->blink())
	{
		if (target == cursor->data())
			return cursor;
	}
	return cursor;
}
const dnode* list_fsearch(const dnode* head_ptr, const dnode::value_type& target)
{
	const dnode* cursor;
	for (cursor = head_ptr; cursor != NULL; cursor = cursor->blink())
	{
		if (target == cursor->data())
			return cursor;
	}
	return cursor;
}
dnode* list_bsearch(dnode* tail_ptr, const dnode::value_type& target)
{
	dnode* cursor;
	for (cursor = tail_ptr; cursor != NULL; cursor = cursor->flink())
	{
		if (target == cursor->data())
			return cursor;
	}
}
const dnode* list_bsearch(const dnode* tail_ptr, const dnode::value_type& target)
{
	const dnode* cursor;
	for (cursor = tail_ptr; cursor != NULL; cursor = cursor->flink())
	{
		if (target == cursor->data())
			return cursor;
	}
}
dnode* list_locate_f(dnode* head_ptr, size_t position)
{
	dnode* cursor = head_ptr;
	size_t i;
	assert(0 < position);
	for (i = 1; (cursor != NULL && i < position); ++i)
		cursor = cursor->blink();
	return cursor;
}
const dnode* list_locate_f(const dnode* head_ptr, size_t position)
{
	const dnode* cursor = head_ptr;
	size_t i;
	assert(0 < position);
	for (i = 1; (cursor != NULL && i < position); ++i)
		cursor = cursor->blink();
	return cursor;
}
dnode* list_locate_b(dnode* tail_ptr, size_t position)
{
	dnode* cursor = tail_ptr;
	size_t i;
	assert(0 < position);
	for (i = 1; (cursor != NULL && i < position); ++i)
		cursor = cursor->flink();
	return cursor;
}
const dnode* list_locate_b(const dnode* tail_ptr, size_t position)
{
	const dnode* cursor = tail_ptr;
	size_t i;
	assert(0 < position);
	for (i = 1; (cursor != NULL && i < position); ++i)
		cursor = cursor->flink();
	return cursor;
}
void list_copy(const dnode* source_ptr, dnode*& head_ptr, dnode*& tail_ptr)
{
	head_ptr = NULL;
	tail_ptr = NULL;
	if (source_ptr == NULL)
		return;
	list_head_insert(head_ptr, source_ptr->data());
	tail_ptr = head_ptr;
	source_ptr = source_ptr->blink();
	while (source_ptr != NULL)
	{
		list_insert(tail_ptr, source_ptr->data());
		tail_ptr = tail_ptr->blink();
		source_ptr = source_ptr->blink();
	}
}
void list_head_remove(dnode*& head_ptr)
{
	dnode* remove_ptr;
	remove_ptr = head_ptr;
	remove_ptr->blink()->set_flink(NULL);
	head_ptr = remove_ptr->blink();
	delete remove_ptr;
}
void list_tail_remove(dnode*& tail_ptr)
{
	dnode* remove_ptr;
	remove_ptr = tail_ptr;
	remove_ptr->flink()->set_blink(NULL);
	tail_ptr = remove_ptr->flink();
	delete remove_ptr;
}
void list_remove(dnode*& previous_ptr)
{
	dnode* remove_ptr;

	remove_ptr = previous_ptr->blink();
	remove_ptr->blink()->set_flink(previous_ptr);
	previous_ptr->set_blink(remove_ptr->blink());
	delete remove_ptr;
}
void list_fclear(dnode*& head_ptr)
{
	while (head_ptr != NULL)
		list_head_remove(head_ptr);
}
void list_bclear(dnode*& tail_ptr)
{
	while (tail_ptr != NULL)
		list_tail_remove(tail_ptr);
}