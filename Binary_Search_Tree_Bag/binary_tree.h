#include <cstdlib>
#include <iomanip>
#include <iostream>

using namespace std;

template <class Item>
class binary_tree_node
{
public:
	binary_tree_node(const Item& init_data = Item(), binary_tree_node* init_left = NULL, binary_tree_node* init_right = NULL);
	Item& data();
	const Item& data() const;
	binary_tree_node*& left();
	const binary_tree_node* left() const;
	binary_tree_node*& right();
	const binary_tree_node* right() const;
	void set_data(const Item& new_data); 
	void set_left(binary_tree_node* new_left);
	void set_right(binary_tree_node* new_right);
	bool is_leaf() const;

private:
	Item data_field;
	binary_tree_node* left_field;
	binary_tree_node* right_field;
};

template <class Item>
void tree_clear(binary_tree_node<Item>*& root_ptr)
{
	if (root_ptr != NULL)
	{
		tree_clear(root_ptr->left());
		tree_clear(root_ptr->right());
		delete root_ptr;
		root_ptr = NULL;
	}
}

template <class Item>
binary_tree_node<Item>* tree_copy(binary_tree_node<Item>* root_ptr)
{
	binary_tree_node<Item>* l_ptr;
	binary_tree_node<Item>* r_ptr;
	if (root_ptr == NULL)
		return NULL;
	else
	{
		l_ptr = tree_copy(root_ptr->left());
		r_ptr = tree_copy(root_ptr->right());
		return new binary_tree_node<Item>(root_ptr->data(), l_ptr, r_ptr);
	}
}

template <class Item>
bool bst_remove(binary_tree_node<Item>*& root_ptr, const Item& target)
{
	if (root_ptr == NULL)
		return false;

	if (target < root_ptr->data())
		bst_remove(root_ptr->left(), target);
	else if (target > root_ptr->data())
		bst_remove(root_ptr->right(), target);
	else
	{
		if (root_ptr->left() == NULL)
		{
			binary_tree_node<Item>* oldroot_ptr = root_ptr;
			root_ptr = root_ptr->right();
			delete oldroot_ptr;
			return true;
		}
		else
		{
			return bst_remove_max(root_ptr->left(), root_ptr->data());
		}
	}
}

template <class Item>
void bst_print(const binary_tree_node<Item>* root_ptr, size_t depth)
{
	if (root_ptr != NULL)
	{
		bst_print(root_ptr->right(), depth + 1);
		std::cout << setw(4 * depth) << "" << root_ptr->data() << endl;
		bst_print(root_ptr->left(), depth + 1);
	}
}
template <class Item>
bool bst_remove_max(binary_tree_node<Item>*& root_ptr, Item& removed)
{
	if (root_ptr->right() == NULL)
	{
		removed = root_ptr->data();
		binary_tree_node<Item>* oldroot_ptr = root_ptr;
		root_ptr = root_ptr->left();
		delete oldroot_ptr;
		return true;
	}
	else
	{
		bst_remove_max(root_ptr->right(), removed);
	}
}

template class binary_tree_node<int>;