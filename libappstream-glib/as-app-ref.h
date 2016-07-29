/* -*- Mode: C; tab-width: 8; indent-tabs-mode: t; c-basic-offset: 8 -*-
 *
 * Copyright (C) 2016 Richard Hughes <richard@hughsie.com>
 *
 * Licensed under the GNU General Public License Version 2
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA.
 */

#ifndef __AS_APP_REF_H
#define __AS_APP_REF_H

#include <glib-object.h>

G_BEGIN_DECLS

#define AS_TYPE_APP_REF	(as_app_ref_get_type ())

G_DECLARE_FINAL_TYPE (AsAppRef, as_app_ref, AS, APP_REF, GObject)

AsAppRef	*as_app_ref_new			(const gchar	*id);
AsAppRef	*as_app_ref_new_from_string	(const gchar	*str);

const gchar	*as_app_ref_get_scope		(AsAppRef	*app_ref);
const gchar	*as_app_ref_get_system		(AsAppRef	*app_ref);
const gchar	*as_app_ref_get_origin		(AsAppRef	*app_ref);
const gchar	*as_app_ref_get_kind		(AsAppRef	*app_ref);
const gchar	*as_app_ref_get_id		(AsAppRef	*app_ref);
const gchar	*as_app_ref_get_arch		(AsAppRef	*app_ref);
const gchar	*as_app_ref_get_branch		(AsAppRef	*app_ref);

void		 as_app_ref_set_scope		(AsAppRef	*app_ref,
						 const gchar	*scope);
void		 as_app_ref_set_system		(AsAppRef	*app_ref,
						 const gchar	*system);
void		 as_app_ref_set_origin		(AsAppRef	*app_ref,
						 const gchar	*origin);
void		 as_app_ref_set_kind		(AsAppRef	*app_ref,
						 const gchar	*kind);
void		 as_app_ref_set_id		(AsAppRef	*app_ref,
						 const gchar	*id);
void		 as_app_ref_set_arch		(AsAppRef	*app_ref,
						 const gchar	*arch);
void		 as_app_ref_set_branch		(AsAppRef	*app_ref,
						 const gchar	*branch);

gchar		*as_app_ref_to_string		(AsAppRef	*app_ref);
gboolean	 as_app_ref_equal		(AsAppRef	*app_ref1,
						 AsAppRef	*app_ref2);

G_END_DECLS

#endif /* __AS_APP_REF_H */
