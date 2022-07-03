// you can use includes, for example:
// #include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

int solution(vector<int> &A) {
    int max_length = 0;
    int curslicelength = 0;
    int cursign = 0;
    int prevsign = 0;
    for ( size_t i = 1; i < A.size(); ++i ) {
        if ( A ) {

        }
        if ( cursign != prevsign ) {
             ++curslicelength;
            cout << "curs = " << curslicelength << " " << A[i-1]<< " " << A[i] << endl;
        }
        else {
            if ( max_length < curslicelength ) {
                max_length = curslicelength;
            }
            curslicelength = 0;
        }
        prevsign = cursign;
    }
    cout << "maxlength =" << max_length <<endl;
    if ( max_length < curslicelength ) {
        max_length = curslicelength;
    }
    if ( 0 == max_length ) {
        return 1;
    }
    return max_length;
}
 A[0]  =  5
  A[1]  =  4
  A[2]  = -3
  A[3]  =  2
  A[4]  =  0
  A[5]  =  1
  A[6]  = -1
  A[7]  =  0
  A[8]  =  2
  A[9]  = -3
  A[10] =  4
  A[11] = -5
