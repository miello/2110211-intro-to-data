void replace(const T& x, CP::list<T>& y) {
  iterator head = begin();
  while(head != end()) {
    if(*head == x) {
      iterator targetHead = y.begin();
      iterator tmp = head;

      ++head;
      erase(tmp);

      while(targetHead != y.end()) {
        insert(head, *targetHead);
        ++targetHead;
      }
      
    } else {
      ++head;
    }
  }

}
