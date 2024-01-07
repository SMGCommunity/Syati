#pragma once

#include "nw4r\misc.h"
#include "inlines.h"

namespace nw4r
{

namespace ut
{

class LinkListNode;

namespace detail {
    class LinkListImpl;
}

namespace detail {

template <typename T,
    typename Difference = PtrDiff,
    typename Pointer = T*,
    typename Reference = T&>
class Iterator {
    public:
    typedef T value_type;
    typedef Difference difference_type;
    typedef Pointer pointer;
    typedef Reference reference;
};

template <typename TIt>
class ReverseIterator : 
    public detail::Iterator<typename TIt::value_type,
    typename TIt::difference_type, typename TIt::pointer,
    typename TIt::reference> {
    public:
    typedef detail::Iterator<typename TIt::value_type,
    typename TIt::difference_type, typename TIt::pointer,
    typename TIt::reference> Base;
    
    typedef ReverseIterator<TIt> Self;
    typedef typename Base::pointer pointer;
    typedef typename Base::reference reference;

    explicit ReverseIterator() {}
    explicit ReverseIterator(TIt it) : mCurrent(it) {}
    template<typename T>
    explicit ReverseIterator(const ReverseIterator<T>& rhs);

    TIt GetBase() const { return mCurrent; }
    reference operator*() const { 
        TIt tmp = mCurrent; return (*--tmp);
    }
    pointer operator->() const { return (&**this); }

    Self& operator++() { (void)--mCurrent; return *this; }
    Self operator++(int) {
        Self tmp = *this;
        (void)--mCurrent;
        return tmp;
    }
    Self& operator--() { (void)++mCurrent; return *this; }
    Self operator--(int) { 
        Self tmp = *this; 
        (void)++mCurrent;
        return tmp;
    }

    friend bool operator==(const Self& r1, const Self& r2) {
        return r1.mCurrent == r2.mCurrent;
    }
    friend bool operator!=(const Self &r1, const Self& r2) {
        return !(r1==r2);
    }

    TIt mCurrent;
};

}

class LinkListNode : private NonCopyable {
    public:
    typedef LinkListNode Self;

    explicit LinkListNode() : mNext(0), mPrev(0) {}

    Self* GetNext() const { return mNext; }
    Self* GetPrev() const { return mPrev; }

    friend bool operator==(const Self& r1, const Self& r2) {
        return &r1==&r2;
    }
    friend bool operator!=(const Self& r1, const Self& r2) {
        return !(r1 == r2);
    }

