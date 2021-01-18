#include "dnode.h"

class dbag
{
public:
	typedef std::size_t size_type;
	typedef double value_type;
	dbag();
	dbag(const dbag& source);
	~dbag();
	void operator=(const dbag& source);
	void operator+=(const dbag& addend);
	friend dbag operator +(const dbag& b1, const dbag& b2);
	friend bool operator ==(const dbag& b1, const dbag& b2);
	bool erase_one(const value_type& target);
	size_type count(const value_type& target) const;
	size_type nodes_count() const;
	dnode* start() const;
	value_type grab();
	void insert(const value_type& entry);
	void show_content();
	void sort();
private:
	dnode* head_ptr;
	size_type many_nodes;
};
