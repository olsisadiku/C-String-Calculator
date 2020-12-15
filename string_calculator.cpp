// string_calculator.cpp
#include <iostream>
#include "my_string.h"
#include "./string_calculator.h"

using std::cout, std::endl;

unsigned int digit_to_decimal(char digit) {
    // TODO(student): implement
    int dig= digit - '0';
    if(dig < 0 || dig >9 ) {
        throw(std::invalid_argument("Invalid Argument"));
    }
    return dig;
}

char decimal_to_digit(unsigned int decimal) {
    // TODO(student): implement
    if(decimal > 9){
        throw(std::invalid_argument("Invalid Argument"));
    }
    char decimal_converter= decimal + '0';
    std::cout << decimal_converter << std::endl;
    return decimal_converter;
}

my_string trim_leading_zeros(const my_string& num) {
    // TODO(student): implement
    my_string trimmed_number = "";
    my_string num1 = num; 
    unsigned int starting_pos = 0;
    bool isLeading = true;
    bool isRan = false;
    if(num1.find("-") != my_string::npos){
        trimmed_number += "-";
        starting_pos = 1;
    }
    while(starting_pos < num1.size()){
        if(num1[starting_pos] > '0' || !isLeading){
            trimmed_number+=num1[starting_pos];
            isLeading = false;
            starting_pos+=1;
            isRan = true;
            continue;
        }
        else if( num1.find("0",starting_pos) != my_string::npos && isLeading){
            starting_pos++;
            if(starting_pos == num1.size() && !isRan){
                return "0";
            }
            continue;

        }
        

    }

    return trimmed_number;
}

my_string addZeros(int size){
    if(size == 0){
        return "";
    }
    my_string zeros = "";
    for(int i = 0; i < size;i++){
        zeros += '0';
    }
    return zeros;
}

my_string subtract(const my_string& lhs, const my_string& rhs);
long long stringToInt(my_string, bool);
my_string add(const my_string& lhs, const my_string& rhs) {
    // TODO(student): implement
    my_string lhs1;
    lhs1 = lhs;

    my_string rhs1;
    rhs1 = rhs; 

    if(lhs1.find("0") == 0){
    cout << "ran find" << endl;

        return rhs1;
    }
    else if(rhs1.find("0")== 0 ){
        return lhs1;
    }
    my_string added = "";
    int num_to_be;
    int remainder =0;
    if(lhs1.find("-") == my_string::npos && rhs1.find("-") == my_string::npos){
 
        if(lhs1.size() > rhs1.size()){

            my_string amount_of_zeros = addZeros(lhs1.size()- rhs1.size());

            rhs1.insert(0, amount_of_zeros);
        
        }
        else if(lhs1.size()  < rhs1.size()){
            my_string amount_of_zeros;
            
            amount_of_zeros = addZeros(rhs1.size() - lhs1.size());
            
            lhs1.insert(0, amount_of_zeros);
        }
        for(int end = lhs1.size()-1; end >= 0; end--){
            char lhs_num = lhs1[end];
            char rhs1_num = rhs1[end];
            int int_lhs = lhs_num- 48 + remainder;
            int int_rhs1 = rhs1_num - 48;
            num_to_be = int_lhs + int_rhs1;
            if(num_to_be >=10){
                num_to_be = num_to_be-10;
                added+= to_string(num_to_be);
                remainder = 1;
            }
            else{
                remainder = 0;
                added+= to_string(num_to_be);
            }
            
      
        }
    }
    bool isNegative= false;
    if(lhs1.find("-") == 0 && rhs1.find("-") == 0 ){
        isNegative = true;
        
        if(lhs1.size() > rhs1.size()){
            my_string amount_of_zeros = addZeros(lhs1.size()- rhs1.size());
            rhs1.insert(1, amount_of_zeros);
        }
        else if(lhs1.size()  < rhs1.size()){
            my_string amount_of_zeros = addZeros(rhs1.size()- lhs1.size());
            lhs1.insert(1, amount_of_zeros);
        }
        for(int end = lhs1.size()-1; end >= 1; end--){
            char lhs_num = lhs1[end];
            char rhs1_num = rhs1[end];
            int int_lhs = lhs_num- 48 + remainder;
            int int_rhs1 = rhs1_num - 48;
            num_to_be = int_lhs + int_rhs1;
            if(num_to_be >=10){
                num_to_be = num_to_be-10;
                added+= to_string(num_to_be);
                remainder = 1;
            }
            else{
                remainder = 0;
                added+= to_string(num_to_be);
            }
            
      
        }
    }
// opposite signs 
    // rhs1 and lhs are the strings
    // string added= "";
    // int num_to_be;
    // int remainder =0;
    if((rhs1.find("-") == 0) ^ (lhs1.find("-") == 0)){
        if(rhs1.find("-") == 0 ){
            return subtract(lhs1, rhs1.substr(1,rhs1.size()));
        }
        else{
            return subtract(rhs1, lhs1.substr(1,lhs1.size()));

        }

    }






///////////////////////////////////////////////////////////////////////////////////
    my_string final ="";
    if(!isNegative){
    for(int i = added.size()-1; i >=0; i--){
        final+= added[i];
    }
    if(remainder ==1){
                final = final.insert(0,to_string(remainder));
            }
    }
    else if(isNegative){
    for(int i = added.size()-1; i >=0; i--){
        final+= added[i];
    }
    if(remainder ==1){
                final.insert(0,to_string(remainder));
            }
            final.insert(0,"-");
    }
    return final;
}

