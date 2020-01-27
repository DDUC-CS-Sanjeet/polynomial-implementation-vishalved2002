#include<iostream>
#include<string.h>
using namespace std;
const int maxsize=10;

class Polynomial
{
  private:
    // Variables to store information about polynomial
    int coeff[maxsize];
    int degree;
    
  public:
    Polynomial()
    {
      // Behavior of default constructor
      degree = 0;
      for (int i =0;i>maxsize;i++)
       coeff[i]=0;
      
    }

    Polynomial(int deg)
    {
    	degree= deg;
      // Behavior of constructor with arguments
    }
  
    ~Polynomial()
    {
      // Behavior of destructor
    }
  
    //  Overload copy constructor, +, - and = operators
    Polynomial(const Polynomial& p)
    {
    	degree = p.degree;
    	
	}
    Polynomial  operator + (Polynomial const &secondPolynomial)
    {

     Polynomial  P3;
     if(degree>secondPolynomial.degree)
       P3.degree=degree;
     else
	   P3.degree= secondPolynomial.degree; 
	

     for ( int i = 0  ; i <= P3.degree ; i++ )
	 {
     	

           P3.coeff[i]  =  coeff[i] +  secondPolynomial.coeff[i] ;    

     }

     return P3;     

}
Polynomial  operator - (Polynomial const  &secondPolynomial)
 {

     Polynomial  P3;
      if(degree>secondPolynomial.degree)
       P3.degree=degree;
       
     else if(degree<secondPolynomial.degree)
	   P3.degree= secondPolynomial.degree; 
	else
	

     for ( int i = 0  ; i <= P3.degree ; i++ )
	 {
           
           P3.coeff [i]  =  coeff [i] -  secondPolynomial.coeff [i] ;
		      

     }

     return P3;
     

}
Polynomial operator = (Polynomial P)
{
	degree = P.degree;
	for (int i=0;i<=degree;i++)
	{
		coeff[i]=P.coeff[i];
	}
}
    void storePolynomial()
    {
      //  Code to enter and store polynomial
     cout<<"Enter the coefficients for your polynimial."<<endl;
	 for(int i=0;i<=degree;i++)
	    {
	    	cout<<"Enter the coefficient for x^"<<i<<" :";
	    	cin>>coeff[i];
			  }      
      
    }
    void display()
    {
      //  Code to print the polynomial in readable format
      for(int i=0;i<=degree;i++)
      {
      	cout<<coeff[i]<<"x^"<<i;
      	if(i!=degree)
      	cout<<"+";
	  }cout<<endl;
    }
  
};

int main()
{
  int degFirst, degSecond;
  // Ask user to input the values of degFirst and degSecond 
  cout<<"Enter the degree of first polynomial-"<<endl;
  cin>> degFirst;
  cout<<"Enter the degree of second polynomial-"<<endl;
  cin >>degSecond;
  Polynomial firstPolynomial(degFirst);
  Polynomial secondPolynomial(degSecond);
  Polynomial thirdPolynomial;
  
  firstPolynomial.storePolynomial();
  secondPolynomial.storePolynomial();
  
  thirdPolynomial=firstPolynomial+secondPolynomial;
  Polynomial fourthPolynomial=firstPolynomial-secondPolynomial;
  cout<<"Your first entered polynomial-"<<endl;
  firstPolynomial.display();
  cout<<"Your second entered polynomial-"<<endl;
  secondPolynomial.display();
  cout<<"Sum of two polynomials-"<<endl;
  thirdPolynomial.display();
  cout<<"Difference of two polynomials-"<<endl;
  fourthPolynomial.display();
}