    Self* mNext;
    Self* mPrev;
};

namespace detail {

class LinkListImpl : private NonCopyable {

public:
typedef LinkListImpl Self;
typedef unsigned long size_type;
typedef PtrDiff difference_type;

typedef LinkListNode Node;
typedef Node value_type;
typedef value_type* pointer;
typedef const value_type* const_pointer;
typedef value_type& reference;
typedef const value_type& const_reference;

class Iterator;
class ConstIterator;

class Iterator : public detail::Iterator<value_type> {

public:
typedef Iterator TIt;
typedef detail::Iterator<value_type> TBaseIt;

explicit Iterator() : mPointer(0) {}

reference operator*() const { return *mPointer; }
pointer operator->() const { return mPointer; }

TIt& operator++() {
    mPointer = mPointer->GetNext();
    return *this;
}
TIt operator++(int) {
    const TIt it(*this);
    (void)++*this;
    return it;
}
TIt& operator--() {
    mPointer = mPointer->GetPrev();
    return *this;
}
TIt operator--(int) {
    const TIt it(*this);
    (void)--*this;
    return it;
}

friend bool operator==(TIt it1, TIt it2) {
    return it1.mPointer == it2.mPointer;
}
friend bool operator!=(TIt it1, TIt it2) {
    return !(it1==it2);
}

explicit Iterator(pointer p) : mPointer(p) {}

pointer mPointer;

friend class LinkListImpl;
friend class ConstIterator;

};
typedef Iterator Iterator_alias_;

class ConstIterator : public detail::Iterator<value_type> {
public:
typedef ConstIterator TIt;
typedef detail::Iterator<value_type> TBaseIt;
typedef const_pointer pointer;
typedef const_reference reference;

explicit ConstIterator() : mPointer(0) {}
ConstIterator(Iterator_alias_ it) : mPointer(it.mPointer) {}

reference operator*() const { 
    return *mPointer;
}
pointer operator->() const { return mPointer; }

TIt& operator++() {
    mPointer = mPointer->GetNext();
    return *this;
}
TIt operator++(int) {
    const TIt it(*this);
    (void)++*this;
    return it;
}
TIt& operator--() {
    mPointer = mPointer->GetPrev();
    return *this;
}
TIt operator--(int) {
    const TIt it(*this);
    (void)--*this;
    return it;
}

friend bool operator==(TIt it1, TIt it2) {
    return it1.mPointer == it2.mPointer;
}
friend bool operator!=(TIt it1, TIt it2) {
    return !(it1==it2);
}

explicit ConstIterator(pointer p) : mPointer(p) {}

pointer mPointer;

friend class LinkListImpl;
};

typedef detail::ReverseIterator<Iterator> ReverseIterator;
typedef detail::ReverseIterator<ConstIterator> ConstReverseIterator;

explicit LinkListImpl() { Initialize_(); }
~LinkListImpl();

size_type GetSize() const {
    return mSize;
}
bool IsEmpty() const {
    return mSize == 0;
}

Iterator GetBeginIter() {
    return Iterator(mNode.GetNext());
}
ConstIterator GetBeginIter() const {
    return ConstIterator(mNode.GetNext());
}
Iterator GetEndIter() {
    return Iterator(&mNode);
}
ConstIterator GetEndIter() const {
    return ConstIterator(&mNode);
}

ReverseIterator GetBeginReverseIter() {
    return ReverseIterator(GetEndIter());
}
ConstReverseIterator GetBeginReverseIter() const {
    return ConstReverseIterator(GetEndIter());
}
ReverseIterator GetEndReverseIter() {
    return ReverseIterator(GetBeginIter());
}
ConstReverseIterator GetEndReverseIter() const {
    return ConstReverseIterator(GetBeginIter());
}

reference GetFront() {
    return *GetBeginIter();
}
const_reference GetFront() const {
    return *GetBeginIter();
}
reference GetBack() {
    return *--GetEndIter();
}
const_reference GetBack() const {
    return *--GetEndIter();
}

void PushFront(pointer p) {
    (void)Insert(GetBeginIter(), p);
}
void PushBack(pointer p) {
    (void)Insert(GetEndIter(), p);
}
void PopFront() {
    (void)Erase(GetBeginIter());
}
void PopBack() {
    (void)Erase(--GetEndIter());
}

Iterator Insert(Iterator it, pointer p);
Iterator Erase(pointer p);
Iterator Erase(Iterator it);
Iterator Erase(Iterator itFirst, Iterator itLast);

void Clear();

void Reverse();

static Iterator GetIteratorFromPointer(pointer p) {
    return Iterator(p);
}
static ConstIterator GetIteratorFromPointer(const_pointer p) {
    return ConstIterator(p);
}

void Initialize_() {
    mSize = 0;
    mNode.mNext = &mNode;
    mNode.mPrev = &mNode;
}

size_type mSize;
Node mNode;

};

}

template <typename T, PtrDiff TNOffset>
class LinkList : public detail::LinkListImpl {
    public:
    typedef detail::LinkListImpl Base;
    typedef LinkList Self;
    using Base::Node;
    using Base::size_type;
    using Base::difference_type;

    typedef T value_type;
    typedef value_type* pointer;
    typedef const value_type* const_pointer;
    typedef value_type& reference;
    typedef const value_type& const_reference;

    typedef Base::Iterator TIt_base_;
    typedef Base::ConstIterator TItC_base_;

    class Iterator;
    class ConstIterator;

    class Iterator : public detail::Iterator<value_type> {
        typedef Iterator TIt;
        typedef detail::Iterator<value_type> TBaseIt;

        explicit Iterator() {}

        reference operator*() const {
            pointer p = operator->();
            return *p
        }
        pointer operator->() const {
            return GetPointerFromNode(it_.operator->());
        }

        TIt& operator++() {
            (void)++it_;
            return *this;
        }
        TIt operator++(int) {
            const TIt it(*this);
            (void)++*this;
            return it;
        }
        TIt& operator--() {
            (void)--it_;
            return *this;
        }
        TIt operator--(int) {
            const TIt it(*this);
            (void)--*this;
            return it;
        }
        

        explicit Iterator(TIt_base_ it) : it_(it) {}

        TIt_base_ it_;

        friend class Self;
        friend class ConstIterator;
    };

    typedef Iterator Iterator_alias_;

    class ConstIterator : public detail::Iterator<value_type> {
        public:
        typedef ConstIterator TIt;
        typedef detail::Iterator<value_type> TBaseIt;
        typedef const_pointer pointer;
        typedef const_reference reference;

