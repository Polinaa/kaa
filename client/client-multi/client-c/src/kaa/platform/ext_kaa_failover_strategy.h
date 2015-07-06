
/*
 * Copyright 2014-2015 CyberVision, Inc.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#ifndef EXT_FAILOVER_STRATEGY_H_
#define EXT_FAILOVER_STRATEGY_H_

#ifndef KAA_FAILOVER_STRATEGY
    #define KAA_FAILOVER_STRATEGY
        typedef struct kaa_failover_strategy_t       kaa_failover_strategy_t;
#endif

#include <stddef.h>
#include "../kaa_error.h"
#include "../platform/time.h"

#define KAA_FAILOVER_RETRY_PERIOD                 5
#define KAA_BOOTSTRAP_RESPONSE_PERIOD            10

typedef enum {
    KAA_NOOP = 0, /*!< Nothing to be done. */
    KAA_RETRY,    /*!< Initiate log upload. */
    KAA_STOP_APP
} kaa_failover_strategy_action_t;


typedef struct {
    kaa_failover_strategy_action_t action;
    kaa_time_t retry_period;
} kaa_failover_decision_t;

kaa_error_t kaa_failover_strategy_set_decision(kaa_failover_strategy_t *self, kaa_failover_decision_t *decision);

#endif /* EXT_FAILOVER_STRATEGY_H_ */
