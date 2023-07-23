class Solution {
public:
    int getSum(int a, int b) {
        while (b != 0) {
            
            //filter out identical component
            unsigned int carry = a & b;
            
            //filter out complementary component
            a = a ^ b;

            //shift b to the left the common components. and assign it to b
            //on the next iteration there will be fewer and fewer common components
            //and gradually b will converge to 0 conce we have shifted the integer left 
            //the appropriate amount of times. 
            b = carry << 1;
        }
        return a;
    }
};