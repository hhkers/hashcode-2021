#include <cmath>
#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <algorithm>

using namespace std;

typedef struct _street {
   int b;
   int e;
   int l;
   int num_of_cars = 0;
} ST;

int D, I, S, V, F;

ST street[100000];
int start_cnt[100000];

int cars[1000][1000];
int car_N[1000];
map<string, int> name_to_id;
map<int, string> id_to_name;

vector<int> inter_in[100000];


bool cmp(pair<string, int> a, pair<string, int> b) {
   if (start_cnt[name_to_id[a.first]] == start_cnt[name_to_id[b.first]]) {
      return a.second < b.second;
   }
   return start_cnt[name_to_id[a.first]] > start_cnt[name_to_id[b.first]];
}
void init() {
   for (int i = 0; i < 100000; i++) {
      inter_in[i].clear();
      start_cnt[i] = 0;
   }
   name_to_id.clear();
   id_to_name.clear();
}
int main() {
   string IN[6] = { "a.txt" , "b.txt", "c.txt", "d.txt", "e.txt", "f.txt" };
   string OUT[6] = { "a.out" , "b.out", "c.out", "d.out", "e.out", "f.out" };
   int WEIGHT[6] = { 10, 2, 15, 5, 2, 27 };

   for (int C = 0; C < 6; ++C) {
      init();

      freopen(IN[C].c_str(), "r", stdin);
      freopen(OUT[C].c_str(), "w", stdout);

      cin >> D >> I >> S >> V >> F;
      int b, e, l;
      string s;
      for (int i = 0; i < S; ++i) {
         cin >> b >> e >> s >> l;
         name_to_id[s] = i;
         id_to_name[i] = s;

         street[i].b = b;
         street[i].e = e;
         street[i].l = l;
         street[i].num_of_cars = 0;
         inter_in[e].push_back(i);
      }

      int p;
      for (int i = 0; i < V; ++i) {
         cin >> p;
         car_N[i] = p;
         for (int j = 0; j < p; ++j) {
            cin >> s;
            int s_id = name_to_id[s];
            cars[i][j] = s_id;
            street[s_id].num_of_cars++;
         }
      }

      if (C == 3) { // for only 'd.txt'
         for (int i = 0; i < V; ++i) {
            int cnt = 0;
            for (int j = 0; j < car_N[i]; ++j) {
               int interN = inter_in[street[cars[i][j]].e].size();
               int streetN = street[cars[i][j]].num_of_cars;
               if (interN > 100 && streetN <= 1)
                  cnt++;
            }
            if (cnt >= 5) {
               bool rm = false;
               for (int j = 0; j < car_N[i]; ++j) {
                  if (street[cars[i][j]].num_of_cars == 1)
                     rm = true;
                  if (rm)
                     street[cars[i][j]].num_of_cars--;
               }
            }
         }
      }

      for (int i = 0; i < V; ++i) {
         start_cnt[cars[i][0]]++;
      }

      vector<pair<int, vector<pair<int, int>>>> print_inter;
      for (int i = 0; i < I; i++) {
         vector<pair<int, int>> tmp;
         for (int j = 0; j < inter_in[i].size(); ++j) {
            int n = street[inter_in[i][j]].num_of_cars;
            if (n > 0) {
               tmp.push_back(make_pair(inter_in[i][j], n));
            }
         }
         if (tmp.size() > 0) {
            print_inter.push_back(make_pair(i, tmp));
         }
      }


      cout << print_inter.size() << endl;
      for (int i = 0; i < print_inter.size(); ++i) {
         cout << print_inter[i].first << endl;
         int n_greens = print_inter[i].second.size();
         cout << n_greens << endl;

         vector<pair<string, int>> tm;
         for (int j = 0; j < n_greens; ++j) {
            string name = id_to_name[print_inter[i].second[j].first];
            int n = print_inter[i].second[j].second;

            n = n / WEIGHT[C];
            if (n < 1)
               n = 1;
            tm.push_back(make_pair(name, n));
         }
         sort(tm.begin(), tm.end(), cmp);

         for (int i = 0; i < tm.size(); ++i) {
            cout << tm[i].first << " " << tm[i].second << endl;
         }
      }



   }
   return 0;

}
