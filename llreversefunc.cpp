void reverse(){
			node* htemp;
			node* ttemp;
			int i,j,temp=0;
			j=countItems();
			htemp=head;
			ttemp=tail;
			int size= countItems()/2;
			for(i=1;i<=size;++i){
				temp=htemp->data;
				htemp->data=ttemp->data;
				ttemp->data=temp;
				htemp=htemp->next;
				j--;
				ttemp=head;
				for(int k=1;k<j;k++){
					ttemp=ttemp->next;
				}
			}
		}
