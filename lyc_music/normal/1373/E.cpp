//QwQcOrZ yyds!!!
#include<bits/stdc++.h>
#define int long long
using namespace std;

inline int read(){
    int x = 0; char ch = getchar(); bool positive = 1;
    for (; !isdigit(ch); ch = getchar())	if (ch == '-')	positive = 0;
    for (; isdigit(ch); ch = getchar())	x = x * 10 + ch - '0';
    return positive ? x : -x;
}
inline void write(int a){
    if(a>=10)write(a/10);
    putchar('0'+a%10);
}
inline void writesp(int a){
    if(a>=10)write(a/10);
    putchar('0'+a%10);
    printf(" ");
}
inline void writeln(int a){
    if(a<0){
    	a=-a; putchar('-');
    }
    write(a); puts("");
}

int a[10][150] = {
    { 1, 2, 3, 4, 5, 6, 7, 8, 9, 19, 29, 39, 49, 59, 69, 79, 89, 99, 199, 299, 399, 499, 599, 699, 799, 899, 999, 1999, 2999, 3999, 4999, 5999, 6999, 7999, 8999, 9999, 19999, 29999, 39999, 49999, 59999, 69999, 79999, 89999, 99999, 199999, 299999, 399999, 499999, 599999, 699999, 799999, 899999, 999999, 1999999, 2999999, 3999999, 4999999, 5999999, 6999999, 7999999, 8999999, 9999999, 19999999, 29999999, 39999999, 49999999, 59999999, 69999999, 79999999, 89999999, 99999999, 199999999, 299999999, 399999999, 499999999, 599999999, 699999999, 799999999, 899999999, 999999999, 1999999999, 2999999999, 3999999999, 4999999999, 5999999999, 6999999999, 7999999999, 8999999999, 9999999999, 19999999999, 29999999999, 39999999999, 49999999999, 59999999999, 69999999999, 79999999999, 89999999999, 99999999999, 199999999999, 299999999999, 399999999999, 499999999999, 599999999999, 699999999999, 799999999999, 899999999999, 999999999999, 1999999999999, 2999999999999, 3999999999999, 4999999999999, 5999999999999, 6999999999999, 7999999999999, 8999999999999, 9999999999999, 19999999999999, 29999999999999, 39999999999999, 49999999999999, 59999999999999, 69999999999999, 79999999999999, 89999999999999, 99999999999999, 199999999999999, 299999999999999, 399999999999999, 499999999999999, 599999999999999, 699999999999999, 799999999999999, 899999999999999, 999999999999999, 1999999999999999, 2999999999999999, 3999999999999999, 4999999999999999, 5999999999999999, 6999999999999999, 7999999999999999, 8999999999999999, 9999999999999999, 19999999999999999, 29999999999999999, 39999999999999999, 49999999999999999, 59999999999999999, 69999999999999999 },
    { 0, -1, 1, -1, 2, -1, 3, -1, 4, 9, 5, 19, 6, 29, 7, 39, 8, 49, 18, 59, 28, 69, 38, 79, 48, 89, 58, 189, 68, 289, 78, 389, 88, 489, 98, 589, 198, 689, 298, 789, 398, 889, 498, 989, 598, 1989, 698, 2989, 798, 3989, 898, 4989, 998, 5989, 1998, 6989, 2998, 7989, 3998, 8989, 4998, 9989, 5998, 19989, 6998, 29989, 7998, 39989, 8998, 49989, 9998, 59989, 19998, 69989, 29998, 79989, 39998, 89989, 49998, 99989, 59998, 199989, 69998, 299989, 79998, 399989, 89998, 499989, 99998, 599989, 199998, 699989, 299998, 799989, 399998, 899989, 499998, 999989, 599998, 1999989, 699998, 2999989, 799998, 3999989, 899998, 4999989, 999998, 5999989, 1999998, 6999989, 2999998, 7999989, 3999998, 8999989, 4999998, 9999989, 5999998, 19999989, 6999998, 29999989, 7999998, 39999989, 8999998, 49999989, 9999998, 59999989, 19999998, 69999989, 29999998, 79999989, 39999998, 89999989, 49999998, 99999989, 59999998, 199999989, 69999998, 299999989, 79999998, 399999989, 89999998, 499999989, 99999998, 599999989, 199999998, 699999989, 299999998, 799999989, 399999998, 899999989 },
    { -1, -1, 0, -1, -1, 1, -1, -1, 2, -1, -1, 3, -1, -1, 4, -1, -1, 5, -1, -1, 6, -1, -1, 7, -1, -1, 17, -1, -1, 27, -1, -1, 37, -1, -1, 47, -1, -1, 57, -1, -1, 67, -1, -1, 77, -1, -1, 87, -1, -1, 97, -1, -1, 197, -1, -1, 297, -1, -1, 397, -1, -1, 497, -1, -1, 597, -1, -1, 697, -1, -1, 797, -1, -1, 897, -1, -1, 997, -1, -1, 1997, -1, -1, 2997, -1, -1, 3997, -1, -1, 4997, -1, -1, 5997, -1, -1, 6997, -1, -1, 7997, -1, -1, 8997, -1, -1, 9997, -1, -1, 19997, -1, -1, 29997, -1, -1, 39997, -1, -1, 49997, -1, -1, 59997, -1, -1, 69997, -1, -1, 79997, -1, -1, 89997, -1, -1, 99997, -1, -1, 199997, -1, -1, 299997, -1, -1, 399997, -1, -1, 499997, -1, -1, 599997, -1, -1, 699997 },
    { -1, -1, -1, -1, -1, 0, -1, -1, -1, 1, -1, -1, -1, 2, 9, -1, -1, 3, 19, 8, -1, 4, 29, 18, 7, 5, 39, 28, 17, 6, 49, 38, 27, 16, 59, 48, 37, 26, 69, 58, 47, 36, 79, 68, 57, 46, 89, 78, 67, 56, 189, 88, 77, 66, 289, 188, 87, 76, 389, 288, 187, 86, 489, 388, 287, 96, 589, 488, 387, 196, 689, 588, 487, 296, 789, 688, 587, 396, 889, 788, 687, 496, 989, 888, 787, 596, 1989, 988, 887, 696, 2989, 1988, 987, 796, 3989, 2988, 1987, 896, 4989, 3988, 2987, 996, 5989, 4988, 3987, 1996, 6989, 5988, 4987, 2996, 7989, 6988, 5987, 3996, 8989, 7988, 6987, 4996, 9989, 8988, 7987, 5996, 19989, 9988, 8987, 6996, 29989, 19988, 9987, 7996, 39989, 29988, 19987, 8996, 49989, 39988, 29987, 9996, 59989, 49988, 39987, 19996, 69989, 59988, 49987, 29996, 79989, 69988, 59987, 39996 },
    { -1, -1, -1, -1, -1, -1, -1, -1, -1, 0, -1, -1, -1, -1, 1, -1, -1, -1, 9, 2, -1, -1, 8, 19, 3, -1, 7, 18, 29, 4, 6, 17, 28, 39, 5, 16, 27, 38, 49, 15, 26, 37, 48, 59, 25, 36, 47, 58, 69, 35, 46, 57, 68, 79, 45, 56, 67, 78, 89, 55, 66, 77, 88, 189, 65, 76, 87, 188, 289, 75, 86, 187, 288, 389, 85, 186, 287, 388, 489, 95, 286, 387, 488, 589, 195, 386, 487, 588, 689, 295, 486, 587, 688, 789, 395, 586, 687, 788, 889, 495, 686, 787, 888, 989, 595, 786, 887, 988, 1989, 695, 886, 987, 1988, 2989, 795, 986, 1987, 2988, 3989, 895, 1986, 2987, 3988, 4989, 995, 2986, 3987, 4988, 5989, 1995, 3986, 4987, 5988, 6989, 2995, 4986, 5987, 6988, 7989, 3995, 5986, 6987, 7988, 8989, 4995, 6986, 7987, 8988, 9989, 5995 },
    { -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, 0, -1, -1, -1, -1, -1, 1, -1, -1, 9, -1, -1, 2, -1, -1, 7, -1, -1, 3, -1, -1, 5, -1, -1, 4, -1, -1, 15, -1, -1, 14, -1, -1, 25, -1, -1, 24, -1, -1, 35, -1, -1, 34, -1, -1, 45, -1, -1, 44, -1, -1, 55, -1, -1, 54, -1, -1, 65, -1, -1, 64, -1, -1, 75, -1, -1, 74, -1, -1, 85, -1, -1, 84, -1, -1, 185, -1, -1, 94, -1, -1, 285, -1, -1, 194, -1, -1, 385, -1, -1, 294, -1, -1, 485, -1, -1, 394, -1, -1, 585, -1, -1, 494, -1, -1, 685, -1, -1, 594, -1, -1, 785, -1, -1, 694, -1, -1, 885, -1, -1, 794, -1, -1, 985, -1, -1, 894, -1, -1, 1985, -1, -1, 994, -1, -1, 2985 },
    { -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, 0, -1, -1, -1, -1, -1, -1, 1, -1, 9, -1, 8, -1, 7, 2, 6, 19, 5, 18, 4, 17, 3, 16, 29, 15, 28, 14, 27, 13, 26, 39, 25, 38, 24, 37, 23, 36, 49, 35, 48, 34, 47, 33, 46, 59, 45, 58, 44, 57, 43, 56, 69, 55, 68, 54, 67, 53, 66, 79, 65, 78, 64, 77, 63, 76, 89, 75, 88, 74, 87, 73, 86, 189, 85, 188, 84, 187, 83, 186, 289, 185, 288, 184, 287, 93, 286, 389, 285, 388, 284, 387, 193, 386, 489, 385, 488, 384, 487, 293, 486, 589, 485, 588, 484, 587, 393, 586, 689, 585, 688, 584, 687, 493, 686, 789, 685, 788, 684, 787, 593, 786, 889, 785, 888, 784, 887, 693, 886, 989, 885 },
    { -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, 0, -1, -1, -1, -1, -1, -1, -1, 1, 9, 8, 7, 6, 5, 4, 3, 2, 19, 18, 17, 16, 15, 14, 13, 12, 29, 28, 27, 26, 25, 24, 23, 22, 39, 38, 37, 36, 35, 34, 33, 32, 49, 48, 47, 46, 45, 44, 43, 42, 59, 58, 57, 56, 55, 54, 53, 52, 69, 68, 67, 66, 65, 64, 63, 62, 79, 78, 77, 76, 75, 74, 73, 72, 89, 88, 87, 86, 85, 84, 83, 82, 189, 188, 187, 186, 185, 184, 183, 92, 289, 288, 287, 286, 285, 284, 283, 192, 389, 388, 387, 386, 385, 384, 383, 292, 489, 488, 487, 486, 485, 484, 483, 392, 589, 588, 587, 586, 585, 584, 583, 492, 689, 688 },
    { -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, 0, -1, -1, -1, -1, -1, -1, -1, -1, 1, -1, -1, -1, -1, -1, -1, -1, -1, 11, -1, -1, -1, -1, -1, -1, -1, -1, 21, -1, -1, -1, -1, -1, -1, -1, -1, 31, -1, -1, -1, -1, -1, -1, -1, -1, 41, -1, -1, -1, -1, -1, -1, -1, -1, 51, -1, -1, -1, -1, -1, -1, -1, -1, 61, -1, -1, -1, -1, -1, -1, -1, -1, 71, -1, -1, -1, -1, -1, -1, -1, -1, 81, -1, -1, -1, -1, -1, -1, -1, -1, 91, -1, -1, -1, -1, -1, -1, -1, -1, 191, -1, -1, -1, -1, -1, -1, -1, -1, 291, -1, -1, -1, -1, -1, -1 },
    { -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31, 32, 33, 34, 35, 36, 37, 38, 39, 40, 41, 42, 43, 44, 45, 46, 47, 48, 49, 50, 51, 52, 53, 54, 55, 56, 57, 58, 59, 60, 61, 62, 63, 64, 65, 66, 67, 68, 69, 70, 71, 72, 73, 74, 75, 76, 77, 78, 79, 80, 81, 82, 83, 84, 85, 86, 87, 88, 89, 90, 181, 182, 183, 184, 185, 186, 187, 188, 189, 190, 281, 282, 283, 284, 285 },
};

int T,n,k;

signed main() 
{
    T=read();
    while (T--)
    {
    	n=read(),k=read();
    	writeln(a[k][n-1]);
    }
    return 0;
}