#include "ErrorRecovery.h"

//========= ErrRecItem  ==============
void ErrRecQueue::enqueue(int lineNo, int colNo, char* txt, char* varName){
	ErrRecItem * item = new ErrRecItem();
	item->colNo = colNo;
	item->lineNo = lineNo;
	item->txt = new char[255];
	item->txt[0] = '\0';
	strcat(item->txt, txt);
	item->var = new char[255];
	item->var[0] = '\0';
	strcat(item->var, varName);
	if(front == 0){
		front = tail = item;
	}
	else{
		tail->next = item;
		tail = item;
	}

}
ErrRecItem * ErrRecQueue::dequeue(){
	ErrRecItem * ret = 0;
	if(front != 0){
		ret = front;
		if(front == tail){
			front = tail = 0;
		}
	}
	else{
		front = front->next;
	}
	return ret;
}

int ErrRecQueue::isEmpty(){
	if(front == 0 )
		return 1;
	else
		return 0;
}
//====================================
ErrorRecovery::ErrorRecovery(void)
{
	this->errQ = new ErrRecQueue();
	this->warnQ = new ErrRecQueue();
}

ErrorRecovery::~ErrorRecovery(void)
{
}

void ErrorRecovery::printErrQueue(){
	while(!errQ->isEmpty()){
		ErrRecItem * e = errQ->dequeue();
		cout<<"Error: ["<<e->lineNo<<","<<e->colNo<<"]   "<<e->txt<<",  "<<e->var<<"\n";
	}
}