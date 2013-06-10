
class Solution 
{
public:    double FindMedianInternal(int a[], int b[], int na, int nb, int left, int right)    
  	   {        
			   if(left > right)        
			   {            
				   return FindMedianInternal(b, a, nb, na, max(0, (na + nb) / 2 - na), min(nb - 1, (na + nb) / 2));        
			   }        
			   int i = (left + right) / 2;        
			   int j = (na + nb) / 2 - i - 1;        
			   if(j >= 0 && j < nb && a[i] < b[j])            
				   return FindMedianInternal(a, b, na, nb, i + 1, right);        
			   else if(j + 1 >= 0 && j + 1 < nb && a[i] > b[j + 1])           
				   return FindMedianInternal(a, b, na, nb, left, i - 1);        
			   else        
			   {            
				   if((na + nb) & 0x1)                
					   return a[i];            
				   else            
				   {               
					   if(i > 0 && j >= 0)                    
						   return (a[i] + max(a[i - 1], b[j])) / 2.0;                
					   else if(i == 0)                    
						   return (a[i] + b[j]) / 2.0;                
					   else                   
						   return (a[i] + a[i-1]) / 2.0;            
				   }        
			   }    
		   }    
		   double findMedianSortedArrays(int A[], int m, int B[], int n) 
		   {        // Start typing your C/C++ solution below        // DO NOT write int main() function        
			   return FindMedianInternal(A, B, m, n, max(0, (m + n) / 2 - n), min(m - 1, (m + n) / 2));    
		   }
};
