#ifndef ZWCC_ASSOCIATION_H
#define ZWCC_ASSOCIATION_H

#include "Arduino.h"

/* Association command class commands */
#define ASSOCIATION_VERSION                                                              0x02
#define ASSOCIATION_GET                                                                  0x02
#define ASSOCIATION_GROUPINGS_GET                                                        0x05
#define ASSOCIATION_GROUPINGS_REPORT                                                     0x06
#define ASSOCIATION_REMOVE                                                               0x04
#define ASSOCIATION_REPORT                                                               0x03
#define ASSOCIATION_SET                                                                  0x01
#define ASSOCIATION_SPECIFIC_GROUP_GET                                                   0x0B
#define ASSOCIATION_SPECIFIC_GROUP_REPORT                                                0x0C

/* Multi Channel Association command class commands */
#define MULTI_CHANNEL_ASSOCIATION_VERSION                                                0x02
#define MULTI_CHANNEL_ASSOCIATION_GET                                                    0x02
#define MULTI_CHANNEL_ASSOCIATION_GROUPINGS_GET                                          0x05
#define MULTI_CHANNEL_ASSOCIATION_GROUPINGS_REPORT                                       0x06
#define MULTI_CHANNEL_ASSOCIATION_REMOVE                                                 0x04
#define MULTI_CHANNEL_ASSOCIATION_REPORT                                                 0x03
#define MULTI_CHANNEL_ASSOCIATION_SET                                                    0x01

/* Association Grp Info command class commands */
#define ASSOCIATION_GRP_INFO_VERSION                                                     0x02
#define ASSOCIATION_GROUP_NAME_GET                                                       0x01
#define ASSOCIATION_GROUP_NAME_REPORT                                                    0x02
#define ASSOCIATION_GROUP_INFO_GET                                                       0x03
#define ASSOCIATION_GROUP_INFO_REPORT                                                    0x04
#define ASSOCIATION_GROUP_COMMAND_LIST_GET                                               0x05
#define ASSOCIATION_GROUP_COMMAND_LIST_REPORT                                            0x06

int zuno_CCAssociationHandler(ZUNOCommandPacket_t *cmd);
int zuno_CCMultiAssociationHandler(ZUNOCommandPacket_t *cmd);
int zuno_CCAssociationGprInfoHandler(ZUNOCommandPacket_t *cmd);

#endif // ZWCC_ASSOCIATION_H