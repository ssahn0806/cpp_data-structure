#include "binary_tree.h"

template <class Item>
class bag
{
public:
	bag();
	bag(const bag<Item>& entry);
	~bag();
	void operator=(const bag<Item>& source);
	void operator+=(const bag<Item>& source);
	void insert_all(const binary_tree_node<Item>* tree_ptr);
	void insert(const Item& entry);
	bool erase_one(const Item& target);
	size_t erase(const Item& target);
	void show_content();
	size_t count(const Item& target) const;
	size_t size();
private:
	binary_tree_node<Item>* root_ptr;
};
