#include <iostream>
#include <utility>
#include <algorithm>
#include <vector>
#include <set>
#include <cstdio>
#include <tuple>
#include <cmath>
using namespace std;
vector<pair<int, int>> skill;
vector<int> prefix_left;
bool sortbysec(const pair<int,int> &a,const pair<int,int> &b){
    return (a.second < b.second);
}
int main(){
    long long int n, x, A, B, m;//x = target
    int prefix = 0;
    tuple<long long int, int, int, int> max = make_tuple(0, 0, 0, 0);
    scanf("%lld %lld %lld %lld %lld", &n, &x, &A, &B, &m);
    for(int i = 1; i <= n; ++i){
        int tmp;
        scanf("%d", &tmp);
        skill.push_back(make_pair(tmp, i));//record the initial order of the input
    }
    sort(skill.begin(), skill.end());//sort by the amount
    for(int j = 0; j < n; ++j){
        prefix += skill[j].first;
        int ans = skill[j].first * (j+1) - prefix;
        prefix_left.push_back(ans);
        //cout << prefix_left[j] << endl;
        //printf("%d\n", prefix_left[j]);
    }
    for(int target_num = 0, i = n; target_num <= n && i >= 0; ++target_num, --i){
        if(target_num != 0){
            m -= x - skill[i].first;
            if(m < 0)break;
        }
        int point = m;
        //printf("point before: %d\n", point);
        int upper = upper_bound(prefix_left.begin(), prefix_left.end(), point) - prefix_left.begin();
        //printf("upper = %d\n", upper);
        if(upper-1 >= n - target_num){
            get<0>(max) = A * target_num + B * x;
            get<1>(max) = n - target_num -1;
            get<2>(max) = target_num;
            get<3>(max) = x;
            continue;
        }
        //printf("upper = %d\n", upper);
        int min_skill = skill[upper-1].first;//the min value
        point -= prefix_left[upper-1];
        //printf("point after = %d\n", point);
        if(upper > 0 ){
            min_skill += floor(point / upper);
        }
        //printf("target_num = %d min_skill = %d\n", target_num, min_skill);
        long long int tmp = A * target_num + B * min_skill;
        if(get<0>(max) < tmp){
            get<0>(max) = tmp;
            get<1>(max) = upper-1;
            get<2>(max) = target_num;
            get<3>(max) = min_skill;
            //printf("max = %d skill_upper = %d\n", get<0>(max), skill[get<1>(max)].first);

        }
        //printf("-------------------------------------------------\n");
        
    }
    //printf("%d %d %d %d\n", get<0>(max), get<1>(max), get<2>(max), get<3>(max));
    //printf("skill[max.second].first : %d\n", skill[max.second].first);
    /*for(int i = 0; i < n; ++i){
        printf("%d%c", skill[i].first, (i == n-1)*'\n'+(i != n-1)*' ');
    }*/
    for(int i = 0, num = skill[get<1>(max)].first/*get<3>(max)*/; i <= get<1>(max); ++i){
        skill[i].first = num;
    }
    for(int i = n-1; i >= n - get<2>(max); --i){
        skill[i].first = x;
    }
    /*for(int i = 0; i < n; ++i){
        printf("%d%c", skill[i].first, (i == n-1)*'\n'+(i != n-1)*' ');
    }*/
    sort(skill.begin(), skill.end(), sortbysec);
    printf("%lld\n", get<0>(max));
    for(int i = 0; i < n; ++i){
        printf("%d%c", skill[i].first, (i == n-1)*'\n'+(i != n-1)*' ');
    }
    
}