#include "GameObject.h"


GameObject::GameObject(const CellPosition & pos)
{
	position = pos; // Sets Position
}

CellPosition GameObject::GetPosition() const
{
	return position;
}

void GameObject::SetPosition(const CellPosition& pos)
{
	position.SetHCell(pos.HCell());
	position.SetVCell(pos.VCell()); 

}

GameObject::~GameObject()
{
}

bool GameObject::IsOverLapping(GameObject* newObj)
{
	return false;
}
