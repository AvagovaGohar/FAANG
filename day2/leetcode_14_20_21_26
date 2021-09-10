//14 
string longestCommonPrefix(vector<string>& strs) {
        string str = strs[0];
        for(int i = 1; i<strs.size(); ++i){
            string tmp = "";
            for(int j = 0;j<strs[i].size() && j<str.size();++j ){
                if(str[j] == strs[i][j]){
                    tmp+=str[j];
                }else{
                    break;
                }
            }
            str = tmp;
            
        }
        return str;
    }
//20
/...
  
//21
  ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
       if(l1 == nullptr){
           return l2;
       }
       if(l2 == nullptr){
           return l1;
       }
    if (l1->val > l2->val) {
        ListNode* tmp = l1;
        l1 = new ListNode;
        l1->val = l2->val;
        l1->next = tmp;
        l2 = l2->next;
    }
    ListNode* start = l1;

    while (l1->next != nullptr && l2 != nullptr) {
        if (l1->next->val >= l2->val) {
            ListNode* tmp = l1->next;
            l1->next = new ListNode;
            l1 = l1->next;
            l1->val = l2->val;
            l1->next = tmp;
            l2 = l2->next;
        }
        else {
            l1 = l1->next;
        }
        
    }
    while (l2 != nullptr) {
        l1->next = new ListNode;
        l1 = l1->next;
        l1->val = l2->val;
        l2 = l2->next;
    }
    return start;
}

// 26
int removeDuplicates(vector<int>& nums) {
        auto it = unique(nums.begin(),nums.end());
        auto it2 = nums.begin();
        int i = 0;
        while(it2!=it && it2!=nums.end()){
            ++i;
            ++it2;
        }
        return i;
    }

//3 
//...
