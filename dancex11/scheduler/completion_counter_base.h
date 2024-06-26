// -*- C++ -*-
/**
 * @file    completion_counter_base.h
 * @author Johnny Willemsen, Martin Corino
 *
 * @copyright Copyright (c) Remedy IT Expertise BV
 */
#ifndef DAnCEX11_COMPLETION_COUNTER_H
#define DAnCEX11_COMPLETION_COUNTER_H

#pragma once

#include /**/ "ace/config-all.h"
#include "ace/Null_Mutex.h"

#include <string>
#include <vector>

namespace DAnCEX11
{

  template <class ACE_LOCK>
  class Completion_Counter_Base
  {
  public:
    using lock_type = ACE_LOCK ;
    using errors_type = std::vector<std::string>;

    Completion_Counter_Base (uint32_t exec_count,
      uint32_t fail_count);

    virtual ~Completion_Counter_Base () = default;

    void decrement_exec_count ();

    void increment_fail_count (const char* error);

    uint32_t exec_count ();

    uint32_t fail_count ();

    bool all_completed ();

    const errors_type& errors () const;

    //@{
    /** Illegal to be called. Deleted explicitly to let the compiler detect any violation */
    Completion_Counter_Base () = delete;
    Completion_Counter_Base (const Completion_Counter_Base&) = delete;
    Completion_Counter_Base (Completion_Counter_Base&&) = delete;
    Completion_Counter_Base& operator= (const Completion_Counter_Base& x) = delete;
    Completion_Counter_Base& operator= (Completion_Counter_Base&& x) = delete;
    //@}
  protected:
    void increment_exec_count ();

    uint32_t exec_count_i ();

    uint32_t fail_count_i ();

    virtual void on_all_completed () = 0;

    virtual void on_all_completed_with_failure () = 0;

  private:
    mutable ACE_LOCK lock_;
    uint32_t exec_count_;
    uint32_t fail_count_;

    errors_type errors_;
  };

} /* DAnCE */

#include "completion_counter_base.cpp"

#endif /* DAnCEX11_COMPLETION_COUNTER_H */
