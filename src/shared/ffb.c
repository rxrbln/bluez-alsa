/*
 * BlueALSA - ffb.c
 * Copyright (c) 2016-2018 Arkadiusz Bokowy
 *
 * This file is a part of bluez-alsa.
 *
 * This project is licensed under the terms of the MIT license.
 *
 */

#include "shared/ffb.h"

#include <stdlib.h>


/**
 * Allocated resources for FIFO-like buffer.
 *
 * @param ffb Pointer to the buffer structure which should be initialized.
 * @param size Number of the buffer unite blocks.
 * @return On success this function returns 0. Otherwise, -1 is returned and
 *	 errno is set to indicate the error. */
int ffb_uint8_init(ffb_uint8_t *ffb, size_t size) {
	if ((ffb->data = ffb->tail = malloc(size * sizeof(*ffb->data))) == NULL)
		return -1;
	ffb->size = size;
	return 0;
}

/**
 * Free resources allocated by the ffb_uint8_init().
 *
 * @param ffb Pointer to initialized buffer structure. */
void ffb_uint8_free(ffb_uint8_t *ffb) {
	if (ffb->data == NULL)
		return;
	free(ffb->data);
	ffb->data = NULL;
}

/**
 * Allocated resources for FIFO-like buffer.
 *
 * @param ffb Pointer to the buffer structure which should be initialized.
 * @param size Number of the buffer unite blocks.
 * @return On success this function returns 0. Otherwise, -1 is returned and
 *	 errno is set to indicate the error. */
int ffb_int16_init(ffb_int16_t *ffb, size_t size) {
	if ((ffb->data = ffb->tail = malloc(size * sizeof(*ffb->data))) == NULL)
		return -1;
	ffb->size = size;
	return 0;
}

/**
 * Free resources allocated by the ffb_int16_init().
 *
 * @param ffb Pointer to initialized buffer structure. */
void ffb_int16_free(ffb_int16_t *ffb) {
	if (ffb->data == NULL)
		return;
	free(ffb->data);
	ffb->data = NULL;
}
