#include <iostream>
#include <iomanip>
using namespace std;

void swapdptr (int**,int**);
void swaprefptr (int*&,int*&);

int main()
{
	int x = 5;
	int	y = 7;

	int *px = &x;  
	int *py = &y;

	cout << "swapDptr()�Լ� ȣ�� �� "<< px << "    " << py << "     " << x << "    " << y << endl;
	swapdptr (&px, &py);
	cout << "swapDptr()�Լ� ȣ�� �� "<< px << "    " << py << "     " << x << "    " << y << endl;
	swaprefptr (px, py);
	cout << "swapRefPtr()�Լ� ȣ�� �� "<< px << "    " << py << "     " << x << "    " << y << endl;
	
	return 0;

}
void swapdptr (int** px,int** py)
{
	int* temp = *px;
	*px = *py;
	*py = temp;

	return;
}
void swaprefptr (int*& px,int*& py)
{
	int* temp = px;
	px = py;
	py = temp;
	
	return;
}