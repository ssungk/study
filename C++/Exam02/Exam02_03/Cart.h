struct PRODUCT
{
	int pID;
	int price;
};

class Cart
{
private:
	int productID[10];
	int nProducts;

public:
	Cart();		
	Cart(const Cart& ca);
	void add(int pID);
	void remove(int pID);	
	void print();
	void print(PRODUCT productPriceAry[]);
};
