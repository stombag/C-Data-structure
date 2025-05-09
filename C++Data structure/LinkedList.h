#pragma once

#include<iostream>

typedef int DataType;
// �ڷ��� int�� DataType�̶�� �ɷ� �̸��� �ٲپ���. ����� int�� �����ϴ�
// ����ϴ� ���� : int ���� �ٸ� �ڷ��� float ���� �ɷ� �ٲܶ� ���⸸ �ٲٸ� �ȴ�., ���� DataType�̶�� ���� ���Ḯ��Ʈ���� ����ϴ� �������� Ÿ���ΰ� �� �� �ִ�.

struct Node
{
	DataType Data;
	Node* NextNode;

};
Node* Create(DataType data);
void Destroy(Node* node);

void Push(Node** Head, Node* node);
void Insert(Node* current, Node* node);
void InsertHead(Node** current, Node* head);

void Remove(Node** head, Node* remove);
Node* GetNode(Node* head, int index);
int GetNodeCount(Node* head);


