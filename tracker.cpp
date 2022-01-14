#include <iostream>
#include <vector>
#include <cstdlib>
#include <iostream>
#include <sstream>
#include <string>
#include <iomanip> 

using namespace std;

// global variables for total males and females
int totalMales = 0;
int totalFemales = 0;

class Country{
    
    private:
        string name;
        int males=0;
        int females=0;
            
    public:
        void setName(string s){
            name = s;
        }
        void setMales(int m){
            males += m;
        }
        void setFemales(int f){
            females += f;
        }
        
        int getTotal(){
            return males + females; 
        }
        string getName(){
            return name; 
        }
        
        void print(){
            cout<< name << " " << males+females <<  endl;

        }

            
};

// class for cities inheriting from class Country

class City: public Country{
    
    public:
    void printb(){
        cout << getName() << " " << getTotal() << endl;
    } 
    
};

int checkifCountryExist(vector<Country> &a, string n){
    for(int i=0; i<a.size(); i++){
        if(a[i].getName() == n){
            return i;
        }
        
        
    }
    return -1; 
}

int checkifCitiesyExist(vector<City> &a, string n){
    for(int i=0; i<a.size(); i++){
        if(a[i].getName() == n){
            return i;
        }
        
        
    }
    return -1; 
}


int main()
{
    
    //defining size of the original vector
    int size = 4; 
    int sizec = 4; 
    
    //temp variables for parsing
    string name; // 
    string city;
    string gender;
    int count; // 
    string line;
    
    
    //vector for countries
    vector<Country> c(size);
    
    //vector for cities
    vector<City> cities(sizec);
    
    
    // i keeps track of number of entries for countries
    int i=0; 
    
    // j keeps track of number of entries for cities
    int j=0; 
    
    
        while(1){

        if(i == size){
            //cout<< "resizing from " << size<< " to ";
            size*= size;
            //cout << "size " << size<<  endl;
            c.resize(size);
        }
        
        if(j == sizec){
            //cout<< "resizing from " << size<< " to ";
            sizec*= sizec;
            //cout << "size " << size<<  endl;
            cities.resize(sizec);
        }
        
        cout << "> ";
        getline(cin, line);
        
        stringstream lineStream(line);
        lineStream >> name;
        
        if (name == "e"){
            break;
        }
        lineStream >> city; 
        lineStream >> gender; 
        lineStream >>count;
        
        
        //check if country exists
        int check = checkifCountryExist(c, name);
        
        //check if city exists
        int cityCheck = checkifCitiesyExist(cities, city);
        
        //cout << check << endl;
        
        if(check != -1){
            
            cout<< "Country already exists.. Updating.. " << endl;
            if(gender =="m"){
                c[check].setMales(count);
                totalMales+= count;
                if(cityCheck!=-1){
                    cities[cityCheck].setMales(count);
                }
                else{
                    cout<< "Adding new city.." << endl;
                    cities[j].setName(city);
                    cities[j].setMales(count);
                    j++;
                }
            }
            else{
                c[check].setFemales(count);
                totalFemales+= count;
                if(cityCheck!=-1){
                    cout<< "city already exists.. Updating.. " << endl;
                    cities[cityCheck].setFemales(count);
                }
                else{
                    cout<< "Adding new city.." << endl;
                    cities[j].setName(city);
                    cities[j].setFemales(count);
                    j++;
                }
            }
            
        }
        else{
            cout<< "Adding new Country.." << endl;
            cout<< "Adding new city.." << endl;
            c[i].setName(name);
            cities[j].setName(city);
            if(gender =="m"){
                c[i].setMales(count);
                totalMales+= count;
                cities[j].setMales(count);
                j++;
                
            }
            else{
                c[i].setFemales(count);
                totalFemales+= count;
                cities[j].setFemales(count);
                j++;
                
            }
            i++;
            
            }
        
        }
        
        
        
        c.resize(i);
        cities.resize(j);

        
        
        //cout<< " size: " << c.size() << endl;
        
    cout<< "Countries: " << endl;
    for(int i=0; i<c.size(); i++){
            c[i].print();
        }    
        
    cout<< "Cities: " << endl;
    for(int i=0; i<cities.size(); i++){
            cities[i].printb();
        }

        cout<< "Males: " <<  totalMales << endl; 
        cout<< "Females: " <<  totalFemales << endl;
           

    return 0;
}
