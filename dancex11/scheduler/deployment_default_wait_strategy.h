/**
 * @file    deployment_default_wait_strategy.h
 * @author  Martin Corino
 *
 * @brief   Default deployment event completion wait strategy.
 *
 * @copyright Copyright (c) Remedy IT Expertise BV
 */

#ifndef DEPLOYMENT_DEFAULT_WAIT_STRATEGY_H_
#define DEPLOYMENT_DEFAULT_WAIT_STRATEGY_H_

#pragma once

#include "dancex11/scheduler/completion_base.h"
#include "dancex11/scheduler/deployment_scheduler.h"

namespace DAnCEX11
{
  template <typename RESULT>
  class Default_Completion_Wait_Strategy final
  {
  public:
    using completion_type = Completion_T<Default_Completion_Wait_Strategy, RESULT>;

    Default_Completion_Wait_Strategy (
        completion_type &counter,
        Deployment_Scheduler &sched)
      : counter_ (counter)
      , sched_ (sched)
    {}
    ~Default_Completion_Wait_Strategy () = default;

    /// Waits for completion of all events, with a timeout
    bool
    wait_on_completion (ACE_Time_Value *tv);

  private:

    bool
    single_threaded_wait_on_completion (ACE_Time_Value *tv);

    completion_type &counter_;
    Deployment_Scheduler &sched_;
  };
}

#include "deployment_default_wait_strategy.cpp"

#endif /* DEPLOYMENT_DEFAULT_WAIT_STRATEGY_H_ */
