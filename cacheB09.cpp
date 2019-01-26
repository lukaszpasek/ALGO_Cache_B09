#include<iostream>
#include<map>
#include <queue>
#include <set>
#include <vector>
#include <algorithm>

using namespace std;
vector < int > references[1000001];

int main()
{

   int t; // number of datasets
   cin>>t;

   for(int i=0 ; i<t ; i++)
   {
       int cache_size,max_value,volume,value;
    cin>>cache_size>>max_value>>volume;
    int points=0;

        map < int, int > chart;
        set < int > cache2;
        set < int > cache1;
        vector < int > x;
        for(int i=0 ; i<volume ; i++)
   {
      //loading data
       cin>>value;
       x.push_back(value);
       references[x[i]].push_back(i);

   }
         queue <int> get_out;
          for(int i=0 ; i<volume ; i++)
   {

               if( i<cache_size && !cache1.count(x[i])) {
               //when cache isn't full and number doesn't exist in cache
               cache1.insert(x[i]);
               // we put reference and value to proper sets
               if( chart[x[i]]<references[x[i]].size()-1)
               {

               cache2.insert(references[x[i]][chart[x[i]]+1]);
               }

               points++;
               }

          if( !cache1.count(x[i])) {


          if(cache1.size()==cache_size)
          {
            // we delete reference and value from proper sets
             if(!get_out.empty())
            {
        cache1.erase(get_out.front());
        cache2.erase(references[get_out.front()][chart[get_out.front()]-1]);
          get_out.pop();

            }
          else
           {
             set<int>::iterator p=cache2.end();
             p--;
         cache1.erase(x[*p]);
         cache2.erase(*p);
          }
           }

          if(cache1.size()<cache_size)
          {  // we put reference and value to proper sets
              cache1.insert(x[i]);
               if( chart[x[i]]<references[x[i]].size()-1)
               {

               cache2.insert(references[x[i]][chart[x[i]]+1]);
               }
          }
          points++;
       }


         else if(cache1.count(x[i]) && chart[x[i]]<references[x[i]].size()-1)
             {  // when value,which exist in set perform next time we havo to change reference
               cache2.erase(references[x[i]][chart[x[i]]]);
               cache2.insert(references[x[i]][chart[x[i]]+1]);
             }


           chart[x[i]]++; // we count perfomances of numbers
             if(chart[x[i]]==references[x[i]].size())
        {// we put numebr into proper set,when number perform last time
            get_out.push(x[i]);

        }
     }
  cout<<points<<endl;

      for(int i=0 ; i<volume ; i++)
   {   //Because vector is global we have to clear for next time
       references[x[i]].clear();
   }

   }
return 0;
}
