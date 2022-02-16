

#include "DataStore.h"



int main(){
	map<string,Mapval*> mymap;
	DataStore ds= DataStore();
	ds.create<int>();
	ds.create<bool>();
	Store<char>* mystore = new Store<char>(); // @suppress("Ambiguous problem")
	char l='f';
	mystore->append(l);
	int k=0;
	cout<<mystore->read(k)<<endl; // @suppress("Invalid overload") // @suppress("Ambiguous problem")
	mymap["int"]=(Mapval*)mystore;
	cout<< ((Store<int>*)mymap["int"])->read(k); // @suppress("Ambiguous problem")
}
