/*
 * Copyright (C) 2018 Paul Kocialkowski <paul.kocialkowski@bootlin.com>
 *
 * Permission is hereby granted, free of charge, to any person obtaining a
 * copy of this software and associated documentation files (the
 * "Software"), to deal in the Software without restriction, including
 * without limitation the rights to use, copy, modify, merge, publish,
 * distribute, sub license, and/or sell copies of the Software, and to
 * permit persons to whom the Software is furnished to do so, subject to
 * the following conditions:
 *
 * The above copyright notice and this permission notice (including the
 * next paragraph) shall be included in all copies or substantial portions
 * of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS
 * OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
 * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NON-INFRINGEMENT.
 * IN NO EVENT SHALL PRECISION INSIGHT AND/OR ITS SUPPLIERS BE LIABLE FOR
 * ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT,
 * TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE
 * SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
 */

#ifndef _MEDIA_H_
#define _MEDIA_H_

/* ioctls */

#define MEDIA_IOC_DEVICE_INFO	_IOWR('|', 0x00, struct media_device_info)
#define MEDIA_IOC_ENUM_ENTITIES	_IOWR('|', 0x01, struct media_entity_desc)
#define MEDIA_IOC_ENUM_LINKS	_IOWR('|', 0x02, struct media_links_enum)
#define MEDIA_IOC_SETUP_LINK	_IOWR('|', 0x03, struct media_link_desc)
#define MEDIA_IOC_G_TOPOLOGY	_IOWR('|', 0x04, struct media_v2_topology)
#define MEDIA_IOC_REQUEST_ALLOC	_IOR ('|', 0x05, int)

/*
 * These ioctls are called on the request file descriptor as returned
 * by MEDIA_IOC_REQUEST_ALLOC.
 */
#define MEDIA_REQUEST_IOC_QUEUE		_IO('|',  0x80)
#define MEDIA_REQUEST_IOC_REINIT	_IO('|',  0x81)


int media_request_alloc(int media_fd);
int media_request_reinit(int request_fd);
int media_request_queue(int request_fd);
int media_request_wait_completion(int request_fd);

#endif
