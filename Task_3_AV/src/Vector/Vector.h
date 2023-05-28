#pragma once
#include <iterator>

template<class T>
class Iterator;

template<class T>
class Vector {
public:
	typedef Iterator<T> iterator;
	typedef Iterator<const T> const_iterator;

	Vector(std::initializer_list<T> values) : _size(values.size()), _capacity(_size), p_data(new T[_capacity]) {
		std::copy(values.begin(), values.end(), p_data.get());
	}

	// Версия инициализации без параметров
	Vector() : _size(0), _capacity(0), p_data(new T[_capacity]) {}

	// получение элемента с обработкой ошибок
	T at(unsigned int index) {
		try {
			return return_value(index);
		}
		catch (const std::exception& ex) {
			std::cout << ex.what() << std::endl;
		}
	}

	// Добавить элемент в контейнер 
	void push_back(const T value) {
		if (this->capacity() > this->size()) {
			this->_size++;
			this->p_data[this->_size - 1] = value;
		}
		else if (this->capacity() <= this->size()) {
			increase_capacity();
			this->_size++;
			this->p_data[this->_size -1] = value;
		}
	}

	// Получить размер контейнера с элементами
	const unsigned int size() const {
		return _size;
	}

	// Получить фактический размер выделенной памяти под контейнер
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

	const const_iterator begin() const {
		return const_iterator(p_data.get());
	}

	const const_iterator end() const {
		return const_iterator(p_data.get() + _size);
	}

private:
	// Functions
	const T return_value(unsigned int& _index) const {
		if (_index >= this->size())
			throw std::out_of_range("[ERROR]: Index greter than size!");
		return p_data[_index];
	}

	void increase_capacity() {
		this->_capacity += this->_size + 1;
		std::unique_ptr<T[]> p_temp(new T[_capacity]);
		for (unsigned int i = 0; i < _size; i++)
			p_temp[i] = this->p_data[i];

		this->p_data.reset();
		this->p_data = std::make_unique<T[]>(_capacity);
		for (unsigned int i = 0; i < _size; i++)
			this->p_data[i] = p_temp[i];

		p_temp.reset();
	}

	// Variables
	size_t _size;
	size_t _capacity;
	std::unique_ptr<T[]> p_data;
};

// Для range based for
template<class T>
class Iterator : public std::iterator<std::input_iterator_tag, T> {
	friend class Vector<T>;
public:
	Iterator(const Iterator& it) : p_it(it.p_it) {}

	bool operator!=(Iterator const& other) const {
		return p_it != other.p_it;
	}

	bool operator==(Iterator const& other) const {
		return p_it == other.p_it;
	}

	typename Iterator::reference operator*() const {
		return *p_it;
	}

	Iterator& operator++() {
		++p_it;
		return *this;
	}

private:
	Iterator(T* p) : p_it(p) {}

	T* p_it = nullptr;
};

