#include <stdint.h>
#include "ruby.h"

#define PRIME32 16777619
#define PRIME64 1099511628211UL


/**
 * FNV fast hashing algorithm in 32 bits.
 * @see http://en.wikipedia.org/wiki/Fowler_Noll_Vo_hash
 */
static inline uint32_t fnv1_32(const char *data, uint32_t len) {
  uint32_t rv = 0x811c9dc5U;
  uint32_t i;
  for (i = 0; i < len; i++) {
    rv = (rv * PRIME32) ^ (unsigned char)(data[i]);
  }
  return rv;
}

/**
 * FNV fast hashing algorithm in 32 bits, variant with operations reversed.
 * @see http://en.wikipedia.org/wiki/Fowler_Noll_Vo_hash
 */
static inline uint32_t fnv1a_32(const char *data, uint32_t len) {
  uint32_t rv = 0x811c9dc5U;
  uint32_t i;
  for (i = 0; i < len; i++) {
    rv = (rv ^ (unsigned char)data[i]) * PRIME32;
  }
  return rv;
}

/**
 * FNV fast hashing algorithm in 64 bits.
 * @see http://en.wikipedia.org/wiki/Fowler_Noll_Vo_hash
 */
static inline uint64_t fnv1_64(const char *data, uint32_t len) {
  uint64_t rv = 0xcbf29ce484222325UL;
  uint32_t i;
  for (i = 0; i < len; i++) {
    rv = (rv * PRIME64) ^ (unsigned char)data[i];
  }
  return (uint64_t)rv;
}

/**
 * FNV fast hashing algorithm in 64 bits, variant with operations reversed.
 * @see http://en.wikipedia.org/wiki/Fowler_Noll_Vo_hash
 */
static inline uint64_t fnv1a_64(const char *data, uint32_t len) {
  uint64_t rv = 0xcbf29ce484222325UL;
  uint32_t i;
  for (i = 0; i < len; i++) {
    rv = (rv ^ (unsigned char)data[i]) * PRIME64;
  }
  return (uint64_t)rv;
}


/* ----- ruby bindings ----- */

static VALUE rbfnv_fnv1_32(VALUE self, VALUE data) {
  return UINT2NUM(fnv1_32(RSTRING(data)->ptr, RSTRING(data)->len));
}

static VALUE rbfnv_fnv1a_32(VALUE self, VALUE data) {
  return UINT2NUM(fnv1a_32(RSTRING(data)->ptr, RSTRING(data)->len));
}

static VALUE rbfnv_fnv1_64(VALUE self, VALUE data) {
  return ULL2NUM(fnv1_64(RSTRING(data)->ptr, RSTRING(data)->len));
}

static VALUE rbfnv_fnv1a_64(VALUE self, VALUE data) {
  return ULL2NUM(fnv1a_64(RSTRING(data)->ptr, RSTRING(data)->len));
}


static VALUE rb_rbfnv;

void Init_rbfnv() {
  /* nothing here yet */
  rb_rbfnv = rb_define_module("Rbfnv");
  rb_define_singleton_method(rb_rbfnv, "fnv1_32", rbfnv_fnv1_32, 1);
  rb_define_singleton_method(rb_rbfnv, "fnv1a_32", rbfnv_fnv1a_32, 1);
  rb_define_singleton_method(rb_rbfnv, "fnv1_64", rbfnv_fnv1_64, 1);
  rb_define_singleton_method(rb_rbfnv, "fnv1a_64", rbfnv_fnv1a_64, 1);
}
