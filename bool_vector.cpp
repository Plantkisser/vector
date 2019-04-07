#define BIT_AMOUNT 8
#include <iostream>


template <typename T>
class Vector;

template <>
class Vector<bool>;



class Proxy
{
	private:
		int index_;

		Vector<bool>* vect_;
	public:
		void connect(Vector<bool>* vect , int index);
		~Proxy();
		Proxy();

		void set_bit (bool value);
		bool get_bit ();

		void operator=(const bool& val);

		operator bool(); 
};



template<>
class Vector <bool>
{
	private:
		char* data_;
		int size_;
		int capacity_;

		Proxy info;
	public:
		void set_bit(bool value, int index);

		bool at(int index);

		void push(bool value);

		bool pop ();

		Proxy operator[](int index);

		Vector(int capacity);

		~Vector();
};






Vector<bool>:: Vector(int capacity)
{
	capacity_ = capacity;
	size_ = 0;
	data_ = new char [capacity];
	info.connect(this, 0);
}





Vector<bool>:: ~Vector()
{
	delete[] data_;

	data_ = nullptr;
}


bool Vector<bool>:: at(int index)
{
	int char_ind = index / BIT_AMOUNT;

	int bit_ind = index % BIT_AMOUNT;

	int checker = 1;

	checker <<= BIT_AMOUNT - 1 - bit_ind;

	return (data_[char_ind] & checker); 
}

void Vector<bool>:: push(bool value)
{
	set_bit(value, size_);

	size_++;

	return;
}

bool Vector<bool>:: pop ()
{
	size_--;

	return at(size_);
}

void Proxy:: connect(Vector<bool>* vect, int index)
{
	vect_ = vect;
	index_ = index;
	return;
}

Proxy:: Proxy():
	vect_(nullptr),
	index_(0)
{
}

Proxy:: ~Proxy()
{

}

Proxy Vector<bool>:: operator[](int index)
{

	info.connect(this, index);

	return info;
}

void Vector<bool>:: set_bit(bool value, int index)
{
	int char_ind = index / BIT_AMOUNT;                                     //  val = 00000001            ->  val =                 00001000                       00001000                                                                                           
                                                                           //  data[char_ind] = 10101001 ->  data[char_ind] =      10101001 |    data[char_ind] = 10100001 -> data[char_ind] = 10101001                                                                                                                      
	int bit_ind = index % BIT_AMOUNT;                                      //  index = 4 -> char_ind = 0, bit_ind = 4 -> changer = 11110111 | ->  set bit_ind 0                                                                                                                       
                                                                                                                                                                                      

	int val = value;

	val <<= BIT_AMOUNT - 1 - bit_ind;

	int changer = 1;

	changer <<= BIT_AMOUNT - 1 - bit_ind;

	changer = ~changer;

	data_[char_ind] = data_[char_ind] & changer;

	data_[char_ind] = data_[char_ind] | val;
}

void Proxy:: set_bit(bool value)
{
	vect_->set_bit(value, index_);
}

bool Proxy:: get_bit()
{
	return vect_->at(index_);
}







void Proxy:: operator=(const bool& val)
{
	set_bit(val);
}


int main()
{
	Vector<bool> v(10);

	v.push(1);

	v.push(0);

	v.push(0);

	bool fl = true;

	v[2] = fl;

	std:: cout << v[2];
 
	
	
	return 0;
}


Proxy:: operator bool()
{
	return get_bit();
}








