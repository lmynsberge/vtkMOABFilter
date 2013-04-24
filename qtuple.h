#ifndef QTUPLE_H
#define QTUPLE_H

#include "QtCore/qdatastream.h"

QT_BEGIN_HEADER

QT_BEGIN_NAMESPACE
QT_MODULE(Core)

template <class T1, class T2, class T3>

struct QTuple
{
    typedef T1 first_type;
    typedef T2 second_type;
	typedef T3 third_type;
	
	QTuple() : first(T1()), second(T2()), third(T2()) {}
	QTuple(const T1 &t1, const T2 &t2, const T3 & t3) : first(t1), second(t2), third(t3) {}
	
	QTuple<T1, T2, T3> &operator=(const QTuple<T1, T2, T3> &other)
	{ first = other.first; second = other.second; third = other.third; return *this; }
	
	T1 first;
	T2 second;
	T3 third;
	
};
///*
template <class T1, class T2, class T3>
Q_INLINE_TEMPLATE bool operator==(const QTuple<T1, T2, T3> &p1, const QTuple<T1, T2, T3> &p2)
{ return p1.first == p2.first && p1.second == p2.second && p1.third == p2.third; }

template <class T1, class T2, class T3>
Q_INLINE_TEMPLATE bool operator!=(const QTuple<T1, T2, T3> &p1, const QTuple<T1, T2, T3> &p2)
{ return !(p1 == p2); }

template <class T1, class T2, class T3>
Q_INLINE_TEMPLATE bool operator<(const QTuple<T1, T2, T3> &p1, const QTuple<T1, T2, T3> &p2)
{
    return p1.first < p2.first || (!(p2.first < p1.first) && p1.second < p2.second) && p1.third < p2.third;
}

template <class T1, class T2, class T3>
Q_INLINE_TEMPLATE bool operator>(const QTuple<T1, T2, T3> &p1, const QTuple<T1, T2, T3> &p2)
{
    return p2 < p1;
}

template <class T1, class T2, class T3>
Q_INLINE_TEMPLATE bool operator<=(const QTuple<T1, T2, T3> &p1, const QTuple<T1, T2, T3> &p2)
{
    return !(p2 < p1);
}

template <class T1, class T2, class T3>
Q_INLINE_TEMPLATE bool operator>=(const QTuple<T1, T2, T3> &p1, const QTuple<T1, T2, T3> &p2)
{
    return !(p1 < p2);
}
//*/
template <class T1, class T2, class T3>
Q_OUTOFLINE_TEMPLATE QTuple<T1, T2, T3> qMakeTuple(const T1 &x, const T2 &y, const T3 &z)
{
    return QTuple<T1, T2, T3>(x, y, z);
}

#ifndef QT_NO_DATASTREAM
template <class T1, class T2, class T3>
inline QDataStream& operator>>(QDataStream& s, QTuple<T1, T2, T3>& p)
{
    s >> p.first >> p.second >> p.third;
    return s;
}

template <class T1, class T2, class T3>
inline QDataStream& operator<<(QDataStream& s, const QTuple<T1, T2, T3>& p)
{
    s << p.first << p.second << p.third;
    return s;
}
#endif

QT_END_NAMESPACE

QT_END_HEADER

#endif // QTUPLE_H