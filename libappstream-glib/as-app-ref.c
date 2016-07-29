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

/**
 * SECTION:as-app-ref
 * @short_description: An unique reference for an application
 * @include: appstream-glib.h
 * @stability: Stable
 *
 * This object represents a reference for the specific component in a store.
 *
 * The ID is made up of the following sections:
 *  1. Scope, e.g. `system` or `user`
 *  2. System, e.g. `package` or `flatpak`
 *  3. Origin, e.g. `fedora` or `gnome-apps-nightly`
 *  4. Kind, e.g. `app` or `runtime`
 *  5. AppStream ID, e.g. `gimp.desktop`
 *  6. Arch, e.g. `x86_64` or `i386`
 *  7. Branch, e.g. `3.20` or `master`
 *
 * For distro-supplied package-based components this unique ID would be valid:
 * `gimp.desktop/system/package/x/x/x/fedora`
 *
 * See also: #AsApp
 */

#include "config.h"

#include <glib.h>

#include "as-app-ref.h"

struct _AsAppRef
{
	GObject			 parent_instance;
	gchar			*scope;
	gchar			*system;
	gchar			*origin;
	gchar			*kind;
	gchar			*id;
	gchar			*arch;
	gchar			*branch;
};

G_DEFINE_TYPE (AsAppRef, as_app_ref, G_TYPE_OBJECT)

/**
 * as_app_ref_new_from_string:
 * @str: A #AsAppRef ID, e.g.
 *             "user/flatpak/gnome-apps-nightly/app/gimp.desktop/i386/master"
 *
 * Creates the application reference from a string.
 *
 * Since: 0.6.1
 *
 * Returns: A #AsAppRef, or %NULL for invalid
 **/
AsAppRef *
as_app_ref_new_from_string (const gchar *str)
{
	g_autoptr(AsAppRef) app_ref = NULL;
	g_auto(GStrv) split = NULL;

	/* trivial */
	if (str == NULL)
		return NULL;

	/* split by delimiter and check size */
	split = g_strsplit (str, "/", -1);
	if (g_strv_length (split) != 7)
		return NULL;

	/* check ID is set */
	if (split[4][0] == '\0')
		return NULL;

	/* create without strdup'ing everything again */
	app_ref = g_object_new (AS_TYPE_APP_REF, NULL);
	app_ref->scope = split[0];
	app_ref->system = split[1];
	app_ref->origin = split[2];
	app_ref->kind = split[3];
	app_ref->id = split[4];
	app_ref->arch = split[5];
	app_ref->branch = split[6];

	/* we consumed the contents */
	g_clear_pointer (&split, g_free);
	return g_steal_pointer (&app_ref);
}

/**
 * as_app_ref_get_scope:
 * @app_ref: A #AsAppRef
 *
 * Gets the application reference scope.
 *
 * Since: 0.6.1
 *
 * Returns: A string, or %NULL if unset
 **/
const gchar *
as_app_ref_get_scope (AsAppRef *app_ref)
{
	g_return_val_if_fail (AS_IS_APP_REF (app_ref), NULL);
	return app_ref->scope;
}

/**
 * as_app_ref_get_system:
 * @app_ref: A #AsAppRef
 *
 * Gets the application reference system.
 *
 * Since: 0.6.1
 *
 * Returns: A string, or %NULL if unset
 **/
const gchar *
as_app_ref_get_system (AsAppRef *app_ref)
{
	g_return_val_if_fail (AS_IS_APP_REF (app_ref), NULL);
	return app_ref->system;
}

/**
 * as_app_ref_get_origin:
 * @app_ref: A #AsAppRef
 *
 * Gets the application reference origin.
 *
 * Since: 0.6.1
 *
 * Returns: A string, or %NULL if unset
 **/
const gchar *
as_app_ref_get_origin (AsAppRef *app_ref)
{
	g_return_val_if_fail (AS_IS_APP_REF (app_ref), NULL);
	return app_ref->origin;
}

/**
 * as_app_ref_get_kind:
 * @app_ref: A #AsAppRef
 *
 * Gets the application reference kind.
 *
 * Since: 0.6.1
 *
 * Returns: A string, or %NULL if unset
 **/
const gchar *
as_app_ref_get_kind (AsAppRef *app_ref)
{
	g_return_val_if_fail (AS_IS_APP_REF (app_ref), NULL);
	return app_ref->kind;
}

