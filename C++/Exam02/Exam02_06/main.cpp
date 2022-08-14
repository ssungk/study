#include <iostream>
using namespace std ;

typedef union 
{
	char * pStr ;
	double fFloat ;
	int nInt ;
} DATA ;

enum DATATYPE { NONE, STRING, FLOAT, INTEGER } ;

class DataType
{
private :
	int m_nType ;
	DATA m_Data ;

public :
	DataType() ;
	DataType( DataType & datatype ) ;
	DataType( char * pStr ) ;
	DataType( double fFloat );
	DataType( int nInt ) ;
	~DataType();
	
	void PrintData();

	DataType operator+( DataType & dt ) ;
	DataType operator=( DataType & dt ) ;
	friend DataType operator+( char * pStr, DataType & dt2 ) ;	
} ;

DataType::DataType()
{ 		
	m_nType = NONE ;
} 

DataType::DataType( DataType & datatype ) 
{
	m_nType = datatype.m_nType ;

	switch(datatype.m_nType)
	{
	case NONE :
		break ;

	case STRING :			
		m_Data.pStr = new char[strlen(datatype.m_Data.pStr)+1] ;
		strcpy( m_Data.pStr, datatype.m_Data.pStr ) ;
		break ;

	case FLOAT :
		m_Data.fFloat = datatype.m_Data.fFloat ;
		break ;

	case INTEGER :
		m_Data.nInt = datatype.m_Data.nInt ;
		break ;

	}
} 

DataType::DataType( char * pStr ) 
{
	m_nType = STRING ;
	m_Data.pStr = new char[strlen(pStr)+1] ;
	strcpy( m_Data.pStr, pStr ) ;
} 

DataType::DataType( double fFloat ) 
{
	m_nType = FLOAT ;
	m_Data.fFloat = fFloat ;
} 

DataType::DataType( int nInt ) 
{
	m_nType = INTEGER ;
	m_Data.nInt = nInt ;
} 

DataType::~DataType()
{
	if( m_nType == STRING )
		delete [] m_Data.pStr ;
}

void DataType::PrintData()
{
		switch(m_nType)
		{
		case NONE :
			cout << "정의된 데이터 형이 없습니다" << endl ;
			break ;

		case STRING :			
			cout << m_Data.pStr << endl ;
			break ;

		case FLOAT :
			cout << m_Data.fFloat << endl ;
			break ;

		case INTEGER :
			cout << m_Data.nInt << endl ;
			break ;

		}
}

DataType DataType::operator+( DataType & dt )
{
	if( m_nType != dt.m_nType )
	{
		cout << "데이터형이 일치하지 않습니다" << endl ;
		return DataType();
	}

	char * strTemp ;
	switch(m_nType)
	{
	case STRING :	
		strTemp = new char[strlen(m_Data.pStr) + strlen(dt.m_Data.pStr)+1] ;
		strcpy(strTemp, m_Data.pStr ) ;
		strcat(strTemp, dt.m_Data.pStr ) ;
		return DataType( strTemp ) ;
		break ;

	case FLOAT :
		return DataType( m_Data.fFloat + dt.m_Data.fFloat ) ;
		break ;

	case INTEGER :
		return DataType( m_Data.nInt + dt.m_Data.nInt ) ;
		break ;

	}
	return DataType() ;
}

DataType operator+( char * pStr, DataType & dt2 )
{
	if( dt2.m_nType != STRING )
	{
		cout << "데이터형이 일치하지 않습니다" << endl ;
		return DataType();
	}

	char * strTemp ;
	strTemp = new char[strlen(pStr) + strlen(dt2.m_Data.pStr)+1] ;
	strcpy(strTemp, pStr ) ;
	strcat(strTemp, dt2.m_Data.pStr ) ;
	return DataType( strTemp ) ;
}

DataType DataType::operator=( DataType & dt )
{
	m_nType = dt.m_nType ;
		
	switch(dt.m_nType)
	{
	case NONE :
		break ;

	case STRING :	
		m_Data.pStr = new char[strlen(dt.m_Data.pStr)+1] ;
		strcpy( m_Data.pStr, dt.m_Data.pStr ) ;
		break ;

	case FLOAT :
		m_Data.fFloat = dt.m_Data.fFloat ;
		break ;

	case INTEGER :
		m_Data.nInt = dt.m_Data.nInt ;
		break ;

	}
	return *this ;
}

void main( void )
{
	DataType IntA( 55 ) ;
	DataType IntB( -45 ) ;
	DataType IntC ;
	IntC = IntA + IntB ;
	IntC.PrintData() ;

	DataType FloatA( 3.14 ) ;
	DataType FloatB( -1.0 ) ;
	DataType FloatC ;
	FloatC = IntA + FloatB ; // 데이터 타입이 일치하지 않아 화면에 에러를 출력
	FloatC = FloatA + FloatB ;
	FloatC.PrintData() ;

	DataType StringA( "Hello" ) ;
	DataType StringB( "World" ) ;
	DataType StringC ;
	StringC = StringA + StringB ;
	StringC.PrintData() ;
	
	DataType StringD( "Bye !!!" ) ;
	DataType StringE ;
	StringE = "Good" + StringD ;
	StringE.PrintData() ;
}