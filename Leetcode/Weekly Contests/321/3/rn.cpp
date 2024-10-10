#include <iostream>
#include <vector>

using namespace std;


struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode* removeNodes(ListNode* head) {
    vector<int> arr;
    vector<int> newArr;
    ListNode* ans = new ListNode();
    
    ListNode* headTemp = head;
    while (headTemp != nullptr){
        arr.push_back(headTemp->val);
        headTemp = headTemp->next;
    }
    
    int curr = 0;
    for (int i = arr.size() - 1; i >= 0; i--){
        if (arr[i] >= curr){
            newArr.push_back(arr[i]);
            curr = arr[i];
        }
    }
    
    ListNode* ansTemp = ans;
    for (int i = newArr.size() - 1; i >= 0; i--){
        ansTemp->val = newArr[i];
        if (i != 0) {
            ansTemp->next = new ListNode();
            ansTemp = ansTemp->next;
        }
    } 
    
    return ans;
}

int main(){
    ListNode* head = new ListNode(5, new ListNode(2, new ListNode(13, new ListNode(3, new ListNode(8)))));
    ListNode* ans = removeNodes(head);
    for (;ans!=nullptr;ans=ans->next){
        cout << ans->val << '\n';
    }
}