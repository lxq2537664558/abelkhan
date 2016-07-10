/*
 * gmmanager.h
 *
 *  Created on: 2016-7-9
 *      Author: qianqians
 */
#ifndef _gmmanager_h
#define _gmmanager_h

#include <unordered_map>

#include <boost/shared_ptr.hpp>

#include <Ichannel.h>

namespace server {

class gmmanager {
public:
	gmmanager() {
	}

	~gmmanager(){
	}

	void reg_channel(std::string gmname, boost::shared_ptr<juggle::Ichannel> ch) {
		gm_channel_map.insert(std::make_pair(gmname, ch));
	}

	void unreg_channel(boost::shared_ptr<juggle::Ichannel> ch) {
		for (auto it = gm_channel_map.begin(); it != gm_channel_map.end(); it++) {
			if (it->second == ch) {
				gm_channel_map.erase(it);
				break;
			}
		}
	}

	bool is_gm(boost::shared_ptr<juggle::Ichannel> ch) {
		for (auto it = gm_channel_map.begin(); it != gm_channel_map.end(); it++) {
			if (it->second == ch) {
				return true;
			}
		}

		return false;
	}

	boost::shared_ptr<juggle::Ichannel> get_channel(std::string gmname) {
		auto it = gm_channel_map.find(gmname);
		if (it != gm_channel_map.end()) {
			return it->second;
		}

		return nullptr;
	}

private:
	std::unordered_map<std::string, boost::shared_ptr<juggle::Ichannel> > gm_channel_map;

};

}

#endif //_gmmanager_h
