// $Id$

// ============================================================================
//
//
// = LIBRARY
//    TAO IDL
//
// = FILENAME
//    be_helper.cpp
//
// = DESCRIPTION
//   Provides helper classes to print generated code to the output
//
// = AUTHOR
//    Aniruddha Gokhale
//
//    Improvements by Carlos O'Ryan
//
// ============================================================================

#include        "idl.h"
#include        "idl_extern.h"
#include        "be.h"

ACE_RCSID(be, be_helper, "$Id$")

static const char copyright [] =
"/* -*- C++ -*- */\n\n"
"// ******  Code generated by the The ACE ORB (TAO) IDL Compiler *******\n"
"// TAO and the TAO IDL Compiler have been developed by the Center for\n"
"// Distributed Object Computing at Washington University, St. Louis.\n"
"//\n"
"// Information about TAO is available at:\n"
"//                 http://www.cs.wustl.edu/~schmidt/TAO.html\n";

TAO_NL::TAO_NL (void)
{
}

TAO_INDENT::TAO_INDENT (int do_now)
  :  do_now_ (do_now)
{
}

TAO_UNINDENT::TAO_UNINDENT (int do_now)
  :  do_now_ (do_now)
{
}

const TAO_NL be_nl;
const TAO_INDENT be_idt;
const TAO_INDENT be_idt_nl (1);
const TAO_UNINDENT be_uidt;
const TAO_UNINDENT be_uidt_nl (1);

// methods of the TAO_OutStream class

TAO_OutStream::TAO_OutStream (void)
  : fp_ (NULL),
    indent_level_ (0)
{
}

TAO_OutStream::~TAO_OutStream (void)
{
  // close the underlying I/O handle only if it exists
  if (fp_)
    {
      ACE_OS::fclose (fp_);
      fp_ = NULL;
    }
  indent_level_ = 0;
}

int
TAO_OutStream::open (const char *fname,
                     TAO_OutStream::STREAM_TYPE st)
{
  if (fname)
    {
      // file name exists, open an I/O file handle
      fp_ = ACE_OS::fopen (fname, "w");
      if (fp_)
        {
          this->st_ = st;
          // put the copyright notice.  Not for the gperf's temp input
          // file.
          if (st != TAO_OutStream::TAO_GPERF_INPUT)
            {
              ACE_OS::fprintf (fp_, "%s\n", copyright);
              ACE_OS::fflush (fp_);
            }
          return 0;
        }
      else
        return -1;
    }
  else
    {
      return -1;
    }
}

// set and get the stream type
void
TAO_OutStream::stream_type (TAO_OutStream::STREAM_TYPE st)
{
  this->st_ = st;
}

TAO_OutStream::STREAM_TYPE
TAO_OutStream::stream_type (void)
{
  return this->st_;
}

// Return the underlying lowlevel file pointer.
// indentation.
FILE *
TAO_OutStream::file (void)
{
  return this->fp_;
}

int
TAO_OutStream::incr_indent (unsigned short flag)
{
  indent_level_++;
  if (flag)
    return this->indent ();
  else
    return 0; // do not indent output
}

// indentation
int
TAO_OutStream::decr_indent (unsigned short flag)
{
  indent_level_--;
  // Just in case somebody gets "unindent happy".
  if (this->indent_level_ < 0)
    {
      // ACE_DEBUG ((LM_DEBUG, "negative indentation?\n"));
      this->indent_level_ = 0;
    }
  if (flag)
    return this->indent ();
  else
    return 0; // do not indent output
}

int
TAO_OutStream::reset (void)
{
  indent_level_ = 0;
  return 0;
}

// indented print
int
TAO_OutStream::indent (void)
{
  int i;
  // based on the current indentation level, leave appropriate number of blank
  // spaces in the output
  if (this->indent_level_ > 0)
    {
      for (i = 0; i < this->indent_level_; i++)
        {
          ACE_OS::fprintf (this->fp_, "  ");
          ACE_OS::fflush (this->fp_);
        }
    }
  return 0;
}

int
TAO_OutStream::nl (void)
{
  ACE_OS::fprintf (this->fp_, "\n");
  this->indent ();
  return 0;
}

