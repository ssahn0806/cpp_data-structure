#include "bag.h"
#include <cstdlib>

template <class Item>
bag<Item>::bag()
{
	root_ptr = NULL;
}

template <class Item>
bag<Item>::bag(const bag<Item>& entry)
{
	this->root_ptr = tree_copy(entry.root_ptr);
}

template <class Item>
bag<Item>::~bag()
{
	tree_clear(root_ptr);
}

template <class Item>
size_t bag<Item>::size()
{
	if (root_ptr == NULL)
		return 0;
	else
	{
		binary_tree_node<Item>* origin = root_ptr;
		root_ptr = root_ptr->left();
		size_t left = size();
		root_ptr = origin;

		root_ptr = root_ptr->right();
		size_t right = size();
		root_ptr = origin;
		return 1 + left + right;
	}
} 

template <class Item>
void bag<Item>::operator=(const bag<Item>& source)
{
	if (this == &source)
		return;
	tree_clear(root_ptr);
	root_ptr = tree_copy(source.root_ptr);
}

template <class Item>
void bag<Item>::operator+=(const bag<Item>& addend)
{
	if (this == &addend)
	{
		binary_tree_node<Item>* add_ptr = tree_copy(addend.root_ptr);
		insert_all(add_ptr);
		tree_clear(add_ptr);
	}
	else
		insert_all(addend.root_ptr);
}

template <class Item>
void bag<Item>::insert(const Item& entry)
{
	binary_tree_node<Item>* new_ptr = new binary_tree_node<Item>(entry);
	if (size() == 0)
		root_ptr = new_ptr;
	else
	{
		binary_tree_node<Item>* node_ptr = root_ptr;
		while (1)
		{
			if (entry <= node_ptr->data())
			{
				if (node_ptr->left() == NULL)
				{
					node_ptr->set_left(new_ptr);
					return;
				}
				else
					node_ptr = node_ptr->left();
			}
			else
			{
				if (node_ptr->right() == NULL)
				{
					node_ptr->set_right(new_ptr);
					return;
				}
				else
					node_ptr = node_ptr->right();
			}
		}
	}
}

template <class Item>
bool bag<Item>::erase_one(const Item& target)
{
	return bst_remove(root_ptr, target);
}

template <class Item>
size_t bag<Item>::erase(const Item& target)
{
	size_t erased = 0;
	while (true)
	{
		if (erase_one(target))
			erased++;
		else
			break;
	}
	return erased;
}

template <class Item>
void bag<Item>::insert_all(const binary_tree_node<Item>* tree_ptr)
{
	if (tree_ptr != NULL)
	{
		insert(tree_ptr->data());
		insert_all(tree_ptr->left());
		insert_all(tree_ptr->right());
	}
}

template <class Item>
void bag<Item>::show_content()
{
	if (root_ptr != NULL)
		bst_print(root_ptr, 1);
	return;
}

template <class Item>
size_t bag<Item>::count(const Item& target) const
{
	size_t many = 0;
	if (root_ptr == NULL)
		return 0;
	else
	{
		binary_tree_node<Item>* node_ptr = root_ptr;
		while (1)
		{
			if (node_ptr->data() == target)
				many++;

			if (node_ptr->left() == NULL && node_ptr->right() == NULL)
				break;
			else if (node_ptr->left() != NULL)
				node_ptr = node_ptr->left();
			else if (node_ptr->right() != NULL)
				node_ptr = node_ptr->right();
		}
	}
	return many;
}
template class bag<int>;