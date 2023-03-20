#pragma once
#include <string>
#include <string.h>

class BufferReader
{
	unsigned char* m_buffer;
	size_t m_readpos;
	size_t m_readpos_saved;
	size_t m_size;
public:
	BufferReader(void* buffer, size_t size)
		:
		m_buffer((unsigned char*)buffer), m_size(size), m_readpos(0)
	{
	}

	void save()
	{
		m_readpos_saved = m_readpos;
	}

	//careful, better would be to push it to a std::stack<>
	void restore()
	{
		m_readpos = m_readpos_saved;
	}

	size_t tell() const
	{
		return m_readpos;
	}

	void advance(int n)
	{
		m_readpos += n;
	}

	int peek(int dist)
	{
		if (m_readpos + dist < 0 || m_readpos + dist >= m_size)
			return -1;
		return m_buffer[m_readpos + dist];
	}

	void set_cursor(int n)
	{
		m_readpos = n;
	}

	std::string read_string(int eof_char = 0)
	{
		std::string s;
		while (1)
		{
			char c;
			size_t pos = m_readpos;
			if(!read(&c, 1, sizeof(c)))
				break;
			if (c == eof_char)
			{
				m_readpos = pos;
				break;
			}
			s.push_back(c);
		}
		return s;
	}

	void seek(int ch)
	{
		while (1)
		{
			if (m_readpos >= m_size)
				break;
			int tmp = m_buffer[m_readpos++];
			if (tmp == ch)
				break;
		}
	}

	bool read(void *out, size_t element_size/*unused*/, size_t n)
	{
		size_t total = element_size * n;
		if (m_readpos + total > m_size)
			return false;
		memcpy(out, &m_buffer[m_readpos], total);
		m_readpos += total;
		return true;
	}
};