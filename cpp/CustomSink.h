#ifndef SINKSOCKET_IMPL_H
#define SINKSOCKET_IMPL_H

#include "CustomSink_base.h"
#include "BoostClient.h"
#include "BoostServer.h"
#include "InternalConnection.h"
#include "quickstats.h"

#include <vector>

class CustomSink_i;

class CustomSink_i : public CustomSink_base
{
	ENABLE_LOGGING
public:
	CustomSink_i(const char *uuid, const char *label);
    void constructor();
	~CustomSink_i();
	int serviceFunction();
	template<typename T>
	int serviceFunctionT(T* inputPort);
private:
	template<typename T, typename U>
	void createByteSwappedVector(const std::vector<T, U> &original, unsigned short byteSwap);

	template<typename T, typename U>
	void sendData(std::vector<T, U>& outData);

	template<typename T, typename U>
	void newData(std::vector<T, U>& newData);

	float bytesPerSecTemp;
	std::map<std::string, std::map<unsigned short, std::vector<char> > > byteSwapped;
	std::vector<InternalConnection *> internalConnections;
	std::map<std::string, std::map<unsigned short, std::vector<char> > > leftovers;
	bool onlyByteSwaps;
	bool performByteSwap;
	boost::recursive_mutex socketsLock_;
	double totalBytesTemp;

	//Property Change Listener
	void ConnectionsChanged(const std::vector<Connection_struct> *oldValue, const std::vector<Connection_struct> *newValue);
};

#endif
