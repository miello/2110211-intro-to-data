// Your code here

std::pair<KeyT, std::pair<int, int>> ImbalanceNodeHelper(node *now) {
    if(now == nullptr) return {KeyT(), {-1, -1}};

    auto left = ImbalanceNodeHelper(now->left);
    auto right = ImbalanceNodeHelper(now->right);

    int sz = 1 + std::max(left.second.first, right.second.first);
    int imbalanceSz = left.second.first - right.second.first;
    imbalanceSz = imbalanceSz < 0 ? -imbalanceSz: imbalanceSz;

    KeyT mn;
    int mxImbalance;
    if(left.second.second == right.second.second) {
        if(mLess(left.first, right.first)) {
            mn = left.first;
        } else {
            mn = right.first;
        }
        mxImbalance = left.second.second;
    } else if(left.second.second > right.second.second) {
        mxImbalance = left.second.second;
        mn = left.first;
    } else {
        mxImbalance = right.second.second;
        mn = right.first;
    }

    if(mxImbalance < imbalanceSz) {
        mxImbalance = imbalanceSz;
        mn = now->data.first;
    } else if(mxImbalance == imbalanceSz) {
        if(mLess(now->data.first, mn)) {
            mn = now->data.first;
        }
    }

    return {mn, {sz, mxImbalance}};
    
}

KeyT getValueOfMostImbalanceNode() {
    return ImbalanceNodeHelper(mRoot).first;
}