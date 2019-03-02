#include <fstream>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main()
  {
    vector<int> tab(255);

  string line;
  ifstream myfile( "d.txt" );
  if (myfile)  
    {
    while (getline( myfile, line )){  
        
        
        for(int j = 0; j < line.length(); j++) {
             tab[(int)line[j]] += 1;        
        }   
    }
    myfile.close();
    }
    cout<< "histogram: ";
    for(int i=0;i<tab.size();i++) {
        if(tab[i]!=0)
        {
            cout<<(char)i<<": "<<tab[i]<<endl;
        }
        
    }

    return 0;
}
