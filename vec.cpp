#include <iostream>

typedef int vectype;

class Vector
{
	private:
		vectype* data_;
		int size_;
		int capacity_;
	public:
		Vector(int capacity);

		Vector();

		Vector(const Vector& vec);

		~Vector();

		vectype at(int index);

		vectype& operator[](int idx);

		void operator=(Vector vec);

		vectype& front ();

		vectype& back ();

		boll operator!=(Vector vec);

		boll operator==(Vector vec);
}

vectype&  Vector:: at (vectype index)
{
	if (size_ == 0)
	{
		cout << "ERROR vector is empty";
		return 0;
	}

	assert(0 <= index && index < size_);

	return data_[index];
}

Vector:: Vector():
	data_(new vectype[SATANDART_CAPACITY]),
	size_(0),
	capacity_(SATANDART_CAPACITY)
	{}

Vector:: Vector(int capacity):
	data_(new vectype[capacity]),
	size_(0),
	capacity_(capacity)
	{}

Vector:: Vector(const Vector& vec):
	capacity_(vec.capacity_)
	data_(new vectype[capacity_]),
	size_(0)
	{
		for (int i = 0; i < vec.size_; i++)
			data_[i] = vec.data_[i];
		size_ = vec.size_;
	}

Vector:: ~Vector()
{
	delete[] data_;

	data_ = nullptr;
}

vectype& Vector:: operator[](int idx)
{
	return at[idx];
}


const Vector & Vector:: operator=(const vector& rhs)
{
	{
		Vector copy (rhs);

		swap(copy);

		return *this;
	}
}

void Vector:: swap (Vector rhs)
{
	std:: swap(size_, rhs.size_);
	std:: swap(data_, rhs.data_);
	std:: swap(capacity_, rhs.capacity_);
}



/*const Vector& Vector:: operator=(const vector& v)
{
	this->~Vector();
	new (this) Vector (v);
	return *this;
}

void* Vector::operator new(size_t, void* mem)
{
	return mem;
}*/


/*void Vector:: operator=(Vector vec)
{
	delete[] data_;

	data_ = new vectype [vec.capacity_];

	for (int i = 0; i < vec.size_; i++)
		data_[i] = vec.data_[i];

	size_ = vec.size_
}*/

















vectype& Vector:: front ()
{
	return data_[size_ - 1];
}

vectype& Vector:: back ();
{
	return data_[0];
}

bool Vector:: operator!=(Vector vec)
{
	if (size_ != vec.size_)
		return true;

	for (int i = 0; i < size_; i++)
	{
		if (data_[i] != vec.data_[i])
			return true;
	}

	return false;
}

bool Vector:: operator==(Vector vec)
{
	if (*this != vec)
		return false
	else 
		return true;
}



void Stack:: push(vectype value)
{
	if (error_ != NO_ERRORS)
		return;

	if (size_ < capacity_ - 2)
	{
		data_[size_++] = value; //

		sum_ += (size_ - 1) * value;
	}
	else
	{
		increase_capacity();

		if (error_ != NO_ERRORS)
			return;

		data_[size_++] = value;

		sum_ += (size_ - 1) * value;
	}

	return;
}

stktype Stack:: pop()
{
	if (error_ != NO_ERRORS)
		return 0;

	stktype value = 0;

	if (size_ > 1)
	{
		sum_ -= (--size_) * data_[size_ ];
		value = data_[size_];
	}
	else 
	{
		error_ = NO_ELEMENTS;
		return 0; 
	}

	return value;
}