// -*- C++ -*-
// $Id$

/**
 * Code generated by the The ACE ORB (TAO) IDL Compiler v1.8.3
 * TAO and the TAO IDL Compiler have been developed by:
 *       Center for Distributed Object Computing
 *       Washington University
 *       St. Louis, MO
 *       USA
 *       http://www.cs.wustl.edu/~schmidt/doc-center.html
 * and
 *       Distributed Object Computing Laboratory
 *       University of California at Irvine
 *       Irvine, CA
 *       USA
 * and
 *       Institute for Software Integrated Systems
 *       Vanderbilt University
 *       Nashville, TN
 *       USA
 *       http://www.isis.vanderbilt.edu/
 *
 * Information about TAO is available at:
 *     http://www.cs.wustl.edu/~schmidt/TAO.html
 **/
#ifndef CIAO_READER_TEST_RECEIVER_EXEC_G1FCGC_H_
#define CIAO_READER_TEST_RECEIVER_EXEC_G1FCGC_H_

#include /**/ "ace/pre.h"

#include "Reader_Test_ReceiverEC.h"

#if !defined (ACE_LACKS_PRAGMA_ONCE)
# pragma once
#endif /* ACE_LACKS_PRAGMA_ONCE */

#include /**/ "Receiver_exec_export.h"
#include "tao/LocalObject.h"

#include <map>

namespace CIAO_Reader_Test_Receiver_Impl
{
  class Receiver_exec_i;

  /**
   * Read Action Generator
   */
  class read_action_Generator
    : public ACE_Event_Handler
  {
  public:
    read_action_Generator (Receiver_exec_i &callback);

    ~read_action_Generator ();

    virtual int handle_timeout (const ACE_Time_Value &tv, const void *arg);
  private:
    Receiver_exec_i &callback_;

  };

  /**
   * Provider Executor Implementation Class: info_out_data_listener_exec_i
   */

  class info_out_data_listener_exec_i
    : public virtual ::Reader_Test::ReaderTestConnector::CCM_Listener,
      public virtual ::CORBA::LocalObject
  {
  public:
    info_out_data_listener_exec_i (
      ::Reader_Test::CCM_Receiver_Context_ptr ctx);
    virtual ~info_out_data_listener_exec_i (void);

    //@{
    /** Operations and attributes from Reader_Test::ReaderTestConnector::Listener. */

    virtual
    void on_one_data (const ::ReaderTest & datum,
    const ::CCM_DDS::ReadInfo & info);

    virtual
    void on_many_data (const ::ReaderTestSeq & data,
    const ::CCM_DDS::ReadInfoSeq & infos);
    //@}

  private:
    ::Reader_Test::CCM_Receiver_Context_var ciao_context_;
  };

  /**
   * Provider Executor Implementation Class: info_out_status_exec_i
   */

  class info_out_status_exec_i
    : public virtual ::CCM_DDS::CCM_PortStatusListener,
      public virtual ::CORBA::LocalObject
  {
  public:
    info_out_status_exec_i (
      ::Reader_Test::CCM_Receiver_Context_ptr ctx);
    virtual ~info_out_status_exec_i (void);

    //@{
    /** Operations and attributes from CCM_DDS::PortStatusListener. */

    virtual
    void on_requested_deadline_missed (::DDS::DataReader_ptr the_reader,
    const ::DDS::RequestedDeadlineMissedStatus & status);

    virtual
    void on_sample_lost (::DDS::DataReader_ptr the_reader,
    const ::DDS::SampleLostStatus & status);
    //@}

  private:
    ::Reader_Test::CCM_Receiver_Context_var ciao_context_;
  };

  /**
   * Provider Executor Implementation Class: reader_start_exec_i
   */

  class reader_start_exec_i
    : public virtual ::CCM_ReaderStarter,
      public virtual ::CORBA::LocalObject
  {
  public:
    reader_start_exec_i (
      ::Reader_Test::CCM_Receiver_Context_ptr ctx,
      Receiver_exec_i & callback);
    virtual ~reader_start_exec_i (void);

    //@{
    /** Operations and attributes from ReaderStarter. */

    virtual
    void start_read (void);

    virtual
    void read_no_data (void);

    virtual
    void set_reader_properties (::CORBA::UShort nr_keys,
    ::CORBA::UShort nr_iterations);
    //@}

  private:
    ::Reader_Test::CCM_Receiver_Context_var ciao_context_;
    Receiver_exec_i &callback_;
  };

  /**
   * Component Executor Implementation Class: Receiver_exec_i
   */

  class Receiver_exec_i
    : public virtual Receiver_Exec,
      public virtual ::CORBA::LocalObject
  {
  public:
    Receiver_exec_i (void);
    virtual ~Receiver_exec_i (void);

    //@{
    /** Supported operations and attributes. */

    //@}

    //@{
    /** Component attributes and port operations. */

    virtual ::Reader_Test::ReaderTestConnector::CCM_Listener_ptr
    get_info_out_data_listener (void);

    virtual ::CCM_DDS::CCM_PortStatusListener_ptr
    get_info_out_status (void);

    virtual ::CCM_ReaderStarter_ptr
    get_reader_start (void);
    //@}

    //@{
    /** Operations from Components::SessionComponent. */
    virtual void set_session_context (::Components::SessionContext_ptr ctx);
    virtual void configuration_complete (void);
    virtual void ccm_activate (void);
    virtual void ccm_passivate (void);
    virtual void ccm_remove (void);
    //@}

    //@{
    /** User defined public operations. */
    void read_no_data ();
    void start_read ();
    bool check_last ();
    void run (void);

    ::CORBA::UShort iterations (void);

    void iterations (::CORBA::UShort iterations);

    ::CORBA::UShort keys (void);

    void keys (::CORBA::UShort keys);
    //@}

  private:
    ::Reader_Test::CCM_Receiver_Context_var ciao_context_;

    //@{
    /** Component attributes. */
    ::Reader_Test::ReaderTestConnector::CCM_Listener_var ciao_info_out_data_listener_;
    ::CCM_DDS::CCM_PortStatusListener_var ciao_info_out_status_;
    ::CCM_ReaderStarter_var ciao_reader_start_;
    //@}

    //@{
    /** User defined members. */
    CORBA::UShort iterations_;
    CORBA::UShort keys_;
    CORBA::Boolean has_run_;

    read_action_Generator *ticker_;

    typedef std::map<ACE_CString, DDS::InstanceHandle_t> Handle_Table;
    Handle_Table handles_;
    //@}

    //@{
    /** User defined private operations. */
    void read_all ();
    void read_last ();
    void read_one_all (bool test_handles = false);
    void read_one_last (bool test_handles = false);
    void test_exception ();
    void test_exception_with_handles ();

    //@}

    /// Get the ACE_Reactor
    ACE_Reactor* reactor (void);
  };

  extern "C" RECEIVER_EXEC_Export ::Components::EnterpriseComponent_ptr
  create_Reader_Test_Receiver_Impl (void);
}

#include /**/ "ace/post.h"

#endif /* ifndef */
