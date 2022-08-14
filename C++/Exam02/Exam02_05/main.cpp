#include <iostream>
#include <time.h>
using namespace std ;

struct TRANSACTION
{
	int nAmount ;
	char strMemo[50] ;
} ;

class BankAccount 
{
private :
	static int BankTotalBalance ;

	int m_nAccountNo ;
	int m_nBalance ;	
	int m_nHistoryCount ;
	static const int MAX_HISTORY_SIZE = 20 ;
	TRANSACTION m_stHistory[MAX_HISTORY_SIZE] ;
	
public :
	BankAccount()
	{ 		
		m_nAccountNo = rand() % 100000 ;
		m_nBalance = 0 ;
		m_nHistoryCount = 1 ;
		memset( &m_stHistory, 0x00, sizeof( TRANSACTION ) * MAX_HISTORY_SIZE ) ;
		m_nHistoryCount = 1 ;
		m_stHistory[0].nAmount = 0 ;
		strcpy( m_stHistory[0].strMemo, "���»���" ) ;
	} ;
	BankAccount( int nBalance ) 
	{
		BankTotalBalance += nBalance ;
		m_nAccountNo = rand() % 100000 ;
		m_nBalance = nBalance ;
		memset( &m_stHistory, 0x00, sizeof( TRANSACTION ) * MAX_HISTORY_SIZE ) ;
		m_nHistoryCount = 1 ;
		m_stHistory[0].nAmount = nBalance ;
		strcpy( m_stHistory[0].strMemo, "���»���" ) ;
	} ;

	void PrintAccount() ;

	void Deposit( int nAmount, char * strMemo );

	void Withdraw( int nAmount, char * strMemo )
	{
		if( m_nHistoryCount == MAX_HISTORY_SIZE )
		{
			cout << "ERROR!!! �ŷ� ������ �ʰ��Ǿ����ϴ� !!! " << endl ;
			return ;
		}
		BankTotalBalance -= nAmount ;
		m_nBalance -= nAmount ;
		m_stHistory[m_nHistoryCount].nAmount = -nAmount ;
		strcpy( m_stHistory[m_nHistoryCount].strMemo, strMemo ) ;
		m_nHistoryCount++ ;
	}
	static void PrintBank() ;
} ;

void BankAccount::Deposit( int nAmount, char * strMemo );
{
	if( m_nHistoryCount == MAX_HISTORY_SIZE )
	{
		cout << "ERROR!!! �ŷ� ������ �ʰ��Ǿ����ϴ� !!! " << endl ;
		return ;
	}
	BankTotalBalance += nAmount ;
	m_nBalance += nAmount ;
	m_stHistory[m_nHistoryCount].nAmount = nAmount ;
	strcpy( m_stHistory[m_nHistoryCount].strMemo, strMemo ) ;
	m_nHistoryCount++ ;
}

 int BankAccount::BankTotalBalance = 0 ;

void BankAccount::PrintAccount()
{
	
	cout << "=======================" << endl ;
	cout << "Account No. " << m_nAccountNo << " Infomation" << endl ;
	cout << "Balance : " << m_nBalance << endl ;
	cout << "Recent History" << endl ;
	for( int i = 0 ; i < m_nHistoryCount ; i++ )
	{
		cout << i << " : " << m_stHistory[i].nAmount << "\t" << m_stHistory[i].strMemo << endl ; 
	}
}

void BankAccount::PrintBank() 
{
	cout << endl << "Total Bank Balance =======" << endl ;
	cout << BankTotalBalance << endl ;
}

void main( void )
{
	srand(time(NULL)) ;
	BankAccount A(50000) ;
	A.Deposit(100000, "�뵷") ;
	A.Withdraw( 21000, "��������" ) ;
	A.Withdraw( 15000, "���Ƹ�ȸ��" ) ;
	A.PrintAccount() ;

	BankAccount B(10000) ;
	B.Withdraw( 4900, "�����" ) ;
	B.Deposit( 600000, "���б�" ) ;
	B.PrintAccount() ;

	BankAccount::PrintBank() ;
}