// macro generation
int
TAO_OutStream::gen_ifdef_macro (const char *flatname, const char *suffix)
{
  static char macro [NAMEBUFSIZE];
  TAO_CodeGen *cg = TAO_CODEGEN::instance ();

  ACE_OS::memset (macro, '\0', NAMEBUFSIZE);
  ACE_OS::sprintf (macro, "_%s_", cg->upcase (flatname));
  if (suffix)
    {
      //ACE_OS::sprintf (macro, "%s_%s_", macro, cg->upcase (suffix));
      // Can't have macro on both sides of sprintf
      // I'm not sure if the first strcat of "_" should be here or
      // not, but having it gives the same functionality as the old
      // sprintf call...
      ACE_OS::strcat (macro, "_");
      ACE_OS::strcat (macro, cg->upcase (suffix));
      ACE_OS::strcat (macro, "_");
    }

  // append a suffix representing the stream type
  switch (this->st_)
    {
    case TAO_OutStream::TAO_CLI_HDR:
      ACE_OS::strcat (macro, "CH_");
      break;
    case TAO_OutStream::TAO_CLI_INL:
      ACE_OS::strcat (macro, "CI_");
      break;
    case TAO_OutStream::TAO_CLI_IMPL:
      ACE_OS::strcat (macro, "CS_");
      break;
    case TAO_OutStream::TAO_SVR_HDR:
      ACE_OS::strcat (macro, "SH_");
      break;
    case TAO_OutStream::TAO_IMPL_HDR:
      ACE_OS::strcat (macro, "IH_");
      break;
    case TAO_OutStream::TAO_IMPL_SKEL:
      ACE_OS::strcat (macro, "IS_");
      break;
    case TAO_OutStream::TAO_SVR_INL:
      ACE_OS::strcat (macro, "SI_");
      break;
    case TAO_OutStream::TAO_SVR_IMPL:
      ACE_OS::strcat (macro, "SS_");
      break;
    default:
      return -1;
    }
  *this << "\n#if !defined (" << macro << ")\n";
  *this << "#define " << macro << "\n\n";
  return 0;
}

int
TAO_OutStream::gen_endif (void)
{
  *this << "\n#endif /* end #if !defined */\n\n";
  return 0;
}


// ifdef generation
int
TAO_OutStream::gen_ifdef_AHETI (void)
{
  *this << "\n"
        << "#if !defined (TAO_USE_SEQUENCE_TEMPLATES)"
        << be_idt_nl;
  return 0;
}

int
TAO_OutStream::gen_else_AHETI (void)
{
  *this << "\n#else /* TAO_USE_SEQUENCE_TEMPLATES */"
        << be_nl;
  return 0;
}

int
TAO_OutStream::gen_endif_AHETI (void)
{
  *this << be_uidt
        << "\n#endif /* !TAO_USE_SEQUENCE_TEMPLATES */ "
        << be_nl;
  return 0;
}


// printf style variable argument print
int
TAO_OutStream::print (const char *format, ...)
{
  int result = 0;
  va_list ap;
  va_start (ap, format);
  ACE_OSCALL (::vfprintf (this->fp_, format, ap), int, -1, result);
  ACE_OS::fflush (fp_);
  va_end (ap);
  return result;
}

TAO_OutStream &
TAO_OutStream::operator<< (const char *str)
{
  ACE_OS::fprintf (this->fp_, "%s", str);
  ACE_OS::fflush (fp_);
  return *this;
}

TAO_OutStream &
TAO_OutStream::operator<< (const ACE_CDR::UShort num)
{
  ACE_OS::fprintf (this->fp_, "%hu", num);
  ACE_OS::fflush (fp_);
  return *this;
}

TAO_OutStream &
TAO_OutStream::operator<< (const ACE_CDR::Short num)
{
  ACE_OS::fprintf (this->fp_, "%hd", num);
  ACE_OS::fflush (fp_);
  return *this;
}

TAO_OutStream &
TAO_OutStream::operator<< (const ACE_CDR::ULong num)
{
  ACE_OS::fprintf (this->fp_, "%lu", num);
  ACE_OS::fflush (fp_);
  return *this;
}

TAO_OutStream &
TAO_OutStream::operator<< (const ACE_CDR::Long num)
{
  ACE_OS::fprintf (this->fp_, "%ld", num);
  ACE_OS::fflush (fp_);
  return *this;
}

TAO_OutStream &
TAO_OutStream::operator<< (const unsigned long num)
{
  ACE_OS::fprintf (this->fp_, "%lu", num);
  ACE_OS::fflush (fp_);
  return *this;
}

TAO_OutStream &
TAO_OutStream::operator<< (const long num)
{
  ACE_OS::fprintf (this->fp_, "%ld", num);
  ACE_OS::fflush (fp_);
  return *this;
}

TAO_OutStream &
TAO_OutStream::operator<< (const TAO_NL&)
{
  ACE_OS::fprintf (this->fp_ , "\n");
  this->indent ();
  return *this;
}

TAO_OutStream &
TAO_OutStream::operator<< (const TAO_INDENT& i)
{
  this->incr_indent (0);
  if (i.do_now_)
    this->nl ();
  return *this;
}

TAO_OutStream &
TAO_OutStream::operator<< (const TAO_UNINDENT& i)
{
  this->decr_indent (0);
  if (i.do_now_)
    this->nl ();
  return *this;
}

TAO_OutStream &
TAO_OutStream::operator<< (Identifier *id)
{
  return this->print (id);
}

TAO_OutStream &
TAO_OutStream::operator<< (UTL_IdList *id)
{
  return this->print (id);
}

TAO_OutStream &
TAO_OutStream::operator<< (AST_Expression *expr)
{
  return this->print (expr);
}
