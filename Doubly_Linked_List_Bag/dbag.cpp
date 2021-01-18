#include "dbag.h"
#include <iostream>
#include <time.h>
#include <cassert>

dbag::dbag()
{
	head_ptr = NULL;
	many_nodes = 0;
}

dbag::dbag(const dbag& source)
{
	dnode* tail_ptr;
	list_copy(source.head_ptr, head_ptr, tail_ptr);
	many_nodes = source.many_nodes;
}

dbag::~dbag()
{
	list_fclear(head_ptr);
	many_nodes = 0;
}

dbag::size_type dbag::nodes_count() const
{
	return many_nodes;
}
dnode* dbag::start() const
{
	return head_ptr;
}
void dbag::operator=(const dbag& source)
{
	dnode* tail_ptr;
	if (this == &source)
		return;
	list_fclear(head_ptr);
	list_copy(source.head_ptr, head_ptr, tail_ptr);
	many_nodes = source.many_nodes;
}

void dbag::operator +=(const dbag& addend)
{
	dnode* copy_tail_ptr;
	dnode* copy_head_ptr;
	if (addend.many_nodes > 0)
	{
		list_copy(addend.head_ptr, copy_head_ptr, copy_tail_ptr);
		copy_tail_ptr->set_blink(head_ptr);
		head_ptr->set_flink(copy_tail_ptr);
		head_ptr = copy_head_ptr;
		many_nodes += addend.many_nodes;
	}
}

dbag operator +(const dbag& b1, const dbag& b2)
{
	dbag copy;

	copy += b1;
	copy += b2;
	return copy;
}
bool operator ==(const dbag& b1, const dbag& b2)
{
	dbag copy_b1, copy_b2;
	/*	if (b1.nodes_count() != b2.nodes_count())
		return false;
		*/
	if (b1.many_nodes != b2.many_nodes)
		return false;
	copy_b1 = b1;
	copy_b2 = b2;

	copy_b1.sort();
	copy_b2.sort();

	/*
	dnode* b1_head = copy_b1.start();
	dnode* b2_head = copy_b2.start();
	*/
	dnode* b1_head = copy_b1.head_ptr;
	dnode* b2_head = copy_b2.head_ptr;

	while (b1_head != NULL)
	{
		if (b1_head->data() != b2_head->data())
			return false;
		b1_head = b1_head->blink();
		b2_head = b2_head->blink();
	}

	return true;
}
bool dbag::erase_one(const value_type& target)
{
	dnode* target_ptr = head_ptr;

	target_ptr = list_fsearch(head_ptr, target);
	if (target_ptr == NULL)
		return false;
	target_ptr->set_data(head_ptr->data());
	list_head_remove(head_ptr);
	--many_nodes;
	return true;
}

dbag::size_type dbag::count(const value_type& target) const
{
	size_type answer = 0;
	const dnode* cursor;
	cursor = list_fsearch(head_ptr, target);
	while (cursor != NULL)
	{
		++answer;
		cursor = cursor->blink();
		cursor = list_fsearch(cursor, target);
	}
	return answer;
}

dbag::value_type dbag::grab()
{
	size_type i;
	const dnode* cursor;
	assert(many_nodes > 0);

	srand(time(0));

	i = (rand() % many_nodes) + 1;
	cursor = list_locate_f(head_ptr, i);
	return cursor->data();
}

void dbag::insert(const value_type& entry)
{
	list_head_insert(head_ptr, entry);
	++many_nodes;
}

void dbag::show_content()
{
	const dnode* cursor;
	cursor = head_ptr;

	if (cursor == NULL)
		std::cout << "No contents" << std::endl;
	else
	{
		std::cout << cursor->data() << " ";
		cursor = cursor->blink();
		while (cursor != NULL)
		{
			std::cout << cursor->data() << " ";
			cursor = cursor->blink();
		}
		std::cout << std::endl;
	}

}

void dbag::sort() //ascending
{
	dnode* i_ptr = head_ptr;
	dnode* j_ptr = NULL;
	dbag::value_type tmp;
	if (i_ptr == NULL)
		return;
	j_ptr = head_ptr->blink();

	for (i_ptr = head_ptr; i_ptr != NULL; i_ptr = i_ptr->blink())
	{
		for (j_ptr = i_ptr->blink(); j_ptr != NULL; j_ptr = j_ptr->blink())
		{
			if (i_ptr->data() > j_ptr->data())
			{
				tmp = i_ptr->data();
				i_ptr->set_data(j_ptr->data());
				j_ptr->set_data(tmp);
			}
		}
	}
	/*
	while (j_ptr != NULL)
	{
		if (i_ptr->data() > j_ptr->data())
		{
			tmp = i_ptr->data();
			i_ptr->set_data(j_ptr->data());
			j_ptr->set_data(tmp);
		}
		i_ptr = i_ptr->blink();
		j_ptr = j_ptr->blink();
	}*/
}

