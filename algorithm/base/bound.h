/*************************************************************************
    > File Name: bound.h
    > Author: pjg
    > Mail: 
    > Created Time: 2023/6/26 11:45:15
 ************************************************************************/

#ifndef __BOUND_H__
#define __BOUND_H__

#define _BASE_BEGIN namespace base {
#define _BASE_END }
#define _BASE ::base::

_BASE_BEGIN

template <typename T = void>
struct less
{
    bool operator()(const T& left, const T& right)
    {
        return left < right;
    }
};

template<>
struct less<void>
{
    template<typename T1, typename T2>
        constexpr auto operator()(T1&& left, T2&& right) const
        -> decltype(static_cast<T1&&>(left) < static_cast<T2&&>(right))
        {
            return (static_cast<T1&&>(left) < static_cast<T2&&>(right));
        }
};

template<typename Iter,
    typename Val,
    typename Pred>
    Iter lower_bound(Iter first, Iter last, const Val& v, Pred pred)
{
    auto count = last - first;
    while (count > 0)
    {
        auto count2 = count >> 1;
        auto mid = first + count2;
        if (pred(*mid, v))
        {
            first = mid + 1;
            count -= count2 + 1;
        }
        else
        {
            count = count2;
        }
    }
    return first;
}

template<typename Iter,
    typename Val>
    Iter lower_bound(Iter first, Iter last, const Val& v)
{
    return _BASE lower_bound(first, last, v, _BASE less<>());
}

template<typename Iter,
    typename Val,
    typename Pred>
    Iter upper_bound(Iter first, Iter last, const Val& v, Pred pred)
{
    auto count = last - first;
    while (count > 0)
    {
        auto count2 = count >> 1;
        auto mid = first + count2;
        if (pred(v, *mid))
        {
            count = count2;
        }
        else
        {
            first = mid + 1;
            count -= count2 + 1;
        }
    }
    return first;
}

template<typename Iter,
    typename Val>
    Iter upper_bound(Iter first, Iter last, const Val& v)
{
    return _BASE upper_bound(first, last, v, _BASE less<>());
}

template<typename Iter,
	typename Value,
	typename Pred>
	bool binary_search(Iter first, Iter last, const Value& v, Pred pred)
{
	auto iter = _BASE lower_bound(first, last, v, pred);
	return iter != last && !pred(v, iter);
}

template<typename Iter,
	typename Value>
	bool binary_search(Iter first, Iter last, const Value& v)
{
	return _BASE binary_search(first, last, v, _BASE less<>());
}

_BASE_END

#endif /*__BOUND_H__*/
