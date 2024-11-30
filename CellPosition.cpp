#include "CellPosition.h"
#include "UI_Info.h"

CellPosition::CellPosition()
{
	// (-1) indicating an invalid cell (uninitialized by the user)
	vCell = -1;
	hCell = -1;
}

CellPosition::CellPosition(int v, int h)
{
	// (-1) indicating an invalid cell (uninitialized by the user)
	vCell = -1;
	hCell = -1;

	SetVCell(v);
	SetHCell(h);
}

CellPosition::CellPosition(int cellNum)
{
	(*this) = GetCellPositionFromNum(cellNum); // the function call will build a cell position (vCell and hCell)
	// from the passed (cellNum)
	// (*this) = ... --> this will copy the returned (vCell and hCell)
	//                   to the data members (vCell and hCell)
}

bool CellPosition::SetVCell(int v)
{
	///TODO: Implement this function as described in the .h file (don't forget the validation)
	// valdation
	if (v >= NumVerticalCells || v < 0)
		return false;
	// setting
	this->vCell = v;
	return true;
}

bool CellPosition::SetHCell(int h)
{
	///TODO: Implement this function as described in the .h file (don't forget the validation)
	// valdation
	if (h >= NumHorizontalCells || h < 0)
		return false;

	// setting
	this->hCell = h;
	return true;

}

int CellPosition::VCell() const
{
	return vCell;
}

int CellPosition::HCell() const
{
	return hCell;
}

bool CellPosition::IsValidCell() const
{
	///TODO: Implement this function as described in the .h file
	//valdation of cell postion
	if ((VCell() >= 0 && VCell() < NumVerticalCells) && (HCell() >= 0 && HCell() < NumHorizontalCells))
		return true;

	return false;
}

int CellPosition::GetCellNum() const
{
	return GetCellNumFromPosition(*this); // (*this) is the calling object of GetCellNum
	// which means the object of the current data members (vCell and hCell)
}

int CellPosition::GetCellNumFromPosition(const CellPosition& cellPosition)
{
	// Note:
	// this is a static function (do NOT need a calling object so CANNOT use the data members of the calling object, vCell&hCell)
	// just define an integer that represents cell number and calculate it using the passed cellPosition then return it

	///TODO: Implement this function as described in the .h file
	int vcell = cellPosition.VCell();
	int hcell = cellPosition.HCell();

	if (cellPosition.IsValidCell()) {
		int CellNum = (NumVerticalCells - 1 - vcell) * (NumHorizontalCells)+hcell + 1;
		return CellNum;
	}
	return -1;
}

CellPosition CellPosition::GetCellPositionFromNum(int cellNum)
{
	// this is a static function (do NOT need a calling object so CANNOT use the data members of the calling object, vCell&hCell)

	CellPosition position;

	/// TODO: Implement this function as described in the .h file
	int hcell = -1, vcell = -1;

	if (cellNum > NumHorizontalCells * NumVerticalCells || cellNum < 0) {
		position.SetHCell(hcell);
		position.SetVCell(vcell);
	}
	else {
		hcell = cellNum % NumHorizontalCells - 1;
		hcell = (hcell < 0) ? NumHorizontalCells - 1 : hcell;
		position.SetHCell(hcell);

		vcell = 8 - (cellNum - hcell - 1) / NumHorizontalCells;
		position.SetVCell(vcell);
	}

	// Note: use the passed cellNum to set the vCell and hCell of the "position" variable declared inside the function
	//       I mean: position.SetVCell(...) and position.SetHCell(...) then return it

	return position;
}

void CellPosition::AddCellNum(int addedNum)
{

	/// TODO: Implement this function as described in the .h file
	int cellNum = GetCellNum();
	cellNum += addedNum;

	this->GetCellPositionFromNum(cellNum);


	// Note: this function updates the data members (vCell and hCell) of the calling object

}
