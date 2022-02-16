/*
 * DataStore.h
 *
 *  Created on: 25 Jan 2021
 *      Author: faez zangariya
 */

#ifndef DATASTORE_H_
#define DATASTORE_H_
#include "Store.h"
#include "FileNotFound.h"
#include "FileFound.h"
#include <typeinfo>


class DataStore {
public:
	virtual ~DataStore(){
		map<string,Mapval*>::iterator it;

		for (it = storesmap.begin(); it != storesmap.end(); it++){
		    delete it->second;
		}
		delete this;
	}

	template<class T>
	void create(){
		if( storesmap.find(typeid(T).name()) == storesmap.end())
			storesmap[typeid(T).name()]=(Mapval*)new Store<T>;
		else{
			throw FileFound();
		}
	}


	template<class T>
	void load(const char* filename){
		if( storesmap.find(typeid(T).name()) == storesmap.end()){
			create<T>();
			fstream f("store.bin", ios::in | ios::out | ios::binary);
			char* Tbuff;
			while(f.good()){
				f.read(Tbuff,sizeof(T));
				((Store<T>*)storesmap[typeid(T).name()])->append(*reinterpret_cast<T*>(Tbuff));
			}
		}
		else{
			throw FileNotFound();
		}
	}

	template<class T>
	Store<T>* store(){
		if( storesmap.find(typeid(T).name()) == storesmap.end())
			throw FileNotFound();
		else{
			return ((Store<T>*)storesmap[typeid(T).name()]);
		}
	}


private:
	map<string,Mapval*> storesmap;
};

#endif /* DATASTORE_H_ */
