#pragma once
#include <iostream>
#include <type_traits>
#include <cmath>


template<class T>
struct vertex {
	T x;
	T y;
	vertex<T>& operator=(vertex<T> A);
};

template<class T>
std::istream& operator>>(std::istream& is, vertex<T>& p) {
	is >> p.x >> p.y;
	return is;
}

template<class T>
std::ostream& operator<<(std::ostream& os, vertex<T> p) {
	os << '(' << p.x << ' ' << p.y << ')';
	return os;
}

template<class T>
vertex<T> operator+(const vertex<T>& A, const vertex<T>& B) {
	vertex<T> res;
	res.x = A.x + B.x;
	res.y = A.y + B.y;
	return res;
}

template<class T>
vertex<T>& vertex<T>::operator=(const vertex<T> A) {
	this->x = A.x;
	this->y = A.y;
	return *this;
}

template<class T>
vertex<T> operator+=(vertex<T>& A, const vertex<T>& B) {
	A.x += B.x;
	A.y += B.y;
	return A;
}

template<class T>
double vector (vertex<T>& A, vertex<T>& B) {
	double res = sqrt(pow(B.x - A.x, 2) + pow(B.y - A.y, 2));
	return res;
}

template<class T>
struct is_vertex : std::false_type {};

template<class T>
struct is_vertex<vertex<T>> : std::true_type {};

