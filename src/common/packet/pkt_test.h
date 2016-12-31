#pragma once

#include "CharacterInfoMessage.h"
#include "CharacterRequestMessage.h"
#include "ConnectToWorldMessage.h"
#include "ConnectToWorldRequestMessage.h"
#include "ControlSync.h"
#include "ControlSyncResp.h"
#include "ClientChallengeXchg.h"
#include "ClientFinished.h"
#include "ClientStart.h"
#include "KeepAliveMessage.h"
#include "LoadMapMessage.h"
#include "LoginMessage.h"
#include "LoginRespMessage.h"
#include "ObjectCreateMessage.h"
#include "opcodes.h"
#include "pkt_header.h"
#include "ServerChallengeXchg.h"
#include "ServerFinished.h"
#include "ServerStart.h"
#include "SetCurrentAvatarMessage.h"
#include "SlottedMetaAck.h"
#include "SlottedMetaPacket.h"
#include "VNLWorldStatusMessage.h"

#define assertBuffersEqual(actual, expected) do {\
    if (actual != expected) {\
        std::cout << "Assert failed! File \"" << __FILE__ << "\" line " << __LINE__ << std::endl;\
        std::cout << std::hex << std::uppercase << "actual (" << #actual << ") vs expectd:" << std::endl << "{" << strHex(actual) << "}" << std::endl << "{" << strHex(expected) << "}" << std::dec << std::nouppercase << std::endl << std::endl;\
    }\
} while (0)

#define assertEqual(actual, expected) do {\
    if (actual != expected) {\
        std::cout << "Assert failed! File \"" << __FILE__ << "\" line " << __LINE__ << std::endl;\
        std::cout << std::hex << std::uppercase << "actual (" << #actual << ") vs expected:" << std::endl << "{" << actual << "}" << std::endl << "{" << expected << "}" << std::dec << std::nouppercase << std::endl << std::endl;\
    }\
} while (0)

#define assertOpcode(bitStream, expectedOpcode) do {\
    uint8_t opcode;\
    bitStream.read(&opcode);\
    assertEqual(opcode, expectedOpcode);\
} while (0)

#define assertControlOpcode(bitStream, expectedOpcode) do {\
    uint8_t opcode;\
    bitStream.read(&opcode);\
    assertEqual(opcode, 0x00);\
    assertOpcode(bitStream, expectedOpcode);\
} while (0)

void testPacketCodingControl();
void testPacketCodingCrypto();
void testPacketCodingGame();