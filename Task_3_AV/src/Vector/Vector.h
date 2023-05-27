#pragma once
#include <iostream>
#include <iterator>

template<class T>
class OwnIterator;

template<class T>
class Vector {
public:
	typedef OwnIterator<T> iterator;
	typedef OwnIterator<const T> const_iterator;

	Vector(std::initializer_list<T> values) : _size(values.size()), _capacity(_size), p_data(new T[_capacity]) {
		std::copy(values.begin(), values.end(), p_data.get());
	}

	T at(unsigned int index) {
		try {
			return return_value(index);
		}
		catch (const std::exception& ex) {
			std::cout << ex.what() << std::endl;
		}
	}

	void push_back(T value) {
		if (this->capacity() > this->size()) {

		}
		else if (this->capacity() <= this->size()) {

		}
	}

	const unsigned int size() const {
		return _size;
	}

	const unsigned int capacity() const {
		return _capacity;
	}
	
	// Iterators
	iterator begin() {
		return iterator(p_data.get());
	}

	iterator end() {
		return iterator(p_data.get() + _size);
	}

	const_iterator begin() const {
		return const_iterator(p_data.get());
	}

	const_iterator end() const {
		return const_iterator(p_data.get() + _size);
	}

private:
	const T return_value(unsigned int& _index) const {
		if (_index >= this->size())
			throw std::out_of_range("[ERROR]: Index greter than size!");
		return p_data[_index];
	}

	// Variables
	size_t _size;
	size_t _capacity;
	std::unique_ptr<T[]> p_data;
};


template<class T>
class OwnIterator : public std::iterator<std::input_iterator_tag, T> {
	friend class Vector<T>;
public:
	OwnIterator(const OwnIterator& it) : p_it(it.p_it) {}

	bool operator!=(OwnIterator const& other) const {
		return p_it != other.p_it;
	}

	bool operator==(OwnIterator const& other) const {
		return p_it == other.p_it;
	}

	typename OwnIterator::reference operator*() const {
		return *p_it;
	}

	OwnIterator& operator++() {
		++p_it;
		return *this;
	}

private:
	OwnIterator(T* p) : p_it(p) {}

	T* p_it = nullptr;
};

