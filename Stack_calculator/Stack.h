template <class Item>
class Stack
{
public:
	Stack(size_t size);
	~Stack();
	void push(const Item& entry);
	void pop();
	Item top() const;
	bool empty() const;
	size_t size() const;

private:
	Item* data;
	size_t used;
};
