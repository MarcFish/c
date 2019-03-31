#include<map>
using namespace std;
map<int,string> p;//用int做索引并指向string
p[1]="sss";
p[2]="sssdd";
map<int string>::iterator iter;
for(iter= p.begin();iter!=p.end();iter++)
printf("%d %s",iter->first,iter->second);
p.size()//大小
iteration=p.find(1);
if(iter!=p.end())
    printf("%s",iter->second);
p.erase(iter);