long long stringToInt(my_string number_before, bool isNegative){
    
    int tenth = 1;
    long long number_to_be = 0;
    my_string final = "";
    int finish_loop =0;
    if(isNegative){
        finish_loop = 1;
    }
    for(int i = number_before.size()-1 ; i >= finish_loop; i--){
         char num = number_before[i];
         long long number = (num - 48) * tenth;
         number_to_be += number; 
         tenth*=10;  
    }
    if(isNegative){
        number_to_be*=-1;
    }
    std::cout<< number_to_be<< std::endl;
    return number_to_be;
}

my_string subtract(const my_string& lhs, const my_string& rhs) {
    // TODO(student): implement
    my_string lhs1;
    lhs1  = lhs;  
    my_string rhs1;
    rhs1  = rhs; 
    long long lhs_num, rhs1_num;
    long long final_num= 0;
    // if statement below handles small numbers
    if(lhs1.size() < 18 && rhs1.size() < 18){
    if(lhs1.find("-") == 0 && rhs1.find("-") == my_string::npos){
        lhs_num = stringToInt(lhs1, true);
        rhs1_num = stringToInt(rhs1, false);
        final_num = lhs_num - rhs1_num;
        std::cout << final_num << std::endl;
        
    }
    if(lhs1.find("-") == my_string::npos && rhs1.find("-") == my_string::npos){
        
        lhs_num = stringToInt(lhs1, false);
        rhs1_num = stringToInt(rhs1, false);
        final_num = lhs_num - rhs1_num;
        std::cout << final_num << std::endl;
    }
    if(lhs1.find("-") == my_string::npos && rhs1.find("-") != my_string::npos){
        lhs_num = stringToInt(lhs1, false);
        rhs1_num = stringToInt(rhs1, true);
        final_num = lhs_num - rhs1_num;
        std::cout << final_num << std::endl;
    }
    if(lhs1.find("-") != my_string::npos && rhs1.find("-") != my_string::npos){
        lhs_num = stringToInt(lhs1, true);
        rhs1_num = stringToInt(rhs1, true);
        final_num = lhs_num - rhs1_num;
        std::cout << final_num << std::endl;
    }
    }
    else{
        
    my_string replacement= "";
        if(lhs1.find("-") != my_string::npos && rhs1.find("-") != my_string::npos){
            my_string replacement =lhs1.substr(1,lhs1.size());
            lhs1 = rhs1.substr(1, rhs1.size());
            rhs1 = replacement;
            cout<< lhs1 << " " << rhs1<< endl; 
        }
        if(lhs1.find("-") == 0 && rhs1.find("-") == my_string::npos){
            // -8 - 8 = -16
            my_string added= add(lhs1.substr(1,lhs1.size()), rhs1);
            added.insert(0, "-");
            return added; 
        }
        if(lhs1.find("-") == my_string::npos && rhs1.find("-") == my_string::npos){
            int first_lhs_num = (char)lhs1[0] - 48;
            int first_rhs1_num = (char)rhs1[0] - 48;
            int sirst_lhs_num = (char)lhs1[1] - 48;
            int sirst_rhs1_num = (char)rhs1[1] - 48;
            bool run = false;
            if(first_lhs_num == first_rhs1_num && sirst_lhs_num < sirst_rhs1_num){
                run =true; 
            }
            my_string added = ""; 
            int remainder =0;
            if(lhs1.size() < rhs1.size()){
                lhs1.insert(0, addZeros(rhs1.size() - lhs1.size()));
                for(int i = lhs1.size()-1; i >=0; i--){
                    int lhs_num = (char)lhs1[i] - 48;
                    int rhs1_num = (char)rhs1[i] - 48- remainder;
                    if(lhs_num > rhs1_num){
                        rhs1_num +=10; 
                        remainder = 1;
                    }
                    else{
                        remainder = 0;
                    }
                    int subtraction = rhs1_num - lhs_num;
                    if(i== 0 && subtraction == 0 ){
                        if(added.find("0", added.size()-2) != my_string::npos){
                            added= added.substr(0, added.size()-1);
                        }
                        break;
                    }
                    added += to_string(subtraction);
                }
                my_string final = "";  
                for(int j = added.size()-1; j >=0; j--){
                    final += added[j];
                    
                } 
                 final.insert(0, "-");
                 
                return final;
            }
            else if(rhs1.size() == lhs1.size() && (first_lhs_num< first_rhs1_num || run)){
                my_string added = ""; 
                 int remainder =0;
                lhs1.insert(0, addZeros(rhs1.size() - lhs1.size()));
                for(int i = lhs1.size()-1; i >=0; i--){
                    int lhs_num = (char)lhs1[i] - 48;
                    int rhs1_num = (char)rhs1[i] - 48- remainder;
                    if(lhs_num > rhs1_num){
                        rhs1_num +=10; 
                        remainder = 1;
                    }
                    else{
                        remainder = 0;
                    }
                    int subtraction = rhs1_num - lhs_num;
                    if(i== 0 && subtraction == 0 ){
                        if(added.find("0", added.size()-2) != my_string::npos){
                            added= added.substr(0, added.size()-1);
                        }
                        break;
                    }
                    added += to_string(subtraction);
                }
                my_string final = "";  
                for(int j = added.size()-1; j >=0; j--){
                    final += added[j];
                    
                } 
                 final.insert(0, "-");
                 
                return final;
            
            }
            else{ 
                my_string added = ""; 
                 int remainder =0;
                rhs1.insert(0, addZeros(lhs1.size() - rhs1.size()));
                for(int i = lhs1.size()-1; i >=0; i--){
                    int lhs_num = (char)lhs1[i] - 48- remainder;
                    int rhs1_num = (char)rhs1[i] - 48;
                    if(lhs_num < rhs1_num){
                        lhs_num +=10; 
                        remainder = 1;
                    }
                    else{
                        remainder = 0;
                    }
                    int subtraction = lhs_num - rhs1_num;
                    if(i== 0 && subtraction == 0 ){
                        if(added.find("0", added.size()-2) != my_string::npos){
                            added= added.substr(0, added.size()-1);
                        }
                        break;
                    }
                    added += to_string(subtraction);
                }
                my_string final = "";  
                for(int j = added.size()-1; j >=0; j--){
                    final += added[j];
                    
                } 
                
                 
                return final;
            }   
            
            
        }
        if(lhs1.find("-") == my_string::npos && rhs1.find("-") != my_string::npos){
            
            my_string added= add(lhs1, rhs1.substr(1,rhs1.size()));
            return added; 
        }
        
    


    }    
    return to_string(final_num);
}

