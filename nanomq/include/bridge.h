#ifndef NANOMQ_BRIDGE_H
#define NANOMQ_BRIDGE_H

#include "nng/mqtt/mqtt_client.h"
#include "nng/nng.h"
#include "nng/supplemental/nanolib/conf.h"
#include "nng/supplemental/util/platform.h"
#include <stdio.h>
#include <stdlib.h>

typedef struct {
	nng_socket       *sock;
	conf_bridge_node *config;
	nng_mqtt_client  *client;
	nng_msg          *connmsg;
	conf             *conf;
	nng_mtx          *switch_mtx;
	nng_cv           *switch_cv;
	nng_mtx          *exec_mtx;
	nng_cv           *exec_cv;
} bridge_param;

extern bool topic_filter(const char *origin, const char *input);
extern int  bridge_client(
     nng_socket *sock, conf *config, conf_bridge_node *bridge_conf);
extern int hybrid_bridge_client(
    nng_socket *sock, conf *config, conf_bridge_node *node);
extern nng_msg *bridge_publish_msg(const char *topic, uint8_t *payload,
    uint32_t len, bool dup, uint8_t qos, bool retain, property *props);

#endif // NANOMQ_BRIDGE_H
