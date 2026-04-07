#pragma once
#ifndef __OPER_OVER_ASSIGN_MOVE_H__
#define __OPER_OVER_ASSIGN_MOVE_H_

class CMyData
{
private:
	int* m_pnData = nullptr;

public:
	explicit CMyData(int nParam);

	CMyData(const CMyData& rhs);

	~CMyData();

	operator int();

	CMyData operator+(const CMyData& rhs);

	CMyData& operator=(const CMyData& rhs);

	CMyData& operator=(CMyData&& rhs);

};

#endif // !__OPER_OVER_ASSIGN_MOVE_H__