my_string reverseString(my_string reverse){
    my_string final = "";

    for(int i = reverse.size()-1; i>= 0; i--){
        final += reverse[i];
    }
    return final; 
}

my_string multiply(const my_string& lhs, const my_string& rhs) {
    // TODO(student): implement
    my_string lhs1; 
    lhs1 = lhs; 
    my_string rhs1;
    rhs1 = rhs; 
    long long lhs_num, rhs1_num;
    long long final_num= 0;
    // if statement below handles small numbers
    if(lhs1.size() < 18 && rhs1.size() < 18){
    if(lhs1.find("-") == 0 && rhs1.find("-") == my_string::npos){
        lhs_num = stringToInt(lhs1, true);
        rhs1_num = stringToInt(rhs1, false);
        final_num = lhs_num * rhs1_num;
        std::cout << final_num << std::endl;
        
    }
    if(lhs1.find("-") == my_string::npos && rhs1.find("-") == my_string::npos){
        
        lhs_num = stringToInt(lhs1, false);
        rhs1_num = stringToInt(rhs1, false);
        final_num = lhs_num * rhs1_num;
        std::cout << final_num << std::endl;
    }
    if(lhs1.find("-") == my_string::npos && rhs1.find("-") != my_string::npos){
        lhs_num = stringToInt(lhs1, false);
        rhs1_num = stringToInt(rhs1, true);
        final_num = lhs_num * rhs1_num;
        std::cout << final_num << std::endl;
    }
    if(lhs1.find("-") != my_string::npos && rhs1.find("-") != my_string::npos){
        lhs_num = stringToInt(lhs1, true);
        rhs1_num = stringToInt(rhs1, true);
        final_num = lhs_num * rhs1_num;
        std::cout << final_num << std::endl;
    }}
    else{
        bool isNegative = false;
        if((rhs1.find("-") != my_string::npos) ^ (lhs1.find("-") != my_string::npos)){
            isNegative = true; 
        }
        if((rhs1.find("-")) == 0){
            rhs1 = rhs1.substr(1, rhs1.size());
        }
        if((lhs1.find("-")) == 0){
            lhs1 = lhs1.substr(1, lhs1.size());
        }

        if (rhs1.size () > lhs1.size ())
	{
	  my_string replacement = lhs1;
	  lhs1 = rhs1;
	  rhs1 = replacement;
	}
      int remainder = 0;
      int amount_of_zeros = 1;
//////////////Multiplying first number ////////////////
      my_string initial = "";
      for (int i = lhs1.size()-1; i >= 0; i--)
	{
	   
	      int lhs_num = (char)lhs1[i] - 48;
	      int rhs1_num = (char)rhs1[rhs1.size()-1] - 48;
	      int current_value = lhs_num * rhs1_num + remainder;
          remainder= 0; 
	      if (i == 0 && current_value > 9)
		{
		  initial += to_string (current_value % 10);
		  initial += to_string (current_value / 10);
          break;
		}
	      else
		{
		  remainder = (current_value / 10);
		  current_value = current_value % 10;

		  initial += to_string (current_value);
		}
	    
	}
      // first string so it can be multiplied
      my_string initial_reversed = "";
      for (int s = initial.size () - 1; s >= 0; s--)
	{
	  initial_reversed += initial[s];
	}
     

///////////////////////////////////////////////////////////////////

      // last gets the last number after multiplication 
      // remainder is added on to the last if the last is greater than 9. 
      // make sure the amount of zeros increased as you run through loop

/////////////////MAIN RUN OF MULTIPLICATION ////////////////////////    

      // initial_reversed is the beginning my_string so we are able to multiply the new my_strings together
      // remainder = 0, use the same logic as the beginning
      // amount of zeros = 1
      my_string final_string = initial_reversed;
      for (int i = rhs1.size () - 2; i >= 0; i--)
	{
	  initial = "";
	  for (int j = lhs1.size () - 1; j >= 0; j--)
	    {
	      /*int lhs_num = (char)lhs[j] - 48; 
	         /int rhs1_num = (char)rhs1[i] - 48; 
	         int multiplication= lhs_num * rhs1_num;
	         if(multiplication > 9){
	         last = (multiplication % 10) + remainder;
	         remainder = (multiplication/10) %  10;
	         if(lhs_num * rhs1_num > 9 && j == 0){
	         last = multiplication + remainder;
	         }
	       */
	      int lhs_num = (char) lhs1[j] - 48;
	      int rhs1_num = (char) rhs1[i] - 48;
	      int current_value = lhs_num * rhs1_num + remainder;
	      if (j == 0 && current_value > 9)
		{
		  initial += to_string (current_value % 10);
		  initial += to_string (current_value / 10);
		}
	      else
		{
		  remainder = (current_value / 10);
		  current_value = current_value % 10;

		  initial += to_string (current_value);
		}
	    }
	  /*else{
	     last = multiplication+remainder;
	     if(last> 9){
	     last = (multiplication+remainder) % 10;
	     remainder = ((multiplication+remainder)/ 10 ) % 10;
	     }
	     remainder = 0;
	     }
	     initial += std::to_my_string(last); 
	     } */

	  remainder = 0;
	  initial = reverseString (initial);
	  initial.insert (initial.size (), addZeros (amount_of_zeros));
	  final_string = add (final_string, initial);
	  amount_of_zeros += 1;
	}
    
        if(isNegative){
            final_string.insert(0, "-");
        }

      return final_string;
//////////////////////////////////////////////////////////////////////    



    
    
    }
    return to_string(final_num);
    }
