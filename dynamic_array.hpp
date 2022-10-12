#include <cstddef>
#include <cstring>
#include <stdexcept>
#include <iterator>

template <typename T> class dynamic_array
{
	private:
		T* m_data;
		std::size_t m_size;
	public:
		class iterator
		{
			private:
				T* p;
			public:
				using iterator_category = std::random_access_iterator_tag;
    			using value_type = T;
    			using difference_type = std::ptrdiff_t;
    			using pointer = T*;
    			using reference = T&;
				iterator(T* ptr) : p(ptr) {}
				T& operator*() const
				{
					return *p;
				}
				T* operator->() const
				{
					return p;
				}
				iterator& operator++()
				{
					p++;
					return *this;
				}
				iterator operator++(int)
				{
					iterator it = *this;
					++(*this);
					return it;
				}
				iterator& operator--()
				{
					p--;
					return *this;
				}
				iterator operator--(int)
				{
					iterator it = *this;
					--(*this);
					return it;
				}
				bool operator==(const iterator& b)
				{
					return this->p == b.p;
				}
				bool operator!=(const iterator& b)
				{
					return !(*this == b);
				}
				bool operator<(const iterator& b)
				{
					return this->p < b.p;
				}
				bool operator>(const iterator& b)
				{
					return this->p > b.p;
				}
				iterator& operator-(const std::ptrdiff_t i)
				{
					iterator it = *this;
					*(this) - i;
					return it;
				}
				iterator& operator+(const std::ptrdiff_t i)
				{
					iterator it = *this;
					*(this) + i;
					return it;
				}
				T& operator[](const std::ptrdiff_t i)
				{
					return this->p[i];
				}
		};
		dynamic_array(std::size_t size)
		{
			m_size = size;
			m_data = new T[m_size]();
		}
		dynamic_array(const dynamic_array<T>& r)
		{
			this->m_size = r.m_size;
			this->m_data = new T[this->m_size];
			std::memcpy(this->m_data, r.m_data, sizeof r.m_data);
		}
		std::size_t size() const { return m_size; }
		iterator begin() {return iterator(m_data); }
		const iterator cbegin() {return iterator(m_data); }
		iterator end() {return iterator(m_data + m_size); }
		const iterator cend() {return iterator(m_data + m_size); }
		T& operator[](const std::size_t index) const
		{
			if (index >= m_size)
			{
				throw std::out_of_range("index is out of range");
			}
			return m_data[index];
		}
		~dynamic_array() { delete[] m_data; }
};