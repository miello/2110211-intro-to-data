#ifndef __STUDENT_H__
#define __STUDENT_H__

#include <algorithm>
#include <vector>
#include "map_bst.h"

template <typename KeyT,typename MappedT, typename CompareT >
size_t CP::map_bst<KeyT,MappedT,CompareT>::process(node* n) {
  if(n == nullptr) return 0;
  int leftH = process(n->left);
  int rightH = process(n->right);

  return 1 + leftH + rightH;
}

template <typename KeyT,typename MappedT, typename CompareT >
std::pair<KeyT,MappedT> CP::map_bst<KeyT,MappedT,CompareT>::subtree(map_bst<KeyT,MappedT,CompareT> &left, map_bst<KeyT,MappedT,CompareT> &right) {
  if(mSize == 0) return std::pair<KeyT,MappedT>();

  left.mRoot = this->mRoot->left;
  right.mRoot = this->mRoot->right;

  if(left.mRoot) left.mRoot->parent = nullptr;
  if(right.mRoot) right.mRoot->parent = nullptr;

  left.mLess = this->mLess;
  right.mLess = this->mLess;

  left.mSize = process(left.mRoot);
  right.mSize = mSize - left.mSize - 1;

  mRoot->left = nullptr;
  mRoot->right = nullptr;
  mRoot->parent = nullptr;

  mSize = 1;

  return mRoot->data;
}

#endif

