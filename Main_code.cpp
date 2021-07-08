#include <iostream>
#include <vector>
#include <stack>
#include <unordered_set>
 #include<unordered_map>
using namespace std;
class Pair{
public:
    int dest;
    int cost;
};
vector<Pair > graph[3];
int minfinder(int* distance,int v,bool* visited){
    int minvertex=-1;
    for(int i=0;i<v;i++)
    {
          if((!visited[i])&&(minvertex==-1||distance[i]<distance[minvertex])){
                minvertex=i;
          }
    
    }  
    return minvertex;
    
}
int Dijkstra(bool* visited,int v,int* distance,int sv,unordered_map<string,int> map1,string* cities,string s2){
     unordered_map<string,string> route;
     int found=0;
     for(int i=0;i<v-1;i++){
        int min;
        if(found==0){
            min=sv;
            found=1;
        }else{
            min=minfinder(distance,v,visited);
        }
        // //cout<<"min"<<endl; 
        // //cout<<min<<endl;
            ////cout<<"graph[min].size()"<<graph[min].size()<<endl;
         for(int j=0;j<graph[min].size();j++){
             
        
             if(!visited[graph[min][j].dest]){
                 int tempdistance=distance[min]+graph[min][j].cost;

                     if(tempdistance<distance[graph[min][j].dest]){
                         distance[graph[min][j].dest]=tempdistance;
                         route[cities[graph[min][j].dest]]=cities[min];
                     }
                     
             }
         }
        visited[min]=true;
     }
 
     // for(int i=0;i<v;i++){
     //     //cout<<cities[i]<<" "<<distance[i]<<endl;
     // }
    cout<<"*----------------------------------*"<<endl;

     string s=s2;
     cout<<s2<<" -->";
     while(route.count(s)!=0){
        cout<<route[s]<<" --> ";
        s=route[s];
     }
     cout<<endl;
     return distance[map1[s2]];
    
}
int distance_finder(string s1,string s2){
     // Write your code here
     #ifndef ONLINE_JUDGE
  
    // For getting input from input.txt file
    freopen("cities.txt", "r", stdin);
    int v;
    int e;
    cin>>v>>e;
    
   

    string* cities=new string[v];
    unordered_map<string,int> map1;
    for (int i = 0; i < v; ++i)
    {
        //cout<<"enter all the cities name";
        cin>>cities[i];
        map1[cities[i]]=i;
    }
    for(int i=0;i<e;i++){
        int f,s,d;
        string s1,s2;
        //cout<<"enter from city"<<endl;
        cin>>s1;
        //cout<<"to city"<<endl;
        cin>>s2;
        f=map1[s1];
        s=map1[s2];
        //cout<<"enter distance between them"<<endl;
        cin>>d;
        vector<Pair > v;
        Pair p1;
        p1.dest=s;
        p1.cost=d;
        graph[f].push_back(p1);
        p1.dest=f;
        graph[s].push_back(p1);
        

    }

    for (int i = 0; i < 4; ++i)
    {
        /* code */  
        //cout<<cities[i]<<" ";
        for (int j = 0; j < graph[i].size(); ++j)
        {
            /* code */
            //cout<<cities[graph[i][j].dest]<<" "<<graph[i][j].cost<<" ";
        }
        //cout<<endl;
    }
    
    bool* visited=new bool[v];
    for(int i=0;i<v;i++){
        visited[i]=false;
    }
    
    int* distance=new int[v];
    
   
    
    // distance[0]=0;

    //cout<<"enter city in which you want to travel ";
   
    int sv=map1[s1];
    

    for(int i=0;i<v;i++){
        distance[i]=INT_MAX;
    }

    distance[sv]=0;


    // for(int i=0;i<v;i++){
    //     //graph[i]=new int[v];
    //     for(int j=0;j<v;j++){
    //         //cout<<graph[i][j]<<" ";
    //     }
    //     //cout<<endl;
    // }

    int distance_fromthiscity=Dijkstra(visited,v,distance,sv,map1,cities,s2);
    cout<<"*----------------------------------*"<<endl;
    cout<<"distance between "<<cities[sv]<<" and "<< s2 <<distance_fromthiscity<<" km"<<endl;

    #endif
    return distance_fromthiscity;
}


class bus{
public:
    int seats;
    bool actype;
    int speed;
    int fair;
    
    bus(int seats1,bool actype1,int speed1,int fair){
        //cout<<"123"<<endl;
        actype=actype1;
        seats=seats1;
        speed=speed1;
        fair=fair;
    }
};


class volvo{
public:
    //bool type;
    bus* s;
    volvo(){
        s=new bus(24,true,100,500);
    }
};


class govt_bus{
 public:
    //bool type;
    bus* s;
    govt_bus(){
        bus* s=new bus(23,false,80,200);
    }
};


int main() {
    string months[13]={" ","january","Feburary","March","April","May","Jun","july","August","september","october","november","december"};
    volvo *volvo_bus=new volvo;
    govt_bus *govt_bus1=new govt_bus;
    cout<<"*..................Welcome to new India travels..................*"<<endl;
    cout<<"enter type of bus you want out of \n 1.volvo \n 2.govt Bus Service";
    int x;
    cin>>x;
    if(x==1){
        //cout<<vseats;
        string s1,s2;
        cout<<"enter starting city"<<endl;
        cin>>s1;
        cout<<"enter ending city"<<endl;
        cin>>s2;
        int ans=distance_finder(s1,s2);
        int eta=ans/volvo_bus->s->speed;
        time_t my_time = time(NULL);
        printf("current time is %s ", ctime(&my_time));
        cout<<endl;
        tm *local_time = localtime(&my_time);
        cout<<"you will reach in ";
        cout<<eta<<" hr"<<endl;
        time_t now = time(0);

         tm *ltm = localtime(&now);

   
     
        if(eta>24){
            cout<<1+ltm->tm_mday<<" "<<months[1+ltm->tm_mon]<<" "<<1900+ltm->tm_year<<" "<<eta+ltm->tm_hour<< ":"<<ltm->tm_min << ":"<<ltm->tm_sec;
            
        }else{
            cout<<ltm->tm_mday<<" "<<months[1+ltm->tm_mon]<<" "<<1900+ltm->tm_year<<" "<<eta+ltm->tm_hour<< ":"<<ltm->tm_min << ":"<<ltm->tm_sec;
            

        }
        cout<<endl;


    }else{
        string s1,s2;
        cout<<"enter starting city"<<endl;
        cin>>s1;
        cout<<"enter ending city"<<endl;
        cin>>s2;
        int ans=distance_finder(s1,s2);
        int eta=ans/govt_bus1->s->speed;
        time_t my_time = time(NULL);
        printf("current time is %s ", ctime(&my_time));
        cout<<endl;
        tm *local_time = localtime(&my_time);
        cout<<"you will reach by ";
        time_t now = time(0);

         tm *ltm = localtime(&now);

   
    
        if(eta>24){
            cout<<1+ltm->tm_mday<<" "<<months[1+ltm->tm_mon]<<" "<<1900+ltm->tm_year<<" "<<eta+ltm->tm_hour<< ":"<<ltm->tm_min << ":"<<ltm->tm_sec;
            
        }else{
            cout<<ltm->tm_mday<<" "<<months[1+ltm->tm_mon]<<" "<<1900+ltm->tm_year<<" "<<eta+ltm->tm_hour<< ":"<<ltm->tm_min << ":"<<ltm->tm_sec;
            

        }
        cout<<endl;
        
    }
    
    
}



