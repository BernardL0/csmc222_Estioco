/*--------------------------------------------------------------------------*/
/* Filename : 201810434_11057.cpp                                           */
/* Description: Peter received money from his parents this week and wants...*/
/* Author : Bernard Louie C. Estioco                                        */
/* Course and Year : BSCS - 2                                               */
/* Last Modified : 03 / 04 / 2020                                           */
/* Honor Code : This is my own code. I have worked hard in completing       */
/* this work and I have not copied from any unauthorized                    */
/* resource. I am also well aware of the policies                           */
/* stipulated in the college student handbook regarding                     */
/* academic dishonesty.                                                     */
/*--------------------------------------------------------------------------*/

#include <bits/stdc++.h>

using namespace std;

int bsearch(int pricel[], int x, int l, int r){
    if(l > r)
        return -1; // x is not in the pricel list
    int m = (l+r)/2; // == left + (right-left)/2
    if(pricel[m] == x)
        return m;
    else if(pricel[m]  < x)
        return bsearch(pricel, x, m+1, r);
    else    // x is less than pricel list
        return bsearch(pricel, x, l, m-1);
}
int main(){
    int n, Bprice, i, j; // i and j are the sum of the Bprice(Book Price
    while(cin >> n){ // inputting the number of prices
        int pricelist[n];
        for(int x = 0; x < n; x++) // inputting the prices
            cin >> pricelist[x];
        sort(pricelist, pricelist + n); // sorting the number of prices
        cin >> Bprice; // inputting the book price
        for(int x = 1; x <= n; x++){
            int y = pricelist[n-x];
            if(bsearch(pricelist,  Bprice-y, 0, n-x) != -1){ // searching for the i price in the N pricelist
                i = Bprice-y;
                j = y;
            }
        }
        cout << "Peter should buy books whose prices are " << i << " and " << j << "."; // printing
        cout << endl << endl;
    }
    return 0;
}
