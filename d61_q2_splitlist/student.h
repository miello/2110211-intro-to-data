void splitList(CP::list<T>& list1, CP::list<T>& list2) {
    int left = mSize / 2 + (mSize & 1);
    int cnt = left - 1;
    
    if(mSize == 0) return;

    node *now = mHeader->next;
    while(cnt--) {
        now = now->next;
    }

    // Update list2
    now->next->prev = list2.mHeader->prev;
    list2.mHeader->prev->next = now->next;
    list2.mHeader->prev = mHeader->prev;
    mHeader->prev->next = list2.mHeader;

    list2.mSize += mSize - left;

    // Update list1
    list1.mHeader->prev->next = mHeader->next;
    mHeader->next->prev = list1.mHeader->prev;
    list1.mHeader->prev = now;
    now->next = list1.mHeader;

    list1.mSize += left;

    // Reset this node
    mHeader->next = mHeader;
    mHeader->prev = mHeader;
    mSize = 0;
}
