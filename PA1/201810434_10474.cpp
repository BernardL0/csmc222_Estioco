/*--------------------------------------------------------------------------*/
/* Filename : 201810434_10474.cpp                                           */
/* Description: Raju and Meena love to play with Marble.                    */
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

int first_occur_bsearch(int marbles[], int findm,  int l, int r){
    if(l > r)
        return -1; // findm marble is not in the N marbles
    int m = (l + r) /2; // == left + (right-left)/2
    if(marbles[m] == findm && (marbles[m-1] != findm || m == 0))
        return m;
    else if(marbles[m] < findm)
        return first_occur_bsearch(marbles, findm, m+1, r);
    else
        return first_occur_bsearch(marbles, findm, l, m-1);
}
int main(){
    int N, Q, counter = 0;
    while(cin >> N >> Q){   // inputting the number of marbles and number of finding marble
        if(N != 0 && Q != 0){
            counter ++;                 // number of Case
            int marble[N], findm[Q];
            for(int i = 0; i < N; i++)  // inputting N Marble
                cin >> marble[i];
            for(int i = 0; i < Q; i++)  // inputting to find the a N Marble
                cin >> findm[i];

            sort(marble, marble+N);     // sorting the marbles
            cout << "CASE# " << counter << ":" << endl;

            for(int i = 0; i < Q; i++){ // for outputting the result
                if(first_occur_bsearch(marble, findm[i], 0, N-1) == -1) // searching for the findm marble in the N Marbles if findm cannot find
                    cout << findm[i] << " not found";                   // from the list of marble print the findm[i] not found
                else // if there is print the findm and found at the list of marble N
                    cout << findm[i] << " found at " << first_occur_bsearch(marble, findm[i], 0, N-1) + 1;
                cout << endl;
            }
        }
        else
            break;
    }
    return 0;
}
