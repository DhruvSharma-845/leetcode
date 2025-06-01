#pragma once


template <typename T>
struct GenericListNode {
    T val;
    GenericListNode<T> *next;

    GenericListNode() : val(0), next(nullptr) {}
    GenericListNode(T x) : val(x), next(nullptr) {}
    GenericListNode(T x, GenericListNode<T> *next) : val(x), next(next) {}
};

using ListNode = GenericListNode<int>;