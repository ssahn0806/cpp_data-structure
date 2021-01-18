#include <cstdlib>

class dnode
{
public:
	typedef double value_type;
	dnode(const value_type& init_data = value_type(), dnode* fore_link = NULL, dnode* back_link = NULL)
	{
		data_field = init_data;
		link_fore = fore_link;
		link_back = back_link;
	}
	void set_data(const value_type& new_data)
	{
		data_field = new_data;
	}
	void set_flink(dnode* new_link)
	{
		if (this != NULL)
		{
			link_fore = new_link;
		}
	}
	void set_blink(dnode* new_link)
	{
		link_back = new_link;
	}
	value_type data() const
	{
		return data_field;
	}
	dnode* flink()
	{
		return link_fore;
	}
	const dnode* flink() const
	{
		return link_fore;
	}
	dnode* blink()
	{
		return link_back;
	}
	const dnode* blink() const
	{
		return link_back;
	}
	
private:
	value_type data_field;
	dnode* link_fore;
	dnode* link_back;

};

size_t list_length_h(const dnode* head_ptr);
size_t list_lenght_b(const dnode* tail_ptr);
void list_head_insert(dnode*& head_ptr, const dnode::value_type& entry);
void list_tail_insert(dnode*& tail_ptr, const dnode::value_type& entry);
void list_insert(dnode* previous_ptr, const dnode::value_type& entry);
dnode* list_fsearch(dnode* head_ptr, const dnode::value_type& target);
const dnode* list_fsearch(const dnode* head_ptr, const dnode::value_type& target);
dnode* list_bsearch(dnode* tail_ptr, const dnode::value_type& target);
const dnode* list_bsearch(const dnode* tail_ptr, const dnode::value_type& target);
dnode* list_locate_f(dnode* head_ptr, size_t position);
const dnode* list_locate_f(const dnode* head_ptr, size_t position);
dnode* list_locate_b(dnode* tail_ptr, size_t position);
const dnode* list_locate_b(const dnode* tail_ptr, size_t position);
void list_copy(const dnode* source_ptr, dnode*& head_ptr, dnode*& tail_ptr);
void list_head_remove(dnode*& head_ptr);
void list_tail_remove(dnode*& tail_ptr);
void list_remove(dnode*& previous_ptr);
void list_fclear(dnode*& head_ptr);
void list_bclear(dnode*& tail_ptr);