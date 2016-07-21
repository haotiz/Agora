//
//  AGSChatEncryptObserver.m
//  AgoraSample
//
//  Created by junhao wang on 6/7/16.
//  Copyright © 2016 Agora. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <AgoraRtcEngineKit/IAgoraRtcEngine.h>
#include <vector>

#include "AGSChatEncryptObserver.h"

extern "C" int registerAgoraPacketObserver(void* nativeHandle, agora::rtc::IPacketObserver* observer);

class AgoraPacketObserver : public agora::rtc::IPacketObserver
{
public:
    AgoraPacketObserver()
    {
        m_txAudioBuffer.resize(2048);
        m_rxAudioBuffer.resize(2048);
        m_txVideoBuffer.resize(2048);
        m_rxVideoBuffer.resize(2048);
    }
    virtual bool onSendAudioPacket(Packet& packet)
    {
        int i;
        //encrypt the packet
        const unsigned char* p = packet.buffer;
        const unsigned char* pe = packet.buffer+packet.size;
        for (i = 0; p < pe && i < m_txAudioBuffer.size(); ++p, ++i)
        {
            m_txAudioBuffer[i] = *p ^ 0x55;
        }
        //assign new buffer and the length back to SDK
        packet.buffer = &m_txAudioBuffer[0];
        packet.size = i;
        return true;
    }

    virtual bool onSendVideoPacket(Packet& packet)
    {
        int i;
        //encrypt the packet
        const unsigned char* p = packet.buffer;
        const unsigned char* pe = packet.buffer+packet.size;
        for (i = 0; p < pe && i < m_txVideoBuffer.size(); ++p, ++i)
        {
            m_txVideoBuffer[i] = *p ^ 0x55;
        }
        //assign new buffer and the length back to SDK
        packet.buffer = &m_txVideoBuffer[0];
        packet.size = i;
        return true;
    }

    virtual bool onReceiveAudioPacket(Packet& packet)
    {
        int i = 0;
        //decrypt the packet
        const unsigned char* p = packet.buffer;
        const unsigned char* pe = packet.buffer+packet.size;
        for (i = 0; p < pe && i < m_rxAudioBuffer.size(); ++p, ++i)
        {
            m_rxAudioBuffer[i] = *p ^ 0x55;
        }
        //assign new buffer and the length back to SDK
        packet.buffer = &m_rxAudioBuffer[0];
        packet.size = i;
        return true;
    }

    virtual bool onReceiveVideoPacket(Packet& packet)
    {
        int i = 0;
        //decrypt the packet
        const unsigned char* p = packet.buffer;
        const unsigned char* pe = packet.buffer+packet.size;
        for (i = 0; p < pe && i < m_rxVideoBuffer.size(); ++p, ++i)
        {
            m_rxVideoBuffer[i] = *p ^ 0x55;
        }
        //assign new buffer and the length back to SDK
        packet.buffer = &m_rxVideoBuffer[0];
        packet.size = i;
        return true;
    }

private:
    std::vector<unsigned char> m_txAudioBuffer; //buffer for sending audio data
    std::vector<unsigned char> m_txVideoBuffer; //buffer for sending video data

    std::vector<unsigned char> m_rxAudioBuffer; //buffer for receiving audio data
    std::vector<unsigned char> m_rxVideoBuffer; //buffer for receiving video data
};


static AgoraPacketObserver *getXOREncryptObserver()
{
    static AgoraPacketObserver *singletonObserver = new AgoraPacketObserver();
    return singletonObserver;
}

@implementation AGSChatEncryptObserver


+ (int) registerEncryptObserver: (AgoraRtcEngineKit*) kit
{
    if (!kit) {
        return AgoraRtc_Error_Failed;
    }

    return registerAgoraPacketObserver([kit getNativeHandle], getXOREncryptObserver());
}


@end

