

#define SWIG_VERSION 0x040100
#define SWIGPYTHON
#define SWIG_PYTHON_DIRECTOR_NO_VTABLE

/* -----------------------------------------------------------------------------
 *  This section contains generic SWIG labels for method/variable
 *  declarations/attributes, and other compiler dependent labels.
 * ----------------------------------------------------------------------------- */

/* template workaround for compilers that cannot correctly implement the C++ standard */
#ifndef SWIGTEMPLATEDISAMBIGUATOR
# if defined(__SUNPRO_CC) && (__SUNPRO_CC <= 0x560)
#  define SWIGTEMPLATEDISAMBIGUATOR template
# elif defined(__HP_aCC)
/* Needed even with `aCC -AA' when `aCC -V' reports HP ANSI C++ B3910B A.03.55 */
/* If we find a maximum version that requires this, the test would be __HP_aCC <= 35500 for A.03.55 */
#  define SWIGTEMPLATEDISAMBIGUATOR template
# else
#  define SWIGTEMPLATEDISAMBIGUATOR
# endif
#endif

/* inline attribute */
#ifndef SWIGINLINE
# if defined(__cplusplus) || (defined(__GNUC__) && !defined(__STRICT_ANSI__))
#   define SWIGINLINE inline
# else
#   define SWIGINLINE
# endif
#endif

/* attribute recognised by some compilers to avoid 'unused' warnings */
#ifndef SWIGUNUSED
# if defined(__GNUC__)
#   if !(defined(__cplusplus)) || (__GNUC__ > 3 || (__GNUC__ == 3 && __GNUC_MINOR__ >= 4))
#     define SWIGUNUSED __attribute__ ((__unused__))
#   else
#     define SWIGUNUSED
#   endif
# elif defined(__ICC)
#   define SWIGUNUSED __attribute__ ((__unused__))
# else
#   define SWIGUNUSED
# endif
#endif

#ifndef SWIG_MSC_UNSUPPRESS_4505
# if defined(_MSC_VER)
#   pragma warning(disable : 4505) /* unreferenced local function has been removed */
# endif
#endif

#ifndef SWIGUNUSEDPARM
# ifdef __cplusplus
#   define SWIGUNUSEDPARM(p)
# else
#   define SWIGUNUSEDPARM(p) p SWIGUNUSED
# endif
#endif

/* internal SWIG method */
#ifndef SWIGINTERN
# define SWIGINTERN static SWIGUNUSED
#endif

/* internal inline SWIG method */
#ifndef SWIGINTERNINLINE
# define SWIGINTERNINLINE SWIGINTERN SWIGINLINE
#endif

/* exporting methods */
#if defined(__GNUC__)
#  if (__GNUC__ >= 4) || (__GNUC__ == 3 && __GNUC_MINOR__ >= 4)
#    ifndef GCC_HASCLASSVISIBILITY
#      define GCC_HASCLASSVISIBILITY
#    endif
#  endif
#endif

#ifndef SWIGEXPORT
# if defined(_WIN32) || defined(__WIN32__) || defined(__CYGWIN__)
#   if defined(STATIC_LINKED)
#     define SWIGEXPORT
#   else
#     define SWIGEXPORT __declspec(dllexport)
#   endif
# else
#   if defined(__GNUC__) && defined(GCC_HASCLASSVISIBILITY)
#     define SWIGEXPORT __attribute__ ((visibility("default")))
#   else
#     define SWIGEXPORT
#   endif
# endif
#endif

/* calling conventions for Windows */
#ifndef SWIGSTDCALL
# if defined(_WIN32) || defined(__WIN32__) || defined(__CYGWIN__)
#   define SWIGSTDCALL __stdcall
# else
#   define SWIGSTDCALL
# endif
#endif

/* Deal with Microsoft's attempt at deprecating C standard runtime functions */
#if !defined(SWIG_NO_CRT_SECURE_NO_DEPRECATE) && defined(_MSC_VER) && !defined(_CRT_SECURE_NO_DEPRECATE)
# define _CRT_SECURE_NO_DEPRECATE
#endif

/* Deal with Microsoft's attempt at deprecating methods in the standard C++ library */
#if !defined(SWIG_NO_SCL_SECURE_NO_DEPRECATE) && defined(_MSC_VER) && !defined(_SCL_SECURE_NO_DEPRECATE)
# define _SCL_SECURE_NO_DEPRECATE
#endif

/* Deal with Apple's deprecated 'AssertMacros.h' from Carbon-framework */
#if defined(__APPLE__) && !defined(__ASSERT_MACROS_DEFINE_VERSIONS_WITHOUT_UNDERSCORES)
# define __ASSERT_MACROS_DEFINE_VERSIONS_WITHOUT_UNDERSCORES 0
#endif

/* Intel's compiler complains if a variable which was never initialised is
 * cast to void, which is a common idiom which we use to indicate that we
 * are aware a variable isn't used.  So we just silence that warning.
 * See: https://github.com/swig/swig/issues/192 for more discussion.
 */
#ifdef __INTEL_COMPILER
# pragma warning disable 592
#endif


#if defined(__GNUC__) && defined(_WIN32) && !defined(SWIG_PYTHON_NO_HYPOT_WORKAROUND)
/* Workaround for '::hypot' has not been declared', see https://bugs.python.org/issue11566 */
# include <math.h>
#endif

#if !defined(PY_SSIZE_T_CLEAN) && !defined(SWIG_NO_PY_SSIZE_T_CLEAN)
#define PY_SSIZE_T_CLEAN
#endif

#if __GNUC__ >= 7
#pragma GCC diagnostic push
#if defined(__cplusplus) && __cplusplus >=201703L
#pragma GCC diagnostic ignored "-Wregister" /* For python-2.7 headers that use register */
#endif
#endif

#if defined(_DEBUG) && defined(SWIG_PYTHON_INTERPRETER_NO_DEBUG)
/* Use debug wrappers with the Python release dll */

#if defined(_MSC_VER) && _MSC_VER >= 1929
/* Workaround compilation errors when redefining _DEBUG in MSVC 2019 version 16.10 and later
 * See https://github.com/swig/swig/issues/2090 */
# include <corecrt.h>
#endif

# undef _DEBUG
# include <Python.h>
# define _DEBUG 1
#else
# include <Python.h>
#endif

#if __GNUC__ >= 7
#pragma GCC diagnostic pop
#endif

/* -----------------------------------------------------------------------------
 * swigrun.swg
 *
 * This file contains generic C API SWIG runtime support for pointer
 * type checking.
 * ----------------------------------------------------------------------------- */

/* This should only be incremented when either the layout of swig_type_info changes,
   or for whatever reason, the runtime changes incompatibly */
#define SWIG_RUNTIME_VERSION "4"

/* define SWIG_TYPE_TABLE_NAME as "SWIG_TYPE_TABLE" */
#ifdef SWIG_TYPE_TABLE
# define SWIG_QUOTE_STRING(x) #x
# define SWIG_EXPAND_AND_QUOTE_STRING(x) SWIG_QUOTE_STRING(x)
# define SWIG_TYPE_TABLE_NAME SWIG_EXPAND_AND_QUOTE_STRING(SWIG_TYPE_TABLE)
#else
# define SWIG_TYPE_TABLE_NAME
#endif

/*
  You can use the SWIGRUNTIME and SWIGRUNTIMEINLINE macros for
  creating a static or dynamic library from the SWIG runtime code.
  In 99.9% of the cases, SWIG just needs to declare them as 'static'.

  But only do this if strictly necessary, ie, if you have problems
  with your compiler or suchlike.
*/

#ifndef SWIGRUNTIME
# define SWIGRUNTIME SWIGINTERN
#endif

#ifndef SWIGRUNTIMEINLINE
# define SWIGRUNTIMEINLINE SWIGRUNTIME SWIGINLINE
#endif

/*  Generic buffer size */
#ifndef SWIG_BUFFER_SIZE
# define SWIG_BUFFER_SIZE 1024
#endif

/* Flags for pointer conversions */
#define SWIG_POINTER_DISOWN        0x1
#define SWIG_CAST_NEW_MEMORY       0x2
#define SWIG_POINTER_NO_NULL       0x4
#define SWIG_POINTER_CLEAR         0x8
#define SWIG_POINTER_RELEASE       (SWIG_POINTER_CLEAR | SWIG_POINTER_DISOWN)

/* Flags for new pointer objects */
#define SWIG_POINTER_OWN           0x1


/*
   Flags/methods for returning states.

   The SWIG conversion methods, as ConvertPtr, return an integer
   that tells if the conversion was successful or not. And if not,
   an error code can be returned (see swigerrors.swg for the codes).

   Use the following macros/flags to set or process the returning
   states.

   In old versions of SWIG, code such as the following was usually written:

     if (SWIG_ConvertPtr(obj,vptr,ty.flags) != -1) {
       // success code
     } else {
       //fail code
     }

   Now you can be more explicit:

    int res = SWIG_ConvertPtr(obj,vptr,ty.flags);
    if (SWIG_IsOK(res)) {
      // success code
    } else {
      // fail code
    }

   which is the same really, but now you can also do

    Type *ptr;
    int res = SWIG_ConvertPtr(obj,(void **)(&ptr),ty.flags);
    if (SWIG_IsOK(res)) {
      // success code
      if (SWIG_IsNewObj(res) {
        ...
	delete *ptr;
      } else {
        ...
      }
    } else {
      // fail code
    }

   I.e., now SWIG_ConvertPtr can return new objects and you can
   identify the case and take care of the deallocation. Of course that
   also requires SWIG_ConvertPtr to return new result values, such as

      int SWIG_ConvertPtr(obj, ptr,...) {
        if (<obj is ok>) {
          if (<need new object>) {
            *ptr = <ptr to new allocated object>;
            return SWIG_NEWOBJ;
          } else {
            *ptr = <ptr to old object>;
            return SWIG_OLDOBJ;
          }
        } else {
          return SWIG_BADOBJ;
        }
      }

   Of course, returning the plain '0(success)/-1(fail)' still works, but you can be
   more explicit by returning SWIG_BADOBJ, SWIG_ERROR or any of the
   SWIG errors code.

   Finally, if the SWIG_CASTRANK_MODE is enabled, the result code
   allows returning the 'cast rank', for example, if you have this

       int food(double)
       int fooi(int);

   and you call

      food(1)   // cast rank '1'  (1 -> 1.0)
      fooi(1)   // cast rank '0'

   just use the SWIG_AddCast()/SWIG_CheckState()
*/

#define SWIG_OK                    (0)
/* Runtime errors are < 0 */
#define SWIG_ERROR                 (-1)
/* Errors in range -1 to -99 are in swigerrors.swg (errors for all languages including those not using the runtime) */
/* Errors in range -100 to -199 are language specific errors defined in *errors.swg */
/* Errors < -200 are generic runtime specific errors */
#define SWIG_ERROR_RELEASE_NOT_OWNED (-200)

#define SWIG_IsOK(r)               (r >= 0)
#define SWIG_ArgError(r)           ((r != SWIG_ERROR) ? r : SWIG_TypeError)

/* The CastRankLimit says how many bits are used for the cast rank */
#define SWIG_CASTRANKLIMIT         (1 << 8)
/* The NewMask denotes the object was created (using new/malloc) */
#define SWIG_NEWOBJMASK            (SWIG_CASTRANKLIMIT  << 1)
/* The TmpMask is for in/out typemaps that use temporal objects */
#define SWIG_TMPOBJMASK            (SWIG_NEWOBJMASK << 1)
/* Simple returning values */
#define SWIG_BADOBJ                (SWIG_ERROR)
#define SWIG_OLDOBJ                (SWIG_OK)
#define SWIG_NEWOBJ                (SWIG_OK | SWIG_NEWOBJMASK)
#define SWIG_TMPOBJ                (SWIG_OK | SWIG_TMPOBJMASK)
/* Check, add and del object mask methods */
#define SWIG_AddNewMask(r)         (SWIG_IsOK(r) ? (r | SWIG_NEWOBJMASK) : r)
#define SWIG_DelNewMask(r)         (SWIG_IsOK(r) ? (r & ~SWIG_NEWOBJMASK) : r)
#define SWIG_IsNewObj(r)           (SWIG_IsOK(r) && (r & SWIG_NEWOBJMASK))
#define SWIG_AddTmpMask(r)         (SWIG_IsOK(r) ? (r | SWIG_TMPOBJMASK) : r)
#define SWIG_DelTmpMask(r)         (SWIG_IsOK(r) ? (r & ~SWIG_TMPOBJMASK) : r)
#define SWIG_IsTmpObj(r)           (SWIG_IsOK(r) && (r & SWIG_TMPOBJMASK))

/* Cast-Rank Mode */
#if defined(SWIG_CASTRANK_MODE)
#  ifndef SWIG_TypeRank
#    define SWIG_TypeRank             unsigned long
#  endif
#  ifndef SWIG_MAXCASTRANK            /* Default cast allowed */
#    define SWIG_MAXCASTRANK          (2)
#  endif
#  define SWIG_CASTRANKMASK          ((SWIG_CASTRANKLIMIT) -1)
#  define SWIG_CastRank(r)           (r & SWIG_CASTRANKMASK)
SWIGINTERNINLINE int SWIG_AddCast(int r) {
  return SWIG_IsOK(r) ? ((SWIG_CastRank(r) < SWIG_MAXCASTRANK) ? (r + 1) : SWIG_ERROR) : r;
}
SWIGINTERNINLINE int SWIG_CheckState(int r) {
  return SWIG_IsOK(r) ? SWIG_CastRank(r) + 1 : 0;
}
#else /* no cast-rank mode */
#  define SWIG_AddCast(r) (r)
#  define SWIG_CheckState(r) (SWIG_IsOK(r) ? 1 : 0)
#endif


#include <string.h>

#ifdef __cplusplus
extern "C" {
#endif

typedef void *(*swig_converter_func)(void *, int *);
typedef struct swig_type_info *(*swig_dycast_func)(void **);

/* Structure to store information on one type */
typedef struct swig_type_info {
  const char             *name;			/* mangled name of this type */
  const char             *str;			/* human readable name of this type */
  swig_dycast_func        dcast;		/* dynamic cast function down a hierarchy */
  struct swig_cast_info  *cast;			/* linked list of types that can cast into this type */
  void                   *clientdata;		/* language specific type data */
  int                    owndata;		/* flag if the structure owns the clientdata */
} swig_type_info;

/* Structure to store a type and conversion function used for casting */
typedef struct swig_cast_info {
  swig_type_info         *type;			/* pointer to type that is equivalent to this type */
  swig_converter_func     converter;		/* function to cast the void pointers */
  struct swig_cast_info  *next;			/* pointer to next cast in linked list */
  struct swig_cast_info  *prev;			/* pointer to the previous cast */
} swig_cast_info;

/* Structure used to store module information
 * Each module generates one structure like this, and the runtime collects
 * all of these structures and stores them in a circularly linked list.*/
typedef struct swig_module_info {
  swig_type_info         **types;		/* Array of pointers to swig_type_info structures that are in this module */
  size_t                 size;		        /* Number of types in this module */
  struct swig_module_info *next;		/* Pointer to next element in circularly linked list */
  swig_type_info         **type_initial;	/* Array of initially generated type structures */
  swig_cast_info         **cast_initial;	/* Array of initially generated casting structures */
  void                    *clientdata;		/* Language specific module data */
} swig_module_info;

/*
  Compare two type names skipping the space characters, therefore
  "char*" == "char *" and "Class<int>" == "Class<int >", etc.

  Return 0 when the two name types are equivalent, as in
  strncmp, but skipping ' '.
*/
SWIGRUNTIME int
SWIG_TypeNameComp(const char *f1, const char *l1,
		  const char *f2, const char *l2) {
  for (;(f1 != l1) && (f2 != l2); ++f1, ++f2) {
    while ((*f1 == ' ') && (f1 != l1)) ++f1;
    while ((*f2 == ' ') && (f2 != l2)) ++f2;
    if (*f1 != *f2) return (*f1 > *f2) ? 1 : -1;
  }
  return (int)((l1 - f1) - (l2 - f2));
}

/*
  Check type equivalence in a name list like <name1>|<name2>|...
  Return 0 if equal, -1 if nb < tb, 1 if nb > tb
*/
SWIGRUNTIME int
SWIG_TypeCmp(const char *nb, const char *tb) {
  int equiv = 1;
  const char* te = tb + strlen(tb);
  const char* ne = nb;
  while (equiv != 0 && *ne) {
    for (nb = ne; *ne; ++ne) {
      if (*ne == '|') break;
    }
    equiv = SWIG_TypeNameComp(nb, ne, tb, te);
    if (*ne) ++ne;
  }
  return equiv;
}

/*
  Check type equivalence in a name list like <name1>|<name2>|...
  Return 0 if not equal, 1 if equal
*/
SWIGRUNTIME int
SWIG_TypeEquiv(const char *nb, const char *tb) {
  return SWIG_TypeCmp(nb, tb) == 0 ? 1 : 0;
}

/*
  Check the typename
*/
SWIGRUNTIME swig_cast_info *
SWIG_TypeCheck(const char *c, swig_type_info *ty) {
  if (ty) {
    swig_cast_info *iter = ty->cast;
    while (iter) {
      if (strcmp(iter->type->name, c) == 0) {
        if (iter == ty->cast)
          return iter;
        /* Move iter to the top of the linked list */
        iter->prev->next = iter->next;
        if (iter->next)
          iter->next->prev = iter->prev;
        iter->next = ty->cast;
        iter->prev = 0;
        if (ty->cast) ty->cast->prev = iter;
        ty->cast = iter;
        return iter;
      }
      iter = iter->next;
    }
  }
  return 0;
}

/*
  Identical to SWIG_TypeCheck, except strcmp is replaced with a pointer comparison
*/
SWIGRUNTIME swig_cast_info *
SWIG_TypeCheckStruct(const swig_type_info *from, swig_type_info *ty) {
  if (ty) {
    swig_cast_info *iter = ty->cast;
    while (iter) {
      if (iter->type == from) {
        if (iter == ty->cast)
          return iter;
        /* Move iter to the top of the linked list */
        iter->prev->next = iter->next;
        if (iter->next)
          iter->next->prev = iter->prev;
        iter->next = ty->cast;
        iter->prev = 0;
        if (ty->cast) ty->cast->prev = iter;
        ty->cast = iter;
        return iter;
      }
      iter = iter->next;
    }
  }
  return 0;
}

/*
  Cast a pointer up an inheritance hierarchy
*/
SWIGRUNTIMEINLINE void *
SWIG_TypeCast(swig_cast_info *ty, void *ptr, int *newmemory) {
  return ((!ty) || (!ty->converter)) ? ptr : (*ty->converter)(ptr, newmemory);
}

/*
   Dynamic pointer casting. Down an inheritance hierarchy
*/
SWIGRUNTIME swig_type_info *
SWIG_TypeDynamicCast(swig_type_info *ty, void **ptr) {
  swig_type_info *lastty = ty;
  if (!ty || !ty->dcast) return ty;
  while (ty && (ty->dcast)) {
    ty = (*ty->dcast)(ptr);
    if (ty) lastty = ty;
  }
  return lastty;
}

/*
  Return the name associated with this type
*/
SWIGRUNTIMEINLINE const char *
SWIG_TypeName(const swig_type_info *ty) {
  return ty->name;
}

/*
  Return the pretty name associated with this type,
  that is an unmangled type name in a form presentable to the user.
*/
SWIGRUNTIME const char *
SWIG_TypePrettyName(const swig_type_info *type) {
  /* The "str" field contains the equivalent pretty names of the
     type, separated by vertical-bar characters.  Choose the last
     name. It should be the most specific; a fully resolved name
     but not necessarily with default template parameters expanded. */
  if (!type) return NULL;
  if (type->str != NULL) {
    const char *last_name = type->str;
    const char *s;
    for (s = type->str; *s; s++)
      if (*s == '|') last_name = s+1;
    return last_name;
  }
  else
    return type->name;
}

/*
   Set the clientdata field for a type
*/
SWIGRUNTIME void
SWIG_TypeClientData(swig_type_info *ti, void *clientdata) {
  swig_cast_info *cast = ti->cast;
  /* if (ti->clientdata == clientdata) return; */
  ti->clientdata = clientdata;

  while (cast) {
    if (!cast->converter) {
      swig_type_info *tc = cast->type;
      if (!tc->clientdata) {
	SWIG_TypeClientData(tc, clientdata);
      }
    }
    cast = cast->next;
  }
}
SWIGRUNTIME void
SWIG_TypeNewClientData(swig_type_info *ti, void *clientdata) {
  SWIG_TypeClientData(ti, clientdata);
  ti->owndata = 1;
}

/*
  Search for a swig_type_info structure only by mangled name
  Search is a O(log #types)

  We start searching at module start, and finish searching when start == end.
  Note: if start == end at the beginning of the function, we go all the way around
  the circular list.
*/
SWIGRUNTIME swig_type_info *
SWIG_MangledTypeQueryModule(swig_module_info *start,
                            swig_module_info *end,
		            const char *name) {
  swig_module_info *iter = start;
  do {
    if (iter->size) {
      size_t l = 0;
      size_t r = iter->size - 1;
      do {
	/* since l+r >= 0, we can (>> 1) instead (/ 2) */
	size_t i = (l + r) >> 1;
	const char *iname = iter->types[i]->name;
	if (iname) {
	  int compare = strcmp(name, iname);
	  if (compare == 0) {
	    return iter->types[i];
	  } else if (compare < 0) {
	    if (i) {
	      r = i - 1;
	    } else {
	      break;
	    }
	  } else if (compare > 0) {
	    l = i + 1;
	  }
	} else {
	  break; /* should never happen */
	}
      } while (l <= r);
    }
    iter = iter->next;
  } while (iter != end);
  return 0;
}

/*
  Search for a swig_type_info structure for either a mangled name or a human readable name.
  It first searches the mangled names of the types, which is a O(log #types)
  If a type is not found it then searches the human readable names, which is O(#types).

  We start searching at module start, and finish searching when start == end.
  Note: if start == end at the beginning of the function, we go all the way around
  the circular list.
*/
SWIGRUNTIME swig_type_info *
SWIG_TypeQueryModule(swig_module_info *start,
                     swig_module_info *end,
		     const char *name) {
  /* STEP 1: Search the name field using binary search */
  swig_type_info *ret = SWIG_MangledTypeQueryModule(start, end, name);
  if (ret) {
    return ret;
  } else {
    /* STEP 2: If the type hasn't been found, do a complete search
       of the str field (the human readable name) */
    swig_module_info *iter = start;
    do {
      size_t i = 0;
      for (; i < iter->size; ++i) {
	if (iter->types[i]->str && (SWIG_TypeEquiv(iter->types[i]->str, name)))
	  return iter->types[i];
      }
      iter = iter->next;
    } while (iter != end);
  }

  /* neither found a match */
  return 0;
}

/*
   Pack binary data into a string
*/
SWIGRUNTIME char *
SWIG_PackData(char *c, void *ptr, size_t sz) {
  static const char hex[17] = "0123456789abcdef";
  const unsigned char *u = (unsigned char *) ptr;
  const unsigned char *eu =  u + sz;
  for (; u != eu; ++u) {
    unsigned char uu = *u;
    *(c++) = hex[(uu & 0xf0) >> 4];
    *(c++) = hex[uu & 0xf];
  }
  return c;
}

/*
   Unpack binary data from a string
*/
SWIGRUNTIME const char *
SWIG_UnpackData(const char *c, void *ptr, size_t sz) {
  unsigned char *u = (unsigned char *) ptr;
  const unsigned char *eu = u + sz;
  for (; u != eu; ++u) {
    char d = *(c++);
    unsigned char uu;
    if ((d >= '0') && (d <= '9'))
      uu = (unsigned char)((d - '0') << 4);
    else if ((d >= 'a') && (d <= 'f'))
      uu = (unsigned char)((d - ('a'-10)) << 4);
    else
      return (char *) 0;
    d = *(c++);
    if ((d >= '0') && (d <= '9'))
      uu |= (unsigned char)(d - '0');
    else if ((d >= 'a') && (d <= 'f'))
      uu |= (unsigned char)(d - ('a'-10));
    else
      return (char *) 0;
    *u = uu;
  }
  return c;
}

/*
   Pack 'void *' into a string buffer.
*/
SWIGRUNTIME char *
SWIG_PackVoidPtr(char *buff, void *ptr, const char *name, size_t bsz) {
  char *r = buff;
  if ((2*sizeof(void *) + 2) > bsz) return 0;
  *(r++) = '_';
  r = SWIG_PackData(r,&ptr,sizeof(void *));
  if (strlen(name) + 1 > (bsz - (r - buff))) return 0;
  strcpy(r,name);
  return buff;
}

SWIGRUNTIME const char *
SWIG_UnpackVoidPtr(const char *c, void **ptr, const char *name) {
  if (*c != '_') {
    if (strcmp(c,"NULL") == 0) {
      *ptr = (void *) 0;
      return name;
    } else {
      return 0;
    }
  }
  return SWIG_UnpackData(++c,ptr,sizeof(void *));
}

SWIGRUNTIME char *
SWIG_PackDataName(char *buff, void *ptr, size_t sz, const char *name, size_t bsz) {
  char *r = buff;
  size_t lname = (name ? strlen(name) : 0);
  if ((2*sz + 2 + lname) > bsz) return 0;
  *(r++) = '_';
  r = SWIG_PackData(r,ptr,sz);
  if (lname) {
    strncpy(r,name,lname+1);
  } else {
    *r = 0;
  }
  return buff;
}

SWIGRUNTIME const char *
SWIG_UnpackDataName(const char *c, void *ptr, size_t sz, const char *name) {
  if (*c != '_') {
    if (strcmp(c,"NULL") == 0) {
      memset(ptr,0,sz);
      return name;
    } else {
      return 0;
    }
  }
  return SWIG_UnpackData(++c,ptr,sz);
}

#ifdef __cplusplus
}
#endif

/* SWIG Errors applicable to all language modules, values are reserved from -1 to -99 */
#define  SWIG_UnknownError    	   -1
#define  SWIG_IOError        	   -2
#define  SWIG_RuntimeError   	   -3
#define  SWIG_IndexError     	   -4
#define  SWIG_TypeError      	   -5
#define  SWIG_DivisionByZero 	   -6
#define  SWIG_OverflowError  	   -7
#define  SWIG_SyntaxError    	   -8
#define  SWIG_ValueError     	   -9
#define  SWIG_SystemError    	   -10
#define  SWIG_AttributeError 	   -11
#define  SWIG_MemoryError    	   -12
#define  SWIG_NullReferenceError   -13


/* Compatibility macros for Python 3 */
#if PY_VERSION_HEX >= 0x03000000

#define PyClass_Check(obj) PyObject_IsInstance(obj, (PyObject *)&PyType_Type)
#define PyInt_Check(x) PyLong_Check(x)
#define PyInt_AsLong(x) PyLong_AsLong(x)
#define PyInt_FromLong(x) PyLong_FromLong(x)
#define PyInt_FromSize_t(x) PyLong_FromSize_t(x)
#define PyString_Check(name) PyBytes_Check(name)
#define PyString_FromString(x) PyUnicode_FromString(x)
#define PyString_Format(fmt, args)  PyUnicode_Format(fmt, args)
#define PyString_AsString(str) PyBytes_AsString(str)
#define PyString_Size(str) PyBytes_Size(str)	
#define PyString_InternFromString(key) PyUnicode_InternFromString(key)
#define Py_TPFLAGS_HAVE_CLASS Py_TPFLAGS_BASETYPE
#define _PyLong_FromSsize_t(x) PyLong_FromSsize_t(x)

#endif

#ifndef Py_TYPE
#  define Py_TYPE(op) ((op)->ob_type)
#endif

/* SWIG APIs for compatibility of both Python 2 & 3 */

#if PY_VERSION_HEX >= 0x03000000
#  define SWIG_Python_str_FromFormat PyUnicode_FromFormat
#else
#  define SWIG_Python_str_FromFormat PyString_FromFormat
#endif


SWIGINTERN char*
SWIG_Python_str_AsChar(PyObject *str)
{
#if PY_VERSION_HEX >= 0x03030000
  return (char *)PyUnicode_AsUTF8(str);
#else
  return PyString_AsString(str);
#endif
}

/* Was useful for Python 3.0.x-3.2.x - now provided only for compatibility
 * with any uses in user interface files. */
#define SWIG_Python_str_DelForPy3(x)


SWIGINTERN PyObject*
SWIG_Python_str_FromChar(const char *c)
{
#if PY_VERSION_HEX >= 0x03000000
  return PyUnicode_FromString(c); 
#else
  return PyString_FromString(c);
#endif
}

#ifndef PyObject_DEL
# define PyObject_DEL PyObject_Del
#endif

/* SWIGPY_USE_CAPSULE is no longer used within SWIG itself, but some user interface files check for it. */
# define SWIGPY_USE_CAPSULE
#ifdef SWIGPYTHON_BUILTIN
# define SWIGPY_CAPSULE_ATTR_NAME "type_pointer_capsule_builtin" SWIG_TYPE_TABLE_NAME
#else
# define SWIGPY_CAPSULE_ATTR_NAME "type_pointer_capsule" SWIG_TYPE_TABLE_NAME
#endif
# define SWIGPY_CAPSULE_NAME ("swig_runtime_data" SWIG_RUNTIME_VERSION "." SWIGPY_CAPSULE_ATTR_NAME)

#if PY_VERSION_HEX < 0x03020000
#define PyDescr_TYPE(x) (((PyDescrObject *)(x))->d_type)
#define PyDescr_NAME(x) (((PyDescrObject *)(x))->d_name)
#define Py_hash_t long
#endif

/* -----------------------------------------------------------------------------
 * error manipulation
 * ----------------------------------------------------------------------------- */

SWIGRUNTIME PyObject*
SWIG_Python_ErrorType(int code) {
  PyObject* type = 0;
  switch(code) {
  case SWIG_MemoryError:
    type = PyExc_MemoryError;
    break;
  case SWIG_IOError:
    type = PyExc_IOError;
    break;
  case SWIG_RuntimeError:
    type = PyExc_RuntimeError;
    break;
  case SWIG_IndexError:
    type = PyExc_IndexError;
    break;
  case SWIG_TypeError:
    type = PyExc_TypeError;
    break;
  case SWIG_DivisionByZero:
    type = PyExc_ZeroDivisionError;
    break;
  case SWIG_OverflowError:
    type = PyExc_OverflowError;
    break;
  case SWIG_SyntaxError:
    type = PyExc_SyntaxError;
    break;
  case SWIG_ValueError:
    type = PyExc_ValueError;
    break;
  case SWIG_SystemError:
    type = PyExc_SystemError;
    break;
  case SWIG_AttributeError:
    type = PyExc_AttributeError;
    break;
  default:
    type = PyExc_RuntimeError;
  }
  return type;
}


SWIGRUNTIME void
SWIG_Python_AddErrorMsg(const char* mesg)
{
  PyObject *type = 0;
  PyObject *value = 0;
  PyObject *traceback = 0;

  if (PyErr_Occurred())
    PyErr_Fetch(&type, &value, &traceback);
  if (value) {
    PyObject *old_str = PyObject_Str(value);
    const char *tmp = SWIG_Python_str_AsChar(old_str);
    PyErr_Clear();
    Py_XINCREF(type);
    if (tmp)
      PyErr_Format(type, "%s %s", tmp, mesg);
    else
      PyErr_Format(type, "%s", mesg);
    Py_DECREF(old_str);
    Py_DECREF(value);
  } else {
    PyErr_SetString(PyExc_RuntimeError, mesg);
  }
}

SWIGRUNTIME int
SWIG_Python_TypeErrorOccurred(PyObject *obj)
{
  PyObject *error;
  if (obj)
    return 0;
  error = PyErr_Occurred();
  return error && PyErr_GivenExceptionMatches(error, PyExc_TypeError);
}

SWIGRUNTIME void
SWIG_Python_RaiseOrModifyTypeError(const char *message)
{
  if (SWIG_Python_TypeErrorOccurred(NULL)) {
    /* Use existing TypeError to preserve stacktrace and enhance with given message */
    PyObject *newvalue;
    PyObject *type = NULL, *value = NULL, *traceback = NULL;
    PyErr_Fetch(&type, &value, &traceback);
#if PY_VERSION_HEX >= 0x03000000
    newvalue = PyUnicode_FromFormat("%S\nAdditional information:\n%s", value, message);
#else
    newvalue = PyString_FromFormat("%s\nAdditional information:\n%s", PyString_AsString(value), message);
#endif
    if (newvalue) {
      Py_XDECREF(value);
      PyErr_Restore(type, newvalue, traceback);
    } else {
      PyErr_Restore(type, value, traceback);
    }
  } else {
    /* Raise TypeError using given message */
    PyErr_SetString(PyExc_TypeError, message);
  }
}

#if defined(SWIG_PYTHON_NO_THREADS)
#  if defined(SWIG_PYTHON_THREADS)
#    undef SWIG_PYTHON_THREADS
#  endif
#endif
#if defined(SWIG_PYTHON_THREADS) /* Threading support is enabled */
#  if !defined(SWIG_PYTHON_USE_GIL) && !defined(SWIG_PYTHON_NO_USE_GIL)
#    define SWIG_PYTHON_USE_GIL
#  endif
#  if defined(SWIG_PYTHON_USE_GIL) /* Use PyGILState threads calls */
#    if !defined(SWIG_PYTHON_INITIALIZE_THREADS)
#      if PY_VERSION_HEX < 0x03070000
#        define SWIG_PYTHON_INITIALIZE_THREADS PyEval_InitThreads()
#      else
#        define SWIG_PYTHON_INITIALIZE_THREADS
#      endif
#    endif
#    ifdef __cplusplus /* C++ code */
       class SWIG_Python_Thread_Block {
         bool status;
         PyGILState_STATE state;
       public:
         void end() { if (status) { PyGILState_Release(state); status = false;} }
         SWIG_Python_Thread_Block() : status(true), state(PyGILState_Ensure()) {}
         ~SWIG_Python_Thread_Block() { end(); }
       };
       class SWIG_Python_Thread_Allow {
         bool status;
         PyThreadState *save;
       public:
         void end() { if (status) { PyEval_RestoreThread(save); status = false; }}
         SWIG_Python_Thread_Allow() : status(true), save(PyEval_SaveThread()) {}
         ~SWIG_Python_Thread_Allow() { end(); }
       };
#      define SWIG_PYTHON_THREAD_BEGIN_BLOCK   SWIG_Python_Thread_Block _swig_thread_block
#      define SWIG_PYTHON_THREAD_END_BLOCK     _swig_thread_block.end()
#      define SWIG_PYTHON_THREAD_BEGIN_ALLOW   SWIG_Python_Thread_Allow _swig_thread_allow
#      define SWIG_PYTHON_THREAD_END_ALLOW     _swig_thread_allow.end()
#    else /* C code */
#      define SWIG_PYTHON_THREAD_BEGIN_BLOCK   PyGILState_STATE _swig_thread_block = PyGILState_Ensure()
#      define SWIG_PYTHON_THREAD_END_BLOCK     PyGILState_Release(_swig_thread_block)
#      define SWIG_PYTHON_THREAD_BEGIN_ALLOW   PyThreadState *_swig_thread_allow = PyEval_SaveThread()
#      define SWIG_PYTHON_THREAD_END_ALLOW     PyEval_RestoreThread(_swig_thread_allow)
#    endif
#  else /* Old thread way, not implemented, user must provide it */
#    if !defined(SWIG_PYTHON_INITIALIZE_THREADS)
#      define SWIG_PYTHON_INITIALIZE_THREADS
#    endif
#    if !defined(SWIG_PYTHON_THREAD_BEGIN_BLOCK)
#      define SWIG_PYTHON_THREAD_BEGIN_BLOCK
#    endif
#    if !defined(SWIG_PYTHON_THREAD_END_BLOCK)
#      define SWIG_PYTHON_THREAD_END_BLOCK
#    endif
#    if !defined(SWIG_PYTHON_THREAD_BEGIN_ALLOW)
#      define SWIG_PYTHON_THREAD_BEGIN_ALLOW
#    endif
#    if !defined(SWIG_PYTHON_THREAD_END_ALLOW)
#      define SWIG_PYTHON_THREAD_END_ALLOW
#    endif
#  endif
#else /* No thread support */
#  define SWIG_PYTHON_INITIALIZE_THREADS
#  define SWIG_PYTHON_THREAD_BEGIN_BLOCK
#  define SWIG_PYTHON_THREAD_END_BLOCK
#  define SWIG_PYTHON_THREAD_BEGIN_ALLOW
#  define SWIG_PYTHON_THREAD_END_ALLOW
#endif

/* -----------------------------------------------------------------------------
 * Python API portion that goes into the runtime
 * ----------------------------------------------------------------------------- */

#ifdef __cplusplus
extern "C" {
#endif

/* -----------------------------------------------------------------------------
 * Constant declarations
 * ----------------------------------------------------------------------------- */

/* Constant Types */
#define SWIG_PY_POINTER 4
#define SWIG_PY_BINARY  5

/* Constant information structure */
typedef struct swig_const_info {
  int type;
  const char *name;
  long lvalue;
  double dvalue;
  void   *pvalue;
  swig_type_info **ptype;
} swig_const_info;

#ifdef __cplusplus
}
#endif


/* -----------------------------------------------------------------------------
 * pyrun.swg
 *
 * This file contains the runtime support for Python modules
 * and includes code for managing global variables and pointer
 * type checking.
 *
 * ----------------------------------------------------------------------------- */

#if PY_VERSION_HEX < 0x02070000 /* 2.7.0 */
# error "This version of SWIG only supports Python >= 2.7"
#endif

#if PY_VERSION_HEX >= 0x03000000 && PY_VERSION_HEX < 0x03030000
# error "This version of SWIG only supports Python 3 >= 3.3"
#endif

/* Common SWIG API */

/* for raw pointers */
#define SWIG_Python_ConvertPtr(obj, pptr, type, flags)  SWIG_Python_ConvertPtrAndOwn(obj, pptr, type, flags, 0)
#define SWIG_ConvertPtr(obj, pptr, type, flags)         SWIG_Python_ConvertPtr(obj, pptr, type, flags)
#define SWIG_ConvertPtrAndOwn(obj,pptr,type,flags,own)  SWIG_Python_ConvertPtrAndOwn(obj, pptr, type, flags, own)

#ifdef SWIGPYTHON_BUILTIN
#define SWIG_NewPointerObj(ptr, type, flags)            SWIG_Python_NewPointerObj(self, ptr, type, flags)
#else
#define SWIG_NewPointerObj(ptr, type, flags)            SWIG_Python_NewPointerObj(NULL, ptr, type, flags)
#endif

#define SWIG_InternalNewPointerObj(ptr, type, flags)	SWIG_Python_NewPointerObj(NULL, ptr, type, flags)

#define SWIG_CheckImplicit(ty)                          SWIG_Python_CheckImplicit(ty) 
#define SWIG_AcquirePtr(ptr, src)                       SWIG_Python_AcquirePtr(ptr, src)
#define swig_owntype                                    int

/* for raw packed data */
#define SWIG_ConvertPacked(obj, ptr, sz, ty)            SWIG_Python_ConvertPacked(obj, ptr, sz, ty)
#define SWIG_NewPackedObj(ptr, sz, type)                SWIG_Python_NewPackedObj(ptr, sz, type)

/* for class or struct pointers */
#define SWIG_ConvertInstance(obj, pptr, type, flags)    SWIG_ConvertPtr(obj, pptr, type, flags)
#define SWIG_NewInstanceObj(ptr, type, flags)           SWIG_NewPointerObj(ptr, type, flags)

/* for C or C++ function pointers */
#define SWIG_ConvertFunctionPtr(obj, pptr, type)        SWIG_Python_ConvertFunctionPtr(obj, pptr, type)
#define SWIG_NewFunctionPtrObj(ptr, type)               SWIG_Python_NewPointerObj(NULL, ptr, type, 0)

/* for C++ member pointers, ie, member methods */
#define SWIG_ConvertMember(obj, ptr, sz, ty)            SWIG_Python_ConvertPacked(obj, ptr, sz, ty)
#define SWIG_NewMemberObj(ptr, sz, type)                SWIG_Python_NewPackedObj(ptr, sz, type)


/* Runtime API */

#define SWIG_GetModule(clientdata)                      SWIG_Python_GetModule(clientdata)
#define SWIG_SetModule(clientdata, pointer)             SWIG_Python_SetModule(pointer)
#define SWIG_NewClientData(obj)                         SwigPyClientData_New(obj)

#define SWIG_SetErrorObj                                SWIG_Python_SetErrorObj                            
#define SWIG_SetErrorMsg                        	SWIG_Python_SetErrorMsg				   
#define SWIG_ErrorType(code)                    	SWIG_Python_ErrorType(code)                        
#define SWIG_Error(code, msg)            		SWIG_Python_SetErrorMsg(SWIG_ErrorType(code), msg) 
#define SWIG_fail                        		goto fail					   


/* Runtime API implementation */

/* Error manipulation */

SWIGINTERN void 
SWIG_Python_SetErrorObj(PyObject *errtype, PyObject *obj) {
  SWIG_PYTHON_THREAD_BEGIN_BLOCK; 
  PyErr_SetObject(errtype, obj);
  Py_DECREF(obj);
  SWIG_PYTHON_THREAD_END_BLOCK;
}

SWIGINTERN void 
SWIG_Python_SetErrorMsg(PyObject *errtype, const char *msg) {
  SWIG_PYTHON_THREAD_BEGIN_BLOCK;
  PyErr_SetString(errtype, msg);
  SWIG_PYTHON_THREAD_END_BLOCK;
}

#define SWIG_Python_Raise(obj, type, desc)  SWIG_Python_SetErrorObj(SWIG_Python_ExceptionType(desc), obj)

/* Set a constant value */

#if defined(SWIGPYTHON_BUILTIN)

SWIGINTERN void
SwigPyBuiltin_AddPublicSymbol(PyObject *seq, const char *key) {
  PyObject *s = PyString_InternFromString(key);
  PyList_Append(seq, s);
  Py_DECREF(s);
}

SWIGINTERN void
SWIG_Python_SetConstant(PyObject *d, PyObject *public_interface, const char *name, PyObject *obj) {   
  PyDict_SetItemString(d, name, obj);
  Py_DECREF(obj);
  if (public_interface)
    SwigPyBuiltin_AddPublicSymbol(public_interface, name);
}

#else

SWIGINTERN void
SWIG_Python_SetConstant(PyObject *d, const char *name, PyObject *obj) {   
  PyDict_SetItemString(d, name, obj);
  Py_DECREF(obj);                            
}

#endif

/* Append a value to the result obj */

SWIGINTERN PyObject*
SWIG_Python_AppendOutput(PyObject* result, PyObject* obj) {
  if (!result) {
    result = obj;
  } else if (result == Py_None) {
    Py_DECREF(result);
    result = obj;
  } else {
    if (!PyList_Check(result)) {
      PyObject *o2 = result;
      result = PyList_New(1);
      if (result) {
        PyList_SET_ITEM(result, 0, o2);
      } else {
        Py_DECREF(obj);
        return o2;
      }
    }
    PyList_Append(result,obj);
    Py_DECREF(obj);
  }
  return result;
}

/* Unpack the argument tuple */

SWIGINTERN Py_ssize_t
SWIG_Python_UnpackTuple(PyObject *args, const char *name, Py_ssize_t min, Py_ssize_t max, PyObject **objs)
{
  if (!args) {
    if (!min && !max) {
      return 1;
    } else {
      PyErr_Format(PyExc_TypeError, "%s expected %s%d arguments, got none", 
		   name, (min == max ? "" : "at least "), (int)min);
      return 0;
    }
  }  
  if (!PyTuple_Check(args)) {
    if (min <= 1 && max >= 1) {
      Py_ssize_t i;
      objs[0] = args;
      for (i = 1; i < max; ++i) {
	objs[i] = 0;
      }
      return 2;
    }
    PyErr_SetString(PyExc_SystemError, "UnpackTuple() argument list is not a tuple");
    return 0;
  } else {
    Py_ssize_t l = PyTuple_GET_SIZE(args);
    if (l < min) {
      PyErr_Format(PyExc_TypeError, "%s expected %s%d arguments, got %d", 
		   name, (min == max ? "" : "at least "), (int)min, (int)l);
      return 0;
    } else if (l > max) {
      PyErr_Format(PyExc_TypeError, "%s expected %s%d arguments, got %d", 
		   name, (min == max ? "" : "at most "), (int)max, (int)l);
      return 0;
    } else {
      Py_ssize_t i;
      for (i = 0; i < l; ++i) {
	objs[i] = PyTuple_GET_ITEM(args, i);
      }
      for (; l < max; ++l) {
	objs[l] = 0;
      }
      return i + 1;
    }    
  }
}

SWIGINTERN int
SWIG_Python_CheckNoKeywords(PyObject *kwargs, const char *name) {
  int no_kwargs = 1;
  if (kwargs) {
    assert(PyDict_Check(kwargs));
    if (PyDict_Size(kwargs) > 0) {
      PyErr_Format(PyExc_TypeError, "%s() does not take keyword arguments", name);
      no_kwargs = 0;
    }
  }
  return no_kwargs;
}

/* A functor is a function object with one single object argument */
#define SWIG_Python_CallFunctor(functor, obj)	        PyObject_CallFunctionObjArgs(functor, obj, NULL);

/*
  Helper for static pointer initialization for both C and C++ code, for example
  static PyObject *SWIG_STATIC_POINTER(MyVar) = NewSomething(...);
*/
#ifdef __cplusplus
#define SWIG_STATIC_POINTER(var)  var
#else
#define SWIG_STATIC_POINTER(var)  var = 0; if (!var) var
#endif

#ifdef __cplusplus
extern "C" {
#endif

/* Python-specific SWIG API */
#define SWIG_newvarlink()                             SWIG_Python_newvarlink()
#define SWIG_addvarlink(p, name, get_attr, set_attr)  SWIG_Python_addvarlink(p, name, get_attr, set_attr)
#define SWIG_InstallConstants(d, constants)           SWIG_Python_InstallConstants(d, constants)
 
/* -----------------------------------------------------------------------------
 * global variable support code.
 * ----------------------------------------------------------------------------- */
 
typedef struct swig_globalvar {   
  char       *name;                  /* Name of global variable */
  PyObject *(*get_attr)(void);       /* Return the current value */
  int       (*set_attr)(PyObject *); /* Set the value */
  struct swig_globalvar *next;
} swig_globalvar;

typedef struct swig_varlinkobject {
  PyObject_HEAD
  swig_globalvar *vars;
} swig_varlinkobject;

SWIGINTERN PyObject *
swig_varlink_repr(PyObject *SWIGUNUSEDPARM(v)) {
#if PY_VERSION_HEX >= 0x03000000
  return PyUnicode_InternFromString("<Swig global variables>");
#else
  return PyString_FromString("<Swig global variables>");
#endif
}

SWIGINTERN PyObject *
swig_varlink_str(PyObject *o) {
  swig_varlinkobject *v = (swig_varlinkobject *) o;
#if PY_VERSION_HEX >= 0x03000000
  PyObject *str = PyUnicode_InternFromString("(");
  PyObject *tail;
  PyObject *joined;
  swig_globalvar *var;
  for (var = v->vars; var; var=var->next) {
    tail = PyUnicode_FromString(var->name);
    joined = PyUnicode_Concat(str, tail);
    Py_DecRef(str);
    Py_DecRef(tail);
    str = joined;
    if (var->next) {
        tail = PyUnicode_InternFromString(", ");
        joined = PyUnicode_Concat(str, tail);
        Py_DecRef(str);
        Py_DecRef(tail);
        str = joined;
    }
  }
  tail = PyUnicode_InternFromString(")");
  joined = PyUnicode_Concat(str, tail);
  Py_DecRef(str);
  Py_DecRef(tail);
  str = joined;
#else
  PyObject *str = PyString_FromString("(");
  swig_globalvar *var;
  for (var = v->vars; var; var=var->next) {
    PyString_ConcatAndDel(&str,PyString_FromString(var->name));
    if (var->next) PyString_ConcatAndDel(&str,PyString_FromString(", "));
  }
  PyString_ConcatAndDel(&str,PyString_FromString(")"));
#endif
  return str;
}

SWIGINTERN void
swig_varlink_dealloc(PyObject *o) {
  swig_varlinkobject *v = (swig_varlinkobject *) o;
  swig_globalvar *var = v->vars;
  while (var) {
    swig_globalvar *n = var->next;
    free(var->name);
    free(var);
    var = n;
  }
}

SWIGINTERN PyObject *
swig_varlink_getattr(PyObject *o, char *n) {
  swig_varlinkobject *v = (swig_varlinkobject *) o;
  PyObject *res = NULL;
  swig_globalvar *var = v->vars;
  while (var) {
    if (strcmp(var->name,n) == 0) {
      res = (*var->get_attr)();
      break;
    }
    var = var->next;
  }
  if (res == NULL && !PyErr_Occurred()) {
    PyErr_Format(PyExc_AttributeError, "Unknown C global variable '%s'", n);
  }
  return res;
}

SWIGINTERN int
swig_varlink_setattr(PyObject *o, char *n, PyObject *p) {
  swig_varlinkobject *v = (swig_varlinkobject *) o;
  int res = 1;
  swig_globalvar *var = v->vars;
  while (var) {
    if (strcmp(var->name,n) == 0) {
      res = (*var->set_attr)(p);
      break;
    }
    var = var->next;
  }
  if (res == 1 && !PyErr_Occurred()) {
    PyErr_Format(PyExc_AttributeError, "Unknown C global variable '%s'", n);
  }
  return res;
}

SWIGINTERN PyTypeObject*
swig_varlink_type(void) {
  static char varlink__doc__[] = "Swig var link object";
  static PyTypeObject varlink_type;
  static int type_init = 0;
  if (!type_init) {
    const PyTypeObject tmp = {
#if PY_VERSION_HEX >= 0x03000000
      PyVarObject_HEAD_INIT(NULL, 0)
#else
      PyObject_HEAD_INIT(NULL)
      0,                                  /* ob_size */
#endif
      "swigvarlink",                      /* tp_name */
      sizeof(swig_varlinkobject),         /* tp_basicsize */
      0,                                  /* tp_itemsize */
      (destructor) swig_varlink_dealloc,  /* tp_dealloc */
#if PY_VERSION_HEX < 0x030800b4
      (printfunc)0,                       /*tp_print*/
#else
      (Py_ssize_t)0,                      /*tp_vectorcall_offset*/
#endif
      (getattrfunc) swig_varlink_getattr, /* tp_getattr */
      (setattrfunc) swig_varlink_setattr, /* tp_setattr */
      0,                                  /* tp_compare */
      (reprfunc) swig_varlink_repr,       /* tp_repr */
      0,                                  /* tp_as_number */
      0,                                  /* tp_as_sequence */
      0,                                  /* tp_as_mapping */
      0,                                  /* tp_hash */
      0,                                  /* tp_call */
      (reprfunc) swig_varlink_str,        /* tp_str */
      0,                                  /* tp_getattro */
      0,                                  /* tp_setattro */
      0,                                  /* tp_as_buffer */
      0,                                  /* tp_flags */
      varlink__doc__,                     /* tp_doc */
      0,                                  /* tp_traverse */
      0,                                  /* tp_clear */
      0,                                  /* tp_richcompare */
      0,                                  /* tp_weaklistoffset */
      0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0, /* tp_iter -> tp_weaklist */
      0,                                  /* tp_del */
      0,                                  /* tp_version_tag */
#if PY_VERSION_HEX >= 0x03040000
      0,                                  /* tp_finalize */
#endif
#if PY_VERSION_HEX >= 0x03080000
      0,                                  /* tp_vectorcall */
#endif
#if (PY_VERSION_HEX >= 0x03080000) && (PY_VERSION_HEX < 0x03090000)
      0,                                  /* tp_print */
#endif
#ifdef COUNT_ALLOCS
      0,                                  /* tp_allocs */
      0,                                  /* tp_frees */
      0,                                  /* tp_maxalloc */
      0,                                  /* tp_prev */
      0                                   /* tp_next */
#endif
    };
    varlink_type = tmp;
    type_init = 1;
    if (PyType_Ready(&varlink_type) < 0)
      return NULL;
  }
  return &varlink_type;
}

/* Create a variable linking object for use later */
SWIGINTERN PyObject *
SWIG_Python_newvarlink(void) {
  swig_varlinkobject *result = PyObject_NEW(swig_varlinkobject, swig_varlink_type());
  if (result) {
    result->vars = 0;
  }
  return ((PyObject*) result);
}

SWIGINTERN void 
SWIG_Python_addvarlink(PyObject *p, const char *name, PyObject *(*get_attr)(void), int (*set_attr)(PyObject *p)) {
  swig_varlinkobject *v = (swig_varlinkobject *) p;
  swig_globalvar *gv = (swig_globalvar *) malloc(sizeof(swig_globalvar));
  if (gv) {
    size_t size = strlen(name)+1;
    gv->name = (char *)malloc(size);
    if (gv->name) {
      memcpy(gv->name, name, size);
      gv->get_attr = get_attr;
      gv->set_attr = set_attr;
      gv->next = v->vars;
    }
  }
  v->vars = gv;
}


static PyObject *Swig_Globals_global = NULL;
  
SWIGINTERN PyObject *
SWIG_globals(void) {
  if (Swig_Globals_global == NULL) {
    Swig_Globals_global = SWIG_newvarlink();
  }
  return Swig_Globals_global;
}

#ifdef __cplusplus
}
#endif

/* -----------------------------------------------------------------------------
 * Pointer declarations
 * ----------------------------------------------------------------------------- */

/* Flags for new pointer objects */
#define SWIG_POINTER_NOSHADOW       (SWIG_POINTER_OWN      << 1)
#define SWIG_POINTER_NEW            (SWIG_POINTER_NOSHADOW | SWIG_POINTER_OWN)

#define SWIG_POINTER_IMPLICIT_CONV  (SWIG_POINTER_DISOWN   << 1)

#define SWIG_BUILTIN_TP_INIT	    (SWIG_POINTER_OWN << 2)
#define SWIG_BUILTIN_INIT	    (SWIG_BUILTIN_TP_INIT | SWIG_POINTER_OWN)

#ifdef __cplusplus
extern "C" {
#endif

/* The python void return value */

SWIGRUNTIMEINLINE PyObject * 
SWIG_Py_Void(void)
{
  PyObject *none = Py_None;
  Py_INCREF(none);
  return none;
}

/* SwigPyClientData */

typedef struct {
  PyObject *klass;
  PyObject *newraw;
  PyObject *newargs;
  PyObject *destroy;
  int delargs;
  int implicitconv;
  PyTypeObject *pytype;
} SwigPyClientData;

SWIGRUNTIMEINLINE int 
SWIG_Python_CheckImplicit(swig_type_info *ty)
{
  SwigPyClientData *data = (SwigPyClientData *)ty->clientdata;
  int fail = data ? data->implicitconv : 0;
  if (fail)
    PyErr_SetString(PyExc_TypeError, "Implicit conversion is prohibited for explicit constructors.");
  return fail;
}

SWIGRUNTIMEINLINE PyObject *
SWIG_Python_ExceptionType(swig_type_info *desc) {
  SwigPyClientData *data = desc ? (SwigPyClientData *) desc->clientdata : 0;
  PyObject *klass = data ? data->klass : 0;
  return (klass ? klass : PyExc_RuntimeError);
}


SWIGRUNTIME SwigPyClientData * 
SwigPyClientData_New(PyObject* obj)
{
  if (!obj) {
    return 0;
  } else {
    SwigPyClientData *data = (SwigPyClientData *)malloc(sizeof(SwigPyClientData));
    /* the klass element */
    data->klass = obj;
    Py_INCREF(data->klass);
    /* the newraw method and newargs arguments used to create a new raw instance */
    if (PyClass_Check(obj)) {
      data->newraw = 0;
      Py_INCREF(obj);
      data->newargs = obj;
    } else {
      data->newraw = PyObject_GetAttrString(data->klass, "__new__");
      if (data->newraw) {
        data->newargs = PyTuple_New(1);
        if (data->newargs) {
          Py_INCREF(obj);
          PyTuple_SET_ITEM(data->newargs, 0, obj);
        } else {
          Py_DECREF(data->newraw);
          Py_DECREF(data->klass);
          free(data);
          return 0;
        }
      } else {
        Py_INCREF(obj);
        data->newargs = obj;
      }
    }
    /* the destroy method, aka as the C++ delete method */
    data->destroy = PyObject_GetAttrString(data->klass, "__swig_destroy__");
    if (PyErr_Occurred()) {
      PyErr_Clear();
      data->destroy = 0;
    }
    if (data->destroy) {
      data->delargs = !(PyCFunction_GET_FLAGS(data->destroy) & METH_O);
    } else {
      data->delargs = 0;
    }
    data->implicitconv = 0;
    data->pytype = 0;
    return data;
  }
}

SWIGRUNTIME void 
SwigPyClientData_Del(SwigPyClientData *data)
{
  Py_XDECREF(data->klass);
  Py_XDECREF(data->newraw);
  Py_XDECREF(data->newargs);
  Py_XDECREF(data->destroy);
  free(data);
}

/* =============== SwigPyObject =====================*/

typedef struct {
  PyObject_HEAD
  void *ptr;
  swig_type_info *ty;
  int own;
  PyObject *next;
#ifdef SWIGPYTHON_BUILTIN
  PyObject *dict;
#endif
} SwigPyObject;


#ifdef SWIGPYTHON_BUILTIN

SWIGRUNTIME PyObject *
SwigPyObject_get___dict__(PyObject *v, PyObject *SWIGUNUSEDPARM(args))
{
  SwigPyObject *sobj = (SwigPyObject *)v;

  if (!sobj->dict)
    sobj->dict = PyDict_New();

  Py_XINCREF(sobj->dict);
  return sobj->dict;
}

#endif

SWIGRUNTIME PyObject *
SwigPyObject_long(SwigPyObject *v)
{
  return PyLong_FromVoidPtr(v->ptr);
}

SWIGRUNTIME PyObject *
SwigPyObject_format(const char* fmt, SwigPyObject *v)
{
  PyObject *res = NULL;
  PyObject *args = PyTuple_New(1);
  if (args) {
    PyObject *val = SwigPyObject_long(v);
    if (val) {
      PyObject *ofmt;
      PyTuple_SET_ITEM(args, 0, val);
      ofmt = SWIG_Python_str_FromChar(fmt);
      if (ofmt) {
#if PY_VERSION_HEX >= 0x03000000
        res = PyUnicode_Format(ofmt,args);
#else
        res = PyString_Format(ofmt,args);
#endif
        Py_DECREF(ofmt);
      }
    }
    Py_DECREF(args);
  }
  return res;
}

SWIGRUNTIME PyObject *
SwigPyObject_oct(SwigPyObject *v)
{
  return SwigPyObject_format("%o",v);
}

SWIGRUNTIME PyObject *
SwigPyObject_hex(SwigPyObject *v)
{
  return SwigPyObject_format("%x",v);
}

SWIGRUNTIME PyObject *
SwigPyObject_repr(SwigPyObject *v)
{
  const char *name = SWIG_TypePrettyName(v->ty);
  PyObject *repr = SWIG_Python_str_FromFormat("<Swig Object of type '%s' at %p>", (name ? name : "unknown"), (void *)v);
  if (repr && v->next) {
    PyObject *nrep = SwigPyObject_repr((SwigPyObject *)v->next);
    if (nrep) {
# if PY_VERSION_HEX >= 0x03000000
      PyObject *joined = PyUnicode_Concat(repr, nrep);
      Py_DecRef(repr);
      Py_DecRef(nrep);
      repr = joined;
# else
      PyString_ConcatAndDel(&repr,nrep);
# endif
    } else {
      Py_DecRef(repr);
      repr = NULL;
    }
  }
  return repr;
}

/* We need a version taking two PyObject* parameters so it's a valid
 * PyCFunction to use in swigobject_methods[]. */
SWIGRUNTIME PyObject *
SwigPyObject_repr2(PyObject *v, PyObject *SWIGUNUSEDPARM(args))
{
  return SwigPyObject_repr((SwigPyObject*)v);
}

SWIGRUNTIME int
SwigPyObject_compare(SwigPyObject *v, SwigPyObject *w)
{
  void *i = v->ptr;
  void *j = w->ptr;
  return (i < j) ? -1 : ((i > j) ? 1 : 0);
}

/* Added for Python 3.x, would it also be useful for Python 2.x? */
SWIGRUNTIME PyObject*
SwigPyObject_richcompare(SwigPyObject *v, SwigPyObject *w, int op)
{
  PyObject* res;
  if( op != Py_EQ && op != Py_NE ) {
    Py_INCREF(Py_NotImplemented);
    return Py_NotImplemented;
  }
  res = PyBool_FromLong( (SwigPyObject_compare(v, w)==0) == (op == Py_EQ) ? 1 : 0);
  return res;  
}


SWIGRUNTIME PyTypeObject* SwigPyObject_TypeOnce(void);

#ifdef SWIGPYTHON_BUILTIN
static swig_type_info *SwigPyObject_stype = 0;
SWIGRUNTIME PyTypeObject*
SwigPyObject_type(void) {
    SwigPyClientData *cd;
    assert(SwigPyObject_stype);
    cd = (SwigPyClientData*) SwigPyObject_stype->clientdata;
    assert(cd);
    assert(cd->pytype);
    return cd->pytype;
}
#else
SWIGRUNTIME PyTypeObject*
SwigPyObject_type(void) {
  static PyTypeObject *SWIG_STATIC_POINTER(type) = SwigPyObject_TypeOnce();
  return type;
}
#endif

SWIGRUNTIMEINLINE int
SwigPyObject_Check(PyObject *op) {
#ifdef SWIGPYTHON_BUILTIN
  PyTypeObject *target_tp = SwigPyObject_type();
  if (PyType_IsSubtype(op->ob_type, target_tp))
    return 1;
  return (strcmp(op->ob_type->tp_name, "SwigPyObject") == 0);
#else
  return (Py_TYPE(op) == SwigPyObject_type())
    || (strcmp(Py_TYPE(op)->tp_name,"SwigPyObject") == 0);
#endif
}

SWIGRUNTIME PyObject *
SwigPyObject_New(void *ptr, swig_type_info *ty, int own);

static PyObject* Swig_Capsule_global = NULL;

SWIGRUNTIME void
SwigPyObject_dealloc(PyObject *v)
{
  SwigPyObject *sobj = (SwigPyObject *) v;
  PyObject *next = sobj->next;
  if (sobj->own == SWIG_POINTER_OWN) {
    swig_type_info *ty = sobj->ty;
    SwigPyClientData *data = ty ? (SwigPyClientData *) ty->clientdata : 0;
    PyObject *destroy = data ? data->destroy : 0;
    if (destroy) {
      /* destroy is always a VARARGS method */
      PyObject *res;

      /* PyObject_CallFunction() has the potential to silently drop
         the active exception.  In cases of unnamed temporary
         variable or where we just finished iterating over a generator
         StopIteration will be active right now, and this needs to
         remain true upon return from SwigPyObject_dealloc.  So save
         and restore. */
      
      PyObject *type = NULL, *value = NULL, *traceback = NULL;
      PyErr_Fetch(&type, &value, &traceback);

      if (data->delargs) {
        /* we need to create a temporary object to carry the destroy operation */
        PyObject *tmp = SwigPyObject_New(sobj->ptr, ty, 0);
        if (tmp) {
          res = SWIG_Python_CallFunctor(destroy, tmp);
        } else {
          res = 0;
        }
        Py_XDECREF(tmp);
      } else {
        PyCFunction meth = PyCFunction_GET_FUNCTION(destroy);
        PyObject *mself = PyCFunction_GET_SELF(destroy);
        res = ((*meth)(mself, v));
      }
      if (!res)
        PyErr_WriteUnraisable(destroy);

      PyErr_Restore(type, value, traceback);

      Py_XDECREF(res);
    } 
#if !defined(SWIG_PYTHON_SILENT_MEMLEAK)
    else {
      const char *name = SWIG_TypePrettyName(ty);
      printf("swig/python detected a memory leak of type '%s', no destructor found.\n", (name ? name : "unknown"));
    }
#endif
    Py_XDECREF(Swig_Capsule_global);
  }
  Py_XDECREF(next);
#ifdef SWIGPYTHON_BUILTIN
  Py_XDECREF(sobj->dict);
#endif
  PyObject_DEL(v);
}

SWIGRUNTIME PyObject* 
SwigPyObject_append(PyObject* v, PyObject* next)
{
  SwigPyObject *sobj = (SwigPyObject *) v;
  if (!SwigPyObject_Check(next)) {
    PyErr_SetString(PyExc_TypeError, "Attempt to append a non SwigPyObject");
    return NULL;
  }
  ((SwigPyObject *)next)->next = sobj->next;
  sobj->next = next;
  Py_INCREF(next);
  return SWIG_Py_Void();
}

SWIGRUNTIME PyObject* 
SwigPyObject_next(PyObject* v, PyObject *SWIGUNUSEDPARM(args))
{
  SwigPyObject *sobj = (SwigPyObject *) v;
  if (sobj->next) {    
    Py_INCREF(sobj->next);
    return sobj->next;
  } else {
    return SWIG_Py_Void();
  }
}

SWIGINTERN PyObject*
SwigPyObject_disown(PyObject* v, PyObject *SWIGUNUSEDPARM(args))
{
  SwigPyObject *sobj = (SwigPyObject *)v;
  sobj->own = 0;
  return SWIG_Py_Void();
}

SWIGINTERN PyObject*
SwigPyObject_acquire(PyObject* v, PyObject *SWIGUNUSEDPARM(args))
{
  SwigPyObject *sobj = (SwigPyObject *)v;
  sobj->own = SWIG_POINTER_OWN;
  return SWIG_Py_Void();
}

SWIGINTERN PyObject*
SwigPyObject_own(PyObject *v, PyObject *args)
{
  PyObject *val = 0;
  if (!PyArg_UnpackTuple(args, "own", 0, 1, &val)) {
    return NULL;
  } else {
    SwigPyObject *sobj = (SwigPyObject *)v;
    PyObject *obj = PyBool_FromLong(sobj->own);
    if (val) {
      if (PyObject_IsTrue(val)) {
        Py_DECREF(SwigPyObject_acquire(v,args));
      } else {
        Py_DECREF(SwigPyObject_disown(v,args));
      }
    } 
    return obj;
  }
}

static PyMethodDef
swigobject_methods[] = {
  {"disown",  SwigPyObject_disown,  METH_NOARGS,  "releases ownership of the pointer"},
  {"acquire", SwigPyObject_acquire, METH_NOARGS,  "acquires ownership of the pointer"},
  {"own",     SwigPyObject_own,     METH_VARARGS, "returns/sets ownership of the pointer"},
  {"append",  SwigPyObject_append,  METH_O,       "appends another 'this' object"},
  {"next",    SwigPyObject_next,    METH_NOARGS,  "returns the next 'this' object"},
  {"__repr__",SwigPyObject_repr2,   METH_NOARGS,  "returns object representation"},
  {0, 0, 0, 0}  
};

SWIGRUNTIME PyTypeObject*
SwigPyObject_TypeOnce(void) {
  static char swigobject_doc[] = "Swig object carries a C/C++ instance pointer";

  static PyNumberMethods SwigPyObject_as_number = {
    (binaryfunc)0, /*nb_add*/
    (binaryfunc)0, /*nb_subtract*/
    (binaryfunc)0, /*nb_multiply*/
    /* nb_divide removed in Python 3 */
#if PY_VERSION_HEX < 0x03000000
    (binaryfunc)0, /*nb_divide*/
#endif
    (binaryfunc)0, /*nb_remainder*/
    (binaryfunc)0, /*nb_divmod*/
    (ternaryfunc)0,/*nb_power*/
    (unaryfunc)0,  /*nb_negative*/
    (unaryfunc)0,  /*nb_positive*/
    (unaryfunc)0,  /*nb_absolute*/
    (inquiry)0,    /*nb_nonzero*/
    0,		   /*nb_invert*/
    0,		   /*nb_lshift*/
    0,		   /*nb_rshift*/
    0,		   /*nb_and*/
    0,		   /*nb_xor*/
    0,		   /*nb_or*/
#if PY_VERSION_HEX < 0x03000000
    0,   /*nb_coerce*/
#endif
    (unaryfunc)SwigPyObject_long, /*nb_int*/
#if PY_VERSION_HEX < 0x03000000
    (unaryfunc)SwigPyObject_long, /*nb_long*/
#else
    0, /*nb_reserved*/
#endif
    (unaryfunc)0,                 /*nb_float*/
#if PY_VERSION_HEX < 0x03000000
    (unaryfunc)SwigPyObject_oct,  /*nb_oct*/
    (unaryfunc)SwigPyObject_hex,  /*nb_hex*/
#endif
#if PY_VERSION_HEX >= 0x03050000 /* 3.5 */
    0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 /* nb_inplace_add -> nb_inplace_matrix_multiply */
#elif PY_VERSION_HEX >= 0x03000000 /* 3.0 */
    0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 /* nb_inplace_add -> nb_index, nb_inplace_divide removed */
#else
    0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 /* nb_inplace_add -> nb_index */
#endif
  };

  static PyTypeObject swigpyobject_type;
  static int type_init = 0;
  if (!type_init) {
    const PyTypeObject tmp = {
#if PY_VERSION_HEX >= 0x03000000
      PyVarObject_HEAD_INIT(NULL, 0)
#else
      PyObject_HEAD_INIT(NULL)
      0,                                    /* ob_size */
#endif
      "SwigPyObject",                       /* tp_name */
      sizeof(SwigPyObject),                 /* tp_basicsize */
      0,                                    /* tp_itemsize */
      (destructor)SwigPyObject_dealloc,     /* tp_dealloc */
#if PY_VERSION_HEX < 0x030800b4
      (printfunc)0,                         /*tp_print*/
#else
      (Py_ssize_t)0,                        /*tp_vectorcall_offset*/
#endif
      (getattrfunc)0,                       /* tp_getattr */
      (setattrfunc)0,                       /* tp_setattr */
#if PY_VERSION_HEX >= 0x03000000
      0, /* tp_reserved in 3.0.1, tp_compare in 3.0.0 but not used */
#else
      (cmpfunc)SwigPyObject_compare,        /* tp_compare */
#endif
      (reprfunc)SwigPyObject_repr,          /* tp_repr */
      &SwigPyObject_as_number,              /* tp_as_number */
      0,                                    /* tp_as_sequence */
      0,                                    /* tp_as_mapping */
      (hashfunc)0,                          /* tp_hash */
      (ternaryfunc)0,                       /* tp_call */
      0,                                    /* tp_str */
      PyObject_GenericGetAttr,              /* tp_getattro */
      0,                                    /* tp_setattro */
      0,                                    /* tp_as_buffer */
      Py_TPFLAGS_DEFAULT,                   /* tp_flags */
      swigobject_doc,                       /* tp_doc */
      0,                                    /* tp_traverse */
      0,                                    /* tp_clear */
      (richcmpfunc)SwigPyObject_richcompare,/* tp_richcompare */
      0,                                    /* tp_weaklistoffset */
      0,                                    /* tp_iter */
      0,                                    /* tp_iternext */
      swigobject_methods,                   /* tp_methods */
      0,                                    /* tp_members */
      0,                                    /* tp_getset */
      0,                                    /* tp_base */
      0,                                    /* tp_dict */
      0,                                    /* tp_descr_get */
      0,                                    /* tp_descr_set */
      0,                                    /* tp_dictoffset */
      0,                                    /* tp_init */
      0,                                    /* tp_alloc */
      0,                                    /* tp_new */
      0,                                    /* tp_free */
      0,                                    /* tp_is_gc */
      0,                                    /* tp_bases */
      0,                                    /* tp_mro */
      0,                                    /* tp_cache */
      0,                                    /* tp_subclasses */
      0,                                    /* tp_weaklist */
      0,                                    /* tp_del */
      0,                                    /* tp_version_tag */
#if PY_VERSION_HEX >= 0x03040000
      0,                                    /* tp_finalize */
#endif
#if PY_VERSION_HEX >= 0x03080000
      0,                                    /* tp_vectorcall */
#endif
#if (PY_VERSION_HEX >= 0x03080000) && (PY_VERSION_HEX < 0x03090000)
      0,                                    /* tp_print */
#endif
#ifdef COUNT_ALLOCS
      0,                                    /* tp_allocs */
      0,                                    /* tp_frees */
      0,                                    /* tp_maxalloc */
      0,                                    /* tp_prev */
      0                                     /* tp_next */
#endif
    };
    swigpyobject_type = tmp;
    type_init = 1;
    if (PyType_Ready(&swigpyobject_type) != 0)
      return NULL;
  }
  return &swigpyobject_type;
}

SWIGRUNTIME PyObject *
SwigPyObject_New(void *ptr, swig_type_info *ty, int own)
{
  SwigPyObject *sobj = PyObject_NEW(SwigPyObject, SwigPyObject_type());
  if (sobj) {
    sobj->ptr  = ptr;
    sobj->ty   = ty;
    sobj->own  = own;
    sobj->next = 0;
#ifdef SWIGPYTHON_BUILTIN
    sobj->dict = 0;
#endif
    if (own == SWIG_POINTER_OWN) {
      /* Obtain a reference to the Python capsule wrapping the module information, so that the
       * module information is correctly destroyed after all SWIG python objects have been freed
       * by the GC (and corresponding destructors invoked) */
      Py_XINCREF(Swig_Capsule_global);
    }
  }
  return (PyObject *)sobj;
}

/* -----------------------------------------------------------------------------
 * Implements a simple Swig Packed type, and use it instead of string
 * ----------------------------------------------------------------------------- */

typedef struct {
  PyObject_HEAD
  void *pack;
  swig_type_info *ty;
  size_t size;
} SwigPyPacked;

SWIGRUNTIME PyObject *
SwigPyPacked_repr(SwigPyPacked *v)
{
  char result[SWIG_BUFFER_SIZE];
  if (SWIG_PackDataName(result, v->pack, v->size, 0, sizeof(result))) {
    return SWIG_Python_str_FromFormat("<Swig Packed at %s%s>", result, v->ty->name);
  } else {
    return SWIG_Python_str_FromFormat("<Swig Packed %s>", v->ty->name);
  }  
}

SWIGRUNTIME PyObject *
SwigPyPacked_str(SwigPyPacked *v)
{
  char result[SWIG_BUFFER_SIZE];
  if (SWIG_PackDataName(result, v->pack, v->size, 0, sizeof(result))){
    return SWIG_Python_str_FromFormat("%s%s", result, v->ty->name);
  } else {
    return SWIG_Python_str_FromChar(v->ty->name);
  }  
}

SWIGRUNTIME int
SwigPyPacked_compare(SwigPyPacked *v, SwigPyPacked *w)
{
  size_t i = v->size;
  size_t j = w->size;
  int s = (i < j) ? -1 : ((i > j) ? 1 : 0);
  return s ? s : strncmp((const char *)v->pack, (const char *)w->pack, 2*v->size);
}

SWIGRUNTIME PyTypeObject* SwigPyPacked_TypeOnce(void);

SWIGRUNTIME PyTypeObject*
SwigPyPacked_type(void) {
  static PyTypeObject *SWIG_STATIC_POINTER(type) = SwigPyPacked_TypeOnce();
  return type;
}

SWIGRUNTIMEINLINE int
SwigPyPacked_Check(PyObject *op) {
  return ((op)->ob_type == SwigPyPacked_TypeOnce()) 
    || (strcmp((op)->ob_type->tp_name,"SwigPyPacked") == 0);
}

SWIGRUNTIME void
SwigPyPacked_dealloc(PyObject *v)
{
  if (SwigPyPacked_Check(v)) {
    SwigPyPacked *sobj = (SwigPyPacked *) v;
    free(sobj->pack);
  }
  PyObject_DEL(v);
}

SWIGRUNTIME PyTypeObject*
SwigPyPacked_TypeOnce(void) {
  static char swigpacked_doc[] = "Swig object carries a C/C++ instance pointer";
  static PyTypeObject swigpypacked_type;
  static int type_init = 0;
  if (!type_init) {
    const PyTypeObject tmp = {
#if PY_VERSION_HEX>=0x03000000
      PyVarObject_HEAD_INIT(NULL, 0)
#else
      PyObject_HEAD_INIT(NULL)
      0,                                    /* ob_size */
#endif
      "SwigPyPacked",                       /* tp_name */
      sizeof(SwigPyPacked),                 /* tp_basicsize */
      0,                                    /* tp_itemsize */
      (destructor)SwigPyPacked_dealloc,     /* tp_dealloc */
#if PY_VERSION_HEX < 0x030800b4
      (printfunc)0,                         /*tp_print*/
#else
      (Py_ssize_t)0,                        /*tp_vectorcall_offset*/
#endif
      (getattrfunc)0,                       /* tp_getattr */
      (setattrfunc)0,                       /* tp_setattr */
#if PY_VERSION_HEX>=0x03000000
      0, /* tp_reserved in 3.0.1 */
#else
      (cmpfunc)SwigPyPacked_compare,        /* tp_compare */
#endif
      (reprfunc)SwigPyPacked_repr,          /* tp_repr */
      0,                                    /* tp_as_number */
      0,                                    /* tp_as_sequence */
      0,                                    /* tp_as_mapping */
      (hashfunc)0,                          /* tp_hash */
      (ternaryfunc)0,                       /* tp_call */
      (reprfunc)SwigPyPacked_str,           /* tp_str */
      PyObject_GenericGetAttr,              /* tp_getattro */
      0,                                    /* tp_setattro */
      0,                                    /* tp_as_buffer */
      Py_TPFLAGS_DEFAULT,                   /* tp_flags */
      swigpacked_doc,                       /* tp_doc */
      0,                                    /* tp_traverse */
      0,                                    /* tp_clear */
      0,                                    /* tp_richcompare */
      0,                                    /* tp_weaklistoffset */
      0,                                    /* tp_iter */
      0,                                    /* tp_iternext */
      0,                                    /* tp_methods */
      0,                                    /* tp_members */
      0,                                    /* tp_getset */
      0,                                    /* tp_base */
      0,                                    /* tp_dict */
      0,                                    /* tp_descr_get */
      0,                                    /* tp_descr_set */
      0,                                    /* tp_dictoffset */
      0,                                    /* tp_init */
      0,                                    /* tp_alloc */
      0,                                    /* tp_new */
      0,                                    /* tp_free */
      0,                                    /* tp_is_gc */
      0,                                    /* tp_bases */
      0,                                    /* tp_mro */
      0,                                    /* tp_cache */
      0,                                    /* tp_subclasses */
      0,                                    /* tp_weaklist */
      0,                                    /* tp_del */
      0,                                    /* tp_version_tag */
#if PY_VERSION_HEX >= 0x03040000
      0,                                    /* tp_finalize */
#endif
#if PY_VERSION_HEX >= 0x03080000
      0,                                    /* tp_vectorcall */
#endif
#if (PY_VERSION_HEX >= 0x03080000) && (PY_VERSION_HEX < 0x03090000)
      0,                                    /* tp_print */
#endif
#ifdef COUNT_ALLOCS
      0,                                    /* tp_allocs */
      0,                                    /* tp_frees */
      0,                                    /* tp_maxalloc */
      0,                                    /* tp_prev */
      0                                     /* tp_next */
#endif
    };
    swigpypacked_type = tmp;
    type_init = 1;
    if (PyType_Ready(&swigpypacked_type) != 0)
      return NULL;
  }
  return &swigpypacked_type;
}

SWIGRUNTIME PyObject *
SwigPyPacked_New(void *ptr, size_t size, swig_type_info *ty)
{
  SwigPyPacked *sobj = PyObject_NEW(SwigPyPacked, SwigPyPacked_type());
  if (sobj) {
    void *pack = malloc(size);
    if (pack) {
      memcpy(pack, ptr, size);
      sobj->pack = pack;
      sobj->ty   = ty;
      sobj->size = size;
    } else {
      PyObject_DEL((PyObject *) sobj);
      sobj = 0;
    }
  }
  return (PyObject *) sobj;
}

SWIGRUNTIME swig_type_info *
SwigPyPacked_UnpackData(PyObject *obj, void *ptr, size_t size)
{
  if (SwigPyPacked_Check(obj)) {
    SwigPyPacked *sobj = (SwigPyPacked *)obj;
    if (sobj->size != size) return 0;
    memcpy(ptr, sobj->pack, size);
    return sobj->ty;
  } else {
    return 0;
  }
}

/* -----------------------------------------------------------------------------
 * pointers/data manipulation
 * ----------------------------------------------------------------------------- */

static PyObject *Swig_This_global = NULL;

SWIGRUNTIME PyObject *
SWIG_This(void)
{
  if (Swig_This_global == NULL)
    Swig_This_global = SWIG_Python_str_FromChar("this");
  return Swig_This_global;
}

/* #define SWIG_PYTHON_SLOW_GETSET_THIS */

/* TODO: I don't know how to implement the fast getset in Python 3 right now */
#if PY_VERSION_HEX>=0x03000000
#define SWIG_PYTHON_SLOW_GETSET_THIS 
#endif

SWIGRUNTIME SwigPyObject *
SWIG_Python_GetSwigThis(PyObject *pyobj) 
{
  PyObject *obj;

  if (SwigPyObject_Check(pyobj))
    return (SwigPyObject *) pyobj;

#ifdef SWIGPYTHON_BUILTIN
  (void)obj;
# ifdef PyWeakref_CheckProxy
  if (PyWeakref_CheckProxy(pyobj)) {
    pyobj = PyWeakref_GET_OBJECT(pyobj);
    if (pyobj && SwigPyObject_Check(pyobj))
      return (SwigPyObject*) pyobj;
  }
# endif
  return NULL;
#else

  obj = 0;

#if !defined(SWIG_PYTHON_SLOW_GETSET_THIS)
  if (PyInstance_Check(pyobj)) {
    obj = _PyInstance_Lookup(pyobj, SWIG_This());      
  } else {
    PyObject **dictptr = _PyObject_GetDictPtr(pyobj);
    if (dictptr != NULL) {
      PyObject *dict = *dictptr;
      obj = dict ? PyDict_GetItem(dict, SWIG_This()) : 0;
    } else {
#ifdef PyWeakref_CheckProxy
      if (PyWeakref_CheckProxy(pyobj)) {
	PyObject *wobj = PyWeakref_GET_OBJECT(pyobj);
	return wobj ? SWIG_Python_GetSwigThis(wobj) : 0;
      }
#endif
      obj = PyObject_GetAttr(pyobj,SWIG_This());
      if (obj) {
	Py_DECREF(obj);
      } else {
	if (PyErr_Occurred()) PyErr_Clear();
	return 0;
      }
    }
  }
#else
  obj = PyObject_GetAttr(pyobj,SWIG_This());
  if (obj) {
    Py_DECREF(obj);
  } else {
    if (PyErr_Occurred()) PyErr_Clear();
    return 0;
  }
#endif
  if (obj && !SwigPyObject_Check(obj)) {
    /* a PyObject is called 'this', try to get the 'real this'
       SwigPyObject from it */ 
    return SWIG_Python_GetSwigThis(obj);
  }
  return (SwigPyObject *)obj;
#endif
}

/* Acquire a pointer value */

SWIGRUNTIME int
SWIG_Python_AcquirePtr(PyObject *obj, int own) {
  if (own == SWIG_POINTER_OWN) {
    SwigPyObject *sobj = SWIG_Python_GetSwigThis(obj);
    if (sobj) {
      int oldown = sobj->own;
      sobj->own = own;
      return oldown;
    }
  }
  return 0;
}

/* Convert a pointer value */

SWIGRUNTIME int
SWIG_Python_ConvertPtrAndOwn(PyObject *obj, void **ptr, swig_type_info *ty, int flags, int *own) {
  int res;
  SwigPyObject *sobj;
  int implicit_conv = (flags & SWIG_POINTER_IMPLICIT_CONV) != 0;

  if (!obj)
    return SWIG_ERROR;
  if (obj == Py_None && !implicit_conv) {
    if (ptr)
      *ptr = 0;
    return (flags & SWIG_POINTER_NO_NULL) ? SWIG_NullReferenceError : SWIG_OK;
  }

  res = SWIG_ERROR;

  sobj = SWIG_Python_GetSwigThis(obj);
  if (own)
    *own = 0;
  while (sobj) {
    void *vptr = sobj->ptr;
    if (ty) {
      swig_type_info *to = sobj->ty;
      if (to == ty) {
        /* no type cast needed */
        if (ptr) *ptr = vptr;
        break;
      } else {
        swig_cast_info *tc = SWIG_TypeCheck(to->name,ty);
        if (!tc) {
          sobj = (SwigPyObject *)sobj->next;
        } else {
          if (ptr) {
            int newmemory = 0;
            *ptr = SWIG_TypeCast(tc,vptr,&newmemory);
            if (newmemory == SWIG_CAST_NEW_MEMORY) {
              assert(own); /* badly formed typemap which will lead to a memory leak - it must set and use own to delete *ptr */
              if (own)
                *own = *own | SWIG_CAST_NEW_MEMORY;
            }
          }
          break;
        }
      }
    } else {
      if (ptr) *ptr = vptr;
      break;
    }
  }
  if (sobj) {
    if (((flags & SWIG_POINTER_RELEASE) == SWIG_POINTER_RELEASE) && !sobj->own) {
      res = SWIG_ERROR_RELEASE_NOT_OWNED;
    } else {
      if (own)
        *own = *own | sobj->own;
      if (flags & SWIG_POINTER_DISOWN) {
        sobj->own = 0;
      }
      if (flags & SWIG_POINTER_CLEAR) {
        sobj->ptr = 0;
      }
      res = SWIG_OK;
    }
  } else {
    if (implicit_conv) {
      SwigPyClientData *data = ty ? (SwigPyClientData *) ty->clientdata : 0;
      if (data && !data->implicitconv) {
        PyObject *klass = data->klass;
        if (klass) {
          PyObject *impconv;
          data->implicitconv = 1; /* avoid recursion and call 'explicit' constructors*/
          impconv = SWIG_Python_CallFunctor(klass, obj);
          data->implicitconv = 0;
          if (PyErr_Occurred()) {
            PyErr_Clear();
            impconv = 0;
          }
          if (impconv) {
            SwigPyObject *iobj = SWIG_Python_GetSwigThis(impconv);
            if (iobj) {
              void *vptr;
              res = SWIG_Python_ConvertPtrAndOwn((PyObject*)iobj, &vptr, ty, 0, 0);
              if (SWIG_IsOK(res)) {
                if (ptr) {
                  *ptr = vptr;
                  /* transfer the ownership to 'ptr' */
                  iobj->own = 0;
                  res = SWIG_AddCast(res);
                  res = SWIG_AddNewMask(res);
                } else {
                  res = SWIG_AddCast(res);		    
                }
              }
            }
            Py_DECREF(impconv);
          }
        }
      }
      if (!SWIG_IsOK(res) && obj == Py_None) {
        if (ptr)
          *ptr = 0;
        if (PyErr_Occurred())
          PyErr_Clear();
        res = SWIG_OK;
      }
    }
  }
  return res;
}

/* Convert a function ptr value */

SWIGRUNTIME int
SWIG_Python_ConvertFunctionPtr(PyObject *obj, void **ptr, swig_type_info *ty) {
  if (!PyCFunction_Check(obj)) {
    return SWIG_ConvertPtr(obj, ptr, ty, 0);
  } else {
    void *vptr = 0;
    swig_cast_info *tc;

    /* here we get the method pointer for callbacks */
    const char *doc = (((PyCFunctionObject *)obj) -> m_ml -> ml_doc);
    const char *desc = doc ? strstr(doc, "swig_ptr: ") : 0;
    if (desc)
      desc = ty ? SWIG_UnpackVoidPtr(desc + 10, &vptr, ty->name) : 0;
    if (!desc)
      return SWIG_ERROR;
    tc = SWIG_TypeCheck(desc,ty);
    if (tc) {
      int newmemory = 0;
      *ptr = SWIG_TypeCast(tc,vptr,&newmemory);
      assert(!newmemory); /* newmemory handling not yet implemented */
    } else {
      return SWIG_ERROR;
    }
    return SWIG_OK;
  }
}

/* Convert a packed pointer value */

SWIGRUNTIME int
SWIG_Python_ConvertPacked(PyObject *obj, void *ptr, size_t sz, swig_type_info *ty) {
  swig_type_info *to = SwigPyPacked_UnpackData(obj, ptr, sz);
  if (!to) return SWIG_ERROR;
  if (ty) {
    if (to != ty) {
      /* check type cast? */
      swig_cast_info *tc = SWIG_TypeCheck(to->name,ty);
      if (!tc) return SWIG_ERROR;
    }
  }
  return SWIG_OK;
}  

/* -----------------------------------------------------------------------------
 * Create a new pointer object
 * ----------------------------------------------------------------------------- */

/*
  Create a new instance object, without calling __init__, and set the
  'this' attribute.
*/

SWIGRUNTIME PyObject* 
SWIG_Python_NewShadowInstance(SwigPyClientData *data, PyObject *swig_this)
{
  PyObject *inst = 0;
  PyObject *newraw = data->newraw;
  if (newraw) {
    inst = PyObject_Call(newraw, data->newargs, NULL);
    if (inst) {
#if !defined(SWIG_PYTHON_SLOW_GETSET_THIS)
      PyObject **dictptr = _PyObject_GetDictPtr(inst);
      if (dictptr != NULL) {
        PyObject *dict = *dictptr;
        if (dict == NULL) {
          dict = PyDict_New();
          *dictptr = dict;
        }
        if (dict) {
          PyDict_SetItem(dict, SWIG_This(), swig_this);
        } else{
          Py_DECREF(inst);
          inst = 0;
        }
      }
#else
      if (PyObject_SetAttr(inst, SWIG_This(), swig_this) == -1) {
        Py_DECREF(inst);
        inst = 0;
      }
#endif
    }
  } else {
#if PY_VERSION_HEX >= 0x03000000
    PyObject *empty_args = PyTuple_New(0);
    if (empty_args) {
      PyObject *empty_kwargs = PyDict_New();
      if (empty_kwargs) {
        inst = ((PyTypeObject *)data->newargs)->tp_new((PyTypeObject *)data->newargs, empty_args, empty_kwargs);
        Py_DECREF(empty_kwargs);
        if (inst) {
          if (PyObject_SetAttr(inst, SWIG_This(), swig_this) == -1) {
            Py_DECREF(inst);
            inst = 0;
          } else {
            PyType_Modified(Py_TYPE(inst));
          }
        }
      }
      Py_DECREF(empty_args);
    }
#else
    PyObject *dict = PyDict_New();
    if (dict) {
      PyDict_SetItem(dict, SWIG_This(), swig_this);
      inst = PyInstance_NewRaw(data->newargs, dict);
      Py_DECREF(dict);
    }
#endif
  }
  return inst;
}

SWIGRUNTIME int
SWIG_Python_SetSwigThis(PyObject *inst, PyObject *swig_this)
{
#if !defined(SWIG_PYTHON_SLOW_GETSET_THIS)
  PyObject **dictptr = _PyObject_GetDictPtr(inst);
  if (dictptr != NULL) {
    PyObject *dict = *dictptr;
    if (dict == NULL) {
      dict = PyDict_New();
      *dictptr = dict;
    }
    if (dict) {
      return PyDict_SetItem(dict, SWIG_This(), swig_this);
    } else{
      return -1;
    }
  }
#endif
  return PyObject_SetAttr(inst, SWIG_This(), swig_this);
} 


SWIGINTERN PyObject *
SWIG_Python_InitShadowInstance(PyObject *args) {
  PyObject *obj[2];
  if (!SWIG_Python_UnpackTuple(args, "swiginit", 2, 2, obj)) {
    return NULL;
  } else {
    SwigPyObject *sthis = SWIG_Python_GetSwigThis(obj[0]);
    if (sthis) {
      Py_DECREF(SwigPyObject_append((PyObject*) sthis, obj[1]));
    } else {
      if (SWIG_Python_SetSwigThis(obj[0], obj[1]) != 0)
        return NULL;
    }
    return SWIG_Py_Void();
  }
}

/* Create a new pointer object */

SWIGRUNTIME PyObject *
SWIG_Python_NewPointerObj(PyObject *self, void *ptr, swig_type_info *type, int flags) {
  SwigPyClientData *clientdata;
  PyObject * robj;
  int own;

  if (!ptr)
    return SWIG_Py_Void();

  clientdata = type ? (SwigPyClientData *)(type->clientdata) : 0;
  own = (flags & SWIG_POINTER_OWN) ? SWIG_POINTER_OWN : 0;
  if (clientdata && clientdata->pytype) {
    SwigPyObject *newobj;
    if (flags & SWIG_BUILTIN_TP_INIT) {
      newobj = (SwigPyObject*) self;
      if (newobj->ptr) {
        PyObject *next_self = clientdata->pytype->tp_alloc(clientdata->pytype, 0);
        while (newobj->next)
	  newobj = (SwigPyObject *) newobj->next;
        newobj->next = next_self;
        newobj = (SwigPyObject *)next_self;
#ifdef SWIGPYTHON_BUILTIN
        newobj->dict = 0;
#endif
      }
    } else {
      newobj = PyObject_New(SwigPyObject, clientdata->pytype);
#ifdef SWIGPYTHON_BUILTIN
      if (newobj) {
        newobj->dict = 0;
      }
#endif
    }
    if (newobj) {
      newobj->ptr = ptr;
      newobj->ty = type;
      newobj->own = own;
      newobj->next = 0;
      return (PyObject*) newobj;
    }
    return SWIG_Py_Void();
  }

  assert(!(flags & SWIG_BUILTIN_TP_INIT));

  robj = SwigPyObject_New(ptr, type, own);
  if (robj && clientdata && !(flags & SWIG_POINTER_NOSHADOW)) {
    PyObject *inst = SWIG_Python_NewShadowInstance(clientdata, robj);
    Py_DECREF(robj);
    robj = inst;
  }
  return robj;
}

/* Create a new packed object */

SWIGRUNTIMEINLINE PyObject *
SWIG_Python_NewPackedObj(void *ptr, size_t sz, swig_type_info *type) {
  return ptr ? SwigPyPacked_New((void *) ptr, sz, type) : SWIG_Py_Void();
}

/* -----------------------------------------------------------------------------*
 *  Get type list 
 * -----------------------------------------------------------------------------*/

#ifdef SWIG_LINK_RUNTIME
void *SWIG_ReturnGlobalTypeList(void *);
#endif

static PyObject *Swig_TypeCache_global = NULL;

/* The python cached type query */
SWIGRUNTIME PyObject *
SWIG_Python_TypeCache(void) {
  if (Swig_TypeCache_global == NULL) {
    Swig_TypeCache_global = PyDict_New();
  }
  return Swig_TypeCache_global;
}

SWIGRUNTIME swig_module_info *
SWIG_Python_GetModule(void *SWIGUNUSEDPARM(clientdata)) {
#ifdef SWIG_LINK_RUNTIME
  static void *type_pointer = (void *)0;
  /* first check if module already created */
  if (!type_pointer) {
    type_pointer = SWIG_ReturnGlobalTypeList((void *)0);
  }
#else
  void *type_pointer = PyCapsule_Import(SWIGPY_CAPSULE_NAME, 0);
  if (PyErr_Occurred()) {
    PyErr_Clear();
    type_pointer = (void *)0;
  }
#endif
  return (swig_module_info *) type_pointer;
}


static int interpreter_counter = 0; // how many (sub-)interpreters are using swig_module's types

SWIGRUNTIME void
SWIG_Python_DestroyModule(PyObject *obj)
{
  swig_module_info *swig_module = (swig_module_info *) PyCapsule_GetPointer(obj, SWIGPY_CAPSULE_NAME);
  swig_type_info **types = swig_module->types;
  size_t i;
  if (--interpreter_counter != 0) // another sub-interpreter may still be using the swig_module's types
    return;
  for (i =0; i < swig_module->size; ++i) {
    swig_type_info *ty = types[i];
    if (ty->owndata) {
      SwigPyClientData *data = (SwigPyClientData *) ty->clientdata;
      ty->clientdata = 0;
      if (data) SwigPyClientData_Del(data);
    }
  }
  Py_DECREF(SWIG_This());
  Swig_This_global = NULL;
  Py_DECREF(SWIG_globals());
  Swig_Globals_global = NULL;
  Py_DECREF(SWIG_Python_TypeCache());
  Swig_TypeCache_global = NULL;
  Swig_Capsule_global = NULL;
}

SWIGRUNTIME void
SWIG_Python_SetModule(swig_module_info *swig_module) {
#if PY_VERSION_HEX >= 0x03000000
 /* Add a dummy module object into sys.modules */
  PyObject *module = PyImport_AddModule("swig_runtime_data" SWIG_RUNTIME_VERSION);
#else
  static PyMethodDef swig_empty_runtime_method_table[] = { {NULL, NULL, 0, NULL} }; /* Sentinel */
  PyObject *module = Py_InitModule("swig_runtime_data" SWIG_RUNTIME_VERSION, swig_empty_runtime_method_table);
#endif
  PyObject *pointer = PyCapsule_New((void *) swig_module, SWIGPY_CAPSULE_NAME, SWIG_Python_DestroyModule);
  if (pointer && module) {
    if (PyModule_AddObject(module, SWIGPY_CAPSULE_ATTR_NAME, pointer) == 0) {
      ++interpreter_counter;
      Swig_Capsule_global = pointer;
    } else {
      Py_DECREF(pointer);
    }
  } else {
    Py_XDECREF(pointer);
  }
}

SWIGRUNTIME swig_type_info *
SWIG_Python_TypeQuery(const char *type)
{
  PyObject *cache = SWIG_Python_TypeCache();
  PyObject *key = SWIG_Python_str_FromChar(type); 
  PyObject *obj = PyDict_GetItem(cache, key);
  swig_type_info *descriptor;
  if (obj) {
    descriptor = (swig_type_info *) PyCapsule_GetPointer(obj, NULL);
  } else {
    swig_module_info *swig_module = SWIG_GetModule(0);
    descriptor = SWIG_TypeQueryModule(swig_module, swig_module, type);
    if (descriptor) {
      obj = PyCapsule_New((void*) descriptor, NULL, NULL);
      if (obj) {
        PyDict_SetItem(cache, key, obj);
        Py_DECREF(obj);
      }
    }
  }
  Py_DECREF(key);
  return descriptor;
}

/* 
   For backward compatibility only
*/
#define SWIG_POINTER_EXCEPTION  0
#define SWIG_arg_fail(arg)      SWIG_Python_ArgFail(arg)
#define SWIG_MustGetPtr(p, type, argnum, flags)  SWIG_Python_MustGetPtr(p, type, argnum, flags)

SWIGRUNTIME int
SWIG_Python_AddErrMesg(const char* mesg, int infront)
{  
  if (PyErr_Occurred()) {
    PyObject *type = 0;
    PyObject *value = 0;
    PyObject *traceback = 0;
    PyErr_Fetch(&type, &value, &traceback);
    if (value) {
      PyObject *old_str = PyObject_Str(value);
      const char *tmp = SWIG_Python_str_AsChar(old_str);
      const char *errmesg = tmp ? tmp : "Invalid error message";
      Py_XINCREF(type);
      PyErr_Clear();
      if (infront) {
	PyErr_Format(type, "%s %s", mesg, errmesg);
      } else {
	PyErr_Format(type, "%s %s", errmesg, mesg);
      }
      Py_DECREF(old_str);
    }
    return 1;
  } else {
    return 0;
  }
}
  
SWIGRUNTIME int
SWIG_Python_ArgFail(int argnum)
{
  if (PyErr_Occurred()) {
    /* add information about failing argument */
    char mesg[256];
    PyOS_snprintf(mesg, sizeof(mesg), "argument number %d:", argnum);
    return SWIG_Python_AddErrMesg(mesg, 1);
  } else {
    return 0;
  }
}

SWIGRUNTIMEINLINE const char *
SwigPyObject_GetDesc(PyObject *self)
{
  SwigPyObject *v = (SwigPyObject *)self;
  swig_type_info *ty = v ? v->ty : 0;
  return ty ? ty->str : "";
}

SWIGRUNTIME void
SWIG_Python_TypeError(const char *type, PyObject *obj)
{
  if (type) {
#if defined(SWIG_COBJECT_TYPES)
    if (obj && SwigPyObject_Check(obj)) {
      const char *otype = (const char *) SwigPyObject_GetDesc(obj);
      if (otype) {
	PyErr_Format(PyExc_TypeError, "a '%s' is expected, 'SwigPyObject(%s)' is received",
		     type, otype);
	return;
      }
    } else 
#endif      
    {
      const char *otype = (obj ? obj->ob_type->tp_name : 0); 
      if (otype) {
	PyObject *str = PyObject_Str(obj);
	const char *cstr = str ? SWIG_Python_str_AsChar(str) : 0;
	if (cstr) {
	  PyErr_Format(PyExc_TypeError, "a '%s' is expected, '%s(%s)' is received",
		       type, otype, cstr);
	} else {
	  PyErr_Format(PyExc_TypeError, "a '%s' is expected, '%s' is received",
		       type, otype);
	}
	Py_XDECREF(str);
	return;
      }
    }   
    PyErr_Format(PyExc_TypeError, "a '%s' is expected", type);
  } else {
    PyErr_Format(PyExc_TypeError, "unexpected type is received");
  }
}


/* Convert a pointer value, signal an exception on a type mismatch */
SWIGRUNTIME void *
SWIG_Python_MustGetPtr(PyObject *obj, swig_type_info *ty, int SWIGUNUSEDPARM(argnum), int flags) {
  void *result;
  if (SWIG_Python_ConvertPtr(obj, &result, ty, flags) == -1) {
    PyErr_Clear();
  }
  return result;
}

#ifdef SWIGPYTHON_BUILTIN
SWIGRUNTIME int
SWIG_Python_NonDynamicSetAttr(PyObject *obj, PyObject *name, PyObject *value) {
  PyTypeObject *tp = obj->ob_type;
  PyObject *descr;
  PyObject *encoded_name;
  descrsetfunc f;
  int res = -1;

# ifdef Py_USING_UNICODE
  if (PyString_Check(name)) {
    name = PyUnicode_Decode(PyString_AsString(name), PyString_Size(name), NULL, NULL);
    if (!name)
      return -1;
  } else if (!PyUnicode_Check(name))
# else
  if (!PyString_Check(name))
# endif
  {
    PyErr_Format(PyExc_TypeError, "attribute name must be string, not '%.200s'", name->ob_type->tp_name);
    return -1;
  } else {
    Py_INCREF(name);
  }

  if (!tp->tp_dict) {
    if (PyType_Ready(tp) != 0)
      goto done;
  }

  descr = _PyType_Lookup(tp, name);
  f = NULL;
  if (descr != NULL)
    f = descr->ob_type->tp_descr_set;
  if (!f) {
    if (PyString_Check(name)) {
      encoded_name = name;
      Py_INCREF(name);
    } else {
      encoded_name = PyUnicode_AsUTF8String(name);
      if (!encoded_name)
        goto done;
    }
    PyErr_Format(PyExc_AttributeError, "'%.100s' object has no attribute '%.200s'", tp->tp_name, PyString_AsString(encoded_name));
    Py_DECREF(encoded_name);
  } else {
    res = f(descr, obj, value);
  }
  
  done:
  Py_DECREF(name);
  return res;
}
#endif


#ifdef __cplusplus
}
#endif



#define SWIG_exception_fail(code, msg) do { SWIG_Error(code, msg); SWIG_fail; } while(0) 

#define SWIG_contract_assert(expr, msg) do { if (!(expr)) { SWIG_Error(SWIG_RuntimeError, msg); SWIG_fail; } } while (0) 



  #define SWIG_exception(code, msg) do { SWIG_Error(code, msg); SWIG_fail;; } while(0) 


/* -------- TYPES TABLE (BEGIN) -------- */

#define SWIGTYPE_p_char swig_types[0]
#define SWIGTYPE_p_float swig_types[1]
#define SWIGTYPE_p_sentencepiece__ImmutableNBestSentencePieceText swig_types[2]
#define SWIGTYPE_p_sentencepiece__ImmutableSentencePieceText swig_types[3]
#define SWIGTYPE_p_sentencepiece__ImmutableSentencePieceText_ImmutableSentencePiece swig_types[4]
#define SWIGTYPE_p_sentencepiece__SentenceIterator swig_types[5]
#define SWIGTYPE_p_sentencepiece__SentencePieceNormalizer swig_types[6]
#define SWIGTYPE_p_sentencepiece__SentencePieceProcessor swig_types[7]
#define SWIGTYPE_p_sentencepiece__SentencePieceTrainer swig_types[8]
#define SWIGTYPE_p_std__string swig_types[9]
#define SWIGTYPE_p_std__unordered_mapT_std__string_std__string_t swig_types[10]
#define SWIGTYPE_p_std__vectorT_absl__string_view_t swig_types[11]
#define SWIGTYPE_p_std__vectorT_int_t swig_types[12]
#define SWIGTYPE_p_std__vectorT_std__vectorT_absl__string_view_t_t swig_types[13]
#define SWIGTYPE_p_std__vectorT_std__vectorT_int_t_t swig_types[14]
static swig_type_info *swig_types[16];
static swig_module_info swig_module = {swig_types, 15, 0, 0, 0, 0};
#define SWIG_TypeQuery(name) SWIG_TypeQueryModule(&swig_module, &swig_module, name)
#define SWIG_MangledTypeQuery(name) SWIG_MangledTypeQueryModule(&swig_module, &swig_module, name)

/* -------- TYPES TABLE (END) -------- */

#ifdef SWIG_TypeQuery
# undef SWIG_TypeQuery
#endif
#define SWIG_TypeQuery SWIG_Python_TypeQuery

/*-----------------------------------------------
              @(target):= _sentencepiece.so
  ------------------------------------------------*/
#if PY_VERSION_HEX >= 0x03000000
#  define SWIG_init    PyInit__sentencepiece

#else
#  define SWIG_init    init_sentencepiece

#endif
#define SWIG_name    "_sentencepiece"

#ifdef __cplusplus
#include <utility>
/* SwigValueWrapper is described in swig.swg */
template<typename T> class SwigValueWrapper {
  struct SwigSmartPointer {
    T *ptr;
    SwigSmartPointer(T *p) : ptr(p) { }
    ~SwigSmartPointer() { delete ptr; }
    SwigSmartPointer& operator=(SwigSmartPointer& rhs) { T* oldptr = ptr; ptr = 0; delete oldptr; ptr = rhs.ptr; rhs.ptr = 0; return *this; }
    void reset(T *p) { T* oldptr = ptr; ptr = 0; delete oldptr; ptr = p; }
  } pointer;
  SwigValueWrapper& operator=(const SwigValueWrapper<T>& rhs);
  SwigValueWrapper(const SwigValueWrapper<T>& rhs);
public:
  SwigValueWrapper() : pointer(0) { }
  SwigValueWrapper& operator=(const T& t) { SwigSmartPointer tmp(new T(t)); pointer = tmp; return *this; }
#if __cplusplus >=201103L
  SwigValueWrapper& operator=(T&& t) { SwigSmartPointer tmp(new T(std::move(t))); pointer = tmp; return *this; }
  operator T&&() const { return std::move(*pointer.ptr); }
#else
  operator T&() const { return *pointer.ptr; }
#endif
  T *operator&() const { return pointer.ptr; }
  static void reset(SwigValueWrapper& t, T *p) { t.pointer.reset(p); }
};

/*
 * SwigValueInit() is a generic initialisation solution as the following approach:
 * 
 *       T c_result = T();
 * 
 * doesn't compile for all types for example:
 * 
 *       unsigned int c_result = unsigned int();
 */
template <typename T> T SwigValueInit() {
  return T();
}

#if __cplusplus >=201103L
# define SWIG_STD_MOVE(OBJ) std::move(OBJ)
#else
# define SWIG_STD_MOVE(OBJ) OBJ
#endif

#endif


#define SWIG_as_voidptr(a) const_cast< void * >(static_cast< const void * >(a)) 
#define SWIG_as_voidptrptr(a) ((void)SWIG_as_voidptr(*a),reinterpret_cast< void** >(a)) 


#include <stdexcept>


namespace swig {
  class SwigPtr_PyObject {
  protected:
    PyObject *_obj;

  public:
    SwigPtr_PyObject() :_obj(0)
    {
    }

    SwigPtr_PyObject(const SwigPtr_PyObject& item) : _obj(item._obj)
    {
      SWIG_PYTHON_THREAD_BEGIN_BLOCK;
      Py_XINCREF(_obj);      
      SWIG_PYTHON_THREAD_END_BLOCK;
    }
    
    SwigPtr_PyObject(PyObject *obj, bool initial_ref = true) :_obj(obj)
    {
      if (initial_ref) {
        SWIG_PYTHON_THREAD_BEGIN_BLOCK;
        Py_XINCREF(_obj);
        SWIG_PYTHON_THREAD_END_BLOCK;
      }
    }
    
    SwigPtr_PyObject & operator=(const SwigPtr_PyObject& item) 
    {
      SWIG_PYTHON_THREAD_BEGIN_BLOCK;
      Py_XINCREF(item._obj);
      Py_XDECREF(_obj);
      _obj = item._obj;
      SWIG_PYTHON_THREAD_END_BLOCK;
      return *this;      
    }
    
    ~SwigPtr_PyObject() 
    {
      SWIG_PYTHON_THREAD_BEGIN_BLOCK;
      Py_XDECREF(_obj);
      SWIG_PYTHON_THREAD_END_BLOCK;
    }
    
    operator PyObject *() const
    {
      return _obj;
    }

    PyObject *operator->() const
    {
      return _obj;
    }
  };
}


namespace swig {
  struct SwigVar_PyObject : SwigPtr_PyObject {
    SwigVar_PyObject(PyObject* obj = 0) : SwigPtr_PyObject(obj, false) { }
    
    SwigVar_PyObject & operator = (PyObject* obj)
    {
      Py_XDECREF(_obj);
      _obj = obj;
      return *this;      
    }
  };
}



#include <atomic>
#include <iostream>
#include <algorithm>
#include <functional>
#include <limits>
#include <cmath>
#include <thread>
#include <vector>
#include <sentencepiece_processor.h>
#include <sentencepiece_trainer.h>

namespace {
PyObject* kUnicodeInput = reinterpret_cast<PyObject* >(0x1);
PyObject* kByteInput = reinterpret_cast<PyObject* >(0x2);

using BytesArray = std::vector<sentencepiece::util::bytes>;

inline void ReleaseResultObject(PyObject *obj) {
  if (obj != nullptr && obj != kUnicodeInput && obj != kByteInput) {
    Py_XDECREF(obj);
  }
}

class PyInputString {
 public:
  explicit PyInputString(PyObject* obj) {
    if (PyUnicode_Check(obj)) {
      str_ = const_cast<char *>(PyUnicode_AsUTF8AndSize(obj, &size_));
      input_type_ = kUnicodeInput;
    } else if (PyBytes_Check(obj)) {
      PyBytes_AsStringAndSize(obj, &str_, &size_);
      input_type_ = kByteInput;
    } else {
      str_ = nullptr;
    }
  }
  absl::string_view str() const { return absl::string_view(data(), size()); }
  const char* data() const { return str_; }
  Py_ssize_t size() const { return size_; }
  bool IsAvalable() const { return str_ != nullptr; }
  PyObject *input_type() const { return input_type_; }

  static bool IsUnicode(PyObject *resultobj) {
    return (resultobj == nullptr || resultobj == kUnicodeInput);
  }

 private:
  PyObject* input_type_ = nullptr;
  char* str_ = nullptr;
  Py_ssize_t size_ = 0;
};

PyObject* MakePyOutputString(const std::string& output,
                             PyObject *resultobj) {
  if (PyInputString::IsUnicode(resultobj)) {
    return PyUnicode_FromStringAndSize(output.data(), output.size());
  }
  return PyBytes_FromStringAndSize(output.data(), output.size());
}

PyObject* MakePyOutputBytes(const sentencepiece::util::bytes& output) {
  return PyBytes_FromStringAndSize(output.data(), output.size());
}

int ToSwigError(sentencepiece::util::StatusCode code) {
  switch (code) {
    case sentencepiece::util::StatusCode::kNotFound:
      return SWIG_IOError;
    case sentencepiece::util::StatusCode::kOutOfRange:
      return SWIG_IndexError;
    case sentencepiece::util::StatusCode::kInvalidArgument:
      return SWIG_SyntaxError;
    default:
      return SWIG_RuntimeError;
  }
  return SWIG_RuntimeError;
}

class PySentenceIterator : public sentencepiece::SentenceIterator {
  public:
  PySentenceIterator(PyObject *iter) : iter_(iter) {
    item_ = PyIter_Next(iter_);
    CopyValue();
  }

  ~PySentenceIterator() {
   // Py_XDECREF(iter_);
  }

  bool done() const override {
    return item_ == nullptr;
  }

  void Next() override {
    item_ = PyIter_Next(iter_);
    CopyValue();
  }

  const std::string &value() const override {
    return value_;
  }

  sentencepiece::util::Status status() const override {
    return status_;
  }

  private:
   void CopyValue() {
     if (item_ == nullptr) return;
     const PyInputString ustring(item_);
     if (ustring.IsAvalable()) {
       const char *data = ustring.data();
       size_t size = ustring.size();
       while (size > 0) {
         if (data[size - 1] == '\r' || data[size - 1] == '\n')
           --size;
         else
           break;
       }
       value_.assign(data, size);
     } else {
       status_ = sentencepiece::util::Status(sentencepiece::util::StatusCode::kInternal,
                                             "Not a string.");
     }
     Py_XDECREF(item_);
   }
   PyObject *iter_ = nullptr;
   PyObject *item_ = nullptr;
   std::string value_;
   sentencepiece::util::Status status_;
};

inline void RewriteIds(const sentencepiece::SentencePieceProcessor &sp,
                       std::vector<int> *ids,
                       bool add_bos, bool add_eos, bool reverse, bool emit_unk_piece) {
  if (!add_bos && !add_eos && !reverse) return;
  if (reverse) std::reverse(ids->begin(), ids->end());
  if (add_bos) ids->insert(ids->begin(), sp.bos_id());
  if (add_eos) ids->push_back(sp.eos_id());
}

inline void RewriteIds(const sentencepiece::SentencePieceProcessor &sp,
                       std::vector<std::string> *pieces,
                       bool add_bos, bool add_eos, bool reverse, bool emit_unk_piece) {
  if (!add_bos && !add_eos && !reverse && !emit_unk_piece) return;
  if (reverse) std::reverse(pieces->begin(), pieces->end());
  if (add_bos) pieces->insert(pieces->begin(), sp.IdToPiece(sp.bos_id()));
  if (add_eos) pieces->push_back(sp.IdToPiece(sp.eos_id()));
  if (emit_unk_piece) {
    const auto &unk = sp.IdToPiece(sp.unk_id());
    for (auto &piece : *pieces) {
      const int id = sp.PieceToId(piece);
      if (id == sp.unk_id()) {
        piece = unk;
      }
    }
  }
}

inline void RewriteIds(const sentencepiece::SentencePieceProcessor &sp,
                       sentencepiece::util::bytes *proto,
                       bool add_bos, bool add_eos, bool reverse, bool emit_unk_piece) {
  if (add_bos || add_eos || reverse || emit_unk_piece) {
    throw sentencepiece::util::Status(
        sentencepiece::util::StatusCode::kUnimplemented,
        "add_bos, add_eos, reverse, and emit_unk_piece is not supported in proto API");
  }
}

inline void RewriteIds(const sentencepiece::SentencePieceProcessor &sp,
                       sentencepiece::ImmutableSentencePieceText *proto,
                       bool add_bos, bool add_eos, bool reverse, bool emit_unk_piece) {
  if (add_bos || add_eos || reverse || emit_unk_piece) {
    throw sentencepiece::util::Status(
        sentencepiece::util::StatusCode::kUnimplemented,
        "add_bos, add_eos, reverse, and emit_unk_piece is not supported in proto API");
  }
}

inline void CheckIds(const std::vector<int> &ids, int num_pieces) {
  for (int id : ids) {
    if (id < 0 || id >= num_pieces) {
      throw sentencepiece::util::Status(
          sentencepiece::util::StatusCode::kOutOfRange,
          "piece id is out of range.");
    }
  }
}

inline void CheckIds(const std::vector<absl::string_view> &ids, int num_pieces) {}

template <typename T>
inline void ConvertToUnicodeSpans(T *proto) {}

template <>
inline void ConvertToUnicodeSpans(sentencepiece::ImmutableSentencePieceText *proto) {
  proto->ConvertToUnicodeSpans();
}

template <>
inline void ConvertToUnicodeSpans(sentencepiece::ImmutableNBestSentencePieceText *proto) {
  proto->ConvertToUnicodeSpans();
}

class ThreadPool {
 public:
  explicit ThreadPool(size_t request_size) :
    request_size_(request_size) {}

  virtual ~ThreadPool() {
    for (auto &task : tasks_) {
      task.join();
    }
  }

  void Schedule(std::function<void()> closure) {
    static constexpr size_t kMinThreadSize = 2;
    if (request_size_ < kMinThreadSize) {
      closure();
    } else {
      tasks_.emplace_back(closure);
    }
  }

 private:
  size_t request_size_ = 0;
  std::vector<std::thread> tasks_;
};

template <typename T>
inline void InitNumThreads(const std::vector<T> &ins, int *num_threads) {
  if (*num_threads < 0) {
    *num_threads = std::thread::hardware_concurrency();
  }
  *num_threads = std::max<int>(1,
                               std::min<int>({*num_threads,
                                     static_cast<int>(ins.size()), 256}));
}

#define DEFINE_ENCODE_BATCH_FUNC_IMPL(FuncName, InType, OutType)        \
  std::vector<OutType> outs(ins.size());                                \
  InitNumThreads(ins, &num_threads);                                    \
  {                                                                     \
    ThreadPool pool(ins.size());                                        \
    std::atomic<size_t> index = 0;                                      \
    for (int n = 0;  n < num_threads; ++n) {                            \
      pool.Schedule([&]() {                                             \
          size_t i = 0;                                                 \
          while ((i = std::atomic_fetch_add(&index, 1)) < outs.size()) { \
            auto out = enable_sampling ?                                \
                       self->Sample##FuncName(ins[i],                   \
                                              nbest_size, alpha) :      \
                       self->FuncName(ins[i]);                          \
            RewriteIds(*self, &out, add_bos, add_eos, reverse,          \
                       emit_unk_piece);                                 \
            ConvertToUnicodeSpans(&out);                                \
            outs[i] = std::move(out);                                   \
          }                                                             \
        });                                                             \
    }                                                                   \
  }                                                                     \
  return outs;

#define DEFINE_DECODE_BATCH_FUNC_IMPL(FuncName, InType, OutType)        \
  std::vector<OutType> outs(ins.size());                                \
  InitNumThreads(ins, &num_threads);                                    \
  {                                                                     \
    std::atomic<size_t> index = 0;                                      \
    ThreadPool pool(ins.size());                                        \
    for (int n = 0;  n < num_threads; ++n) {                            \
      pool.Schedule([&]() {                                             \
          size_t i = 0;                                                 \
          while ((i = std::atomic_fetch_add(&index, 1)) < outs.size()) { \
            CheckIds(ins[i], self->GetPieceSize());                     \
            auto out = self->FuncName(ins[i]);                          \
            ConvertToUnicodeSpans(&out);                                \
            outs[i] = std::move(out);                                   \
          }                                                             \
        });                                                             \
    }                                                                   \
  }                                                                     \
  return outs;

}  // namespace


SWIGINTERNINLINE PyObject*
  SWIG_From_unsigned_SS_int  (unsigned int value)
{
  return PyInt_FromSize_t((size_t) value);
}

SWIGINTERN sentencepiece::util::bytes const &sentencepiece_ImmutableSentencePieceText_ImmutableSentencePiece__surface_as_bytes(sentencepiece::ImmutableSentencePieceText_ImmutableSentencePiece const *self){
    return self->surface();
  }
SWIGINTERN sentencepiece::util::bytes const &sentencepiece_ImmutableSentencePieceText_ImmutableSentencePiece__piece_as_bytes(sentencepiece::ImmutableSentencePieceText_ImmutableSentencePiece const *self){
    return self->piece();
  }

  #define SWIG_From_long   PyInt_FromLong 


SWIGINTERNINLINE PyObject* 
SWIG_From_unsigned_SS_long  (unsigned long value)
{
  return (value > LONG_MAX) ?
    PyLong_FromUnsignedLong(value) : PyInt_FromLong(static_cast< long >(value));
}


#include <limits.h>
#if !defined(SWIG_NO_LLONG_MAX)
# if !defined(LLONG_MAX) && defined(__GNUC__) && defined (__LONG_LONG_MAX__)
#   define LLONG_MAX __LONG_LONG_MAX__
#   define LLONG_MIN (-LLONG_MAX - 1LL)
#   define ULLONG_MAX (LLONG_MAX * 2ULL + 1ULL)
# endif
#endif


#if defined(LLONG_MAX) && !defined(SWIG_LONG_LONG_AVAILABLE)
#  define SWIG_LONG_LONG_AVAILABLE
#endif


#ifdef SWIG_LONG_LONG_AVAILABLE
SWIGINTERNINLINE PyObject* 
SWIG_From_unsigned_SS_long_SS_long  (unsigned long long value)
{
  return (value > LONG_MAX) ?
    PyLong_FromUnsignedLongLong(value) : PyInt_FromLong(static_cast< long >(value));
}
#endif


SWIGINTERNINLINE PyObject *
SWIG_From_size_t  (size_t value)
{    
#ifdef SWIG_LONG_LONG_AVAILABLE
  if (sizeof(size_t) <= sizeof(unsigned long)) {
#endif
    return SWIG_From_unsigned_SS_long  (static_cast< unsigned long >(value));
#ifdef SWIG_LONG_LONG_AVAILABLE
  } else {
    /* assume sizeof(size_t) <= sizeof(unsigned long long) */
    return SWIG_From_unsigned_SS_long_SS_long  (static_cast< unsigned long long >(value));
  }
#endif
}


SWIGINTERN int
SWIG_AsVal_double (PyObject *obj, double *val)
{
  int res = SWIG_TypeError;
  if (PyFloat_Check(obj)) {
    if (val) *val = PyFloat_AsDouble(obj);
    return SWIG_OK;
#if PY_VERSION_HEX < 0x03000000
  } else if (PyInt_Check(obj)) {
    if (val) *val = (double) PyInt_AsLong(obj);
    return SWIG_OK;
#endif
  } else if (PyLong_Check(obj)) {
    double v = PyLong_AsDouble(obj);
    if (!PyErr_Occurred()) {
      if (val) *val = v;
      return SWIG_OK;
    } else {
      PyErr_Clear();
    }
  }
#ifdef SWIG_PYTHON_CAST_MODE
  {
    int dispatch = 0;
    double d = PyFloat_AsDouble(obj);
    if (!PyErr_Occurred()) {
      if (val) *val = d;
      return SWIG_AddCast(SWIG_OK);
    } else {
      PyErr_Clear();
    }
    if (!dispatch) {
      long v = PyLong_AsLong(obj);
      if (!PyErr_Occurred()) {
	if (val) *val = v;
	return SWIG_AddCast(SWIG_AddCast(SWIG_OK));
      } else {
	PyErr_Clear();
      }
    }
  }
#endif
  return res;
}


#include <float.h>


#include <math.h>


SWIGINTERNINLINE int
SWIG_CanCastAsInteger(double *d, double min, double max) {
  double x = *d;
  if ((min <= x && x <= max)) {
   double fx = floor(x);
   double cx = ceil(x);
   double rd =  ((x - fx) < 0.5) ? fx : cx; /* simple rint */
   if ((errno == EDOM) || (errno == ERANGE)) {
     errno = 0;
   } else {
     double summ, reps, diff;
     if (rd < x) {
       diff = x - rd;
     } else if (rd > x) {
       diff = rd - x;
     } else {
       return 1;
     }
     summ = rd + x;
     reps = diff/summ;
     if (reps < 8*DBL_EPSILON) {
       *d = rd;
       return 1;
     }
   }
  }
  return 0;
}


SWIGINTERN int
SWIG_AsVal_long (PyObject *obj, long* val)
{
#if PY_VERSION_HEX < 0x03000000
  if (PyInt_Check(obj)) {
    if (val) *val = PyInt_AsLong(obj);
    return SWIG_OK;
  } else
#endif
  if (PyLong_Check(obj)) {
    long v = PyLong_AsLong(obj);
    if (!PyErr_Occurred()) {
      if (val) *val = v;
      return SWIG_OK;
    } else {
      PyErr_Clear();
      return SWIG_OverflowError;
    }
  }
#ifdef SWIG_PYTHON_CAST_MODE
  {
    int dispatch = 0;
    long v = PyInt_AsLong(obj);
    if (!PyErr_Occurred()) {
      if (val) *val = v;
      return SWIG_AddCast(SWIG_OK);
    } else {
      PyErr_Clear();
    }
    if (!dispatch) {
      double d;
      int res = SWIG_AddCast(SWIG_AsVal_double (obj,&d));
      if (SWIG_IsOK(res) && SWIG_CanCastAsInteger(&d, LONG_MIN, LONG_MAX)) {
	if (val) *val = (long)(d);
	return res;
      }
    }
  }
#endif
  return SWIG_TypeError;
}


SWIGINTERN int
SWIG_AsVal_int (PyObject * obj, int *val)
{
  long v;
  int res = SWIG_AsVal_long (obj, &v);
  if (SWIG_IsOK(res)) {
    if ((v < INT_MIN || v > INT_MAX)) {
      return SWIG_OverflowError;
    } else {
      if (val) *val = static_cast< int >(v);
    }
  }  
  return res;
}


  #define SWIG_From_double   PyFloat_FromDouble 


SWIGINTERNINLINE PyObject *
SWIG_From_float  (float value)
{    
  return SWIG_From_double  (value);
}

SWIGINTERN sentencepiece::util::bytes const &sentencepiece_ImmutableSentencePieceText__text_as_bytes(sentencepiece::ImmutableSentencePieceText const *self){
    return self->text();
  }

SWIGINTERN swig_type_info*
SWIG_pchar_descriptor(void)
{
  static int init = 0;
  static swig_type_info* info = 0;
  if (!init) {
    info = SWIG_TypeQuery("_p_char");
    init = 1;
  }
  return info;
}


SWIGINTERN int
SWIG_AsCharPtrAndSize(PyObject *obj, char** cptr, size_t* psize, int *alloc)
{
#if PY_VERSION_HEX>=0x03000000
#if defined(SWIG_PYTHON_STRICT_BYTE_CHAR)
  if (PyBytes_Check(obj))
#else
  if (PyUnicode_Check(obj))
#endif
#else  
  if (PyString_Check(obj))
#endif
  {
    char *cstr; Py_ssize_t len;
    int ret = SWIG_OK;
#if PY_VERSION_HEX>=0x03000000
#if !defined(SWIG_PYTHON_STRICT_BYTE_CHAR)
    if (!alloc && cptr) {
        /* We can't allow converting without allocation, since the internal
           representation of string in Python 3 is UCS-2/UCS-4 but we require
           a UTF-8 representation.
           TODO(bhy) More detailed explanation */
        return SWIG_RuntimeError;
    }
    obj = PyUnicode_AsUTF8String(obj);
    if (!obj)
      return SWIG_TypeError;
    if (alloc)
      *alloc = SWIG_NEWOBJ;
#endif
    if (PyBytes_AsStringAndSize(obj, &cstr, &len) == -1)
      return SWIG_TypeError;
#else
    if (PyString_AsStringAndSize(obj, &cstr, &len) == -1)
      return SWIG_TypeError;
#endif
    if (cptr) {
      if (alloc) {
	if (*alloc == SWIG_NEWOBJ) {
	  *cptr = reinterpret_cast< char* >(memcpy(new char[len + 1], cstr, sizeof(char)*(len + 1)));
	  *alloc = SWIG_NEWOBJ;
	} else {
	  *cptr = cstr;
	  *alloc = SWIG_OLDOBJ;
	}
      } else {
#if PY_VERSION_HEX>=0x03000000
#if defined(SWIG_PYTHON_STRICT_BYTE_CHAR)
	*cptr = PyBytes_AsString(obj);
#else
	assert(0); /* Should never reach here with Unicode strings in Python 3 */
#endif
#else
	*cptr = SWIG_Python_str_AsChar(obj);
        if (!*cptr)
          ret = SWIG_TypeError;
#endif
      }
    }
    if (psize) *psize = len + 1;
#if PY_VERSION_HEX>=0x03000000 && !defined(SWIG_PYTHON_STRICT_BYTE_CHAR)
    Py_XDECREF(obj);
#endif
    return ret;
  } else {
#if defined(SWIG_PYTHON_2_UNICODE)
#if defined(SWIG_PYTHON_STRICT_BYTE_CHAR)
#error "Cannot use both SWIG_PYTHON_2_UNICODE and SWIG_PYTHON_STRICT_BYTE_CHAR at once"
#endif
#if PY_VERSION_HEX<0x03000000
    if (PyUnicode_Check(obj)) {
      char *cstr; Py_ssize_t len;
      if (!alloc && cptr) {
        return SWIG_RuntimeError;
      }
      obj = PyUnicode_AsUTF8String(obj);
      if (!obj)
        return SWIG_TypeError;
      if (PyString_AsStringAndSize(obj, &cstr, &len) != -1) {
        if (cptr) {
          if (alloc) *alloc = SWIG_NEWOBJ;
          *cptr = reinterpret_cast< char* >(memcpy(new char[len + 1], cstr, sizeof(char)*(len + 1)));
        }
        if (psize) *psize = len + 1;

        Py_XDECREF(obj);
        return SWIG_OK;
      } else {
        Py_XDECREF(obj);
      }
    }
#endif
#endif

    swig_type_info* pchar_descriptor = SWIG_pchar_descriptor();
    if (pchar_descriptor) {
      void* vptr = 0;
      if (SWIG_ConvertPtr(obj, &vptr, pchar_descriptor, 0) == SWIG_OK) {
	if (cptr) *cptr = (char *) vptr;
	if (psize) *psize = vptr ? (strlen((char *)vptr) + 1) : 0;
	if (alloc) *alloc = SWIG_OLDOBJ;
	return SWIG_OK;
      }
    }
  }
  return SWIG_TypeError;
}





/* Getting isfinite working pre C99 across multiple platforms is non-trivial. Users can provide SWIG_isfinite on older platforms. */
#ifndef SWIG_isfinite
/* isfinite() is a macro for C99 */
# if defined(isfinite)
#  define SWIG_isfinite(X) (isfinite(X))
# elif defined(__cplusplus) && __cplusplus >= 201103L
/* Use a template so that this works whether isfinite() is std::isfinite() or
 * in the global namespace.  The reality seems to vary between compiler
 * versions.
 *
 * Make sure namespace std exists to avoid compiler warnings.
 *
 * extern "C++" is required as this fragment can end up inside an extern "C" { } block
 */
namespace std { }
extern "C++" template<typename T>
inline int SWIG_isfinite_func(T x) {
  using namespace std;
  return isfinite(x);
}
#  define SWIG_isfinite(X) (SWIG_isfinite_func(X))
# elif defined(__GNUC__) && (__GNUC__ > 4 || (__GNUC__ == 4 && __GNUC_MINOR__ >= 2))
#  define SWIG_isfinite(X) (__builtin_isfinite(X))
# elif defined(_MSC_VER)
#  define SWIG_isfinite(X) (_finite(X))
# elif defined(__sun) && defined(__SVR4)
#  include <ieeefp.h>
#  define SWIG_isfinite(X) (finite(X))
# endif
#endif


/* Accept infinite as a valid float value unless we are unable to check if a value is finite */
#ifdef SWIG_isfinite
# define SWIG_Float_Overflow_Check(X) ((X < -FLT_MAX || X > FLT_MAX) && SWIG_isfinite(X))
#else
# define SWIG_Float_Overflow_Check(X) ((X < -FLT_MAX || X > FLT_MAX))
#endif


SWIGINTERN int
SWIG_AsVal_float (PyObject * obj, float *val)
{
  double v;
  int res = SWIG_AsVal_double (obj, &v);
  if (SWIG_IsOK(res)) {
    if (SWIG_Float_Overflow_Check(v)) {
      return SWIG_OverflowError;
    } else {
      if (val) *val = static_cast< float >(v);
    }
  }  
  return res;
}


SWIGINTERNINLINE PyObject*
  SWIG_From_int  (int value)
{
  return PyInt_FromLong((long) value);
}


SWIGINTERNINLINE PyObject*
  SWIG_From_bool  (bool value)
{
  return PyBool_FromLong(value ? 1 : 0);
}

SWIGINTERN sentencepiece::util::Status sentencepiece_SentencePieceProcessor_LoadFromFile(sentencepiece::SentencePieceProcessor *self,absl::string_view arg){
    return self->Load(arg);
  }

SWIGINTERN int
SWIG_AsVal_bool (PyObject *obj, bool *val)
{
  int r;
  if (!PyBool_Check(obj))
    return SWIG_ERROR;
  r = PyObject_IsTrue(obj);
  if (r == -1)
    return SWIG_ERROR;
  if (val) *val = r ? true : false;
  return SWIG_OK;
}

SWIGINTERN std::vector< int > sentencepiece_SentencePieceProcessor__EncodeAsIds(sentencepiece::SentencePieceProcessor const *self,absl::string_view text,bool enable_sampling,int nbest_size,float alpha,bool add_bos,bool add_eos,bool reverse,bool emit_unk_piece){
    auto ids = enable_sampling ?
               self->SampleEncodeAsIds(text, nbest_size, alpha) :
               self->EncodeAsIds(text);
    RewriteIds(*self, &ids, add_bos, add_eos, reverse, emit_unk_piece);
    return ids;
  }
SWIGINTERN std::vector< std::string > sentencepiece_SentencePieceProcessor__EncodeAsPieces(sentencepiece::SentencePieceProcessor const *self,absl::string_view text,bool enable_sampling,int nbest_size,float alpha,bool add_bos,bool add_eos,bool reverse,bool emit_unk_piece){
    auto pieces = enable_sampling ?
                  self->SampleEncodeAsPieces(text, nbest_size, alpha) :
                  self->EncodeAsPieces(text);
    RewriteIds(*self, &pieces, add_bos, add_eos, reverse, emit_unk_piece);
    return pieces;
  }
SWIGINTERN sentencepiece::util::bytes sentencepiece_SentencePieceProcessor__EncodeAsSerializedProto(sentencepiece::SentencePieceProcessor const *self,absl::string_view text,bool enable_sampling,int nbest_size,float alpha,bool add_bos,bool add_eos,bool reverse,bool emit_unk_piece){
    auto proto = enable_sampling ?
                 self->SampleEncodeAsSerializedProto(text, nbest_size, alpha) :
                 self->EncodeAsSerializedProto(text);
    RewriteIds(*self, &proto, add_bos, add_eos, reverse, emit_unk_piece);
    return proto;
  }
SWIGINTERN sentencepiece::ImmutableSentencePieceText sentencepiece_SentencePieceProcessor__EncodeAsImmutableProto(sentencepiece::SentencePieceProcessor const *self,absl::string_view text,bool enable_sampling,int nbest_size,float alpha,bool add_bos,bool add_eos,bool reverse,bool emit_unk_piece){
    auto proto = enable_sampling ?
                 self->SampleEncodeAsImmutableProto(text, nbest_size, alpha) :
                 self->EncodeAsImmutableProto(text);
    proto.ConvertToUnicodeSpans();
    RewriteIds(*self, &proto, add_bos, add_eos, reverse, emit_unk_piece);
    return proto;
  }
SWIGINTERN std::vector< std::vector< int > > sentencepiece_SentencePieceProcessor__EncodeAsIdsBatch(sentencepiece::SentencePieceProcessor const *self,std::vector< absl::string_view > const &ins,int num_threads,bool enable_sampling,int nbest_size,float alpha,bool add_bos,bool add_eos,bool reverse,bool emit_unk_piece){
    DEFINE_ENCODE_BATCH_FUNC_IMPL(EncodeAsIds,
                                  absl::string_view, std::vector<int>);
  }
SWIGINTERN std::vector< std::vector< std::string > > sentencepiece_SentencePieceProcessor__EncodeAsPiecesBatch(sentencepiece::SentencePieceProcessor const *self,std::vector< absl::string_view > const &ins,int num_threads,bool enable_sampling,int nbest_size,float alpha,bool add_bos,bool add_eos,bool reverse,bool emit_unk_piece){
    DEFINE_ENCODE_BATCH_FUNC_IMPL(EncodeAsPieces,
                                  absl::string_view, std::vector<std::string>);
  }
SWIGINTERN BytesArray sentencepiece_SentencePieceProcessor__EncodeAsSerializedProtoBatch(sentencepiece::SentencePieceProcessor const *self,std::vector< absl::string_view > const &ins,int num_threads,bool enable_sampling,int nbest_size,float alpha,bool add_bos,bool add_eos,bool reverse,bool emit_unk_piece){
    DEFINE_ENCODE_BATCH_FUNC_IMPL(EncodeAsSerializedProto,
                                  absl::string_view,
                                  sentencepiece::util::bytes);
  }
SWIGINTERN std::vector< sentencepiece::ImmutableSentencePieceText > sentencepiece_SentencePieceProcessor__EncodeAsImmutableProtoBatch(sentencepiece::SentencePieceProcessor const *self,std::vector< absl::string_view > const &ins,int num_threads,bool enable_sampling,int nbest_size,float alpha,bool add_bos,bool add_eos,bool reverse,bool emit_unk_piece){
    DEFINE_ENCODE_BATCH_FUNC_IMPL(EncodeAsImmutableProto,
                                  absl::string_view,
                                  sentencepiece::ImmutableSentencePieceText);
  }
SWIGINTERN std::string sentencepiece_SentencePieceProcessor__DecodeIds(sentencepiece::SentencePieceProcessor const *self,std::vector< int > const &ids){
    CheckIds(ids, self->GetPieceSize());
    return self->DecodeIds(ids);
  }
SWIGINTERN sentencepiece::util::bytes sentencepiece_SentencePieceProcessor__DecodeIdsAsBytes(sentencepiece::SentencePieceProcessor const *self,std::vector< int > const &ids){
    CheckIds(ids, self->GetPieceSize());
    return self->DecodeIds(ids);
  }
SWIGINTERN std::string sentencepiece_SentencePieceProcessor__DecodePieces(sentencepiece::SentencePieceProcessor const *self,std::vector< absl::string_view > const &pieces){
    return self->DecodePieces(pieces);
  }
SWIGINTERN sentencepiece::util::bytes sentencepiece_SentencePieceProcessor__DecodeIdsAsSerializedProto(sentencepiece::SentencePieceProcessor const *self,std::vector< int > const &ids){
    CheckIds(ids, self->GetPieceSize());
    return self->DecodeIdsAsSerializedProto(ids);
  }
SWIGINTERN sentencepiece::util::bytes sentencepiece_SentencePieceProcessor__DecodePiecesAsSerializedProto(sentencepiece::SentencePieceProcessor const *self,std::vector< absl::string_view > const &pieces){
    CheckIds(pieces, self->GetPieceSize());
    return self->DecodePiecesAsSerializedProto(pieces);
  }
SWIGINTERN sentencepiece::ImmutableSentencePieceText sentencepiece_SentencePieceProcessor__DecodeIdsAsImmutableProto(sentencepiece::SentencePieceProcessor const *self,std::vector< int > const &ids){
    CheckIds(ids, self->GetPieceSize());
    auto proto = self->DecodeIdsAsImmutableProto(ids);
    proto.ConvertToUnicodeSpans();
    return proto;
  }
SWIGINTERN sentencepiece::ImmutableSentencePieceText sentencepiece_SentencePieceProcessor__DecodePiecesAsImmutableProto(sentencepiece::SentencePieceProcessor const *self,std::vector< absl::string_view > const &pieces){
    CheckIds(pieces, self->GetPieceSize());
    auto proto= self->DecodePiecesAsImmutableProto(pieces);
    proto.ConvertToUnicodeSpans();
    return proto;
  }
SWIGINTERN std::vector< std::string > sentencepiece_SentencePieceProcessor__DecodeIdsBatch(sentencepiece::SentencePieceProcessor const *self,std::vector< std::vector< int > > const &ins,int num_threads){
    DEFINE_DECODE_BATCH_FUNC_IMPL(DecodeIds, int, std::string);
  }
SWIGINTERN BytesArray sentencepiece_SentencePieceProcessor__DecodeIdsAsBytesBatch(sentencepiece::SentencePieceProcessor const *self,std::vector< std::vector< int > > const &ins,int num_threads){
    DEFINE_DECODE_BATCH_FUNC_IMPL(DecodeIds, int, std::string);
  }
SWIGINTERN BytesArray sentencepiece_SentencePieceProcessor__DecodeIdsAsSerializedProtoBatch(sentencepiece::SentencePieceProcessor const *self,std::vector< std::vector< int > > const &ins,int num_threads){
    DEFINE_DECODE_BATCH_FUNC_IMPL(DecodeIdsAsSerializedProto, int,
                                  sentencepiece::util::bytes);
  }
SWIGINTERN std::vector< sentencepiece::ImmutableSentencePieceText > sentencepiece_SentencePieceProcessor__DecodeIdsAsImmutableProtoBatch(sentencepiece::SentencePieceProcessor const *self,std::vector< std::vector< int > > const &ins,int num_threads){
    DEFINE_DECODE_BATCH_FUNC_IMPL(DecodeIdsAsImmutableProto, int,
                                  sentencepiece::ImmutableSentencePieceText);
  }
SWIGINTERN std::vector< std::string > sentencepiece_SentencePieceProcessor__DecodePiecesBatch(sentencepiece::SentencePieceProcessor const *self,std::vector< std::vector< absl::string_view > > const &ins,int num_threads){
    DEFINE_DECODE_BATCH_FUNC_IMPL(DecodePieces, std::string, std::string);
  }
SWIGINTERN BytesArray sentencepiece_SentencePieceProcessor__DecodePiecesAsSerializedProtoBatch(sentencepiece::SentencePieceProcessor const *self,std::vector< std::vector< absl::string_view > > const &ins,int num_threads){
    DEFINE_DECODE_BATCH_FUNC_IMPL(DecodePiecesAsSerializedProto, std::string,
                                  sentencepiece::util::bytes);
  }
SWIGINTERN std::vector< sentencepiece::ImmutableSentencePieceText > sentencepiece_SentencePieceProcessor__DecodePiecesAsImmutableProtoBatch(sentencepiece::SentencePieceProcessor const *self,std::vector< std::vector< absl::string_view > > const &ins,int num_threads){
    DEFINE_DECODE_BATCH_FUNC_IMPL(DecodePiecesAsImmutableProto, std::string,
                                  sentencepiece::ImmutableSentencePieceText);
  }
SWIGINTERN std::vector< std::vector< int > > sentencepiece_SentencePieceProcessor__NBestEncodeAsIds(sentencepiece::SentencePieceProcessor const *self,absl::string_view text,int nbest_size,bool add_bos,bool add_eos,bool reverse,bool emit_unk_piece){
    auto idss = self->NBestEncodeAsIds(text, nbest_size);
    for (auto &ids : idss) {
      RewriteIds(*self, &ids, add_bos, add_eos, reverse, emit_unk_piece);
    }
    return idss;
  }
SWIGINTERN std::vector< std::vector< std::string > > sentencepiece_SentencePieceProcessor__NBestEncodeAsPieces(sentencepiece::SentencePieceProcessor const *self,absl::string_view text,int nbest_size,bool add_bos,bool add_eos,bool reverse,bool emit_unk_piece){
    auto piecess = self->NBestEncodeAsPieces(text, nbest_size);
    for (auto &pieces : piecess) {
      RewriteIds(*self, &pieces, add_bos, add_eos, reverse, emit_unk_piece);
    }
    return piecess;
  }
SWIGINTERN sentencepiece::util::bytes sentencepiece_SentencePieceProcessor__NBestEncodeAsSerializedProto(sentencepiece::SentencePieceProcessor const *self,absl::string_view text,int nbest_size,bool add_bos,bool add_eos,bool reverse,bool emit_unk_piece){
    RewriteIds(*self, static_cast<sentencepiece::util::bytes *>(nullptr),
               add_bos, add_eos, reverse, emit_unk_piece);
    return self->NBestEncodeAsSerializedProto(text, nbest_size);
  }
SWIGINTERN sentencepiece::ImmutableNBestSentencePieceText sentencepiece_SentencePieceProcessor__NBestEncodeAsImmutableProto(sentencepiece::SentencePieceProcessor const *self,absl::string_view text,int nbest_size,bool add_bos,bool add_eos,bool reverse,bool emit_unk_piece){
    RewriteIds(*self, static_cast<sentencepiece::ImmutableSentencePieceText *>(nullptr),
               add_bos, add_eos, reverse, emit_unk_piece);
    auto proto = self->NBestEncodeAsImmutableProto(text, nbest_size);
    proto.ConvertToUnicodeSpans();
    return proto;
  }
SWIGINTERN std::vector< std::pair< std::vector< int >,float > > sentencepiece_SentencePieceProcessor__SampleEncodeAndScoreAsIds(sentencepiece::SentencePieceProcessor const *self,absl::string_view text,int num_samples,float alpha,bool wor,bool include_best,bool add_bos,bool add_eos,bool reverse,bool emit_unk_piece){
    auto idss = self->SampleEncodeAndScoreAsIds(text, num_samples,
                                                 alpha, wor, include_best);
    for (auto &ids : idss) {
      RewriteIds(*self, &ids.first, add_bos, add_eos, reverse, emit_unk_piece);
    }
    return idss;
  }
SWIGINTERN std::vector< std::pair< std::vector< std::string >,float > > sentencepiece_SentencePieceProcessor__SampleEncodeAndScoreAsPieces(sentencepiece::SentencePieceProcessor const *self,absl::string_view text,int num_samples,float alpha,bool wor,bool include_best,bool add_bos,bool add_eos,bool reverse,bool emit_unk_piece){
    auto piecess = self->SampleEncodeAndScoreAsPieces(text, num_samples,
                                                       alpha, wor, include_best);
    for (auto &pieces : piecess) {
      RewriteIds(*self, &pieces.first, add_bos, add_eos, reverse, emit_unk_piece);
    }
    return piecess;
  }
SWIGINTERN sentencepiece::util::bytes sentencepiece_SentencePieceProcessor__SampleEncodeAndScoreAsSerializedProto(sentencepiece::SentencePieceProcessor const *self,absl::string_view text,int num_samples,float alpha,bool wor,bool include_best,bool add_bos,bool add_eos,bool reverse,bool emit_unk_piece){
    RewriteIds(*self, static_cast<sentencepiece::util::bytes *>(nullptr),
               add_bos, add_eos, reverse, emit_unk_piece);
    return self->SampleEncodeAndScoreAsSerializedProto(text, num_samples,
                                                        alpha, wor, include_best);
  }
SWIGINTERN sentencepiece::ImmutableNBestSentencePieceText sentencepiece_SentencePieceProcessor__SampleEncodeAndScoreAsImmutableProto(sentencepiece::SentencePieceProcessor const *self,absl::string_view text,int num_samples,float alpha,bool wor,bool include_best,bool add_bos,bool add_eos,bool reverse,bool emit_unk_piece){
    RewriteIds(*self, static_cast<sentencepiece::util::bytes *>(nullptr),
               add_bos, add_eos, reverse, emit_unk_piece);
    auto proto = self->SampleEncodeAndScoreAsImmutableProto(text, num_samples,
                                                       alpha, wor, include_best);
    proto.ConvertToUnicodeSpans();
    return proto;
  }
SWIGINTERN std::string sentencepiece_SentencePieceProcessor__Normalize(sentencepiece::SentencePieceProcessor *self,absl::string_view text){
    return self->Normalize(text);
  }
SWIGINTERN std::pair< std::string,std::vector< size_t > > sentencepiece_SentencePieceProcessor__NormalizeWithOffsets(sentencepiece::SentencePieceProcessor *self,absl::string_view text){
    std::pair<std::string, std::vector<size_t>> result;
    self->Normalize(text, &result.first, &result.second).IgnoreError();
    return result;
  }
SWIGINTERN float sentencepiece_SentencePieceProcessor__CalculateEntropy(sentencepiece::SentencePieceProcessor *self,absl::string_view text,float alpha){
    return self->CalculateEntropy(text, alpha);
  }
SWIGINTERN std::vector< float > sentencepiece_SentencePieceProcessor__CalculateEntropyBatch(sentencepiece::SentencePieceProcessor *self,std::vector< absl::string_view > const &ins,float alpha,int num_threads){
    std::vector<float> outs(ins.size());
    InitNumThreads(ins, &num_threads);
    {
      ThreadPool pool(ins.size());
      std::atomic<size_t> index = 0;
      for (int n = 0;  n < num_threads; ++n) {
        pool.Schedule([&]() {
           size_t i = 0;
           while ((i = std::atomic_fetch_add(&index, 1)) < outs.size()) {
             outs[i] = self->CalculateEntropy(ins[i], alpha);
           }
         });
      }
    }
    return outs;
  }
SWIGINTERN sentencepiece::util::Status sentencepiece_SentencePieceProcessor__OverrideNormalizerSpec(sentencepiece::SentencePieceProcessor *self,std::unordered_map< std::string,std::string > const &args){
    sentencepiece::util::Status status;
    for (const auto &[key, value] : args) {
      status = sentencepiece::SentencePieceTrainer::SetProtoField(
          key, value,
          self->mutable_normalizer_spec());
      if (!status.ok()) return status;
    }
    return status;
  }

SWIGINTERN int
SWIG_AsVal_unsigned_SS_long (PyObject *obj, unsigned long *val) 
{
#if PY_VERSION_HEX < 0x03000000
  if (PyInt_Check(obj)) {
    long v = PyInt_AsLong(obj);
    if (v >= 0) {
      if (val) *val = v;
      return SWIG_OK;
    } else {
      return SWIG_OverflowError;
    }
  } else
#endif
  if (PyLong_Check(obj)) {
    unsigned long v = PyLong_AsUnsignedLong(obj);
    if (!PyErr_Occurred()) {
      if (val) *val = v;
      return SWIG_OK;
    } else {
      PyErr_Clear();
      return SWIG_OverflowError;
    }
  }
#ifdef SWIG_PYTHON_CAST_MODE
  {
    int dispatch = 0;
    unsigned long v = PyLong_AsUnsignedLong(obj);
    if (!PyErr_Occurred()) {
      if (val) *val = v;
      return SWIG_AddCast(SWIG_OK);
    } else {
      PyErr_Clear();
    }
    if (!dispatch) {
      double d;
      int res = SWIG_AddCast(SWIG_AsVal_double (obj,&d));
      if (SWIG_IsOK(res) && SWIG_CanCastAsInteger(&d, 0, ULONG_MAX)) {
	if (val) *val = (unsigned long)(d);
	return res;
      }
    }
  }
#endif
  return SWIG_TypeError;
}


SWIGINTERN int
SWIG_AsVal_unsigned_SS_int (PyObject * obj, unsigned int *val)
{
  unsigned long v;
  int res = SWIG_AsVal_unsigned_SS_long (obj, &v);
  if (SWIG_IsOK(res)) {
    if ((v > UINT_MAX)) {
      return SWIG_OverflowError;
    } else {
      if (val) *val = static_cast< unsigned int >(v);
    }
  }  
  return res;
}

SWIGINTERN void sentencepiece_SentencePieceTrainer__TrainFromString(absl::string_view arg){
    const auto _status = sentencepiece::SentencePieceTrainer::Train(arg);
    if (!_status.ok()) throw _status;
    return;
  }
SWIGINTERN void sentencepiece_SentencePieceTrainer__TrainFromMap(std::unordered_map< std::string,std::string > const &args){
    const auto _status = sentencepiece::SentencePieceTrainer::Train(args);
    if (!_status.ok()) throw _status;
    return;
  }
SWIGINTERN void sentencepiece_SentencePieceTrainer__TrainFromMap2(std::unordered_map< std::string,std::string > const &args,sentencepiece::SentenceIterator *iter){
    const auto _status = sentencepiece::SentencePieceTrainer::Train(args, iter);
    if (!_status.ok()) throw _status;
    return;
  }
SWIGINTERN sentencepiece::util::bytes sentencepiece_SentencePieceTrainer__TrainFromMap3(std::unordered_map< std::string,std::string > const &args){
    sentencepiece::util::bytes model_proto;
    const auto _status = sentencepiece::SentencePieceTrainer::Train(args, nullptr, &model_proto);
    if (!_status.ok()) throw _status;
    return model_proto;
  }
SWIGINTERN sentencepiece::util::bytes sentencepiece_SentencePieceTrainer__TrainFromMap4(std::unordered_map< std::string,std::string > const &args,sentencepiece::SentenceIterator *iter){
    sentencepiece::util::bytes model_proto;
    const auto _status = sentencepiece::SentencePieceTrainer::Train(args, iter, &model_proto);
    if (!_status.ok()) throw _status;
    return model_proto;
  }
SWIGINTERN sentencepiece::util::Status sentencepiece_SentencePieceNormalizer_LoadFromFile(sentencepiece::SentencePieceNormalizer *self,absl::string_view arg){
    return self->Load(arg);
  }
SWIGINTERN std::string sentencepiece_SentencePieceNormalizer__Normalize(sentencepiece::SentencePieceNormalizer *self,absl::string_view text){
    std::string result;
    const auto _status = self->Normalize(text, &result);
    if (!_status.ok()) throw _status;
    return result;
  }
SWIGINTERN std::pair< std::string,std::vector< size_t > > sentencepiece_SentencePieceNormalizer__NormalizeWithOffsets(sentencepiece::SentencePieceNormalizer *self,absl::string_view text){
    std::pair<std::string, std::vector<size_t>> result;
    const auto _status = self->Normalize(text, &result.first, &result.second);
    if (!_status.ok()) throw _status;
    return result;
  }
SWIGINTERN void sentencepiece_SentencePieceNormalizer__SetProtoField(sentencepiece::SentencePieceNormalizer *self,absl::string_view name,bool value){
    sentencepiece::SentencePieceTrainer::SetProtoField(
        name,
        value ? "1" : "0",
        self->mutable_normalizer_spec()).IgnoreError();
  }
#ifdef __cplusplus
extern "C" {
#endif
SWIGINTERN PyObject *_wrap_new_ImmutableSentencePieceText_ImmutableSentencePiece(PyObject *self, PyObject *args) {
  PyObject *resultobj = 0;
  sentencepiece::ImmutableSentencePieceText_ImmutableSentencePiece *result = 0 ;
  
  if (!SWIG_Python_UnpackTuple(args, "new_ImmutableSentencePieceText_ImmutableSentencePiece", 0, 0, 0)) SWIG_fail;
  {
    try {
      result = (sentencepiece::ImmutableSentencePieceText_ImmutableSentencePiece *)new sentencepiece::ImmutableSentencePieceText_ImmutableSentencePiece();
      ReleaseResultObject(resultobj);
    }
    catch (const sentencepiece::util::Status &status) {
      SWIG_exception(ToSwigError(status.code()), status.ToString().c_str());
    }
  }
  resultobj = SWIG_NewPointerObj(SWIG_as_voidptr(result), SWIGTYPE_p_sentencepiece__ImmutableSentencePieceText_ImmutableSentencePiece, SWIG_POINTER_NEW |  0 );
  return resultobj;
fail:
  return NULL;
}


SWIGINTERN PyObject *_wrap_delete_ImmutableSentencePieceText_ImmutableSentencePiece(PyObject *self, PyObject *args) {
  PyObject *resultobj = 0;
  sentencepiece::ImmutableSentencePieceText_ImmutableSentencePiece *arg1 = (sentencepiece::ImmutableSentencePieceText_ImmutableSentencePiece *) 0 ;
  void *argp1 = 0 ;
  int res1 = 0 ;
  PyObject *swig_obj[1] ;
  
  if (!args) SWIG_fail;
  swig_obj[0] = args;
  res1 = SWIG_ConvertPtr(swig_obj[0], &argp1,SWIGTYPE_p_sentencepiece__ImmutableSentencePieceText_ImmutableSentencePiece, SWIG_POINTER_DISOWN |  0 );
  if (!SWIG_IsOK(res1)) {
    SWIG_exception_fail(SWIG_ArgError(res1), "in method '" "delete_ImmutableSentencePieceText_ImmutableSentencePiece" "', argument " "1"" of type '" "sentencepiece::ImmutableSentencePieceText_ImmutableSentencePiece *""'"); 
  }
  arg1 = reinterpret_cast< sentencepiece::ImmutableSentencePieceText_ImmutableSentencePiece * >(argp1);
  {
    try {
      delete arg1;
      ReleaseResultObject(resultobj);
    }
    catch (const sentencepiece::util::Status &status) {
      SWIG_exception(ToSwigError(status.code()), status.ToString().c_str());
    }
  }
  resultobj = SWIG_Py_Void();
  return resultobj;
fail:
  return NULL;
}


SWIGINTERN PyObject *_wrap_ImmutableSentencePieceText_ImmutableSentencePiece__piece(PyObject *self, PyObject *args) {
  PyObject *resultobj = 0;
  sentencepiece::ImmutableSentencePieceText_ImmutableSentencePiece *arg1 = (sentencepiece::ImmutableSentencePieceText_ImmutableSentencePiece *) 0 ;
  void *argp1 = 0 ;
  int res1 = 0 ;
  PyObject *swig_obj[1] ;
  std::string *result = 0 ;
  
  if (!args) SWIG_fail;
  swig_obj[0] = args;
  res1 = SWIG_ConvertPtr(swig_obj[0], &argp1,SWIGTYPE_p_sentencepiece__ImmutableSentencePieceText_ImmutableSentencePiece, 0 |  0 );
  if (!SWIG_IsOK(res1)) {
    SWIG_exception_fail(SWIG_ArgError(res1), "in method '" "ImmutableSentencePieceText_ImmutableSentencePiece__piece" "', argument " "1"" of type '" "sentencepiece::ImmutableSentencePieceText_ImmutableSentencePiece const *""'"); 
  }
  arg1 = reinterpret_cast< sentencepiece::ImmutableSentencePieceText_ImmutableSentencePiece * >(argp1);
  {
    try {
      result = (std::string *) &((sentencepiece::ImmutableSentencePieceText_ImmutableSentencePiece const *)arg1)->piece();
      ReleaseResultObject(resultobj);
    }
    catch (const sentencepiece::util::Status &status) {
      SWIG_exception(ToSwigError(status.code()), status.ToString().c_str());
    }
  }
  {
    PyObject *input_type = resultobj;
    resultobj = MakePyOutputString(*result, input_type);
  }
  return resultobj;
fail:
  return NULL;
}


SWIGINTERN PyObject *_wrap_ImmutableSentencePieceText_ImmutableSentencePiece__surface(PyObject *self, PyObject *args) {
  PyObject *resultobj = 0;
  sentencepiece::ImmutableSentencePieceText_ImmutableSentencePiece *arg1 = (sentencepiece::ImmutableSentencePieceText_ImmutableSentencePiece *) 0 ;
  void *argp1 = 0 ;
  int res1 = 0 ;
  PyObject *swig_obj[1] ;
  std::string *result = 0 ;
  
  if (!args) SWIG_fail;
  swig_obj[0] = args;
  res1 = SWIG_ConvertPtr(swig_obj[0], &argp1,SWIGTYPE_p_sentencepiece__ImmutableSentencePieceText_ImmutableSentencePiece, 0 |  0 );
  if (!SWIG_IsOK(res1)) {
    SWIG_exception_fail(SWIG_ArgError(res1), "in method '" "ImmutableSentencePieceText_ImmutableSentencePiece__surface" "', argument " "1"" of type '" "sentencepiece::ImmutableSentencePieceText_ImmutableSentencePiece const *""'"); 
  }
  arg1 = reinterpret_cast< sentencepiece::ImmutableSentencePieceText_ImmutableSentencePiece * >(argp1);
  {
    try {
      result = (std::string *) &((sentencepiece::ImmutableSentencePieceText_ImmutableSentencePiece const *)arg1)->surface();
      ReleaseResultObject(resultobj);
    }
    catch (const sentencepiece::util::Status &status) {
      SWIG_exception(ToSwigError(status.code()), status.ToString().c_str());
    }
  }
  {
    PyObject *input_type = resultobj;
    resultobj = MakePyOutputString(*result, input_type);
  }
  return resultobj;
fail:
  return NULL;
}


SWIGINTERN PyObject *_wrap_ImmutableSentencePieceText_ImmutableSentencePiece__id(PyObject *self, PyObject *args) {
  PyObject *resultobj = 0;
  sentencepiece::ImmutableSentencePieceText_ImmutableSentencePiece *arg1 = (sentencepiece::ImmutableSentencePieceText_ImmutableSentencePiece *) 0 ;
  void *argp1 = 0 ;
  int res1 = 0 ;
  PyObject *swig_obj[1] ;
  uint32_t result;
  
  if (!args) SWIG_fail;
  swig_obj[0] = args;
  res1 = SWIG_ConvertPtr(swig_obj[0], &argp1,SWIGTYPE_p_sentencepiece__ImmutableSentencePieceText_ImmutableSentencePiece, 0 |  0 );
  if (!SWIG_IsOK(res1)) {
    SWIG_exception_fail(SWIG_ArgError(res1), "in method '" "ImmutableSentencePieceText_ImmutableSentencePiece__id" "', argument " "1"" of type '" "sentencepiece::ImmutableSentencePieceText_ImmutableSentencePiece const *""'"); 
  }
  arg1 = reinterpret_cast< sentencepiece::ImmutableSentencePieceText_ImmutableSentencePiece * >(argp1);
  {
    try {
      result = ((sentencepiece::ImmutableSentencePieceText_ImmutableSentencePiece const *)arg1)->id();
      ReleaseResultObject(resultobj);
    }
    catch (const sentencepiece::util::Status &status) {
      SWIG_exception(ToSwigError(status.code()), status.ToString().c_str());
    }
  }
  resultobj = SWIG_From_unsigned_SS_int(static_cast< unsigned int >(result));
  return resultobj;
fail:
  return NULL;
}


SWIGINTERN PyObject *_wrap_ImmutableSentencePieceText_ImmutableSentencePiece__begin(PyObject *self, PyObject *args) {
  PyObject *resultobj = 0;
  sentencepiece::ImmutableSentencePieceText_ImmutableSentencePiece *arg1 = (sentencepiece::ImmutableSentencePieceText_ImmutableSentencePiece *) 0 ;
  void *argp1 = 0 ;
  int res1 = 0 ;
  PyObject *swig_obj[1] ;
  uint32_t result;
  
  if (!args) SWIG_fail;
  swig_obj[0] = args;
  res1 = SWIG_ConvertPtr(swig_obj[0], &argp1,SWIGTYPE_p_sentencepiece__ImmutableSentencePieceText_ImmutableSentencePiece, 0 |  0 );
  if (!SWIG_IsOK(res1)) {
    SWIG_exception_fail(SWIG_ArgError(res1), "in method '" "ImmutableSentencePieceText_ImmutableSentencePiece__begin" "', argument " "1"" of type '" "sentencepiece::ImmutableSentencePieceText_ImmutableSentencePiece const *""'"); 
  }
  arg1 = reinterpret_cast< sentencepiece::ImmutableSentencePieceText_ImmutableSentencePiece * >(argp1);
  {
    try {
      result = ((sentencepiece::ImmutableSentencePieceText_ImmutableSentencePiece const *)arg1)->begin();
      ReleaseResultObject(resultobj);
    }
    catch (const sentencepiece::util::Status &status) {
      SWIG_exception(ToSwigError(status.code()), status.ToString().c_str());
    }
  }
  resultobj = SWIG_From_unsigned_SS_int(static_cast< unsigned int >(result));
  return resultobj;
fail:
  return NULL;
}


SWIGINTERN PyObject *_wrap_ImmutableSentencePieceText_ImmutableSentencePiece__end(PyObject *self, PyObject *args) {
  PyObject *resultobj = 0;
  sentencepiece::ImmutableSentencePieceText_ImmutableSentencePiece *arg1 = (sentencepiece::ImmutableSentencePieceText_ImmutableSentencePiece *) 0 ;
  void *argp1 = 0 ;
  int res1 = 0 ;
  PyObject *swig_obj[1] ;
  uint32_t result;
  
  if (!args) SWIG_fail;
  swig_obj[0] = args;
  res1 = SWIG_ConvertPtr(swig_obj[0], &argp1,SWIGTYPE_p_sentencepiece__ImmutableSentencePieceText_ImmutableSentencePiece, 0 |  0 );
  if (!SWIG_IsOK(res1)) {
    SWIG_exception_fail(SWIG_ArgError(res1), "in method '" "ImmutableSentencePieceText_ImmutableSentencePiece__end" "', argument " "1"" of type '" "sentencepiece::ImmutableSentencePieceText_ImmutableSentencePiece const *""'"); 
  }
  arg1 = reinterpret_cast< sentencepiece::ImmutableSentencePieceText_ImmutableSentencePiece * >(argp1);
  {
    try {
      result = ((sentencepiece::ImmutableSentencePieceText_ImmutableSentencePiece const *)arg1)->end();
      ReleaseResultObject(resultobj);
    }
    catch (const sentencepiece::util::Status &status) {
      SWIG_exception(ToSwigError(status.code()), status.ToString().c_str());
    }
  }
  resultobj = SWIG_From_unsigned_SS_int(static_cast< unsigned int >(result));
  return resultobj;
fail:
  return NULL;
}


SWIGINTERN PyObject *_wrap_ImmutableSentencePieceText_ImmutableSentencePiece__surface_as_bytes(PyObject *self, PyObject *args) {
  PyObject *resultobj = 0;
  sentencepiece::ImmutableSentencePieceText_ImmutableSentencePiece *arg1 = (sentencepiece::ImmutableSentencePieceText_ImmutableSentencePiece *) 0 ;
  void *argp1 = 0 ;
  int res1 = 0 ;
  PyObject *swig_obj[1] ;
  sentencepiece::util::bytes *result = 0 ;
  
  if (!args) SWIG_fail;
  swig_obj[0] = args;
  res1 = SWIG_ConvertPtr(swig_obj[0], &argp1,SWIGTYPE_p_sentencepiece__ImmutableSentencePieceText_ImmutableSentencePiece, 0 |  0 );
  if (!SWIG_IsOK(res1)) {
    SWIG_exception_fail(SWIG_ArgError(res1), "in method '" "ImmutableSentencePieceText_ImmutableSentencePiece__surface_as_bytes" "', argument " "1"" of type '" "sentencepiece::ImmutableSentencePieceText_ImmutableSentencePiece const *""'"); 
  }
  arg1 = reinterpret_cast< sentencepiece::ImmutableSentencePieceText_ImmutableSentencePiece * >(argp1);
  {
    try {
      result = (sentencepiece::util::bytes *) &sentencepiece_ImmutableSentencePieceText_ImmutableSentencePiece__surface_as_bytes((sentencepiece::ImmutableSentencePieceText_ImmutableSentencePiece const *)arg1);
      ReleaseResultObject(resultobj);
    }
    catch (const sentencepiece::util::Status &status) {
      SWIG_exception(ToSwigError(status.code()), status.ToString().c_str());
    }
  }
  {
    resultobj = MakePyOutputBytes(*result);
  }
  return resultobj;
fail:
  return NULL;
}


SWIGINTERN PyObject *_wrap_ImmutableSentencePieceText_ImmutableSentencePiece__piece_as_bytes(PyObject *self, PyObject *args) {
  PyObject *resultobj = 0;
  sentencepiece::ImmutableSentencePieceText_ImmutableSentencePiece *arg1 = (sentencepiece::ImmutableSentencePieceText_ImmutableSentencePiece *) 0 ;
  void *argp1 = 0 ;
  int res1 = 0 ;
  PyObject *swig_obj[1] ;
  sentencepiece::util::bytes *result = 0 ;
  
  if (!args) SWIG_fail;
  swig_obj[0] = args;
  res1 = SWIG_ConvertPtr(swig_obj[0], &argp1,SWIGTYPE_p_sentencepiece__ImmutableSentencePieceText_ImmutableSentencePiece, 0 |  0 );
  if (!SWIG_IsOK(res1)) {
    SWIG_exception_fail(SWIG_ArgError(res1), "in method '" "ImmutableSentencePieceText_ImmutableSentencePiece__piece_as_bytes" "', argument " "1"" of type '" "sentencepiece::ImmutableSentencePieceText_ImmutableSentencePiece const *""'"); 
  }
  arg1 = reinterpret_cast< sentencepiece::ImmutableSentencePieceText_ImmutableSentencePiece * >(argp1);
  {
    try {
      result = (sentencepiece::util::bytes *) &sentencepiece_ImmutableSentencePieceText_ImmutableSentencePiece__piece_as_bytes((sentencepiece::ImmutableSentencePieceText_ImmutableSentencePiece const *)arg1);
      ReleaseResultObject(resultobj);
    }
    catch (const sentencepiece::util::Status &status) {
      SWIG_exception(ToSwigError(status.code()), status.ToString().c_str());
    }
  }
  {
    resultobj = MakePyOutputBytes(*result);
  }
  return resultobj;
fail:
  return NULL;
}


SWIGINTERN PyObject *ImmutableSentencePieceText_ImmutableSentencePiece_swigregister(PyObject *SWIGUNUSEDPARM(self), PyObject *args) {
  PyObject *obj;
  if (!SWIG_Python_UnpackTuple(args, "swigregister", 1, 1, &obj)) return NULL;
  SWIG_TypeNewClientData(SWIGTYPE_p_sentencepiece__ImmutableSentencePieceText_ImmutableSentencePiece, SWIG_NewClientData(obj));
  return SWIG_Py_Void();
}

SWIGINTERN PyObject *ImmutableSentencePieceText_ImmutableSentencePiece_swiginit(PyObject *SWIGUNUSEDPARM(self), PyObject *args) {
  return SWIG_Python_InitShadowInstance(args);
}

SWIGINTERN PyObject *_wrap_new_ImmutableSentencePieceText(PyObject *self, PyObject *args) {
  PyObject *resultobj = 0;
  sentencepiece::ImmutableSentencePieceText *result = 0 ;
  
  if (!SWIG_Python_UnpackTuple(args, "new_ImmutableSentencePieceText", 0, 0, 0)) SWIG_fail;
  {
    try {
      result = (sentencepiece::ImmutableSentencePieceText *)new sentencepiece::ImmutableSentencePieceText();
      ReleaseResultObject(resultobj);
    }
    catch (const sentencepiece::util::Status &status) {
      SWIG_exception(ToSwigError(status.code()), status.ToString().c_str());
    }
  }
  resultobj = SWIG_NewPointerObj(SWIG_as_voidptr(result), SWIGTYPE_p_sentencepiece__ImmutableSentencePieceText, SWIG_POINTER_NEW |  0 );
  return resultobj;
fail:
  return NULL;
}


SWIGINTERN PyObject *_wrap_delete_ImmutableSentencePieceText(PyObject *self, PyObject *args) {
  PyObject *resultobj = 0;
  sentencepiece::ImmutableSentencePieceText *arg1 = (sentencepiece::ImmutableSentencePieceText *) 0 ;
  void *argp1 = 0 ;
  int res1 = 0 ;
  PyObject *swig_obj[1] ;
  
  if (!args) SWIG_fail;
  swig_obj[0] = args;
  res1 = SWIG_ConvertPtr(swig_obj[0], &argp1,SWIGTYPE_p_sentencepiece__ImmutableSentencePieceText, SWIG_POINTER_DISOWN |  0 );
  if (!SWIG_IsOK(res1)) {
    SWIG_exception_fail(SWIG_ArgError(res1), "in method '" "delete_ImmutableSentencePieceText" "', argument " "1"" of type '" "sentencepiece::ImmutableSentencePieceText *""'"); 
  }
  arg1 = reinterpret_cast< sentencepiece::ImmutableSentencePieceText * >(argp1);
  {
    try {
      delete arg1;
      ReleaseResultObject(resultobj);
    }
    catch (const sentencepiece::util::Status &status) {
      SWIG_exception(ToSwigError(status.code()), status.ToString().c_str());
    }
  }
  resultobj = SWIG_Py_Void();
  return resultobj;
fail:
  return NULL;
}


SWIGINTERN PyObject *_wrap_ImmutableSentencePieceText__pieces_size(PyObject *self, PyObject *args) {
  PyObject *resultobj = 0;
  sentencepiece::ImmutableSentencePieceText *arg1 = (sentencepiece::ImmutableSentencePieceText *) 0 ;
  void *argp1 = 0 ;
  int res1 = 0 ;
  PyObject *swig_obj[1] ;
  size_t result;
  
  if (!args) SWIG_fail;
  swig_obj[0] = args;
  res1 = SWIG_ConvertPtr(swig_obj[0], &argp1,SWIGTYPE_p_sentencepiece__ImmutableSentencePieceText, 0 |  0 );
  if (!SWIG_IsOK(res1)) {
    SWIG_exception_fail(SWIG_ArgError(res1), "in method '" "ImmutableSentencePieceText__pieces_size" "', argument " "1"" of type '" "sentencepiece::ImmutableSentencePieceText const *""'"); 
  }
  arg1 = reinterpret_cast< sentencepiece::ImmutableSentencePieceText * >(argp1);
  {
    try {
      result = ((sentencepiece::ImmutableSentencePieceText const *)arg1)->pieces_size();
      ReleaseResultObject(resultobj);
    }
    catch (const sentencepiece::util::Status &status) {
      SWIG_exception(ToSwigError(status.code()), status.ToString().c_str());
    }
  }
  resultobj = SWIG_From_size_t(static_cast< size_t >(result));
  return resultobj;
fail:
  return NULL;
}


SWIGINTERN PyObject *_wrap_ImmutableSentencePieceText__pieces(PyObject *self, PyObject *args) {
  PyObject *resultobj = 0;
  sentencepiece::ImmutableSentencePieceText *arg1 = (sentencepiece::ImmutableSentencePieceText *) 0 ;
  int arg2 ;
  void *argp1 = 0 ;
  int res1 = 0 ;
  int val2 ;
  int ecode2 = 0 ;
  PyObject *swig_obj[2] ;
  sentencepiece::ImmutableSentencePieceText_ImmutableSentencePiece result;
  
  if (!SWIG_Python_UnpackTuple(args, "ImmutableSentencePieceText__pieces", 2, 2, swig_obj)) SWIG_fail;
  res1 = SWIG_ConvertPtr(swig_obj[0], &argp1,SWIGTYPE_p_sentencepiece__ImmutableSentencePieceText, 0 |  0 );
  if (!SWIG_IsOK(res1)) {
    SWIG_exception_fail(SWIG_ArgError(res1), "in method '" "ImmutableSentencePieceText__pieces" "', argument " "1"" of type '" "sentencepiece::ImmutableSentencePieceText const *""'"); 
  }
  arg1 = reinterpret_cast< sentencepiece::ImmutableSentencePieceText * >(argp1);
  ecode2 = SWIG_AsVal_int(swig_obj[1], &val2);
  if (!SWIG_IsOK(ecode2)) {
    SWIG_exception_fail(SWIG_ArgError(ecode2), "in method '" "ImmutableSentencePieceText__pieces" "', argument " "2"" of type '" "int""'");
  } 
  arg2 = static_cast< int >(val2);
  {
    try {
      result = ((sentencepiece::ImmutableSentencePieceText const *)arg1)->pieces(arg2);
      ReleaseResultObject(resultobj);
    }
    catch (const sentencepiece::util::Status &status) {
      SWIG_exception(ToSwigError(status.code()), status.ToString().c_str());
    }
  }
  resultobj = SWIG_NewPointerObj((new sentencepiece::ImmutableSentencePieceText_ImmutableSentencePiece(result)), SWIGTYPE_p_sentencepiece__ImmutableSentencePieceText_ImmutableSentencePiece, SWIG_POINTER_OWN |  0 );
  return resultobj;
fail:
  return NULL;
}


SWIGINTERN PyObject *_wrap_ImmutableSentencePieceText__text(PyObject *self, PyObject *args) {
  PyObject *resultobj = 0;
  sentencepiece::ImmutableSentencePieceText *arg1 = (sentencepiece::ImmutableSentencePieceText *) 0 ;
  void *argp1 = 0 ;
  int res1 = 0 ;
  PyObject *swig_obj[1] ;
  std::string *result = 0 ;
  
  if (!args) SWIG_fail;
  swig_obj[0] = args;
  res1 = SWIG_ConvertPtr(swig_obj[0], &argp1,SWIGTYPE_p_sentencepiece__ImmutableSentencePieceText, 0 |  0 );
  if (!SWIG_IsOK(res1)) {
    SWIG_exception_fail(SWIG_ArgError(res1), "in method '" "ImmutableSentencePieceText__text" "', argument " "1"" of type '" "sentencepiece::ImmutableSentencePieceText const *""'"); 
  }
  arg1 = reinterpret_cast< sentencepiece::ImmutableSentencePieceText * >(argp1);
  {
    try {
      result = (std::string *) &((sentencepiece::ImmutableSentencePieceText const *)arg1)->text();
      ReleaseResultObject(resultobj);
    }
    catch (const sentencepiece::util::Status &status) {
      SWIG_exception(ToSwigError(status.code()), status.ToString().c_str());
    }
  }
  {
    PyObject *input_type = resultobj;
    resultobj = MakePyOutputString(*result, input_type);
  }
  return resultobj;
fail:
  return NULL;
}


SWIGINTERN PyObject *_wrap_ImmutableSentencePieceText__score(PyObject *self, PyObject *args) {
  PyObject *resultobj = 0;
  sentencepiece::ImmutableSentencePieceText *arg1 = (sentencepiece::ImmutableSentencePieceText *) 0 ;
  void *argp1 = 0 ;
  int res1 = 0 ;
  PyObject *swig_obj[1] ;
  float result;
  
  if (!args) SWIG_fail;
  swig_obj[0] = args;
  res1 = SWIG_ConvertPtr(swig_obj[0], &argp1,SWIGTYPE_p_sentencepiece__ImmutableSentencePieceText, 0 |  0 );
  if (!SWIG_IsOK(res1)) {
    SWIG_exception_fail(SWIG_ArgError(res1), "in method '" "ImmutableSentencePieceText__score" "', argument " "1"" of type '" "sentencepiece::ImmutableSentencePieceText const *""'"); 
  }
  arg1 = reinterpret_cast< sentencepiece::ImmutableSentencePieceText * >(argp1);
  {
    try {
      result = (float)((sentencepiece::ImmutableSentencePieceText const *)arg1)->score();
      ReleaseResultObject(resultobj);
    }
    catch (const sentencepiece::util::Status &status) {
      SWIG_exception(ToSwigError(status.code()), status.ToString().c_str());
    }
  }
  resultobj = SWIG_From_float(static_cast< float >(result));
  return resultobj;
fail:
  return NULL;
}


SWIGINTERN PyObject *_wrap_ImmutableSentencePieceText_SerializeAsString(PyObject *self, PyObject *args) {
  PyObject *resultobj = 0;
  sentencepiece::ImmutableSentencePieceText *arg1 = (sentencepiece::ImmutableSentencePieceText *) 0 ;
  void *argp1 = 0 ;
  int res1 = 0 ;
  PyObject *swig_obj[1] ;
  sentencepiece::util::bytes result;
  
  if (!args) SWIG_fail;
  swig_obj[0] = args;
  res1 = SWIG_ConvertPtr(swig_obj[0], &argp1,SWIGTYPE_p_sentencepiece__ImmutableSentencePieceText, 0 |  0 );
  if (!SWIG_IsOK(res1)) {
    SWIG_exception_fail(SWIG_ArgError(res1), "in method '" "ImmutableSentencePieceText_SerializeAsString" "', argument " "1"" of type '" "sentencepiece::ImmutableSentencePieceText const *""'"); 
  }
  arg1 = reinterpret_cast< sentencepiece::ImmutableSentencePieceText * >(argp1);
  {
    try {
      result = ((sentencepiece::ImmutableSentencePieceText const *)arg1)->SerializeAsString();
      ReleaseResultObject(resultobj);
    }
    catch (const sentencepiece::util::Status &status) {
      SWIG_exception(ToSwigError(status.code()), status.ToString().c_str());
    }
  }
  {
    resultobj = MakePyOutputBytes(result);
  }
  return resultobj;
fail:
  return NULL;
}


SWIGINTERN PyObject *_wrap_ImmutableSentencePieceText__text_as_bytes(PyObject *self, PyObject *args) {
  PyObject *resultobj = 0;
  sentencepiece::ImmutableSentencePieceText *arg1 = (sentencepiece::ImmutableSentencePieceText *) 0 ;
  void *argp1 = 0 ;
  int res1 = 0 ;
  PyObject *swig_obj[1] ;
  sentencepiece::util::bytes *result = 0 ;
  
  if (!args) SWIG_fail;
  swig_obj[0] = args;
  res1 = SWIG_ConvertPtr(swig_obj[0], &argp1,SWIGTYPE_p_sentencepiece__ImmutableSentencePieceText, 0 |  0 );
  if (!SWIG_IsOK(res1)) {
    SWIG_exception_fail(SWIG_ArgError(res1), "in method '" "ImmutableSentencePieceText__text_as_bytes" "', argument " "1"" of type '" "sentencepiece::ImmutableSentencePieceText const *""'"); 
  }
  arg1 = reinterpret_cast< sentencepiece::ImmutableSentencePieceText * >(argp1);
  {
    try {
      result = (sentencepiece::util::bytes *) &sentencepiece_ImmutableSentencePieceText__text_as_bytes((sentencepiece::ImmutableSentencePieceText const *)arg1);
      ReleaseResultObject(resultobj);
    }
    catch (const sentencepiece::util::Status &status) {
      SWIG_exception(ToSwigError(status.code()), status.ToString().c_str());
    }
  }
  {
    resultobj = MakePyOutputBytes(*result);
  }
  return resultobj;
fail:
  return NULL;
}


SWIGINTERN PyObject *ImmutableSentencePieceText_swigregister(PyObject *SWIGUNUSEDPARM(self), PyObject *args) {
  PyObject *obj;
  if (!SWIG_Python_UnpackTuple(args, "swigregister", 1, 1, &obj)) return NULL;
  SWIG_TypeNewClientData(SWIGTYPE_p_sentencepiece__ImmutableSentencePieceText, SWIG_NewClientData(obj));
  return SWIG_Py_Void();
}

SWIGINTERN PyObject *ImmutableSentencePieceText_swiginit(PyObject *SWIGUNUSEDPARM(self), PyObject *args) {
  return SWIG_Python_InitShadowInstance(args);
}

SWIGINTERN PyObject *_wrap_new_ImmutableNBestSentencePieceText(PyObject *self, PyObject *args) {
  PyObject *resultobj = 0;
  sentencepiece::ImmutableNBestSentencePieceText *result = 0 ;
  
  if (!SWIG_Python_UnpackTuple(args, "new_ImmutableNBestSentencePieceText", 0, 0, 0)) SWIG_fail;
  {
    try {
      result = (sentencepiece::ImmutableNBestSentencePieceText *)new sentencepiece::ImmutableNBestSentencePieceText();
      ReleaseResultObject(resultobj);
    }
    catch (const sentencepiece::util::Status &status) {
      SWIG_exception(ToSwigError(status.code()), status.ToString().c_str());
    }
  }
  resultobj = SWIG_NewPointerObj(SWIG_as_voidptr(result), SWIGTYPE_p_sentencepiece__ImmutableNBestSentencePieceText, SWIG_POINTER_NEW |  0 );
  return resultobj;
fail:
  return NULL;
}


SWIGINTERN PyObject *_wrap_delete_ImmutableNBestSentencePieceText(PyObject *self, PyObject *args) {
  PyObject *resultobj = 0;
  sentencepiece::ImmutableNBestSentencePieceText *arg1 = (sentencepiece::ImmutableNBestSentencePieceText *) 0 ;
  void *argp1 = 0 ;
  int res1 = 0 ;
  PyObject *swig_obj[1] ;
  
  if (!args) SWIG_fail;
  swig_obj[0] = args;
  res1 = SWIG_ConvertPtr(swig_obj[0], &argp1,SWIGTYPE_p_sentencepiece__ImmutableNBestSentencePieceText, SWIG_POINTER_DISOWN |  0 );
  if (!SWIG_IsOK(res1)) {
    SWIG_exception_fail(SWIG_ArgError(res1), "in method '" "delete_ImmutableNBestSentencePieceText" "', argument " "1"" of type '" "sentencepiece::ImmutableNBestSentencePieceText *""'"); 
  }
  arg1 = reinterpret_cast< sentencepiece::ImmutableNBestSentencePieceText * >(argp1);
  {
    try {
      delete arg1;
      ReleaseResultObject(resultobj);
    }
    catch (const sentencepiece::util::Status &status) {
      SWIG_exception(ToSwigError(status.code()), status.ToString().c_str());
    }
  }
  resultobj = SWIG_Py_Void();
  return resultobj;
fail:
  return NULL;
}


SWIGINTERN PyObject *_wrap_ImmutableNBestSentencePieceText__nbests_size(PyObject *self, PyObject *args) {
  PyObject *resultobj = 0;
  sentencepiece::ImmutableNBestSentencePieceText *arg1 = (sentencepiece::ImmutableNBestSentencePieceText *) 0 ;
  void *argp1 = 0 ;
  int res1 = 0 ;
  PyObject *swig_obj[1] ;
  size_t result;
  
  if (!args) SWIG_fail;
  swig_obj[0] = args;
  res1 = SWIG_ConvertPtr(swig_obj[0], &argp1,SWIGTYPE_p_sentencepiece__ImmutableNBestSentencePieceText, 0 |  0 );
  if (!SWIG_IsOK(res1)) {
    SWIG_exception_fail(SWIG_ArgError(res1), "in method '" "ImmutableNBestSentencePieceText__nbests_size" "', argument " "1"" of type '" "sentencepiece::ImmutableNBestSentencePieceText const *""'"); 
  }
  arg1 = reinterpret_cast< sentencepiece::ImmutableNBestSentencePieceText * >(argp1);
  {
    try {
      result = ((sentencepiece::ImmutableNBestSentencePieceText const *)arg1)->nbests_size();
      ReleaseResultObject(resultobj);
    }
    catch (const sentencepiece::util::Status &status) {
      SWIG_exception(ToSwigError(status.code()), status.ToString().c_str());
    }
  }
  resultobj = SWIG_From_size_t(static_cast< size_t >(result));
  return resultobj;
fail:
  return NULL;
}


SWIGINTERN PyObject *_wrap_ImmutableNBestSentencePieceText__nbests(PyObject *self, PyObject *args) {
  PyObject *resultobj = 0;
  sentencepiece::ImmutableNBestSentencePieceText *arg1 = (sentencepiece::ImmutableNBestSentencePieceText *) 0 ;
  int arg2 ;
  void *argp1 = 0 ;
  int res1 = 0 ;
  int val2 ;
  int ecode2 = 0 ;
  PyObject *swig_obj[2] ;
  sentencepiece::ImmutableSentencePieceText result;
  
  if (!SWIG_Python_UnpackTuple(args, "ImmutableNBestSentencePieceText__nbests", 2, 2, swig_obj)) SWIG_fail;
  res1 = SWIG_ConvertPtr(swig_obj[0], &argp1,SWIGTYPE_p_sentencepiece__ImmutableNBestSentencePieceText, 0 |  0 );
  if (!SWIG_IsOK(res1)) {
    SWIG_exception_fail(SWIG_ArgError(res1), "in method '" "ImmutableNBestSentencePieceText__nbests" "', argument " "1"" of type '" "sentencepiece::ImmutableNBestSentencePieceText const *""'"); 
  }
  arg1 = reinterpret_cast< sentencepiece::ImmutableNBestSentencePieceText * >(argp1);
  ecode2 = SWIG_AsVal_int(swig_obj[1], &val2);
  if (!SWIG_IsOK(ecode2)) {
    SWIG_exception_fail(SWIG_ArgError(ecode2), "in method '" "ImmutableNBestSentencePieceText__nbests" "', argument " "2"" of type '" "int""'");
  } 
  arg2 = static_cast< int >(val2);
  {
    try {
      result = ((sentencepiece::ImmutableNBestSentencePieceText const *)arg1)->nbests(arg2);
      ReleaseResultObject(resultobj);
    }
    catch (const sentencepiece::util::Status &status) {
      SWIG_exception(ToSwigError(status.code()), status.ToString().c_str());
    }
  }
  resultobj = SWIG_NewPointerObj((new sentencepiece::ImmutableSentencePieceText(result)), SWIGTYPE_p_sentencepiece__ImmutableSentencePieceText, SWIG_POINTER_OWN |  0 );
  return resultobj;
fail:
  return NULL;
}


SWIGINTERN PyObject *_wrap_ImmutableNBestSentencePieceText_SerializeAsString(PyObject *self, PyObject *args) {
  PyObject *resultobj = 0;
  sentencepiece::ImmutableNBestSentencePieceText *arg1 = (sentencepiece::ImmutableNBestSentencePieceText *) 0 ;
  void *argp1 = 0 ;
  int res1 = 0 ;
  PyObject *swig_obj[1] ;
  sentencepiece::util::bytes result;
  
  if (!args) SWIG_fail;
  swig_obj[0] = args;
  res1 = SWIG_ConvertPtr(swig_obj[0], &argp1,SWIGTYPE_p_sentencepiece__ImmutableNBestSentencePieceText, 0 |  0 );
  if (!SWIG_IsOK(res1)) {
    SWIG_exception_fail(SWIG_ArgError(res1), "in method '" "ImmutableNBestSentencePieceText_SerializeAsString" "', argument " "1"" of type '" "sentencepiece::ImmutableNBestSentencePieceText const *""'"); 
  }
  arg1 = reinterpret_cast< sentencepiece::ImmutableNBestSentencePieceText * >(argp1);
  {
    try {
      result = ((sentencepiece::ImmutableNBestSentencePieceText const *)arg1)->SerializeAsString();
      ReleaseResultObject(resultobj);
    }
    catch (const sentencepiece::util::Status &status) {
      SWIG_exception(ToSwigError(status.code()), status.ToString().c_str());
    }
  }
  {
    resultobj = MakePyOutputBytes(result);
  }
  return resultobj;
fail:
  return NULL;
}


SWIGINTERN PyObject *ImmutableNBestSentencePieceText_swigregister(PyObject *SWIGUNUSEDPARM(self), PyObject *args) {
  PyObject *obj;
  if (!SWIG_Python_UnpackTuple(args, "swigregister", 1, 1, &obj)) return NULL;
  SWIG_TypeNewClientData(SWIGTYPE_p_sentencepiece__ImmutableNBestSentencePieceText, SWIG_NewClientData(obj));
  return SWIG_Py_Void();
}

SWIGINTERN PyObject *ImmutableNBestSentencePieceText_swiginit(PyObject *SWIGUNUSEDPARM(self), PyObject *args) {
  return SWIG_Python_InitShadowInstance(args);
}

SWIGINTERN PyObject *_wrap_new_SentencePieceProcessor(PyObject *self, PyObject *args) {
  PyObject *resultobj = 0;
  sentencepiece::SentencePieceProcessor *result = 0 ;
  
  if (!SWIG_Python_UnpackTuple(args, "new_SentencePieceProcessor", 0, 0, 0)) SWIG_fail;
  {
    try {
      result = (sentencepiece::SentencePieceProcessor *)new sentencepiece::SentencePieceProcessor();
      ReleaseResultObject(resultobj);
    }
    catch (const sentencepiece::util::Status &status) {
      SWIG_exception(ToSwigError(status.code()), status.ToString().c_str());
    }
  }
  resultobj = SWIG_NewPointerObj(SWIG_as_voidptr(result), SWIGTYPE_p_sentencepiece__SentencePieceProcessor, SWIG_POINTER_NEW |  0 );
  return resultobj;
fail:
  return NULL;
}


SWIGINTERN PyObject *_wrap_delete_SentencePieceProcessor(PyObject *self, PyObject *args) {
  PyObject *resultobj = 0;
  sentencepiece::SentencePieceProcessor *arg1 = (sentencepiece::SentencePieceProcessor *) 0 ;
  void *argp1 = 0 ;
  int res1 = 0 ;
  PyObject *swig_obj[1] ;
  
  if (!args) SWIG_fail;
  swig_obj[0] = args;
  res1 = SWIG_ConvertPtr(swig_obj[0], &argp1,SWIGTYPE_p_sentencepiece__SentencePieceProcessor, SWIG_POINTER_DISOWN |  0 );
  if (!SWIG_IsOK(res1)) {
    SWIG_exception_fail(SWIG_ArgError(res1), "in method '" "delete_SentencePieceProcessor" "', argument " "1"" of type '" "sentencepiece::SentencePieceProcessor *""'"); 
  }
  arg1 = reinterpret_cast< sentencepiece::SentencePieceProcessor * >(argp1);
  {
    try {
      delete arg1;
      ReleaseResultObject(resultobj);
    }
    catch (const sentencepiece::util::Status &status) {
      SWIG_exception(ToSwigError(status.code()), status.ToString().c_str());
    }
  }
  resultobj = SWIG_Py_Void();
  return resultobj;
fail:
  return NULL;
}


SWIGINTERN PyObject *_wrap_SentencePieceProcessor_LoadFromSerializedProto(PyObject *self, PyObject *args) {
  PyObject *resultobj = 0;
  sentencepiece::SentencePieceProcessor *arg1 = (sentencepiece::SentencePieceProcessor *) 0 ;
  absl::string_view arg2 ;
  void *argp1 = 0 ;
  int res1 = 0 ;
  PyObject *swig_obj[2] ;
  sentencepiece::util::Status result;
  
  if (!SWIG_Python_UnpackTuple(args, "SentencePieceProcessor_LoadFromSerializedProto", 2, 2, swig_obj)) SWIG_fail;
  res1 = SWIG_ConvertPtr(swig_obj[0], &argp1,SWIGTYPE_p_sentencepiece__SentencePieceProcessor, 0 |  0 );
  if (!SWIG_IsOK(res1)) {
    SWIG_exception_fail(SWIG_ArgError(res1), "in method '" "SentencePieceProcessor_LoadFromSerializedProto" "', argument " "1"" of type '" "sentencepiece::SentencePieceProcessor *""'"); 
  }
  arg1 = reinterpret_cast< sentencepiece::SentencePieceProcessor * >(argp1);
  {
    const PyInputString ustring(swig_obj[1]);
    if (!ustring.IsAvalable()) {
      PyErr_SetString(PyExc_TypeError, "not a string");
      SWIG_fail;
    }
    resultobj = ustring.input_type();
    arg2 = ustring.str();
  }
  {
    try {
      result = (arg1)->LoadFromSerializedProto(arg2);
      ReleaseResultObject(resultobj);
    }
    catch (const sentencepiece::util::Status &status) {
      SWIG_exception(ToSwigError(status.code()), status.ToString().c_str());
    }
  }
  {
    if (!(&result)->ok()) {
      SWIG_exception(ToSwigError((&result)->code()), (&result)->ToString().c_str());
    }
    resultobj = SWIG_From_bool((&result)->ok());
  }
  return resultobj;
fail:
  return NULL;
}


SWIGINTERN PyObject *_wrap_SentencePieceProcessor_SetEncodeExtraOptions(PyObject *self, PyObject *args) {
  PyObject *resultobj = 0;
  sentencepiece::SentencePieceProcessor *arg1 = (sentencepiece::SentencePieceProcessor *) 0 ;
  absl::string_view arg2 ;
  void *argp1 = 0 ;
  int res1 = 0 ;
  PyObject *swig_obj[2] ;
  sentencepiece::util::Status result;
  
  if (!SWIG_Python_UnpackTuple(args, "SentencePieceProcessor_SetEncodeExtraOptions", 2, 2, swig_obj)) SWIG_fail;
  res1 = SWIG_ConvertPtr(swig_obj[0], &argp1,SWIGTYPE_p_sentencepiece__SentencePieceProcessor, 0 |  0 );
  if (!SWIG_IsOK(res1)) {
    SWIG_exception_fail(SWIG_ArgError(res1), "in method '" "SentencePieceProcessor_SetEncodeExtraOptions" "', argument " "1"" of type '" "sentencepiece::SentencePieceProcessor *""'"); 
  }
  arg1 = reinterpret_cast< sentencepiece::SentencePieceProcessor * >(argp1);
  {
    const PyInputString ustring(swig_obj[1]);
    if (!ustring.IsAvalable()) {
      PyErr_SetString(PyExc_TypeError, "not a string");
      SWIG_fail;
    }
    resultobj = ustring.input_type();
    arg2 = ustring.str();
  }
  {
    try {
      result = (arg1)->SetEncodeExtraOptions(arg2);
      ReleaseResultObject(resultobj);
    }
    catch (const sentencepiece::util::Status &status) {
      SWIG_exception(ToSwigError(status.code()), status.ToString().c_str());
    }
  }
  {
    if (!(&result)->ok()) {
      SWIG_exception(ToSwigError((&result)->code()), (&result)->ToString().c_str());
    }
    resultobj = SWIG_From_bool((&result)->ok());
  }
  return resultobj;
fail:
  return NULL;
}


SWIGINTERN PyObject *_wrap_SentencePieceProcessor_SetDecodeExtraOptions(PyObject *self, PyObject *args) {
  PyObject *resultobj = 0;
  sentencepiece::SentencePieceProcessor *arg1 = (sentencepiece::SentencePieceProcessor *) 0 ;
  absl::string_view arg2 ;
  void *argp1 = 0 ;
  int res1 = 0 ;
  PyObject *swig_obj[2] ;
  sentencepiece::util::Status result;
  
  if (!SWIG_Python_UnpackTuple(args, "SentencePieceProcessor_SetDecodeExtraOptions", 2, 2, swig_obj)) SWIG_fail;
  res1 = SWIG_ConvertPtr(swig_obj[0], &argp1,SWIGTYPE_p_sentencepiece__SentencePieceProcessor, 0 |  0 );
  if (!SWIG_IsOK(res1)) {
    SWIG_exception_fail(SWIG_ArgError(res1), "in method '" "SentencePieceProcessor_SetDecodeExtraOptions" "', argument " "1"" of type '" "sentencepiece::SentencePieceProcessor *""'"); 
  }
  arg1 = reinterpret_cast< sentencepiece::SentencePieceProcessor * >(argp1);
  {
    const PyInputString ustring(swig_obj[1]);
    if (!ustring.IsAvalable()) {
      PyErr_SetString(PyExc_TypeError, "not a string");
      SWIG_fail;
    }
    resultobj = ustring.input_type();
    arg2 = ustring.str();
  }
  {
    try {
      result = (arg1)->SetDecodeExtraOptions(arg2);
      ReleaseResultObject(resultobj);
    }
    catch (const sentencepiece::util::Status &status) {
      SWIG_exception(ToSwigError(status.code()), status.ToString().c_str());
    }
  }
  {
    if (!(&result)->ok()) {
      SWIG_exception(ToSwigError((&result)->code()), (&result)->ToString().c_str());
    }
    resultobj = SWIG_From_bool((&result)->ok());
  }
  return resultobj;
fail:
  return NULL;
}


SWIGINTERN PyObject *_wrap_SentencePieceProcessor_SetVocabulary(PyObject *self, PyObject *args) {
  PyObject *resultobj = 0;
  sentencepiece::SentencePieceProcessor *arg1 = (sentencepiece::SentencePieceProcessor *) 0 ;
  std::vector< absl::string_view > *arg2 = 0 ;
  void *argp1 = 0 ;
  int res1 = 0 ;
  PyObject *swig_obj[2] ;
  sentencepiece::util::Status result;
  
  if (!SWIG_Python_UnpackTuple(args, "SentencePieceProcessor_SetVocabulary", 2, 2, swig_obj)) SWIG_fail;
  res1 = SWIG_ConvertPtr(swig_obj[0], &argp1,SWIGTYPE_p_sentencepiece__SentencePieceProcessor, 0 |  0 );
  if (!SWIG_IsOK(res1)) {
    SWIG_exception_fail(SWIG_ArgError(res1), "in method '" "SentencePieceProcessor_SetVocabulary" "', argument " "1"" of type '" "sentencepiece::SentencePieceProcessor *""'"); 
  }
  arg1 = reinterpret_cast< sentencepiece::SentencePieceProcessor * >(argp1);
  {
    std::vector<absl::string_view> *out = nullptr;
    if (PyList_Check(swig_obj[1])) {
      const size_t size = PyList_Size(swig_obj[1]);
      out = new std::vector<absl::string_view>(size);
      for (size_t i = 0; i < size; ++i) {
        const PyInputString ustring(PyList_GetItem(swig_obj[1], i));
        if (ustring.IsAvalable()) {
          (*out)[i] = ustring.str();
        } else {
          PyErr_SetString(PyExc_TypeError, "list must contain strings");
          SWIG_fail;
        }
        resultobj = ustring.input_type();
      }
    } else {
      PyErr_SetString(PyExc_TypeError, "not a list");
      SWIG_fail;
    }
    arg2 = out;
  }
  {
    try {
      result = (arg1)->SetVocabulary((std::vector< absl::string_view > const &)*arg2);
      ReleaseResultObject(resultobj);
    }
    catch (const sentencepiece::util::Status &status) {
      SWIG_exception(ToSwigError(status.code()), status.ToString().c_str());
    }
  }
  {
    if (!(&result)->ok()) {
      SWIG_exception(ToSwigError((&result)->code()), (&result)->ToString().c_str());
    }
    resultobj = SWIG_From_bool((&result)->ok());
  }
  {
    delete arg2;
  }
  return resultobj;
fail:
  {
    delete arg2;
  }
  return NULL;
}


SWIGINTERN PyObject *_wrap_SentencePieceProcessor_ResetVocabulary(PyObject *self, PyObject *args) {
  PyObject *resultobj = 0;
  sentencepiece::SentencePieceProcessor *arg1 = (sentencepiece::SentencePieceProcessor *) 0 ;
  void *argp1 = 0 ;
  int res1 = 0 ;
  PyObject *swig_obj[1] ;
  sentencepiece::util::Status result;
  
  if (!args) SWIG_fail;
  swig_obj[0] = args;
  res1 = SWIG_ConvertPtr(swig_obj[0], &argp1,SWIGTYPE_p_sentencepiece__SentencePieceProcessor, 0 |  0 );
  if (!SWIG_IsOK(res1)) {
    SWIG_exception_fail(SWIG_ArgError(res1), "in method '" "SentencePieceProcessor_ResetVocabulary" "', argument " "1"" of type '" "sentencepiece::SentencePieceProcessor *""'"); 
  }
  arg1 = reinterpret_cast< sentencepiece::SentencePieceProcessor * >(argp1);
  {
    try {
      result = (arg1)->ResetVocabulary();
      ReleaseResultObject(resultobj);
    }
    catch (const sentencepiece::util::Status &status) {
      SWIG_exception(ToSwigError(status.code()), status.ToString().c_str());
    }
  }
  {
    if (!(&result)->ok()) {
      SWIG_exception(ToSwigError((&result)->code()), (&result)->ToString().c_str());
    }
    resultobj = SWIG_From_bool((&result)->ok());
  }
  return resultobj;
fail:
  return NULL;
}


SWIGINTERN PyObject *_wrap_SentencePieceProcessor_LoadVocabulary(PyObject *self, PyObject *args) {
  PyObject *resultobj = 0;
  sentencepiece::SentencePieceProcessor *arg1 = (sentencepiece::SentencePieceProcessor *) 0 ;
  absl::string_view arg2 ;
  int arg3 ;
  void *argp1 = 0 ;
  int res1 = 0 ;
  int val3 ;
  int ecode3 = 0 ;
  PyObject *swig_obj[3] ;
  sentencepiece::util::Status result;
  
  if (!SWIG_Python_UnpackTuple(args, "SentencePieceProcessor_LoadVocabulary", 3, 3, swig_obj)) SWIG_fail;
  res1 = SWIG_ConvertPtr(swig_obj[0], &argp1,SWIGTYPE_p_sentencepiece__SentencePieceProcessor, 0 |  0 );
  if (!SWIG_IsOK(res1)) {
    SWIG_exception_fail(SWIG_ArgError(res1), "in method '" "SentencePieceProcessor_LoadVocabulary" "', argument " "1"" of type '" "sentencepiece::SentencePieceProcessor *""'"); 
  }
  arg1 = reinterpret_cast< sentencepiece::SentencePieceProcessor * >(argp1);
  {
    const PyInputString ustring(swig_obj[1]);
    if (!ustring.IsAvalable()) {
      PyErr_SetString(PyExc_TypeError, "not a string");
      SWIG_fail;
    }
    resultobj = ustring.input_type();
    arg2 = ustring.str();
  }
  ecode3 = SWIG_AsVal_int(swig_obj[2], &val3);
  if (!SWIG_IsOK(ecode3)) {
    SWIG_exception_fail(SWIG_ArgError(ecode3), "in method '" "SentencePieceProcessor_LoadVocabulary" "', argument " "3"" of type '" "int""'");
  } 
  arg3 = static_cast< int >(val3);
  {
    try {
      result = (arg1)->LoadVocabulary(arg2,arg3);
      ReleaseResultObject(resultobj);
    }
    catch (const sentencepiece::util::Status &status) {
      SWIG_exception(ToSwigError(status.code()), status.ToString().c_str());
    }
  }
  {
    if (!(&result)->ok()) {
      SWIG_exception(ToSwigError((&result)->code()), (&result)->ToString().c_str());
    }
    resultobj = SWIG_From_bool((&result)->ok());
  }
  return resultobj;
fail:
  return NULL;
}


SWIGINTERN PyObject *_wrap_SentencePieceProcessor_CalculateEntropy__SWIG_0(PyObject *self, Py_ssize_t nobjs, PyObject **swig_obj) {
  PyObject *resultobj = 0;
  sentencepiece::SentencePieceProcessor *arg1 = (sentencepiece::SentencePieceProcessor *) 0 ;
  absl::string_view arg2 ;
  float arg3 ;
  float *arg4 = (float *) 0 ;
  void *argp1 = 0 ;
  int res1 = 0 ;
  float val3 ;
  int ecode3 = 0 ;
  void *argp4 = 0 ;
  int res4 = 0 ;
  sentencepiece::util::Status result;
  
  if ((nobjs < 4) || (nobjs > 4)) SWIG_fail;
  res1 = SWIG_ConvertPtr(swig_obj[0], &argp1,SWIGTYPE_p_sentencepiece__SentencePieceProcessor, 0 |  0 );
  if (!SWIG_IsOK(res1)) {
    SWIG_exception_fail(SWIG_ArgError(res1), "in method '" "SentencePieceProcessor_CalculateEntropy" "', argument " "1"" of type '" "sentencepiece::SentencePieceProcessor const *""'"); 
  }
  arg1 = reinterpret_cast< sentencepiece::SentencePieceProcessor * >(argp1);
  {
    const PyInputString ustring(swig_obj[1]);
    if (!ustring.IsAvalable()) {
      PyErr_SetString(PyExc_TypeError, "not a string");
      SWIG_fail;
    }
    resultobj = ustring.input_type();
    arg2 = ustring.str();
  }
  ecode3 = SWIG_AsVal_float(swig_obj[2], &val3);
  if (!SWIG_IsOK(ecode3)) {
    SWIG_exception_fail(SWIG_ArgError(ecode3), "in method '" "SentencePieceProcessor_CalculateEntropy" "', argument " "3"" of type '" "float""'");
  } 
  arg3 = static_cast< float >(val3);
  res4 = SWIG_ConvertPtr(swig_obj[3], &argp4,SWIGTYPE_p_float, 0 |  0 );
  if (!SWIG_IsOK(res4)) {
    SWIG_exception_fail(SWIG_ArgError(res4), "in method '" "SentencePieceProcessor_CalculateEntropy" "', argument " "4"" of type '" "float *""'"); 
  }
  arg4 = reinterpret_cast< float * >(argp4);
  {
    try {
      result = ((sentencepiece::SentencePieceProcessor const *)arg1)->CalculateEntropy(arg2,arg3,arg4);
      ReleaseResultObject(resultobj);
    }
    catch (const sentencepiece::util::Status &status) {
      SWIG_exception(ToSwigError(status.code()), status.ToString().c_str());
    }
  }
  {
    if (!(&result)->ok()) {
      SWIG_exception(ToSwigError((&result)->code()), (&result)->ToString().c_str());
    }
    resultobj = SWIG_From_bool((&result)->ok());
  }
  return resultobj;
fail:
  return NULL;
}


SWIGINTERN PyObject *_wrap_SentencePieceProcessor_CalculateEntropy__SWIG_1(PyObject *self, Py_ssize_t nobjs, PyObject **swig_obj) {
  PyObject *resultobj = 0;
  sentencepiece::SentencePieceProcessor *arg1 = (sentencepiece::SentencePieceProcessor *) 0 ;
  absl::string_view arg2 ;
  float arg3 ;
  void *argp1 = 0 ;
  int res1 = 0 ;
  float val3 ;
  int ecode3 = 0 ;
  float result;
  
  if ((nobjs < 3) || (nobjs > 3)) SWIG_fail;
  res1 = SWIG_ConvertPtr(swig_obj[0], &argp1,SWIGTYPE_p_sentencepiece__SentencePieceProcessor, 0 |  0 );
  if (!SWIG_IsOK(res1)) {
    SWIG_exception_fail(SWIG_ArgError(res1), "in method '" "SentencePieceProcessor_CalculateEntropy" "', argument " "1"" of type '" "sentencepiece::SentencePieceProcessor const *""'"); 
  }
  arg1 = reinterpret_cast< sentencepiece::SentencePieceProcessor * >(argp1);
  {
    const PyInputString ustring(swig_obj[1]);
    if (!ustring.IsAvalable()) {
      PyErr_SetString(PyExc_TypeError, "not a string");
      SWIG_fail;
    }
    resultobj = ustring.input_type();
    arg2 = ustring.str();
  }
  ecode3 = SWIG_AsVal_float(swig_obj[2], &val3);
  if (!SWIG_IsOK(ecode3)) {
    SWIG_exception_fail(SWIG_ArgError(ecode3), "in method '" "SentencePieceProcessor_CalculateEntropy" "', argument " "3"" of type '" "float""'");
  } 
  arg3 = static_cast< float >(val3);
  {
    try {
      result = (float)((sentencepiece::SentencePieceProcessor const *)arg1)->CalculateEntropy(arg2,arg3);
      ReleaseResultObject(resultobj);
    }
    catch (const sentencepiece::util::Status &status) {
      SWIG_exception(ToSwigError(status.code()), status.ToString().c_str());
    }
  }
  resultobj = SWIG_From_float(static_cast< float >(result));
  return resultobj;
fail:
  return NULL;
}


SWIGINTERN PyObject *_wrap_SentencePieceProcessor_CalculateEntropy(PyObject *self, PyObject *args) {
  Py_ssize_t argc;
  PyObject *argv[5] = {
    0
  };
  
  if (!(argc = SWIG_Python_UnpackTuple(args, "SentencePieceProcessor_CalculateEntropy", 0, 4, argv))) SWIG_fail;
  --argc;
  if (argc == 3) {
    int _v = 0;
    void *vptr = 0;
    int res = SWIG_ConvertPtr(argv[0], &vptr, SWIGTYPE_p_sentencepiece__SentencePieceProcessor, 0);
    _v = SWIG_CheckState(res);
    if (_v) {
      int res = SWIG_AsCharPtrAndSize(argv[1], 0, NULL, 0);
      _v = SWIG_CheckState(res);
      if (_v) {
        {
          int res = SWIG_AsVal_float(argv[2], NULL);
          _v = SWIG_CheckState(res);
        }
        if (_v) {
          return _wrap_SentencePieceProcessor_CalculateEntropy__SWIG_1(self, argc, argv);
        }
      }
    }
  }
  if (argc == 4) {
    int _v = 0;
    void *vptr = 0;
    int res = SWIG_ConvertPtr(argv[0], &vptr, SWIGTYPE_p_sentencepiece__SentencePieceProcessor, 0);
    _v = SWIG_CheckState(res);
    if (_v) {
      int res = SWIG_AsCharPtrAndSize(argv[1], 0, NULL, 0);
      _v = SWIG_CheckState(res);
      if (_v) {
        {
          int res = SWIG_AsVal_float(argv[2], NULL);
          _v = SWIG_CheckState(res);
        }
        if (_v) {
          void *vptr = 0;
          int res = SWIG_ConvertPtr(argv[3], &vptr, SWIGTYPE_p_float, 0);
          _v = SWIG_CheckState(res);
          if (_v) {
            return _wrap_SentencePieceProcessor_CalculateEntropy__SWIG_0(self, argc, argv);
          }
        }
      }
    }
  }
  
fail:
  SWIG_Python_RaiseOrModifyTypeError("Wrong number or type of arguments for overloaded function 'SentencePieceProcessor_CalculateEntropy'.\n"
    "  Possible C/C++ prototypes are:\n"
    "    sentencepiece::SentencePieceProcessor::CalculateEntropy(absl::string_view,float,float *) const\n"
    "    sentencepiece::SentencePieceProcessor::CalculateEntropy(absl::string_view,float) const\n");
  return 0;
}


SWIGINTERN PyObject *_wrap_SentencePieceProcessor_GetPieceSize(PyObject *self, PyObject *args) {
  PyObject *resultobj = 0;
  sentencepiece::SentencePieceProcessor *arg1 = (sentencepiece::SentencePieceProcessor *) 0 ;
  void *argp1 = 0 ;
  int res1 = 0 ;
  PyObject *swig_obj[1] ;
  int result;
  
  if (!args) SWIG_fail;
  swig_obj[0] = args;
  res1 = SWIG_ConvertPtr(swig_obj[0], &argp1,SWIGTYPE_p_sentencepiece__SentencePieceProcessor, 0 |  0 );
  if (!SWIG_IsOK(res1)) {
    SWIG_exception_fail(SWIG_ArgError(res1), "in method '" "SentencePieceProcessor_GetPieceSize" "', argument " "1"" of type '" "sentencepiece::SentencePieceProcessor const *""'"); 
  }
  arg1 = reinterpret_cast< sentencepiece::SentencePieceProcessor * >(argp1);
  {
    try {
      result = (int)((sentencepiece::SentencePieceProcessor const *)arg1)->GetPieceSize();
      ReleaseResultObject(resultobj);
    }
    catch (const sentencepiece::util::Status &status) {
      SWIG_exception(ToSwigError(status.code()), status.ToString().c_str());
    }
  }
  resultobj = SWIG_From_int(static_cast< int >(result));
  return resultobj;
fail:
  return NULL;
}


SWIGINTERN PyObject *_wrap_SentencePieceProcessor_PieceToId(PyObject *self, PyObject *args) {
  PyObject *resultobj = 0;
  sentencepiece::SentencePieceProcessor *arg1 = (sentencepiece::SentencePieceProcessor *) 0 ;
  absl::string_view arg2 ;
  void *argp1 = 0 ;
  int res1 = 0 ;
  PyObject *swig_obj[2] ;
  int result;
  
  if (!SWIG_Python_UnpackTuple(args, "SentencePieceProcessor_PieceToId", 2, 2, swig_obj)) SWIG_fail;
  res1 = SWIG_ConvertPtr(swig_obj[0], &argp1,SWIGTYPE_p_sentencepiece__SentencePieceProcessor, 0 |  0 );
  if (!SWIG_IsOK(res1)) {
    SWIG_exception_fail(SWIG_ArgError(res1), "in method '" "SentencePieceProcessor_PieceToId" "', argument " "1"" of type '" "sentencepiece::SentencePieceProcessor const *""'"); 
  }
  arg1 = reinterpret_cast< sentencepiece::SentencePieceProcessor * >(argp1);
  {
    const PyInputString ustring(swig_obj[1]);
    if (!ustring.IsAvalable()) {
      PyErr_SetString(PyExc_TypeError, "not a string");
      SWIG_fail;
    }
    resultobj = ustring.input_type();
    arg2 = ustring.str();
  }
  {
    try {
      result = (int)((sentencepiece::SentencePieceProcessor const *)arg1)->PieceToId(arg2);
      ReleaseResultObject(resultobj);
    }
    catch (const sentencepiece::util::Status &status) {
      SWIG_exception(ToSwigError(status.code()), status.ToString().c_str());
    }
  }
  resultobj = SWIG_From_int(static_cast< int >(result));
  return resultobj;
fail:
  return NULL;
}


SWIGINTERN PyObject *_wrap_SentencePieceProcessor_IdToPiece(PyObject *self, PyObject *args) {
  PyObject *resultobj = 0;
  sentencepiece::SentencePieceProcessor *arg1 = (sentencepiece::SentencePieceProcessor *) 0 ;
  int arg2 ;
  void *argp1 = 0 ;
  int res1 = 0 ;
  int val2 ;
  int ecode2 = 0 ;
  PyObject *swig_obj[2] ;
  std::string *result = 0 ;
  
  if (!SWIG_Python_UnpackTuple(args, "SentencePieceProcessor_IdToPiece", 2, 2, swig_obj)) SWIG_fail;
  res1 = SWIG_ConvertPtr(swig_obj[0], &argp1,SWIGTYPE_p_sentencepiece__SentencePieceProcessor, 0 |  0 );
  if (!SWIG_IsOK(res1)) {
    SWIG_exception_fail(SWIG_ArgError(res1), "in method '" "SentencePieceProcessor_IdToPiece" "', argument " "1"" of type '" "sentencepiece::SentencePieceProcessor const *""'"); 
  }
  arg1 = reinterpret_cast< sentencepiece::SentencePieceProcessor * >(argp1);
  ecode2 = SWIG_AsVal_int(swig_obj[1], &val2);
  if (!SWIG_IsOK(ecode2)) {
    SWIG_exception_fail(SWIG_ArgError(ecode2), "in method '" "SentencePieceProcessor_IdToPiece" "', argument " "2"" of type '" "int""'");
  } 
  arg2 = static_cast< int >(val2);
  {
    try {
      result = (std::string *) &((sentencepiece::SentencePieceProcessor const *)arg1)->IdToPiece(arg2);
      ReleaseResultObject(resultobj);
    }
    catch (const sentencepiece::util::Status &status) {
      SWIG_exception(ToSwigError(status.code()), status.ToString().c_str());
    }
  }
  {
    PyObject *input_type = resultobj;
    resultobj = MakePyOutputString(*result, input_type);
  }
  return resultobj;
fail:
  return NULL;
}


SWIGINTERN PyObject *_wrap_SentencePieceProcessor_GetScore(PyObject *self, PyObject *args) {
  PyObject *resultobj = 0;
  sentencepiece::SentencePieceProcessor *arg1 = (sentencepiece::SentencePieceProcessor *) 0 ;
  int arg2 ;
  void *argp1 = 0 ;
  int res1 = 0 ;
  int val2 ;
  int ecode2 = 0 ;
  PyObject *swig_obj[2] ;
  float result;
  
  if (!SWIG_Python_UnpackTuple(args, "SentencePieceProcessor_GetScore", 2, 2, swig_obj)) SWIG_fail;
  res1 = SWIG_ConvertPtr(swig_obj[0], &argp1,SWIGTYPE_p_sentencepiece__SentencePieceProcessor, 0 |  0 );
  if (!SWIG_IsOK(res1)) {
    SWIG_exception_fail(SWIG_ArgError(res1), "in method '" "SentencePieceProcessor_GetScore" "', argument " "1"" of type '" "sentencepiece::SentencePieceProcessor const *""'"); 
  }
  arg1 = reinterpret_cast< sentencepiece::SentencePieceProcessor * >(argp1);
  ecode2 = SWIG_AsVal_int(swig_obj[1], &val2);
  if (!SWIG_IsOK(ecode2)) {
    SWIG_exception_fail(SWIG_ArgError(ecode2), "in method '" "SentencePieceProcessor_GetScore" "', argument " "2"" of type '" "int""'");
  } 
  arg2 = static_cast< int >(val2);
  {
    try {
      result = (float)((sentencepiece::SentencePieceProcessor const *)arg1)->GetScore(arg2);
      ReleaseResultObject(resultobj);
    }
    catch (const sentencepiece::util::Status &status) {
      SWIG_exception(ToSwigError(status.code()), status.ToString().c_str());
    }
  }
  resultobj = SWIG_From_float(static_cast< float >(result));
  return resultobj;
fail:
  return NULL;
}


SWIGINTERN PyObject *_wrap_SentencePieceProcessor_IsUnknown(PyObject *self, PyObject *args) {
  PyObject *resultobj = 0;
  sentencepiece::SentencePieceProcessor *arg1 = (sentencepiece::SentencePieceProcessor *) 0 ;
  int arg2 ;
  void *argp1 = 0 ;
  int res1 = 0 ;
  int val2 ;
  int ecode2 = 0 ;
  PyObject *swig_obj[2] ;
  bool result;
  
  if (!SWIG_Python_UnpackTuple(args, "SentencePieceProcessor_IsUnknown", 2, 2, swig_obj)) SWIG_fail;
  res1 = SWIG_ConvertPtr(swig_obj[0], &argp1,SWIGTYPE_p_sentencepiece__SentencePieceProcessor, 0 |  0 );
  if (!SWIG_IsOK(res1)) {
    SWIG_exception_fail(SWIG_ArgError(res1), "in method '" "SentencePieceProcessor_IsUnknown" "', argument " "1"" of type '" "sentencepiece::SentencePieceProcessor const *""'"); 
  }
  arg1 = reinterpret_cast< sentencepiece::SentencePieceProcessor * >(argp1);
  ecode2 = SWIG_AsVal_int(swig_obj[1], &val2);
  if (!SWIG_IsOK(ecode2)) {
    SWIG_exception_fail(SWIG_ArgError(ecode2), "in method '" "SentencePieceProcessor_IsUnknown" "', argument " "2"" of type '" "int""'");
  } 
  arg2 = static_cast< int >(val2);
  {
    try {
      result = (bool)((sentencepiece::SentencePieceProcessor const *)arg1)->IsUnknown(arg2);
      ReleaseResultObject(resultobj);
    }
    catch (const sentencepiece::util::Status &status) {
      SWIG_exception(ToSwigError(status.code()), status.ToString().c_str());
    }
  }
  resultobj = SWIG_From_bool(static_cast< bool >(result));
  return resultobj;
fail:
  return NULL;
}


SWIGINTERN PyObject *_wrap_SentencePieceProcessor_IsControl(PyObject *self, PyObject *args) {
  PyObject *resultobj = 0;
  sentencepiece::SentencePieceProcessor *arg1 = (sentencepiece::SentencePieceProcessor *) 0 ;
  int arg2 ;
  void *argp1 = 0 ;
  int res1 = 0 ;
  int val2 ;
  int ecode2 = 0 ;
  PyObject *swig_obj[2] ;
  bool result;
  
  if (!SWIG_Python_UnpackTuple(args, "SentencePieceProcessor_IsControl", 2, 2, swig_obj)) SWIG_fail;
  res1 = SWIG_ConvertPtr(swig_obj[0], &argp1,SWIGTYPE_p_sentencepiece__SentencePieceProcessor, 0 |  0 );
  if (!SWIG_IsOK(res1)) {
    SWIG_exception_fail(SWIG_ArgError(res1), "in method '" "SentencePieceProcessor_IsControl" "', argument " "1"" of type '" "sentencepiece::SentencePieceProcessor const *""'"); 
  }
  arg1 = reinterpret_cast< sentencepiece::SentencePieceProcessor * >(argp1);
  ecode2 = SWIG_AsVal_int(swig_obj[1], &val2);
  if (!SWIG_IsOK(ecode2)) {
    SWIG_exception_fail(SWIG_ArgError(ecode2), "in method '" "SentencePieceProcessor_IsControl" "', argument " "2"" of type '" "int""'");
  } 
  arg2 = static_cast< int >(val2);
  {
    try {
      result = (bool)((sentencepiece::SentencePieceProcessor const *)arg1)->IsControl(arg2);
      ReleaseResultObject(resultobj);
    }
    catch (const sentencepiece::util::Status &status) {
      SWIG_exception(ToSwigError(status.code()), status.ToString().c_str());
    }
  }
  resultobj = SWIG_From_bool(static_cast< bool >(result));
  return resultobj;
fail:
  return NULL;
}


SWIGINTERN PyObject *_wrap_SentencePieceProcessor_IsUnused(PyObject *self, PyObject *args) {
  PyObject *resultobj = 0;
  sentencepiece::SentencePieceProcessor *arg1 = (sentencepiece::SentencePieceProcessor *) 0 ;
  int arg2 ;
  void *argp1 = 0 ;
  int res1 = 0 ;
  int val2 ;
  int ecode2 = 0 ;
  PyObject *swig_obj[2] ;
  bool result;
  
  if (!SWIG_Python_UnpackTuple(args, "SentencePieceProcessor_IsUnused", 2, 2, swig_obj)) SWIG_fail;
  res1 = SWIG_ConvertPtr(swig_obj[0], &argp1,SWIGTYPE_p_sentencepiece__SentencePieceProcessor, 0 |  0 );
  if (!SWIG_IsOK(res1)) {
    SWIG_exception_fail(SWIG_ArgError(res1), "in method '" "SentencePieceProcessor_IsUnused" "', argument " "1"" of type '" "sentencepiece::SentencePieceProcessor const *""'"); 
  }
  arg1 = reinterpret_cast< sentencepiece::SentencePieceProcessor * >(argp1);
  ecode2 = SWIG_AsVal_int(swig_obj[1], &val2);
  if (!SWIG_IsOK(ecode2)) {
    SWIG_exception_fail(SWIG_ArgError(ecode2), "in method '" "SentencePieceProcessor_IsUnused" "', argument " "2"" of type '" "int""'");
  } 
  arg2 = static_cast< int >(val2);
  {
    try {
      result = (bool)((sentencepiece::SentencePieceProcessor const *)arg1)->IsUnused(arg2);
      ReleaseResultObject(resultobj);
    }
    catch (const sentencepiece::util::Status &status) {
      SWIG_exception(ToSwigError(status.code()), status.ToString().c_str());
    }
  }
  resultobj = SWIG_From_bool(static_cast< bool >(result));
  return resultobj;
fail:
  return NULL;
}


SWIGINTERN PyObject *_wrap_SentencePieceProcessor_IsByte(PyObject *self, PyObject *args) {
  PyObject *resultobj = 0;
  sentencepiece::SentencePieceProcessor *arg1 = (sentencepiece::SentencePieceProcessor *) 0 ;
  int arg2 ;
  void *argp1 = 0 ;
  int res1 = 0 ;
  int val2 ;
  int ecode2 = 0 ;
  PyObject *swig_obj[2] ;
  bool result;
  
  if (!SWIG_Python_UnpackTuple(args, "SentencePieceProcessor_IsByte", 2, 2, swig_obj)) SWIG_fail;
  res1 = SWIG_ConvertPtr(swig_obj[0], &argp1,SWIGTYPE_p_sentencepiece__SentencePieceProcessor, 0 |  0 );
  if (!SWIG_IsOK(res1)) {
    SWIG_exception_fail(SWIG_ArgError(res1), "in method '" "SentencePieceProcessor_IsByte" "', argument " "1"" of type '" "sentencepiece::SentencePieceProcessor const *""'"); 
  }
  arg1 = reinterpret_cast< sentencepiece::SentencePieceProcessor * >(argp1);
  ecode2 = SWIG_AsVal_int(swig_obj[1], &val2);
  if (!SWIG_IsOK(ecode2)) {
    SWIG_exception_fail(SWIG_ArgError(ecode2), "in method '" "SentencePieceProcessor_IsByte" "', argument " "2"" of type '" "int""'");
  } 
  arg2 = static_cast< int >(val2);
  {
    try {
      result = (bool)((sentencepiece::SentencePieceProcessor const *)arg1)->IsByte(arg2);
      ReleaseResultObject(resultobj);
    }
    catch (const sentencepiece::util::Status &status) {
      SWIG_exception(ToSwigError(status.code()), status.ToString().c_str());
    }
  }
  resultobj = SWIG_From_bool(static_cast< bool >(result));
  return resultobj;
fail:
  return NULL;
}


SWIGINTERN PyObject *_wrap_SentencePieceProcessor_unk_id(PyObject *self, PyObject *args) {
  PyObject *resultobj = 0;
  sentencepiece::SentencePieceProcessor *arg1 = (sentencepiece::SentencePieceProcessor *) 0 ;
  void *argp1 = 0 ;
  int res1 = 0 ;
  PyObject *swig_obj[1] ;
  int result;
  
  if (!args) SWIG_fail;
  swig_obj[0] = args;
  res1 = SWIG_ConvertPtr(swig_obj[0], &argp1,SWIGTYPE_p_sentencepiece__SentencePieceProcessor, 0 |  0 );
  if (!SWIG_IsOK(res1)) {
    SWIG_exception_fail(SWIG_ArgError(res1), "in method '" "SentencePieceProcessor_unk_id" "', argument " "1"" of type '" "sentencepiece::SentencePieceProcessor const *""'"); 
  }
  arg1 = reinterpret_cast< sentencepiece::SentencePieceProcessor * >(argp1);
  {
    try {
      result = (int)((sentencepiece::SentencePieceProcessor const *)arg1)->unk_id();
      ReleaseResultObject(resultobj);
    }
    catch (const sentencepiece::util::Status &status) {
      SWIG_exception(ToSwigError(status.code()), status.ToString().c_str());
    }
  }
  resultobj = SWIG_From_int(static_cast< int >(result));
  return resultobj;
fail:
  return NULL;
}


SWIGINTERN PyObject *_wrap_SentencePieceProcessor_bos_id(PyObject *self, PyObject *args) {
  PyObject *resultobj = 0;
  sentencepiece::SentencePieceProcessor *arg1 = (sentencepiece::SentencePieceProcessor *) 0 ;
  void *argp1 = 0 ;
  int res1 = 0 ;
  PyObject *swig_obj[1] ;
  int result;
  
  if (!args) SWIG_fail;
  swig_obj[0] = args;
  res1 = SWIG_ConvertPtr(swig_obj[0], &argp1,SWIGTYPE_p_sentencepiece__SentencePieceProcessor, 0 |  0 );
  if (!SWIG_IsOK(res1)) {
    SWIG_exception_fail(SWIG_ArgError(res1), "in method '" "SentencePieceProcessor_bos_id" "', argument " "1"" of type '" "sentencepiece::SentencePieceProcessor const *""'"); 
  }
  arg1 = reinterpret_cast< sentencepiece::SentencePieceProcessor * >(argp1);
  {
    try {
      result = (int)((sentencepiece::SentencePieceProcessor const *)arg1)->bos_id();
      ReleaseResultObject(resultobj);
    }
    catch (const sentencepiece::util::Status &status) {
      SWIG_exception(ToSwigError(status.code()), status.ToString().c_str());
    }
  }
  resultobj = SWIG_From_int(static_cast< int >(result));
  return resultobj;
fail:
  return NULL;
}


SWIGINTERN PyObject *_wrap_SentencePieceProcessor_eos_id(PyObject *self, PyObject *args) {
  PyObject *resultobj = 0;
  sentencepiece::SentencePieceProcessor *arg1 = (sentencepiece::SentencePieceProcessor *) 0 ;
  void *argp1 = 0 ;
  int res1 = 0 ;
  PyObject *swig_obj[1] ;
  int result;
  
  if (!args) SWIG_fail;
  swig_obj[0] = args;
  res1 = SWIG_ConvertPtr(swig_obj[0], &argp1,SWIGTYPE_p_sentencepiece__SentencePieceProcessor, 0 |  0 );
  if (!SWIG_IsOK(res1)) {
    SWIG_exception_fail(SWIG_ArgError(res1), "in method '" "SentencePieceProcessor_eos_id" "', argument " "1"" of type '" "sentencepiece::SentencePieceProcessor const *""'"); 
  }
  arg1 = reinterpret_cast< sentencepiece::SentencePieceProcessor * >(argp1);
  {
    try {
      result = (int)((sentencepiece::SentencePieceProcessor const *)arg1)->eos_id();
      ReleaseResultObject(resultobj);
    }
    catch (const sentencepiece::util::Status &status) {
      SWIG_exception(ToSwigError(status.code()), status.ToString().c_str());
    }
  }
  resultobj = SWIG_From_int(static_cast< int >(result));
  return resultobj;
fail:
  return NULL;
}


SWIGINTERN PyObject *_wrap_SentencePieceProcessor_pad_id(PyObject *self, PyObject *args) {
  PyObject *resultobj = 0;
  sentencepiece::SentencePieceProcessor *arg1 = (sentencepiece::SentencePieceProcessor *) 0 ;
  void *argp1 = 0 ;
  int res1 = 0 ;
  PyObject *swig_obj[1] ;
  int result;
  
  if (!args) SWIG_fail;
  swig_obj[0] = args;
  res1 = SWIG_ConvertPtr(swig_obj[0], &argp1,SWIGTYPE_p_sentencepiece__SentencePieceProcessor, 0 |  0 );
  if (!SWIG_IsOK(res1)) {
    SWIG_exception_fail(SWIG_ArgError(res1), "in method '" "SentencePieceProcessor_pad_id" "', argument " "1"" of type '" "sentencepiece::SentencePieceProcessor const *""'"); 
  }
  arg1 = reinterpret_cast< sentencepiece::SentencePieceProcessor * >(argp1);
  {
    try {
      result = (int)((sentencepiece::SentencePieceProcessor const *)arg1)->pad_id();
      ReleaseResultObject(resultobj);
    }
    catch (const sentencepiece::util::Status &status) {
      SWIG_exception(ToSwigError(status.code()), status.ToString().c_str());
    }
  }
  resultobj = SWIG_From_int(static_cast< int >(result));
  return resultobj;
fail:
  return NULL;
}


SWIGINTERN PyObject *_wrap_SentencePieceProcessor_serialized_model_proto(PyObject *self, PyObject *args) {
  PyObject *resultobj = 0;
  sentencepiece::SentencePieceProcessor *arg1 = (sentencepiece::SentencePieceProcessor *) 0 ;
  void *argp1 = 0 ;
  int res1 = 0 ;
  PyObject *swig_obj[1] ;
  sentencepiece::util::bytes result;
  
  if (!args) SWIG_fail;
  swig_obj[0] = args;
  res1 = SWIG_ConvertPtr(swig_obj[0], &argp1,SWIGTYPE_p_sentencepiece__SentencePieceProcessor, 0 |  0 );
  if (!SWIG_IsOK(res1)) {
    SWIG_exception_fail(SWIG_ArgError(res1), "in method '" "SentencePieceProcessor_serialized_model_proto" "', argument " "1"" of type '" "sentencepiece::SentencePieceProcessor const *""'"); 
  }
  arg1 = reinterpret_cast< sentencepiece::SentencePieceProcessor * >(argp1);
  {
    try {
      result = ((sentencepiece::SentencePieceProcessor const *)arg1)->serialized_model_proto();
      ReleaseResultObject(resultobj);
    }
    catch (const sentencepiece::util::Status &status) {
      SWIG_exception(ToSwigError(status.code()), status.ToString().c_str());
    }
  }
  {
    resultobj = MakePyOutputBytes(result);
  }
  return resultobj;
fail:
  return NULL;
}


SWIGINTERN PyObject *_wrap_SentencePieceProcessor_LoadFromFile(PyObject *self, PyObject *args) {
  PyObject *resultobj = 0;
  sentencepiece::SentencePieceProcessor *arg1 = (sentencepiece::SentencePieceProcessor *) 0 ;
  absl::string_view arg2 ;
  void *argp1 = 0 ;
  int res1 = 0 ;
  PyObject *swig_obj[2] ;
  sentencepiece::util::Status result;
  
  if (!SWIG_Python_UnpackTuple(args, "SentencePieceProcessor_LoadFromFile", 2, 2, swig_obj)) SWIG_fail;
  res1 = SWIG_ConvertPtr(swig_obj[0], &argp1,SWIGTYPE_p_sentencepiece__SentencePieceProcessor, 0 |  0 );
  if (!SWIG_IsOK(res1)) {
    SWIG_exception_fail(SWIG_ArgError(res1), "in method '" "SentencePieceProcessor_LoadFromFile" "', argument " "1"" of type '" "sentencepiece::SentencePieceProcessor *""'"); 
  }
  arg1 = reinterpret_cast< sentencepiece::SentencePieceProcessor * >(argp1);
  {
    const PyInputString ustring(swig_obj[1]);
    if (!ustring.IsAvalable()) {
      PyErr_SetString(PyExc_TypeError, "not a string");
      SWIG_fail;
    }
    resultobj = ustring.input_type();
    arg2 = ustring.str();
  }
  {
    try {
      result = sentencepiece_SentencePieceProcessor_LoadFromFile(arg1,SWIG_STD_MOVE(arg2));
      ReleaseResultObject(resultobj);
    }
    catch (const sentencepiece::util::Status &status) {
      SWIG_exception(ToSwigError(status.code()), status.ToString().c_str());
    }
  }
  {
    if (!(&result)->ok()) {
      SWIG_exception(ToSwigError((&result)->code()), (&result)->ToString().c_str());
    }
    resultobj = SWIG_From_bool((&result)->ok());
  }
  return resultobj;
fail:
  return NULL;
}


SWIGINTERN PyObject *_wrap_SentencePieceProcessor__EncodeAsIds(PyObject *self, PyObject *args) {
  PyObject *resultobj = 0;
  sentencepiece::SentencePieceProcessor *arg1 = (sentencepiece::SentencePieceProcessor *) 0 ;
  absl::string_view arg2 ;
  bool arg3 ;
  int arg4 ;
  float arg5 ;
  bool arg6 ;
  bool arg7 ;
  bool arg8 ;
  bool arg9 ;
  void *argp1 = 0 ;
  int res1 = 0 ;
  bool val3 ;
  int ecode3 = 0 ;
  int val4 ;
  int ecode4 = 0 ;
  float val5 ;
  int ecode5 = 0 ;
  bool val6 ;
  int ecode6 = 0 ;
  bool val7 ;
  int ecode7 = 0 ;
  bool val8 ;
  int ecode8 = 0 ;
  bool val9 ;
  int ecode9 = 0 ;
  PyObject *swig_obj[9] ;
  std::vector< int > result;
  
  if (!SWIG_Python_UnpackTuple(args, "SentencePieceProcessor__EncodeAsIds", 9, 9, swig_obj)) SWIG_fail;
  res1 = SWIG_ConvertPtr(swig_obj[0], &argp1,SWIGTYPE_p_sentencepiece__SentencePieceProcessor, 0 |  0 );
  if (!SWIG_IsOK(res1)) {
    SWIG_exception_fail(SWIG_ArgError(res1), "in method '" "SentencePieceProcessor__EncodeAsIds" "', argument " "1"" of type '" "sentencepiece::SentencePieceProcessor const *""'"); 
  }
  arg1 = reinterpret_cast< sentencepiece::SentencePieceProcessor * >(argp1);
  {
    const PyInputString ustring(swig_obj[1]);
    if (!ustring.IsAvalable()) {
      PyErr_SetString(PyExc_TypeError, "not a string");
      SWIG_fail;
    }
    resultobj = ustring.input_type();
    arg2 = ustring.str();
  }
  ecode3 = SWIG_AsVal_bool(swig_obj[2], &val3);
  if (!SWIG_IsOK(ecode3)) {
    SWIG_exception_fail(SWIG_ArgError(ecode3), "in method '" "SentencePieceProcessor__EncodeAsIds" "', argument " "3"" of type '" "bool""'");
  } 
  arg3 = static_cast< bool >(val3);
  ecode4 = SWIG_AsVal_int(swig_obj[3], &val4);
  if (!SWIG_IsOK(ecode4)) {
    SWIG_exception_fail(SWIG_ArgError(ecode4), "in method '" "SentencePieceProcessor__EncodeAsIds" "', argument " "4"" of type '" "int""'");
  } 
  arg4 = static_cast< int >(val4);
  ecode5 = SWIG_AsVal_float(swig_obj[4], &val5);
  if (!SWIG_IsOK(ecode5)) {
    SWIG_exception_fail(SWIG_ArgError(ecode5), "in method '" "SentencePieceProcessor__EncodeAsIds" "', argument " "5"" of type '" "float""'");
  } 
  arg5 = static_cast< float >(val5);
  ecode6 = SWIG_AsVal_bool(swig_obj[5], &val6);
  if (!SWIG_IsOK(ecode6)) {
    SWIG_exception_fail(SWIG_ArgError(ecode6), "in method '" "SentencePieceProcessor__EncodeAsIds" "', argument " "6"" of type '" "bool""'");
  } 
  arg6 = static_cast< bool >(val6);
  ecode7 = SWIG_AsVal_bool(swig_obj[6], &val7);
  if (!SWIG_IsOK(ecode7)) {
    SWIG_exception_fail(SWIG_ArgError(ecode7), "in method '" "SentencePieceProcessor__EncodeAsIds" "', argument " "7"" of type '" "bool""'");
  } 
  arg7 = static_cast< bool >(val7);
  ecode8 = SWIG_AsVal_bool(swig_obj[7], &val8);
  if (!SWIG_IsOK(ecode8)) {
    SWIG_exception_fail(SWIG_ArgError(ecode8), "in method '" "SentencePieceProcessor__EncodeAsIds" "', argument " "8"" of type '" "bool""'");
  } 
  arg8 = static_cast< bool >(val8);
  ecode9 = SWIG_AsVal_bool(swig_obj[8], &val9);
  if (!SWIG_IsOK(ecode9)) {
    SWIG_exception_fail(SWIG_ArgError(ecode9), "in method '" "SentencePieceProcessor__EncodeAsIds" "', argument " "9"" of type '" "bool""'");
  } 
  arg9 = static_cast< bool >(val9);
  {
    try {
      result = sentencepiece_SentencePieceProcessor__EncodeAsIds((sentencepiece::SentencePieceProcessor const *)arg1,SWIG_STD_MOVE(arg2),arg3,arg4,arg5,arg6,arg7,arg8,arg9);
      ReleaseResultObject(resultobj);
    }
    catch (const sentencepiece::util::Status &status) {
      SWIG_exception(ToSwigError(status.code()), status.ToString().c_str());
    }
  }
  {
    resultobj = PyList_New((&result)->size());
    for (size_t i = 0; i < (&result)->size(); ++i) {
      PyList_SET_ITEM(resultobj, i, PyInt_FromLong(static_cast<long>(result[i])));
    }
  }
  return resultobj;
fail:
  return NULL;
}


SWIGINTERN PyObject *_wrap_SentencePieceProcessor__EncodeAsPieces(PyObject *self, PyObject *args) {
  PyObject *resultobj = 0;
  sentencepiece::SentencePieceProcessor *arg1 = (sentencepiece::SentencePieceProcessor *) 0 ;
  absl::string_view arg2 ;
  bool arg3 ;
  int arg4 ;
  float arg5 ;
  bool arg6 ;
  bool arg7 ;
  bool arg8 ;
  bool arg9 ;
  void *argp1 = 0 ;
  int res1 = 0 ;
  bool val3 ;
  int ecode3 = 0 ;
  int val4 ;
  int ecode4 = 0 ;
  float val5 ;
  int ecode5 = 0 ;
  bool val6 ;
  int ecode6 = 0 ;
  bool val7 ;
  int ecode7 = 0 ;
  bool val8 ;
  int ecode8 = 0 ;
  bool val9 ;
  int ecode9 = 0 ;
  PyObject *swig_obj[9] ;
  std::vector< std::string > result;
  
  if (!SWIG_Python_UnpackTuple(args, "SentencePieceProcessor__EncodeAsPieces", 9, 9, swig_obj)) SWIG_fail;
  res1 = SWIG_ConvertPtr(swig_obj[0], &argp1,SWIGTYPE_p_sentencepiece__SentencePieceProcessor, 0 |  0 );
  if (!SWIG_IsOK(res1)) {
    SWIG_exception_fail(SWIG_ArgError(res1), "in method '" "SentencePieceProcessor__EncodeAsPieces" "', argument " "1"" of type '" "sentencepiece::SentencePieceProcessor const *""'"); 
  }
  arg1 = reinterpret_cast< sentencepiece::SentencePieceProcessor * >(argp1);
  {
    const PyInputString ustring(swig_obj[1]);
    if (!ustring.IsAvalable()) {
      PyErr_SetString(PyExc_TypeError, "not a string");
      SWIG_fail;
    }
    resultobj = ustring.input_type();
    arg2 = ustring.str();
  }
  ecode3 = SWIG_AsVal_bool(swig_obj[2], &val3);
  if (!SWIG_IsOK(ecode3)) {
    SWIG_exception_fail(SWIG_ArgError(ecode3), "in method '" "SentencePieceProcessor__EncodeAsPieces" "', argument " "3"" of type '" "bool""'");
  } 
  arg3 = static_cast< bool >(val3);
  ecode4 = SWIG_AsVal_int(swig_obj[3], &val4);
  if (!SWIG_IsOK(ecode4)) {
    SWIG_exception_fail(SWIG_ArgError(ecode4), "in method '" "SentencePieceProcessor__EncodeAsPieces" "', argument " "4"" of type '" "int""'");
  } 
  arg4 = static_cast< int >(val4);
  ecode5 = SWIG_AsVal_float(swig_obj[4], &val5);
  if (!SWIG_IsOK(ecode5)) {
    SWIG_exception_fail(SWIG_ArgError(ecode5), "in method '" "SentencePieceProcessor__EncodeAsPieces" "', argument " "5"" of type '" "float""'");
  } 
  arg5 = static_cast< float >(val5);
  ecode6 = SWIG_AsVal_bool(swig_obj[5], &val6);
  if (!SWIG_IsOK(ecode6)) {
    SWIG_exception_fail(SWIG_ArgError(ecode6), "in method '" "SentencePieceProcessor__EncodeAsPieces" "', argument " "6"" of type '" "bool""'");
  } 
  arg6 = static_cast< bool >(val6);
  ecode7 = SWIG_AsVal_bool(swig_obj[6], &val7);
  if (!SWIG_IsOK(ecode7)) {
    SWIG_exception_fail(SWIG_ArgError(ecode7), "in method '" "SentencePieceProcessor__EncodeAsPieces" "', argument " "7"" of type '" "bool""'");
  } 
  arg7 = static_cast< bool >(val7);
  ecode8 = SWIG_AsVal_bool(swig_obj[7], &val8);
  if (!SWIG_IsOK(ecode8)) {
    SWIG_exception_fail(SWIG_ArgError(ecode8), "in method '" "SentencePieceProcessor__EncodeAsPieces" "', argument " "8"" of type '" "bool""'");
  } 
  arg8 = static_cast< bool >(val8);
  ecode9 = SWIG_AsVal_bool(swig_obj[8], &val9);
  if (!SWIG_IsOK(ecode9)) {
    SWIG_exception_fail(SWIG_ArgError(ecode9), "in method '" "SentencePieceProcessor__EncodeAsPieces" "', argument " "9"" of type '" "bool""'");
  } 
  arg9 = static_cast< bool >(val9);
  {
    try {
      result = sentencepiece_SentencePieceProcessor__EncodeAsPieces((sentencepiece::SentencePieceProcessor const *)arg1,SWIG_STD_MOVE(arg2),arg3,arg4,arg5,arg6,arg7,arg8,arg9);
      ReleaseResultObject(resultobj);
    }
    catch (const sentencepiece::util::Status &status) {
      SWIG_exception(ToSwigError(status.code()), status.ToString().c_str());
    }
  }
  {
    PyObject *input_type = resultobj;
    resultobj = PyList_New((&result)->size());
    for (size_t i = 0; i < (&result)->size(); ++i) {
      PyList_SET_ITEM(resultobj, i, MakePyOutputString(result[i], input_type));
    }
  }
  return resultobj;
fail:
  return NULL;
}


SWIGINTERN PyObject *_wrap_SentencePieceProcessor__EncodeAsSerializedProto(PyObject *self, PyObject *args) {
  PyObject *resultobj = 0;
  sentencepiece::SentencePieceProcessor *arg1 = (sentencepiece::SentencePieceProcessor *) 0 ;
  absl::string_view arg2 ;
  bool arg3 ;
  int arg4 ;
  float arg5 ;
  bool arg6 ;
  bool arg7 ;
  bool arg8 ;
  bool arg9 ;
  void *argp1 = 0 ;
  int res1 = 0 ;
  bool val3 ;
  int ecode3 = 0 ;
  int val4 ;
  int ecode4 = 0 ;
  float val5 ;
  int ecode5 = 0 ;
  bool val6 ;
  int ecode6 = 0 ;
  bool val7 ;
  int ecode7 = 0 ;
  bool val8 ;
  int ecode8 = 0 ;
  bool val9 ;
  int ecode9 = 0 ;
  PyObject *swig_obj[9] ;
  sentencepiece::util::bytes result;
  
  if (!SWIG_Python_UnpackTuple(args, "SentencePieceProcessor__EncodeAsSerializedProto", 9, 9, swig_obj)) SWIG_fail;
  res1 = SWIG_ConvertPtr(swig_obj[0], &argp1,SWIGTYPE_p_sentencepiece__SentencePieceProcessor, 0 |  0 );
  if (!SWIG_IsOK(res1)) {
    SWIG_exception_fail(SWIG_ArgError(res1), "in method '" "SentencePieceProcessor__EncodeAsSerializedProto" "', argument " "1"" of type '" "sentencepiece::SentencePieceProcessor const *""'"); 
  }
  arg1 = reinterpret_cast< sentencepiece::SentencePieceProcessor * >(argp1);
  {
    const PyInputString ustring(swig_obj[1]);
    if (!ustring.IsAvalable()) {
      PyErr_SetString(PyExc_TypeError, "not a string");
      SWIG_fail;
    }
    resultobj = ustring.input_type();
    arg2 = ustring.str();
  }
  ecode3 = SWIG_AsVal_bool(swig_obj[2], &val3);
  if (!SWIG_IsOK(ecode3)) {
    SWIG_exception_fail(SWIG_ArgError(ecode3), "in method '" "SentencePieceProcessor__EncodeAsSerializedProto" "', argument " "3"" of type '" "bool""'");
  } 
  arg3 = static_cast< bool >(val3);
  ecode4 = SWIG_AsVal_int(swig_obj[3], &val4);
  if (!SWIG_IsOK(ecode4)) {
    SWIG_exception_fail(SWIG_ArgError(ecode4), "in method '" "SentencePieceProcessor__EncodeAsSerializedProto" "', argument " "4"" of type '" "int""'");
  } 
  arg4 = static_cast< int >(val4);
  ecode5 = SWIG_AsVal_float(swig_obj[4], &val5);
  if (!SWIG_IsOK(ecode5)) {
    SWIG_exception_fail(SWIG_ArgError(ecode5), "in method '" "SentencePieceProcessor__EncodeAsSerializedProto" "', argument " "5"" of type '" "float""'");
  } 
  arg5 = static_cast< float >(val5);
  ecode6 = SWIG_AsVal_bool(swig_obj[5], &val6);
  if (!SWIG_IsOK(ecode6)) {
    SWIG_exception_fail(SWIG_ArgError(ecode6), "in method '" "SentencePieceProcessor__EncodeAsSerializedProto" "', argument " "6"" of type '" "bool""'");
  } 
  arg6 = static_cast< bool >(val6);
  ecode7 = SWIG_AsVal_bool(swig_obj[6], &val7);
  if (!SWIG_IsOK(ecode7)) {
    SWIG_exception_fail(SWIG_ArgError(ecode7), "in method '" "SentencePieceProcessor__EncodeAsSerializedProto" "', argument " "7"" of type '" "bool""'");
  } 
  arg7 = static_cast< bool >(val7);
  ecode8 = SWIG_AsVal_bool(swig_obj[7], &val8);
  if (!SWIG_IsOK(ecode8)) {
    SWIG_exception_fail(SWIG_ArgError(ecode8), "in method '" "SentencePieceProcessor__EncodeAsSerializedProto" "', argument " "8"" of type '" "bool""'");
  } 
  arg8 = static_cast< bool >(val8);
  ecode9 = SWIG_AsVal_bool(swig_obj[8], &val9);
  if (!SWIG_IsOK(ecode9)) {
    SWIG_exception_fail(SWIG_ArgError(ecode9), "in method '" "SentencePieceProcessor__EncodeAsSerializedProto" "', argument " "9"" of type '" "bool""'");
  } 
  arg9 = static_cast< bool >(val9);
  {
    try {
      result = sentencepiece_SentencePieceProcessor__EncodeAsSerializedProto((sentencepiece::SentencePieceProcessor const *)arg1,SWIG_STD_MOVE(arg2),arg3,arg4,arg5,arg6,arg7,arg8,arg9);
      ReleaseResultObject(resultobj);
    }
    catch (const sentencepiece::util::Status &status) {
      SWIG_exception(ToSwigError(status.code()), status.ToString().c_str());
    }
  }
  {
    resultobj = MakePyOutputBytes(result);
  }
  return resultobj;
fail:
  return NULL;
}


SWIGINTERN PyObject *_wrap_SentencePieceProcessor__EncodeAsImmutableProto(PyObject *self, PyObject *args) {
  PyObject *resultobj = 0;
  sentencepiece::SentencePieceProcessor *arg1 = (sentencepiece::SentencePieceProcessor *) 0 ;
  absl::string_view arg2 ;
  bool arg3 ;
  int arg4 ;
  float arg5 ;
  bool arg6 ;
  bool arg7 ;
  bool arg8 ;
  bool arg9 ;
  void *argp1 = 0 ;
  int res1 = 0 ;
  bool val3 ;
  int ecode3 = 0 ;
  int val4 ;
  int ecode4 = 0 ;
  float val5 ;
  int ecode5 = 0 ;
  bool val6 ;
  int ecode6 = 0 ;
  bool val7 ;
  int ecode7 = 0 ;
  bool val8 ;
  int ecode8 = 0 ;
  bool val9 ;
  int ecode9 = 0 ;
  PyObject *swig_obj[9] ;
  sentencepiece::ImmutableSentencePieceText result;
  
  if (!SWIG_Python_UnpackTuple(args, "SentencePieceProcessor__EncodeAsImmutableProto", 9, 9, swig_obj)) SWIG_fail;
  res1 = SWIG_ConvertPtr(swig_obj[0], &argp1,SWIGTYPE_p_sentencepiece__SentencePieceProcessor, 0 |  0 );
  if (!SWIG_IsOK(res1)) {
    SWIG_exception_fail(SWIG_ArgError(res1), "in method '" "SentencePieceProcessor__EncodeAsImmutableProto" "', argument " "1"" of type '" "sentencepiece::SentencePieceProcessor const *""'"); 
  }
  arg1 = reinterpret_cast< sentencepiece::SentencePieceProcessor * >(argp1);
  {
    const PyInputString ustring(swig_obj[1]);
    if (!ustring.IsAvalable()) {
      PyErr_SetString(PyExc_TypeError, "not a string");
      SWIG_fail;
    }
    resultobj = ustring.input_type();
    arg2 = ustring.str();
  }
  ecode3 = SWIG_AsVal_bool(swig_obj[2], &val3);
  if (!SWIG_IsOK(ecode3)) {
    SWIG_exception_fail(SWIG_ArgError(ecode3), "in method '" "SentencePieceProcessor__EncodeAsImmutableProto" "', argument " "3"" of type '" "bool""'");
  } 
  arg3 = static_cast< bool >(val3);
  ecode4 = SWIG_AsVal_int(swig_obj[3], &val4);
  if (!SWIG_IsOK(ecode4)) {
    SWIG_exception_fail(SWIG_ArgError(ecode4), "in method '" "SentencePieceProcessor__EncodeAsImmutableProto" "', argument " "4"" of type '" "int""'");
  } 
  arg4 = static_cast< int >(val4);
  ecode5 = SWIG_AsVal_float(swig_obj[4], &val5);
  if (!SWIG_IsOK(ecode5)) {
    SWIG_exception_fail(SWIG_ArgError(ecode5), "in method '" "SentencePieceProcessor__EncodeAsImmutableProto" "', argument " "5"" of type '" "float""'");
  } 
  arg5 = static_cast< float >(val5);
  ecode6 = SWIG_AsVal_bool(swig_obj[5], &val6);
  if (!SWIG_IsOK(ecode6)) {
    SWIG_exception_fail(SWIG_ArgError(ecode6), "in method '" "SentencePieceProcessor__EncodeAsImmutableProto" "', argument " "6"" of type '" "bool""'");
  } 
  arg6 = static_cast< bool >(val6);
  ecode7 = SWIG_AsVal_bool(swig_obj[6], &val7);
  if (!SWIG_IsOK(ecode7)) {
    SWIG_exception_fail(SWIG_ArgError(ecode7), "in method '" "SentencePieceProcessor__EncodeAsImmutableProto" "', argument " "7"" of type '" "bool""'");
  } 
  arg7 = static_cast< bool >(val7);
  ecode8 = SWIG_AsVal_bool(swig_obj[7], &val8);
  if (!SWIG_IsOK(ecode8)) {
    SWIG_exception_fail(SWIG_ArgError(ecode8), "in method '" "SentencePieceProcessor__EncodeAsImmutableProto" "', argument " "8"" of type '" "bool""'");
  } 
  arg8 = static_cast< bool >(val8);
  ecode9 = SWIG_AsVal_bool(swig_obj[8], &val9);
  if (!SWIG_IsOK(ecode9)) {
    SWIG_exception_fail(SWIG_ArgError(ecode9), "in method '" "SentencePieceProcessor__EncodeAsImmutableProto" "', argument " "9"" of type '" "bool""'");
  } 
  arg9 = static_cast< bool >(val9);
  {
    try {
      result = sentencepiece_SentencePieceProcessor__EncodeAsImmutableProto((sentencepiece::SentencePieceProcessor const *)arg1,SWIG_STD_MOVE(arg2),arg3,arg4,arg5,arg6,arg7,arg8,arg9);
      ReleaseResultObject(resultobj);
    }
    catch (const sentencepiece::util::Status &status) {
      SWIG_exception(ToSwigError(status.code()), status.ToString().c_str());
    }
  }
  resultobj = SWIG_NewPointerObj((new sentencepiece::ImmutableSentencePieceText(result)), SWIGTYPE_p_sentencepiece__ImmutableSentencePieceText, SWIG_POINTER_OWN |  0 );
  return resultobj;
fail:
  return NULL;
}


SWIGINTERN PyObject *_wrap_SentencePieceProcessor__EncodeAsIdsBatch(PyObject *self, PyObject *args) {
  PyObject *resultobj = 0;
  sentencepiece::SentencePieceProcessor *arg1 = (sentencepiece::SentencePieceProcessor *) 0 ;
  std::vector< absl::string_view > *arg2 = 0 ;
  int arg3 ;
  bool arg4 ;
  int arg5 ;
  float arg6 ;
  bool arg7 ;
  bool arg8 ;
  bool arg9 ;
  bool arg10 ;
  void *argp1 = 0 ;
  int res1 = 0 ;
  int val3 ;
  int ecode3 = 0 ;
  bool val4 ;
  int ecode4 = 0 ;
  int val5 ;
  int ecode5 = 0 ;
  float val6 ;
  int ecode6 = 0 ;
  bool val7 ;
  int ecode7 = 0 ;
  bool val8 ;
  int ecode8 = 0 ;
  bool val9 ;
  int ecode9 = 0 ;
  bool val10 ;
  int ecode10 = 0 ;
  PyObject *swig_obj[10] ;
  std::vector< std::vector< int > > result;
  
  if (!SWIG_Python_UnpackTuple(args, "SentencePieceProcessor__EncodeAsIdsBatch", 10, 10, swig_obj)) SWIG_fail;
  res1 = SWIG_ConvertPtr(swig_obj[0], &argp1,SWIGTYPE_p_sentencepiece__SentencePieceProcessor, 0 |  0 );
  if (!SWIG_IsOK(res1)) {
    SWIG_exception_fail(SWIG_ArgError(res1), "in method '" "SentencePieceProcessor__EncodeAsIdsBatch" "', argument " "1"" of type '" "sentencepiece::SentencePieceProcessor const *""'"); 
  }
  arg1 = reinterpret_cast< sentencepiece::SentencePieceProcessor * >(argp1);
  {
    std::vector<absl::string_view> *out = nullptr;
    if (PyList_Check(swig_obj[1])) {
      const size_t size = PyList_Size(swig_obj[1]);
      out = new std::vector<absl::string_view>(size);
      for (size_t i = 0; i < size; ++i) {
        const PyInputString ustring(PyList_GetItem(swig_obj[1], i));
        if (ustring.IsAvalable()) {
          (*out)[i] = ustring.str();
        } else {
          PyErr_SetString(PyExc_TypeError, "list must contain strings");
          SWIG_fail;
        }
        resultobj = ustring.input_type();
      }
    } else {
      PyErr_SetString(PyExc_TypeError, "not a list");
      SWIG_fail;
    }
    arg2 = out;
  }
  ecode3 = SWIG_AsVal_int(swig_obj[2], &val3);
  if (!SWIG_IsOK(ecode3)) {
    SWIG_exception_fail(SWIG_ArgError(ecode3), "in method '" "SentencePieceProcessor__EncodeAsIdsBatch" "', argument " "3"" of type '" "int""'");
  } 
  arg3 = static_cast< int >(val3);
  ecode4 = SWIG_AsVal_bool(swig_obj[3], &val4);
  if (!SWIG_IsOK(ecode4)) {
    SWIG_exception_fail(SWIG_ArgError(ecode4), "in method '" "SentencePieceProcessor__EncodeAsIdsBatch" "', argument " "4"" of type '" "bool""'");
  } 
  arg4 = static_cast< bool >(val4);
  ecode5 = SWIG_AsVal_int(swig_obj[4], &val5);
  if (!SWIG_IsOK(ecode5)) {
    SWIG_exception_fail(SWIG_ArgError(ecode5), "in method '" "SentencePieceProcessor__EncodeAsIdsBatch" "', argument " "5"" of type '" "int""'");
  } 
  arg5 = static_cast< int >(val5);
  ecode6 = SWIG_AsVal_float(swig_obj[5], &val6);
  if (!SWIG_IsOK(ecode6)) {
    SWIG_exception_fail(SWIG_ArgError(ecode6), "in method '" "SentencePieceProcessor__EncodeAsIdsBatch" "', argument " "6"" of type '" "float""'");
  } 
  arg6 = static_cast< float >(val6);
  ecode7 = SWIG_AsVal_bool(swig_obj[6], &val7);
  if (!SWIG_IsOK(ecode7)) {
    SWIG_exception_fail(SWIG_ArgError(ecode7), "in method '" "SentencePieceProcessor__EncodeAsIdsBatch" "', argument " "7"" of type '" "bool""'");
  } 
  arg7 = static_cast< bool >(val7);
  ecode8 = SWIG_AsVal_bool(swig_obj[7], &val8);
  if (!SWIG_IsOK(ecode8)) {
    SWIG_exception_fail(SWIG_ArgError(ecode8), "in method '" "SentencePieceProcessor__EncodeAsIdsBatch" "', argument " "8"" of type '" "bool""'");
  } 
  arg8 = static_cast< bool >(val8);
  ecode9 = SWIG_AsVal_bool(swig_obj[8], &val9);
  if (!SWIG_IsOK(ecode9)) {
    SWIG_exception_fail(SWIG_ArgError(ecode9), "in method '" "SentencePieceProcessor__EncodeAsIdsBatch" "', argument " "9"" of type '" "bool""'");
  } 
  arg9 = static_cast< bool >(val9);
  ecode10 = SWIG_AsVal_bool(swig_obj[9], &val10);
  if (!SWIG_IsOK(ecode10)) {
    SWIG_exception_fail(SWIG_ArgError(ecode10), "in method '" "SentencePieceProcessor__EncodeAsIdsBatch" "', argument " "10"" of type '" "bool""'");
  } 
  arg10 = static_cast< bool >(val10);
  {
    try {
      result = sentencepiece_SentencePieceProcessor__EncodeAsIdsBatch((sentencepiece::SentencePieceProcessor const *)arg1,(std::vector< absl::string_view > const &)*arg2,arg3,arg4,arg5,arg6,arg7,arg8,arg9,arg10);
      ReleaseResultObject(resultobj);
    }
    catch (const sentencepiece::util::Status &status) {
      SWIG_exception(ToSwigError(status.code()), status.ToString().c_str());
    }
  }
  {
    resultobj = PyList_New((&result)->size());
    for (size_t i = 0; i < (&result)->size(); ++i) {
      PyObject *obj = PyList_New(result[i].size());
      for (size_t j = 0; j < result[i].size(); ++j) {
        PyList_SET_ITEM(obj, j, PyInt_FromLong(static_cast<long>(result[i][j])));
      }
      PyList_SET_ITEM(resultobj, i, obj);
    }
  }
  {
    delete arg2;
  }
  return resultobj;
fail:
  {
    delete arg2;
  }
  return NULL;
}


SWIGINTERN PyObject *_wrap_SentencePieceProcessor__EncodeAsPiecesBatch(PyObject *self, PyObject *args) {
  PyObject *resultobj = 0;
  sentencepiece::SentencePieceProcessor *arg1 = (sentencepiece::SentencePieceProcessor *) 0 ;
  std::vector< absl::string_view > *arg2 = 0 ;
  int arg3 ;
  bool arg4 ;
  int arg5 ;
  float arg6 ;
  bool arg7 ;
  bool arg8 ;
  bool arg9 ;
  bool arg10 ;
  void *argp1 = 0 ;
  int res1 = 0 ;
  int val3 ;
  int ecode3 = 0 ;
  bool val4 ;
  int ecode4 = 0 ;
  int val5 ;
  int ecode5 = 0 ;
  float val6 ;
  int ecode6 = 0 ;
  bool val7 ;
  int ecode7 = 0 ;
  bool val8 ;
  int ecode8 = 0 ;
  bool val9 ;
  int ecode9 = 0 ;
  bool val10 ;
  int ecode10 = 0 ;
  PyObject *swig_obj[10] ;
  std::vector< std::vector< std::string > > result;
  
  if (!SWIG_Python_UnpackTuple(args, "SentencePieceProcessor__EncodeAsPiecesBatch", 10, 10, swig_obj)) SWIG_fail;
  res1 = SWIG_ConvertPtr(swig_obj[0], &argp1,SWIGTYPE_p_sentencepiece__SentencePieceProcessor, 0 |  0 );
  if (!SWIG_IsOK(res1)) {
    SWIG_exception_fail(SWIG_ArgError(res1), "in method '" "SentencePieceProcessor__EncodeAsPiecesBatch" "', argument " "1"" of type '" "sentencepiece::SentencePieceProcessor const *""'"); 
  }
  arg1 = reinterpret_cast< sentencepiece::SentencePieceProcessor * >(argp1);
  {
    std::vector<absl::string_view> *out = nullptr;
    if (PyList_Check(swig_obj[1])) {
      const size_t size = PyList_Size(swig_obj[1]);
      out = new std::vector<absl::string_view>(size);
      for (size_t i = 0; i < size; ++i) {
        const PyInputString ustring(PyList_GetItem(swig_obj[1], i));
        if (ustring.IsAvalable()) {
          (*out)[i] = ustring.str();
        } else {
          PyErr_SetString(PyExc_TypeError, "list must contain strings");
          SWIG_fail;
        }
        resultobj = ustring.input_type();
      }
    } else {
      PyErr_SetString(PyExc_TypeError, "not a list");
      SWIG_fail;
    }
    arg2 = out;
  }
  ecode3 = SWIG_AsVal_int(swig_obj[2], &val3);
  if (!SWIG_IsOK(ecode3)) {
    SWIG_exception_fail(SWIG_ArgError(ecode3), "in method '" "SentencePieceProcessor__EncodeAsPiecesBatch" "', argument " "3"" of type '" "int""'");
  } 
  arg3 = static_cast< int >(val3);
  ecode4 = SWIG_AsVal_bool(swig_obj[3], &val4);
  if (!SWIG_IsOK(ecode4)) {
    SWIG_exception_fail(SWIG_ArgError(ecode4), "in method '" "SentencePieceProcessor__EncodeAsPiecesBatch" "', argument " "4"" of type '" "bool""'");
  } 
  arg4 = static_cast< bool >(val4);
  ecode5 = SWIG_AsVal_int(swig_obj[4], &val5);
  if (!SWIG_IsOK(ecode5)) {
    SWIG_exception_fail(SWIG_ArgError(ecode5), "in method '" "SentencePieceProcessor__EncodeAsPiecesBatch" "', argument " "5"" of type '" "int""'");
  } 
  arg5 = static_cast< int >(val5);
  ecode6 = SWIG_AsVal_float(swig_obj[5], &val6);
  if (!SWIG_IsOK(ecode6)) {
    SWIG_exception_fail(SWIG_ArgError(ecode6), "in method '" "SentencePieceProcessor__EncodeAsPiecesBatch" "', argument " "6"" of type '" "float""'");
  } 
  arg6 = static_cast< float >(val6);
  ecode7 = SWIG_AsVal_bool(swig_obj[6], &val7);
  if (!SWIG_IsOK(ecode7)) {
    SWIG_exception_fail(SWIG_ArgError(ecode7), "in method '" "SentencePieceProcessor__EncodeAsPiecesBatch" "', argument " "7"" of type '" "bool""'");
  } 
  arg7 = static_cast< bool >(val7);
  ecode8 = SWIG_AsVal_bool(swig_obj[7], &val8);
  if (!SWIG_IsOK(ecode8)) {
    SWIG_exception_fail(SWIG_ArgError(ecode8), "in method '" "SentencePieceProcessor__EncodeAsPiecesBatch" "', argument " "8"" of type '" "bool""'");
  } 
  arg8 = static_cast< bool >(val8);
  ecode9 = SWIG_AsVal_bool(swig_obj[8], &val9);
  if (!SWIG_IsOK(ecode9)) {
    SWIG_exception_fail(SWIG_ArgError(ecode9), "in method '" "SentencePieceProcessor__EncodeAsPiecesBatch" "', argument " "9"" of type '" "bool""'");
  } 
  arg9 = static_cast< bool >(val9);
  ecode10 = SWIG_AsVal_bool(swig_obj[9], &val10);
  if (!SWIG_IsOK(ecode10)) {
    SWIG_exception_fail(SWIG_ArgError(ecode10), "in method '" "SentencePieceProcessor__EncodeAsPiecesBatch" "', argument " "10"" of type '" "bool""'");
  } 
  arg10 = static_cast< bool >(val10);
  {
    try {
      result = sentencepiece_SentencePieceProcessor__EncodeAsPiecesBatch((sentencepiece::SentencePieceProcessor const *)arg1,(std::vector< absl::string_view > const &)*arg2,arg3,arg4,arg5,arg6,arg7,arg8,arg9,arg10);
      ReleaseResultObject(resultobj);
    }
    catch (const sentencepiece::util::Status &status) {
      SWIG_exception(ToSwigError(status.code()), status.ToString().c_str());
    }
  }
  {
    PyObject *input_type = resultobj;
    resultobj = PyList_New((&result)->size());
    for (size_t i = 0; i < (&result)->size(); ++i) {
      PyObject *obj = PyList_New(result[i].size());
      for (size_t j = 0; j < result[i].size(); ++j) {
        PyList_SET_ITEM(obj, j, MakePyOutputString(result[i][j], input_type));
      }
      PyList_SET_ITEM(resultobj, i, obj);
    }
  }
  {
    delete arg2;
  }
  return resultobj;
fail:
  {
    delete arg2;
  }
  return NULL;
}


SWIGINTERN PyObject *_wrap_SentencePieceProcessor__EncodeAsSerializedProtoBatch(PyObject *self, PyObject *args) {
  PyObject *resultobj = 0;
  sentencepiece::SentencePieceProcessor *arg1 = (sentencepiece::SentencePieceProcessor *) 0 ;
  std::vector< absl::string_view > *arg2 = 0 ;
  int arg3 ;
  bool arg4 ;
  int arg5 ;
  float arg6 ;
  bool arg7 ;
  bool arg8 ;
  bool arg9 ;
  bool arg10 ;
  void *argp1 = 0 ;
  int res1 = 0 ;
  int val3 ;
  int ecode3 = 0 ;
  bool val4 ;
  int ecode4 = 0 ;
  int val5 ;
  int ecode5 = 0 ;
  float val6 ;
  int ecode6 = 0 ;
  bool val7 ;
  int ecode7 = 0 ;
  bool val8 ;
  int ecode8 = 0 ;
  bool val9 ;
  int ecode9 = 0 ;
  bool val10 ;
  int ecode10 = 0 ;
  PyObject *swig_obj[10] ;
  BytesArray result;
  
  if (!SWIG_Python_UnpackTuple(args, "SentencePieceProcessor__EncodeAsSerializedProtoBatch", 10, 10, swig_obj)) SWIG_fail;
  res1 = SWIG_ConvertPtr(swig_obj[0], &argp1,SWIGTYPE_p_sentencepiece__SentencePieceProcessor, 0 |  0 );
  if (!SWIG_IsOK(res1)) {
    SWIG_exception_fail(SWIG_ArgError(res1), "in method '" "SentencePieceProcessor__EncodeAsSerializedProtoBatch" "', argument " "1"" of type '" "sentencepiece::SentencePieceProcessor const *""'"); 
  }
  arg1 = reinterpret_cast< sentencepiece::SentencePieceProcessor * >(argp1);
  {
    std::vector<absl::string_view> *out = nullptr;
    if (PyList_Check(swig_obj[1])) {
      const size_t size = PyList_Size(swig_obj[1]);
      out = new std::vector<absl::string_view>(size);
      for (size_t i = 0; i < size; ++i) {
        const PyInputString ustring(PyList_GetItem(swig_obj[1], i));
        if (ustring.IsAvalable()) {
          (*out)[i] = ustring.str();
        } else {
          PyErr_SetString(PyExc_TypeError, "list must contain strings");
          SWIG_fail;
        }
        resultobj = ustring.input_type();
      }
    } else {
      PyErr_SetString(PyExc_TypeError, "not a list");
      SWIG_fail;
    }
    arg2 = out;
  }
  ecode3 = SWIG_AsVal_int(swig_obj[2], &val3);
  if (!SWIG_IsOK(ecode3)) {
    SWIG_exception_fail(SWIG_ArgError(ecode3), "in method '" "SentencePieceProcessor__EncodeAsSerializedProtoBatch" "', argument " "3"" of type '" "int""'");
  } 
  arg3 = static_cast< int >(val3);
  ecode4 = SWIG_AsVal_bool(swig_obj[3], &val4);
  if (!SWIG_IsOK(ecode4)) {
    SWIG_exception_fail(SWIG_ArgError(ecode4), "in method '" "SentencePieceProcessor__EncodeAsSerializedProtoBatch" "', argument " "4"" of type '" "bool""'");
  } 
  arg4 = static_cast< bool >(val4);
  ecode5 = SWIG_AsVal_int(swig_obj[4], &val5);
  if (!SWIG_IsOK(ecode5)) {
    SWIG_exception_fail(SWIG_ArgError(ecode5), "in method '" "SentencePieceProcessor__EncodeAsSerializedProtoBatch" "', argument " "5"" of type '" "int""'");
  } 
  arg5 = static_cast< int >(val5);
  ecode6 = SWIG_AsVal_float(swig_obj[5], &val6);
  if (!SWIG_IsOK(ecode6)) {
    SWIG_exception_fail(SWIG_ArgError(ecode6), "in method '" "SentencePieceProcessor__EncodeAsSerializedProtoBatch" "', argument " "6"" of type '" "float""'");
  } 
  arg6 = static_cast< float >(val6);
  ecode7 = SWIG_AsVal_bool(swig_obj[6], &val7);
  if (!SWIG_IsOK(ecode7)) {
    SWIG_exception_fail(SWIG_ArgError(ecode7), "in method '" "SentencePieceProcessor__EncodeAsSerializedProtoBatch" "', argument " "7"" of type '" "bool""'");
  } 
  arg7 = static_cast< bool >(val7);
  ecode8 = SWIG_AsVal_bool(swig_obj[7], &val8);
  if (!SWIG_IsOK(ecode8)) {
    SWIG_exception_fail(SWIG_ArgError(ecode8), "in method '" "SentencePieceProcessor__EncodeAsSerializedProtoBatch" "', argument " "8"" of type '" "bool""'");
  } 
  arg8 = static_cast< bool >(val8);
  ecode9 = SWIG_AsVal_bool(swig_obj[8], &val9);
  if (!SWIG_IsOK(ecode9)) {
    SWIG_exception_fail(SWIG_ArgError(ecode9), "in method '" "SentencePieceProcessor__EncodeAsSerializedProtoBatch" "', argument " "9"" of type '" "bool""'");
  } 
  arg9 = static_cast< bool >(val9);
  ecode10 = SWIG_AsVal_bool(swig_obj[9], &val10);
  if (!SWIG_IsOK(ecode10)) {
    SWIG_exception_fail(SWIG_ArgError(ecode10), "in method '" "SentencePieceProcessor__EncodeAsSerializedProtoBatch" "', argument " "10"" of type '" "bool""'");
  } 
  arg10 = static_cast< bool >(val10);
  {
    try {
      result = sentencepiece_SentencePieceProcessor__EncodeAsSerializedProtoBatch((sentencepiece::SentencePieceProcessor const *)arg1,(std::vector< absl::string_view > const &)*arg2,arg3,arg4,arg5,arg6,arg7,arg8,arg9,arg10);
      ReleaseResultObject(resultobj);
    }
    catch (const sentencepiece::util::Status &status) {
      SWIG_exception(ToSwigError(status.code()), status.ToString().c_str());
    }
  }
  {
    resultobj = PyList_New((&result)->size());
    for (size_t i = 0; i < (&result)->size(); ++i) {
      PyList_SET_ITEM(resultobj, i, MakePyOutputBytes(result[i]));
    }
  }
  {
    delete arg2;
  }
  return resultobj;
fail:
  {
    delete arg2;
  }
  return NULL;
}


SWIGINTERN PyObject *_wrap_SentencePieceProcessor__EncodeAsImmutableProtoBatch(PyObject *self, PyObject *args) {
  PyObject *resultobj = 0;
  sentencepiece::SentencePieceProcessor *arg1 = (sentencepiece::SentencePieceProcessor *) 0 ;
  std::vector< absl::string_view > *arg2 = 0 ;
  int arg3 ;
  bool arg4 ;
  int arg5 ;
  float arg6 ;
  bool arg7 ;
  bool arg8 ;
  bool arg9 ;
  bool arg10 ;
  void *argp1 = 0 ;
  int res1 = 0 ;
  int val3 ;
  int ecode3 = 0 ;
  bool val4 ;
  int ecode4 = 0 ;
  int val5 ;
  int ecode5 = 0 ;
  float val6 ;
  int ecode6 = 0 ;
  bool val7 ;
  int ecode7 = 0 ;
  bool val8 ;
  int ecode8 = 0 ;
  bool val9 ;
  int ecode9 = 0 ;
  bool val10 ;
  int ecode10 = 0 ;
  PyObject *swig_obj[10] ;
  SwigValueWrapper< std::vector< sentencepiece::ImmutableSentencePieceText > > result;
  
  if (!SWIG_Python_UnpackTuple(args, "SentencePieceProcessor__EncodeAsImmutableProtoBatch", 10, 10, swig_obj)) SWIG_fail;
  res1 = SWIG_ConvertPtr(swig_obj[0], &argp1,SWIGTYPE_p_sentencepiece__SentencePieceProcessor, 0 |  0 );
  if (!SWIG_IsOK(res1)) {
    SWIG_exception_fail(SWIG_ArgError(res1), "in method '" "SentencePieceProcessor__EncodeAsImmutableProtoBatch" "', argument " "1"" of type '" "sentencepiece::SentencePieceProcessor const *""'"); 
  }
  arg1 = reinterpret_cast< sentencepiece::SentencePieceProcessor * >(argp1);
  {
    std::vector<absl::string_view> *out = nullptr;
    if (PyList_Check(swig_obj[1])) {
      const size_t size = PyList_Size(swig_obj[1]);
      out = new std::vector<absl::string_view>(size);
      for (size_t i = 0; i < size; ++i) {
        const PyInputString ustring(PyList_GetItem(swig_obj[1], i));
        if (ustring.IsAvalable()) {
          (*out)[i] = ustring.str();
        } else {
          PyErr_SetString(PyExc_TypeError, "list must contain strings");
          SWIG_fail;
        }
        resultobj = ustring.input_type();
      }
    } else {
      PyErr_SetString(PyExc_TypeError, "not a list");
      SWIG_fail;
    }
    arg2 = out;
  }
  ecode3 = SWIG_AsVal_int(swig_obj[2], &val3);
  if (!SWIG_IsOK(ecode3)) {
    SWIG_exception_fail(SWIG_ArgError(ecode3), "in method '" "SentencePieceProcessor__EncodeAsImmutableProtoBatch" "', argument " "3"" of type '" "int""'");
  } 
  arg3 = static_cast< int >(val3);
  ecode4 = SWIG_AsVal_bool(swig_obj[3], &val4);
  if (!SWIG_IsOK(ecode4)) {
    SWIG_exception_fail(SWIG_ArgError(ecode4), "in method '" "SentencePieceProcessor__EncodeAsImmutableProtoBatch" "', argument " "4"" of type '" "bool""'");
  } 
  arg4 = static_cast< bool >(val4);
  ecode5 = SWIG_AsVal_int(swig_obj[4], &val5);
  if (!SWIG_IsOK(ecode5)) {
    SWIG_exception_fail(SWIG_ArgError(ecode5), "in method '" "SentencePieceProcessor__EncodeAsImmutableProtoBatch" "', argument " "5"" of type '" "int""'");
  } 
  arg5 = static_cast< int >(val5);
  ecode6 = SWIG_AsVal_float(swig_obj[5], &val6);
  if (!SWIG_IsOK(ecode6)) {
    SWIG_exception_fail(SWIG_ArgError(ecode6), "in method '" "SentencePieceProcessor__EncodeAsImmutableProtoBatch" "', argument " "6"" of type '" "float""'");
  } 
  arg6 = static_cast< float >(val6);
  ecode7 = SWIG_AsVal_bool(swig_obj[6], &val7);
  if (!SWIG_IsOK(ecode7)) {
    SWIG_exception_fail(SWIG_ArgError(ecode7), "in method '" "SentencePieceProcessor__EncodeAsImmutableProtoBatch" "', argument " "7"" of type '" "bool""'");
  } 
  arg7 = static_cast< bool >(val7);
  ecode8 = SWIG_AsVal_bool(swig_obj[7], &val8);
  if (!SWIG_IsOK(ecode8)) {
    SWIG_exception_fail(SWIG_ArgError(ecode8), "in method '" "SentencePieceProcessor__EncodeAsImmutableProtoBatch" "', argument " "8"" of type '" "bool""'");
  } 
  arg8 = static_cast< bool >(val8);
  ecode9 = SWIG_AsVal_bool(swig_obj[8], &val9);
  if (!SWIG_IsOK(ecode9)) {
    SWIG_exception_fail(SWIG_ArgError(ecode9), "in method '" "SentencePieceProcessor__EncodeAsImmutableProtoBatch" "', argument " "9"" of type '" "bool""'");
  } 
  arg9 = static_cast< bool >(val9);
  ecode10 = SWIG_AsVal_bool(swig_obj[9], &val10);
  if (!SWIG_IsOK(ecode10)) {
    SWIG_exception_fail(SWIG_ArgError(ecode10), "in method '" "SentencePieceProcessor__EncodeAsImmutableProtoBatch" "', argument " "10"" of type '" "bool""'");
  } 
  arg10 = static_cast< bool >(val10);
  {
    try {
      result = sentencepiece_SentencePieceProcessor__EncodeAsImmutableProtoBatch((sentencepiece::SentencePieceProcessor const *)arg1,(std::vector< absl::string_view > const &)*arg2,arg3,arg4,arg5,arg6,arg7,arg8,arg9,arg10);
      ReleaseResultObject(resultobj);
    }
    catch (const sentencepiece::util::Status &status) {
      SWIG_exception(ToSwigError(status.code()), status.ToString().c_str());
    }
  }
  {
    resultobj = PyList_New((&result)->size());
    for (size_t i = 0; i < (&result)->size(); ++i) {
      PyObject *obj = SWIG_NewPointerObj(new sentencepiece::ImmutableSentencePieceText((&result)->at(i)), SWIGTYPE_p_sentencepiece__ImmutableSentencePieceText, SWIG_POINTER_OWN | 0);
      PyList_SET_ITEM(resultobj, i, obj);
    }
  }
  {
    delete arg2;
  }
  return resultobj;
fail:
  {
    delete arg2;
  }
  return NULL;
}


SWIGINTERN PyObject *_wrap_SentencePieceProcessor__DecodeIds(PyObject *self, PyObject *args) {
  PyObject *resultobj = 0;
  sentencepiece::SentencePieceProcessor *arg1 = (sentencepiece::SentencePieceProcessor *) 0 ;
  std::vector< int > *arg2 = 0 ;
  void *argp1 = 0 ;
  int res1 = 0 ;
  PyObject *swig_obj[2] ;
  std::string result;
  
  if (!SWIG_Python_UnpackTuple(args, "SentencePieceProcessor__DecodeIds", 2, 2, swig_obj)) SWIG_fail;
  res1 = SWIG_ConvertPtr(swig_obj[0], &argp1,SWIGTYPE_p_sentencepiece__SentencePieceProcessor, 0 |  0 );
  if (!SWIG_IsOK(res1)) {
    SWIG_exception_fail(SWIG_ArgError(res1), "in method '" "SentencePieceProcessor__DecodeIds" "', argument " "1"" of type '" "sentencepiece::SentencePieceProcessor const *""'"); 
  }
  arg1 = reinterpret_cast< sentencepiece::SentencePieceProcessor * >(argp1);
  {
    std::vector<int> *out = nullptr;
    if (PyList_Check(swig_obj[1])) {
      const size_t size = PyList_Size(swig_obj[1]);
      out = new std::vector<int>(size);
      for (size_t i = 0; i < size; ++i) {
        PyObject *o = PyList_GetItem(swig_obj[1], i);
        if (PyInt_Check(o)) {
          (*out)[i] = static_cast<int>(PyInt_AsLong(o));
        } else {
          PyErr_SetString(PyExc_TypeError,"list must contain integers");
          SWIG_fail;
        }
      }
    } else {
      PyErr_SetString(PyExc_TypeError,"not a list");
      SWIG_fail;
    }
    arg2 = out;
  }
  {
    try {
      result = sentencepiece_SentencePieceProcessor__DecodeIds((sentencepiece::SentencePieceProcessor const *)arg1,(std::vector< int > const &)*arg2);
      ReleaseResultObject(resultobj);
    }
    catch (const sentencepiece::util::Status &status) {
      SWIG_exception(ToSwigError(status.code()), status.ToString().c_str());
    }
  }
  {
    PyObject *input_type = resultobj;
    resultobj = MakePyOutputString(result, input_type);
  }
  {
    delete arg2;
  }
  return resultobj;
fail:
  {
    delete arg2;
  }
  return NULL;
}


SWIGINTERN PyObject *_wrap_SentencePieceProcessor__DecodeIdsAsBytes(PyObject *self, PyObject *args) {
  PyObject *resultobj = 0;
  sentencepiece::SentencePieceProcessor *arg1 = (sentencepiece::SentencePieceProcessor *) 0 ;
  std::vector< int > *arg2 = 0 ;
  void *argp1 = 0 ;
  int res1 = 0 ;
  PyObject *swig_obj[2] ;
  sentencepiece::util::bytes result;
  
  if (!SWIG_Python_UnpackTuple(args, "SentencePieceProcessor__DecodeIdsAsBytes", 2, 2, swig_obj)) SWIG_fail;
  res1 = SWIG_ConvertPtr(swig_obj[0], &argp1,SWIGTYPE_p_sentencepiece__SentencePieceProcessor, 0 |  0 );
  if (!SWIG_IsOK(res1)) {
    SWIG_exception_fail(SWIG_ArgError(res1), "in method '" "SentencePieceProcessor__DecodeIdsAsBytes" "', argument " "1"" of type '" "sentencepiece::SentencePieceProcessor const *""'"); 
  }
  arg1 = reinterpret_cast< sentencepiece::SentencePieceProcessor * >(argp1);
  {
    std::vector<int> *out = nullptr;
    if (PyList_Check(swig_obj[1])) {
      const size_t size = PyList_Size(swig_obj[1]);
      out = new std::vector<int>(size);
      for (size_t i = 0; i < size; ++i) {
        PyObject *o = PyList_GetItem(swig_obj[1], i);
        if (PyInt_Check(o)) {
          (*out)[i] = static_cast<int>(PyInt_AsLong(o));
        } else {
          PyErr_SetString(PyExc_TypeError,"list must contain integers");
          SWIG_fail;
        }
      }
    } else {
      PyErr_SetString(PyExc_TypeError,"not a list");
      SWIG_fail;
    }
    arg2 = out;
  }
  {
    try {
      result = sentencepiece_SentencePieceProcessor__DecodeIdsAsBytes((sentencepiece::SentencePieceProcessor const *)arg1,(std::vector< int > const &)*arg2);
      ReleaseResultObject(resultobj);
    }
    catch (const sentencepiece::util::Status &status) {
      SWIG_exception(ToSwigError(status.code()), status.ToString().c_str());
    }
  }
  {
    resultobj = MakePyOutputBytes(result);
  }
  {
    delete arg2;
  }
  return resultobj;
fail:
  {
    delete arg2;
  }
  return NULL;
}


SWIGINTERN PyObject *_wrap_SentencePieceProcessor__DecodePieces(PyObject *self, PyObject *args) {
  PyObject *resultobj = 0;
  sentencepiece::SentencePieceProcessor *arg1 = (sentencepiece::SentencePieceProcessor *) 0 ;
  std::vector< absl::string_view > *arg2 = 0 ;
  void *argp1 = 0 ;
  int res1 = 0 ;
  PyObject *swig_obj[2] ;
  std::string result;
  
  if (!SWIG_Python_UnpackTuple(args, "SentencePieceProcessor__DecodePieces", 2, 2, swig_obj)) SWIG_fail;
  res1 = SWIG_ConvertPtr(swig_obj[0], &argp1,SWIGTYPE_p_sentencepiece__SentencePieceProcessor, 0 |  0 );
  if (!SWIG_IsOK(res1)) {
    SWIG_exception_fail(SWIG_ArgError(res1), "in method '" "SentencePieceProcessor__DecodePieces" "', argument " "1"" of type '" "sentencepiece::SentencePieceProcessor const *""'"); 
  }
  arg1 = reinterpret_cast< sentencepiece::SentencePieceProcessor * >(argp1);
  {
    std::vector<absl::string_view> *out = nullptr;
    if (PyList_Check(swig_obj[1])) {
      const size_t size = PyList_Size(swig_obj[1]);
      out = new std::vector<absl::string_view>(size);
      for (size_t i = 0; i < size; ++i) {
        const PyInputString ustring(PyList_GetItem(swig_obj[1], i));
        if (ustring.IsAvalable()) {
          (*out)[i] = ustring.str();
        } else {
          PyErr_SetString(PyExc_TypeError, "list must contain strings");
          SWIG_fail;
        }
        resultobj = ustring.input_type();
      }
    } else {
      PyErr_SetString(PyExc_TypeError, "not a list");
      SWIG_fail;
    }
    arg2 = out;
  }
  {
    try {
      result = sentencepiece_SentencePieceProcessor__DecodePieces((sentencepiece::SentencePieceProcessor const *)arg1,(std::vector< absl::string_view > const &)*arg2);
      ReleaseResultObject(resultobj);
    }
    catch (const sentencepiece::util::Status &status) {
      SWIG_exception(ToSwigError(status.code()), status.ToString().c_str());
    }
  }
  {
    PyObject *input_type = resultobj;
    resultobj = MakePyOutputString(result, input_type);
  }
  {
    delete arg2;
  }
  return resultobj;
fail:
  {
    delete arg2;
  }
  return NULL;
}


SWIGINTERN PyObject *_wrap_SentencePieceProcessor__DecodeIdsAsSerializedProto(PyObject *self, PyObject *args) {
  PyObject *resultobj = 0;
  sentencepiece::SentencePieceProcessor *arg1 = (sentencepiece::SentencePieceProcessor *) 0 ;
  std::vector< int > *arg2 = 0 ;
  void *argp1 = 0 ;
  int res1 = 0 ;
  PyObject *swig_obj[2] ;
  sentencepiece::util::bytes result;
  
  if (!SWIG_Python_UnpackTuple(args, "SentencePieceProcessor__DecodeIdsAsSerializedProto", 2, 2, swig_obj)) SWIG_fail;
  res1 = SWIG_ConvertPtr(swig_obj[0], &argp1,SWIGTYPE_p_sentencepiece__SentencePieceProcessor, 0 |  0 );
  if (!SWIG_IsOK(res1)) {
    SWIG_exception_fail(SWIG_ArgError(res1), "in method '" "SentencePieceProcessor__DecodeIdsAsSerializedProto" "', argument " "1"" of type '" "sentencepiece::SentencePieceProcessor const *""'"); 
  }
  arg1 = reinterpret_cast< sentencepiece::SentencePieceProcessor * >(argp1);
  {
    std::vector<int> *out = nullptr;
    if (PyList_Check(swig_obj[1])) {
      const size_t size = PyList_Size(swig_obj[1]);
      out = new std::vector<int>(size);
      for (size_t i = 0; i < size; ++i) {
        PyObject *o = PyList_GetItem(swig_obj[1], i);
        if (PyInt_Check(o)) {
          (*out)[i] = static_cast<int>(PyInt_AsLong(o));
        } else {
          PyErr_SetString(PyExc_TypeError,"list must contain integers");
          SWIG_fail;
        }
      }
    } else {
      PyErr_SetString(PyExc_TypeError,"not a list");
      SWIG_fail;
    }
    arg2 = out;
  }
  {
    try {
      result = sentencepiece_SentencePieceProcessor__DecodeIdsAsSerializedProto((sentencepiece::SentencePieceProcessor const *)arg1,(std::vector< int > const &)*arg2);
      ReleaseResultObject(resultobj);
    }
    catch (const sentencepiece::util::Status &status) {
      SWIG_exception(ToSwigError(status.code()), status.ToString().c_str());
    }
  }
  {
    resultobj = MakePyOutputBytes(result);
  }
  {
    delete arg2;
  }
  return resultobj;
fail:
  {
    delete arg2;
  }
  return NULL;
}


SWIGINTERN PyObject *_wrap_SentencePieceProcessor__DecodePiecesAsSerializedProto(PyObject *self, PyObject *args) {
  PyObject *resultobj = 0;
  sentencepiece::SentencePieceProcessor *arg1 = (sentencepiece::SentencePieceProcessor *) 0 ;
  std::vector< absl::string_view > *arg2 = 0 ;
  void *argp1 = 0 ;
  int res1 = 0 ;
  PyObject *swig_obj[2] ;
  sentencepiece::util::bytes result;
  
  if (!SWIG_Python_UnpackTuple(args, "SentencePieceProcessor__DecodePiecesAsSerializedProto", 2, 2, swig_obj)) SWIG_fail;
  res1 = SWIG_ConvertPtr(swig_obj[0], &argp1,SWIGTYPE_p_sentencepiece__SentencePieceProcessor, 0 |  0 );
  if (!SWIG_IsOK(res1)) {
    SWIG_exception_fail(SWIG_ArgError(res1), "in method '" "SentencePieceProcessor__DecodePiecesAsSerializedProto" "', argument " "1"" of type '" "sentencepiece::SentencePieceProcessor const *""'"); 
  }
  arg1 = reinterpret_cast< sentencepiece::SentencePieceProcessor * >(argp1);
  {
    std::vector<absl::string_view> *out = nullptr;
    if (PyList_Check(swig_obj[1])) {
      const size_t size = PyList_Size(swig_obj[1]);
      out = new std::vector<absl::string_view>(size);
      for (size_t i = 0; i < size; ++i) {
        const PyInputString ustring(PyList_GetItem(swig_obj[1], i));
        if (ustring.IsAvalable()) {
          (*out)[i] = ustring.str();
        } else {
          PyErr_SetString(PyExc_TypeError, "list must contain strings");
          SWIG_fail;
        }
        resultobj = ustring.input_type();
      }
    } else {
      PyErr_SetString(PyExc_TypeError, "not a list");
      SWIG_fail;
    }
    arg2 = out;
  }
  {
    try {
      result = sentencepiece_SentencePieceProcessor__DecodePiecesAsSerializedProto((sentencepiece::SentencePieceProcessor const *)arg1,(std::vector< absl::string_view > const &)*arg2);
      ReleaseResultObject(resultobj);
    }
    catch (const sentencepiece::util::Status &status) {
      SWIG_exception(ToSwigError(status.code()), status.ToString().c_str());
    }
  }
  {
    resultobj = MakePyOutputBytes(result);
  }
  {
    delete arg2;
  }
  return resultobj;
fail:
  {
    delete arg2;
  }
  return NULL;
}


SWIGINTERN PyObject *_wrap_SentencePieceProcessor__DecodeIdsAsImmutableProto(PyObject *self, PyObject *args) {
  PyObject *resultobj = 0;
  sentencepiece::SentencePieceProcessor *arg1 = (sentencepiece::SentencePieceProcessor *) 0 ;
  std::vector< int > *arg2 = 0 ;
  void *argp1 = 0 ;
  int res1 = 0 ;
  PyObject *swig_obj[2] ;
  sentencepiece::ImmutableSentencePieceText result;
  
  if (!SWIG_Python_UnpackTuple(args, "SentencePieceProcessor__DecodeIdsAsImmutableProto", 2, 2, swig_obj)) SWIG_fail;
  res1 = SWIG_ConvertPtr(swig_obj[0], &argp1,SWIGTYPE_p_sentencepiece__SentencePieceProcessor, 0 |  0 );
  if (!SWIG_IsOK(res1)) {
    SWIG_exception_fail(SWIG_ArgError(res1), "in method '" "SentencePieceProcessor__DecodeIdsAsImmutableProto" "', argument " "1"" of type '" "sentencepiece::SentencePieceProcessor const *""'"); 
  }
  arg1 = reinterpret_cast< sentencepiece::SentencePieceProcessor * >(argp1);
  {
    std::vector<int> *out = nullptr;
    if (PyList_Check(swig_obj[1])) {
      const size_t size = PyList_Size(swig_obj[1]);
      out = new std::vector<int>(size);
      for (size_t i = 0; i < size; ++i) {
        PyObject *o = PyList_GetItem(swig_obj[1], i);
        if (PyInt_Check(o)) {
          (*out)[i] = static_cast<int>(PyInt_AsLong(o));
        } else {
          PyErr_SetString(PyExc_TypeError,"list must contain integers");
          SWIG_fail;
        }
      }
    } else {
      PyErr_SetString(PyExc_TypeError,"not a list");
      SWIG_fail;
    }
    arg2 = out;
  }
  {
    try {
      result = sentencepiece_SentencePieceProcessor__DecodeIdsAsImmutableProto((sentencepiece::SentencePieceProcessor const *)arg1,(std::vector< int > const &)*arg2);
      ReleaseResultObject(resultobj);
    }
    catch (const sentencepiece::util::Status &status) {
      SWIG_exception(ToSwigError(status.code()), status.ToString().c_str());
    }
  }
  resultobj = SWIG_NewPointerObj((new sentencepiece::ImmutableSentencePieceText(result)), SWIGTYPE_p_sentencepiece__ImmutableSentencePieceText, SWIG_POINTER_OWN |  0 );
  {
    delete arg2;
  }
  return resultobj;
fail:
  {
    delete arg2;
  }
  return NULL;
}


SWIGINTERN PyObject *_wrap_SentencePieceProcessor__DecodePiecesAsImmutableProto(PyObject *self, PyObject *args) {
  PyObject *resultobj = 0;
  sentencepiece::SentencePieceProcessor *arg1 = (sentencepiece::SentencePieceProcessor *) 0 ;
  std::vector< absl::string_view > *arg2 = 0 ;
  void *argp1 = 0 ;
  int res1 = 0 ;
  PyObject *swig_obj[2] ;
  sentencepiece::ImmutableSentencePieceText result;
  
  if (!SWIG_Python_UnpackTuple(args, "SentencePieceProcessor__DecodePiecesAsImmutableProto", 2, 2, swig_obj)) SWIG_fail;
  res1 = SWIG_ConvertPtr(swig_obj[0], &argp1,SWIGTYPE_p_sentencepiece__SentencePieceProcessor, 0 |  0 );
  if (!SWIG_IsOK(res1)) {
    SWIG_exception_fail(SWIG_ArgError(res1), "in method '" "SentencePieceProcessor__DecodePiecesAsImmutableProto" "', argument " "1"" of type '" "sentencepiece::SentencePieceProcessor const *""'"); 
  }
  arg1 = reinterpret_cast< sentencepiece::SentencePieceProcessor * >(argp1);
  {
    std::vector<absl::string_view> *out = nullptr;
    if (PyList_Check(swig_obj[1])) {
      const size_t size = PyList_Size(swig_obj[1]);
      out = new std::vector<absl::string_view>(size);
      for (size_t i = 0; i < size; ++i) {
        const PyInputString ustring(PyList_GetItem(swig_obj[1], i));
        if (ustring.IsAvalable()) {
          (*out)[i] = ustring.str();
        } else {
          PyErr_SetString(PyExc_TypeError, "list must contain strings");
          SWIG_fail;
        }
        resultobj = ustring.input_type();
      }
    } else {
      PyErr_SetString(PyExc_TypeError, "not a list");
      SWIG_fail;
    }
    arg2 = out;
  }
  {
    try {
      result = sentencepiece_SentencePieceProcessor__DecodePiecesAsImmutableProto((sentencepiece::SentencePieceProcessor const *)arg1,(std::vector< absl::string_view > const &)*arg2);
      ReleaseResultObject(resultobj);
    }
    catch (const sentencepiece::util::Status &status) {
      SWIG_exception(ToSwigError(status.code()), status.ToString().c_str());
    }
  }
  resultobj = SWIG_NewPointerObj((new sentencepiece::ImmutableSentencePieceText(result)), SWIGTYPE_p_sentencepiece__ImmutableSentencePieceText, SWIG_POINTER_OWN |  0 );
  {
    delete arg2;
  }
  return resultobj;
fail:
  {
    delete arg2;
  }
  return NULL;
}


SWIGINTERN PyObject *_wrap_SentencePieceProcessor__DecodeIdsBatch(PyObject *self, PyObject *args) {
  PyObject *resultobj = 0;
  sentencepiece::SentencePieceProcessor *arg1 = (sentencepiece::SentencePieceProcessor *) 0 ;
  std::vector< std::vector< int > > *arg2 = 0 ;
  int arg3 ;
  void *argp1 = 0 ;
  int res1 = 0 ;
  int val3 ;
  int ecode3 = 0 ;
  PyObject *swig_obj[3] ;
  std::vector< std::string > result;
  
  if (!SWIG_Python_UnpackTuple(args, "SentencePieceProcessor__DecodeIdsBatch", 3, 3, swig_obj)) SWIG_fail;
  res1 = SWIG_ConvertPtr(swig_obj[0], &argp1,SWIGTYPE_p_sentencepiece__SentencePieceProcessor, 0 |  0 );
  if (!SWIG_IsOK(res1)) {
    SWIG_exception_fail(SWIG_ArgError(res1), "in method '" "SentencePieceProcessor__DecodeIdsBatch" "', argument " "1"" of type '" "sentencepiece::SentencePieceProcessor const *""'"); 
  }
  arg1 = reinterpret_cast< sentencepiece::SentencePieceProcessor * >(argp1);
  {
    std::vector<std::vector<int>> *out = nullptr;
    if (PyList_Check(swig_obj[1])) {
      const size_t size = PyList_Size(swig_obj[1]);
      out = new std::vector<std::vector<int>>(size);
      for (size_t i = 0; i < size; ++i) {
        PyObject *o = PyList_GetItem(swig_obj[1], i);
        if (PyList_Check(o)) {
          const size_t size2 = PyList_Size(o);
          (*out)[i].resize(size2);
          for (size_t j = 0; j < size2; ++j) {
            PyObject *o2 = PyList_GetItem(o, j);
            if (PyInt_Check(o2)) {
              (*out)[i][j] = static_cast<int>(PyInt_AsLong(o2));
            } else {
              PyErr_SetString(PyExc_TypeError, "list must contain strings");
              SWIG_fail;
            }
          }
        } else {
          PyErr_SetString(PyExc_TypeError, "not a list");
          SWIG_fail;
        }
      }
    } else {
      PyErr_SetString(PyExc_TypeError,"not a list");
      SWIG_fail;
    }
    arg2 = out;
  }
  ecode3 = SWIG_AsVal_int(swig_obj[2], &val3);
  if (!SWIG_IsOK(ecode3)) {
    SWIG_exception_fail(SWIG_ArgError(ecode3), "in method '" "SentencePieceProcessor__DecodeIdsBatch" "', argument " "3"" of type '" "int""'");
  } 
  arg3 = static_cast< int >(val3);
  {
    try {
      result = sentencepiece_SentencePieceProcessor__DecodeIdsBatch((sentencepiece::SentencePieceProcessor const *)arg1,(std::vector< std::vector< int > > const &)*arg2,arg3);
      ReleaseResultObject(resultobj);
    }
    catch (const sentencepiece::util::Status &status) {
      SWIG_exception(ToSwigError(status.code()), status.ToString().c_str());
    }
  }
  {
    PyObject *input_type = resultobj;
    resultobj = PyList_New((&result)->size());
    for (size_t i = 0; i < (&result)->size(); ++i) {
      PyList_SET_ITEM(resultobj, i, MakePyOutputString(result[i], input_type));
    }
  }
  {
    delete arg2;
  }
  return resultobj;
fail:
  {
    delete arg2;
  }
  return NULL;
}


SWIGINTERN PyObject *_wrap_SentencePieceProcessor__DecodeIdsAsBytesBatch(PyObject *self, PyObject *args) {
  PyObject *resultobj = 0;
  sentencepiece::SentencePieceProcessor *arg1 = (sentencepiece::SentencePieceProcessor *) 0 ;
  std::vector< std::vector< int > > *arg2 = 0 ;
  int arg3 ;
  void *argp1 = 0 ;
  int res1 = 0 ;
  int val3 ;
  int ecode3 = 0 ;
  PyObject *swig_obj[3] ;
  BytesArray result;
  
  if (!SWIG_Python_UnpackTuple(args, "SentencePieceProcessor__DecodeIdsAsBytesBatch", 3, 3, swig_obj)) SWIG_fail;
  res1 = SWIG_ConvertPtr(swig_obj[0], &argp1,SWIGTYPE_p_sentencepiece__SentencePieceProcessor, 0 |  0 );
  if (!SWIG_IsOK(res1)) {
    SWIG_exception_fail(SWIG_ArgError(res1), "in method '" "SentencePieceProcessor__DecodeIdsAsBytesBatch" "', argument " "1"" of type '" "sentencepiece::SentencePieceProcessor const *""'"); 
  }
  arg1 = reinterpret_cast< sentencepiece::SentencePieceProcessor * >(argp1);
  {
    std::vector<std::vector<int>> *out = nullptr;
    if (PyList_Check(swig_obj[1])) {
      const size_t size = PyList_Size(swig_obj[1]);
      out = new std::vector<std::vector<int>>(size);
      for (size_t i = 0; i < size; ++i) {
        PyObject *o = PyList_GetItem(swig_obj[1], i);
        if (PyList_Check(o)) {
          const size_t size2 = PyList_Size(o);
          (*out)[i].resize(size2);
          for (size_t j = 0; j < size2; ++j) {
            PyObject *o2 = PyList_GetItem(o, j);
            if (PyInt_Check(o2)) {
              (*out)[i][j] = static_cast<int>(PyInt_AsLong(o2));
            } else {
              PyErr_SetString(PyExc_TypeError, "list must contain strings");
              SWIG_fail;
            }
          }
        } else {
          PyErr_SetString(PyExc_TypeError, "not a list");
          SWIG_fail;
        }
      }
    } else {
      PyErr_SetString(PyExc_TypeError,"not a list");
      SWIG_fail;
    }
    arg2 = out;
  }
  ecode3 = SWIG_AsVal_int(swig_obj[2], &val3);
  if (!SWIG_IsOK(ecode3)) {
    SWIG_exception_fail(SWIG_ArgError(ecode3), "in method '" "SentencePieceProcessor__DecodeIdsAsBytesBatch" "', argument " "3"" of type '" "int""'");
  } 
  arg3 = static_cast< int >(val3);
  {
    try {
      result = sentencepiece_SentencePieceProcessor__DecodeIdsAsBytesBatch((sentencepiece::SentencePieceProcessor const *)arg1,(std::vector< std::vector< int > > const &)*arg2,arg3);
      ReleaseResultObject(resultobj);
    }
    catch (const sentencepiece::util::Status &status) {
      SWIG_exception(ToSwigError(status.code()), status.ToString().c_str());
    }
  }
  {
    resultobj = PyList_New((&result)->size());
    for (size_t i = 0; i < (&result)->size(); ++i) {
      PyList_SET_ITEM(resultobj, i, MakePyOutputBytes(result[i]));
    }
  }
  {
    delete arg2;
  }
  return resultobj;
fail:
  {
    delete arg2;
  }
  return NULL;
}


SWIGINTERN PyObject *_wrap_SentencePieceProcessor__DecodeIdsAsSerializedProtoBatch(PyObject *self, PyObject *args) {
  PyObject *resultobj = 0;
  sentencepiece::SentencePieceProcessor *arg1 = (sentencepiece::SentencePieceProcessor *) 0 ;
  std::vector< std::vector< int > > *arg2 = 0 ;
  int arg3 ;
  void *argp1 = 0 ;
  int res1 = 0 ;
  int val3 ;
  int ecode3 = 0 ;
  PyObject *swig_obj[3] ;
  BytesArray result;
  
  if (!SWIG_Python_UnpackTuple(args, "SentencePieceProcessor__DecodeIdsAsSerializedProtoBatch", 3, 3, swig_obj)) SWIG_fail;
  res1 = SWIG_ConvertPtr(swig_obj[0], &argp1,SWIGTYPE_p_sentencepiece__SentencePieceProcessor, 0 |  0 );
  if (!SWIG_IsOK(res1)) {
    SWIG_exception_fail(SWIG_ArgError(res1), "in method '" "SentencePieceProcessor__DecodeIdsAsSerializedProtoBatch" "', argument " "1"" of type '" "sentencepiece::SentencePieceProcessor const *""'"); 
  }
  arg1 = reinterpret_cast< sentencepiece::SentencePieceProcessor * >(argp1);
  {
    std::vector<std::vector<int>> *out = nullptr;
    if (PyList_Check(swig_obj[1])) {
      const size_t size = PyList_Size(swig_obj[1]);
      out = new std::vector<std::vector<int>>(size);
      for (size_t i = 0; i < size; ++i) {
        PyObject *o = PyList_GetItem(swig_obj[1], i);
        if (PyList_Check(o)) {
          const size_t size2 = PyList_Size(o);
          (*out)[i].resize(size2);
          for (size_t j = 0; j < size2; ++j) {
            PyObject *o2 = PyList_GetItem(o, j);
            if (PyInt_Check(o2)) {
              (*out)[i][j] = static_cast<int>(PyInt_AsLong(o2));
            } else {
              PyErr_SetString(PyExc_TypeError, "list must contain strings");
              SWIG_fail;
            }
          }
        } else {
          PyErr_SetString(PyExc_TypeError, "not a list");
          SWIG_fail;
        }
      }
    } else {
      PyErr_SetString(PyExc_TypeError,"not a list");
      SWIG_fail;
    }
    arg2 = out;
  }
  ecode3 = SWIG_AsVal_int(swig_obj[2], &val3);
  if (!SWIG_IsOK(ecode3)) {
    SWIG_exception_fail(SWIG_ArgError(ecode3), "in method '" "SentencePieceProcessor__DecodeIdsAsSerializedProtoBatch" "', argument " "3"" of type '" "int""'");
  } 
  arg3 = static_cast< int >(val3);
  {
    try {
      result = sentencepiece_SentencePieceProcessor__DecodeIdsAsSerializedProtoBatch((sentencepiece::SentencePieceProcessor const *)arg1,(std::vector< std::vector< int > > const &)*arg2,arg3);
      ReleaseResultObject(resultobj);
    }
    catch (const sentencepiece::util::Status &status) {
      SWIG_exception(ToSwigError(status.code()), status.ToString().c_str());
    }
  }
  {
    resultobj = PyList_New((&result)->size());
    for (size_t i = 0; i < (&result)->size(); ++i) {
      PyList_SET_ITEM(resultobj, i, MakePyOutputBytes(result[i]));
    }
  }
  {
    delete arg2;
  }
  return resultobj;
fail:
  {
    delete arg2;
  }
  return NULL;
}


SWIGINTERN PyObject *_wrap_SentencePieceProcessor__DecodeIdsAsImmutableProtoBatch(PyObject *self, PyObject *args) {
  PyObject *resultobj = 0;
  sentencepiece::SentencePieceProcessor *arg1 = (sentencepiece::SentencePieceProcessor *) 0 ;
  std::vector< std::vector< int > > *arg2 = 0 ;
  int arg3 ;
  void *argp1 = 0 ;
  int res1 = 0 ;
  int val3 ;
  int ecode3 = 0 ;
  PyObject *swig_obj[3] ;
  SwigValueWrapper< std::vector< sentencepiece::ImmutableSentencePieceText > > result;
  
  if (!SWIG_Python_UnpackTuple(args, "SentencePieceProcessor__DecodeIdsAsImmutableProtoBatch", 3, 3, swig_obj)) SWIG_fail;
  res1 = SWIG_ConvertPtr(swig_obj[0], &argp1,SWIGTYPE_p_sentencepiece__SentencePieceProcessor, 0 |  0 );
  if (!SWIG_IsOK(res1)) {
    SWIG_exception_fail(SWIG_ArgError(res1), "in method '" "SentencePieceProcessor__DecodeIdsAsImmutableProtoBatch" "', argument " "1"" of type '" "sentencepiece::SentencePieceProcessor const *""'"); 
  }
  arg1 = reinterpret_cast< sentencepiece::SentencePieceProcessor * >(argp1);
  {
    std::vector<std::vector<int>> *out = nullptr;
    if (PyList_Check(swig_obj[1])) {
      const size_t size = PyList_Size(swig_obj[1]);
      out = new std::vector<std::vector<int>>(size);
      for (size_t i = 0; i < size; ++i) {
        PyObject *o = PyList_GetItem(swig_obj[1], i);
        if (PyList_Check(o)) {
          const size_t size2 = PyList_Size(o);
          (*out)[i].resize(size2);
          for (size_t j = 0; j < size2; ++j) {
            PyObject *o2 = PyList_GetItem(o, j);
            if (PyInt_Check(o2)) {
              (*out)[i][j] = static_cast<int>(PyInt_AsLong(o2));
            } else {
              PyErr_SetString(PyExc_TypeError, "list must contain strings");
              SWIG_fail;
            }
          }
        } else {
          PyErr_SetString(PyExc_TypeError, "not a list");
          SWIG_fail;
        }
      }
    } else {
      PyErr_SetString(PyExc_TypeError,"not a list");
      SWIG_fail;
    }
    arg2 = out;
  }
  ecode3 = SWIG_AsVal_int(swig_obj[2], &val3);
  if (!SWIG_IsOK(ecode3)) {
    SWIG_exception_fail(SWIG_ArgError(ecode3), "in method '" "SentencePieceProcessor__DecodeIdsAsImmutableProtoBatch" "', argument " "3"" of type '" "int""'");
  } 
  arg3 = static_cast< int >(val3);
  {
    try {
      result = sentencepiece_SentencePieceProcessor__DecodeIdsAsImmutableProtoBatch((sentencepiece::SentencePieceProcessor const *)arg1,(std::vector< std::vector< int > > const &)*arg2,arg3);
      ReleaseResultObject(resultobj);
    }
    catch (const sentencepiece::util::Status &status) {
      SWIG_exception(ToSwigError(status.code()), status.ToString().c_str());
    }
  }
  {
    resultobj = PyList_New((&result)->size());
    for (size_t i = 0; i < (&result)->size(); ++i) {
      PyObject *obj = SWIG_NewPointerObj(new sentencepiece::ImmutableSentencePieceText((&result)->at(i)), SWIGTYPE_p_sentencepiece__ImmutableSentencePieceText, SWIG_POINTER_OWN | 0);
      PyList_SET_ITEM(resultobj, i, obj);
    }
  }
  {
    delete arg2;
  }
  return resultobj;
fail:
  {
    delete arg2;
  }
  return NULL;
}


SWIGINTERN PyObject *_wrap_SentencePieceProcessor__DecodePiecesBatch(PyObject *self, PyObject *args) {
  PyObject *resultobj = 0;
  sentencepiece::SentencePieceProcessor *arg1 = (sentencepiece::SentencePieceProcessor *) 0 ;
  std::vector< std::vector< absl::string_view > > *arg2 = 0 ;
  int arg3 ;
  void *argp1 = 0 ;
  int res1 = 0 ;
  int val3 ;
  int ecode3 = 0 ;
  PyObject *swig_obj[3] ;
  std::vector< std::string > result;
  
  if (!SWIG_Python_UnpackTuple(args, "SentencePieceProcessor__DecodePiecesBatch", 3, 3, swig_obj)) SWIG_fail;
  res1 = SWIG_ConvertPtr(swig_obj[0], &argp1,SWIGTYPE_p_sentencepiece__SentencePieceProcessor, 0 |  0 );
  if (!SWIG_IsOK(res1)) {
    SWIG_exception_fail(SWIG_ArgError(res1), "in method '" "SentencePieceProcessor__DecodePiecesBatch" "', argument " "1"" of type '" "sentencepiece::SentencePieceProcessor const *""'"); 
  }
  arg1 = reinterpret_cast< sentencepiece::SentencePieceProcessor * >(argp1);
  {
    std::vector<std::vector<absl::string_view>> *out = nullptr;
    if (PyList_Check(swig_obj[1])) {
      const size_t size = PyList_Size(swig_obj[1]);
      out = new std::vector<std::vector<absl::string_view>>(size);
      for (size_t i = 0; i < size; ++i) {
        PyObject *o = PyList_GetItem(swig_obj[1], i);
        if (PyList_Check(o)) {
          const size_t size2 = PyList_Size(o);
          (*out)[i].resize(size2);
          for (size_t j = 0; j < size2; ++j) {
            const PyInputString ustring(PyList_GetItem(o, j));
            if (ustring.IsAvalable()) {
              (*out)[i][j] = ustring.str();
            } else {
              PyErr_SetString(PyExc_TypeError,"list must contain integers");
              SWIG_fail;
            }
            resultobj = ustring.input_type();
          }
        } else {
          PyErr_SetString(PyExc_TypeError,"not a list");
          SWIG_fail;
        }
      }
    } else {
      PyErr_SetString(PyExc_TypeError,"not a list");
      SWIG_fail;
    }
    arg2 = out;
  }
  ecode3 = SWIG_AsVal_int(swig_obj[2], &val3);
  if (!SWIG_IsOK(ecode3)) {
    SWIG_exception_fail(SWIG_ArgError(ecode3), "in method '" "SentencePieceProcessor__DecodePiecesBatch" "', argument " "3"" of type '" "int""'");
  } 
  arg3 = static_cast< int >(val3);
  {
    try {
      result = sentencepiece_SentencePieceProcessor__DecodePiecesBatch((sentencepiece::SentencePieceProcessor const *)arg1,(std::vector< std::vector< absl::string_view > > const &)*arg2,arg3);
      ReleaseResultObject(resultobj);
    }
    catch (const sentencepiece::util::Status &status) {
      SWIG_exception(ToSwigError(status.code()), status.ToString().c_str());
    }
  }
  {
    PyObject *input_type = resultobj;
    resultobj = PyList_New((&result)->size());
    for (size_t i = 0; i < (&result)->size(); ++i) {
      PyList_SET_ITEM(resultobj, i, MakePyOutputString(result[i], input_type));
    }
  }
  return resultobj;
fail:
  return NULL;
}


SWIGINTERN PyObject *_wrap_SentencePieceProcessor__DecodePiecesAsSerializedProtoBatch(PyObject *self, PyObject *args) {
  PyObject *resultobj = 0;
  sentencepiece::SentencePieceProcessor *arg1 = (sentencepiece::SentencePieceProcessor *) 0 ;
  std::vector< std::vector< absl::string_view > > *arg2 = 0 ;
  int arg3 ;
  void *argp1 = 0 ;
  int res1 = 0 ;
  int val3 ;
  int ecode3 = 0 ;
  PyObject *swig_obj[3] ;
  BytesArray result;
  
  if (!SWIG_Python_UnpackTuple(args, "SentencePieceProcessor__DecodePiecesAsSerializedProtoBatch", 3, 3, swig_obj)) SWIG_fail;
  res1 = SWIG_ConvertPtr(swig_obj[0], &argp1,SWIGTYPE_p_sentencepiece__SentencePieceProcessor, 0 |  0 );
  if (!SWIG_IsOK(res1)) {
    SWIG_exception_fail(SWIG_ArgError(res1), "in method '" "SentencePieceProcessor__DecodePiecesAsSerializedProtoBatch" "', argument " "1"" of type '" "sentencepiece::SentencePieceProcessor const *""'"); 
  }
  arg1 = reinterpret_cast< sentencepiece::SentencePieceProcessor * >(argp1);
  {
    std::vector<std::vector<absl::string_view>> *out = nullptr;
    if (PyList_Check(swig_obj[1])) {
      const size_t size = PyList_Size(swig_obj[1]);
      out = new std::vector<std::vector<absl::string_view>>(size);
      for (size_t i = 0; i < size; ++i) {
        PyObject *o = PyList_GetItem(swig_obj[1], i);
        if (PyList_Check(o)) {
          const size_t size2 = PyList_Size(o);
          (*out)[i].resize(size2);
          for (size_t j = 0; j < size2; ++j) {
            const PyInputString ustring(PyList_GetItem(o, j));
            if (ustring.IsAvalable()) {
              (*out)[i][j] = ustring.str();
            } else {
              PyErr_SetString(PyExc_TypeError,"list must contain integers");
              SWIG_fail;
            }
            resultobj = ustring.input_type();
          }
        } else {
          PyErr_SetString(PyExc_TypeError,"not a list");
          SWIG_fail;
        }
      }
    } else {
      PyErr_SetString(PyExc_TypeError,"not a list");
      SWIG_fail;
    }
    arg2 = out;
  }
  ecode3 = SWIG_AsVal_int(swig_obj[2], &val3);
  if (!SWIG_IsOK(ecode3)) {
    SWIG_exception_fail(SWIG_ArgError(ecode3), "in method '" "SentencePieceProcessor__DecodePiecesAsSerializedProtoBatch" "', argument " "3"" of type '" "int""'");
  } 
  arg3 = static_cast< int >(val3);
  {
    try {
      result = sentencepiece_SentencePieceProcessor__DecodePiecesAsSerializedProtoBatch((sentencepiece::SentencePieceProcessor const *)arg1,(std::vector< std::vector< absl::string_view > > const &)*arg2,arg3);
      ReleaseResultObject(resultobj);
    }
    catch (const sentencepiece::util::Status &status) {
      SWIG_exception(ToSwigError(status.code()), status.ToString().c_str());
    }
  }
  {
    resultobj = PyList_New((&result)->size());
    for (size_t i = 0; i < (&result)->size(); ++i) {
      PyList_SET_ITEM(resultobj, i, MakePyOutputBytes(result[i]));
    }
  }
  return resultobj;
fail:
  return NULL;
}


SWIGINTERN PyObject *_wrap_SentencePieceProcessor__DecodePiecesAsImmutableProtoBatch(PyObject *self, PyObject *args) {
  PyObject *resultobj = 0;
  sentencepiece::SentencePieceProcessor *arg1 = (sentencepiece::SentencePieceProcessor *) 0 ;
  std::vector< std::vector< absl::string_view > > *arg2 = 0 ;
  int arg3 ;
  void *argp1 = 0 ;
  int res1 = 0 ;
  int val3 ;
  int ecode3 = 0 ;
  PyObject *swig_obj[3] ;
  SwigValueWrapper< std::vector< sentencepiece::ImmutableSentencePieceText > > result;
  
  if (!SWIG_Python_UnpackTuple(args, "SentencePieceProcessor__DecodePiecesAsImmutableProtoBatch", 3, 3, swig_obj)) SWIG_fail;
  res1 = SWIG_ConvertPtr(swig_obj[0], &argp1,SWIGTYPE_p_sentencepiece__SentencePieceProcessor, 0 |  0 );
  if (!SWIG_IsOK(res1)) {
    SWIG_exception_fail(SWIG_ArgError(res1), "in method '" "SentencePieceProcessor__DecodePiecesAsImmutableProtoBatch" "', argument " "1"" of type '" "sentencepiece::SentencePieceProcessor const *""'"); 
  }
  arg1 = reinterpret_cast< sentencepiece::SentencePieceProcessor * >(argp1);
  {
    std::vector<std::vector<absl::string_view>> *out = nullptr;
    if (PyList_Check(swig_obj[1])) {
      const size_t size = PyList_Size(swig_obj[1]);
      out = new std::vector<std::vector<absl::string_view>>(size);
      for (size_t i = 0; i < size; ++i) {
        PyObject *o = PyList_GetItem(swig_obj[1], i);
        if (PyList_Check(o)) {
          const size_t size2 = PyList_Size(o);
          (*out)[i].resize(size2);
          for (size_t j = 0; j < size2; ++j) {
            const PyInputString ustring(PyList_GetItem(o, j));
            if (ustring.IsAvalable()) {
              (*out)[i][j] = ustring.str();
            } else {
              PyErr_SetString(PyExc_TypeError,"list must contain integers");
              SWIG_fail;
            }
            resultobj = ustring.input_type();
          }
        } else {
          PyErr_SetString(PyExc_TypeError,"not a list");
          SWIG_fail;
        }
      }
    } else {
      PyErr_SetString(PyExc_TypeError,"not a list");
      SWIG_fail;
    }
    arg2 = out;
  }
  ecode3 = SWIG_AsVal_int(swig_obj[2], &val3);
  if (!SWIG_IsOK(ecode3)) {
    SWIG_exception_fail(SWIG_ArgError(ecode3), "in method '" "SentencePieceProcessor__DecodePiecesAsImmutableProtoBatch" "', argument " "3"" of type '" "int""'");
  } 
  arg3 = static_cast< int >(val3);
  {
    try {
      result = sentencepiece_SentencePieceProcessor__DecodePiecesAsImmutableProtoBatch((sentencepiece::SentencePieceProcessor const *)arg1,(std::vector< std::vector< absl::string_view > > const &)*arg2,arg3);
      ReleaseResultObject(resultobj);
    }
    catch (const sentencepiece::util::Status &status) {
      SWIG_exception(ToSwigError(status.code()), status.ToString().c_str());
    }
  }
  {
    resultobj = PyList_New((&result)->size());
    for (size_t i = 0; i < (&result)->size(); ++i) {
      PyObject *obj = SWIG_NewPointerObj(new sentencepiece::ImmutableSentencePieceText((&result)->at(i)), SWIGTYPE_p_sentencepiece__ImmutableSentencePieceText, SWIG_POINTER_OWN | 0);
      PyList_SET_ITEM(resultobj, i, obj);
    }
  }
  return resultobj;
fail:
  return NULL;
}


SWIGINTERN PyObject *_wrap_SentencePieceProcessor__NBestEncodeAsIds(PyObject *self, PyObject *args) {
  PyObject *resultobj = 0;
  sentencepiece::SentencePieceProcessor *arg1 = (sentencepiece::SentencePieceProcessor *) 0 ;
  absl::string_view arg2 ;
  int arg3 ;
  bool arg4 ;
  bool arg5 ;
  bool arg6 ;
  bool arg7 ;
  void *argp1 = 0 ;
  int res1 = 0 ;
  int val3 ;
  int ecode3 = 0 ;
  bool val4 ;
  int ecode4 = 0 ;
  bool val5 ;
  int ecode5 = 0 ;
  bool val6 ;
  int ecode6 = 0 ;
  bool val7 ;
  int ecode7 = 0 ;
  PyObject *swig_obj[7] ;
  std::vector< std::vector< int > > result;
  
  if (!SWIG_Python_UnpackTuple(args, "SentencePieceProcessor__NBestEncodeAsIds", 7, 7, swig_obj)) SWIG_fail;
  res1 = SWIG_ConvertPtr(swig_obj[0], &argp1,SWIGTYPE_p_sentencepiece__SentencePieceProcessor, 0 |  0 );
  if (!SWIG_IsOK(res1)) {
    SWIG_exception_fail(SWIG_ArgError(res1), "in method '" "SentencePieceProcessor__NBestEncodeAsIds" "', argument " "1"" of type '" "sentencepiece::SentencePieceProcessor const *""'"); 
  }
  arg1 = reinterpret_cast< sentencepiece::SentencePieceProcessor * >(argp1);
  {
    const PyInputString ustring(swig_obj[1]);
    if (!ustring.IsAvalable()) {
      PyErr_SetString(PyExc_TypeError, "not a string");
      SWIG_fail;
    }
    resultobj = ustring.input_type();
    arg2 = ustring.str();
  }
  ecode3 = SWIG_AsVal_int(swig_obj[2], &val3);
  if (!SWIG_IsOK(ecode3)) {
    SWIG_exception_fail(SWIG_ArgError(ecode3), "in method '" "SentencePieceProcessor__NBestEncodeAsIds" "', argument " "3"" of type '" "int""'");
  } 
  arg3 = static_cast< int >(val3);
  ecode4 = SWIG_AsVal_bool(swig_obj[3], &val4);
  if (!SWIG_IsOK(ecode4)) {
    SWIG_exception_fail(SWIG_ArgError(ecode4), "in method '" "SentencePieceProcessor__NBestEncodeAsIds" "', argument " "4"" of type '" "bool""'");
  } 
  arg4 = static_cast< bool >(val4);
  ecode5 = SWIG_AsVal_bool(swig_obj[4], &val5);
  if (!SWIG_IsOK(ecode5)) {
    SWIG_exception_fail(SWIG_ArgError(ecode5), "in method '" "SentencePieceProcessor__NBestEncodeAsIds" "', argument " "5"" of type '" "bool""'");
  } 
  arg5 = static_cast< bool >(val5);
  ecode6 = SWIG_AsVal_bool(swig_obj[5], &val6);
  if (!SWIG_IsOK(ecode6)) {
    SWIG_exception_fail(SWIG_ArgError(ecode6), "in method '" "SentencePieceProcessor__NBestEncodeAsIds" "', argument " "6"" of type '" "bool""'");
  } 
  arg6 = static_cast< bool >(val6);
  ecode7 = SWIG_AsVal_bool(swig_obj[6], &val7);
  if (!SWIG_IsOK(ecode7)) {
    SWIG_exception_fail(SWIG_ArgError(ecode7), "in method '" "SentencePieceProcessor__NBestEncodeAsIds" "', argument " "7"" of type '" "bool""'");
  } 
  arg7 = static_cast< bool >(val7);
  {
    try {
      result = sentencepiece_SentencePieceProcessor__NBestEncodeAsIds((sentencepiece::SentencePieceProcessor const *)arg1,SWIG_STD_MOVE(arg2),arg3,arg4,arg5,arg6,arg7);
      ReleaseResultObject(resultobj);
    }
    catch (const sentencepiece::util::Status &status) {
      SWIG_exception(ToSwigError(status.code()), status.ToString().c_str());
    }
  }
  {
    resultobj = PyList_New((&result)->size());
    for (size_t i = 0; i < (&result)->size(); ++i) {
      PyObject *obj = PyList_New(result[i].size());
      for (size_t j = 0; j < result[i].size(); ++j) {
        PyList_SET_ITEM(obj, j, PyInt_FromLong(static_cast<long>(result[i][j])));
      }
      PyList_SET_ITEM(resultobj, i, obj);
    }
  }
  return resultobj;
fail:
  return NULL;
}


SWIGINTERN PyObject *_wrap_SentencePieceProcessor__NBestEncodeAsPieces(PyObject *self, PyObject *args) {
  PyObject *resultobj = 0;
  sentencepiece::SentencePieceProcessor *arg1 = (sentencepiece::SentencePieceProcessor *) 0 ;
  absl::string_view arg2 ;
  int arg3 ;
  bool arg4 ;
  bool arg5 ;
  bool arg6 ;
  bool arg7 ;
  void *argp1 = 0 ;
  int res1 = 0 ;
  int val3 ;
  int ecode3 = 0 ;
  bool val4 ;
  int ecode4 = 0 ;
  bool val5 ;
  int ecode5 = 0 ;
  bool val6 ;
  int ecode6 = 0 ;
  bool val7 ;
  int ecode7 = 0 ;
  PyObject *swig_obj[7] ;
  std::vector< std::vector< std::string > > result;
  
  if (!SWIG_Python_UnpackTuple(args, "SentencePieceProcessor__NBestEncodeAsPieces", 7, 7, swig_obj)) SWIG_fail;
  res1 = SWIG_ConvertPtr(swig_obj[0], &argp1,SWIGTYPE_p_sentencepiece__SentencePieceProcessor, 0 |  0 );
  if (!SWIG_IsOK(res1)) {
    SWIG_exception_fail(SWIG_ArgError(res1), "in method '" "SentencePieceProcessor__NBestEncodeAsPieces" "', argument " "1"" of type '" "sentencepiece::SentencePieceProcessor const *""'"); 
  }
  arg1 = reinterpret_cast< sentencepiece::SentencePieceProcessor * >(argp1);
  {
    const PyInputString ustring(swig_obj[1]);
    if (!ustring.IsAvalable()) {
      PyErr_SetString(PyExc_TypeError, "not a string");
      SWIG_fail;
    }
    resultobj = ustring.input_type();
    arg2 = ustring.str();
  }
  ecode3 = SWIG_AsVal_int(swig_obj[2], &val3);
  if (!SWIG_IsOK(ecode3)) {
    SWIG_exception_fail(SWIG_ArgError(ecode3), "in method '" "SentencePieceProcessor__NBestEncodeAsPieces" "', argument " "3"" of type '" "int""'");
  } 
  arg3 = static_cast< int >(val3);
  ecode4 = SWIG_AsVal_bool(swig_obj[3], &val4);
  if (!SWIG_IsOK(ecode4)) {
    SWIG_exception_fail(SWIG_ArgError(ecode4), "in method '" "SentencePieceProcessor__NBestEncodeAsPieces" "', argument " "4"" of type '" "bool""'");
  } 
  arg4 = static_cast< bool >(val4);
  ecode5 = SWIG_AsVal_bool(swig_obj[4], &val5);
  if (!SWIG_IsOK(ecode5)) {
    SWIG_exception_fail(SWIG_ArgError(ecode5), "in method '" "SentencePieceProcessor__NBestEncodeAsPieces" "', argument " "5"" of type '" "bool""'");
  } 
  arg5 = static_cast< bool >(val5);
  ecode6 = SWIG_AsVal_bool(swig_obj[5], &val6);
  if (!SWIG_IsOK(ecode6)) {
    SWIG_exception_fail(SWIG_ArgError(ecode6), "in method '" "SentencePieceProcessor__NBestEncodeAsPieces" "', argument " "6"" of type '" "bool""'");
  } 
  arg6 = static_cast< bool >(val6);
  ecode7 = SWIG_AsVal_bool(swig_obj[6], &val7);
  if (!SWIG_IsOK(ecode7)) {
    SWIG_exception_fail(SWIG_ArgError(ecode7), "in method '" "SentencePieceProcessor__NBestEncodeAsPieces" "', argument " "7"" of type '" "bool""'");
  } 
  arg7 = static_cast< bool >(val7);
  {
    try {
      result = sentencepiece_SentencePieceProcessor__NBestEncodeAsPieces((sentencepiece::SentencePieceProcessor const *)arg1,SWIG_STD_MOVE(arg2),arg3,arg4,arg5,arg6,arg7);
      ReleaseResultObject(resultobj);
    }
    catch (const sentencepiece::util::Status &status) {
      SWIG_exception(ToSwigError(status.code()), status.ToString().c_str());
    }
  }
  {
    PyObject *input_type = resultobj;
    resultobj = PyList_New((&result)->size());
    for (size_t i = 0; i < (&result)->size(); ++i) {
      PyObject *obj = PyList_New(result[i].size());
      for (size_t j = 0; j < result[i].size(); ++j) {
        PyList_SET_ITEM(obj, j, MakePyOutputString(result[i][j], input_type));
      }
      PyList_SET_ITEM(resultobj, i, obj);
    }
  }
  return resultobj;
fail:
  return NULL;
}


SWIGINTERN PyObject *_wrap_SentencePieceProcessor__NBestEncodeAsSerializedProto(PyObject *self, PyObject *args) {
  PyObject *resultobj = 0;
  sentencepiece::SentencePieceProcessor *arg1 = (sentencepiece::SentencePieceProcessor *) 0 ;
  absl::string_view arg2 ;
  int arg3 ;
  bool arg4 ;
  bool arg5 ;
  bool arg6 ;
  bool arg7 ;
  void *argp1 = 0 ;
  int res1 = 0 ;
  int val3 ;
  int ecode3 = 0 ;
  bool val4 ;
  int ecode4 = 0 ;
  bool val5 ;
  int ecode5 = 0 ;
  bool val6 ;
  int ecode6 = 0 ;
  bool val7 ;
  int ecode7 = 0 ;
  PyObject *swig_obj[7] ;
  sentencepiece::util::bytes result;
  
  if (!SWIG_Python_UnpackTuple(args, "SentencePieceProcessor__NBestEncodeAsSerializedProto", 7, 7, swig_obj)) SWIG_fail;
  res1 = SWIG_ConvertPtr(swig_obj[0], &argp1,SWIGTYPE_p_sentencepiece__SentencePieceProcessor, 0 |  0 );
  if (!SWIG_IsOK(res1)) {
    SWIG_exception_fail(SWIG_ArgError(res1), "in method '" "SentencePieceProcessor__NBestEncodeAsSerializedProto" "', argument " "1"" of type '" "sentencepiece::SentencePieceProcessor const *""'"); 
  }
  arg1 = reinterpret_cast< sentencepiece::SentencePieceProcessor * >(argp1);
  {
    const PyInputString ustring(swig_obj[1]);
    if (!ustring.IsAvalable()) {
      PyErr_SetString(PyExc_TypeError, "not a string");
      SWIG_fail;
    }
    resultobj = ustring.input_type();
    arg2 = ustring.str();
  }
  ecode3 = SWIG_AsVal_int(swig_obj[2], &val3);
  if (!SWIG_IsOK(ecode3)) {
    SWIG_exception_fail(SWIG_ArgError(ecode3), "in method '" "SentencePieceProcessor__NBestEncodeAsSerializedProto" "', argument " "3"" of type '" "int""'");
  } 
  arg3 = static_cast< int >(val3);
  ecode4 = SWIG_AsVal_bool(swig_obj[3], &val4);
  if (!SWIG_IsOK(ecode4)) {
    SWIG_exception_fail(SWIG_ArgError(ecode4), "in method '" "SentencePieceProcessor__NBestEncodeAsSerializedProto" "', argument " "4"" of type '" "bool""'");
  } 
  arg4 = static_cast< bool >(val4);
  ecode5 = SWIG_AsVal_bool(swig_obj[4], &val5);
  if (!SWIG_IsOK(ecode5)) {
    SWIG_exception_fail(SWIG_ArgError(ecode5), "in method '" "SentencePieceProcessor__NBestEncodeAsSerializedProto" "', argument " "5"" of type '" "bool""'");
  } 
  arg5 = static_cast< bool >(val5);
  ecode6 = SWIG_AsVal_bool(swig_obj[5], &val6);
  if (!SWIG_IsOK(ecode6)) {
    SWIG_exception_fail(SWIG_ArgError(ecode6), "in method '" "SentencePieceProcessor__NBestEncodeAsSerializedProto" "', argument " "6"" of type '" "bool""'");
  } 
  arg6 = static_cast< bool >(val6);
  ecode7 = SWIG_AsVal_bool(swig_obj[6], &val7);
  if (!SWIG_IsOK(ecode7)) {
    SWIG_exception_fail(SWIG_ArgError(ecode7), "in method '" "SentencePieceProcessor__NBestEncodeAsSerializedProto" "', argument " "7"" of type '" "bool""'");
  } 
  arg7 = static_cast< bool >(val7);
  {
    try {
      result = sentencepiece_SentencePieceProcessor__NBestEncodeAsSerializedProto((sentencepiece::SentencePieceProcessor const *)arg1,SWIG_STD_MOVE(arg2),arg3,arg4,arg5,arg6,arg7);
      ReleaseResultObject(resultobj);
    }
    catch (const sentencepiece::util::Status &status) {
      SWIG_exception(ToSwigError(status.code()), status.ToString().c_str());
    }
  }
  {
    resultobj = MakePyOutputBytes(result);
  }
  return resultobj;
fail:
  return NULL;
}


SWIGINTERN PyObject *_wrap_SentencePieceProcessor__NBestEncodeAsImmutableProto(PyObject *self, PyObject *args) {
  PyObject *resultobj = 0;
  sentencepiece::SentencePieceProcessor *arg1 = (sentencepiece::SentencePieceProcessor *) 0 ;
  absl::string_view arg2 ;
  int arg3 ;
  bool arg4 ;
  bool arg5 ;
  bool arg6 ;
  bool arg7 ;
  void *argp1 = 0 ;
  int res1 = 0 ;
  int val3 ;
  int ecode3 = 0 ;
  bool val4 ;
  int ecode4 = 0 ;
  bool val5 ;
  int ecode5 = 0 ;
  bool val6 ;
  int ecode6 = 0 ;
  bool val7 ;
  int ecode7 = 0 ;
  PyObject *swig_obj[7] ;
  sentencepiece::ImmutableNBestSentencePieceText result;
  
  if (!SWIG_Python_UnpackTuple(args, "SentencePieceProcessor__NBestEncodeAsImmutableProto", 7, 7, swig_obj)) SWIG_fail;
  res1 = SWIG_ConvertPtr(swig_obj[0], &argp1,SWIGTYPE_p_sentencepiece__SentencePieceProcessor, 0 |  0 );
  if (!SWIG_IsOK(res1)) {
    SWIG_exception_fail(SWIG_ArgError(res1), "in method '" "SentencePieceProcessor__NBestEncodeAsImmutableProto" "', argument " "1"" of type '" "sentencepiece::SentencePieceProcessor const *""'"); 
  }
  arg1 = reinterpret_cast< sentencepiece::SentencePieceProcessor * >(argp1);
  {
    const PyInputString ustring(swig_obj[1]);
    if (!ustring.IsAvalable()) {
      PyErr_SetString(PyExc_TypeError, "not a string");
      SWIG_fail;
    }
    resultobj = ustring.input_type();
    arg2 = ustring.str();
  }
  ecode3 = SWIG_AsVal_int(swig_obj[2], &val3);
  if (!SWIG_IsOK(ecode3)) {
    SWIG_exception_fail(SWIG_ArgError(ecode3), "in method '" "SentencePieceProcessor__NBestEncodeAsImmutableProto" "', argument " "3"" of type '" "int""'");
  } 
  arg3 = static_cast< int >(val3);
  ecode4 = SWIG_AsVal_bool(swig_obj[3], &val4);
  if (!SWIG_IsOK(ecode4)) {
    SWIG_exception_fail(SWIG_ArgError(ecode4), "in method '" "SentencePieceProcessor__NBestEncodeAsImmutableProto" "', argument " "4"" of type '" "bool""'");
  } 
  arg4 = static_cast< bool >(val4);
  ecode5 = SWIG_AsVal_bool(swig_obj[4], &val5);
  if (!SWIG_IsOK(ecode5)) {
    SWIG_exception_fail(SWIG_ArgError(ecode5), "in method '" "SentencePieceProcessor__NBestEncodeAsImmutableProto" "', argument " "5"" of type '" "bool""'");
  } 
  arg5 = static_cast< bool >(val5);
  ecode6 = SWIG_AsVal_bool(swig_obj[5], &val6);
  if (!SWIG_IsOK(ecode6)) {
    SWIG_exception_fail(SWIG_ArgError(ecode6), "in method '" "SentencePieceProcessor__NBestEncodeAsImmutableProto" "', argument " "6"" of type '" "bool""'");
  } 
  arg6 = static_cast< bool >(val6);
  ecode7 = SWIG_AsVal_bool(swig_obj[6], &val7);
  if (!SWIG_IsOK(ecode7)) {
    SWIG_exception_fail(SWIG_ArgError(ecode7), "in method '" "SentencePieceProcessor__NBestEncodeAsImmutableProto" "', argument " "7"" of type '" "bool""'");
  } 
  arg7 = static_cast< bool >(val7);
  {
    try {
      result = sentencepiece_SentencePieceProcessor__NBestEncodeAsImmutableProto((sentencepiece::SentencePieceProcessor const *)arg1,SWIG_STD_MOVE(arg2),arg3,arg4,arg5,arg6,arg7);
      ReleaseResultObject(resultobj);
    }
    catch (const sentencepiece::util::Status &status) {
      SWIG_exception(ToSwigError(status.code()), status.ToString().c_str());
    }
  }
  resultobj = SWIG_NewPointerObj((new sentencepiece::ImmutableNBestSentencePieceText(result)), SWIGTYPE_p_sentencepiece__ImmutableNBestSentencePieceText, SWIG_POINTER_OWN |  0 );
  return resultobj;
fail:
  return NULL;
}


SWIGINTERN PyObject *_wrap_SentencePieceProcessor__SampleEncodeAndScoreAsIds(PyObject *self, PyObject *args) {
  PyObject *resultobj = 0;
  sentencepiece::SentencePieceProcessor *arg1 = (sentencepiece::SentencePieceProcessor *) 0 ;
  absl::string_view arg2 ;
  int arg3 ;
  float arg4 ;
  bool arg5 ;
  bool arg6 ;
  bool arg7 ;
  bool arg8 ;
  bool arg9 ;
  bool arg10 ;
  void *argp1 = 0 ;
  int res1 = 0 ;
  int val3 ;
  int ecode3 = 0 ;
  float val4 ;
  int ecode4 = 0 ;
  bool val5 ;
  int ecode5 = 0 ;
  bool val6 ;
  int ecode6 = 0 ;
  bool val7 ;
  int ecode7 = 0 ;
  bool val8 ;
  int ecode8 = 0 ;
  bool val9 ;
  int ecode9 = 0 ;
  bool val10 ;
  int ecode10 = 0 ;
  PyObject *swig_obj[10] ;
  std::vector< std::pair< std::vector< int >,float > > result;
  
  if (!SWIG_Python_UnpackTuple(args, "SentencePieceProcessor__SampleEncodeAndScoreAsIds", 10, 10, swig_obj)) SWIG_fail;
  res1 = SWIG_ConvertPtr(swig_obj[0], &argp1,SWIGTYPE_p_sentencepiece__SentencePieceProcessor, 0 |  0 );
  if (!SWIG_IsOK(res1)) {
    SWIG_exception_fail(SWIG_ArgError(res1), "in method '" "SentencePieceProcessor__SampleEncodeAndScoreAsIds" "', argument " "1"" of type '" "sentencepiece::SentencePieceProcessor const *""'"); 
  }
  arg1 = reinterpret_cast< sentencepiece::SentencePieceProcessor * >(argp1);
  {
    const PyInputString ustring(swig_obj[1]);
    if (!ustring.IsAvalable()) {
      PyErr_SetString(PyExc_TypeError, "not a string");
      SWIG_fail;
    }
    resultobj = ustring.input_type();
    arg2 = ustring.str();
  }
  ecode3 = SWIG_AsVal_int(swig_obj[2], &val3);
  if (!SWIG_IsOK(ecode3)) {
    SWIG_exception_fail(SWIG_ArgError(ecode3), "in method '" "SentencePieceProcessor__SampleEncodeAndScoreAsIds" "', argument " "3"" of type '" "int""'");
  } 
  arg3 = static_cast< int >(val3);
  ecode4 = SWIG_AsVal_float(swig_obj[3], &val4);
  if (!SWIG_IsOK(ecode4)) {
    SWIG_exception_fail(SWIG_ArgError(ecode4), "in method '" "SentencePieceProcessor__SampleEncodeAndScoreAsIds" "', argument " "4"" of type '" "float""'");
  } 
  arg4 = static_cast< float >(val4);
  ecode5 = SWIG_AsVal_bool(swig_obj[4], &val5);
  if (!SWIG_IsOK(ecode5)) {
    SWIG_exception_fail(SWIG_ArgError(ecode5), "in method '" "SentencePieceProcessor__SampleEncodeAndScoreAsIds" "', argument " "5"" of type '" "bool""'");
  } 
  arg5 = static_cast< bool >(val5);
  ecode6 = SWIG_AsVal_bool(swig_obj[5], &val6);
  if (!SWIG_IsOK(ecode6)) {
    SWIG_exception_fail(SWIG_ArgError(ecode6), "in method '" "SentencePieceProcessor__SampleEncodeAndScoreAsIds" "', argument " "6"" of type '" "bool""'");
  } 
  arg6 = static_cast< bool >(val6);
  ecode7 = SWIG_AsVal_bool(swig_obj[6], &val7);
  if (!SWIG_IsOK(ecode7)) {
    SWIG_exception_fail(SWIG_ArgError(ecode7), "in method '" "SentencePieceProcessor__SampleEncodeAndScoreAsIds" "', argument " "7"" of type '" "bool""'");
  } 
  arg7 = static_cast< bool >(val7);
  ecode8 = SWIG_AsVal_bool(swig_obj[7], &val8);
  if (!SWIG_IsOK(ecode8)) {
    SWIG_exception_fail(SWIG_ArgError(ecode8), "in method '" "SentencePieceProcessor__SampleEncodeAndScoreAsIds" "', argument " "8"" of type '" "bool""'");
  } 
  arg8 = static_cast< bool >(val8);
  ecode9 = SWIG_AsVal_bool(swig_obj[8], &val9);
  if (!SWIG_IsOK(ecode9)) {
    SWIG_exception_fail(SWIG_ArgError(ecode9), "in method '" "SentencePieceProcessor__SampleEncodeAndScoreAsIds" "', argument " "9"" of type '" "bool""'");
  } 
  arg9 = static_cast< bool >(val9);
  ecode10 = SWIG_AsVal_bool(swig_obj[9], &val10);
  if (!SWIG_IsOK(ecode10)) {
    SWIG_exception_fail(SWIG_ArgError(ecode10), "in method '" "SentencePieceProcessor__SampleEncodeAndScoreAsIds" "', argument " "10"" of type '" "bool""'");
  } 
  arg10 = static_cast< bool >(val10);
  {
    try {
      result = sentencepiece_SentencePieceProcessor__SampleEncodeAndScoreAsIds((sentencepiece::SentencePieceProcessor const *)arg1,SWIG_STD_MOVE(arg2),arg3,arg4,arg5,arg6,arg7,arg8,arg9,arg10);
      ReleaseResultObject(resultobj);
    }
    catch (const sentencepiece::util::Status &status) {
      SWIG_exception(ToSwigError(status.code()), status.ToString().c_str());
    }
  }
  {
    resultobj = PyList_New((&result)->size());
    for (size_t i = 0; i < (&result)->size(); ++i) {
      PyObject *obj = PyList_New(result[i].first.size());
      for (size_t j = 0; j < result[i].first.size(); ++j) {
        PyList_SET_ITEM(obj, j, PyInt_FromLong(static_cast<long>(result[i].first[j])));
      }
      PyList_SET_ITEM(resultobj, i, PyTuple_Pack(2, obj, PyFloat_FromDouble(static_cast<double>(result[i].second))));
    }
  }
  return resultobj;
fail:
  return NULL;
}


SWIGINTERN PyObject *_wrap_SentencePieceProcessor__SampleEncodeAndScoreAsPieces(PyObject *self, PyObject *args) {
  PyObject *resultobj = 0;
  sentencepiece::SentencePieceProcessor *arg1 = (sentencepiece::SentencePieceProcessor *) 0 ;
  absl::string_view arg2 ;
  int arg3 ;
  float arg4 ;
  bool arg5 ;
  bool arg6 ;
  bool arg7 ;
  bool arg8 ;
  bool arg9 ;
  bool arg10 ;
  void *argp1 = 0 ;
  int res1 = 0 ;
  int val3 ;
  int ecode3 = 0 ;
  float val4 ;
  int ecode4 = 0 ;
  bool val5 ;
  int ecode5 = 0 ;
  bool val6 ;
  int ecode6 = 0 ;
  bool val7 ;
  int ecode7 = 0 ;
  bool val8 ;
  int ecode8 = 0 ;
  bool val9 ;
  int ecode9 = 0 ;
  bool val10 ;
  int ecode10 = 0 ;
  PyObject *swig_obj[10] ;
  std::vector< std::pair< std::vector< std::string >,float > > result;
  
  if (!SWIG_Python_UnpackTuple(args, "SentencePieceProcessor__SampleEncodeAndScoreAsPieces", 10, 10, swig_obj)) SWIG_fail;
  res1 = SWIG_ConvertPtr(swig_obj[0], &argp1,SWIGTYPE_p_sentencepiece__SentencePieceProcessor, 0 |  0 );
  if (!SWIG_IsOK(res1)) {
    SWIG_exception_fail(SWIG_ArgError(res1), "in method '" "SentencePieceProcessor__SampleEncodeAndScoreAsPieces" "', argument " "1"" of type '" "sentencepiece::SentencePieceProcessor const *""'"); 
  }
  arg1 = reinterpret_cast< sentencepiece::SentencePieceProcessor * >(argp1);
  {
    const PyInputString ustring(swig_obj[1]);
    if (!ustring.IsAvalable()) {
      PyErr_SetString(PyExc_TypeError, "not a string");
      SWIG_fail;
    }
    resultobj = ustring.input_type();
    arg2 = ustring.str();
  }
  ecode3 = SWIG_AsVal_int(swig_obj[2], &val3);
  if (!SWIG_IsOK(ecode3)) {
    SWIG_exception_fail(SWIG_ArgError(ecode3), "in method '" "SentencePieceProcessor__SampleEncodeAndScoreAsPieces" "', argument " "3"" of type '" "int""'");
  } 
  arg3 = static_cast< int >(val3);
  ecode4 = SWIG_AsVal_float(swig_obj[3], &val4);
  if (!SWIG_IsOK(ecode4)) {
    SWIG_exception_fail(SWIG_ArgError(ecode4), "in method '" "SentencePieceProcessor__SampleEncodeAndScoreAsPieces" "', argument " "4"" of type '" "float""'");
  } 
  arg4 = static_cast< float >(val4);
  ecode5 = SWIG_AsVal_bool(swig_obj[4], &val5);
  if (!SWIG_IsOK(ecode5)) {
    SWIG_exception_fail(SWIG_ArgError(ecode5), "in method '" "SentencePieceProcessor__SampleEncodeAndScoreAsPieces" "', argument " "5"" of type '" "bool""'");
  } 
  arg5 = static_cast< bool >(val5);
  ecode6 = SWIG_AsVal_bool(swig_obj[5], &val6);
  if (!SWIG_IsOK(ecode6)) {
    SWIG_exception_fail(SWIG_ArgError(ecode6), "in method '" "SentencePieceProcessor__SampleEncodeAndScoreAsPieces" "', argument " "6"" of type '" "bool""'");
  } 
  arg6 = static_cast< bool >(val6);
  ecode7 = SWIG_AsVal_bool(swig_obj[6], &val7);
  if (!SWIG_IsOK(ecode7)) {
    SWIG_exception_fail(SWIG_ArgError(ecode7), "in method '" "SentencePieceProcessor__SampleEncodeAndScoreAsPieces" "', argument " "7"" of type '" "bool""'");
  } 
  arg7 = static_cast< bool >(val7);
  ecode8 = SWIG_AsVal_bool(swig_obj[7], &val8);
  if (!SWIG_IsOK(ecode8)) {
    SWIG_exception_fail(SWIG_ArgError(ecode8), "in method '" "SentencePieceProcessor__SampleEncodeAndScoreAsPieces" "', argument " "8"" of type '" "bool""'");
  } 
  arg8 = static_cast< bool >(val8);
  ecode9 = SWIG_AsVal_bool(swig_obj[8], &val9);
  if (!SWIG_IsOK(ecode9)) {
    SWIG_exception_fail(SWIG_ArgError(ecode9), "in method '" "SentencePieceProcessor__SampleEncodeAndScoreAsPieces" "', argument " "9"" of type '" "bool""'");
  } 
  arg9 = static_cast< bool >(val9);
  ecode10 = SWIG_AsVal_bool(swig_obj[9], &val10);
  if (!SWIG_IsOK(ecode10)) {
    SWIG_exception_fail(SWIG_ArgError(ecode10), "in method '" "SentencePieceProcessor__SampleEncodeAndScoreAsPieces" "', argument " "10"" of type '" "bool""'");
  } 
  arg10 = static_cast< bool >(val10);
  {
    try {
      result = sentencepiece_SentencePieceProcessor__SampleEncodeAndScoreAsPieces((sentencepiece::SentencePieceProcessor const *)arg1,SWIG_STD_MOVE(arg2),arg3,arg4,arg5,arg6,arg7,arg8,arg9,arg10);
      ReleaseResultObject(resultobj);
    }
    catch (const sentencepiece::util::Status &status) {
      SWIG_exception(ToSwigError(status.code()), status.ToString().c_str());
    }
  }
  {
    PyObject *input_type = resultobj;
    resultobj = PyList_New((&result)->size());
    for (size_t i = 0; i < (&result)->size(); ++i) {
      PyObject *obj = PyList_New(result[i].first.size());
      for (size_t j = 0; j < result[i].first.size(); ++j) {
        PyList_SET_ITEM(obj, j, MakePyOutputString(result[i].first[j], input_type));
      }
      PyList_SET_ITEM(resultobj, i, PyTuple_Pack(2, obj, PyFloat_FromDouble(static_cast<double>(result[i].second))));
    }
  }
  return resultobj;
fail:
  return NULL;
}


SWIGINTERN PyObject *_wrap_SentencePieceProcessor__SampleEncodeAndScoreAsSerializedProto(PyObject *self, PyObject *args) {
  PyObject *resultobj = 0;
  sentencepiece::SentencePieceProcessor *arg1 = (sentencepiece::SentencePieceProcessor *) 0 ;
  absl::string_view arg2 ;
  int arg3 ;
  float arg4 ;
  bool arg5 ;
  bool arg6 ;
  bool arg7 ;
  bool arg8 ;
  bool arg9 ;
  bool arg10 ;
  void *argp1 = 0 ;
  int res1 = 0 ;
  int val3 ;
  int ecode3 = 0 ;
  float val4 ;
  int ecode4 = 0 ;
  bool val5 ;
  int ecode5 = 0 ;
  bool val6 ;
  int ecode6 = 0 ;
  bool val7 ;
  int ecode7 = 0 ;
  bool val8 ;
  int ecode8 = 0 ;
  bool val9 ;
  int ecode9 = 0 ;
  bool val10 ;
  int ecode10 = 0 ;
  PyObject *swig_obj[10] ;
  sentencepiece::util::bytes result;
  
  if (!SWIG_Python_UnpackTuple(args, "SentencePieceProcessor__SampleEncodeAndScoreAsSerializedProto", 10, 10, swig_obj)) SWIG_fail;
  res1 = SWIG_ConvertPtr(swig_obj[0], &argp1,SWIGTYPE_p_sentencepiece__SentencePieceProcessor, 0 |  0 );
  if (!SWIG_IsOK(res1)) {
    SWIG_exception_fail(SWIG_ArgError(res1), "in method '" "SentencePieceProcessor__SampleEncodeAndScoreAsSerializedProto" "', argument " "1"" of type '" "sentencepiece::SentencePieceProcessor const *""'"); 
  }
  arg1 = reinterpret_cast< sentencepiece::SentencePieceProcessor * >(argp1);
  {
    const PyInputString ustring(swig_obj[1]);
    if (!ustring.IsAvalable()) {
      PyErr_SetString(PyExc_TypeError, "not a string");
      SWIG_fail;
    }
    resultobj = ustring.input_type();
    arg2 = ustring.str();
  }
  ecode3 = SWIG_AsVal_int(swig_obj[2], &val3);
  if (!SWIG_IsOK(ecode3)) {
    SWIG_exception_fail(SWIG_ArgError(ecode3), "in method '" "SentencePieceProcessor__SampleEncodeAndScoreAsSerializedProto" "', argument " "3"" of type '" "int""'");
  } 
  arg3 = static_cast< int >(val3);
  ecode4 = SWIG_AsVal_float(swig_obj[3], &val4);
  if (!SWIG_IsOK(ecode4)) {
    SWIG_exception_fail(SWIG_ArgError(ecode4), "in method '" "SentencePieceProcessor__SampleEncodeAndScoreAsSerializedProto" "', argument " "4"" of type '" "float""'");
  } 
  arg4 = static_cast< float >(val4);
  ecode5 = SWIG_AsVal_bool(swig_obj[4], &val5);
  if (!SWIG_IsOK(ecode5)) {
    SWIG_exception_fail(SWIG_ArgError(ecode5), "in method '" "SentencePieceProcessor__SampleEncodeAndScoreAsSerializedProto" "', argument " "5"" of type '" "bool""'");
  } 
  arg5 = static_cast< bool >(val5);
  ecode6 = SWIG_AsVal_bool(swig_obj[5], &val6);
  if (!SWIG_IsOK(ecode6)) {
    SWIG_exception_fail(SWIG_ArgError(ecode6), "in method '" "SentencePieceProcessor__SampleEncodeAndScoreAsSerializedProto" "', argument " "6"" of type '" "bool""'");
  } 
  arg6 = static_cast< bool >(val6);
  ecode7 = SWIG_AsVal_bool(swig_obj[6], &val7);
  if (!SWIG_IsOK(ecode7)) {
    SWIG_exception_fail(SWIG_ArgError(ecode7), "in method '" "SentencePieceProcessor__SampleEncodeAndScoreAsSerializedProto" "', argument " "7"" of type '" "bool""'");
  } 
  arg7 = static_cast< bool >(val7);
  ecode8 = SWIG_AsVal_bool(swig_obj[7], &val8);
  if (!SWIG_IsOK(ecode8)) {
    SWIG_exception_fail(SWIG_ArgError(ecode8), "in method '" "SentencePieceProcessor__SampleEncodeAndScoreAsSerializedProto" "', argument " "8"" of type '" "bool""'");
  } 
  arg8 = static_cast< bool >(val8);
  ecode9 = SWIG_AsVal_bool(swig_obj[8], &val9);
  if (!SWIG_IsOK(ecode9)) {
    SWIG_exception_fail(SWIG_ArgError(ecode9), "in method '" "SentencePieceProcessor__SampleEncodeAndScoreAsSerializedProto" "', argument " "9"" of type '" "bool""'");
  } 
  arg9 = static_cast< bool >(val9);
  ecode10 = SWIG_AsVal_bool(swig_obj[9], &val10);
  if (!SWIG_IsOK(ecode10)) {
    SWIG_exception_fail(SWIG_ArgError(ecode10), "in method '" "SentencePieceProcessor__SampleEncodeAndScoreAsSerializedProto" "', argument " "10"" of type '" "bool""'");
  } 
  arg10 = static_cast< bool >(val10);
  {
    try {
      result = sentencepiece_SentencePieceProcessor__SampleEncodeAndScoreAsSerializedProto((sentencepiece::SentencePieceProcessor const *)arg1,SWIG_STD_MOVE(arg2),arg3,arg4,arg5,arg6,arg7,arg8,arg9,arg10);
      ReleaseResultObject(resultobj);
    }
    catch (const sentencepiece::util::Status &status) {
      SWIG_exception(ToSwigError(status.code()), status.ToString().c_str());
    }
  }
  {
    resultobj = MakePyOutputBytes(result);
  }
  return resultobj;
fail:
  return NULL;
}


SWIGINTERN PyObject *_wrap_SentencePieceProcessor__SampleEncodeAndScoreAsImmutableProto(PyObject *self, PyObject *args) {
  PyObject *resultobj = 0;
  sentencepiece::SentencePieceProcessor *arg1 = (sentencepiece::SentencePieceProcessor *) 0 ;
  absl::string_view arg2 ;
  int arg3 ;
  float arg4 ;
  bool arg5 ;
  bool arg6 ;
  bool arg7 ;
  bool arg8 ;
  bool arg9 ;
  bool arg10 ;
  void *argp1 = 0 ;
  int res1 = 0 ;
  int val3 ;
  int ecode3 = 0 ;
  float val4 ;
  int ecode4 = 0 ;
  bool val5 ;
  int ecode5 = 0 ;
  bool val6 ;
  int ecode6 = 0 ;
  bool val7 ;
  int ecode7 = 0 ;
  bool val8 ;
  int ecode8 = 0 ;
  bool val9 ;
  int ecode9 = 0 ;
  bool val10 ;
  int ecode10 = 0 ;
  PyObject *swig_obj[10] ;
  sentencepiece::ImmutableNBestSentencePieceText result;
  
  if (!SWIG_Python_UnpackTuple(args, "SentencePieceProcessor__SampleEncodeAndScoreAsImmutableProto", 10, 10, swig_obj)) SWIG_fail;
  res1 = SWIG_ConvertPtr(swig_obj[0], &argp1,SWIGTYPE_p_sentencepiece__SentencePieceProcessor, 0 |  0 );
  if (!SWIG_IsOK(res1)) {
    SWIG_exception_fail(SWIG_ArgError(res1), "in method '" "SentencePieceProcessor__SampleEncodeAndScoreAsImmutableProto" "', argument " "1"" of type '" "sentencepiece::SentencePieceProcessor const *""'"); 
  }
  arg1 = reinterpret_cast< sentencepiece::SentencePieceProcessor * >(argp1);
  {
    const PyInputString ustring(swig_obj[1]);
    if (!ustring.IsAvalable()) {
      PyErr_SetString(PyExc_TypeError, "not a string");
      SWIG_fail;
    }
    resultobj = ustring.input_type();
    arg2 = ustring.str();
  }
  ecode3 = SWIG_AsVal_int(swig_obj[2], &val3);
  if (!SWIG_IsOK(ecode3)) {
    SWIG_exception_fail(SWIG_ArgError(ecode3), "in method '" "SentencePieceProcessor__SampleEncodeAndScoreAsImmutableProto" "', argument " "3"" of type '" "int""'");
  } 
  arg3 = static_cast< int >(val3);
  ecode4 = SWIG_AsVal_float(swig_obj[3], &val4);
  if (!SWIG_IsOK(ecode4)) {
    SWIG_exception_fail(SWIG_ArgError(ecode4), "in method '" "SentencePieceProcessor__SampleEncodeAndScoreAsImmutableProto" "', argument " "4"" of type '" "float""'");
  } 
  arg4 = static_cast< float >(val4);
  ecode5 = SWIG_AsVal_bool(swig_obj[4], &val5);
  if (!SWIG_IsOK(ecode5)) {
    SWIG_exception_fail(SWIG_ArgError(ecode5), "in method '" "SentencePieceProcessor__SampleEncodeAndScoreAsImmutableProto" "', argument " "5"" of type '" "bool""'");
  } 
  arg5 = static_cast< bool >(val5);
  ecode6 = SWIG_AsVal_bool(swig_obj[5], &val6);
  if (!SWIG_IsOK(ecode6)) {
    SWIG_exception_fail(SWIG_ArgError(ecode6), "in method '" "SentencePieceProcessor__SampleEncodeAndScoreAsImmutableProto" "', argument " "6"" of type '" "bool""'");
  } 
  arg6 = static_cast< bool >(val6);
  ecode7 = SWIG_AsVal_bool(swig_obj[6], &val7);
  if (!SWIG_IsOK(ecode7)) {
    SWIG_exception_fail(SWIG_ArgError(ecode7), "in method '" "SentencePieceProcessor__SampleEncodeAndScoreAsImmutableProto" "', argument " "7"" of type '" "bool""'");
  } 
  arg7 = static_cast< bool >(val7);
  ecode8 = SWIG_AsVal_bool(swig_obj[7], &val8);
  if (!SWIG_IsOK(ecode8)) {
    SWIG_exception_fail(SWIG_ArgError(ecode8), "in method '" "SentencePieceProcessor__SampleEncodeAndScoreAsImmutableProto" "', argument " "8"" of type '" "bool""'");
  } 
  arg8 = static_cast< bool >(val8);
  ecode9 = SWIG_AsVal_bool(swig_obj[8], &val9);
  if (!SWIG_IsOK(ecode9)) {
    SWIG_exception_fail(SWIG_ArgError(ecode9), "in method '" "SentencePieceProcessor__SampleEncodeAndScoreAsImmutableProto" "', argument " "9"" of type '" "bool""'");
  } 
  arg9 = static_cast< bool >(val9);
  ecode10 = SWIG_AsVal_bool(swig_obj[9], &val10);
  if (!SWIG_IsOK(ecode10)) {
    SWIG_exception_fail(SWIG_ArgError(ecode10), "in method '" "SentencePieceProcessor__SampleEncodeAndScoreAsImmutableProto" "', argument " "10"" of type '" "bool""'");
  } 
  arg10 = static_cast< bool >(val10);
  {
    try {
      result = sentencepiece_SentencePieceProcessor__SampleEncodeAndScoreAsImmutableProto((sentencepiece::SentencePieceProcessor const *)arg1,SWIG_STD_MOVE(arg2),arg3,arg4,arg5,arg6,arg7,arg8,arg9,arg10);
      ReleaseResultObject(resultobj);
    }
    catch (const sentencepiece::util::Status &status) {
      SWIG_exception(ToSwigError(status.code()), status.ToString().c_str());
    }
  }
  resultobj = SWIG_NewPointerObj((new sentencepiece::ImmutableNBestSentencePieceText(result)), SWIGTYPE_p_sentencepiece__ImmutableNBestSentencePieceText, SWIG_POINTER_OWN |  0 );
  return resultobj;
fail:
  return NULL;
}


SWIGINTERN PyObject *_wrap_SentencePieceProcessor__Normalize(PyObject *self, PyObject *args) {
  PyObject *resultobj = 0;
  sentencepiece::SentencePieceProcessor *arg1 = (sentencepiece::SentencePieceProcessor *) 0 ;
  absl::string_view arg2 ;
  void *argp1 = 0 ;
  int res1 = 0 ;
  PyObject *swig_obj[2] ;
  std::string result;
  
  if (!SWIG_Python_UnpackTuple(args, "SentencePieceProcessor__Normalize", 2, 2, swig_obj)) SWIG_fail;
  res1 = SWIG_ConvertPtr(swig_obj[0], &argp1,SWIGTYPE_p_sentencepiece__SentencePieceProcessor, 0 |  0 );
  if (!SWIG_IsOK(res1)) {
    SWIG_exception_fail(SWIG_ArgError(res1), "in method '" "SentencePieceProcessor__Normalize" "', argument " "1"" of type '" "sentencepiece::SentencePieceProcessor *""'"); 
  }
  arg1 = reinterpret_cast< sentencepiece::SentencePieceProcessor * >(argp1);
  {
    const PyInputString ustring(swig_obj[1]);
    if (!ustring.IsAvalable()) {
      PyErr_SetString(PyExc_TypeError, "not a string");
      SWIG_fail;
    }
    resultobj = ustring.input_type();
    arg2 = ustring.str();
  }
  {
    try {
      result = sentencepiece_SentencePieceProcessor__Normalize(arg1,SWIG_STD_MOVE(arg2));
      ReleaseResultObject(resultobj);
    }
    catch (const sentencepiece::util::Status &status) {
      SWIG_exception(ToSwigError(status.code()), status.ToString().c_str());
    }
  }
  {
    PyObject *input_type = resultobj;
    resultobj = MakePyOutputString(result, input_type);
  }
  return resultobj;
fail:
  return NULL;
}


SWIGINTERN PyObject *_wrap_SentencePieceProcessor__NormalizeWithOffsets(PyObject *self, PyObject *args) {
  PyObject *resultobj = 0;
  sentencepiece::SentencePieceProcessor *arg1 = (sentencepiece::SentencePieceProcessor *) 0 ;
  absl::string_view arg2 ;
  void *argp1 = 0 ;
  int res1 = 0 ;
  PyObject *swig_obj[2] ;
  std::pair< std::string,std::vector< size_t > > result;
  
  if (!SWIG_Python_UnpackTuple(args, "SentencePieceProcessor__NormalizeWithOffsets", 2, 2, swig_obj)) SWIG_fail;
  res1 = SWIG_ConvertPtr(swig_obj[0], &argp1,SWIGTYPE_p_sentencepiece__SentencePieceProcessor, 0 |  0 );
  if (!SWIG_IsOK(res1)) {
    SWIG_exception_fail(SWIG_ArgError(res1), "in method '" "SentencePieceProcessor__NormalizeWithOffsets" "', argument " "1"" of type '" "sentencepiece::SentencePieceProcessor *""'"); 
  }
  arg1 = reinterpret_cast< sentencepiece::SentencePieceProcessor * >(argp1);
  {
    const PyInputString ustring(swig_obj[1]);
    if (!ustring.IsAvalable()) {
      PyErr_SetString(PyExc_TypeError, "not a string");
      SWIG_fail;
    }
    resultobj = ustring.input_type();
    arg2 = ustring.str();
  }
  {
    try {
      result = sentencepiece_SentencePieceProcessor__NormalizeWithOffsets(arg1,SWIG_STD_MOVE(arg2));
      ReleaseResultObject(resultobj);
    }
    catch (const sentencepiece::util::Status &status) {
      SWIG_exception(ToSwigError(status.code()), status.ToString().c_str());
    }
  }
  {
    PyObject *input_type = resultobj;
    if (PyInputString::IsUnicode(input_type)) {
      sentencepiece::ConvertToUnicodeAlignment(arg2, (&result)->first, &(&result)->second);
    }
    PyObject *obj = PyList_New((&result)->second.size());
    for (size_t i = 0; i < (&result)->second.size(); ++i) {
      PyList_SET_ITEM(obj, i, PyInt_FromLong(static_cast<long>((&result)->second[i])));
    }
    resultobj = PyTuple_Pack(2, MakePyOutputString((&result)->first, input_type), obj);
  }
  return resultobj;
fail:
  return NULL;
}


SWIGINTERN PyObject *_wrap_SentencePieceProcessor__CalculateEntropy(PyObject *self, PyObject *args) {
  PyObject *resultobj = 0;
  sentencepiece::SentencePieceProcessor *arg1 = (sentencepiece::SentencePieceProcessor *) 0 ;
  absl::string_view arg2 ;
  float arg3 ;
  void *argp1 = 0 ;
  int res1 = 0 ;
  float val3 ;
  int ecode3 = 0 ;
  PyObject *swig_obj[3] ;
  float result;
  
  if (!SWIG_Python_UnpackTuple(args, "SentencePieceProcessor__CalculateEntropy", 3, 3, swig_obj)) SWIG_fail;
  res1 = SWIG_ConvertPtr(swig_obj[0], &argp1,SWIGTYPE_p_sentencepiece__SentencePieceProcessor, 0 |  0 );
  if (!SWIG_IsOK(res1)) {
    SWIG_exception_fail(SWIG_ArgError(res1), "in method '" "SentencePieceProcessor__CalculateEntropy" "', argument " "1"" of type '" "sentencepiece::SentencePieceProcessor *""'"); 
  }
  arg1 = reinterpret_cast< sentencepiece::SentencePieceProcessor * >(argp1);
  {
    const PyInputString ustring(swig_obj[1]);
    if (!ustring.IsAvalable()) {
      PyErr_SetString(PyExc_TypeError, "not a string");
      SWIG_fail;
    }
    resultobj = ustring.input_type();
    arg2 = ustring.str();
  }
  ecode3 = SWIG_AsVal_float(swig_obj[2], &val3);
  if (!SWIG_IsOK(ecode3)) {
    SWIG_exception_fail(SWIG_ArgError(ecode3), "in method '" "SentencePieceProcessor__CalculateEntropy" "', argument " "3"" of type '" "float""'");
  } 
  arg3 = static_cast< float >(val3);
  {
    try {
      result = (float)sentencepiece_SentencePieceProcessor__CalculateEntropy(arg1,SWIG_STD_MOVE(arg2),arg3);
      ReleaseResultObject(resultobj);
    }
    catch (const sentencepiece::util::Status &status) {
      SWIG_exception(ToSwigError(status.code()), status.ToString().c_str());
    }
  }
  resultobj = SWIG_From_float(static_cast< float >(result));
  return resultobj;
fail:
  return NULL;
}


SWIGINTERN PyObject *_wrap_SentencePieceProcessor__CalculateEntropyBatch(PyObject *self, PyObject *args) {
  PyObject *resultobj = 0;
  sentencepiece::SentencePieceProcessor *arg1 = (sentencepiece::SentencePieceProcessor *) 0 ;
  std::vector< absl::string_view > *arg2 = 0 ;
  float arg3 ;
  int arg4 ;
  void *argp1 = 0 ;
  int res1 = 0 ;
  float val3 ;
  int ecode3 = 0 ;
  int val4 ;
  int ecode4 = 0 ;
  PyObject *swig_obj[4] ;
  std::vector< float > result;
  
  if (!SWIG_Python_UnpackTuple(args, "SentencePieceProcessor__CalculateEntropyBatch", 4, 4, swig_obj)) SWIG_fail;
  res1 = SWIG_ConvertPtr(swig_obj[0], &argp1,SWIGTYPE_p_sentencepiece__SentencePieceProcessor, 0 |  0 );
  if (!SWIG_IsOK(res1)) {
    SWIG_exception_fail(SWIG_ArgError(res1), "in method '" "SentencePieceProcessor__CalculateEntropyBatch" "', argument " "1"" of type '" "sentencepiece::SentencePieceProcessor *""'"); 
  }
  arg1 = reinterpret_cast< sentencepiece::SentencePieceProcessor * >(argp1);
  {
    std::vector<absl::string_view> *out = nullptr;
    if (PyList_Check(swig_obj[1])) {
      const size_t size = PyList_Size(swig_obj[1]);
      out = new std::vector<absl::string_view>(size);
      for (size_t i = 0; i < size; ++i) {
        const PyInputString ustring(PyList_GetItem(swig_obj[1], i));
        if (ustring.IsAvalable()) {
          (*out)[i] = ustring.str();
        } else {
          PyErr_SetString(PyExc_TypeError, "list must contain strings");
          SWIG_fail;
        }
        resultobj = ustring.input_type();
      }
    } else {
      PyErr_SetString(PyExc_TypeError, "not a list");
      SWIG_fail;
    }
    arg2 = out;
  }
  ecode3 = SWIG_AsVal_float(swig_obj[2], &val3);
  if (!SWIG_IsOK(ecode3)) {
    SWIG_exception_fail(SWIG_ArgError(ecode3), "in method '" "SentencePieceProcessor__CalculateEntropyBatch" "', argument " "3"" of type '" "float""'");
  } 
  arg3 = static_cast< float >(val3);
  ecode4 = SWIG_AsVal_int(swig_obj[3], &val4);
  if (!SWIG_IsOK(ecode4)) {
    SWIG_exception_fail(SWIG_ArgError(ecode4), "in method '" "SentencePieceProcessor__CalculateEntropyBatch" "', argument " "4"" of type '" "int""'");
  } 
  arg4 = static_cast< int >(val4);
  {
    try {
      result = sentencepiece_SentencePieceProcessor__CalculateEntropyBatch(arg1,(std::vector< absl::string_view > const &)*arg2,arg3,arg4);
      ReleaseResultObject(resultobj);
    }
    catch (const sentencepiece::util::Status &status) {
      SWIG_exception(ToSwigError(status.code()), status.ToString().c_str());
    }
  }
  {
    resultobj = PyList_New((&result)->size());
    for (size_t i = 0; i < (&result)->size(); ++i) {
      PyList_SET_ITEM(resultobj, i, PyFloat_FromDouble(static_cast<double>(result[i])));
    }
  }
  {
    delete arg2;
  }
  return resultobj;
fail:
  {
    delete arg2;
  }
  return NULL;
}


SWIGINTERN PyObject *_wrap_SentencePieceProcessor__OverrideNormalizerSpec(PyObject *self, PyObject *args) {
  PyObject *resultobj = 0;
  sentencepiece::SentencePieceProcessor *arg1 = (sentencepiece::SentencePieceProcessor *) 0 ;
  std::unordered_map< std::string,std::string > *arg2 = 0 ;
  void *argp1 = 0 ;
  int res1 = 0 ;
  PyObject *swig_obj[2] ;
  sentencepiece::util::Status result;
  
  if (!SWIG_Python_UnpackTuple(args, "SentencePieceProcessor__OverrideNormalizerSpec", 2, 2, swig_obj)) SWIG_fail;
  res1 = SWIG_ConvertPtr(swig_obj[0], &argp1,SWIGTYPE_p_sentencepiece__SentencePieceProcessor, 0 |  0 );
  if (!SWIG_IsOK(res1)) {
    SWIG_exception_fail(SWIG_ArgError(res1), "in method '" "SentencePieceProcessor__OverrideNormalizerSpec" "', argument " "1"" of type '" "sentencepiece::SentencePieceProcessor *""'"); 
  }
  arg1 = reinterpret_cast< sentencepiece::SentencePieceProcessor * >(argp1);
  {
    std::unordered_map<std::string, std::string> *out = nullptr;
    if (PyDict_Check(swig_obj[1])) {
      PyObject *key, *value;
      Py_ssize_t pos = 0;
      out = new std::unordered_map<std::string, std::string>;
      while (PyDict_Next(swig_obj[1], &pos, &key, &value)) {
        const PyInputString key_ustring(key);
        const PyInputString value_ustring(value);
        if (key_ustring.IsAvalable() && value_ustring.IsAvalable()) {
          out->emplace(std::string(key_ustring.data(), key_ustring.size()),
            std::string(value_ustring.data(), value_ustring.size()));
        } else {
          PyErr_SetString(PyExc_TypeError, "map must contain strings.");
          SWIG_fail;
        }
        resultobj = key_ustring.input_type();
      }
    } else {
      PyErr_SetString(PyExc_TypeError, "not a dictionary");
      SWIG_fail;
    }
    arg2 = out;
  }
  {
    try {
      result = sentencepiece_SentencePieceProcessor__OverrideNormalizerSpec(arg1,(std::unordered_map< std::string,std::string > const &)*arg2);
      ReleaseResultObject(resultobj);
    }
    catch (const sentencepiece::util::Status &status) {
      SWIG_exception(ToSwigError(status.code()), status.ToString().c_str());
    }
  }
  {
    if (!(&result)->ok()) {
      SWIG_exception(ToSwigError((&result)->code()), (&result)->ToString().c_str());
    }
    resultobj = SWIG_From_bool((&result)->ok());
  }
  {
    delete arg2;
  }
  return resultobj;
fail:
  {
    delete arg2;
  }
  return NULL;
}


SWIGINTERN PyObject *SentencePieceProcessor_swigregister(PyObject *SWIGUNUSEDPARM(self), PyObject *args) {
  PyObject *obj;
  if (!SWIG_Python_UnpackTuple(args, "swigregister", 1, 1, &obj)) return NULL;
  SWIG_TypeNewClientData(SWIGTYPE_p_sentencepiece__SentencePieceProcessor, SWIG_NewClientData(obj));
  return SWIG_Py_Void();
}

SWIGINTERN PyObject *SentencePieceProcessor_swiginit(PyObject *SWIGUNUSEDPARM(self), PyObject *args) {
  return SWIG_Python_InitShadowInstance(args);
}

SWIGINTERN PyObject *_wrap_SetRandomGeneratorSeed(PyObject *self, PyObject *args) {
  PyObject *resultobj = 0;
  unsigned int arg1 ;
  unsigned int val1 ;
  int ecode1 = 0 ;
  PyObject *swig_obj[1] ;
  
  if (!args) SWIG_fail;
  swig_obj[0] = args;
  ecode1 = SWIG_AsVal_unsigned_SS_int(swig_obj[0], &val1);
  if (!SWIG_IsOK(ecode1)) {
    SWIG_exception_fail(SWIG_ArgError(ecode1), "in method '" "SetRandomGeneratorSeed" "', argument " "1"" of type '" "unsigned int""'");
  } 
  arg1 = static_cast< unsigned int >(val1);
  {
    try {
      sentencepiece::SetRandomGeneratorSeed(arg1);
      ReleaseResultObject(resultobj);
    }
    catch (const sentencepiece::util::Status &status) {
      SWIG_exception(ToSwigError(status.code()), status.ToString().c_str());
    }
  }
  resultobj = SWIG_Py_Void();
  return resultobj;
fail:
  return NULL;
}


SWIGINTERN PyObject *_wrap_SetMinLogLevel(PyObject *self, PyObject *args) {
  PyObject *resultobj = 0;
  int arg1 ;
  int val1 ;
  int ecode1 = 0 ;
  PyObject *swig_obj[1] ;
  
  if (!args) SWIG_fail;
  swig_obj[0] = args;
  ecode1 = SWIG_AsVal_int(swig_obj[0], &val1);
  if (!SWIG_IsOK(ecode1)) {
    SWIG_exception_fail(SWIG_ArgError(ecode1), "in method '" "SetMinLogLevel" "', argument " "1"" of type '" "int""'");
  } 
  arg1 = static_cast< int >(val1);
  {
    try {
      sentencepiece::SetMinLogLevel(arg1);
      ReleaseResultObject(resultobj);
    }
    catch (const sentencepiece::util::Status &status) {
      SWIG_exception(ToSwigError(status.code()), status.ToString().c_str());
    }
  }
  resultobj = SWIG_Py_Void();
  return resultobj;
fail:
  return NULL;
}


SWIGINTERN PyObject *_wrap_SentencePieceTrainer__TrainFromString(PyObject *self, PyObject *args) {
  PyObject *resultobj = 0;
  absl::string_view arg1 ;
  PyObject *swig_obj[1] ;
  
  if (!args) SWIG_fail;
  swig_obj[0] = args;
  {
    const PyInputString ustring(swig_obj[0]);
    if (!ustring.IsAvalable()) {
      PyErr_SetString(PyExc_TypeError, "not a string");
      SWIG_fail;
    }
    resultobj = ustring.input_type();
    arg1 = ustring.str();
  }
  {
    try {
      sentencepiece_SentencePieceTrainer__TrainFromString(SWIG_STD_MOVE(arg1));
      ReleaseResultObject(resultobj);
    }
    catch (const sentencepiece::util::Status &status) {
      SWIG_exception(ToSwigError(status.code()), status.ToString().c_str());
    }
  }
  resultobj = SWIG_Py_Void();
  return resultobj;
fail:
  return NULL;
}


SWIGINTERN PyObject *_wrap_SentencePieceTrainer__TrainFromMap(PyObject *self, PyObject *args) {
  PyObject *resultobj = 0;
  std::unordered_map< std::string,std::string > *arg1 = 0 ;
  PyObject *swig_obj[1] ;
  
  if (!args) SWIG_fail;
  swig_obj[0] = args;
  {
    std::unordered_map<std::string, std::string> *out = nullptr;
    if (PyDict_Check(swig_obj[0])) {
      PyObject *key, *value;
      Py_ssize_t pos = 0;
      out = new std::unordered_map<std::string, std::string>;
      while (PyDict_Next(swig_obj[0], &pos, &key, &value)) {
        const PyInputString key_ustring(key);
        const PyInputString value_ustring(value);
        if (key_ustring.IsAvalable() && value_ustring.IsAvalable()) {
          out->emplace(std::string(key_ustring.data(), key_ustring.size()),
            std::string(value_ustring.data(), value_ustring.size()));
        } else {
          PyErr_SetString(PyExc_TypeError, "map must contain strings.");
          SWIG_fail;
        }
        resultobj = key_ustring.input_type();
      }
    } else {
      PyErr_SetString(PyExc_TypeError, "not a dictionary");
      SWIG_fail;
    }
    arg1 = out;
  }
  {
    try {
      sentencepiece_SentencePieceTrainer__TrainFromMap((std::unordered_map< std::string,std::string > const &)*arg1);
      ReleaseResultObject(resultobj);
    }
    catch (const sentencepiece::util::Status &status) {
      SWIG_exception(ToSwigError(status.code()), status.ToString().c_str());
    }
  }
  resultobj = SWIG_Py_Void();
  {
    delete arg1;
  }
  return resultobj;
fail:
  {
    delete arg1;
  }
  return NULL;
}


SWIGINTERN PyObject *_wrap_SentencePieceTrainer__TrainFromMap2(PyObject *self, PyObject *args) {
  PyObject *resultobj = 0;
  std::unordered_map< std::string,std::string > *arg1 = 0 ;
  sentencepiece::SentenceIterator *arg2 = (sentencepiece::SentenceIterator *) 0 ;
  PyObject *swig_obj[2] ;
  
  if (!SWIG_Python_UnpackTuple(args, "SentencePieceTrainer__TrainFromMap2", 2, 2, swig_obj)) SWIG_fail;
  {
    std::unordered_map<std::string, std::string> *out = nullptr;
    if (PyDict_Check(swig_obj[0])) {
      PyObject *key, *value;
      Py_ssize_t pos = 0;
      out = new std::unordered_map<std::string, std::string>;
      while (PyDict_Next(swig_obj[0], &pos, &key, &value)) {
        const PyInputString key_ustring(key);
        const PyInputString value_ustring(value);
        if (key_ustring.IsAvalable() && value_ustring.IsAvalable()) {
          out->emplace(std::string(key_ustring.data(), key_ustring.size()),
            std::string(value_ustring.data(), value_ustring.size()));
        } else {
          PyErr_SetString(PyExc_TypeError, "map must contain strings.");
          SWIG_fail;
        }
        resultobj = key_ustring.input_type();
      }
    } else {
      PyErr_SetString(PyExc_TypeError, "not a dictionary");
      SWIG_fail;
    }
    arg1 = out;
  }
  {
    sentencepiece::SentenceIterator *out = nullptr;
    if (PyIter_Check(swig_obj[1])) {
      out = new PySentenceIterator(swig_obj[1]);
    } else {
      PyErr_SetString(PyExc_TypeError, "not a iterator");
      SWIG_fail;
    }
    arg2 = out;
  }
  {
    try {
      sentencepiece_SentencePieceTrainer__TrainFromMap2((std::unordered_map< std::string,std::string > const &)*arg1,arg2);
      ReleaseResultObject(resultobj);
    }
    catch (const sentencepiece::util::Status &status) {
      SWIG_exception(ToSwigError(status.code()), status.ToString().c_str());
    }
  }
  resultobj = SWIG_Py_Void();
  {
    delete arg1;
  }
  {
    delete arg2;
  }
  return resultobj;
fail:
  {
    delete arg1;
  }
  {
    delete arg2;
  }
  return NULL;
}


SWIGINTERN PyObject *_wrap_SentencePieceTrainer__TrainFromMap3(PyObject *self, PyObject *args) {
  PyObject *resultobj = 0;
  std::unordered_map< std::string,std::string > *arg1 = 0 ;
  PyObject *swig_obj[1] ;
  sentencepiece::util::bytes result;
  
  if (!args) SWIG_fail;
  swig_obj[0] = args;
  {
    std::unordered_map<std::string, std::string> *out = nullptr;
    if (PyDict_Check(swig_obj[0])) {
      PyObject *key, *value;
      Py_ssize_t pos = 0;
      out = new std::unordered_map<std::string, std::string>;
      while (PyDict_Next(swig_obj[0], &pos, &key, &value)) {
        const PyInputString key_ustring(key);
        const PyInputString value_ustring(value);
        if (key_ustring.IsAvalable() && value_ustring.IsAvalable()) {
          out->emplace(std::string(key_ustring.data(), key_ustring.size()),
            std::string(value_ustring.data(), value_ustring.size()));
        } else {
          PyErr_SetString(PyExc_TypeError, "map must contain strings.");
          SWIG_fail;
        }
        resultobj = key_ustring.input_type();
      }
    } else {
      PyErr_SetString(PyExc_TypeError, "not a dictionary");
      SWIG_fail;
    }
    arg1 = out;
  }
  {
    try {
      result = sentencepiece_SentencePieceTrainer__TrainFromMap3((std::unordered_map< std::string,std::string > const &)*arg1);
      ReleaseResultObject(resultobj);
    }
    catch (const sentencepiece::util::Status &status) {
      SWIG_exception(ToSwigError(status.code()), status.ToString().c_str());
    }
  }
  {
    resultobj = MakePyOutputBytes(result);
  }
  {
    delete arg1;
  }
  return resultobj;
fail:
  {
    delete arg1;
  }
  return NULL;
}


SWIGINTERN PyObject *_wrap_SentencePieceTrainer__TrainFromMap4(PyObject *self, PyObject *args) {
  PyObject *resultobj = 0;
  std::unordered_map< std::string,std::string > *arg1 = 0 ;
  sentencepiece::SentenceIterator *arg2 = (sentencepiece::SentenceIterator *) 0 ;
  PyObject *swig_obj[2] ;
  sentencepiece::util::bytes result;
  
  if (!SWIG_Python_UnpackTuple(args, "SentencePieceTrainer__TrainFromMap4", 2, 2, swig_obj)) SWIG_fail;
  {
    std::unordered_map<std::string, std::string> *out = nullptr;
    if (PyDict_Check(swig_obj[0])) {
      PyObject *key, *value;
      Py_ssize_t pos = 0;
      out = new std::unordered_map<std::string, std::string>;
      while (PyDict_Next(swig_obj[0], &pos, &key, &value)) {
        const PyInputString key_ustring(key);
        const PyInputString value_ustring(value);
        if (key_ustring.IsAvalable() && value_ustring.IsAvalable()) {
          out->emplace(std::string(key_ustring.data(), key_ustring.size()),
            std::string(value_ustring.data(), value_ustring.size()));
        } else {
          PyErr_SetString(PyExc_TypeError, "map must contain strings.");
          SWIG_fail;
        }
        resultobj = key_ustring.input_type();
      }
    } else {
      PyErr_SetString(PyExc_TypeError, "not a dictionary");
      SWIG_fail;
    }
    arg1 = out;
  }
  {
    sentencepiece::SentenceIterator *out = nullptr;
    if (PyIter_Check(swig_obj[1])) {
      out = new PySentenceIterator(swig_obj[1]);
    } else {
      PyErr_SetString(PyExc_TypeError, "not a iterator");
      SWIG_fail;
    }
    arg2 = out;
  }
  {
    try {
      result = sentencepiece_SentencePieceTrainer__TrainFromMap4((std::unordered_map< std::string,std::string > const &)*arg1,arg2);
      ReleaseResultObject(resultobj);
    }
    catch (const sentencepiece::util::Status &status) {
      SWIG_exception(ToSwigError(status.code()), status.ToString().c_str());
    }
  }
  {
    resultobj = MakePyOutputBytes(result);
  }
  {
    delete arg1;
  }
  {
    delete arg2;
  }
  return resultobj;
fail:
  {
    delete arg1;
  }
  {
    delete arg2;
  }
  return NULL;
}


SWIGINTERN PyObject *SentencePieceTrainer_swigregister(PyObject *SWIGUNUSEDPARM(self), PyObject *args) {
  PyObject *obj;
  if (!SWIG_Python_UnpackTuple(args, "swigregister", 1, 1, &obj)) return NULL;
  SWIG_TypeNewClientData(SWIGTYPE_p_sentencepiece__SentencePieceTrainer, SWIG_NewClientData(obj));
  return SWIG_Py_Void();
}

SWIGINTERN PyObject *_wrap_new_SentencePieceNormalizer(PyObject *self, PyObject *args) {
  PyObject *resultobj = 0;
  sentencepiece::SentencePieceNormalizer *result = 0 ;
  
  if (!SWIG_Python_UnpackTuple(args, "new_SentencePieceNormalizer", 0, 0, 0)) SWIG_fail;
  {
    try {
      result = (sentencepiece::SentencePieceNormalizer *)new sentencepiece::SentencePieceNormalizer();
      ReleaseResultObject(resultobj);
    }
    catch (const sentencepiece::util::Status &status) {
      SWIG_exception(ToSwigError(status.code()), status.ToString().c_str());
    }
  }
  resultobj = SWIG_NewPointerObj(SWIG_as_voidptr(result), SWIGTYPE_p_sentencepiece__SentencePieceNormalizer, SWIG_POINTER_NEW |  0 );
  return resultobj;
fail:
  return NULL;
}


SWIGINTERN PyObject *_wrap_delete_SentencePieceNormalizer(PyObject *self, PyObject *args) {
  PyObject *resultobj = 0;
  sentencepiece::SentencePieceNormalizer *arg1 = (sentencepiece::SentencePieceNormalizer *) 0 ;
  void *argp1 = 0 ;
  int res1 = 0 ;
  PyObject *swig_obj[1] ;
  
  if (!args) SWIG_fail;
  swig_obj[0] = args;
  res1 = SWIG_ConvertPtr(swig_obj[0], &argp1,SWIGTYPE_p_sentencepiece__SentencePieceNormalizer, SWIG_POINTER_DISOWN |  0 );
  if (!SWIG_IsOK(res1)) {
    SWIG_exception_fail(SWIG_ArgError(res1), "in method '" "delete_SentencePieceNormalizer" "', argument " "1"" of type '" "sentencepiece::SentencePieceNormalizer *""'"); 
  }
  arg1 = reinterpret_cast< sentencepiece::SentencePieceNormalizer * >(argp1);
  {
    try {
      delete arg1;
      ReleaseResultObject(resultobj);
    }
    catch (const sentencepiece::util::Status &status) {
      SWIG_exception(ToSwigError(status.code()), status.ToString().c_str());
    }
  }
  resultobj = SWIG_Py_Void();
  return resultobj;
fail:
  return NULL;
}


SWIGINTERN PyObject *_wrap_SentencePieceNormalizer_LoadFromSerializedProto(PyObject *self, PyObject *args) {
  PyObject *resultobj = 0;
  sentencepiece::SentencePieceNormalizer *arg1 = (sentencepiece::SentencePieceNormalizer *) 0 ;
  absl::string_view arg2 ;
  void *argp1 = 0 ;
  int res1 = 0 ;
  PyObject *swig_obj[2] ;
  sentencepiece::util::Status result;
  
  if (!SWIG_Python_UnpackTuple(args, "SentencePieceNormalizer_LoadFromSerializedProto", 2, 2, swig_obj)) SWIG_fail;
  res1 = SWIG_ConvertPtr(swig_obj[0], &argp1,SWIGTYPE_p_sentencepiece__SentencePieceNormalizer, 0 |  0 );
  if (!SWIG_IsOK(res1)) {
    SWIG_exception_fail(SWIG_ArgError(res1), "in method '" "SentencePieceNormalizer_LoadFromSerializedProto" "', argument " "1"" of type '" "sentencepiece::SentencePieceNormalizer *""'"); 
  }
  arg1 = reinterpret_cast< sentencepiece::SentencePieceNormalizer * >(argp1);
  {
    const PyInputString ustring(swig_obj[1]);
    if (!ustring.IsAvalable()) {
      PyErr_SetString(PyExc_TypeError, "not a string");
      SWIG_fail;
    }
    resultobj = ustring.input_type();
    arg2 = ustring.str();
  }
  {
    try {
      result = (arg1)->LoadFromSerializedProto(arg2);
      ReleaseResultObject(resultobj);
    }
    catch (const sentencepiece::util::Status &status) {
      SWIG_exception(ToSwigError(status.code()), status.ToString().c_str());
    }
  }
  {
    if (!(&result)->ok()) {
      SWIG_exception(ToSwigError((&result)->code()), (&result)->ToString().c_str());
    }
    resultobj = SWIG_From_bool((&result)->ok());
  }
  return resultobj;
fail:
  return NULL;
}


SWIGINTERN PyObject *_wrap_SentencePieceNormalizer_LoadFromRuleTSV(PyObject *self, PyObject *args) {
  PyObject *resultobj = 0;
  sentencepiece::SentencePieceNormalizer *arg1 = (sentencepiece::SentencePieceNormalizer *) 0 ;
  absl::string_view arg2 ;
  void *argp1 = 0 ;
  int res1 = 0 ;
  PyObject *swig_obj[2] ;
  sentencepiece::util::Status result;
  
  if (!SWIG_Python_UnpackTuple(args, "SentencePieceNormalizer_LoadFromRuleTSV", 2, 2, swig_obj)) SWIG_fail;
  res1 = SWIG_ConvertPtr(swig_obj[0], &argp1,SWIGTYPE_p_sentencepiece__SentencePieceNormalizer, 0 |  0 );
  if (!SWIG_IsOK(res1)) {
    SWIG_exception_fail(SWIG_ArgError(res1), "in method '" "SentencePieceNormalizer_LoadFromRuleTSV" "', argument " "1"" of type '" "sentencepiece::SentencePieceNormalizer *""'"); 
  }
  arg1 = reinterpret_cast< sentencepiece::SentencePieceNormalizer * >(argp1);
  {
    const PyInputString ustring(swig_obj[1]);
    if (!ustring.IsAvalable()) {
      PyErr_SetString(PyExc_TypeError, "not a string");
      SWIG_fail;
    }
    resultobj = ustring.input_type();
    arg2 = ustring.str();
  }
  {
    try {
      result = (arg1)->LoadFromRuleTSV(arg2);
      ReleaseResultObject(resultobj);
    }
    catch (const sentencepiece::util::Status &status) {
      SWIG_exception(ToSwigError(status.code()), status.ToString().c_str());
    }
  }
  {
    if (!(&result)->ok()) {
      SWIG_exception(ToSwigError((&result)->code()), (&result)->ToString().c_str());
    }
    resultobj = SWIG_From_bool((&result)->ok());
  }
  return resultobj;
fail:
  return NULL;
}


SWIGINTERN PyObject *_wrap_SentencePieceNormalizer_LoadFromRuleName(PyObject *self, PyObject *args) {
  PyObject *resultobj = 0;
  sentencepiece::SentencePieceNormalizer *arg1 = (sentencepiece::SentencePieceNormalizer *) 0 ;
  absl::string_view arg2 ;
  void *argp1 = 0 ;
  int res1 = 0 ;
  PyObject *swig_obj[2] ;
  sentencepiece::util::Status result;
  
  if (!SWIG_Python_UnpackTuple(args, "SentencePieceNormalizer_LoadFromRuleName", 2, 2, swig_obj)) SWIG_fail;
  res1 = SWIG_ConvertPtr(swig_obj[0], &argp1,SWIGTYPE_p_sentencepiece__SentencePieceNormalizer, 0 |  0 );
  if (!SWIG_IsOK(res1)) {
    SWIG_exception_fail(SWIG_ArgError(res1), "in method '" "SentencePieceNormalizer_LoadFromRuleName" "', argument " "1"" of type '" "sentencepiece::SentencePieceNormalizer *""'"); 
  }
  arg1 = reinterpret_cast< sentencepiece::SentencePieceNormalizer * >(argp1);
  {
    const PyInputString ustring(swig_obj[1]);
    if (!ustring.IsAvalable()) {
      PyErr_SetString(PyExc_TypeError, "not a string");
      SWIG_fail;
    }
    resultobj = ustring.input_type();
    arg2 = ustring.str();
  }
  {
    try {
      result = (arg1)->LoadFromRuleName(arg2);
      ReleaseResultObject(resultobj);
    }
    catch (const sentencepiece::util::Status &status) {
      SWIG_exception(ToSwigError(status.code()), status.ToString().c_str());
    }
  }
  {
    if (!(&result)->ok()) {
      SWIG_exception(ToSwigError((&result)->code()), (&result)->ToString().c_str());
    }
    resultobj = SWIG_From_bool((&result)->ok());
  }
  return resultobj;
fail:
  return NULL;
}


SWIGINTERN PyObject *_wrap_SentencePieceNormalizer_serialized_model_proto(PyObject *self, PyObject *args) {
  PyObject *resultobj = 0;
  sentencepiece::SentencePieceNormalizer *arg1 = (sentencepiece::SentencePieceNormalizer *) 0 ;
  void *argp1 = 0 ;
  int res1 = 0 ;
  PyObject *swig_obj[1] ;
  std::string result;
  
  if (!args) SWIG_fail;
  swig_obj[0] = args;
  res1 = SWIG_ConvertPtr(swig_obj[0], &argp1,SWIGTYPE_p_sentencepiece__SentencePieceNormalizer, 0 |  0 );
  if (!SWIG_IsOK(res1)) {
    SWIG_exception_fail(SWIG_ArgError(res1), "in method '" "SentencePieceNormalizer_serialized_model_proto" "', argument " "1"" of type '" "sentencepiece::SentencePieceNormalizer const *""'"); 
  }
  arg1 = reinterpret_cast< sentencepiece::SentencePieceNormalizer * >(argp1);
  {
    try {
      result = ((sentencepiece::SentencePieceNormalizer const *)arg1)->serialized_model_proto();
      ReleaseResultObject(resultobj);
    }
    catch (const sentencepiece::util::Status &status) {
      SWIG_exception(ToSwigError(status.code()), status.ToString().c_str());
    }
  }
  {
    PyObject *input_type = resultobj;
    resultobj = MakePyOutputString(result, input_type);
  }
  return resultobj;
fail:
  return NULL;
}


SWIGINTERN PyObject *_wrap_SentencePieceNormalizer_LoadFromFile(PyObject *self, PyObject *args) {
  PyObject *resultobj = 0;
  sentencepiece::SentencePieceNormalizer *arg1 = (sentencepiece::SentencePieceNormalizer *) 0 ;
  absl::string_view arg2 ;
  void *argp1 = 0 ;
  int res1 = 0 ;
  PyObject *swig_obj[2] ;
  sentencepiece::util::Status result;
  
  if (!SWIG_Python_UnpackTuple(args, "SentencePieceNormalizer_LoadFromFile", 2, 2, swig_obj)) SWIG_fail;
  res1 = SWIG_ConvertPtr(swig_obj[0], &argp1,SWIGTYPE_p_sentencepiece__SentencePieceNormalizer, 0 |  0 );
  if (!SWIG_IsOK(res1)) {
    SWIG_exception_fail(SWIG_ArgError(res1), "in method '" "SentencePieceNormalizer_LoadFromFile" "', argument " "1"" of type '" "sentencepiece::SentencePieceNormalizer *""'"); 
  }
  arg1 = reinterpret_cast< sentencepiece::SentencePieceNormalizer * >(argp1);
  {
    const PyInputString ustring(swig_obj[1]);
    if (!ustring.IsAvalable()) {
      PyErr_SetString(PyExc_TypeError, "not a string");
      SWIG_fail;
    }
    resultobj = ustring.input_type();
    arg2 = ustring.str();
  }
  {
    try {
      result = sentencepiece_SentencePieceNormalizer_LoadFromFile(arg1,SWIG_STD_MOVE(arg2));
      ReleaseResultObject(resultobj);
    }
    catch (const sentencepiece::util::Status &status) {
      SWIG_exception(ToSwigError(status.code()), status.ToString().c_str());
    }
  }
  {
    if (!(&result)->ok()) {
      SWIG_exception(ToSwigError((&result)->code()), (&result)->ToString().c_str());
    }
    resultobj = SWIG_From_bool((&result)->ok());
  }
  return resultobj;
fail:
  return NULL;
}


SWIGINTERN PyObject *_wrap_SentencePieceNormalizer__Normalize(PyObject *self, PyObject *args) {
  PyObject *resultobj = 0;
  sentencepiece::SentencePieceNormalizer *arg1 = (sentencepiece::SentencePieceNormalizer *) 0 ;
  absl::string_view arg2 ;
  void *argp1 = 0 ;
  int res1 = 0 ;
  PyObject *swig_obj[2] ;
  std::string result;
  
  if (!SWIG_Python_UnpackTuple(args, "SentencePieceNormalizer__Normalize", 2, 2, swig_obj)) SWIG_fail;
  res1 = SWIG_ConvertPtr(swig_obj[0], &argp1,SWIGTYPE_p_sentencepiece__SentencePieceNormalizer, 0 |  0 );
  if (!SWIG_IsOK(res1)) {
    SWIG_exception_fail(SWIG_ArgError(res1), "in method '" "SentencePieceNormalizer__Normalize" "', argument " "1"" of type '" "sentencepiece::SentencePieceNormalizer *""'"); 
  }
  arg1 = reinterpret_cast< sentencepiece::SentencePieceNormalizer * >(argp1);
  {
    const PyInputString ustring(swig_obj[1]);
    if (!ustring.IsAvalable()) {
      PyErr_SetString(PyExc_TypeError, "not a string");
      SWIG_fail;
    }
    resultobj = ustring.input_type();
    arg2 = ustring.str();
  }
  {
    try {
      result = sentencepiece_SentencePieceNormalizer__Normalize(arg1,SWIG_STD_MOVE(arg2));
      ReleaseResultObject(resultobj);
    }
    catch (const sentencepiece::util::Status &status) {
      SWIG_exception(ToSwigError(status.code()), status.ToString().c_str());
    }
  }
  {
    PyObject *input_type = resultobj;
    resultobj = MakePyOutputString(result, input_type);
  }
  return resultobj;
fail:
  return NULL;
}


SWIGINTERN PyObject *_wrap_SentencePieceNormalizer__NormalizeWithOffsets(PyObject *self, PyObject *args) {
  PyObject *resultobj = 0;
  sentencepiece::SentencePieceNormalizer *arg1 = (sentencepiece::SentencePieceNormalizer *) 0 ;
  absl::string_view arg2 ;
  void *argp1 = 0 ;
  int res1 = 0 ;
  PyObject *swig_obj[2] ;
  std::pair< std::string,std::vector< size_t > > result;
  
  if (!SWIG_Python_UnpackTuple(args, "SentencePieceNormalizer__NormalizeWithOffsets", 2, 2, swig_obj)) SWIG_fail;
  res1 = SWIG_ConvertPtr(swig_obj[0], &argp1,SWIGTYPE_p_sentencepiece__SentencePieceNormalizer, 0 |  0 );
  if (!SWIG_IsOK(res1)) {
    SWIG_exception_fail(SWIG_ArgError(res1), "in method '" "SentencePieceNormalizer__NormalizeWithOffsets" "', argument " "1"" of type '" "sentencepiece::SentencePieceNormalizer *""'"); 
  }
  arg1 = reinterpret_cast< sentencepiece::SentencePieceNormalizer * >(argp1);
  {
    const PyInputString ustring(swig_obj[1]);
    if (!ustring.IsAvalable()) {
      PyErr_SetString(PyExc_TypeError, "not a string");
      SWIG_fail;
    }
    resultobj = ustring.input_type();
    arg2 = ustring.str();
  }
  {
    try {
      result = sentencepiece_SentencePieceNormalizer__NormalizeWithOffsets(arg1,SWIG_STD_MOVE(arg2));
      ReleaseResultObject(resultobj);
    }
    catch (const sentencepiece::util::Status &status) {
      SWIG_exception(ToSwigError(status.code()), status.ToString().c_str());
    }
  }
  {
    PyObject *input_type = resultobj;
    if (PyInputString::IsUnicode(input_type)) {
      sentencepiece::ConvertToUnicodeAlignment(arg2, (&result)->first, &(&result)->second);
    }
    PyObject *obj = PyList_New((&result)->second.size());
    for (size_t i = 0; i < (&result)->second.size(); ++i) {
      PyList_SET_ITEM(obj, i, PyInt_FromLong(static_cast<long>((&result)->second[i])));
    }
    resultobj = PyTuple_Pack(2, MakePyOutputString((&result)->first, input_type), obj);
  }
  return resultobj;
fail:
  return NULL;
}


SWIGINTERN PyObject *_wrap_SentencePieceNormalizer__SetProtoField(PyObject *self, PyObject *args) {
  PyObject *resultobj = 0;
  sentencepiece::SentencePieceNormalizer *arg1 = (sentencepiece::SentencePieceNormalizer *) 0 ;
  absl::string_view arg2 ;
  bool arg3 ;
  void *argp1 = 0 ;
  int res1 = 0 ;
  bool val3 ;
  int ecode3 = 0 ;
  PyObject *swig_obj[3] ;
  
  if (!SWIG_Python_UnpackTuple(args, "SentencePieceNormalizer__SetProtoField", 3, 3, swig_obj)) SWIG_fail;
  res1 = SWIG_ConvertPtr(swig_obj[0], &argp1,SWIGTYPE_p_sentencepiece__SentencePieceNormalizer, 0 |  0 );
  if (!SWIG_IsOK(res1)) {
    SWIG_exception_fail(SWIG_ArgError(res1), "in method '" "SentencePieceNormalizer__SetProtoField" "', argument " "1"" of type '" "sentencepiece::SentencePieceNormalizer *""'"); 
  }
  arg1 = reinterpret_cast< sentencepiece::SentencePieceNormalizer * >(argp1);
  {
    const PyInputString ustring(swig_obj[1]);
    if (!ustring.IsAvalable()) {
      PyErr_SetString(PyExc_TypeError, "not a string");
      SWIG_fail;
    }
    resultobj = ustring.input_type();
    arg2 = ustring.str();
  }
  ecode3 = SWIG_AsVal_bool(swig_obj[2], &val3);
  if (!SWIG_IsOK(ecode3)) {
    SWIG_exception_fail(SWIG_ArgError(ecode3), "in method '" "SentencePieceNormalizer__SetProtoField" "', argument " "3"" of type '" "bool""'");
  } 
  arg3 = static_cast< bool >(val3);
  {
    try {
      sentencepiece_SentencePieceNormalizer__SetProtoField(arg1,SWIG_STD_MOVE(arg2),arg3);
      ReleaseResultObject(resultobj);
    }
    catch (const sentencepiece::util::Status &status) {
      SWIG_exception(ToSwigError(status.code()), status.ToString().c_str());
    }
  }
  resultobj = SWIG_Py_Void();
  return resultobj;
fail:
  return NULL;
}


SWIGINTERN PyObject *SentencePieceNormalizer_swigregister(PyObject *SWIGUNUSEDPARM(self), PyObject *args) {
  PyObject *obj;
  if (!SWIG_Python_UnpackTuple(args, "swigregister", 1, 1, &obj)) return NULL;
  SWIG_TypeNewClientData(SWIGTYPE_p_sentencepiece__SentencePieceNormalizer, SWIG_NewClientData(obj));
  return SWIG_Py_Void();
}

SWIGINTERN PyObject *SentencePieceNormalizer_swiginit(PyObject *SWIGUNUSEDPARM(self), PyObject *args) {
  return SWIG_Python_InitShadowInstance(args);
}

static PyMethodDef SwigMethods[] = {
	 { "new_ImmutableSentencePieceText_ImmutableSentencePiece", _wrap_new_ImmutableSentencePieceText_ImmutableSentencePiece, METH_NOARGS, NULL},
	 { "delete_ImmutableSentencePieceText_ImmutableSentencePiece", _wrap_delete_ImmutableSentencePieceText_ImmutableSentencePiece, METH_O, NULL},
	 { "ImmutableSentencePieceText_ImmutableSentencePiece__piece", _wrap_ImmutableSentencePieceText_ImmutableSentencePiece__piece, METH_O, NULL},
	 { "ImmutableSentencePieceText_ImmutableSentencePiece__surface", _wrap_ImmutableSentencePieceText_ImmutableSentencePiece__surface, METH_O, NULL},
	 { "ImmutableSentencePieceText_ImmutableSentencePiece__id", _wrap_ImmutableSentencePieceText_ImmutableSentencePiece__id, METH_O, NULL},
	 { "ImmutableSentencePieceText_ImmutableSentencePiece__begin", _wrap_ImmutableSentencePieceText_ImmutableSentencePiece__begin, METH_O, NULL},
	 { "ImmutableSentencePieceText_ImmutableSentencePiece__end", _wrap_ImmutableSentencePieceText_ImmutableSentencePiece__end, METH_O, NULL},
	 { "ImmutableSentencePieceText_ImmutableSentencePiece__surface_as_bytes", _wrap_ImmutableSentencePieceText_ImmutableSentencePiece__surface_as_bytes, METH_O, NULL},
	 { "ImmutableSentencePieceText_ImmutableSentencePiece__piece_as_bytes", _wrap_ImmutableSentencePieceText_ImmutableSentencePiece__piece_as_bytes, METH_O, NULL},
	 { "ImmutableSentencePieceText_ImmutableSentencePiece_swigregister", ImmutableSentencePieceText_ImmutableSentencePiece_swigregister, METH_O, NULL},
	 { "ImmutableSentencePieceText_ImmutableSentencePiece_swiginit", ImmutableSentencePieceText_ImmutableSentencePiece_swiginit, METH_VARARGS, NULL},
	 { "new_ImmutableSentencePieceText", _wrap_new_ImmutableSentencePieceText, METH_NOARGS, NULL},
	 { "delete_ImmutableSentencePieceText", _wrap_delete_ImmutableSentencePieceText, METH_O, NULL},
	 { "ImmutableSentencePieceText__pieces_size", _wrap_ImmutableSentencePieceText__pieces_size, METH_O, NULL},
	 { "ImmutableSentencePieceText__pieces", _wrap_ImmutableSentencePieceText__pieces, METH_VARARGS, NULL},
	 { "ImmutableSentencePieceText__text", _wrap_ImmutableSentencePieceText__text, METH_O, NULL},
	 { "ImmutableSentencePieceText__score", _wrap_ImmutableSentencePieceText__score, METH_O, NULL},
	 { "ImmutableSentencePieceText_SerializeAsString", _wrap_ImmutableSentencePieceText_SerializeAsString, METH_O, NULL},
	 { "ImmutableSentencePieceText__text_as_bytes", _wrap_ImmutableSentencePieceText__text_as_bytes, METH_O, NULL},
	 { "ImmutableSentencePieceText_swigregister", ImmutableSentencePieceText_swigregister, METH_O, NULL},
	 { "ImmutableSentencePieceText_swiginit", ImmutableSentencePieceText_swiginit, METH_VARARGS, NULL},
	 { "new_ImmutableNBestSentencePieceText", _wrap_new_ImmutableNBestSentencePieceText, METH_NOARGS, NULL},
	 { "delete_ImmutableNBestSentencePieceText", _wrap_delete_ImmutableNBestSentencePieceText, METH_O, NULL},
	 { "ImmutableNBestSentencePieceText__nbests_size", _wrap_ImmutableNBestSentencePieceText__nbests_size, METH_O, NULL},
	 { "ImmutableNBestSentencePieceText__nbests", _wrap_ImmutableNBestSentencePieceText__nbests, METH_VARARGS, NULL},
	 { "ImmutableNBestSentencePieceText_SerializeAsString", _wrap_ImmutableNBestSentencePieceText_SerializeAsString, METH_O, NULL},
	 { "ImmutableNBestSentencePieceText_swigregister", ImmutableNBestSentencePieceText_swigregister, METH_O, NULL},
	 { "ImmutableNBestSentencePieceText_swiginit", ImmutableNBestSentencePieceText_swiginit, METH_VARARGS, NULL},
	 { "new_SentencePieceProcessor", _wrap_new_SentencePieceProcessor, METH_NOARGS, NULL},
	 { "delete_SentencePieceProcessor", _wrap_delete_SentencePieceProcessor, METH_O, NULL},
	 { "SentencePieceProcessor_LoadFromSerializedProto", _wrap_SentencePieceProcessor_LoadFromSerializedProto, METH_VARARGS, NULL},
	 { "SentencePieceProcessor_SetEncodeExtraOptions", _wrap_SentencePieceProcessor_SetEncodeExtraOptions, METH_VARARGS, NULL},
	 { "SentencePieceProcessor_SetDecodeExtraOptions", _wrap_SentencePieceProcessor_SetDecodeExtraOptions, METH_VARARGS, NULL},
	 { "SentencePieceProcessor_SetVocabulary", _wrap_SentencePieceProcessor_SetVocabulary, METH_VARARGS, NULL},
	 { "SentencePieceProcessor_ResetVocabulary", _wrap_SentencePieceProcessor_ResetVocabulary, METH_O, NULL},
	 { "SentencePieceProcessor_LoadVocabulary", _wrap_SentencePieceProcessor_LoadVocabulary, METH_VARARGS, NULL},
	 { "SentencePieceProcessor_CalculateEntropy", _wrap_SentencePieceProcessor_CalculateEntropy, METH_VARARGS, NULL},
	 { "SentencePieceProcessor_GetPieceSize", _wrap_SentencePieceProcessor_GetPieceSize, METH_O, NULL},
	 { "SentencePieceProcessor_PieceToId", _wrap_SentencePieceProcessor_PieceToId, METH_VARARGS, NULL},
	 { "SentencePieceProcessor_IdToPiece", _wrap_SentencePieceProcessor_IdToPiece, METH_VARARGS, NULL},
	 { "SentencePieceProcessor_GetScore", _wrap_SentencePieceProcessor_GetScore, METH_VARARGS, NULL},
	 { "SentencePieceProcessor_IsUnknown", _wrap_SentencePieceProcessor_IsUnknown, METH_VARARGS, NULL},
	 { "SentencePieceProcessor_IsControl", _wrap_SentencePieceProcessor_IsControl, METH_VARARGS, NULL},
	 { "SentencePieceProcessor_IsUnused", _wrap_SentencePieceProcessor_IsUnused, METH_VARARGS, NULL},
	 { "SentencePieceProcessor_IsByte", _wrap_SentencePieceProcessor_IsByte, METH_VARARGS, NULL},
	 { "SentencePieceProcessor_unk_id", _wrap_SentencePieceProcessor_unk_id, METH_O, NULL},
	 { "SentencePieceProcessor_bos_id", _wrap_SentencePieceProcessor_bos_id, METH_O, NULL},
	 { "SentencePieceProcessor_eos_id", _wrap_SentencePieceProcessor_eos_id, METH_O, NULL},
	 { "SentencePieceProcessor_pad_id", _wrap_SentencePieceProcessor_pad_id, METH_O, NULL},
	 { "SentencePieceProcessor_serialized_model_proto", _wrap_SentencePieceProcessor_serialized_model_proto, METH_O, NULL},
	 { "SentencePieceProcessor_LoadFromFile", _wrap_SentencePieceProcessor_LoadFromFile, METH_VARARGS, NULL},
	 { "SentencePieceProcessor__EncodeAsIds", _wrap_SentencePieceProcessor__EncodeAsIds, METH_VARARGS, NULL},
	 { "SentencePieceProcessor__EncodeAsPieces", _wrap_SentencePieceProcessor__EncodeAsPieces, METH_VARARGS, NULL},
	 { "SentencePieceProcessor__EncodeAsSerializedProto", _wrap_SentencePieceProcessor__EncodeAsSerializedProto, METH_VARARGS, NULL},
	 { "SentencePieceProcessor__EncodeAsImmutableProto", _wrap_SentencePieceProcessor__EncodeAsImmutableProto, METH_VARARGS, NULL},
	 { "SentencePieceProcessor__EncodeAsIdsBatch", _wrap_SentencePieceProcessor__EncodeAsIdsBatch, METH_VARARGS, NULL},
	 { "SentencePieceProcessor__EncodeAsPiecesBatch", _wrap_SentencePieceProcessor__EncodeAsPiecesBatch, METH_VARARGS, NULL},
	 { "SentencePieceProcessor__EncodeAsSerializedProtoBatch", _wrap_SentencePieceProcessor__EncodeAsSerializedProtoBatch, METH_VARARGS, NULL},
	 { "SentencePieceProcessor__EncodeAsImmutableProtoBatch", _wrap_SentencePieceProcessor__EncodeAsImmutableProtoBatch, METH_VARARGS, NULL},
	 { "SentencePieceProcessor__DecodeIds", _wrap_SentencePieceProcessor__DecodeIds, METH_VARARGS, NULL},
	 { "SentencePieceProcessor__DecodeIdsAsBytes", _wrap_SentencePieceProcessor__DecodeIdsAsBytes, METH_VARARGS, NULL},
	 { "SentencePieceProcessor__DecodePieces", _wrap_SentencePieceProcessor__DecodePieces, METH_VARARGS, NULL},
	 { "SentencePieceProcessor__DecodeIdsAsSerializedProto", _wrap_SentencePieceProcessor__DecodeIdsAsSerializedProto, METH_VARARGS, NULL},
	 { "SentencePieceProcessor__DecodePiecesAsSerializedProto", _wrap_SentencePieceProcessor__DecodePiecesAsSerializedProto, METH_VARARGS, NULL},
	 { "SentencePieceProcessor__DecodeIdsAsImmutableProto", _wrap_SentencePieceProcessor__DecodeIdsAsImmutableProto, METH_VARARGS, NULL},
	 { "SentencePieceProcessor__DecodePiecesAsImmutableProto", _wrap_SentencePieceProcessor__DecodePiecesAsImmutableProto, METH_VARARGS, NULL},
	 { "SentencePieceProcessor__DecodeIdsBatch", _wrap_SentencePieceProcessor__DecodeIdsBatch, METH_VARARGS, NULL},
	 { "SentencePieceProcessor__DecodeIdsAsBytesBatch", _wrap_SentencePieceProcessor__DecodeIdsAsBytesBatch, METH_VARARGS, NULL},
	 { "SentencePieceProcessor__DecodeIdsAsSerializedProtoBatch", _wrap_SentencePieceProcessor__DecodeIdsAsSerializedProtoBatch, METH_VARARGS, NULL},
	 { "SentencePieceProcessor__DecodeIdsAsImmutableProtoBatch", _wrap_SentencePieceProcessor__DecodeIdsAsImmutableProtoBatch, METH_VARARGS, NULL},
	 { "SentencePieceProcessor__DecodePiecesBatch", _wrap_SentencePieceProcessor__DecodePiecesBatch, METH_VARARGS, NULL},
	 { "SentencePieceProcessor__DecodePiecesAsSerializedProtoBatch", _wrap_SentencePieceProcessor__DecodePiecesAsSerializedProtoBatch, METH_VARARGS, NULL},
	 { "SentencePieceProcessor__DecodePiecesAsImmutableProtoBatch", _wrap_SentencePieceProcessor__DecodePiecesAsImmutableProtoBatch, METH_VARARGS, NULL},
	 { "SentencePieceProcessor__NBestEncodeAsIds", _wrap_SentencePieceProcessor__NBestEncodeAsIds, METH_VARARGS, NULL},
	 { "SentencePieceProcessor__NBestEncodeAsPieces", _wrap_SentencePieceProcessor__NBestEncodeAsPieces, METH_VARARGS, NULL},
	 { "SentencePieceProcessor__NBestEncodeAsSerializedProto", _wrap_SentencePieceProcessor__NBestEncodeAsSerializedProto, METH_VARARGS, NULL},
	 { "SentencePieceProcessor__NBestEncodeAsImmutableProto", _wrap_SentencePieceProcessor__NBestEncodeAsImmutableProto, METH_VARARGS, NULL},
	 { "SentencePieceProcessor__SampleEncodeAndScoreAsIds", _wrap_SentencePieceProcessor__SampleEncodeAndScoreAsIds, METH_VARARGS, NULL},
	 { "SentencePieceProcessor__SampleEncodeAndScoreAsPieces", _wrap_SentencePieceProcessor__SampleEncodeAndScoreAsPieces, METH_VARARGS, NULL},
	 { "SentencePieceProcessor__SampleEncodeAndScoreAsSerializedProto", _wrap_SentencePieceProcessor__SampleEncodeAndScoreAsSerializedProto, METH_VARARGS, NULL},
	 { "SentencePieceProcessor__SampleEncodeAndScoreAsImmutableProto", _wrap_SentencePieceProcessor__SampleEncodeAndScoreAsImmutableProto, METH_VARARGS, NULL},
	 { "SentencePieceProcessor__Normalize", _wrap_SentencePieceProcessor__Normalize, METH_VARARGS, NULL},
	 { "SentencePieceProcessor__NormalizeWithOffsets", _wrap_SentencePieceProcessor__NormalizeWithOffsets, METH_VARARGS, NULL},
	 { "SentencePieceProcessor__CalculateEntropy", _wrap_SentencePieceProcessor__CalculateEntropy, METH_VARARGS, NULL},
	 { "SentencePieceProcessor__CalculateEntropyBatch", _wrap_SentencePieceProcessor__CalculateEntropyBatch, METH_VARARGS, NULL},
	 { "SentencePieceProcessor__OverrideNormalizerSpec", _wrap_SentencePieceProcessor__OverrideNormalizerSpec, METH_VARARGS, NULL},
	 { "SentencePieceProcessor_swigregister", SentencePieceProcessor_swigregister, METH_O, NULL},
	 { "SentencePieceProcessor_swiginit", SentencePieceProcessor_swiginit, METH_VARARGS, NULL},
	 { "SetRandomGeneratorSeed", _wrap_SetRandomGeneratorSeed, METH_O, NULL},
	 { "SetMinLogLevel", _wrap_SetMinLogLevel, METH_O, NULL},
	 { "SentencePieceTrainer__TrainFromString", _wrap_SentencePieceTrainer__TrainFromString, METH_O, NULL},
	 { "SentencePieceTrainer__TrainFromMap", _wrap_SentencePieceTrainer__TrainFromMap, METH_O, NULL},
	 { "SentencePieceTrainer__TrainFromMap2", _wrap_SentencePieceTrainer__TrainFromMap2, METH_VARARGS, NULL},
	 { "SentencePieceTrainer__TrainFromMap3", _wrap_SentencePieceTrainer__TrainFromMap3, METH_O, NULL},
	 { "SentencePieceTrainer__TrainFromMap4", _wrap_SentencePieceTrainer__TrainFromMap4, METH_VARARGS, NULL},
	 { "SentencePieceTrainer_swigregister", SentencePieceTrainer_swigregister, METH_O, NULL},
	 { "new_SentencePieceNormalizer", _wrap_new_SentencePieceNormalizer, METH_NOARGS, NULL},
	 { "delete_SentencePieceNormalizer", _wrap_delete_SentencePieceNormalizer, METH_O, NULL},
	 { "SentencePieceNormalizer_LoadFromSerializedProto", _wrap_SentencePieceNormalizer_LoadFromSerializedProto, METH_VARARGS, NULL},
	 { "SentencePieceNormalizer_LoadFromRuleTSV", _wrap_SentencePieceNormalizer_LoadFromRuleTSV, METH_VARARGS, NULL},
	 { "SentencePieceNormalizer_LoadFromRuleName", _wrap_SentencePieceNormalizer_LoadFromRuleName, METH_VARARGS, NULL},
	 { "SentencePieceNormalizer_serialized_model_proto", _wrap_SentencePieceNormalizer_serialized_model_proto, METH_O, NULL},
	 { "SentencePieceNormalizer_LoadFromFile", _wrap_SentencePieceNormalizer_LoadFromFile, METH_VARARGS, NULL},
	 { "SentencePieceNormalizer__Normalize", _wrap_SentencePieceNormalizer__Normalize, METH_VARARGS, NULL},
	 { "SentencePieceNormalizer__NormalizeWithOffsets", _wrap_SentencePieceNormalizer__NormalizeWithOffsets, METH_VARARGS, NULL},
	 { "SentencePieceNormalizer__SetProtoField", _wrap_SentencePieceNormalizer__SetProtoField, METH_VARARGS, NULL},
	 { "SentencePieceNormalizer_swigregister", SentencePieceNormalizer_swigregister, METH_O, NULL},
	 { "SentencePieceNormalizer_swiginit", SentencePieceNormalizer_swiginit, METH_VARARGS, NULL},
	 { NULL, NULL, 0, NULL }
};


/* -------- TYPE CONVERSION AND EQUIVALENCE RULES (BEGIN) -------- */

static swig_type_info _swigt__p_char = {"_p_char", "char *", 0, 0, (void*)0, 0};
static swig_type_info _swigt__p_float = {"_p_float", "float *", 0, 0, (void*)0, 0};
static swig_type_info _swigt__p_sentencepiece__ImmutableNBestSentencePieceText = {"_p_sentencepiece__ImmutableNBestSentencePieceText", "sentencepiece::ImmutableNBestSentencePieceText *", 0, 0, (void*)0, 0};
static swig_type_info _swigt__p_sentencepiece__ImmutableSentencePieceText = {"_p_sentencepiece__ImmutableSentencePieceText", "sentencepiece::ImmutableSentencePieceText *", 0, 0, (void*)0, 0};
static swig_type_info _swigt__p_sentencepiece__ImmutableSentencePieceText_ImmutableSentencePiece = {"_p_sentencepiece__ImmutableSentencePieceText_ImmutableSentencePiece", "sentencepiece::ImmutableSentencePieceText_ImmutableSentencePiece *", 0, 0, (void*)0, 0};
static swig_type_info _swigt__p_sentencepiece__SentenceIterator = {"_p_sentencepiece__SentenceIterator", "sentencepiece::SentenceIterator *", 0, 0, (void*)0, 0};
static swig_type_info _swigt__p_sentencepiece__SentencePieceNormalizer = {"_p_sentencepiece__SentencePieceNormalizer", "sentencepiece::SentencePieceNormalizer *", 0, 0, (void*)0, 0};
static swig_type_info _swigt__p_sentencepiece__SentencePieceProcessor = {"_p_sentencepiece__SentencePieceProcessor", "sentencepiece::SentencePieceProcessor *", 0, 0, (void*)0, 0};
static swig_type_info _swigt__p_sentencepiece__SentencePieceTrainer = {"_p_sentencepiece__SentencePieceTrainer", "sentencepiece::SentencePieceTrainer *", 0, 0, (void*)0, 0};
static swig_type_info _swigt__p_std__string = {"_p_std__string", "sentencepiece::util::bytes *|std::string *", 0, 0, (void*)0, 0};
static swig_type_info _swigt__p_std__unordered_mapT_std__string_std__string_t = {"_p_std__unordered_mapT_std__string_std__string_t", "std::unordered_map< std::string,std::string > *", 0, 0, (void*)0, 0};
static swig_type_info _swigt__p_std__vectorT_absl__string_view_t = {"_p_std__vectorT_absl__string_view_t", "std::vector< absl::string_view > *", 0, 0, (void*)0, 0};
static swig_type_info _swigt__p_std__vectorT_int_t = {"_p_std__vectorT_int_t", "std::vector< int > *", 0, 0, (void*)0, 0};
static swig_type_info _swigt__p_std__vectorT_std__vectorT_absl__string_view_t_t = {"_p_std__vectorT_std__vectorT_absl__string_view_t_t", "std::vector< std::vector< absl::string_view > > *", 0, 0, (void*)0, 0};
static swig_type_info _swigt__p_std__vectorT_std__vectorT_int_t_t = {"_p_std__vectorT_std__vectorT_int_t_t", "std::vector< std::vector< int > > *", 0, 0, (void*)0, 0};

static swig_type_info *swig_type_initial[] = {
  &_swigt__p_char,
  &_swigt__p_float,
  &_swigt__p_sentencepiece__ImmutableNBestSentencePieceText,
  &_swigt__p_sentencepiece__ImmutableSentencePieceText,
  &_swigt__p_sentencepiece__ImmutableSentencePieceText_ImmutableSentencePiece,
  &_swigt__p_sentencepiece__SentenceIterator,
  &_swigt__p_sentencepiece__SentencePieceNormalizer,
  &_swigt__p_sentencepiece__SentencePieceProcessor,
  &_swigt__p_sentencepiece__SentencePieceTrainer,
  &_swigt__p_std__string,
  &_swigt__p_std__unordered_mapT_std__string_std__string_t,
  &_swigt__p_std__vectorT_absl__string_view_t,
  &_swigt__p_std__vectorT_int_t,
  &_swigt__p_std__vectorT_std__vectorT_absl__string_view_t_t,
  &_swigt__p_std__vectorT_std__vectorT_int_t_t,
};

static swig_cast_info _swigc__p_char[] = {  {&_swigt__p_char, 0, 0, 0},{0, 0, 0, 0}};
static swig_cast_info _swigc__p_float[] = {  {&_swigt__p_float, 0, 0, 0},{0, 0, 0, 0}};
static swig_cast_info _swigc__p_sentencepiece__ImmutableNBestSentencePieceText[] = {  {&_swigt__p_sentencepiece__ImmutableNBestSentencePieceText, 0, 0, 0},{0, 0, 0, 0}};
static swig_cast_info _swigc__p_sentencepiece__ImmutableSentencePieceText[] = {  {&_swigt__p_sentencepiece__ImmutableSentencePieceText, 0, 0, 0},{0, 0, 0, 0}};
static swig_cast_info _swigc__p_sentencepiece__ImmutableSentencePieceText_ImmutableSentencePiece[] = {  {&_swigt__p_sentencepiece__ImmutableSentencePieceText_ImmutableSentencePiece, 0, 0, 0},{0, 0, 0, 0}};
static swig_cast_info _swigc__p_sentencepiece__SentenceIterator[] = {  {&_swigt__p_sentencepiece__SentenceIterator, 0, 0, 0},{0, 0, 0, 0}};
static swig_cast_info _swigc__p_sentencepiece__SentencePieceNormalizer[] = {  {&_swigt__p_sentencepiece__SentencePieceNormalizer, 0, 0, 0},{0, 0, 0, 0}};
static swig_cast_info _swigc__p_sentencepiece__SentencePieceProcessor[] = {  {&_swigt__p_sentencepiece__SentencePieceProcessor, 0, 0, 0},{0, 0, 0, 0}};
static swig_cast_info _swigc__p_sentencepiece__SentencePieceTrainer[] = {  {&_swigt__p_sentencepiece__SentencePieceTrainer, 0, 0, 0},{0, 0, 0, 0}};
static swig_cast_info _swigc__p_std__string[] = {  {&_swigt__p_std__string, 0, 0, 0},{0, 0, 0, 0}};
static swig_cast_info _swigc__p_std__unordered_mapT_std__string_std__string_t[] = {  {&_swigt__p_std__unordered_mapT_std__string_std__string_t, 0, 0, 0},{0, 0, 0, 0}};
static swig_cast_info _swigc__p_std__vectorT_absl__string_view_t[] = {  {&_swigt__p_std__vectorT_absl__string_view_t, 0, 0, 0},{0, 0, 0, 0}};
static swig_cast_info _swigc__p_std__vectorT_int_t[] = {  {&_swigt__p_std__vectorT_int_t, 0, 0, 0},{0, 0, 0, 0}};
static swig_cast_info _swigc__p_std__vectorT_std__vectorT_absl__string_view_t_t[] = {  {&_swigt__p_std__vectorT_std__vectorT_absl__string_view_t_t, 0, 0, 0},{0, 0, 0, 0}};
static swig_cast_info _swigc__p_std__vectorT_std__vectorT_int_t_t[] = {  {&_swigt__p_std__vectorT_std__vectorT_int_t_t, 0, 0, 0},{0, 0, 0, 0}};

static swig_cast_info *swig_cast_initial[] = {
  _swigc__p_char,
  _swigc__p_float,
  _swigc__p_sentencepiece__ImmutableNBestSentencePieceText,
  _swigc__p_sentencepiece__ImmutableSentencePieceText,
  _swigc__p_sentencepiece__ImmutableSentencePieceText_ImmutableSentencePiece,
  _swigc__p_sentencepiece__SentenceIterator,
  _swigc__p_sentencepiece__SentencePieceNormalizer,
  _swigc__p_sentencepiece__SentencePieceProcessor,
  _swigc__p_sentencepiece__SentencePieceTrainer,
  _swigc__p_std__string,
  _swigc__p_std__unordered_mapT_std__string_std__string_t,
  _swigc__p_std__vectorT_absl__string_view_t,
  _swigc__p_std__vectorT_int_t,
  _swigc__p_std__vectorT_std__vectorT_absl__string_view_t_t,
  _swigc__p_std__vectorT_std__vectorT_int_t_t,
};


/* -------- TYPE CONVERSION AND EQUIVALENCE RULES (END) -------- */

static swig_const_info swig_const_table[] = {
{0, 0, 0, 0.0, 0, 0}};

#ifdef __cplusplus
}
#endif
/* -----------------------------------------------------------------------------
 * Type initialization:
 * This problem is tough by the requirement that no dynamic
 * memory is used. Also, since swig_type_info structures store pointers to
 * swig_cast_info structures and swig_cast_info structures store pointers back
 * to swig_type_info structures, we need some lookup code at initialization.
 * The idea is that swig generates all the structures that are needed.
 * The runtime then collects these partially filled structures.
 * The SWIG_InitializeModule function takes these initial arrays out of
 * swig_module, and does all the lookup, filling in the swig_module.types
 * array with the correct data and linking the correct swig_cast_info
 * structures together.
 *
 * The generated swig_type_info structures are assigned statically to an initial
 * array. We just loop through that array, and handle each type individually.
 * First we lookup if this type has been already loaded, and if so, use the
 * loaded structure instead of the generated one. Then we have to fill in the
 * cast linked list. The cast data is initially stored in something like a
 * two-dimensional array. Each row corresponds to a type (there are the same
 * number of rows as there are in the swig_type_initial array). Each entry in
 * a column is one of the swig_cast_info structures for that type.
 * The cast_initial array is actually an array of arrays, because each row has
 * a variable number of columns. So to actually build the cast linked list,
 * we find the array of casts associated with the type, and loop through it
 * adding the casts to the list. The one last trick we need to do is making
 * sure the type pointer in the swig_cast_info struct is correct.
 *
 * First off, we lookup the cast->type name to see if it is already loaded.
 * There are three cases to handle:
 *  1) If the cast->type has already been loaded AND the type we are adding
 *     casting info to has not been loaded (it is in this module), THEN we
 *     replace the cast->type pointer with the type pointer that has already
 *     been loaded.
 *  2) If BOTH types (the one we are adding casting info to, and the
 *     cast->type) are loaded, THEN the cast info has already been loaded by
 *     the previous module so we just ignore it.
 *  3) Finally, if cast->type has not already been loaded, then we add that
 *     swig_cast_info to the linked list (because the cast->type) pointer will
 *     be correct.
 * ----------------------------------------------------------------------------- */

#ifdef __cplusplus
extern "C" {
#if 0
} /* c-mode */
#endif
#endif

#if 0
#define SWIGRUNTIME_DEBUG
#endif

#ifndef SWIG_INIT_CLIENT_DATA_TYPE
#define SWIG_INIT_CLIENT_DATA_TYPE void *
#endif

SWIGRUNTIME void
SWIG_InitializeModule(SWIG_INIT_CLIENT_DATA_TYPE clientdata) {
  size_t i;
  swig_module_info *module_head, *iter;
  int init;
  
  /* check to see if the circular list has been setup, if not, set it up */
  if (swig_module.next==0) {
    /* Initialize the swig_module */
    swig_module.type_initial = swig_type_initial;
    swig_module.cast_initial = swig_cast_initial;
    swig_module.next = &swig_module;
    init = 1;
  } else {
    init = 0;
  }
  
  /* Try and load any already created modules */
  module_head = SWIG_GetModule(clientdata);
  if (!module_head) {
    /* This is the first module loaded for this interpreter */
    /* so set the swig module into the interpreter */
    SWIG_SetModule(clientdata, &swig_module);
  } else {
    /* the interpreter has loaded a SWIG module, but has it loaded this one? */
    iter=module_head;
    do {
      if (iter==&swig_module) {
        /* Our module is already in the list, so there's nothing more to do. */
        return;
      }
      iter=iter->next;
    } while (iter!= module_head);
    
    /* otherwise we must add our module into the list */
    swig_module.next = module_head->next;
    module_head->next = &swig_module;
  }
  
  /* When multiple interpreters are used, a module could have already been initialized in
       a different interpreter, but not yet have a pointer in this interpreter.
       In this case, we do not want to continue adding types... everything should be
       set up already */
  if (init == 0) return;
  
  /* Now work on filling in swig_module.types */
#ifdef SWIGRUNTIME_DEBUG
  printf("SWIG_InitializeModule: size %lu\n", (unsigned long)swig_module.size);
#endif
  for (i = 0; i < swig_module.size; ++i) {
    swig_type_info *type = 0;
    swig_type_info *ret;
    swig_cast_info *cast;
    
#ifdef SWIGRUNTIME_DEBUG
    printf("SWIG_InitializeModule: type %lu %s\n", (unsigned long)i, swig_module.type_initial[i]->name);
#endif
    
    /* if there is another module already loaded */
    if (swig_module.next != &swig_module) {
      type = SWIG_MangledTypeQueryModule(swig_module.next, &swig_module, swig_module.type_initial[i]->name);
    }
    if (type) {
      /* Overwrite clientdata field */
#ifdef SWIGRUNTIME_DEBUG
      printf("SWIG_InitializeModule: found type %s\n", type->name);
#endif
      if (swig_module.type_initial[i]->clientdata) {
        type->clientdata = swig_module.type_initial[i]->clientdata;
#ifdef SWIGRUNTIME_DEBUG
        printf("SWIG_InitializeModule: found and overwrite type %s \n", type->name);
#endif
      }
    } else {
      type = swig_module.type_initial[i];
    }
    
    /* Insert casting types */
    cast = swig_module.cast_initial[i];
    while (cast->type) {
      /* Don't need to add information already in the list */
      ret = 0;
#ifdef SWIGRUNTIME_DEBUG
      printf("SWIG_InitializeModule: look cast %s\n", cast->type->name);
#endif
      if (swig_module.next != &swig_module) {
        ret = SWIG_MangledTypeQueryModule(swig_module.next, &swig_module, cast->type->name);
#ifdef SWIGRUNTIME_DEBUG
        if (ret) printf("SWIG_InitializeModule: found cast %s\n", ret->name);
#endif
      }
      if (ret) {
        if (type == swig_module.type_initial[i]) {
#ifdef SWIGRUNTIME_DEBUG
          printf("SWIG_InitializeModule: skip old type %s\n", ret->name);
#endif
          cast->type = ret;
          ret = 0;
        } else {
          /* Check for casting already in the list */
          swig_cast_info *ocast = SWIG_TypeCheck(ret->name, type);
#ifdef SWIGRUNTIME_DEBUG
          if (ocast) printf("SWIG_InitializeModule: skip old cast %s\n", ret->name);
#endif
          if (!ocast) ret = 0;
        }
      }
      
      if (!ret) {
#ifdef SWIGRUNTIME_DEBUG
        printf("SWIG_InitializeModule: adding cast %s\n", cast->type->name);
#endif
        if (type->cast) {
          type->cast->prev = cast;
          cast->next = type->cast;
        }
        type->cast = cast;
      }
      cast++;
    }
    /* Set entry in modules->types array equal to the type */
    swig_module.types[i] = type;
  }
  swig_module.types[i] = 0;
  
#ifdef SWIGRUNTIME_DEBUG
  printf("**** SWIG_InitializeModule: Cast List ******\n");
  for (i = 0; i < swig_module.size; ++i) {
    int j = 0;
    swig_cast_info *cast = swig_module.cast_initial[i];
    printf("SWIG_InitializeModule: type %lu %s\n", (unsigned long)i, swig_module.type_initial[i]->name);
    while (cast->type) {
      printf("SWIG_InitializeModule: cast type %s\n", cast->type->name);
      cast++;
      ++j;
    }
    printf("---- Total casts: %d\n",j);
  }
  printf("**** SWIG_InitializeModule: Cast List ******\n");
#endif
}

/* This function will propagate the clientdata field of type to
* any new swig_type_info structures that have been added into the list
* of equivalent types.  It is like calling
* SWIG_TypeClientData(type, clientdata) a second time.
*/
SWIGRUNTIME void
SWIG_PropagateClientData(void) {
  size_t i;
  swig_cast_info *equiv;
  static int init_run = 0;
  
  if (init_run) return;
  init_run = 1;
  
  for (i = 0; i < swig_module.size; i++) {
    if (swig_module.types[i]->clientdata) {
      equiv = swig_module.types[i]->cast;
      while (equiv) {
        if (!equiv->converter) {
          if (equiv->type && !equiv->type->clientdata)
          SWIG_TypeClientData(equiv->type, swig_module.types[i]->clientdata);
        }
        equiv = equiv->next;
      }
    }
  }
}

#ifdef __cplusplus
#if 0
{
  /* c-mode */
#endif
}
#endif



#ifdef __cplusplus
extern "C" {
#endif
  
  /* -----------------------------------------------------------------------------
   * constants/methods manipulation
   * ----------------------------------------------------------------------------- */
  
  /* Install Constants */
  SWIGINTERN void
  SWIG_Python_InstallConstants(PyObject *d, swig_const_info constants[]) {
    PyObject *obj = 0;
    size_t i;
    for (i = 0; constants[i].type; ++i) {
      switch(constants[i].type) {
      case SWIG_PY_POINTER:
        obj = SWIG_InternalNewPointerObj(constants[i].pvalue, *(constants[i]).ptype,0);
        break;
      case SWIG_PY_BINARY:
        obj = SWIG_NewPackedObj(constants[i].pvalue, constants[i].lvalue, *(constants[i].ptype));
        break;
      default:
        obj = 0;
        break;
      }
      if (obj) {
        PyDict_SetItemString(d, constants[i].name, obj);
        Py_DECREF(obj);
      }
    }
  }
  
  /* -----------------------------------------------------------------------------
   * Patch %callback methods' docstrings to hold the callback ptrs
   * -----------------------------------------------------------------------------*/
  
  SWIGINTERN void
  SWIG_Python_FixMethods(PyMethodDef *methods, const swig_const_info *const_table, swig_type_info **types, swig_type_info **types_initial) {
    size_t i;
    for (i = 0; methods[i].ml_name; ++i) {
      const char *c = methods[i].ml_doc;
      if (!c) continue;
      c = strstr(c, "swig_ptr: ");
      if (c) {
        int j;
        const swig_const_info *ci = 0;
        const char *name = c + 10;
        for (j = 0; const_table[j].type; ++j) {
          if (strncmp(const_table[j].name, name, 
              strlen(const_table[j].name)) == 0) {
            ci = &(const_table[j]);
            break;
          }
        }
        if (ci) {
          void *ptr = (ci->type == SWIG_PY_POINTER) ? ci->pvalue : 0;
          if (ptr) {
            size_t shift = (ci->ptype) - types;
            swig_type_info *ty = types_initial[shift];
            size_t ldoc = (c - methods[i].ml_doc);
            size_t lptr = strlen(ty->name)+2*sizeof(void*)+2;
            char *ndoc = (char*)malloc(ldoc + lptr + 10);
            if (ndoc) {
              char *buff = ndoc;
              memcpy(buff, methods[i].ml_doc, ldoc);
              buff += ldoc;
              memcpy(buff, "swig_ptr: ", 10);
              buff += 10;
              SWIG_PackVoidPtr(buff, ptr, ty->name, lptr);
              methods[i].ml_doc = ndoc;
            }
          }
        }
      }
    }
  } 
  
#ifdef __cplusplus
}
#endif




/* -----------------------------------------------------------------------------*
 *  Partial Init method
 * -----------------------------------------------------------------------------*/

#ifdef __cplusplus
extern "C"
#endif

SWIGEXPORT 
#if PY_VERSION_HEX >= 0x03000000
PyObject*
#else
void
#endif
SWIG_init(void) {
  PyObject *m, *d, *md, *globals;
  
#if PY_VERSION_HEX >= 0x03000000
  static struct PyModuleDef SWIG_module = {
    PyModuleDef_HEAD_INIT,
    SWIG_name,
    NULL,
    -1,
    SwigMethods,
    NULL,
    NULL,
    NULL,
    NULL
  };
#endif
  
#if defined(SWIGPYTHON_BUILTIN)
  static SwigPyClientData SwigPyObject_clientdata = {
    0, 0, 0, 0, 0, 0, 0
  };
  static PyGetSetDef this_getset_def = {
    (char *)"this", &SwigPyBuiltin_ThisClosure, NULL, NULL, NULL
  };
  static SwigPyGetSet thisown_getset_closure = {
    SwigPyObject_own,
    SwigPyObject_own
  };
  static PyGetSetDef thisown_getset_def = {
    (char *)"thisown", SwigPyBuiltin_GetterClosure, SwigPyBuiltin_SetterClosure, NULL, &thisown_getset_closure
  };
  PyTypeObject *builtin_pytype;
  int builtin_base_count;
  swig_type_info *builtin_basetype;
  PyObject *tuple;
  PyGetSetDescrObject *static_getset;
  PyTypeObject *metatype;
  PyTypeObject *swigpyobject;
  SwigPyClientData *cd;
  PyObject *public_interface, *public_symbol;
  PyObject *this_descr;
  PyObject *thisown_descr;
  PyObject *self = 0;
  int i;
  
  (void)builtin_pytype;
  (void)builtin_base_count;
  (void)builtin_basetype;
  (void)tuple;
  (void)static_getset;
  (void)self;
  
  /* Metaclass is used to implement static member variables */
  metatype = SwigPyObjectType();
  assert(metatype);
#endif
  
  (void)globals;
  
  /* Create singletons now to avoid potential deadlocks with multi-threaded usage after module initialization */
  SWIG_This();
  SWIG_Python_TypeCache();
  SwigPyPacked_type();
#ifndef SWIGPYTHON_BUILTIN
  SwigPyObject_type();
#endif
  
  /* Fix SwigMethods to carry the callback ptrs when needed */
  SWIG_Python_FixMethods(SwigMethods, swig_const_table, swig_types, swig_type_initial);
  
#if PY_VERSION_HEX >= 0x03000000
  m = PyModule_Create(&SWIG_module);
#else
  m = Py_InitModule(SWIG_name, SwigMethods);
#endif
  
  md = d = PyModule_GetDict(m);
  (void)md;
  
  SWIG_InitializeModule(0);
  
#ifdef SWIGPYTHON_BUILTIN
  swigpyobject = SwigPyObject_TypeOnce();
  
  SwigPyObject_stype = SWIG_MangledTypeQuery("_p_SwigPyObject");
  assert(SwigPyObject_stype);
  cd = (SwigPyClientData*) SwigPyObject_stype->clientdata;
  if (!cd) {
    SwigPyObject_stype->clientdata = &SwigPyObject_clientdata;
    SwigPyObject_clientdata.pytype = swigpyobject;
  } else if (swigpyobject->tp_basicsize != cd->pytype->tp_basicsize) {
    PyErr_SetString(PyExc_RuntimeError, "Import error: attempted to load two incompatible swig-generated modules.");
# if PY_VERSION_HEX >= 0x03000000
    return NULL;
# else
    return;
# endif
  }
  
  /* All objects have a 'this' attribute */
  this_descr = PyDescr_NewGetSet(SwigPyObject_type(), &this_getset_def);
  (void)this_descr;
  
  /* All objects have a 'thisown' attribute */
  thisown_descr = PyDescr_NewGetSet(SwigPyObject_type(), &thisown_getset_def);
  (void)thisown_descr;
  
  public_interface = PyList_New(0);
  public_symbol = 0;
  (void)public_symbol;
  
  PyDict_SetItemString(md, "__all__", public_interface);
  Py_DECREF(public_interface);
  for (i = 0; SwigMethods[i].ml_name != NULL; ++i)
  SwigPyBuiltin_AddPublicSymbol(public_interface, SwigMethods[i].ml_name);
  for (i = 0; swig_const_table[i].name != 0; ++i)
  SwigPyBuiltin_AddPublicSymbol(public_interface, swig_const_table[i].name);
#endif
  
  SWIG_InstallConstants(d,swig_const_table);
  
#if PY_VERSION_HEX >= 0x03000000
  return m;
#else
  return;
#endif
}
