//
// Created by waheed on 7/13/20.
//

#ifndef OPEN62541_UA_PUBSUB_AMQP_H
#define OPEN62541_UA_PUBSUB_AMQP_H


#ifdef __cplusplus
extern "C" {
#endif

#include <open62541/plugin/pubsub.h>

/* AMQP network layer specific internal data */
typedef struct {
    UA_NetworkAddressUrlDataType address;

} UA_PubSubChannelDataAMQP;

UA_PubSubTransportLayer
UA_PubSubTransportLayerAMQP(void);


#ifdef __cplusplus
} // extern "C"
#endif

#endif //OPEN62541_UA_PUBSUB_AMQP_H
