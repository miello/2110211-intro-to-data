void shift(int k) {
  	if(mSize <= 1) return;
	
	int pos = abs(k) % mSize;

	if(k < 0) {
		pos = mSize - pos;
	}

	pos %= mSize;

	node* head = mHeader->next;
	while(pos--) {
		head = head->next;
	}

	// Remove mHeader from current position
	mHeader->prev->next = mHeader->next;
	mHeader->next->prev = mHeader->prev;

	// insert mHeader before newHead position
	mHeader->next = head;
	mHeader->prev = head->prev;

	head->prev->next = mHeader;
	head->prev = mHeader;
}