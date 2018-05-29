/*
 * BlueALSA - ffb.h
 * Copyright (c) 2016-2018 Arkadiusz Bokowy
 *
 * This file is a part of bluez-alsa.
 *
 * This project is licensed under the terms of the MIT license.
 *
 */

#ifndef BLUEALSA_SHARED_FFB_H_
#define BLUEALSA_SHARED_FFB_H_

#include <stddef.h>
#include <stdint.h>
#include <string.h>

/**
 * Convenience wrapper for FIFO-like buffer for uint8_t. */
typedef struct {
	/* pointer to the allocated memory block */
	uint8_t *data;
	/* pointer to the end of data */
	uint8_t *tail;
	/* size of the buffer */
	size_t size;
} ffb_uint8_t;

/**
 * Convenience wrapper for FIFO-like buffer for int16_t. */
typedef struct {
	int16_t *data;
	int16_t *tail;
	size_t size;
} ffb_int16_t;

int ffb_uint8_init(ffb_uint8_t *ffb, size_t size);
void ffb_uint8_free(ffb_uint8_t *ffb);

int ffb_int16_init(ffb_int16_t *ffb, size_t size);
void ffb_int16_free(ffb_int16_t *ffb);

#define ffb_len_in(p) ((p)->size - ffb_len_out(p))
#define ffb_len_out(p) ((size_t)((p)->tail - (p)->data))

#define ffb_seek(p, len) ((p)->tail += len)
#define ffb_rewind(p, len) do { \
		memmove((p)->data, (p)->data + (len), sizeof(*(p)->data) * (ffb_len_out(p) - (len))); \
		(p)->tail -= len; \
	} while (0)

#endif
