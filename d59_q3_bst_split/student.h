#ifndef __STUDENT_H_
#define __STUDENT_H_

template <typename KeyT,
          typename MappedT,
          typename CompareT >
CP::map_bst<KeyT,MappedT,CompareT> CP::map_bst<KeyT,MappedT,CompareT>::split(KeyT val) {
  //your code here
  CP::map_bst<KeyT,MappedT,CompareT> result;
  node *tmp = mRoot;
  node *less = nullptr, *more = nullptr;

  while(tmp != nullptr) {
    // Reset parent
    if(tmp->parent != nullptr) {
      if(tmp->parent->left == tmp) {
        tmp->parent->left = nullptr;
      } else if(tmp->parent->right == tmp) {
        tmp->parent->right = nullptr;  
      }
      tmp->parent = nullptr;
    }

    // Case more than or equal val
    if(!mLess(tmp->data.first, val)) {
      if(more == nullptr) {
        if(tmp == mRoot) {
          mRoot = nullptr;
        }
        more = tmp;
        result.mRoot = tmp;
      } else {
        tmp->parent = more;
        if(!mLess(more->data.first, tmp->data.first)) {
          more->left = tmp;
        } else {
          more->right = tmp;
        }
        more = tmp;
      }
      tmp = tmp->left;
    } 
    // Case less than val
    else {
      if(less == nullptr) {
        less = tmp;
        mRoot = tmp;
      } else {
        tmp->parent = less;
        if(!mLess(less->data.first, tmp->data.first)) {
          less->left = tmp;
        } else {
          less->right = tmp;
        }
        less = tmp;
      }
      tmp = tmp->right;
    }
  }
  return result;
}

#endif
