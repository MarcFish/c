#include<algorithm>
#include<vector>
using namespace std;
vector<int> s;
bool cmp(int x,int y){
    return true;
}
bool pred(int x){
    return true;
}
int main(void){
    //
    auto mi=min_element(s.begin(),s.end(),cmp);//*mi
    auto ma=max_element(s.begin(),s.end(),cmp);//*ma
    auto mima=minmax_element(s.begin(),s.end(),cmp);//*mima.first,*mima.second

    //
    sort(s.begin(),s.end(),cmp);
    stable_sort(s.begin(),s.end(),cmp);
    partial_sort(s.begin(),s.begin()+5,s.end(),cmp);
    //partial_sort_copy(s.begin(),s.begin()+5,s.end(),cmp);
    is_sorted(s.begin(),s.end(),cmp);

    //
    bool flag=binary_search(s.begin(),s.end(),5,cmp);//return bool
    auto iter=equal_range(s.begin(),s.end(),5,cmp);//if (!(a<b) && !(b<a)) or if (!comp(a,b) && !comp(b,a))
                                                    //iter.first-s.begin() iter.second-s.begin()
    auto iter=lower_bound(s.begin(),s.end(),5,cmp);//iter-s.begin()
    auto iter=upper_bound(s.begin(),s.end(),5,cmp);//iter-s.begin()

    //
    bool flag=all_of(s.begin(),s.end(),pred);
    bool flag=any_of(s.begin(),s.end(),pred);
    bool flag=none_of(s.begin(),s.end(),pred);
    auto iter=find(s.begin(),s.end(),5);//operator ==
    auto iter=find_if(s.begin(),s.end(),pred);
    int n=count(s.begin(),s.end(),5);//operator ==
    //int n=count_if(s.begin(),s.end(),5,pred);

    //
    auto iter=unique(s.begin(),s.end(),pred);//operator ==
    reverse(s.begin(),s.end());
    rotate(s.begin(),s.begin()+3,s.end());//1 2 3 4 5 6 7 8 9->4 5 6 7 8 9 1 2 3

    vector<int> a,b;
    merge(a.begin(),a.end(),b.begin(),b.end(),s.begin(),cmp);//if (!(a<b) && !(b<a)) or if (!comp(a,b) && !comp(b,a))
    bool flag=includes(a.begin(),a.end(),b.begin(),b.end(),cmp);//a in b
    auto iter=set_union(a.begin(),a.end(),b.begin(),b.end(),s.begin(),cmp);//if (!(a<b) && !(b<a)) or if (!comp(a,b) && !comp(b,a))
    auto iter=set_intersection(a.begin(),a.end(),b.begin(),b.end(),s.begin(),cmp);//if (!(a<b) && !(b<a)) or if (!comp(a,b) && !comp(b,a))
    auto iter=set_difference(a.begin(),a.end(),b.begin(),b.end(),s.begin(),cmp);//if (!(a<b) && !(b<a)) or if (!comp(a,b) && !comp(b,a))

    auto iter=search(a.begin(),a.end(),b.begin(),b.end(),pred);//operator == iter-a.begin()
    auto iter=search_n(a.begin(),a.end(),5,pred);//operator ==
    bool flat=equal(a.begin(),a.end(),b.begin(),b.end(),pred);
    auto iter=stable_partition(a.begin(),a.end(),pred);//

    bool flag=next_permutation(s.begin(),s.end(),cmp);
    bool flag=prev_permutation(s.begin(),s.end(),cmp);
}