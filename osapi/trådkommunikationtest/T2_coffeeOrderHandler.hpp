#pragma once
#include <osapi/Thread.hpp>
#include <osapi/ThreadFunctor.hpp>
#include "Messages.hpp"
#include <iostream>
#include <string>
#include <osapi/Utility.hpp>
#include "UART.h"
#include "ConvertToGram.h"

class T2_coffeOrderHandler :public osapi::ThreadFunctor
{
public:
  T2_coffeOrderHandler(int size);
  virtual void run();
  void handler(osapi::Message* msg, unsigned long id);
  void sendStatus();
  void setmsgQ(osapi::MsgQueue *msgQ);
  osapi::MsgQueue* getmsgQ();

private:
  osapi::MsgQueue*  mq_;
  osapi::MsgQueue*  T1Mq_;
  UART              UART_;
  ConvertToGram     grams_;
  int               filter_=0;
  Status            status_;
};
