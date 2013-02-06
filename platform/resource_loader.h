/* @license
 * This file is part of the Game Closure SDK.
 *
 * The Game Closure SDK is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 
 * The Game Closure SDK is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU General Public License for more details.
 
 * You should have received a copy of the GNU General Public License
 * along with the Game Closure SDK.  If not, see <http://www.gnu.org/licenses/>.
 */

#ifndef RESOURCE_LOADER_H
#define RESOURCE_LOADER_H

#include "platform/platform.h"
#include "core/util/detect.h"
#include "core/texture_2d.h"
#include <pthread.h>

typedef struct resource_t {
	union {
		char *text;
		int tex;
	};
	long long int size;
	bool mapped;
} resource;

typedef struct resource_t *resource_p;

#ifdef __cplusplus
extern "C" {
#endif

void resource_loader_initialize(const char *path);
void resource_loader_deinitialize();
resource_p resource_loader_load_url(const char *url);
unsigned char *resource_loader_read_file(const char *url, unsigned long *sz);
bool is_remote_resource(const char *url);
void launch_remote_texture_load(const char *url);
char *resource_loader_string_from_url(const char *url);
bool resource_loader_load_image_with_c(texture_2d *texture);
void resource_loader_destroy_resource(resource_p res);
unsigned char *load_texture(texture_2d *texture);

#ifdef __cplusplus
}
#endif

#endif
