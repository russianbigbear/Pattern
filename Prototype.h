#ifndef _PROTO
#define _PROTO
template <class T>
class Prototype {
public:
	virtual T* Clone() = 0;
};
#endif