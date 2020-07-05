#include<string>
using namespace std;

class countyTax{
	private:
		double tax;
		string county;
	public:
		countyTax(){
			tax=0;
			county="";
		}
		countyTax(string county,double tax){
			this->tax=tax;
			this->county=county;
		}
		void setTax(double tax){
			this->tax=tax;
		}
		void setCounty(string county){
			this->county=county;
		}
		double getTax(){
			return tax;
		}
		string getCounty(){
			return county;
		}
};
