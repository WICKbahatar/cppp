SinglyLinkedListNode* reverse(SinglyLinkedListNode* head) {
if(head == nullptr || head->next == nullptr){  
    return head;  
}
SinglyLinkedListNode* remaining = reverse(head->next);
head->next->next = head;
head->next = nullptr;  
return remaining; 
}