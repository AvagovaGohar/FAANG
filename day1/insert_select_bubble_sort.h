#include <iostream>
#include <algorithm>
#include <iterator>

//bubble
template<typename IT>
void bubble_sort(IT start, IT end) {
	while (start != end) {
		auto cur = start;
		auto prev = cur++;
		while (!(cur == end))
		{
			if (*cur < *prev) {
				auto tmp = std::move(*cur);
				*cur = std::move(*prev);
				*prev = tmp;
			}
			++cur;
			++prev;
		}
		cur = start;
		prev = cur++;
		while (cur != end)
		{
			++cur;
			++prev;
		}
		end = prev;
	}
}

//insertion
template<typename IT>
bool minus_iterator(IT start, IT end, IT& cur) {
	if (cur == start)
		return false;
    
	auto cur_tmp = start;
	auto prev_tmp = cur_tmp++;
	
	while (cur_tmp != cur)
	{
		++cur_tmp;
		++prev_tmp;
	}
	cur = prev_tmp;
	return true;
}

template<typename IT>
void insertion_sort(IT start, IT end) {
	auto tmp_start = end;
	while (true)
	{
		auto cur_tmp = tmp_start;
		if (cur_tmp == end) {
			minus_iterator(start, end, tmp_start);
			continue;
		}
		auto prev_tmp = cur_tmp++;
		auto key = *prev_tmp;
		while (cur_tmp !=end && key > *cur_tmp)
		{
			*prev_tmp = *cur_tmp;
			++cur_tmp;
			++prev_tmp;
		}
		*prev_tmp = key;
		bool t = minus_iterator(start, end, tmp_start);
		if (!t) {
			break;
		}
	}
}

//selection
template<typename IT>
void selection_sort(IT start, IT end){
	auto cur = start;
	while (start != end) {
		cur = start;
		++cur;
		auto min = start;
		while (cur !=end)
		{
			if (*min > * cur)
				min = cur;
			++cur;
		}
		auto tmp = std::move(*min);
		*min = std::move(*start);
		*start = tmp;
		++start;
	}
}
