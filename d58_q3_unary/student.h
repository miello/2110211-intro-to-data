#ifndef __STUDENT_H__
#define __STUDENT_H__

template <typename KeyT,
          typename MappedT,
          typename CompareT>
size_t CP::map_bst<KeyT,MappedT,CompareT>::process(node* ptr) const {
  if(ptr == nullptr) return 0;
  
  int foundLeft = ptr->left != nullptr;
  int foundRight = ptr->right != nullptr;

  int unary_left_node = process(ptr->left);
  int unary_right_node = process(ptr->right);

  return (foundLeft ^ foundRight) + unary_left_node + unary_right_node; 


  return 0;
}

template <typename KeyT,
          typename MappedT,
          typename CompareT>
size_t CP::map_bst<KeyT,MappedT,CompareT>::count_unary() const {
  return process(mRoot);
}

#endif
