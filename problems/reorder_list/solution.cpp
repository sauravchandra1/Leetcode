class Solution 
{
public:
    void reorderList(ListNode* head)
	{
        if (head == nullptr		// case size 0
			|| head->next == nullptr		// case size 1
			|| head->next->next == nullptr)		// case size 2
			return;
			
		int len = getLength(head);
		ListNode* head1 = head, *head2 = head;
		
		for (int i = 0; i < len / 2; i++)
			head2 = head2->next;
			
		bool stop = false;
		reArrange(head1, head2, stop);
	}

	void reArrange(ListNode*& head1, ListNode*& head2, bool& stop) 
	{
		if (head2 == nullptr)
			return;
			
		reArrange(head1, head2->next, stop);
		
		if (!stop && (head1 == head2 || head1->next == head2)) 
		{
			head2->next = nullptr;
			stop = true;
		}
		if (!stop) 
		{
			head2->next = head1->next;
			head1->next = head2;
			head1 = head2->next;
		}
	}	

	int getLength(const ListNode* head)
	{
		int length = 0;
		while (head != nullptr)
		{
			length ++;
			head = head->next;
		}
		return length;
	}
};