/**
 * as_app_ref_get_id:
 * @app_ref: A #AsAppRef
 *
 * Gets the application reference id.
 *
 * Since: 0.6.1
 *
 * Returns: A string, or %NULL if unset
 **/
const gchar *
as_app_ref_get_id (AsAppRef *app_ref)
{
	g_return_val_if_fail (AS_IS_APP_REF (app_ref), NULL);
	return app_ref->id;
}

/**
 * as_app_ref_get_arch:
 * @app_ref: A #AsAppRef
 *
 * Gets the application reference arch.
 *
 * Since: 0.6.1
 *
 * Returns: A string, or %NULL if unset
 **/
const gchar *
as_app_ref_get_arch (AsAppRef *app_ref)
{
	g_return_val_if_fail (AS_IS_APP_REF (app_ref), NULL);
	return app_ref->arch;
}

/**
 * as_app_ref_get_branch:
 * @app_ref: A #AsAppRef
 *
 * Gets the application reference branch.
 *
 * Since: 0.6.1
 *
 * Returns: A string, or %NULL if unset
 **/
const gchar *
as_app_ref_get_branch (AsAppRef *app_ref)
{
	g_return_val_if_fail (AS_IS_APP_REF (app_ref), NULL);
	return app_ref->branch;
}

/**
 * as_app_ref_set_scope:
 * @app_ref: A #AsAppRef
 * @scope: The scope, e.g. `system` or `user`
 *
 * Sets the application reference scope.
 *
 * Since: 0.6.1
 **/
void
as_app_ref_set_scope (AsAppRef *app_ref, const gchar *scope)
{
	g_return_if_fail (AS_IS_APP_REF (app_ref));
	g_free (app_ref->scope);
	app_ref->scope = g_strdup (scope);
}

/**
 * as_app_ref_set_system:
 * @app_ref: A #AsAppRef
 * @system: The system, e.g. `package` or `flatpak`
 *
 * Sets the application reference system.
 *
 * Since: 0.6.1
 **/
void
as_app_ref_set_system (AsAppRef *app_ref, const gchar *system)
{
	g_return_if_fail (AS_IS_APP_REF (app_ref));
	g_free (app_ref->system);
	app_ref->system = g_strdup (system);
}

/**
 * as_app_ref_set_origin:
 * @app_ref: A #AsAppRef
 * @origin: The origin, e.g. `fedora` or `gnome-apps-nightly`
 *
 * Sets the application reference origin.
 *
 * Since: 0.6.1
 **/
void
as_app_ref_set_origin (AsAppRef *app_ref, const gchar *origin)
{
	g_return_if_fail (AS_IS_APP_REF (app_ref));
	g_free (app_ref->origin);
	app_ref->origin = g_strdup (origin);
}

/**
 * as_app_ref_set_kind:
 * @app_ref: A #AsAppRef
 * @kind: The kind, e.g. `app` or `runtime`
 *
 * Sets the application reference kind.
 *
 * Since: 0.6.1
 **/
void
as_app_ref_set_kind (AsAppRef *app_ref, const gchar *kind)
{
	g_return_if_fail (AS_IS_APP_REF (app_ref));
	g_free (app_ref->kind);
	app_ref->kind = g_strdup (kind);
}

/**
 * as_app_ref_set_id:
 * @app_ref: A #AsAppRef
 * @id: The AppStream ID, e.g. `gimp.desktop`
 *
 * Sets the application reference id.
 *
 * Since: 0.6.1
 **/
void
as_app_ref_set_id (AsAppRef *app_ref, const gchar *id)
{
	g_return_if_fail (AS_IS_APP_REF (app_ref));
	g_free (app_ref->id);
	app_ref->id = g_strdup (id);
}

/**
 * as_app_ref_set_arch:
 * @app_ref: A #AsAppRef
 * @arch: The arch, e.g. `x86_64` or `i386`
 *
 * Sets the application reference arch.
 *
 * Since: 0.6.1
 **/
void
as_app_ref_set_arch (AsAppRef *app_ref, const gchar *arch)
{
	g_return_if_fail (AS_IS_APP_REF (app_ref));
	g_free (app_ref->arch);
	app_ref->arch = g_strdup (arch);
}

/**
 * as_app_ref_set_branch:
 * @app_ref: A #AsAppRef
 * @branch: The branch, e.g. `3.20` or `master`
 *
 * Sets the application reference branch.
 *
 * Since: 0.6.1
 **/
