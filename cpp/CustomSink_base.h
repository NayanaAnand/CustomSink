#ifndef SINKSOCKET_BASE_IMPL_BASE_H
#define SINKSOCKET_BASE_IMPL_BASE_H

#include <boost/thread.hpp>
#include <ossie/Component.h>
#include <ossie/ThreadedComponent.h>

#include <bulkio/bulkio.h>
#include "struct_props.h"

class CustomSink_base : public Component, protected ThreadedComponent
{
    public:
        CustomSink_base(const char *uuid, const char *label);
        ~CustomSink_base();

        void start() throw (CF::Resource::StartError, CORBA::SystemException);

        void stop() throw (CF::Resource::StopError, CORBA::SystemException);

        void releaseObject() throw (CF::LifeCycle::ReleaseError, CORBA::SystemException);

        void loadProperties();

    protected:
        // Member variables exposed as properties
        /// Property: total_bytes
        double total_bytes;
        /// Property: bytes_per_sec
        float bytes_per_sec;
        /// Property: Connections
        std::vector<Connection_struct> Connections;
        /// Property: ConnectionStats
        std::vector<ConnectionStat_struct> ConnectionStats;

        // Ports
        /// Port: dataOctet_in
        bulkio::InOctetPort *dataOctet_in;
        /// Port: dataChar_in
        bulkio::InCharPort *dataChar_in;
        /// Port: dataShort_in
        bulkio::InShortPort *dataShort_in;
        /// Port: dataUshort_in
        bulkio::InUShortPort *dataUshort_in;
        /// Port: dataLong_in
        bulkio::InLongPort *dataLong_in;
        /// Port: dataUlong_in
        bulkio::InULongPort *dataUlong_in;
        /// Port: dataFloat_in
        bulkio::InFloatPort *dataFloat_in;
        /// Port: dataDouble_in
        bulkio::InDoublePort *dataDouble_in;

    private:
};
#endif // SINKSOCKET_BASE_IMPL_BASE_H
