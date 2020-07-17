//
// Created by waheed on 7/13/20.
//

#include "ua_pubsub_amqp.h"
#include <open62541/plugin/log_stdout.h>

/**
 * Open AMQP connection, connects to AMQP-1.0 broker
 * @param amqpConnectionConfig
 * @return Pointer to PubSubChannel if successful otherwise null
 */
static UA_PubSubChannel *UA_PubSubChannelAMQP_open(UA_PubSubConnectionConfig *amqpConnectionConfig)
{
    /* Create a new pubsub channel */
    UA_PubSubChannel *amqpChannel = (UA_PubSubChannel *) UA_calloc(1, sizeof(UA_PubSubChannel));
    if(!amqpChannel){
        UA_LOG_ERROR(UA_Log_Stdout, UA_LOGCATEGORY_SERVER, "PubSub AMQP Connection creation failed. Out of memory.");
        return NULL;
    }

    return amqpChannel;
}
/**
 * Generate a new AMQP channel. Based on the given configuration.
 *
 * @param connectionConfig connection configuration
 * @return  ref to created channel, NULL on error
 */
static UA_PubSubChannel *
TransportLayerAMQP_addChannel(UA_PubSubConnectionConfig *connectionConfig) {
    UA_LOG_INFO(UA_Log_Stdout, UA_LOGCATEGORY_USERLAND, "PubSub AMQP: channel requested.");
    UA_PubSubChannel * pubSubChannel = UA_PubSubChannelAMQP_open(connectionConfig);
    /*
    if(pubSubChannel){
        pubSubChannel->regist = UA_PubSubChannelMQTT_regist;
        pubSubChannel->unregist = UA_PubSubChannelMQTT_unregist;
        pubSubChannel->send = UA_PubSubChannelMQTT_send;
        pubSubChannel->close = UA_PubSubChannelMQTT_close;
        pubSubChannel->yield = UA_PubSubChannelMQTT_yield;

        pubSubChannel->connectionConfig = connectionConfig;
    }
     */
    return pubSubChannel;
}

UA_PubSubTransportLayer
UA_PubSubTransportLayerAMQP(void) {
    UA_PubSubTransportLayer pubSubTransportLayer;
    pubSubTransportLayer.transportProfileUri = UA_STRING("http://opcfoundation.org/UA-Profile/Transport/pubsub-amqp");
    pubSubTransportLayer.createPubSubChannel = &TransportLayerAMQP_addChannel;
    return pubSubTransportLayer;
}