void
as_app_ref_set_branch (AsAppRef *app_ref, const gchar *branch)
{
	g_return_if_fail (AS_IS_APP_REF (app_ref));
	g_free (app_ref->branch);
	app_ref->branch = g_strdup (branch);
}

static const gchar *
as_app_ref_fix_id_part (const gchar *tmp)
{
	if (tmp == NULL || tmp[0] == '\0')
		return "*";
	return tmp;
}

/**
 * as_app_ref_to_string:
 * @app_ref: A #AsAppRef
 *
 * Exports the application reference as a string.
 *
 * Returns: A string, or %NULL if invalid
 *
 * Since: 0.6.1
 **/
gchar *
as_app_ref_to_string (AsAppRef *app_ref)
{
	g_return_val_if_fail (AS_IS_APP_REF (app_ref), NULL);
	if (app_ref->id == NULL)
		return NULL;
	return g_strdup_printf ("%s/%s/%s/%s/%s/%s/%s",
				as_app_ref_fix_id_part (app_ref->scope),
				as_app_ref_fix_id_part (app_ref->system),
				as_app_ref_fix_id_part (app_ref->origin),
				as_app_ref_fix_id_part (app_ref->kind),
				app_ref->id,
				as_app_ref_fix_id_part (app_ref->arch),
				as_app_ref_fix_id_part (app_ref->branch));
}

static gboolean
as_app_ref_compare_id_part (const gchar *part1, const gchar *part2)
{
	if (part1 == NULL || part1[0] == '*')
		return TRUE;
	if (part2 == NULL || part2[0] == '*')
		return TRUE;
	return g_strcmp0 (part1, part2) == 0;
}

/**
 * as_app_ref_equal:
 * @app_ref1: a #AsAppRef
 * @app_ref2: another #AsAppRef
 *
 * Compares each app reference for equality, taking into account wildcards.
 *
 * Returns: %TRUE if the IDs are equal
 *
 * Since: 0.6.1
 */
gboolean
as_app_ref_equal (AsAppRef *app_ref1, AsAppRef *app_ref2)
{
	g_return_val_if_fail (AS_IS_APP_REF (app_ref1), FALSE);
	g_return_val_if_fail (AS_IS_APP_REF (app_ref2), FALSE);
	if (app_ref1 == app_ref2)
		return TRUE;
	if (!as_app_ref_compare_id_part (app_ref1->scope, app_ref2->scope))
		return FALSE;
	if (!as_app_ref_compare_id_part (app_ref1->system, app_ref2->system))
		return FALSE;
	if (!as_app_ref_compare_id_part (app_ref1->origin, app_ref2->origin))
		return FALSE;
	if (!as_app_ref_compare_id_part (app_ref1->kind, app_ref2->kind))
		return FALSE;
	if (!as_app_ref_compare_id_part (app_ref1->id, app_ref2->id))
		return FALSE;
	if (!as_app_ref_compare_id_part (app_ref1->arch, app_ref2->arch))
		return FALSE;
	if (!as_app_ref_compare_id_part (app_ref1->branch, app_ref2->branch))
		return FALSE;
	return TRUE;
}

static void
as_app_ref_finalize (GObject *object)
{
	AsAppRef *app_ref = AS_APP_REF (object);

	g_free (app_ref->scope);
	g_free (app_ref->system);
	g_free (app_ref->origin);
	g_free (app_ref->kind);
	g_free (app_ref->id);
	g_free (app_ref->arch);
	g_free (app_ref->branch);

	G_OBJECT_CLASS (as_app_ref_parent_class)->finalize (object);
}

static void
as_app_ref_class_init (AsAppRefClass *klass)
{
	GObjectClass *object_class = G_OBJECT_CLASS (klass);
	object_class->finalize = as_app_ref_finalize;
}

static void
as_app_ref_init (AsAppRef *app_ref)
{
}

/**
 * as_app_ref_new:
 * @id: The AppStream ID, e.g. `gimp.desktop`
 *
 * Creates a new #AsAppRef.
 *
 * Returns: (transfer full): a #AsAppRef
 *
 * Since: 0.6.1
 **/
AsAppRef *
as_app_ref_new (const gchar *id)
{
	AsAppRef *app_ref;
	app_ref = g_object_new (AS_TYPE_APP_REF, NULL);
	app_ref->id = g_strdup (id);
	return AS_APP_REF (app_ref);
}
