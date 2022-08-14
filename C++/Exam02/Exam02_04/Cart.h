struct PRODUCT
{
	int pID;	
	int price;	
};

class Cart
{
private:
	int* productID;
	int nProducts;

public:
	static const PRODUCT productPriceAry[];
	Cart();		
	Cart(int num);
	Cart(const Cart& ca);
	friend void add(Cart& ca, int pID);
	friend void remove(Cart& ca, int pID);	
	void print();
};