        explicit ConstIterator() {}
        ConstIterator(Iterator_alias_ it) : it_(it.it_) {}

        reference operator*() const {
            pointer p = operator->();
            return *p;
        }
        pointer operator->() const {
            return GetPointerFromNode(it_.operator->());
        }

        TIt& operator++() {
            (void)++it_;
            return this;
        }
        TIt operator++(int) {
            const TIt it(*this);
            (void)++*this;
            return it;
        }
        TIt& operator--() {
            (void)--it_;
            return *this;
        }
        TIt operator--(int) {
            const TIt it(*this);
            (void)--*this;
            return it;
        }

        friend bool operator==(TIt it1, TIt it2) {
            return it1.it_ == it2.it_;
        }
        friend bool operator!=(TIt it1, TIt it2) {
            return !(it1 == it2);
        }

        explicit ConstIterator(TItC_base_ it) : it_(it) {}

        TItC_base_ it_;

        friend class Self;
    };

    typedef detail::ReverseIterator<Iterator> ReverseIterator;
    typedef detail::ReverseIterator<ConstIterator> ConstReverseIterator;

    explicit LinkList() {}

    using Base::GetSize;
    using Base::IsEmpty;

    Iterator GetBeginIter() {
        return Iterator(Base::GetBeginIter());
    }
    ConstIterator GetBeginIter() const {
        return ConstIterator(const_cast<Self*>(this)->GetBeginIter());
    }
    Iterator GetEndIter() { 
        return Iterator(Base::GetEndIter());
    }
    ConstIterator GetEndIter() const {
        return ConstIterator(const_cast<Self*>(this)->GetEndIter());
    }

    ReverseIterator GetBeginReverseIter() {
        return ReverseIterator(GetEndIter());
    }
    ConstReverseIterator GetBeginReverseIter() const {
        return ConstReverseIterator(GetEndIter());
    }
    ReverseIterator GetEndReverseIter() {
        return ReverseIterator(GetBeginIter());
    }
    ConstReverseIterator GetEndReverseIter() const {
        return ConstReverseIterator(GetBeginIter());
    }

    reference GetFront() {
        return *GetBeginIter();
    }
    const_reference GetFront() const {
        return *GetBeginIter();
    }
    reference GetBack() {
        return *--GetEndIter();
    }
    const_reference GetBack() const {
        return *--GetEndIter();
    }

    Iterator Insert(Iterator it, pointer p) {
        return 
        Iterator(Base::Insert(it.it_, GetNodeFromPointer(p)));
    }
    void PushFront(pointer p) {
        (void)Insert(GetBeginIter(), p);
    }
    void PushBack(pointer p) {
        (void)Insert(GetEndIter(), p);
    }

    using Base::PopFront;
    using Base::PopBack;

    Iterator Erase(Iterator it) {
        return Iterator(Base::Erase(it.it_);)
    }
    Iterator Erase(Iterator itFirst, Iterator itLast) {
        return Iterator(Base::Erase(itFirst.it_, itLast.it_));
    }
    Iterator Erase(pointer p) {
        return Iterator(Base::Erase(GetNodeFromPointer(p)));
    }

    using Base::Clear;
    using Base::Reverse;


    static Iterator GetIteratorFromPointer(Node* p) {
        return Iterator(Base::GetIteratorFromPointer(p));
    }
    static ConstIterator GetIteratorFromPointer(const Node* p) {
        return ConstIterator(Base::GetIteratorFromPointer(p));
    }
    static Iterator GetIteratorFromPointer(pointer p) {
        return GetIteratorFromPointer(GetNodeFromPointer(p));
    }
    static ConstIterator GetIteratorFromPointer(const_pointer p) {
        return GetIteratorFromPointer(GetNodeFromPointer(p));
    }

    static Node* GetNodeFromPointer(pointer p) {
        return reinterpret_cast<Node*>
        (reinterpret_cast<IntPtr>(p)+TNOffset);
    }
    static const Node* GetNodeFromPointer(const_pointer p) {
        return reinterpret_cast<const Node*>
        (reinterpret_cast<IntPtr>(p)+TNOffset);
    }
    static pointer GetPointerFromNode(Node* p) {
        return reinterpret_cast<pointer>
        (reinterpret_cast<IntPtr>(p)-TNOffset);
    }
    static const_pointer GetPointerFromNode(const Node* p) {
        return reinterpret_cast<const_pointer>
        (reinterpret_cast<IntPtr>(p)-TNOffset);
    }
};

}

}