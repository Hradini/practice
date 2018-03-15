void reverselinear(){
			node* temp;
			node*cur;
			node*prev;
			tail=head;
			cur=head;
			temp=head;
			prev=NULL;
			if(head!=NULL){
			while(temp!=NULL){
				if(cur==head){
					temp=cur->next;
					cur->next=NULL;
					prev=cur;
					cur=temp;
					temp=cur->next;
					cur->next=prev;
				}
				else{
					prev=cur;
					cur=temp;
					temp=cur->next;
					cur->next=prev;
				}
			}head=cur;
			}
		}
